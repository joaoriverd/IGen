#ifndef ATLAS_CPLXSIMD_H
   #define ATLAS_CPLXSIMD_H 1
#include "atlas_simd.h"
/*
 *                          FUNCTIONALITY SUMMARY
 * ============================================================================
 * Constant integers: ATL_CXVLEN, ATL_CXSPLDb
 * Load/store for partial vecs (replace I with 0 < I < VLEN/2, 1 always there):
 *    ATL_vcxldI, ATL_vcxuldI, ATL_vcxustI, ATL_vcxustI
 * Macros for axpy-based computation:
 *    ATL_vcxsplitRIld,  ATL_vcxsplitRI, ATL_vcxPrepAlpha
 * Macros for dot-based computation:
 *    ATL_vcxswapRI, ATL_vcxdotcomb
 * Macros for updating complex C in GEMM
 *   * ATL_vunpckLO ATL_vunpckHI
 * ============================================================================
 */
/*
 * ============================================================================
 * This file provides macros for doing the types complex computations
 * needed by ATLAS in a machine, precision and VLEN-independent manner
 * (i.e., this file changes based on VLEN/SIMD ISA, float/double, VLEN,
 *  but kernels implemented using work unchanged regardless of these variables).
 * ATLAS essentially does dot-product based computations (dot,GEMVT,GEMM)
 * and AXPY-based (AXPY,GER,GER2).  Both types of computation need both
 * load and stores.  We just use the real load/store for full VLEN ops.
 * However, we also need the ability to load/store a single complex number,
 * which means the ability to load/store pairs of real numbers.  In addition,
 * if we want to be able perform vector cleanup, we need the ability to
 * load/store I complex numbers (0 < I < ATL_VLEN/2), with loads zeroing any
 * elements above the loaded values.  Therefore, this file provides
 * (ATL_VLEN/2 - 1)*4 routines for loading/store complex numbers:
 *    ATL_vcxldI(r_, p_) : load lower 2*I elts of aligned p_ to r_, zero rest
 *    ATL_vcxuldI(r_, p_): load lower 2*I elts of unaligned p_ to r_, zero rest
 *    ATL_vcxstI(p_, r_) : store lower 2*I real elts of r_ to aligned p_
 *    ATL_vcxustI(p_, r_): store lower 2*I real elts of r_ to unaligned p_
 *
 * There are numerous ways to do complex computations, but this file provides
 * a particular approach for both dot- and axpy-based computations.
 *
 * For AXPY-based computations, we are performance limited by load/store of Y,
 * so we permute all other ops to allow us to keep Y in natural order.
 * Not all SIMD ISAs allow one to do different operations to different
 * vector elements (eg., ADDSUB), so instead we manipulate alpha outside
 * the main loop so that it is is permuted and scaled appropriately to allow
 * us to do MAC-based AXPY calculations.  We will split X into two vectors
 * with duplicated entries:
 *   {Xr, Xr}*(VLEN/2)          {Xi, Xi}*(VLEN/2)
 * This permutation must be done inside the loop, and is thus expensive.
 * We provide the following functions to accomplish this:
 *    ATL_vcxsplitRIld(rR_, rI, p_): split&dup cplx #s from aligned p_
      ATL_vcxsplitRI(rXr_, rXi_)  : split&dup from natural-order reg rXi_
 * ATL_vcxsplitRIld can be built out of ATL_vld & ATL_vcxsplitRI, which is how
 * it is done for cleanup, but on some systems it is more efficient to
 * do it directly from memory, so we provide a specialized high-performance
 * version.  On some systems, the alignment restrictions for this operation
 * are lower than full VLEN, so we also provide the const macro:
 *    ATL_CXSPLDb : required byte alignment for ATL_vcxsplitRIld.
 * We use ATL_cxsplit for vector cleanup & when X is not aligned to ATL_CXSPLDb.
 * axpy-based calcs are doing Y += alpha * X.  Alpha is loop-invariant, so we
 * can manipulate it outside the loop, even if that manipulation is relatively
 * inefficient.  In order to perform the two real MACs required for cplx MAC,
 * alpha is split into two vectors that match up with our X vecs as in:
 *   {Xr,   Xr}*(VLEN/2)          {Xi,    Xi}*(VLEN/2)
 *   {ALi, Alr}*(VLEN/2)          {ALr, -ALi}*(VLEN/2
 * The first of these is the natural order alpha (alN), and the second scaled
 * and permuted (alS).  First the scalar complex number is loaded to the
 * register using ATL_cx[u]ld1, then it is transformed with:
 *    ATL_vcxPrepAlpha(alN, alS): alN is input & output, alS output only
 *
 * The naive approach to performing complex MAC (multiply and accumulate)
 * requires permuting both X and Y inside the loop, which is very expensive.
 * However, we notice that DOT (the accumulator) is loop invariant, so we
 * can instead keep it in permuted & scaled form throughout the loop.  This
 * allows us to avoid either the permute of X or Y (but not both).
 * For DOT-based there is no performance difference between X and Y, so we
 * can choose to permute either one (one must be computed to build the complex
 * multiply and accumulate (MAC) out of real MACs).  In general you can only
 * force one vector to be aligned (vecs may be mutually misaligned), and that
 * load will be cheaper than the unaligned load.  We therefore perform loop
 * peeling to force X to be aligned whenever that is possible, and then
 * permute X rather than Y.  The permute adds to the dependence chain in the
 * loop, so you want dependent it on the fastest load.
 *
 * The technique for DOT-based calculations is that the two half of the MACs
 * are stored in two different dot variables throughout the loop, one storing
 * partial results for the real result, and one for the imaginary result.
 * The real/imag dot vectors must be internally summed up to produce the
 * final answer (this operation performed outside the loop).  The imaginary
 * dot looks like: {Xr*Yi, Xi*Yr}*(VLEN/2), so we add all elts to get the ans.
 * Real looks:     {Xi*Yi, Xr*Yr}*(VLEN/2), so we must subtract the odd elts
 * from the even.  We provide this macro to accomplish this:
 *    ATL_cxdotcomb(rR, rI) : put final ans in low 2 elts of rR
 *
 * Inside the loop, we keep Y in natural order, and have X in both natural
 * order (rN) and with imaginary and complex swapped (rS).  We provide:
 *    ATL_cxriswap(rS, rN): swap imag & real components of rN, store in rS
 *
 * ============================================================================
 */
/*
 * Define some length-specific constants.
 * ATL_VONEPN is used to scale so even words are negated (imag*imag).
 */
#if ATL_VLEN == 2
   #define ATL_CXVLEN 1
   #define ATL_CXVLSH 0
   #define ATL_VONEPN ((ATL_VTYPE){ATL_rone, ATL_rnone})
#elif ATL_VLEN == 4
   #define ATL_CXVLEN 2
   #define ATL_CXVLSH 1
   #define ATL_VONEPN ((ATL_VTYPE){ATL_rone, ATL_rnone,ATL_rone, ATL_rnone})
#elif ATL_VLEN == 8
   #define ATL_CXVLEN 4
   #define ATL_CXVLSH 2
   #define ATL_VONEPN ((ATL_VTYPE){ATL_rone, ATL_rnone,ATL_rone, ATL_rnone,\
                                   ATL_rone, ATL_rnone,ATL_rone, ATL_rnone})
#elif ATL_VLEN == 16
   #define ATL_CXVLEN 8
   #define ATL_CXVLSH 3
   #define ATL_VONEPN ((ATL_VTYPE){ATL_rone, ATL_rnone,ATL_rone, ATL_rnone,\
                                   ATL_rone, ATL_rnone,ATL_rone, ATL_rnone, \
                                   ATL_rone, ATL_rnone,ATL_rone, ATL_rnone, \
                                   ATL_rone, ATL_rnone,ATL_rone, ATL_rnone})
#elif ATL_VLEN == 32
   #define ATL_CXVLEN 16
   #define ATL_CXVLSH 4
   #define ATL_VONEPN (ATL_VTYPE){ATL_rone, ATL_rnone,ATL_rone, ATL_rnone,\
                                  ATL_rone, ATL_rnone,ATL_rone, ATL_rnone} \
                                  ATL_rone, ATL_rnone,ATL_rone, ATL_rnone, \
                                  ATL_rone, ATL_rnone,ATL_rone, ATL_rnone, \
                                  ATL_rone, ATL_rnone,ATL_rone, ATL_rnone, \
                                  ATL_rone, ATL_rnone,ATL_rone, ATL_rnone, \
                                  ATL_rone, ATL_rnone,ATL_rone, ATL_rnone, \
                                  ATL_rone, ATL_rnone,ATL_rone, ATL_rnone}
#else
   #error "unsupported VLEN!"
#endif

/*
 * Define ld/st I, 0 < I < VLEN/2, I=1 always present (scalar complex ld/st)
 */
#if ATL_VLEN == 2  /* 1 vec == 1 complex: DCPLX&(SSE2||VSX||ARM) or gnuvec */
   #define ATL_vcxld1(r_, p_) ATL_vld(r_, p_)
   #define ATL_vcxuld1(r_, p_) ATL_vuld(r_, p_)
   #define ATL_vcxst1(p_, r_) ATL_vst(p_, r_)
   #define ATL_vcxust1(p_, r_) ATL_vust(p_, r_)
#elif ATL_VLEN >= 4   /* gnuvec or DCPLX & AVX or SCPLX & (VSX || SSE) */
   #if (ATL_VSX) && defined(SCPLX)
      #if 0 /* gnuvec works better for unaligned load */
      #define ATL_vcxuld1(r_, p_) \
      {  ATL_VTYPE t0_, t1_;\
         t0_ = vec_splats(*(p_)); \
         t1_ = vec_splats((p_)[1]); \
         t0_ = vec_vmrglw(t0_, t1_); \
         ATL_vzero(r_); \
         r_ = vec_xxpermdi(t0_, r_, 0); \
      }
      #endif
      #define ATL_vcxld1(r_, p_) r_ = (ATL_VTYPE) \
         ((vector double){*((double*)(p_))})
      #define ATL_vcxust1(p_, r_) { *(p_) = r_[0]; (p_)[1] = r_[1]; }
      #define ATL_vcxst1(p_, r_) ATL_vcxust1(p_, r_)
   #elif (defined(ATL_VECARM1) || defined(ATL_NEON)) && defined(SCPLX)
      #define ATL_vcxuld1(r_, p_) \
         r_ = vcombine_f32(vld1_f32(p_), vdup_n_f32(0.0f))
      #define ATL_vcxust1(p_, r_) vst1_f32(p_, vget_low_f32(r_))
      #define ATL_vcxld1(r_, p_) ATL_vcxuld1(r_, p_)
      #define ATL_vcxst1(p_, r_) ATL_vcxust1(p_, r_)
   #elif defined(ATL_AVX) && defined(DCPLX)
      #define ATL_vcxld1(r_, p_) \
      { \
         ATL_vzero(r_); \
         r_ = _mm256_insertf128_pd(r_, _mm_load_pd(p_), 0); \
      }
      #define ATL_vcxuld1(r_, p_) \
      { \
         ATL_vzero(r_); \
         r_ = _mm256_insertf128_pd(r_, _mm_loadu_pd(p_), 0); \
      }
      #define ATL_vcxst1(p_, r_) _mm_store_pd(p_, _mm256_extractf128_pd(r_, 0))
      #define ATL_vcxust1(p_, r_) _mm_storeu_pd(p_, _mm256_extractf128_pd(r_,0))
   #elif defined(ATL_AVX) && defined(SCPLX)
      #define ATL_vcxld1(r_, p_) \
      {  __m128 t0_;\
         ATL_vzero(r_); \
         t0_ = _mm_setzero_ps(); \
         r_ = _mm256_insertf128_ps(r_, _mm_loadl_pi(t0_,(void*)(p_)), 0); \
      }
      #define ATL_vcxuld1(r_, p_) \
      {  __m128 t0_, t1_;\
         ATL_vzero(r_); \
         t0_ = _mm_load_ss(p_); \
         t1_ = _mm_load_ss((p_)+1); \
         t0_ = _mm_unpacklo_ps(t0_, t1_); \
         r_ = _mm256_insertf128_ps(r_, t0_, 0); \
      }
      #define ATL_vcxst1(p_, r_) \
         _mm_storel_pi((void*)(p_), _mm256_extractf128_ps(r_, 0))
      #define ATL_vcxust1(p_, r_) \
      {  __m128 t_;\
         t_ = _mm256_extractf128_ps(r_,0); \
         _mm_store_ss(p_, t_); \
         _mm_store_ss((p_)+1, _mm_shuffle_ps(t_, t_, 1)); \
      }
   #elif defined(ATL_SSE1) && defined(SCPLX)
      #define ATL_vcxld1(r_, p_) \
      { \
         ATL_vzero(r_); \
         r_ = _mm_loadl_pi(r_, ((void*)(p_))); \
      }
      #define ATL_vcxuld1(r_, p_) \
      {  ATL_VTYPE t_;\
         r_ = _mm_load_ss(p_); \
         t_ = _mm_load_ss((p_)+1); \
         r_ = _mm_unpacklo_ps(r_, t_); \
      }
      #define ATL_vcxst1(p_, r_) _mm_storel_pi((void*)(p_), r_)
      #define ATL_vcxust1(p_, r_) \
      { \
         _mm_store_ss(p_, r_); \
         _mm_store_ss((p_)+1, _mm_shuffle_ps(r_, r_, 1)); \
      }
   #else  /* gnuvec */
      #define ATL_vcxuld1(r_, p_) r_ = (ATL_VTYPE){*(p_), (p_)[1]}
      #define ATL_vcxust1(p_, r_) \
      { \
         *(p_) = (r_)[0]; \
         (p_)[1] = (r_)[1]; \
      }
      #define ATL_vcxld1 ATL_vcxuld1
      #define ATL_vcxst1 ATL_vcxust1
   #endif
/*
 * For VL == 8, is gnuvec or SCPLX&AVX or DCPLX&AVX512
 * For VL > 8, can only be SCPLX&AVX512 or gnuvec
 */
   #if ATL_VLEN >= 8  /* VL>=8, must define add op[2,3] */
      #if defined(SCPLX) && defined(ATL_AVX)
         #define ATL_vcxld2(r_, p_) \
         { \
            ATL_vzero(r_); \
            r_ = _mm256_insertf128_ps(r_, _mm_load_ps(p_), 0); \
         }
         #define ATL_vcxuld2(r_, p_) \
         { \
            ATL_vzero(r_); \
            r_ = _mm256_insertf128_ps(r_, _mm_loadu_ps(p_), 0); \
         }
         #define ATL_vcxld3(r_, p_) \
         { __m128 t_; \
            r_ = _mm256_insertf128_ps(r_, _mm_load_ps(p_), 0); \
            t_ = _mm_setzero_ps(); \
            t_ = _mm_loadl_pi(t_, ((void*)((p_)+4))); \
            r_ = _mm256_insertf128_ps(r_, t_, 1); \
         }
         #define ATL_vcxuld3(r_, p_) \
         { __m128 t0_, t1_; \
            r_ = _mm256_insertf128_ps(r_, _mm_loadu_ps(p_), 0); \
            t0_ = _mm_load_ss((p_)+4); \
            t1_ = _mm_load_ss((p_)+5); \
            t0_ = _mm_unpacklo_ps(t0_, t1_); \
            r_ = _mm256_insertf128_ps(r_, t0_, 1); \
         }
         #define ATL_vcxst2(p_, r_) \
            _mm_store_ps(p_, _mm256_extractf128_ps(r_, 0))
         #define ATL_vcxust2(p_, r_) \
             _mm_storeu_ps(p_, _mm256_extractf128_ps(r_,0))
         #define ATL_vcxst3(p_, r_) \
         {  __m128 t_; \
            ATL_vcxst2(p_, r_); \
            t_ = _mm256_extractf128_ps(r_, 0); \
            _mm_storel_pi((void*)((p_)+4), t_) ; \
         }
         #define ATL_vcxust3(p_, r_) \
         {  __m128 t_; \
            ATL_vcxust2(p_, r_); \
            t_ = _mm256_extractf128_ps(r_, 1); \
            _mm_store_ss((p_)+4, t_); \
            _mm_store_ss((p_)+5, _mm_shuffle_ps(t_, t_, 1)); \
         }
      #elif defined(DCPLX) &&  defined(ATL_AVX512__00)
         #error "AVX512 not presently supported"
      #elif defined(SCPLX) &&  defined(ATL_AVX512__00)
         #error "AVX512 not presently supported"
      #else /* gnuvec */
         #define ATL_vcxuld2(r_, p_) \
            r_ = (ATL_VTYPE){*(p_), (p_)[1], (p_)[2], (p_)[3]}
         #define ATL_vcxust2(p_, r_) \
         { \
            *(p_) = (r_)[0]; \
            (p_)[1] = (r_)[1]; \
            (p_)[2] = (r_)[2]; \
            (p_)[3] = (r_)[3]; \
         }
         #define ATL_vcxuld3(r_, p_) \
            r_ = (ATL_VTYPE){*(p_), (p_)[1], (p_)[2], (p_)[3], (p_)[4], (p_)[5]}
         #define ATL_vcxust3(p_, r_) \
         { \
            *(p_) = (r_)[0]; \
            (p_)[1] = (r_)[1]; \
            (p_)[2] = (r_)[2]; \
            (p_)[3] = (r_)[3]; \
            (p_)[4] = (r_)[4]; \
            (p_)[5] = (r_)[5]; \
         }

         #define ATL_vcxld2 ATL_vcxuld2
         #define ATL_vcxst2 ATL_vcxust2
         #define ATL_vcxld3 ATL_vcxuld3
         #define ATL_vcxst3 ATL_vcxust3
      #endif
      #if ATL_VLEN >= 16  /* need [4-7]: gnuvec or SREAL&AVX512 */
         #if defined(SCPLX__0) &&  defined(ATL_AVX512__0)
         #else /* gnuvec */
            #define ATL_vcxuld4(r_, p_) r_ = (ATL_VTYPE)\
               {*(p_), (p_)[1], (p_)[2], (p_)[3], \
                 (p_)[4],(p_)[5],(p_)[6],(p_)[7]}
            #define ATL_vcxuld5(r_, p_) r_ = (ATL_VTYPE)\
               {*(p_), (p_)[1], (p_)[2], (p_)[3], \
                 (p_)[4],(p_)[5],(p_)[6],(p_)[7], \
                 (p_)[8],(p_)[9]}
            #define ATL_vcxuld6(r_, p_) r_ = (ATL_VTYPE)\
               {*(p_), (p_)[1], (p_)[2], (p_)[3], \
                 (p_)[4],(p_)[5],(p_)[6],(p_)[7], \
                 (p_)[8],(p_)[9],(p_)[10],(p_)[11]}
            #define ATL_vcxuld7(r_, p_) r_ = (ATL_VTYPE)\
               {*(p_), (p_)[1], (p_)[2], (p_)[3], \
                 (p_)[4],(p_)[5],(p_)[6],(p_)[7], \
                 (p_)[8],(p_)[9],(p_)[10],(p_)[11], \
                 (p_)[12],(p_)[13]}
            #define ATL_vcxust4(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
            }
            #define ATL_vcxust5(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
            }
            #define ATL_vcxust6(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
               (p_)[10] = (r_)[10]; \
               (p_)[11] = (r_)[11]; \
            }
            #define ATL_vcxust7(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
               (p_)[10] = (r_)[10]; \
               (p_)[11] = (r_)[11]; \
               (p_)[12] = (r_)[12]; \
               (p_)[13] = (r_)[13]; \
            }

            #define ATL_vcxld4 ATL_vcxuld4
            #define ATL_vcxst4 ATL_vcxust4
            #define ATL_vcxld5 ATL_vcxuld5
            #define ATL_vcxst5 ATL_vcxust5
            #define ATL_vcxld6 ATL_vcxuld6
            #define ATL_vcxst6 ATL_vcxust6
            #define ATL_vcxld7 ATL_vcxuld7
            #define ATL_vcxst7 ATL_vcxust7
         #endif
         #if ATL_VLEN >= 32

         #define ATL_vcxuld8(r_, p_) r_ = (ATL_VTYPE){*(p_),\
                                        (p_)[1], \
                                        (p_)[2], \
                                        (p_)[3], \
                                        (p_)[4], \
                                        (p_)[5], \
                                        (p_)[6], \
                                        (p_)[7], \
                                        (p_)[8], \
                                        (p_)[9], \
                                        (p_)[10], \
                                        (p_)[11], \
                                        (p_)[12], \
                                        (p_)[13], \
                                        (p_)[14], \
                                        (p_)[15], \
                                     }
            #define ATL_vcxust8(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
               (p_)[10] = (r_)[10]; \
               (p_)[11] = (r_)[11]; \
               (p_)[12] = (r_)[12]; \
               (p_)[13] = (r_)[13]; \
               (p_)[14] = (r_)[14]; \
               (p_)[15] = (r_)[15]; \
            }
         #define ATL_vcxuld9(r_, p_) r_ = (ATL_VTYPE){*(p_),\
                                        (p_)[1], \
                                        (p_)[2], \
                                        (p_)[3], \
                                        (p_)[4], \
                                        (p_)[5], \
                                        (p_)[6], \
                                        (p_)[7], \
                                        (p_)[8], \
                                        (p_)[9], \
                                        (p_)[10], \
                                        (p_)[11], \
                                        (p_)[12], \
                                        (p_)[13], \
                                        (p_)[14], \
                                        (p_)[15], \
                                        (p_)[16], \
                                        (p_)[17], \
                                     }
            #define ATL_vcxust9(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
               (p_)[10] = (r_)[10]; \
               (p_)[11] = (r_)[11]; \
               (p_)[12] = (r_)[12]; \
               (p_)[13] = (r_)[13]; \
               (p_)[14] = (r_)[14]; \
               (p_)[15] = (r_)[15]; \
               (p_)[16] = (r_)[16]; \
               (p_)[17] = (r_)[17]; \
            }
         #define ATL_vcxuld10(r_, p_) r_ = (ATL_VTYPE){*(p_),\
                                        (p_)[1], \
                                        (p_)[2], \
                                        (p_)[3], \
                                        (p_)[4], \
                                        (p_)[5], \
                                        (p_)[6], \
                                        (p_)[7], \
                                        (p_)[8], \
                                        (p_)[9], \
                                        (p_)[10], \
                                        (p_)[11], \
                                        (p_)[12], \
                                        (p_)[13], \
                                        (p_)[14], \
                                        (p_)[15], \
                                        (p_)[16], \
                                        (p_)[17], \
                                        (p_)[18], \
                                        (p_)[19], \
                                     }
            #define ATL_vcxust10(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
               (p_)[10] = (r_)[10]; \
               (p_)[11] = (r_)[11]; \
               (p_)[12] = (r_)[12]; \
               (p_)[13] = (r_)[13]; \
               (p_)[14] = (r_)[14]; \
               (p_)[15] = (r_)[15]; \
               (p_)[16] = (r_)[16]; \
               (p_)[17] = (r_)[17]; \
               (p_)[18] = (r_)[18]; \
               (p_)[19] = (r_)[19]; \
            }
         #define ATL_vcxuld11(r_, p_) r_ = (ATL_VTYPE){*(p_),\
                                        (p_)[1], \
                                        (p_)[2], \
                                        (p_)[3], \
                                        (p_)[4], \
                                        (p_)[5], \
                                        (p_)[6], \
                                        (p_)[7], \
                                        (p_)[8], \
                                        (p_)[9], \
                                        (p_)[10], \
                                        (p_)[11], \
                                        (p_)[12], \
                                        (p_)[13], \
                                        (p_)[14], \
                                        (p_)[15], \
                                        (p_)[16], \
                                        (p_)[17], \
                                        (p_)[18], \
                                        (p_)[19], \
                                        (p_)[20], \
                                        (p_)[21], \
                                     }
            #define ATL_vcxust11(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
               (p_)[10] = (r_)[10]; \
               (p_)[11] = (r_)[11]; \
               (p_)[12] = (r_)[12]; \
               (p_)[13] = (r_)[13]; \
               (p_)[14] = (r_)[14]; \
               (p_)[15] = (r_)[15]; \
               (p_)[16] = (r_)[16]; \
               (p_)[17] = (r_)[17]; \
               (p_)[18] = (r_)[18]; \
               (p_)[19] = (r_)[19]; \
               (p_)[20] = (r_)[20]; \
               (p_)[21] = (r_)[21]; \
            }
         #define ATL_vcxuld12(r_, p_) r_ = (ATL_VTYPE){*(p_),\
                                        (p_)[1], \
                                        (p_)[2], \
                                        (p_)[3], \
                                        (p_)[4], \
                                        (p_)[5], \
                                        (p_)[6], \
                                        (p_)[7], \
                                        (p_)[8], \
                                        (p_)[9], \
                                        (p_)[10], \
                                        (p_)[11], \
                                        (p_)[12], \
                                        (p_)[13], \
                                        (p_)[14], \
                                        (p_)[15], \
                                        (p_)[16], \
                                        (p_)[17], \
                                        (p_)[18], \
                                        (p_)[19], \
                                        (p_)[20], \
                                        (p_)[21], \
                                        (p_)[22], \
                                        (p_)[23], \
                                     }
            #define ATL_vcxust12(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
               (p_)[10] = (r_)[10]; \
               (p_)[11] = (r_)[11]; \
               (p_)[12] = (r_)[12]; \
               (p_)[13] = (r_)[13]; \
               (p_)[14] = (r_)[14]; \
               (p_)[15] = (r_)[15]; \
               (p_)[16] = (r_)[16]; \
               (p_)[17] = (r_)[17]; \
               (p_)[18] = (r_)[18]; \
               (p_)[19] = (r_)[19]; \
               (p_)[20] = (r_)[20]; \
               (p_)[21] = (r_)[21]; \
               (p_)[22] = (r_)[22]; \
               (p_)[23] = (r_)[23]; \
            }
         #define ATL_vcxuld13(r_, p_) r_ = (ATL_VTYPE){*(p_),\
                                        (p_)[1], \
                                        (p_)[2], \
                                        (p_)[3], \
                                        (p_)[4], \
                                        (p_)[5], \
                                        (p_)[6], \
                                        (p_)[7], \
                                        (p_)[8], \
                                        (p_)[9], \
                                        (p_)[10], \
                                        (p_)[11], \
                                        (p_)[12], \
                                        (p_)[13], \
                                        (p_)[14], \
                                        (p_)[15], \
                                        (p_)[16], \
                                        (p_)[17], \
                                        (p_)[18], \
                                        (p_)[19], \
                                        (p_)[20], \
                                        (p_)[21], \
                                        (p_)[22], \
                                        (p_)[23], \
                                        (p_)[24], \
                                        (p_)[25], \
                                     }
            #define ATL_vcxust13(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
               (p_)[10] = (r_)[10]; \
               (p_)[11] = (r_)[11]; \
               (p_)[12] = (r_)[12]; \
               (p_)[13] = (r_)[13]; \
               (p_)[14] = (r_)[14]; \
               (p_)[15] = (r_)[15]; \
               (p_)[16] = (r_)[16]; \
               (p_)[17] = (r_)[17]; \
               (p_)[18] = (r_)[18]; \
               (p_)[19] = (r_)[19]; \
               (p_)[20] = (r_)[20]; \
               (p_)[21] = (r_)[21]; \
               (p_)[22] = (r_)[22]; \
               (p_)[23] = (r_)[23]; \
               (p_)[24] = (r_)[24]; \
               (p_)[25] = (r_)[25]; \
            }
         #define ATL_vcxuld14(r_, p_) r_ = (ATL_VTYPE){*(p_),\
                                        (p_)[1], \
                                        (p_)[2], \
                                        (p_)[3], \
                                        (p_)[4], \
                                        (p_)[5], \
                                        (p_)[6], \
                                        (p_)[7], \
                                        (p_)[8], \
                                        (p_)[9], \
                                        (p_)[10], \
                                        (p_)[11], \
                                        (p_)[12], \
                                        (p_)[13], \
                                        (p_)[14], \
                                        (p_)[15], \
                                        (p_)[16], \
                                        (p_)[17], \
                                        (p_)[18], \
                                        (p_)[19], \
                                        (p_)[20], \
                                        (p_)[21], \
                                        (p_)[22], \
                                        (p_)[23], \
                                        (p_)[24], \
                                        (p_)[25], \
                                        (p_)[26], \
                                        (p_)[27], \
                                     }
            #define ATL_vcxust14(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
               (p_)[10] = (r_)[10]; \
               (p_)[11] = (r_)[11]; \
               (p_)[12] = (r_)[12]; \
               (p_)[13] = (r_)[13]; \
               (p_)[14] = (r_)[14]; \
               (p_)[15] = (r_)[15]; \
               (p_)[16] = (r_)[16]; \
               (p_)[17] = (r_)[17]; \
               (p_)[18] = (r_)[18]; \
               (p_)[19] = (r_)[19]; \
               (p_)[20] = (r_)[20]; \
               (p_)[21] = (r_)[21]; \
               (p_)[22] = (r_)[22]; \
               (p_)[23] = (r_)[23]; \
               (p_)[24] = (r_)[24]; \
               (p_)[25] = (r_)[25]; \
               (p_)[26] = (r_)[26]; \
               (p_)[27] = (r_)[27]; \
            }
         #define ATL_vcxuld15(r_, p_) r_ = (ATL_VTYPE){*(p_),\
                                        (p_)[1], \
                                        (p_)[2], \
                                        (p_)[3], \
                                        (p_)[4], \
                                        (p_)[5], \
                                        (p_)[6], \
                                        (p_)[7], \
                                        (p_)[8], \
                                        (p_)[9], \
                                        (p_)[10], \
                                        (p_)[11], \
                                        (p_)[12], \
                                        (p_)[13], \
                                        (p_)[14], \
                                        (p_)[15], \
                                        (p_)[16], \
                                        (p_)[17], \
                                        (p_)[18], \
                                        (p_)[19], \
                                        (p_)[20], \
                                        (p_)[21], \
                                        (p_)[22], \
                                        (p_)[23], \
                                        (p_)[24], \
                                        (p_)[25], \
                                        (p_)[26], \
                                        (p_)[27], \
                                        (p_)[28], \
                                        (p_)[29], \
                                     }
            #define ATL_vcxust15(p_, r_) \
            { \
               *(p_) = (r_)[0]; \
               (p_)[1] = (r_)[1]; \
               (p_)[2] = (r_)[2]; \
               (p_)[3] = (r_)[3]; \
               (p_)[4] = (r_)[4]; \
               (p_)[5] = (r_)[5]; \
               (p_)[6] = (r_)[6]; \
               (p_)[7] = (r_)[7]; \
               (p_)[8] = (r_)[8]; \
               (p_)[9] = (r_)[9]; \
               (p_)[10] = (r_)[10]; \
               (p_)[11] = (r_)[11]; \
               (p_)[12] = (r_)[12]; \
               (p_)[13] = (r_)[13]; \
               (p_)[14] = (r_)[14]; \
               (p_)[15] = (r_)[15]; \
               (p_)[16] = (r_)[16]; \
               (p_)[17] = (r_)[17]; \
               (p_)[18] = (r_)[18]; \
               (p_)[19] = (r_)[19]; \
               (p_)[20] = (r_)[20]; \
               (p_)[21] = (r_)[21]; \
               (p_)[22] = (r_)[22]; \
               (p_)[23] = (r_)[23]; \
               (p_)[24] = (r_)[24]; \
               (p_)[25] = (r_)[25]; \
               (p_)[26] = (r_)[26]; \
               (p_)[27] = (r_)[27]; \
               (p_)[28] = (r_)[28]; \
               (p_)[29] = (r_)[29]; \
            }
            #define ATL_vcxld8 ATL_vcxuld8
            #define ATL_vcxst8 ATL_vcxust8
            #define ATL_vcxld9 ATL_vcxuld9
            #define ATL_vcxst9 ATL_vcxust9
            #define ATL_vcxld10 ATL_vcxuld10
            #define ATL_vcxst10 ATL_vcxust10
            #define ATL_vcxld11 ATL_vcxuld11
            #define ATL_vcxst11 ATL_vcxust11
            #define ATL_vcxld12 ATL_vcxuld12
            #define ATL_vcxst12 ATL_vcxust12
            #define ATL_vcxld13 ATL_vcxuld13
            #define ATL_vcxst13 ATL_vcxust13
            #define ATL_vcxld14 ATL_vcxuld14
            #define ATL_vcxst14 ATL_vcxust14
            #define ATL_vcxld15 ATL_vcxuld15
            #define ATL_vcxst15 ATL_vcxust15
            #if ATL_VLEN > 32 /* VLEN == 32, gnuvec only */
               #error "Unsupported VLEN > 32"
            #endif
         #endif
      #endif
   #endif
#endif
/*
 * Define ATL_vcxswapRI, ATL_vcxsplitRI.
 * Define ATL_vcxsplitRIld if you dont want vld/splitRI version.
 * Define ATL_vcxdotcomb & ATL_vcxPrepAlpha if you don't want to use
 * system-indep (slow) versions.  ATL_vcxdotcomb has a fast sys-indep
 * version for VLEN==2.
 * Define ATL_vunpckLO/HI if you don't want to use sys-ind vers.
 */
#ifdef ATL_VSX
   #ifdef SCPLX
      #define ATL_vunpckLO(d_, s0_, s1_) d_ = (ATL_VTYPE) \
         vec_mergee((vector unsigned int)(s0_), (vector unsigned int)(s1_));
      #define ATL_vunpckHI(d_, s0_, s1_) d_ = (ATL_VTYPE) \
         vec_mergeo((vector unsigned int)(s0_), (vector unsigned int)(s1_));
      #define ATL_vcxswapRI(d_, s_) d_ = vec_perm(s_,s_,(vector unsigned char) \
         {4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11})
      #if ATL_FULLGCCVSX   /* not supported by older gcc (eg. 4.8) */
         #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */ \
         { \
            rXr_ = (ATL_VTYPE) vec_mergee((vector unsigned int)(rXi_), \
                                          (vector unsigned int) (rXi_)); \
            rXi_ = (ATL_VTYPE) vec_mergeo((vector unsigned int)(rXi_),\
                                          (vector unsigned int)(rXi_)); \
         }
         #define ATL_vcxdotcomb(rR_, rI_) /* low 2 elts rR_ gets ans */ \
         {  ATL_VTYPE t1_;\
            ATL_vmul(rR_, rR_, ATL_VONEPN); \
            t1_ = vec_vmrglw(rR_, rI_); \
            rR_ = vec_vmrghw(rR_, rI_); \
            ATL_vadd(rR_, rR_, t1_); \
            t1_ = vec_xxpermdi(rR_, rR_, 2); \
            ATL_vadd(rR_, rR_, t1_); \
         }
      #else
/*
 *       Using these guys as constants isn't so great: gcc 4.8.2 pulls
 *       the formation of the first iperm vector out of a loop, but then leaves
 *       the formation of the second (in terms of the first) inside the loop.
 *       The fix is to have this file define DECL/INIT macros, where we manually
 *       declare the perm vector, create it, and hoist it ourselves.
 *       We'll keep with crap way, since later gcc supports mergee/mergeo.
 */
         #define ATL_MERGEE (vector unsigned char) \
            {0, 1, 2, 3, 0, 1, 2, 3, 8, 9, 10, 11, 8, 9, 10, 11}
         #define ATL_MERGEO (vector unsigned char) \
            {4, 5, 6, 7, 4, 5, 6, 7, 12, 13, 14, 15, 12, 13, 14, 15}
         #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */ \
         { \
            rXr_ = vec_perm(rXi_, rXi, ATL_MERGEE); \
            rXi_ = vec_perm(rXi_, rXi, ATL_MERGEO); \
         }
      #endif
   #else /* DCPLX */
      #define ATL_vunpckLO(d_, s0_, s1_) d_ = vec_xxpermdi(s0_, s1_, 0)
      #define ATL_vunpckHI(d_, s0_, s1_) d_ = vec_xxpermdi(s0_, s1_, 3)
      #define ATL_vcxswapRI(d_, s_) d_ = vec_xxpermdi(s_, s_, 2)
      #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */ \
      { \
         rXr_ = vec_xxpermdi(rXi_, rXi_, 0); \
         rXi_ = vec_xxpermdi(rXi_, rXi_, 3); \
      }
      #define ATL_CXSPLDb ATL_VLENb
      #define ATL_vcxsplitRIld(rXr_, rXi_, pX_) \
      { \
         rXr_ = vec_splats(*(pX_)); \
         rXi_ = vec_splats(*((pX_)+1)); \
      }
   #endif
#elif defined(ATL_VECARM1) || defined(ATL_NEON)
   #ifdef SCPLX
      #if 0
      #define ATL_vcxsplitRIld(rXr_, rXi_, pX_) \
      { unsigned long long *lp_=(void*)(pX_), l0_, l1_, rl0_, il0_, rl1_, il1_;\
         l0_ = *lp_;                /* l0 = {i0, r0}   :: cycle 0 */\
         l1_ = lp_[1];              /* l1 = {i1, r1}   :: cycle 0 */\
         rl0_ = l0_ << 32;          /* rl0= {r0,  0}   :: cycle 1 */\
         il0_ = l0_ >> 32;          /* il0= { 0, i0}   :: cycle 1*/\
         rl1_ = l1_ << 32;          /* rl1= {r1,  0}   :: cycle 2*/\
         il1_ = l1_ >> 32;          /* il1= { 0, i1}   :: cycle 2*/\
         rl0_ |= (rl0_>> 32);       /* rl0= {r0, r0}   :: cycle 3*/\
         il0_ |= (il0_<< 32);       /* il0= {i0, i0}   :: cycle 3*/\
         rl1_ |= (rl1_>> 32);       /* rl1= {r1, r1}   :: cycle 4*/\
         il1_ |= (il1_<< 32);       /* il1= {i1, i1}   :: cycle 4*/\
         rXr_ = vcombine_f32(vreinterpret_f32_u64(rl0_), \
                             vreinterpret_f32_u64(rl1_)); /* cycle 5 */\
         rXi_ = vcombine_f32(vreinterpret_f32_u64(il0_), \
                             vreinterpret_f32_u64(il1_)); /* cycle 6 */\
      }
      #endif

      #if defined(ATL_VECARM1)
         #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */  \
         {  \
            rXr_ = vtrn1q_f32(rXi_, rXi_); \
            rXi_ = vtrn2q_f32(rXi_, rXi_); \
         }
      #else
         #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */  \
         { \
            rXr_[0] = rXr_[1] = rXi[0]; \
            rXr_[2] = rXr_[3] = rXi[2]; \
            rXi_[0] = rXi_[1] = rXi[1]; \
            rXi_[2] = rXi_[3] = rXi[3]; \
         }
      #endif
      #define ATL_vcxswapRI(d_, s_) \
         d_ = vreinterpretq_f32_s32(vrev64q_s32(vreinterpretq_s32_f32(s_)))
      #define ATL_vcxdotcomb(rR_, rI_) /* low 2 elts rR_ gets ans */ \
      { \
         rR_[0] += (rR_)[2] - (rR_)[1] - (rR_)[3]; \
         (rR_)[1] = (rI_)[0] + (rI_)[1] + (rI_)[2] + (rI_)[3]; \
      }
      #define ATL_vcxPrepAlpha(rALn_, rALs_) /* rALs={ral,-ial}*(VLEN/2) */ \
      { \
         rALn_ = vreinterpretq_f32_u64(vdupq_lane_u64(\
                    vreinterpret_u64_f32(vget_low_f32(rALn_)),0)); \
         ATL_vmul(rALs_, rALn_, ATL_VONEPN); \
         ATL_vcxswapRI(rALs_, rALs_); \
      }
   #else
      #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */  \
      { \
         rXr_ = vdupq_laneq_f64(rXi_, 0); \
         rXi_ = vdupq_laneq_f64(rXi_, 1); \
      }
      #define ATL_vcxswapRI(d_, s_) \
         d_ = vcombine_f64(vget_high_f64(s_),vget_low_f64(s_))
      #define ATL_vcxdotcomb(rR_, rI_) /* low 2 elts rR_ gets ans */ \
      { \
         ATL_vmul(rR_, rR_, ATL_VONEPN); \
         rR_ = vpaddq_f64(rR_, rI_); \
      }
      #define ATL_vcxPrepAlpha(rALn_, rALs_) /* rALs={ral,-ial}*(VLEN/2) */ \
      { \
         ATL_vmul(rALs_, rALn_, ATL_VONEPN); \
         ATL_vcxswapRI(rALs_, rALs_); \
      }
   #endif
#elif defined(ATL_AVXMAC) || defined(ATL_AVX)
   #ifdef SCPLX
      #define ATL_vunpckLO(d_, s0_, s1_) d_ = _mm256_unpacklo_ps(s0_, s1_)
      #define ATL_vunpckHI(d_, s0_, s1_) d_ = _mm256_unpackhi_ps(s0_, s1_)
      #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */  \
      { \
         rXr_ = _mm256_moveldup_ps(rXi); \
         rXi_ = _mm256_movehdup_ps(rXi); \
      }
      #define ATL_vcxswapRI(d_, s_) d_ = _mm256_shuffle_ps(s_, s_, 0xB1)
      #define ATL_vcxdotcomb(rR_, rI_) /* low 2 elts rR_ gets ans */ \
      {  __m128 t0_, t1_;\
         ATL_vmul(rR_, rR_, ATL_VONEPN); \
         rR_ = _mm256_hadd_ps(rR_, rI_); \
         rR_ = _mm256_hadd_ps(rR_, rR_); \
         t0_ =  _mm256_extractf128_ps(rR_, 1); \
         t0_ = _mm_add_ps(t0_, _mm256_extractf128_ps(rR_, 0)); \
         rR_ = _mm256_insertf128_ps(rR_, t0_, 0); \
      }
      #define ATL_vcxPrepAlpha(rALn_, rALs_) /* rALs={ral,-ial}*(VLEN/2) */ \
      {  __m128 t0_; \
         t0_ = _mm256_extractf128_ps(rALn_,0); \
         t0_ = _mm_movelh_ps(t0_, t0_); \
         rALn_ = _mm256_insertf128_ps(rALn_,t0_, 0); \
         rALn_ = _mm256_insertf128_ps(rALn_,t0_, 1); \
         ATL_vmul(rALs_, rALn_, ATL_VONEPN); \
         ATL_vcxswapRI(rALs_, rALs_); \
      }
   #else  /* DCPLX */
      #define ATL_vunpckLO(d_, s0_, s1_) d_ = _mm256_unpacklo_pd(s0_, s1_)
      #define ATL_vunpckHI(d_, s0_, s1_) d_ = _mm256_unpackhi_pd(s0_, s1_)
      #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */  \
      { \
         rXr_ = _mm256_movedup_pd(rXi); \
         rXi_ = _mm256_shuffle_pd(rXi, rXi, 0xF); \
      }
      #define ATL_vcxswapRI(d_, s_) d_ = _mm256_shuffle_pd(s_, s_, 5)
      #define ATL_vcxdotcomb(rR_, rI_) /* low 2 elts rR_ gets ans */ \
      {  __m128d t0_;\
         ATL_vmul(rR_, rR_, ATL_VONEPN); \
         rR_ = _mm256_hadd_pd(rR_, rI_); \
         t0_ =  _mm256_extractf128_pd(rR_, 1); \
         t0_ =  _mm_add_pd(t0_, _mm256_extractf128_pd(rR_, 0)); \
         rR_ = _mm256_insertf128_pd(rR_, t0_, 0); \
      }
      #define ATL_vcxPrepAlpha(rALn_, rALs_) /* rALs={ral,-ial}*(VLEN/2) */ \
      { \
         rALn_ = _mm256_insertf128_pd(rALn_,_mm256_extractf128_pd(rALn_,0),1); \
         ATL_vmul(rALs_, rALn_, ATL_VONEPN); \
         ATL_vcxswapRI(rALs_, rALs_); \
      }
   #endif
#elif defined(ATL_SSE2) && defined(DCPLX)
   #define ATL_vunpckLO(d_, s0_, s1_) d_ = _mm_unpacklo_pd(s0_, s1_)
   #define ATL_vunpckHI(d_, s0_, s1_) d_ = _mm_unpackhi_pd(s0_, s1_)
   #ifdef ATL_SSE3
      #define ATL_CXSPLDb 8
      #define ATL_vcxsplitRIld(rXr_, rXi_, pX_) \
      { \
         rXr = _mm_loaddup_pd(pX_); \
         rXi = _mm_loaddup_pd((pX_)+1); \
      }
      #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */  \
      { \
         rXr_ = _mm_movedup_pd(rXi); \
         rXi_ = _mm_shuffle_pd(rXi, rXi, 0xF); \
      }
      #define ATL_vcxdotcomb(rR_, rI_) /* low 2 elts rR_ gets ans */ \
      { \
         ATL_vmul(rR_, rR_, ATL_VONEPN); \
         rR_ = _mm_hadd_pd(rR_, rI_); \
      }
   #else
      #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */  \
      { \
         rXr_ = _mm_unpacklo_pd(rXi, rXi); \
         rXi_ = _mm_unpackhi_pd(rXi, rXi); \
      }
      #define ATL_vcxdotcomb(rR_, rI_) /* low 2 elts rR_ gets ans */ \
      {  __m128d t1_;\
         ATL_vmul(rR_, rR_, ATL_VONEPN); \
         t1_ = _mm_unpacklo_pd(rR_, rI_); \
         rR_ = _mm_unpackhi_pd(rR_, rI_); \
         ATL_vadd(rR_, rR_, t1_); \
      }
   #endif
   #define ATL_vcxswapRI(d_, s_) d_ = _mm_shuffle_pd(s_, s_, 5);
#elif defined(ATL_SSE1) && defined(SCPLX)
   #define ATL_vunpckLO(d_, s0_, s1_) d_ = _mm_unpacklo_ps(s0_, s1_)
   #define ATL_vunpckHI(d_, s0_, s1_) d_ = _mm_unpackhi_ps(s0_, s1_)
   #ifdef ATL_SSE3
      #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */ \
      { \
         rXr_ = _mm_moveldup_ps(rXi); \
         rXi_ = _mm_movehdup_ps(rXi); \
      }
      #define ATL_vcxdotcomb(rR_, rI_) /* low 2 elts rR_ gets ans */ \
      { \
         ATL_vmul(rR_, rR_, ATL_VONEPN); \
         rR_ = _mm_hadd_ps(rR_, rI_); \
         rR_ = _mm_hadd_ps(rR_, rR_); \
      }
   #else
      #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */  \
      { \
         rXr_ = _mm_shuffle_ps(rXi, rXi, 0xA0); \
         rXi_ = _mm_shuffle_ps(rXi, rXi, 0xF5); \
      }
      #define ATL_vcxdotcomb(rR_, rI_) /* low 2 elts rR_ gets ans */ \
      {  __m128 t1_;\
         ATL_vmul(rR_, rR_, ATL_VONEPN); \
         t1_ = _mm_unpacklo_ps(rR_, rI_); \
         rR_ = _mm_unpackhi_ps(rR_, rI_); \
         ATL_vadd(rR_, rR_, t1_); \
         t1_ = _mm_movehl_ps(t1_, rR_); \
         ATL_vadd(rR_, rR_, t1_); \
      }
   #endif
   #define ATL_vcxswapRI(d_, s_) d_ = _mm_shuffle_ps(s_, s_, 0xB1)
   #define ATL_vcxPrepAlpha(rALn_, rALs_) /* rALs={ral,-ial}*(VLEN/2) */ \
   { \
      rALn_ = _mm_movelh_ps(rALn_, rALn_); \
      ATL_vmul(rALs_, rALn_, ATL_VONEPN); \
      ATL_vcxswapRI(rALs_, rALs_); \
   }
#else  /* gnuvec */
   #if ATL_VLEN == 2
      #ifndef ATL_vunpckLO
         #define ATL_vunpckLO(d_, s0_, s1_) d_ = {(s1_)[0],(s0_)[0]}
         #define ATL_vunpckHI(d_, s0_, s1_) d_ = {(s1_)[1],(s0_)[1]}
      #endif
      #define ATL_VIPERMR ((ATL_VITYPE){0, 0})
      #define ATL_VIPERMI ((ATL_VITYPE){1, 1})
      #define ATL_vcxswapRI(rd_, rs_) \
         rd_ = __builtin_shuffle(rs_, (ATL_VITYPE){1,0})
      #define ATL_vcxdotcomb(rR_, rI_) \
      { \
         (rR_)[0] -= (rR_)[1]; \
         (rR_)[1] = (rI_)[0] + (rI_)[1]; \
      }
   #elif  ATL_VLEN == 4
      #ifndef ATL_vunpckLO
         #define ATL_vunpckLO(d_, s0_, s1_) d_ = \
            {(s1_)[2],(s0_)[2],(s1_)[0],(s0_)[0]}
         #define ATL_vunpckHI(d_, s0_, s1_) d_ = \
            {(s1_)[3],(s0_)[3],(s1_)[1],(s0_)[1]}
      #endif
      #define ATL_vcxswapRI(rd_, rs_) \
         rd_ = __builtin_shuffle(rs_, (ATL_VITYPE){1,0,3,2})
      #define ATL_vcxdotcomb(rR_, rI_) \
      { \
         rR_[0] += (rR_)[2] - (rR_)[1] - (rR_)[3]; \
         (rR_)[1] = (rI_)[0] + (rI_)[1] + (rI_)[2] + (rI_)[3]; \
      }
      #define ATL_VIPERMR ((ATL_VITYPE){0, 0, 2, 2})
      #define ATL_VIPERMI ((ATL_VITYPE){1, 1, 3, 3})
   #elif  ATL_VLEN == 8
      #ifndef ATL_vunpckLO
         #define ATL_vunpckLO(d_, s0_, s1_) d_ = \
            {(s1_)[6],(s0_)[6],(s1_)[4],(s0_)[4], \
             (s1_)[2],(s0_)[2],(s1_)[0],(s0_)[0]}
         #define ATL_vunpckHI(d_, s0_, s1_) d_ = \
            {(s1_)[7],(s0_)[7],(s1_)[5],(s0_)[5], \
             (s1_)[3],(s0_)[3],(s1_)[1],(s0_)[1]}
      #endif
      #define ATL_vcxswapRI(rd_, rs_) \
         rd_ = __builtin_shuffle(rs_, (ATL_VITYPE){1,0,3,2,5,4,7,6})
      #define ATL_vcxdotcomb(rR_, rI_) \
      { \
         (rR_)[0] += (rR_)[2]+(rR_)[4]+(rR_)[6] \
               - (rR_)[1]-(rR_)[3]-(rR_)[5]-(rR_)[7]; \
         (rR_)[1] = (rI_)[0] + (rI_)[1] + (rI_)[2] + (rI_)[3] \
                  + (rI_)[4] + (rI_)[5] + (rI_)[6] + (rI_)[7]; \
      }
      #define ATL_VIPERMR ((ATL_VITYPE){0, 0, 2, 2, 4, 4, 6, 6})
      #define ATL_VIPERMI ((ATL_VITYPE){1, 1, 3, 3, 5, 5, 7, 7})
   #elif  ATL_VLEN == 16
      #ifndef ATL_vunpckLO
         #define ATL_vunpckLO(d_, s0_, s1_) d_ = \
            {(s1_)[14],(s0_)[14],(s1_)[12],(s0_)[12], \
             (s1_)[10],(s0_)[10],(s1_)[8],(s0_)[8], \
             (s1_)[6],(s0_)[6],(s1_)[4],(s0_)[4], \
             (s1_)[2],(s0_)[2],(s1_)[0],(s0_)[0]}
         #define ATL_vunpckHI(d_, s0_, s1_) d_ = \
            {(s1_)[15],(s0_)[15],(s1_)[13],(s0_)[13], \
             (s1_)[11],(s0_)[11],(s1_)[9],(s0_)[9], \
             (s1_)[7],(s0_)[7],(s1_)[5],(s0_)[5], \
             (s1_)[3],(s0_)[3],(s1_)[1],(s0_)[1]}
      #endif
      #define ATL_vcxswapRI(rd_, rs_) \
         rd_ = __builtin_shuffle(rs_, (ATL_VITYPE){1,0,3,2,5,4,7,6, \
                                                   9,8,11,10,13,12,15,14})
      #define ATL_vcxdotcomb(rR_, rI_) \
      { \
         (rR_)[0] += (rR_)[2]+(rR_)[4]+(rR_)[6]+(rR_)[8]+(rR_)[10]+(rR_)[12] \
                   + (rR_)[14] - (rR_)[1]-(rR_)[3]-(rR_)[5]-(rR_)[7] \
                   - (rR_)[9]-(rR_)[11]-(rR_)[13]-(rR_)[15]; \
         (rR_)[1] = (rI_)[0] + (rI_)[1] + (rI_)[2] + (rI_)[3] \
                  + (rI_)[4] + (rI_)[5] + (rI_)[6] + (rI_)[7]  \
                  + (rI_)[8] + (rI_)[9] + (rI_)[10] + (rI_)[11]  \
                  + (rI_)[12] + (rI_)[13] + (rI_)[14] + (rI_)[15]; \
      }
      #define ATL_VIPERMR ((ATL_VITYPE){0, 0, 2, 2, 4, 4, 6, 6, \
                                        8, 8, 10, 10, 12, 12, 14, 14})
      #define ATL_VIPERMI ((ATL_VITYPE){1, 1, 3, 3, 5, 5, 7, 7, \
                                        9, 9, 11, 11, 13, 13, 15, 15})
   #elif  ATL_VLEN == 32
      #define ATL_vcxswapRI(rd_, rs_) \
         rd_ = __builtin_shuffle(rs_, (ATL_VITYPE){1,0,3,2,5,4,7,6, \
                                                   9,8,11,10,13,12,15,14, \
                                                   17,16,19,18,21,20,23,22, \
                                                   25,24,27,26,29,28,31,30})
      #define ATL_vcxdotcomb(rR_, rI_) \
      { \
         (rR_)[0] += (rR_)[2]+(rR_)[4]+(rR_)[6] \
                   + (rR_)[8]+(rR_)[10]+(rR_)[12]+(rR_)[14] \
                   + (rR_)[16]+(rR_)[18]+(rR_)[20]+(rR_)[22] \
                   + (rR_)[24]+(rR_)[26]+(rR_)[28]+(rR_)[30] \
                   - (rR_)[1]-(rR_)[3]-(rR_)[5]-(rR_)[7] \
                   - (rR_)[9]-(rR_)[11]-(rR_)[13]-(rR_)[15] \
                   - (rR_)[17]-(rR_)[19]-(rR_)[21]-(rR_)[23] \
                   - (rR_)[25]-(rR_)[27]-(rR_)[29]-(rR_)[31]; \
         (rR_)[1] = (rI_)[0] + (rI_)[1] + (rI_)[2] + (rI_)[3] \
                  + (rI_)[4] + (rI_)[5] + (rI_)[6] + (rI_)[7]  \
                  + (rI_)[8] + (rI_)[9] + (rI_)[10] + (rI_)[11]  \
                  + (rI_)[12] + (rI_)[13] + (rI_)[14] + (rI_)[15] \
                  + (rI_)[16] + (rI_)[17] + (rI_)[18] + (rI_)[19] \
                  + (rI_)[20] + (rI_)[21] + (rI_)[22] + (rI_)[23] \
                  + (rI_)[24] + (rI_)[25] + (rI_)[26] + (rI_)[27] \
                  + (rI_)[28] + (rI_)[29] + (rI_)[30] + (rI_)[31]; \
      }
       #define ATL_VIPERMR ((ATL_VITYPE) \
        { 0,  0,  2,  2,  4,  4,  6,  6,  8,  8, 10, 10, 12, 12, 14, 14, \
          16, 16, 18, 18, 20, 20, 22, 22, 24, 24, 26, 26, 28, 28, 30, 30})
       #define ATL_VIPERMI ((ATL_VITYPE) \
        { 1,  1,  3,  3,  5,  5,  7,  7,  9,  9, 11, 11, 13, 13, 15, 15, \
         17, 17, 19, 19, 21, 21, 23, 23, 25, 25, 27, 27, 29, 29, 31, 31})
   #else
      #error "unsupported ATL_VLEN!"
   #endif
   #define ATL_vcxsplitRI(rXr_, rXi_)  /* rXi input & output */  \
   { \
      rXr_ = __builtin_shuffle(rXi_, ATL_VIPERMR); \
      rXi_ = __builtin_shuffle(rXi_, ATL_VIPERMI); \
   }
#endif
/*
 * brute-force alpha prep works on any gcc-compat compiler & vec ISA
 */
#ifndef ATL_vcxPrepAlpha
   #if ATL_VLEN == 2  /* case that can be vec wt predef ops */
      #define ATL_vcxPrepAlpha(rALn_, rALs_) /* rALs={ral,-ial}*(VLEN/2) */ \
      { \
         ATL_vmul(rALs_, rALn_, ATL_VONEPN); \
         ATL_vcxswapRI(rALs_, rALs_); \
      }
   #else
      #define ATL_vcxPrepAlpha(rALn_, rALs_) /* rALs={ral,-ial}*(VLEN/2) */ \
      { \
         TYPE mr_[ATL_VLEN] __attribute__ ((aligned (ATL_VLENb)));\
         TYPE a0_, a1_; int i_; \
         ATL_vst(mr_, rALn_); \
         a0_ = *(mr_); a1_ = mr_[1]; \
         for (i_=2; i_ < ATL_VLEN; i_ += 2) \
         { mr_[i_] = a0_; mr_[i_+1] = a1_; } \
         ATL_vld(rALn_, mr_); \
         a0_ = -a1_; a1_ = *(mr_); \
         for (i_=0; i_ < ATL_VLEN; i_ += 2) \
         { mr_[i_] = a0_; mr_[i_+1] = a1_; } \
         ATL_vld(rALs_, mr_); \
      }
   #endif
#endif
/*
 * brute force combine that will work on any gcc-compatible compiler/vec ISA
 */
#ifndef ATL_vcxdotcomb
   #define ATL_vcxdotcomb(rR_, rI_) /* low 2 elts rR gets ans */ \
   { \
      TYPE mr_[ATL_VLEN] __attribute__ ((aligned (ATL_VLENb)));\
      TYPE mi_[ATL_VLEN] __attribute__ ((aligned (ATL_VLENb)));\
      int i_;  \
      register TYPE dr_=ATL_rzero, di_=ATL_rzero; \
      ATL_vst(mr_, rR_); \
      ATL_vst(mi_, rI_); \
      for (i_=0; i_ < ATL_VLEN; i_ += 2) \
      { \
         dr_ += mr_[i_] - mr_[i_+1]; \
         di_ += mi_[i_] + mi_[i_+1]; \
      } \
      mr_[0] = dr_; \
      mr_[1] = di_; \
      ATL_vld(rR_, mr_); \
   }
#endif
/*
 * Default vcxsplitRIld that uses ATL_vld & ATL_vcxsplitRI
 */
#ifndef ATL_CXSPLDb
   #define ATL_CXSPLDb ATL_VLENb
#endif
#ifndef ATL_vcxsplitRIld
   #define ATL_vcxsplitRIld(rXr_, rXi_, pX_) \
   { \
      ATL_vld(rXi_, pX_); \
      ATL_vcxsplitRI(rXr_, rXi_); \
   }
#endif
/*
 * Convenience funcs for one vector iteration of DOT product, aligned &
 * unaligned Y. rX_ comes in already preloaded so that it can be used across mul
 * cols, as in GEMVT.  vX is natural order, vXs real/imag swapped (cxriswap).
 */
#define ATL_vcxdotA(dotR_, dotI_, vX_, vXs_, pY_) \
{\
   register ATL_VTYPE vY_; \
   ATL_vld(vY_, pY_); \
   ATL_vmac(dotR_, vX_, vY_); \
   ATL_vmac(dotI_, vXs_, vY); \
}

#define ATL_vcxdotU(dotR_, dotI_, vX_, vXs_, pY_) \
{\
   register ATL_VTYPE vY_; \
   ATL_vuld(vY_, pY_); \
   ATL_vmac(dotR_, vX_, vY_); \
   ATL_vmac(dotI_, vXs_, vY); \
}
/*
 * Convenience funcs for one vector iteration of AXPLY, [Un]&Aligned pY_
 * X comes in already split into vXr_ (real elts) and vXi_ (imag elts) so
 * that the same X values can be used across multiple Y vecs (which are
 * actually A columns for GER.
 */
#define ATL_vcxaxpyA(pY_, vXr_, vXi_, vALn_, vALs_) \
{                                      /* ALs={ALr,-iAL}; */ \
   register ATL_VTYPE vY_;             /* ALn={iAL,rAL} */ \
   ATL_vld(vY_, pY_);                  /* vY = {iY,rY, ...} */ \
   ATL_vmac(vY_, vXi_, vALs_);         /* vY += {iX*rAL, -iX*iAL} */ \
   ATL_vmac(vY_, vXr_, vALn_);         /* vY += {rX*iAL, rX*rAL} */ \
   ATL_vst(pY_, vY_); \
}

#define ATL_vcxaxpyU(pY_, vXr_, vXi_, vALn_, vALs_) \
{                                      /* ALs={ALr,-iAL}; */ \
   register ATL_VTYPE vY_, vXr_, vXi_; /* ALn={iAL,rAL} */ \
   ATL_vuld(vY_, pY_);                 /* vY = {iY,rY, ...} */ \
   ATL_vmac(vY_, vXi_, vALs_);         /* vY += {iX*rAL, -iX*iAL} */ \
   ATL_vmac(vY_, vXr_, vALn_);         /* vY += {rX*iAL, rX*rAL} */ \
   ATL_vst(pY_, vY_); \
}
/*
 * Remainder load/store functions.  They take 0 < n_ < (ATL_VLEN/2), which
 * is the number of complex elts to load/store from/to the ptr
 */

#if ATL_VLEN <= 4
   #define ATL_vcxldR(r_, p_, n_) ATL_vcxld1(r_, p_)
   #define ATL_vcxuldR(r_, p_, n_) ATL_vcxuld1(r_, p_)
   #define ATL_vcxstR(p_, r_, n_) ATL_vcxst1(p_, r_)
   #define ATL_vcxustR(p_, r_, n_) ATL_vcxust1(p_, r_)
   #define ATL_vcxldXYR(rX_, pX_, rY_, pY_, n_) \
   { \
      ATL_vcxld1(rX_, pX_); \
      ATL_vcxld1(rY_, pY_); \
   }
   #define ATL_vcxldXuYR(rX_, pX_, rY_, pY_, n_) \
   { \
      ATL_vcxld1(rX_, pX_); \
      ATL_vcxuld1(rY_, pY_); \
   }
   #define ATL_vcxlduXuYR(rX_, pX_, rY_, pY_, n_) \
   { \
      ATL_vcxuld1(rX_, pX_); \
      ATL_vcxuld1(rY_, pY_); \
   }
#elif ATL_VLEN == 8
   #define ATL_vcxldXYR(rX_,pX_,rY_,pY_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxld1(rX_,pX_); \
         ATL_vcxld1(rY_,pY_); \
         break; \
      case 2 : \
         ATL_vcxld2(rX_,pX_); \
         ATL_vcxld2(rY_,pY_); \
         break; \
      default: \
         ATL_vcxld3(rX_,pX_); \
         ATL_vcxld3(rY_,pY_); \
      } \
   }
   #define ATL_vcxldXuYR(rX_,pX_,rY_,pY_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxld1(rX_,pX_); \
         ATL_vcxuld1(rY_,pY_); \
         break; \
      case 2 : \
         ATL_vcxld2(rX_,pX_); \
         ATL_vcxuld2(rY_,pY_); \
         break; \
      default: \
         ATL_vcxld3(rX_,pX_); \
         ATL_vcxuld3(rY_,pY_); \
      } \
   }
   #define ATL_vcxlduXuYR(rX_,pX_,rY_,pY_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxuld1(rX_,pX_); \
         ATL_vcxuld1(rY_,pY_); \
         break; \
      case 2 : \
         ATL_vcxuld2(rX_,pX_); \
         ATL_vcxuld2(rY_,pY_); \
         break; \
      default: \
         ATL_vcxuld3(rX_,pX_); \
         ATL_vcxuld3(rY_,pY_); \
      } \
   }
   #define ATL_vcxldR(r_,p_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxld1(r_,p_); \
         break; \
      case 2 : \
         ATL_vcxld2(r_,p_); \
         break; \
      default: \
         ATL_vcxld3(r_,p_); \
      } \
   }
   #define ATL_vcxstR(p_,r_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxst1(p_,r_); \
         break; \
      case 2 : \
         ATL_vcxst2(p_,r_); \
         break; \
      default: \
         ATL_vcxst3(p_,r_); \
      } \
   }
   #define ATL_vcxuldR(r_,p_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxuld1(r_,p_); \
         break; \
      case 2 : \
         ATL_vcxuld2(r_,p_); \
         break; \
      default: \
         ATL_vcxuld3(r_,p_); \
      } \
   }
   #define ATL_vcxustR(p_,r_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxust1(p_,r_); \
         break; \
      case 2 : \
         ATL_vcxust2(p_,r_); \
         break; \
      default: \
         ATL_vcxust3(p_,r_); \
      } \
   }
#elif ATL_VLEN == 16
   #define ATL_vcxldXYR(rX_,pX_,rY_,pY_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxld1(rX_,pX_); \
         ATL_vcxld1(rY_,pY_); \
         break; \
      case 2 : \
         ATL_vcxld2(rX_,pX_); \
         ATL_vcxld2(rY_,pY_); \
         break; \
      case 3 : \
         ATL_vcxld3(rX_,pX_); \
         ATL_vcxld3(rY_,pY_); \
         break; \
      case 4 : \
         ATL_vcxld4(rX_,pX_); \
         ATL_vcxld4(rY_,pY_); \
         break; \
      case 5 : \
         ATL_vcxld5(rX_,pX_); \
         ATL_vcxld5(rY_,pY_); \
         break; \
      case 6 : \
         ATL_vcxld6(rX_,pX_); \
         ATL_vcxld6(rY_,pY_); \
         break; \
      default: \
         ATL_vcxld7(rX_,pX_); \
         ATL_vcxld7(rY_,pY_); \
      } \
   }
   #define ATL_vcxldXuYR(rX_,pX_,rY_,pY_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxld1(rX_,pX_); \
         ATL_vcxuld1(rY_,pY_); \
         break; \
      case 2 : \
         ATL_vcxld2(rX_,pX_); \
         ATL_vcxuld2(rY_,pY_); \
         break; \
      case 3 : \
         ATL_vcxld3(rX_,pX_); \
         ATL_vcxuld3(rY_,pY_); \
         break; \
      case 4 : \
         ATL_vcxld4(rX_,pX_); \
         ATL_vcxuld4(rY_,pY_); \
         break; \
      case 5 : \
         ATL_vcxld5(rX_,pX_); \
         ATL_vcxuld5(rY_,pY_); \
         break; \
      case 6 : \
         ATL_vcxld6(rX_,pX_); \
         ATL_vcxuld6(rY_,pY_); \
         break; \
      default: \
         ATL_vcxld7(rX_,pX_); \
         ATL_vcxuld7(rY_,pY_); \
      } \
   }
   #define ATL_vcxlduXuYR(rX_,pX_,rY_,pY_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxuld1(rX_,pX_); \
         ATL_vcxuld1(rY_,pY_); \
         break; \
      case 2 : \
         ATL_vcxuld2(rX_,pX_); \
         ATL_vcxuld2(rY_,pY_); \
         break; \
      case 3 : \
         ATL_vcxuld3(rX_,pX_); \
         ATL_vcxuld3(rY_,pY_); \
         break; \
      case 4 : \
         ATL_vcxuld4(rX_,pX_); \
         ATL_vcxuld4(rY_,pY_); \
         break; \
      case 5 : \
         ATL_vcxuld5(rX_,pX_); \
         ATL_vcxuld5(rY_,pY_); \
         break; \
      case 6 : \
         ATL_vcxuld6(rX_,pX_); \
         ATL_vcxuld6(rY_,pY_); \
         break; \
      default: \
         ATL_vcxuld7(rX_,pX_); \
         ATL_vcxuld7(rY_,pY_); \
      } \
   }
   #define ATL_vcxldR(r_,p_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxld1(r_,p_); \
         break; \
      case 2 : \
         ATL_vcxld2(r_,p_); \
         break; \
      case 3 : \
         ATL_vcxld3(r_,p_); \
         break; \
      case 4 : \
         ATL_vcxld4(r_,p_); \
         break; \
      case 5 : \
         ATL_vcxld5(r_,p_); \
         break; \
      case 6 : \
         ATL_vcxld6(r_,p_); \
         break; \
      default: \
         ATL_vcxld7(r_,p_); \
      } \
   }
   #define ATL_vcxstR(p_,r_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxst1(p_,r_); \
         break; \
      case 2 : \
         ATL_vcxst2(p_,r_); \
         break; \
      case 3 : \
         ATL_vcxst3(p_,r_); \
         break; \
      case 4 : \
         ATL_vcxst4(p_,r_); \
         break; \
      case 5 : \
         ATL_vcxst5(p_,r_); \
         break; \
      case 6 : \
         ATL_vcxst6(p_,r_); \
         break; \
      default: \
         ATL_vcxst7(p_,r_); \
      } \
   }
   #define ATL_vcxuldR(r_,p_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxuld1(r_,p_); \
         break; \
      case 2 : \
         ATL_vcxuld2(r_,p_); \
         break; \
      case 3 : \
         ATL_vcxuld3(r_,p_); \
         break; \
      case 4 : \
         ATL_vcxuld4(r_,p_); \
         break; \
      case 5 : \
         ATL_vcxuld5(r_,p_); \
         break; \
      case 6 : \
         ATL_vcxuld6(r_,p_); \
         break; \
      default: \
         ATL_vcxuld7(r_,p_); \
      } \
   }
   #define ATL_vcxustR(p_,r_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxust1(p_,r_); \
         break; \
      case 2 : \
         ATL_vcxust2(p_,r_); \
         break; \
      case 3 : \
         ATL_vcxust3(p_,r_); \
         break; \
      case 4 : \
         ATL_vcxust4(p_,r_); \
         break; \
      case 5 : \
         ATL_vcxust5(p_,r_); \
         break; \
      case 6 : \
         ATL_vcxust6(p_,r_); \
         break; \
      default: \
         ATL_vcxust7(p_,r_); \
      } \
   }
#elif ATL_VLEN == 32
   #define ATL_vcxldXYR(rX_,pX_,rY_,pY_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxld1(rX_,pX_); \
         ATL_vcxld1(rY_,pY_); \
         break; \
      case 2 : \
         ATL_vcxld2(rX_,pX_); \
         ATL_vcxld2(rY_,pY_); \
         break; \
      case 3 : \
         ATL_vcxld3(rX_,pX_); \
         ATL_vcxld3(rY_,pY_); \
         break; \
      case 4 : \
         ATL_vcxld4(rX_,pX_); \
         ATL_vcxld4(rY_,pY_); \
         break; \
      case 5 : \
         ATL_vcxld5(rX_,pX_); \
         ATL_vcxld5(rY_,pY_); \
         break; \
      case 6 : \
         ATL_vcxld6(rX_,pX_); \
         ATL_vcxld6(rY_,pY_); \
         break; \
      case 7 : \
         ATL_vcxld7(rX_,pX_); \
         ATL_vcxld7(rY_,pY_); \
         break; \
      case 8 : \
         ATL_vcxld8(rX_,pX_); \
         ATL_vcxld8(rY_,pY_); \
         break; \
      case 9 : \
         ATL_vcxld9(rX_,pX_); \
         ATL_vcxld9(rY_,pY_); \
         break; \
      case 10 : \
         ATL_vcxld10(rX_,pX_); \
         ATL_vcxld10(rY_,pY_); \
         break; \
      case 11 : \
         ATL_vcxld11(rX_,pX_); \
         ATL_vcxld11(rY_,pY_); \
         break; \
      case 12 : \
         ATL_vcxld12(rX_,pX_); \
         ATL_vcxld12(rY_,pY_); \
         break; \
      case 13 : \
         ATL_vcxld13(rX_,pX_); \
         ATL_vcxld13(rY_,pY_); \
         break; \
      case 14 : \
         ATL_vcxld14(rX_,pX_); \
         ATL_vcxld14(rY_,pY_); \
         break; \
      default: \
         ATL_vcxld15(rX_,pX_); \
         ATL_vcxld15(rY_,pY_); \
      } \
   }
   #define ATL_vcxldXuYR(rX_,pX_,rY_,pY_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxld1(rX_,pX_); \
         ATL_vcxuld1(rY_,pY_); \
         break; \
      case 2 : \
         ATL_vcxld2(rX_,pX_); \
         ATL_vcxuld2(rY_,pY_); \
         break; \
      case 3 : \
         ATL_vcxld3(rX_,pX_); \
         ATL_vcxuld3(rY_,pY_); \
         break; \
      case 4 : \
         ATL_vcxld4(rX_,pX_); \
         ATL_vcxuld4(rY_,pY_); \
         break; \
      case 5 : \
         ATL_vcxld5(rX_,pX_); \
         ATL_vcxuld5(rY_,pY_); \
         break; \
      case 6 : \
         ATL_vcxld6(rX_,pX_); \
         ATL_vcxuld6(rY_,pY_); \
         break; \
      case 7 : \
         ATL_vcxld7(rX_,pX_); \
         ATL_vcxuld7(rY_,pY_); \
         break; \
      case 8 : \
         ATL_vcxld8(rX_,pX_); \
         ATL_vcxuld8(rY_,pY_); \
         break; \
      case 9 : \
         ATL_vcxld9(rX_,pX_); \
         ATL_vcxuld9(rY_,pY_); \
         break; \
      case 10 : \
         ATL_vcxld10(rX_,pX_); \
         ATL_vcxuld10(rY_,pY_); \
         break; \
      case 11 : \
         ATL_vcxld11(rX_,pX_); \
         ATL_vcxuld11(rY_,pY_); \
         break; \
      case 12 : \
         ATL_vcxld12(rX_,pX_); \
         ATL_vcxuld12(rY_,pY_); \
         break; \
      case 13 : \
         ATL_vcxld13(rX_,pX_); \
         ATL_vcxuld13(rY_,pY_); \
         break; \
      case 14 : \
         ATL_vcxld14(rX_,pX_); \
         ATL_vcxuld14(rY_,pY_); \
         break; \
      default: \
         ATL_vcxld15(rX_,pX_); \
         ATL_vcxuld15(rY_,pY_); \
      } \
   }
   #define ATL_vcxlduXuYR(rX_,pX_,rY_,pY_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxuld1(rX_,pX_); \
         ATL_vcxuld1(rY_,pY_); \
         break; \
      case 2 : \
         ATL_vcxuld2(rX_,pX_); \
         ATL_vcxuld2(rY_,pY_); \
         break; \
      case 3 : \
         ATL_vcxuld3(rX_,pX_); \
         ATL_vcxuld3(rY_,pY_); \
         break; \
      case 4 : \
         ATL_vcxuld4(rX_,pX_); \
         ATL_vcxuld4(rY_,pY_); \
         break; \
      case 5 : \
         ATL_vcxuld5(rX_,pX_); \
         ATL_vcxuld5(rY_,pY_); \
         break; \
      case 6 : \
         ATL_vcxuld6(rX_,pX_); \
         ATL_vcxuld6(rY_,pY_); \
         break; \
      case 7 : \
         ATL_vcxuld7(rX_,pX_); \
         ATL_vcxuld7(rY_,pY_); \
         break; \
      case 8 : \
         ATL_vcxuld8(rX_,pX_); \
         ATL_vcxuld8(rY_,pY_); \
         break; \
      case 9 : \
         ATL_vcxuld9(rX_,pX_); \
         ATL_vcxuld9(rY_,pY_); \
         break; \
      case 10 : \
         ATL_vcxuld10(rX_,pX_); \
         ATL_vcxuld10(rY_,pY_); \
         break; \
      case 11 : \
         ATL_vcxuld11(rX_,pX_); \
         ATL_vcxuld11(rY_,pY_); \
         break; \
      case 12 : \
         ATL_vcxuld12(rX_,pX_); \
         ATL_vcxuld12(rY_,pY_); \
         break; \
      case 13 : \
         ATL_vcxuld13(rX_,pX_); \
         ATL_vcxuld13(rY_,pY_); \
         break; \
      case 14 : \
         ATL_vcxuld14(rX_,pX_); \
         ATL_vcxuld14(rY_,pY_); \
         break; \
      default: \
         ATL_vcxuld15(rX_,pX_); \
         ATL_vcxuld15(rY_,pY_); \
      } \
   }
   #define ATL_vcxldR(r_,p_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxld1(r_,p_); \
         break; \
      case 2 : \
         ATL_vcxld2(r_,p_); \
         break; \
      case 3 : \
         ATL_vcxld3(r_,p_); \
         break; \
      case 4 : \
         ATL_vcxld4(r_,p_); \
         break; \
      case 5 : \
         ATL_vcxld5(r_,p_); \
         break; \
      case 6 : \
         ATL_vcxld6(r_,p_); \
         break; \
      case 7 : \
         ATL_vcxld7(r_,p_); \
         break; \
      case 8 : \
         ATL_vcxld8(r_,p_); \
         break; \
      case 9 : \
         ATL_vcxld9(r_,p_); \
         break; \
      case 10 : \
         ATL_vcxld10(r_,p_); \
         break; \
      case 11 : \
         ATL_vcxld11(r_,p_); \
         break; \
      case 12 : \
         ATL_vcxld12(r_,p_); \
         break; \
      case 13 : \
         ATL_vcxld13(r_,p_); \
         break; \
      case 14 : \
         ATL_vcxld14(r_,p_); \
         break; \
      default: \
         ATL_vcxld15(r_,p_); \
      } \
   }
   #define ATL_vcxstR(p_,r_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxst1(p_,r_); \
         break; \
      case 2 : \
         ATL_vcxst2(p_,r_); \
         break; \
      case 3 : \
         ATL_vcxst3(p_,r_); \
         break; \
      case 4 : \
         ATL_vcxst4(p_,r_); \
         break; \
      case 5 : \
         ATL_vcxst5(p_,r_); \
         break; \
      case 6 : \
         ATL_vcxst6(p_,r_); \
         break; \
      case 7 : \
         ATL_vcxst7(p_,r_); \
         break; \
      case 8 : \
         ATL_vcxst8(p_,r_); \
         break; \
      case 9 : \
         ATL_vcxst9(p_,r_); \
         break; \
      case 10 : \
         ATL_vcxst10(p_,r_); \
         break; \
      case 11 : \
         ATL_vcxst11(p_,r_); \
         break; \
      case 12 : \
         ATL_vcxst12(p_,r_); \
         break; \
      case 13 : \
         ATL_vcxst13(p_,r_); \
         break; \
      case 14 : \
         ATL_vcxst14(p_,r_); \
         break; \
      default: \
         ATL_vcxst15(p_,r_); \
      } \
   }
   #define ATL_vcxuldR(r_,p_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxuld1(r_,p_); \
         break; \
      case 2 : \
         ATL_vcxuld2(r_,p_); \
         break; \
      case 3 : \
         ATL_vcxuld3(r_,p_); \
         break; \
      case 4 : \
         ATL_vcxuld4(r_,p_); \
         break; \
      case 5 : \
         ATL_vcxuld5(r_,p_); \
         break; \
      case 6 : \
         ATL_vcxuld6(r_,p_); \
         break; \
      case 7 : \
         ATL_vcxuld7(r_,p_); \
         break; \
      case 8 : \
         ATL_vcxuld8(r_,p_); \
         break; \
      case 9 : \
         ATL_vcxuld9(r_,p_); \
         break; \
      case 10 : \
         ATL_vcxuld10(r_,p_); \
         break; \
      case 11 : \
         ATL_vcxuld11(r_,p_); \
         break; \
      case 12 : \
         ATL_vcxuld12(r_,p_); \
         break; \
      case 13 : \
         ATL_vcxuld13(r_,p_); \
         break; \
      case 14 : \
         ATL_vcxuld14(r_,p_); \
         break; \
      default: \
         ATL_vcxuld15(r_,p_); \
      } \
   }
   #define ATL_vcxustR(p_,r_,n_) \
   { \
      switch(n_) \
      { \
      case 1 : \
         ATL_vcxust1(p_,r_); \
         break; \
      case 2 : \
         ATL_vcxust2(p_,r_); \
         break; \
      case 3 : \
         ATL_vcxust3(p_,r_); \
         break; \
      case 4 : \
         ATL_vcxust4(p_,r_); \
         break; \
      case 5 : \
         ATL_vcxust5(p_,r_); \
         break; \
      case 6 : \
         ATL_vcxust6(p_,r_); \
         break; \
      case 7 : \
         ATL_vcxust7(p_,r_); \
         break; \
      case 8 : \
         ATL_vcxust8(p_,r_); \
         break; \
      case 9 : \
         ATL_vcxust9(p_,r_); \
         break; \
      case 10 : \
         ATL_vcxust10(p_,r_); \
         break; \
      case 11 : \
         ATL_vcxust11(p_,r_); \
         break; \
      case 12 : \
         ATL_vcxust12(p_,r_); \
         break; \
      case 13 : \
         ATL_vcxust13(p_,r_); \
         break; \
      case 14 : \
         ATL_vcxust14(p_,r_); \
         break; \
      default: \
         ATL_vcxust15(p_,r_); \
      } \
   }
#endif    /* end VLEN test for remainder definitions */

#endif   /* end multiple inclusion guard */
