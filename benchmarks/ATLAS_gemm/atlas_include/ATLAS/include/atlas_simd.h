#ifndef ATLAS_SIMD_H
   #define  ATLAS_SIMD_H 1
#ifdef ATL_GAS_ARM64
   #define ATL_VECARM1 1
/*
 * On 32-bit ARM, disable SIMD unless NONIEEE flag is thrown
 */
#elif defined(ATL_GAS_ARM)
   #if !defined(ATL_NONIEEE) || !(defined(SREAL) || defined(SCPLX))
      #ifdef ATL_VLEN
         #undef ATL_VLEN
      #endif
      #define ATL_VLEN 1
   #else
      #define ATL_NEON 1
   #endif
#endif
//#undef ATL_AVX
//#undef ATL_SSE3
//#undef ATL_SSE2
//#undef ATL_SSE1
//#define ATL_FRCGNUVEC 1
//#define ATL_VLEN 32
/*
 * This header files contains wrappers to allow you to use SIMD vector
 * extensions in a very simplified way in a type-independent manner.
 * ATL_VLEN is treated differently, depending on whether we are using
 * system-dependent vectorization (eg., AVX, VSX, etc.) or gnu vectorization:
 * - For gnu vectorization, ATL_VLEN must be defined as a power of 2.
 * - For non-gnu vec ATL_VLEN should match the system, or be undefined.
* All macro funcs first arg is the destination.  vr stands for vector register.
 * We support the following miscellaneous instructions:
 *    ATL_vzero(vr)       : zero all vr entries
 *    ATL_vcopy(vrd, vrs) : vrd = vrs
 *
 * We support 5 load/store operations (where p is a pointer):
 *    ATL_vbcast(vr, p) : broadcast pointed-to scalar to all vr entries
 *    ATL_vuld(vr, p)   : unaligned load from ptr to vr
 *    ATL_vld(vr, p)    : aligned load from ptr to vr
 *    ATL_vust(p, vr)   : unaligned store to ptr from vr
 *    ATL_vst(p, vr)    : aligned store to ptr from vr
 * NOTE: if VLEN < native length, all  usually assume unaligned data,
 *       and (except bcast) become a series of instructions rather than one.
 *
 * We support 3 computational macros:
 * ATL_vadd(vrd, vrs1, vrs2) : vrd = vrs1 + vrs2
 * ATL_vsub(vrd, vrs1, vrs2) : vrd = vrs1 - vrs2
 * ATL_vmul(vrd, vrs1, vrs2) : vrd = vrs1 * vrs2
 * ATL_vmac(vrd, vrs1, vrs2) : vrd += vrs1 * vrs2
 *
 * For L1BLAS, we support a vector being summed to a scalar.
 * NOTE: srd must be a scalar reg
 *    ATL_vrsum1(srd, vrs)        : srd = sum(vrs[:])
 * For k-vec amm, we need to support summing up VLEN different accumulators,
 * and placing the result in one destination.  This requires the using code
 * to know VLEN (perhaps with a cpp if/else chain), but allows us to get
 * high performance on C stores.  We show the answer for vvrsum2 & 4, but
 * remember that only vvrsumVLEN will actually exist:
 *    ATL_vvrsum2(d, s0, s1) : d[0] = sum(s0[:]), d[1] = sum(s1[:])
 *    ATL_vvrsum4(d, s1, s2, s3, s4) : d[0:3] = sum(s0:4)
 */
/*
 * If ATL_VLEN is set, force gnuvec if it isn't set to the native length
 */
#ifdef ATL_VLEN
   #ifdef ATL_VSX
      #if ((defined(SREAL) || defined(SCPLX)) && ATL_VLEN != 4) || \
          ((defined(DREAL) || defined(DCPLX)) && ATL_VLEN != 2)
         #define ATL_FRCGNUVEC
      #endif
   #elif defined(ATL_VXZ)
      #if ATL_VLEN != 2;
         #define ATL_FRCGNUVEC
      #endif
   #elif defined(ATL_NEON)
      #if ((defined(SREAL) || defined(SCPLX)) && ATL_VLEN != 4) || \
          ((defined(DREAL) || defined(DCPLX)) && ATL_VLEN != 1)
         #define ATL_FRCGNUVEC
      #endif
   #elif defined(ATL_VECARM1)
      #if ((defined(SREAL) || defined(SCPLX)) && ATL_VLEN != 4) || \
          ((defined(DREAL) || defined(DCPLX)) && ATL_VLEN != 2)
         #define ATL_FRCGNUVEC
      #endif
   #elif defined(ATL_AVXMAC)
      #if ((defined(SREAL) || defined(SCPLX)) && ATL_VLEN != 8) || \
          ((defined(DREAL) || defined(DCPLX)) && ATL_VLEN != 4)
         #define ATL_FRCGNUVEC
      #endif
   #elif defined(ATL_AVX)
      #if ((defined(SREAL) || defined(SCPLX)) && ATL_VLEN != 8) || \
          ((defined(DREAL) || defined(DCPLX)) && ATL_VLEN != 4)
         #define ATL_FRCGNUVEC
      #endif
   #elif defined(ATL_SSE2)
      #if ((defined(SREAL) || defined(SCPLX)) && ATL_VLEN != 4) || \
          ((defined(DREAL) || defined(DCPLX)) && ATL_VLEN != 2)
         #define ATL_FRCGNUVEC
      #endif
   #elif defined(ATL_SSE1)
      #if ((defined(SREAL) || defined(SCPLX)) && ATL_VLEN != 4) || \
          ((defined(DREAL) || defined(DCPLX)) && ATL_VLEN != 2)
         #define ATL_FRCGNUVEC
      #endif
   #endif
/*
 * Compute ATL_VLEN based on SIMD extension & TYPE, if not already set
 */
#else
   #ifdef ATL_VSX
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLEN 4
      #else
         #define ATL_VLEN 2
      #endif
   #elif defined(ATL_VXZ)
      #define ATL_VLEN 2
   #elif defined(ATL_NEON)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLEN 4
      #else
         #define ATL_VLEN 1
      #endif
   #elif defined(ATL_VECARM1)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLEN 4
      #else
         #define ATL_VLEN 2
      #endif
   #elif defined(ATL_AVXMAC)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLEN 8
      #else
         #define ATL_VLEN 4
      #endif
   #elif defined(ATL_AVX)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLEN 8
      #else
         #define ATL_VLEN 4
      #endif
   #elif defined(ATL_SSE2)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLEN 4
      #else
         #define ATL_VLEN 2
      #endif
   #elif defined(ATL_SSE1)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLEN 4
      #else
         #define ATL_VLEN 2
      #endif
   #endif
#endif
/*
 * Derive ATL_VLENb (veclen in bytes) from ATL_VLEN
 */
#ifndef ATL_VLEN
   #error "ATL_VLEN not defined!"
#else
   #if ATL_VLEN == 1
      #define ATL_VLSH 0
      #define ATL_DivByVLEN(i_) (i_)
      #define ATL_MulByVLEN(i_) (i_)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLENb 4
      #else
         #define ATL_VLENb 8
      #endif
   #elif ATL_VLEN == 2
      #define ATL_VLSH 1
      #define ATL_DivByVLEN(i_) ((i_)>>1)
      #define ATL_MulByVLEN(i_) ((i_)<<1)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLENb 8
      #else
         #define ATL_VLENb 16
      #endif
   #elif ATL_VLEN == 4
      #define ATL_VLSH 2
      #define ATL_DivByVLEN(i_) ((i_)>>2)
      #define ATL_MulByVLEN(i_) ((i_)<<2)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLENb 16
      #else
         #define ATL_VLENb 32
      #endif
   #elif ATL_VLEN == 8
      #define ATL_VLSH 3
      #define ATL_DivByVLEN(i_) ((i_)>>3)
      #define ATL_MulByVLEN(i_) ((i_)<<3)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLENb 32
      #else
         #define ATL_VLENb 64
      #endif
   #elif ATL_VLEN == 16
      #define ATL_VLSH 4
      #define ATL_DivByVLEN(i_) ((i_)>>4)
      #define ATL_MulByVLEN(i_) ((i_)<<4)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLENb 64
      #else
         #define ATL_VLENb 128
      #endif
   #elif ATL_VLEN == 32
      #define ATL_VLSH 5
      #define ATL_DivByVLEN(i_) ((i_)>>5)
      #define ATL_MulByVLEN(i_) ((i_)<<5)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLENb 128
      #else
         #define ATL_VLENb 256
      #endif
   #else
      #define ATL_DivByVLEN(i_) ((i_)/ATL_VLEN)
      #define ATL_MulByVLEN(i_) ((i_)*ATL_VLEN)
      #if defined(SREAL) || defined(SCPLX)
         #define ATL_VLENb (ATL_VLEN*4)
      #else
         #define ATL_VLENb (ATL_VLEN*8)
      #endif
   #endif
#endif
/*
 * We may want to force use of GNU vectorization on any platform.  If so,
 * undefine any defined system-specific vectorization.
 * Undefine all vectorization if VLEN=1 (scalar code)!
 */
#if defined(ATL_FRCGNUVEC) || ATL_VLEN < 2
   #ifdef ATL_NEON
      #undef ATL_NEON
   #endif
   #ifdef ATL_VECARM1
      #undef ATL_VECARM1
   #endif
   #ifdef ATL_SSE1
      #undef ATL_SSE1
   #endif
   #ifdef ATL_SSE2
      #undef ATL_SSE2
   #endif
   #ifdef ATL_SSE3
      #undef ATL_SSE3
   #endif
   #ifdef ATL_AVX
      #undef ATL_AVX
   #endif
   #ifdef ATL_AVXMAC
      #undef ATL_AVXMAC
   #endif
   #ifdef ATL_VSXZ
      #undef ATL_VSXZ
   #endif
   #ifdef ATL_VSX
      #undef ATL_VSX
   #endif
   #if ATL_VLEN < 2 && defined(ATL_FRCGNUVEC)
       #undef ATL_FRCGNUVEC
   #endif
#endif
/*
 * Now set computational macros based on ATL_VLEN & SIMD defines
 */
#if defined(ATL_VSX)
   #include <altivec.h>
/*
 * Older gcc don't support don't support xxpermdi, merge[o,e], xxsel
 */
   #if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ > 9) || \
        (__GNUC__ == 4 && __GNUC_MINOR__ == 9 && __GNU_PATHLEVEL__ > 1) || \
        !defined(__GNUC__)
      #define ATL_FULLGCCVSX 1
   #else
      #define ATL_FULLGCCVSX 0
   #endif
   #if defined(SREAL) || defined(SCPLX)
      #define ATL_VTYPE vector float
      #if ATL_VLEN != 4
         #error "VSX supports only VLEN = 4 for floats!"
      #endif
   #else        /* double precision */
      #define ATL_VTYPE vector double
      #if ATL_VLEN != 2
         #error "VSX supports only VLEN = 2 for doubles!"
      #endif
   #endif
   #define ATL_vzero(v_) v_ = vec_splats((TYPE)0.0)
   #define ATL_vcopy(d_, s_) d_ = s_
   #define ATL_vbcast(v_, p_) v_ =  vec_splats(*((TYPE*)(p_)))
   #define ATL_vuld(v_, p_) v_ = vec_vsx_ld(0, (ATL_VTYPE*)(p_))
   #define ATL_vld(v_, p_) v_ = vec_ld(0, (ATL_VTYPE*)(p_))
   #define ATL_vust(p_, v_) vec_vsx_st(v_, 0, (ATL_VTYPE*)(p_))
   #define ATL_vst(p_, v_)  vec_st(v_, 0, (ATL_VTYPE*)(p_))
   #define ATL_vadd(d_, s1_, s2_) d_ =  vec_add(s1_, s2_)
   #define ATL_vsub(d_, s1_, s2_) d_ =  vec_sub(s1_, s2_)
   #define ATL_vmul(d_, s1_, s2_) d_ =  vec_mul(s1_, s2_)
   #define ATL_vmac(d_, s1_, s2_) d_ = vec_madd(s1_, s2_, d_)
   #if defined(SREAL) || defined(SCPLX)
      #define ATL_vrsum1(d_, s_) \
      { \
         VTYPE t_; \
         d_ = vec_splat(s_, 1); \
         d_ = vec_add(d_, s_) ; \
         t_ = vec_splat(s_, 2); \
         d_ = vec_add(d_, t_) ; \
         t_ = vec_splat(s_, 3); \
         d_ = vec_add(d_, t_) ; \
      }
      #if ATL_FULLGCCVSX
         #define ATL_vvrsum4(s0_, s1_, s2_, s3_) \
         {  ATL_VTYPE t_, h_;                    /*{s0d,s0c,s0b,s0a}*/\
            t_ = vec_vmrghw(s0_, s1_);           /*{s1b,s0b,s1a,s0a}*/\
            s0_ = vec_vmrglw(s0_, s1_);          /* s1d,s0d,s1c,s0c}*/ \
            s0_ = ATL_vadd(s0_, s0_, t_);        /*{s1bd,s0bd,s1ac,s0ac}*/\
            h_ = vec_vmrghw(s2_, s3_);           /*{s3b,s2b,s3a,s2a}*/\
            s2_ = vec_vmrglw(s2_, s3_);          /*{s3d,s2d,s3c,s2c}*/ \
            s2_ = ATL_vadd(s2_, s2_, h_);        /*{s3bd,s2bd,s3ac,s2ac}*/\
            t_ =  vec_xxpermdi(s0_, s2_, 0);     /*{s3ac,s2ac,s1ac,s0ac}*/\
            s0_ = vec_xxpermdi(s0_, s2_, 3);     /*{s3bd,s2bd,s1bd,s0bd}*/ \
            ATL_vadd(s0_, s0_, t_); \
            s0_ = vec_xxpermdi(s0_, s0_, 2);     /* pwr8 endian-insanity */ \
         }
         #define ATL_vvrsum2(s0_, s1_) \
         {  ATL_VTYPE t_, h_;                    /*{s0d,s0c,s0b,s0a}*/\
            t_ = vec_vmrghw(s0_, s1_);           /*{s1b,s0b,s1a,s0a}*/\
            s0_ = vec_vmrglw(s0_, s1_);          /*{s1d,s0d,s1c,s0c}*/ \
            s0_ = ATL_vadd(s0_, s0_, t_);        /*{s1bd,s0bd,s1ac,s0ac}*/\
            t_ =  vec_xxpermdi(s0_, s0_, 0);     /*{s1ac,s0ac,s1ac,s0ac}*/\
            s0_ = vec_xxpermdi(s0_, s0_, 3);     /*{s1bd,s0bd,s1bd,s0bd}*/ \
            ATL_vadd(s0_, s0_, t_); \
            s0_ = vec_xxpermdi(s0_, s0_, 2);     /* pwr8 endian-insanity */ \
         }
         #define ATL_vvrsum1(s0_) \
         {  ATL_VTYPE t_, h_;                    /*{s0d,s0c,s0b,s0a}*/\
            t_ = vec_vmrghw(s0_, s0_);           /*{s0b,s0b,s0a,s0a}*/\
            s0_ = vec_vmrglw(s0_, s0_);          /*{s0d,s0d,s0c,s0c}*/ \
            s0_ = ATL_vadd(s0_, s0_, t_);        /*{s0bd,s0bd,s0ac,s0ac}*/\
            t_ =  vec_xxpermdi(s0_, s0_, 0);     /*{s0ac,s0ac,s0ac,s0ac}*/\
            s0_ = vec_xxpermdi(s0_, s0_, 3);     /*{s0bd,s0bd,s0bd,s0bd}*/ \
            ATL_vadd(s0_, s0_, t_); \
            s0_ = vec_xxpermdi(s0_, s0_, 2);     /* pwr8 endian-insanity */ \
         }
      #endif
      #define ATL_vsplat0(d_, s_) d_ = vec_splat(s_, 0)
      #define ATL_vsplat1(d_, s_) d_ = vec_splat(s_, 1)
      #define ATL_vsplat2(d_, s_) d_ = vec_splat(s_, 2)
      #define ATL_vsplat3(d_, s_) d_ = vec_splat(s_, 3)
   #else
      #define ATL_vrsum1(d_, s_) \
      { \
         d_ = vec_splat(s_, 1); \
         d_ = vec_add(d_, s_) ; \
      }
      #if ATL_FULLGCCVSX
         #define ATL_vvrsum2(s0_, s1_) \
         {  ATL_VTYPE t_;\
            t_ =  vec_xxpermdi(s0_, s1_, 0); \
            s0_ = vec_xxpermdi(s0_, s1_, 3); \
            ATL_vadd(s0_, s0_, t_); \
            s0_ = vec_xxpermdi(s0_, s0_, 2); /* pwr8 endian-insanity */ \
         }
         #define ATL_vvrsum1(s0_) \
         {  ATL_VTYPE t_;\
            t_ =  vec_xxpermdi(s0_, s0_, 0); \
            ATL_vadd(s0_, s0_, t_); \
         }
      #else
         #define ATL_vvrsum1(s0_) \
         {  ATL_VTYPE t_;\
            t_ = vec_splat(s0_, 1); \
            ATL_vadd(s0_, s0_, t_); \
         }
      #endif
      #define ATL_vsplat0(d_, s_) d_ = vec_splat(s_, 0)
      #define ATL_vsplat1(d_, s_) d_ = vec_splat(s_, 1)
   #endif
#elif defined(ATL_VXZ)
   #include <vecintrin.h>

   #if ATL_VLEN != 2
      #error "VSXZ supports only VLEN = 2!"
   #endif
   #define ATL_VTYPE vector double
   #if (defined(DREAL) || defined(DCPLX))
      #define ATL_vld(v_, p_) {v_[0] = *(p_); v_[1] = (p_)[1]; }
      #define ATL_vst(p_, v_)  {*(p_) = v_[0]; (p_)[1] = v_[1];}
   #else
      #define ATL_vld(v_, p_) v_ = vec_ld2f(p_);
      #define ATL_vst(p_, v_) vec_st2f(v_, p_);
   #endif
   #define ATL_vzero(v_) v_ = vec_splats((TYPE)0.0)
   #define ATL_vcopy(d_, s_) d_ = s_
   #define ATL_vbcast(v_, p_) v_ =  vec_splats(*((TYPE*)(p_)))
   #define ATL_vuld(v_, p_) ATL_vld(v_, p_)
   #define ATL_vust(p_, v_) ATL_vst(p_, v_)
   #define ATL_vadd(d_, s1_, s2_) d_ =  s1_ + s2_
   #define ATL_vsub(d_, s1_, s2_) d_ =  s1_ - s2_
   #define ATL_vmul(d_, s1_, s2_) d_ =  s1_ * s2_
   #define ATL_vmac(d_, s1_, s2_) d_ = vec_madd(s1_, s2_, d_)
   #define ATL_vvrsum1(s0_) \
   {  ATL_VTYPE t_;\
      t_ = vec_splat(s0_, 1); \
      s0 += t_; \
   }
   #define ATL_vsplat0(d_, s_) d_ = vec_splat(s_, 0)
   #define ATL_vsplat1(d_, s_) d_ = vec_splat(s_, 1)
#elif defined(ATL_NEON) && (defined(SREAL) || defined(SCPLX))
   #include "arm_neon.h"
   #define ATL_VTYPE float32x4_t
  #define ATL_vzero(v_) v_ = vdupq_n_f32(0.0f)
   #define ATL_vbcast(v_, p_) v_ =  vdupq_n_f32(*(p_));
   #define ATL_vld(v_, p_) v_ = vld1q_f32(p_)
   #define ATL_vst(p_, v_) vst1q_f32(p_, v_)
   #define ATL_vadd(d_, s1_, s2_) d_ = vaddq_f32(s1_, s2_)
   #define ATL_vsub(d_, s1_, s2_) d_ = vsubq_f32(s1_, s2_)
   #define ATL_vmul(d_, s1_, s2_) d_ = vmulq_f32(s1_, s2_)
   #define ATL_vmac(d_, s1_, s2_) d_ = vmlaq_f32(d_, s1_, s2_)
   #define ATL_vrsum1(d_, s_) \
   {  ATL_VTYPE t4_; float32x2_t t2_, t1_; \
      t1_ = vget_high_f32(s_); \
      t2_ = vget_low_f32(s_); \
      t2_ = vpadd_f32(t1_, t2_); \
      d_ = vget_lane_f32(t2_, 0); \
      d_ += vget_lane_f32(t2_, 1); \
   }
   #define ATL_vvrsum4(s0_, s1_, s2_, s3_) \
   { ATL_VTYPE t0_, t1_; \
      t0_[0] = s0_[0]; \
      t0_[1] = s1_[0]; \
      t0_[2] = s2_[0]; \
      t0_[3] = s3_[0]; \
      t1_[0] = s0_[1]; \
      t1_[1] = s1_[1]; \
      t1_[2] = s2_[1]; \
      t1_[3] = s3_[1]; \
      t0_ = vaddq_f32(t0_, t1_); \
      t1_[0] = s0_[2]; \
      t1_[1] = s1_[2]; \
      t1_[2] = s2_[2]; \
      t1_[3] = s3_[2]; \
      t0_ = vaddq_f32(t0_, t1_); \
      t1_[0] = s0_[3]; \
      t1_[1] = s1_[3]; \
      t1_[2] = s2_[3]; \
      t1_[3] = s3_[3]; \
      s0_ = vaddq_f32(t0_, t1_); \
   }
   #define ATL_vsplat0(d_, s_) d_ = vmovq_n_f32(vgetq_lane_f32(s_, 0))
   #define ATL_vsplat1(d_, s_) d_ = vmovq_n_f32(vgetq_lane_f32(s_, 1))
   #define ATL_vsplat2(d_, s_) d_ = vmovq_n_f32(vgetq_lane_f32(s_, 2))
   #define ATL_vsplat3(d_, s_) d_ = vmovq_n_f32(vgetq_lane_f32(s_, 3))
   #define ATL_vuld(v_, p_) ATL_vld(v_, p_)
   #define ATL_vust(p_, v_) ATL_vst(p_, v_)
#elif defined(ATL_VECARM1)
   #include "arm_neon.h"
   #if defined(SREAL) || defined(SCPLX)
      #define ATL_VTYPE float32x4_t
   #else
      #define ATL_VTYPE float64x2_t
   #endif
   #if defined(SREAL) || defined(SCPLX)
      #define ATL_vzero(v_) v_ = vdupq_n_f32(0.0f)
      #define ATL_vbcast(v_, p_) v_ =  vld1q_dup_f32(p_)
      #define ATL_vld(v_, p_) v_ = vld1q_f32(p_)
      #define ATL_vst(p_, v_) vst1q_f32(p_, v_)
      #define ATL_vadd(d_, s1_, s2_) d_ = vaddq_f32(s1_, s2_)
      #define ATL_vsub(d_, s1_, s2_) d_ = vsubq_f32(s1_, s2_)
      #define ATL_vmul(d_, s1_, s2_) d_ = vmulq_f32(s1_, s2_)
      #define ATL_vmac(d_, s1_, s2_) d_ = vfmaq_f32(d_, s1_, s2_)
      #define ATL_vrsum1(d_, s_) \
      {  ATL_VTYPE t4_; float32x2_t t2_, t1_; \
         t1_ = vget_high_f32(s_); \
         t2_ = vget_low_f32(s_); \
         t2_ = vpadd_f32(t1_, t2_); \
         d_ = vget_lane_f32(t2_, 0); \
         d_ += vget_lane_f32(t2_, 1); \
      }
      #define ATL_vvrsum4(s0_, s1_, s2_, s3_) \
      { ATL_VTYPE t0_, t1_; \
         t0_[0] = s0_[0]; \
         t0_[1] = s1_[0]; \
         t0_[2] = s2_[0]; \
         t0_[3] = s3_[0]; \
         t1_[0] = s0_[1]; \
         t1_[1] = s1_[1]; \
         t1_[2] = s2_[1]; \
         t1_[3] = s3_[1]; \
         t0_ = vaddq_f32(t0_, t1_); \
         t1_[0] = s0_[2]; \
         t1_[1] = s1_[2]; \
         t1_[2] = s2_[2]; \
         t1_[3] = s3_[2]; \
         t0_ = vaddq_f32(t0_, t1_); \
         t1_[0] = s0_[3]; \
         t1_[1] = s1_[3]; \
         t1_[2] = s2_[3]; \
         t1_[3] = s3_[3]; \
         s0_ = vaddq_f32(t0_, t1_); \
      }
      #define ATL_vsplat0(d_, s_) d_ = vdupq_laneq_f32(s_, 0)
      #define ATL_vsplat1(d_, s_) d_ = vdupq_laneq_f32(s_, 1)
      #define ATL_vsplat2(d_, s_) d_ = vdupq_laneq_f32(s_, 2)
      #define ATL_vsplat3(d_, s_) d_ = vdupq_laneq_f32(s_, 3)
   #else  /* double */
      #define ATL_vzero(v_) v_ = vdupq_n_f64(0.0)
      #define ATL_vbcast(v_, p_) v_ =  vld1q_dup_f64(p_)
      #define ATL_vld(v_, p_) v_ = vld1q_f64(p_)
      #define ATL_vst(p_, v_) vst1q_f64(p_, v_)
      #define ATL_vadd(d_, s1_, s2_) d_ = vaddq_f64(s1_, s2_)
      #define ATL_vsub(d_, s1_, s2_) d_ = vsubq_f64(s1_, s2_)
      #define ATL_vmul(d_, s1_, s2_) d_ = vmulq_f64(s1_, s2_)
      #define ATL_vmac(d_, s1_, s2_) d_ = vfmaq_f64(d_, s1_, s2_)
      #define ATL_vrsum1(d_, s_) d_ = vget_low_f64(vpaddq_f64(s_, s_))
      #define ATL_vvrsum2(s0_, s1_) s0_ = vpaddq_f64(s0_, s1_)
      #define ATL_vsplat0(d_, s_) d_ = vdupq_laneq_f64(s_, 0)
      #define ATL_vsplat1(d_, s_) d_ = vdupq_laneq_f64(s_, 1)
   #endif
   #define ATL_vuld(v_, p_) ATL_vld(v_, p_)
   #define ATL_vust(p_, v_) ATL_vst(p_, v_)
#elif defined(ATL_AVXMAC) || defined(ATL_AVX)
   #include <immintrin.h>
   #if defined(SREAL) || defined(SCPLX)
      #if ATL_VLEN != 8
         #error "VLEN != 8 not supported for AVX or AVX2!"
      #endif
      #define ATL_VTYPE __m256
      #define ATL_vzero(v_) v_ = _mm256_setzero_ps()
      #define ATL_vbcast(v_, p_) v_ =  _mm256_broadcast_ss(p_)
      #define ATL_vuld(v_, p_) v_ = _mm256_loadu_ps(p_)
      #define ATL_vld(v_, p_) v_ = _mm256_load_ps(p_)
      #define ATL_vust(p_, v_) _mm256_storeu_ps(p_, v_)
      #define ATL_vst(p_, v_) _mm256_store_ps(p_, v_)
      #define ATL_vadd(d_, s1_, s2_) d_ =  _mm256_add_ps(s1_, s2_)
      #define ATL_vsub(d_, s1_, s2_) d_ =  _mm256_sub_ps(s1_, s2_)
      #define ATL_vmul(d_, s1_, s2_) d_ =  _mm256_mul_ps(s1_, s2_)
      #ifdef ATL_AVXMAC
         #define ATL_vmac(d_, s1_, s2_) \
            d_ = _mm256_fmadd_ps(s1_, s2_, d_)
      #else
         #define ATL_vmac(d_, s1_, s2_) \
         { ATL_VTYPE t_; \
            t_ = _mm256_mul_ps(s1_, s2_); \
            d_ = _mm256_add_ps(t_, d_); \
         }
      #endif
      #define ATL_vvrsum8(s0_, s1_, s2_, s3_, s4_, s5_, s6_, s7_) \
      { \
         s0_ = _mm256_hadd_ps(s0_, s1_); \
            /*{s1gh,s1ef,s0gh,s0ef,s1cd,s1ab,s0cd,s0ab}*/\
         s2_ = _mm256_hadd_ps(s2_, s3_); \
            /*{s3gh,s3ef,s2gh,s2ef,s3cd,s3ab,s2cd,s2ab}*/\
         s4_ = _mm256_hadd_ps(s4_, s5_); \
            /*{s5gh,s5ef,s4gh,s4ef,s5cd,s5ab,s4cd,s4ab}*/\
         s6_ = _mm256_hadd_ps(s6_, s7_); \
            /*{s7gh,s7ef,s6gh,s6ef,s7cd,s7ab,s6cd,s6ab}*/\
         s0_ = _mm256_hadd_ps(s0_, s2_); \
            /*{s3e-h,s2e-h,s1e-h,s0e-g,s3a-d,s2a-d,s1a-d,s0a-d}*/\
         s4_ = _mm256_hadd_ps(s4_, s6_); \
            /*{s7e-h,s6e-h,s5e-h,s4e-g,s7a-d,s6a-d,s5a-d,s4a-d}*/\
         s1_ = _mm256_permute2f128_ps(s0_, s4_, 0x31); \
            /*{s7e-h,s6e-h,s5e-h,s4e-g,s3e-h,s2e-h,s1e-h,s0e-g}*/\
         s0_ = _mm256_permute2f128_ps(s0_, s4_, 0x20); \
            /*{s7a-d,s6a-d,s5a-d,s4a-d,s3a-d,s2a-d,s1a-d,s0a-d}*/\
         ATL_vadd(s0_, s0_, s1_); \
      }
      #define ATL_vvrsum4(s0_, s1_, s2_, s3_) \
      { \
         s0_ = _mm256_hadd_ps(s0_, s1_); \
            /*{s1gh,s1ef,s0gh,s0ef,s1cd,s1ab,s0cd,s0ab}*/\
         s2_ = _mm256_hadd_ps(s2_, s3_); \
            /*{s3gh,s3ef,s2gh,s2ef,s3cd,s3ab,s2cd,s2ab}*/\
         s0_ = _mm256_hadd_ps(s0_, s2_); \
            /*{s3e-h,s2e-h,s1e-h,s0e-g,s3a-d,s2a-d,s1a-d,s0a-d}*/\
         s1_ = _mm256_permute2f128_ps(s0_, s0_, 0x31); \
            /*{s3e-h,s2e-h,s1e-h,s0e-g,s3e-h,s2e-h,s1e-h,s0e-g}*/\
         s0_ = _mm256_permute2f128_ps(s0_, s0_, 0x20); \
            /*{s3a-d,s2a-d,s1a-d,s0a-d,s3a-d,s2a-d,s1a-d,s0a-d}*/\
         ATL_vadd(s0_, s0_, s1_); \
      }
      #define ATL_vvrsum2(s0_, s1_) \
      { \
         s0_ = _mm256_hadd_ps(s0_, s1_); \
            /*{s1gh,s1ef,s0gh,s0ef,s1cd,s1ab,s0cd,s0ab}*/\
         s0_ = _mm256_hadd_ps(s0_, s0_); \
            /*{s1e-h,s0e-h,s1e-h,s0e-g,s1a-d,s0a-d,s1a-d,s0a-d}*/\
         s1_ = _mm256_permute2f128_ps(s0_, s0_, 0x31); \
            /*{s1e-h,s0e-h,s1e-h,s0e-g,s1e-h,s0e-h,s1e-h,s0e-g}*/\
         s0_ = _mm256_permute2f128_ps(s0_, s0_, 0x20); \
            /*{s1a-d,s0a-d,s1a-d,s0a-d,s1a-d,s0a-d,s1a-d,s0a-d}*/\
         ATL_vadd(s0_, s0_, s1_); \
      }
      #define ATL_vvrsum1(s0_) \
      {  ATL_VTYPE t1_; \
         s0_ = _mm256_hadd_ps(s0_, s0_); \
            /*{s0gh,s0ef,s0gh,s0ef,s0cd,s0ab,s0cd,s0ab}*/\
         s0_ = _mm256_hadd_ps(s0_, s0_); \
            /*{s0e-h,s0e-h,s0e-h,s0e-g,s0a-d,s0a-d,s0a-d,s0a-d}*/\
         t1_ = _mm256_permute2f128_ps(s0_, s0_, 0x31); \
            /*{s0e-h,s0e-h,s0e-h,s0e-g,s0e-h,s0e-h,s0e-h,s0e-g}*/\
         s0_ = _mm256_permute2f128_ps(s0_, s0_, 0x20); \
            /*{s0a-d,s0a-d,s0a-d,s0a-d,s0a-d,s0a-d,s0a-d,s0a-d}*/\
         ATL_vadd(s0_, s0_, t1_); \
      }
      #define ATL_vsplat0(d_, s_) \
      { \
         d_ = _mm256_shuffle_ps(s_, s_, 0); \
         d_ = _mm256_insertf128_ps(d_, _mm256_extractf128_ps(d_,0), 1); \
      }
      #define ATL_vsplat1(d_, s_) \
      { \
         d_ = _mm256_shuffle_ps(s_, s_, 0x55); \
         d_ = _mm256_insertf128_ps(d_, _mm256_extractf128_ps(d_,0), 1); \
      }
      #define ATL_vsplat2(d_, s_) \
      { \
         d_ = _mm256_shuffle_ps(s_, s_, 0xAA); \
         d_ = _mm256_insertf128_ps(d_, _mm256_extractf128_ps(d_,0), 1); \
      }
      #define ATL_vsplat3(d_, s_) \
      { \
         d_ = _mm256_shuffle_ps(s_, s_, 0xFF); \
         d_ = _mm256_insertf128_ps(d_, _mm256_extractf128_ps(d_,0), 1); \
      }
      #define ATL_vsplat4(d_, s_) \
      { \
         d_ = _mm256_shuffle_ps(s_, s_, 0); \
         d_ = _mm256_insertf128_ps(d_, _mm256_extractf128_ps(d_,1), 0); \
      }
      #define ATL_vsplat5(d_, s_) \
      { \
         d_ = _mm256_shuffle_ps(s_, s_, 0x55); \
         d_ = _mm256_insertf128_ps(d_, _mm256_extractf128_ps(d_,1), 0); \
      }
      #define ATL_vsplat6(d_, s_) \
      { \
         d_ = _mm256_shuffle_ps(s_, s_, 0xAA); \
         d_ = _mm256_insertf128_ps(d_, _mm256_extractf128_ps(d_,1), 0); \
      }
      #define ATL_vsplat7(d_, s_) \
      { \
         d_ = _mm256_shuffle_ps(s_, s_, 0xFF); \
         d_ = _mm256_insertf128_ps(d_, _mm256_extractf128_ps(d_,1), 0); \
      }
   #else        /* double precision */
      #if ATL_VLEN != 4
         #error "AVX SUPPORTS ONLY VLEN=4 FOR DOUBLE!"
      #endif
      #define ATL_VTYPE __m256d
      #define ATL_vzero(v_) v_ = _mm256_setzero_pd()
      #define ATL_vbcast(v_, p_) v_ =  _mm256_broadcast_sd(p_)
      #define ATL_vuld(v_, p_) v_ = _mm256_loadu_pd(p_)
      #define ATL_vld(v_, p_) v_ = _mm256_load_pd(p_)
      #define ATL_vust(p_, v_) _mm256_storeu_pd(p_, v_)
      #define ATL_vst(p_, v_) _mm256_store_pd(p_, v_)
      #define ATL_vadd(d_, s1_, s2_) d_ =  _mm256_add_pd(s1_, s2_)
      #define ATL_vsub(d_, s1_, s2_) d_ =  _mm256_sub_pd(s1_, s2_)
      #define ATL_vmul(d_, s1_, s2_) d_ =  _mm256_mul_pd(s1_, s2_)
      #ifdef ATL_AVXMAC
         #define ATL_vmac(d_, s1_, s2_) \
            d_ = _mm256_fmadd_pd(s1_, s2_, d_)
      #else
         #define ATL_vmac(d_, s1_, s2_) \
         { ATL_VTYPE t_; \
            t_ = _mm256_mul_pd(s1_, s2_); \
            d_ = _mm256_add_pd(t_, d_); \
         }
      #endif
      #define ATL_vrsum1(d_, s_) \
      {  __m128d t_; \
         t_ = _mm_add_pd(_mm256_extractf128_pd(s_, 0), \
                         _mm256_extractf128_pd(s_, 1)); \
         t_ = _mm_hadd_pd(t_, t_); \
         d_ = _mm_cvtsd_f64(t_); \
      }
      #define ATL_vvrsum4(s0_, s1_, s2_, s3_) \
      { \
         s0_ = _mm256_hadd_pd(s0_, s1_); /*{s1cd,s0cd,s1ab,s0ab}*/ \
         s2_ = _mm256_hadd_pd(s2_, s3_); /*{s3cd,s2cd,s3ab,s2ab}*/ \
         s1_ = _mm256_permute2f128_pd(s0_, s2_,0x31);/*{s3cd,s2cd,s1cd,s0cd}*/ \
         s0_ = _mm256_permute2f128_pd(s0_, s2_,0x20);/*{s3ab,s2ab,s1ab,s0ab}*/ \
         ATL_vadd(s0_, s0_, s1_); \
      }
      #define ATL_vvrsum2(s0_, s1_) \
      { \
         s0_ = _mm256_hadd_pd(s0_, s1_); /*{s1cd,s0cd,s1ab,s0ab}*/ \
         s1_ = _mm256_permute2f128_pd(s0_, s1_,0x31);/*{s3cd,s2cd,s1cd,s0cd}*/ \
         ATL_vadd(s0_, s0_, s1_); \
      }
      #define ATL_vvrsum1(s0_) \
      { ATL_VTYPE s1_; \
         s0_ = _mm256_hadd_pd(s0_, s0_); /*{s0cd,s0cd,s0ab,s0ab}*/ \
         s1_ = _mm256_permute2f128_pd(s0_, s1_,0x31);/*{s0cd,s0cd,s0cd,s0cd}*/ \
         ATL_vadd(s0_, s0_, s1_); \
      }
      #define ATL_vsplat0(d_, s_) \
      { \
         d_ = _mm256_unpacklo_pd(s_, s_); \
         d_ = _mm256_insertf128_pd(d_, _mm256_extractf128_pd(d_,0), 1); \
      }
      #define ATL_vsplat2(d_, s_) \
      { \
         d_ = _mm256_unpacklo_pd(s_, s_); \
         d_ = _mm256_insertf128_pd(d_, _mm256_extractf128_pd(d_,1), 0); \
      }
      #define ATL_vsplat1(d_, s_) \
      { \
         d_ = _mm256_unpackhi_pd(s_, s_); \
         d_ = _mm256_insertf128_pd(d_, _mm256_extractf128_pd(d_,0), 1); \
      }
      #define ATL_vsplat3(d_, s_) \
      { \
         d_ = _mm256_unpackhi_pd(s_, s_); \
         d_ = _mm256_insertf128_pd(d_, _mm256_extractf128_pd(d_,1), 0); \
      }
   #endif
#elif defined(ATL_SSE2) && (defined(DREAL) || defined(DCPLX))
   #include <xmmintrin.h>
   #if defined(ATL_SSE3)
      #include <pmmintrin.h>
      #include <tmmintrin.h>
   #endif
   #define ATL_VTYPE __m128d
   #if ATL_VLEN != 2
      #error "VLEN == 2 only supported size for double precision SSE!"
   #endif
   #define ATL_vzero(v_) v_ = _mm_setzero_pd()
   #define ATL_vbcast(v_, p_) v_ =  _mm_load1_pd(p_)
   #define ATL_vuld(v_, p_) v_ = _mm_loadu_pd(p_)
   #define ATL_vld(v_, p_) v_ = _mm_load_pd(p_)
   #define ATL_vust(p_, v_) _mm_storeu_pd(p_, v_)
   #define ATL_vst(p_, v_) _mm_store_pd(p_, v_)
   #define ATL_vadd(d_, s1_, s2_) d_ =  _mm_add_pd(s1_, s2_)
   #define ATL_vsub(d_, s1_, s2_) d_ =  _mm_sub_pd(s1_, s2_)
   #define ATL_vmul(d_, s1_, s2_) d_ =  _mm_mul_pd(s1_, s2_)
   #define ATL_vmac(d_, s1_, s2_) \
   { ATL_VTYPE t_; \
      t_ = _mm_mul_pd(s1_, s2_); \
      d_ = _mm_add_pd(t_, d_); \
   }
   #ifdef ATL_SSE3
      #define ATL_vrsum1(d_, s_) d_ = _mm_cvtsd_f64(_mm_hadd_pd(s_, s_))
      #define ATL_vvrsum2(s0_, s1_) s0_ = _mm_hadd_pd(s0_, s1_)
      #define ATL_vvrsum1(s0_) s0_ = _mm_hadd_pd(s0_, s0_)
      #define ATL_vsplat0(d_, s_) d_ = _mm_movedup_pd(s_)
      #define ATL_vsplat1(d_, s_) d_ = (ATL_VTYPE) \
         _mm_shuffle_epi32((__m128i)(s_), 0xEE)
   #else
      #define ATL_vrsum1(d_, s_) \
         d_ = _mm_cvtsd_f64(_mm_add_sd(_mm_unpackhi_pd(s_, s_), s_))
      #define ATL_vvrsum2(s0_, s1_) \
      { \
         __m128d t0_; \
         t0_ = _mm_unpackhi_pd(s0_, s1_); \
         s0_ = _mm_unpacklo_pd(s0_, s1_); \
         ATL_vadd(s0_, s0_, t0_); \
      }
      #define ATL_vvrsum1(s0_) \
      { \
         __m128d t0_; \
         t0_ = _mm_unpackhi_pd(s0_, s0_); \
         s0_ = _mm_unpacklo_pd(s0_, s0_); \
         ATL_vadd(s0_, s0_, t0_); \
      }
      #define ATL_vsplat0(d_, s_) d_ = (ATL_VTYPE) \
         _mm_shuffle_epi32((__m128i)(s_), 0x0)
      #define ATL_vsplat1(d_, s_) d_ = (ATL_VTYPE) \
         _mm_shuffle_epi32((__m128i)(s_), 0x55)
      #define ATL_vsplat2(d_, s_) d_ = (ATL_VTYPE) \
         _mm_shuffle_epi32((__m128i)(s_), 0xAA)
      #define ATL_vsplat3(d_, s_) d_ = (ATL_VTYPE) \
         _mm_shuffle_epi32((__m128i)(s_), 0xFF)
   #endif
#elif defined(ATL_SSE1)
   #include <xmmintrin.h>
   #if defined(ATL_SSE3)
      #include <tmmintrin.h>
   #endif
   #define ATL_VTYPE __m128
   #if defined(ATL_VLEN) && ATL_VLEN != 4
      #error "VLEN == 4 only supported size for single precision SSE!"
   #elif !defined(ATL_VLEN)
      #define ATL_VLEN 4
   #endif
   #define ATL_vzero(v_) v_ = _mm_setzero_ps()
   #define ATL_vbcast(v_, p_) v_ =  _mm_load1_ps(p_)
   #define ATL_vuld(v_, p_) v_ = _mm_loadu_ps(p_)
   #define ATL_vld(v_, p_) v_ = _mm_load_ps(p_)
   #define ATL_vust(p_, v_) _mm_storeu_ps(p_, v_)
   #define ATL_vst(p_, v_) _mm_store_ps(p_, v_)
   #define ATL_vadd(d_, s1_, s2_) d_ =  _mm_add_ps(s1_, s2_)
   #define ATL_vsub(d_, s1_, s2_) d_ =  _mm_sub_ps(s1_, s2_)
   #define ATL_vmul(d_, s1_, s2_) d_ =  _mm_mul_ps(s1_, s2_)
   #define ATL_vmac(d_, s1_, s2_) \
   { ATL_VTYPE t_; \
      t_ = _mm_mul_ps(s1_, s2_); \
      d_ = _mm_add_ps(t_, d_); \
   }
   #ifdef ATL_SSE3
      #define ATL_vrsum1(d_, s_) \
      {  ATL_VTYPE t_; \
         t_ = _mm_hadd_ps(s_, s_); \
         d_ = _mm_cvtss_f32(_mm_hadd_ps(t_, t_)); \
      }
      #define ATL_vvrsum4(s0_, s1_, s2_, s3_) \
      { \
         s0_ = _mm_hadd_ps(s0_, s1_); /*{s1cd,s1ab,s0cd,s0ab}*/ \
         s2_ = _mm_hadd_ps(s2_, s3_); /*{s3cd,s3ab,s2cd,s2ab}*/ \
         s0_ = _mm_hadd_ps(s0_, s2_); /*{s3a-d,s2a-d,s1a-d,s0a-d}*/ \
      }
      #define ATL_vvrsum2(s0_, s1_) \
      { \
         s0_ = _mm_hadd_ps(s0_, s1_); /*{s1cd,s1ab,s0cd,s0ab}*/ \
         s0_ = _mm_hadd_ps(s0_, s0_); /*{s1a-d,s0a-d,s1a-d,s0a-d}*/ \
      }
      #define ATL_vvrsum1(s0_) \
      { \
         s0_ = _mm_hadd_ps(s0_, s0_); /*{s0cd,s0ab,s0cd,s0ab}*/ \
         s0_ = _mm_hadd_ps(s0_, s0_); /*{s0a-d,s0a-d,s0a-d,s0a-d}*/ \
      }
   #else
      #define ATL_vrsum1(d_, s_) \
      { \
         ATL_VTYPE t_; \
         t_ = _mm_movehl_ps(s_, s_); \
         t_ = _mm_add_ps(t_, s_); \
         t_ = _mm_add_ps(t_, _mm_shuffle_ps(t_, t_, 1)); \
         d_ = _mm_cvtss_f32(t_); \
      }
      #define ATL_vvrsum4(s0_, s1_, s2_, s3_) \
      {                                      /*{sXd,  sXc,  sXb,  sXa}*/ \
         ATL_VTYPE t0_; \
         t0_ = _mm_unpackhi_ps(s0_,s1_);     /*{s1d,  s0d,  s1c,  s0c}*/\
         s0_ = _mm_unpacklo_ps(s0_,s1_);     /*{s1b,  s0b,  s1a,  s0a}*/\
         s1_ = _mm_unpackhi_ps(s2_,s3_);     /*{s3d,  s2d,  s3c,  s2c}*/\
         ATL_vadd(s0_, s0_, t0_);            /*{s1bd, s0bd, s1ac, s0ac}*/\
         s2_ = _mm_unpacklo_ps(s2_,s3_);     /*{s3b,  s2b,  s3a,  s2a}*/\
         ATL_vadd(s2_, s2_, s1_);            /*{s3bd, s2bd, s3ac, s2ac}*/\
         t0_ = _mm_shuffle_ps(s0_,s2_,0xEE); /*{s3bd, s2bd, s1bd, s0bd}*/\
         s0_ = _mm_shuffle_ps(s0_,s2_,0x44); /*{s3ac, s2ac, s1ac, s0ac}*/\
         ATL_vadd(s0_,s0_,t0_);              /*{s3a-d,s2a-d,s1a-d,s0a-d}*/\
      }
      #define ATL_vvrsum2(s0_, s1_) \
      {                                      /*{sXd,  sXc,  sXb,  sXa}*/ \
         ATL_VTYPE t0_; \
         t0_ = _mm_unpackhi_ps(s0_,s1_);     /*{s1d,  s0d,  s1c,  s0c}*/\
         s0_ = _mm_unpacklo_ps(s0_,s1_);     /*{s1b,  s0b,  s1a,  s0a}*/\
         ATL_vadd(s0_, s0_, t0_);            /*{s1bd, s0bd, s1ac, s0ac}*/\
         t0_ = _mm_shuffle_ps(s0_,s0_,0xEE); /*{s1bd, s0bd, s1bd, s0bd}*/\
         s0_ = _mm_shuffle_ps(s0_,s0_,0x44); /*{s1ac, s0ac, s1ac, s0ac}*/\
         ATL_vadd(s0_,s0_,t0_);              /*{s1a-d,s0a-d,s1a-d,s0a-d}*/\
      }
      #define ATL_vvrsum1(s0_) \
      {                                      /*{sXd,  sXc,  sXb,  sXa}*/ \
         ATL_VTYPE t0_; \
         t0_ = _mm_unpackhi_ps(s0_,s0_);     /*{s0d,  s0d,  s0c,  s0c}*/\
         s0_ = _mm_unpacklo_ps(s0_,s0_);     /*{s0b,  s0b,  s0a,  s0a}*/\
         ATL_vadd(s0_, s0_, t0_);            /*{s0bd, s0bd, s0ac, s0ac}*/\
         t0_ = _mm_shuffle_ps(s0_,s0_,0xEE); /*{s0bd, s0bd, s0bd, s0bd}*/\
         s0_ = _mm_shuffle_ps(s0_,s0_,0x44); /*{s0ac, s0ac, s0ac, s0ac}*/\
         ATL_vadd(s0_,s0_,t0_);              /*{s0a-d,s0a-d,s0a-d,s0a-d}*/\
      }
   #endif
#elif ATL_VLEN > 1  /* use gnuvec when atlas knows no VEC ISA */
   #define ATL_VTYPE TYPE __attribute__ ((vector_size (ATL_VLENb)))
   #if defined(SREAL) || defined(SCPLX)
      #define ATL_VITYPE int  __attribute__ ((vector_size (ATL_VLENb)))
   #else
      #define ATL_VITYPE long long  __attribute__ ((vector_size (ATL_VLENb)))
   #endif
   #define ATL_vzero(d_) d_ = (ATL_VTYPE)(((ATL_VITYPE)(d_))^((ATL_VITYPE)(d_)))
   #define ATL_vcopy(d_, s_) d_ = s_
   #ifndef ATL_vbcast
      #if 0
         #define ATL_vbcast(v_, p_) v_ = *((TYPE*)(p_));
      #elif 0
         #define ATL_vbcast(v_, p_) \
         { \
            (v_)[0] = p_; \
            v_ =  __builtin_shuffle(v_, (ATL_VITYPE){0}); \
         }
      #endif
   #endif
   #define ATL_vld(v_, p_) \
      v_ = *((ATL_VTYPE*)__builtin_assume_aligned(p_,ATL_VLENb))
   #define ATL_vust(p_, v_) *((ATL_VTYPE*)(p_)) = v_
   #define ATL_vst(p_, v_) \
      *((ATL_VTYPE*)__builtin_assume_aligned(p_,ATL_VLENb)) = v_
   #define ATL_vadd(d_, s1_, s2_) d_ =  s1_ + s2_
   #define ATL_vsub(d_, s1_, s2_) d_ =  s1_ - s2_
   #define ATL_vmul(d_, s1_, s2_) d_ =  s1_ * s2_
   #define ATL_vmac(d_, s1_, s2_) d_ += s1_ * s2_
   #if ATL_VLEN == 1
      #define ATL_vbcast(v_, p_) v_ = *(p_)
      #ifndef ATL_vuld
         #define ATL_vuld(v_, p_) v_ = {*(p_)}
      #endif
      #ifndef ATL_vrsum1
         #define ATL_vrsum1(d_, s_) d_ = (s_)
      #endif
   #elif ATL_VLEN == 2
      #define ATL_vbcast(v_, p_) v_ = (ATL_VTYPE){*(p_), *(p_)}
      #ifndef ATL_vuld
         #define ATL_vuld(v_, p_) v_ = (ATL_VTYPE){*(p_), (p_)[1]}
      #endif
      #ifndef ATL_vrsum1
         #define ATL_vrsum1(d_, s_) d_ = ((s_)[0] + (s_)[1])
      #endif
   #elif ATL_VLEN == 4
      #define ATL_vbcast(v_, p_) v_ = (ATL_VTYPE){*(p_), *(p_), *(p_), *(p_)}
      #ifndef ATL_vuld
      #define ATL_vuld(v_, p_) v_ = (ATL_VTYPE){*(p_),(p_)[1],(p_)[2],(p_)[3]}
      #endif
      #ifndef ATL_vrsum1
         #define ATL_vrsum1(d_, s_) d_ = ((s_)[0] + (s_)[1] + (s_)[2] + (s_)[3])
      #endif
   #elif ATL_VLEN == 8
      #ifndef ATL_vuld
      #define ATL_vuld(v_, p_) v_ = (ATL_VTYPE) \
         {*(p_), (p_)[1], (p_)[2], (p_)[3], (p_)[4], (p_)[5], (p_)[6], (p_)[7]}
      #endif
      #define ATL_vbcast(v_, p_) v_ = (ATL_VTYPE){*(p_), *(p_), *(p_), *(p_), \
               *(p_), *(p_), *(p_), *(p_)}
      #ifndef ATL_vrsum1
      #define ATL_vrsum1(d_, s_) d_ = ((s_)[0] + (s_)[1] + (s_)[2] + (s_)[3] + \
                                       (s_)[4] + (s_)[5] + (s_)[6] + (s_)[7])
      #endif
   #elif ATL_VLEN == 16
      #ifndef ATL_vuld
      #define ATL_vuld(v_, p_) v_ = (ATL_VTYPE) \
         {*(p_),(p_)[1],(p_)[2],(p_)[3],(p_)[4],(p_)[5],(p_)[6],(p_)[7], \
          (p_)[8],(p_)[9],(p_)[10],(p_)[11],(p_)[12],(p_)[13],(p_)[14],(p_)[15]}
      #endif
      #ifndef ATL_vrsum1
      #define ATL_vrsum1(d_, s_) d_ = \
      ((s_)[0]+(s_)[1]+(s_)[2]+(s_)[3]+(s_)[4]+(s_)[5]+(s_)[6]+(s_)[7] +\
       (s_)[ 8]+(s_)[ 9]+(s_)[10]+(s_)[11]+(s_)[12]+(s_)[13]+(s_)[14]+(s_)[15])
      #endif
   #elif ATL_VLEN == 32
      #ifndef ATL_vuld
      #define ATL_vuld(v_, p_) v_ = (ATL_VTYPE) \
      {*(p_),(p_)[1],(p_)[2],(p_)[3],(p_)[4],(p_)[5],(p_)[6],(p_)[7], \
       (p_)[8],(p_)[9],(p_)[10],(p_)[11],(p_)[12],(p_)[13],(p_)[14],(p_)[15],\
       (p_)[16],(p_)[17],(p_)[18],(p_)[19],(p_)[20],(p_)[21],(p_)[22],(p_)[23],\
       (p_)[24],(p_)[25],(p_)[26],(p_)[27],(p_)[28],(p_)[29],(p_)[30],(p_)[31]}
      #endif
      #define ATL_vrsum1(d_, s_) d_ = \
      ((s_)[0]+(s_)[1]+(s_)[2]+(s_)[3]+(s_)[4]+(s_)[5]+(s_)[6]+(s_)[7] \
      +(s_)[ 8]+(s_)[ 9]+(s_)[10]+(s_)[11]+(s_)[12]+(s_)[13]+(s_)[14]+(s_)[15] \
      +(s_)[16]+(s_)[17]+(s_)[18]+(s_)[19]+(s_)[20]+(s_)[21]+(s_)[22]+(s_)[23] \
      +(s_)[24]+(s_)[25]+(s_)[26]+(s_)[27]+(s_)[28]+(s_)[29]+(s_)[30]+(s_)[31])
   #else
      #error "Unsupported ATL_VLEN"
   #endif
#else
   #if defined(ATL_VLEN) && ATL_VLEN != 1
      #error "For systems without vector support, only ATL_VLEN=1 supported!"
   #elif !defined(ATL_VLEN)
      #define ATL_VLEN 1
   #endif
   #define ATL_VTYPE TYPE

   #define ATL_vzero(d_) d_ = 0.0
   #define ATL_vcopy(d_, s_) d_ = s_
   #define ATL_vbcast(d_, p_) d_ = *(p_)
   #define ATL_vuld(v_, p_) v_ = *(p_)
   #define ATL_vld(v_, p_) v_ = *(p_)
   #define ATL_vust(p_, s_) *(p_) = s_
   #define ATL_vst(p_, s_) *(p_) = s_
   #define ATL_vadd(d_, s1_, s2_) d_ =  (s1_) + (s2_)
   #define ATL_vsub(d_, s1_, s2_) d_ =  (s1_) - (s2_)
   #define ATL_vmul(d_, s1_, s2_) d_ =  (s1_) * (s2_)
   #define ATL_vmac(d_, s1_, s2_) d_ += (s1_) * (s2_)
   #define ATL_vrsum1(d_, s_) d_ = s_
#endif
/*
 * If it isn't already defined (fast system-specific version), define vvrsumX
 * This may be horribly slow or great, depending on how smart the compiler is.
 */
#if ATL_VLEN == 2
   #ifndef ATL_vvrsum1
      #define ATL_vvrsum1(s0_) s0_[0] += s0_[1]
   #endif
   #ifndef ATL_vvrsum2
      #define ATL_vvrsum2(s0_, s1_) \
      { \
         s0_[0] += s0_[1]; \
         s0_[1] = s1_[0] + s1_[1]; \
      }
   #endif
#endif
#if ATL_VLEN == 4
   #ifndef ATL_vvrsum1
      #define ATL_vvrsum1(s0_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]; \
      }
   #endif
   #ifndef ATL_vvrsum2
      #define ATL_vvrsum2(s0_, s1_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]; \
      }
   #endif
   #ifndef ATL_vvrsum4
      #define ATL_vvrsum4(s0_, s1_, s2_, s3_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]; \
         s0_[2] = s2_[0]+s2_[1]+s2_[2]+s2_[3]; \
         s0_[3] = s3_[0]+s3_[1]+s3_[2]+s3_[3]; \
      }
   #endif
#endif
#if ATL_VLEN == 8
   #ifndef ATL_vvrsum1
      #define ATL_vvrsum1(s0_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]; \
      }
   #endif
   #ifndef ATL_vvrsum2
      #define ATL_vvrsum2(s0_, s1_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]; \
      }
   #endif
   #ifndef ATL_vvrsum4
      #define ATL_vvrsum4(s0_, s1_, s2_, s3_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]; \
         s0_[2] = s2_[0]+s2_[1]+s2_[2]+s2_[3]+s2_[4]+s2_[5]+s2_[6]+s2_[7]; \
         s0_[3] = s3_[0]+s3_[1]+s3_[2]+s3_[3]+s3_[4]+s3_[5]+s3_[6]+s3_[7]; \
      }
   #endif
   #ifndef ATL_vvrsum8
      #define ATL_vvrsum8(s0_, s1_, s2_, s3_, s4_, s5_, s6_, s7_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]; \
         s0_[2] = s2_[0]+s2_[1]+s2_[2]+s2_[3]+s2_[4]+s2_[5]+s2_[6]+s2_[7]; \
         s0_[3] = s3_[0]+s3_[1]+s3_[2]+s3_[3]+s3_[4]+s3_[5]+s3_[6]+s3_[7]; \
         s0_[4] = s4_[0]+s4_[1]+s4_[2]+s4_[3]+s4_[4]+s4_[5]+s4_[6]+s4_[7]; \
         s0_[5] = s5_[0]+s5_[1]+s5_[2]+s5_[3]+s5_[4]+s5_[5]+s5_[6]+s5_[7]; \
         s0_[6] = s6_[0]+s6_[1]+s6_[2]+s6_[3]+s6_[4]+s6_[5]+s6_[6]+s6_[7]; \
         s0_[7] = s7_[0]+s7_[1]+s7_[2]+s7_[3]+s7_[4]+s7_[5]+s7_[6]+s7_[7]; \
      }
   #endif
#endif
#if ATL_VLEN == 16
   #ifndef ATL_vvrsum1
      #define ATL_vvrsum1(s0_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]; \
      }
   #endif
   #ifndef ATL_vvrsum2
      #define ATL_vvrsum2(s0_, s1_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]+s1_[8]+s1_[9]+s1_[10]+s1_[11]+s1_[12]+s1_[13]+s1_[14]+s1_[15]; \
      }
   #endif
   #ifndef ATL_vvrsum4
      #define ATL_vvrsum4(s0_, s1_, s2_, s3_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]+s1_[8]+s1_[9]+s1_[10]+s1_[11]+s1_[12]+s1_[13]+s1_[14]+s1_[15]; \
         s0_[2] = s2_[0]+s2_[1]+s2_[2]+s2_[3]+s2_[4]+s2_[5]+s2_[6]+s2_[7]+s2_[8]+s2_[9]+s2_[10]+s2_[11]+s2_[12]+s2_[13]+s2_[14]+s2_[15]; \
         s0_[3] = s3_[0]+s3_[1]+s3_[2]+s3_[3]+s3_[4]+s3_[5]+s3_[6]+s3_[7]+s3_[8]+s3_[9]+s3_[10]+s3_[11]+s3_[12]+s3_[13]+s3_[14]+s3_[15]; \
      }
   #endif
   #ifndef ATL_vvrsum8
      #define ATL_vvrsum8(s0_, s1_, s2_, s3_, s4_, s5_, s6_, s7_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]+s1_[8]+s1_[9]+s1_[10]+s1_[11]+s1_[12]+s1_[13]+s1_[14]+s1_[15]; \
         s0_[2] = s2_[0]+s2_[1]+s2_[2]+s2_[3]+s2_[4]+s2_[5]+s2_[6]+s2_[7]+s2_[8]+s2_[9]+s2_[10]+s2_[11]+s2_[12]+s2_[13]+s2_[14]+s2_[15]; \
         s0_[3] = s3_[0]+s3_[1]+s3_[2]+s3_[3]+s3_[4]+s3_[5]+s3_[6]+s3_[7]+s3_[8]+s3_[9]+s3_[10]+s3_[11]+s3_[12]+s3_[13]+s3_[14]+s3_[15]; \
         s0_[4] = s4_[0]+s4_[1]+s4_[2]+s4_[3]+s4_[4]+s4_[5]+s4_[6]+s4_[7]+s4_[8]+s4_[9]+s4_[10]+s4_[11]+s4_[12]+s4_[13]+s4_[14]+s4_[15]; \
         s0_[5] = s5_[0]+s5_[1]+s5_[2]+s5_[3]+s5_[4]+s5_[5]+s5_[6]+s5_[7]+s5_[8]+s5_[9]+s5_[10]+s5_[11]+s5_[12]+s5_[13]+s5_[14]+s5_[15]; \
         s0_[6] = s6_[0]+s6_[1]+s6_[2]+s6_[3]+s6_[4]+s6_[5]+s6_[6]+s6_[7]+s6_[8]+s6_[9]+s6_[10]+s6_[11]+s6_[12]+s6_[13]+s6_[14]+s6_[15]; \
         s0_[7] = s7_[0]+s7_[1]+s7_[2]+s7_[3]+s7_[4]+s7_[5]+s7_[6]+s7_[7]+s7_[8]+s7_[9]+s7_[10]+s7_[11]+s7_[12]+s7_[13]+s7_[14]+s7_[15]; \
      }
   #endif
   #ifndef ATL_vvrsum16
      #define ATL_vvrsum16(s0_, s1_, s2_, s3_, s4_, s5_, s6_, s7_, s8_, s9_, s10_, s11_, s12_, s13_, s14_, s15_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]+s1_[8]+s1_[9]+s1_[10]+s1_[11]+s1_[12]+s1_[13]+s1_[14]+s1_[15]; \
         s0_[2] = s2_[0]+s2_[1]+s2_[2]+s2_[3]+s2_[4]+s2_[5]+s2_[6]+s2_[7]+s2_[8]+s2_[9]+s2_[10]+s2_[11]+s2_[12]+s2_[13]+s2_[14]+s2_[15]; \
         s0_[3] = s3_[0]+s3_[1]+s3_[2]+s3_[3]+s3_[4]+s3_[5]+s3_[6]+s3_[7]+s3_[8]+s3_[9]+s3_[10]+s3_[11]+s3_[12]+s3_[13]+s3_[14]+s3_[15]; \
         s0_[4] = s4_[0]+s4_[1]+s4_[2]+s4_[3]+s4_[4]+s4_[5]+s4_[6]+s4_[7]+s4_[8]+s4_[9]+s4_[10]+s4_[11]+s4_[12]+s4_[13]+s4_[14]+s4_[15]; \
         s0_[5] = s5_[0]+s5_[1]+s5_[2]+s5_[3]+s5_[4]+s5_[5]+s5_[6]+s5_[7]+s5_[8]+s5_[9]+s5_[10]+s5_[11]+s5_[12]+s5_[13]+s5_[14]+s5_[15]; \
         s0_[6] = s6_[0]+s6_[1]+s6_[2]+s6_[3]+s6_[4]+s6_[5]+s6_[6]+s6_[7]+s6_[8]+s6_[9]+s6_[10]+s6_[11]+s6_[12]+s6_[13]+s6_[14]+s6_[15]; \
         s0_[7] = s7_[0]+s7_[1]+s7_[2]+s7_[3]+s7_[4]+s7_[5]+s7_[6]+s7_[7]+s7_[8]+s7_[9]+s7_[10]+s7_[11]+s7_[12]+s7_[13]+s7_[14]+s7_[15]; \
         s0_[8] = s8_[0]+s8_[1]+s8_[2]+s8_[3]+s8_[4]+s8_[5]+s8_[6]+s8_[7]+s8_[8]+s8_[9]+s8_[10]+s8_[11]+s8_[12]+s8_[13]+s8_[14]+s8_[15]; \
         s0_[9] = s9_[0]+s9_[1]+s9_[2]+s9_[3]+s9_[4]+s9_[5]+s9_[6]+s9_[7]+s9_[8]+s9_[9]+s9_[10]+s9_[11]+s9_[12]+s9_[13]+s9_[14]+s9_[15]; \
         s0_[10] = s10_[0]+s10_[1]+s10_[2]+s10_[3]+s10_[4]+s10_[5]+s10_[6]+s10_[7]+s10_[8]+s10_[9]+s10_[10]+s10_[11]+s10_[12]+s10_[13]+s10_[14]+s10_[15]; \
         s0_[11] = s11_[0]+s11_[1]+s11_[2]+s11_[3]+s11_[4]+s11_[5]+s11_[6]+s11_[7]+s11_[8]+s11_[9]+s11_[10]+s11_[11]+s11_[12]+s11_[13]+s11_[14]+s11_[15]; \
         s0_[12] = s12_[0]+s12_[1]+s12_[2]+s12_[3]+s12_[4]+s12_[5]+s12_[6]+s12_[7]+s12_[8]+s12_[9]+s12_[10]+s12_[11]+s12_[12]+s12_[13]+s12_[14]+s12_[15]; \
         s0_[13] = s13_[0]+s13_[1]+s13_[2]+s13_[3]+s13_[4]+s13_[5]+s13_[6]+s13_[7]+s13_[8]+s13_[9]+s13_[10]+s13_[11]+s13_[12]+s13_[13]+s13_[14]+s13_[15]; \
         s0_[14] = s14_[0]+s14_[1]+s14_[2]+s14_[3]+s14_[4]+s14_[5]+s14_[6]+s14_[7]+s14_[8]+s14_[9]+s14_[10]+s14_[11]+s14_[12]+s14_[13]+s14_[14]+s14_[15]; \
         s0_[15] = s15_[0]+s15_[1]+s15_[2]+s15_[3]+s15_[4]+s15_[5]+s15_[6]+s15_[7]+s15_[8]+s15_[9]+s15_[10]+s15_[11]+s15_[12]+s15_[13]+s15_[14]+s15_[15]; \
      }
   #endif
#endif
#if ATL_VLEN == 32
   #ifndef ATL_vvrsum1
      #define ATL_vvrsum1(s0_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]+s0_[16]+s0_[17]+s0_[18]+s0_[19]+s0_[20]+s0_[21]+s0_[22]+s0_[23]+s0_[24]+s0_[25]+s0_[26]+s0_[27]+s0_[28]+s0_[29]+s0_[30]+s0_[31]; \
      }
   #endif
   #ifndef ATL_vvrsum2
      #define ATL_vvrsum2(s0_, s1_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]+s0_[16]+s0_[17]+s0_[18]+s0_[19]+s0_[20]+s0_[21]+s0_[22]+s0_[23]+s0_[24]+s0_[25]+s0_[26]+s0_[27]+s0_[28]+s0_[29]+s0_[30]+s0_[31]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]+s1_[8]+s1_[9]+s1_[10]+s1_[11]+s1_[12]+s1_[13]+s1_[14]+s1_[15]+s1_[16]+s1_[17]+s1_[18]+s1_[19]+s1_[20]+s1_[21]+s1_[22]+s1_[23]+s1_[24]+s1_[25]+s1_[26]+s1_[27]+s1_[28]+s1_[29]+s1_[30]+s1_[31]; \
      }
   #endif
   #ifndef ATL_vvrsum4
      #define ATL_vvrsum4(s0_, s1_, s2_, s3_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]+s0_[16]+s0_[17]+s0_[18]+s0_[19]+s0_[20]+s0_[21]+s0_[22]+s0_[23]+s0_[24]+s0_[25]+s0_[26]+s0_[27]+s0_[28]+s0_[29]+s0_[30]+s0_[31]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]+s1_[8]+s1_[9]+s1_[10]+s1_[11]+s1_[12]+s1_[13]+s1_[14]+s1_[15]+s1_[16]+s1_[17]+s1_[18]+s1_[19]+s1_[20]+s1_[21]+s1_[22]+s1_[23]+s1_[24]+s1_[25]+s1_[26]+s1_[27]+s1_[28]+s1_[29]+s1_[30]+s1_[31]; \
         s0_[2] = s2_[0]+s2_[1]+s2_[2]+s2_[3]+s2_[4]+s2_[5]+s2_[6]+s2_[7]+s2_[8]+s2_[9]+s2_[10]+s2_[11]+s2_[12]+s2_[13]+s2_[14]+s2_[15]+s2_[16]+s2_[17]+s2_[18]+s2_[19]+s2_[20]+s2_[21]+s2_[22]+s2_[23]+s2_[24]+s2_[25]+s2_[26]+s2_[27]+s2_[28]+s2_[29]+s2_[30]+s2_[31]; \
         s0_[3] = s3_[0]+s3_[1]+s3_[2]+s3_[3]+s3_[4]+s3_[5]+s3_[6]+s3_[7]+s3_[8]+s3_[9]+s3_[10]+s3_[11]+s3_[12]+s3_[13]+s3_[14]+s3_[15]+s3_[16]+s3_[17]+s3_[18]+s3_[19]+s3_[20]+s3_[21]+s3_[22]+s3_[23]+s3_[24]+s3_[25]+s3_[26]+s3_[27]+s3_[28]+s3_[29]+s3_[30]+s3_[31]; \
      }
   #endif
   #ifndef ATL_vvrsum8
      #define ATL_vvrsum8(s0_, s1_, s2_, s3_, s4_, s5_, s6_, s7_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]+s0_[16]+s0_[17]+s0_[18]+s0_[19]+s0_[20]+s0_[21]+s0_[22]+s0_[23]+s0_[24]+s0_[25]+s0_[26]+s0_[27]+s0_[28]+s0_[29]+s0_[30]+s0_[31]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]+s1_[8]+s1_[9]+s1_[10]+s1_[11]+s1_[12]+s1_[13]+s1_[14]+s1_[15]+s1_[16]+s1_[17]+s1_[18]+s1_[19]+s1_[20]+s1_[21]+s1_[22]+s1_[23]+s1_[24]+s1_[25]+s1_[26]+s1_[27]+s1_[28]+s1_[29]+s1_[30]+s1_[31]; \
         s0_[2] = s2_[0]+s2_[1]+s2_[2]+s2_[3]+s2_[4]+s2_[5]+s2_[6]+s2_[7]+s2_[8]+s2_[9]+s2_[10]+s2_[11]+s2_[12]+s2_[13]+s2_[14]+s2_[15]+s2_[16]+s2_[17]+s2_[18]+s2_[19]+s2_[20]+s2_[21]+s2_[22]+s2_[23]+s2_[24]+s2_[25]+s2_[26]+s2_[27]+s2_[28]+s2_[29]+s2_[30]+s2_[31]; \
         s0_[3] = s3_[0]+s3_[1]+s3_[2]+s3_[3]+s3_[4]+s3_[5]+s3_[6]+s3_[7]+s3_[8]+s3_[9]+s3_[10]+s3_[11]+s3_[12]+s3_[13]+s3_[14]+s3_[15]+s3_[16]+s3_[17]+s3_[18]+s3_[19]+s3_[20]+s3_[21]+s3_[22]+s3_[23]+s3_[24]+s3_[25]+s3_[26]+s3_[27]+s3_[28]+s3_[29]+s3_[30]+s3_[31]; \
         s0_[4] = s4_[0]+s4_[1]+s4_[2]+s4_[3]+s4_[4]+s4_[5]+s4_[6]+s4_[7]+s4_[8]+s4_[9]+s4_[10]+s4_[11]+s4_[12]+s4_[13]+s4_[14]+s4_[15]+s4_[16]+s4_[17]+s4_[18]+s4_[19]+s4_[20]+s4_[21]+s4_[22]+s4_[23]+s4_[24]+s4_[25]+s4_[26]+s4_[27]+s4_[28]+s4_[29]+s4_[30]+s4_[31]; \
         s0_[5] = s5_[0]+s5_[1]+s5_[2]+s5_[3]+s5_[4]+s5_[5]+s5_[6]+s5_[7]+s5_[8]+s5_[9]+s5_[10]+s5_[11]+s5_[12]+s5_[13]+s5_[14]+s5_[15]+s5_[16]+s5_[17]+s5_[18]+s5_[19]+s5_[20]+s5_[21]+s5_[22]+s5_[23]+s5_[24]+s5_[25]+s5_[26]+s5_[27]+s5_[28]+s5_[29]+s5_[30]+s5_[31]; \
         s0_[6] = s6_[0]+s6_[1]+s6_[2]+s6_[3]+s6_[4]+s6_[5]+s6_[6]+s6_[7]+s6_[8]+s6_[9]+s6_[10]+s6_[11]+s6_[12]+s6_[13]+s6_[14]+s6_[15]+s6_[16]+s6_[17]+s6_[18]+s6_[19]+s6_[20]+s6_[21]+s6_[22]+s6_[23]+s6_[24]+s6_[25]+s6_[26]+s6_[27]+s6_[28]+s6_[29]+s6_[30]+s6_[31]; \
         s0_[7] = s7_[0]+s7_[1]+s7_[2]+s7_[3]+s7_[4]+s7_[5]+s7_[6]+s7_[7]+s7_[8]+s7_[9]+s7_[10]+s7_[11]+s7_[12]+s7_[13]+s7_[14]+s7_[15]+s7_[16]+s7_[17]+s7_[18]+s7_[19]+s7_[20]+s7_[21]+s7_[22]+s7_[23]+s7_[24]+s7_[25]+s7_[26]+s7_[27]+s7_[28]+s7_[29]+s7_[30]+s7_[31]; \
      }
   #endif
   #ifndef ATL_vvrsum16
      #define ATL_vvrsum16(s0_, s1_, s2_, s3_, s4_, s5_, s6_, s7_, s8_, s9_, s10_, s11_, s12_, s13_, s14_, s15_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]+s0_[16]+s0_[17]+s0_[18]+s0_[19]+s0_[20]+s0_[21]+s0_[22]+s0_[23]+s0_[24]+s0_[25]+s0_[26]+s0_[27]+s0_[28]+s0_[29]+s0_[30]+s0_[31]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]+s1_[8]+s1_[9]+s1_[10]+s1_[11]+s1_[12]+s1_[13]+s1_[14]+s1_[15]+s1_[16]+s1_[17]+s1_[18]+s1_[19]+s1_[20]+s1_[21]+s1_[22]+s1_[23]+s1_[24]+s1_[25]+s1_[26]+s1_[27]+s1_[28]+s1_[29]+s1_[30]+s1_[31]; \
         s0_[2] = s2_[0]+s2_[1]+s2_[2]+s2_[3]+s2_[4]+s2_[5]+s2_[6]+s2_[7]+s2_[8]+s2_[9]+s2_[10]+s2_[11]+s2_[12]+s2_[13]+s2_[14]+s2_[15]+s2_[16]+s2_[17]+s2_[18]+s2_[19]+s2_[20]+s2_[21]+s2_[22]+s2_[23]+s2_[24]+s2_[25]+s2_[26]+s2_[27]+s2_[28]+s2_[29]+s2_[30]+s2_[31]; \
         s0_[3] = s3_[0]+s3_[1]+s3_[2]+s3_[3]+s3_[4]+s3_[5]+s3_[6]+s3_[7]+s3_[8]+s3_[9]+s3_[10]+s3_[11]+s3_[12]+s3_[13]+s3_[14]+s3_[15]+s3_[16]+s3_[17]+s3_[18]+s3_[19]+s3_[20]+s3_[21]+s3_[22]+s3_[23]+s3_[24]+s3_[25]+s3_[26]+s3_[27]+s3_[28]+s3_[29]+s3_[30]+s3_[31]; \
         s0_[4] = s4_[0]+s4_[1]+s4_[2]+s4_[3]+s4_[4]+s4_[5]+s4_[6]+s4_[7]+s4_[8]+s4_[9]+s4_[10]+s4_[11]+s4_[12]+s4_[13]+s4_[14]+s4_[15]+s4_[16]+s4_[17]+s4_[18]+s4_[19]+s4_[20]+s4_[21]+s4_[22]+s4_[23]+s4_[24]+s4_[25]+s4_[26]+s4_[27]+s4_[28]+s4_[29]+s4_[30]+s4_[31]; \
         s0_[5] = s5_[0]+s5_[1]+s5_[2]+s5_[3]+s5_[4]+s5_[5]+s5_[6]+s5_[7]+s5_[8]+s5_[9]+s5_[10]+s5_[11]+s5_[12]+s5_[13]+s5_[14]+s5_[15]+s5_[16]+s5_[17]+s5_[18]+s5_[19]+s5_[20]+s5_[21]+s5_[22]+s5_[23]+s5_[24]+s5_[25]+s5_[26]+s5_[27]+s5_[28]+s5_[29]+s5_[30]+s5_[31]; \
         s0_[6] = s6_[0]+s6_[1]+s6_[2]+s6_[3]+s6_[4]+s6_[5]+s6_[6]+s6_[7]+s6_[8]+s6_[9]+s6_[10]+s6_[11]+s6_[12]+s6_[13]+s6_[14]+s6_[15]+s6_[16]+s6_[17]+s6_[18]+s6_[19]+s6_[20]+s6_[21]+s6_[22]+s6_[23]+s6_[24]+s6_[25]+s6_[26]+s6_[27]+s6_[28]+s6_[29]+s6_[30]+s6_[31]; \
         s0_[7] = s7_[0]+s7_[1]+s7_[2]+s7_[3]+s7_[4]+s7_[5]+s7_[6]+s7_[7]+s7_[8]+s7_[9]+s7_[10]+s7_[11]+s7_[12]+s7_[13]+s7_[14]+s7_[15]+s7_[16]+s7_[17]+s7_[18]+s7_[19]+s7_[20]+s7_[21]+s7_[22]+s7_[23]+s7_[24]+s7_[25]+s7_[26]+s7_[27]+s7_[28]+s7_[29]+s7_[30]+s7_[31]; \
         s0_[8] = s8_[0]+s8_[1]+s8_[2]+s8_[3]+s8_[4]+s8_[5]+s8_[6]+s8_[7]+s8_[8]+s8_[9]+s8_[10]+s8_[11]+s8_[12]+s8_[13]+s8_[14]+s8_[15]+s8_[16]+s8_[17]+s8_[18]+s8_[19]+s8_[20]+s8_[21]+s8_[22]+s8_[23]+s8_[24]+s8_[25]+s8_[26]+s8_[27]+s8_[28]+s8_[29]+s8_[30]+s8_[31]; \
         s0_[9] = s9_[0]+s9_[1]+s9_[2]+s9_[3]+s9_[4]+s9_[5]+s9_[6]+s9_[7]+s9_[8]+s9_[9]+s9_[10]+s9_[11]+s9_[12]+s9_[13]+s9_[14]+s9_[15]+s9_[16]+s9_[17]+s9_[18]+s9_[19]+s9_[20]+s9_[21]+s9_[22]+s9_[23]+s9_[24]+s9_[25]+s9_[26]+s9_[27]+s9_[28]+s9_[29]+s9_[30]+s9_[31]; \
         s0_[10] = s10_[0]+s10_[1]+s10_[2]+s10_[3]+s10_[4]+s10_[5]+s10_[6]+s10_[7]+s10_[8]+s10_[9]+s10_[10]+s10_[11]+s10_[12]+s10_[13]+s10_[14]+s10_[15]+s10_[16]+s10_[17]+s10_[18]+s10_[19]+s10_[20]+s10_[21]+s10_[22]+s10_[23]+s10_[24]+s10_[25]+s10_[26]+s10_[27]+s10_[28]+s10_[29]+s10_[30]+s10_[31]; \
         s0_[11] = s11_[0]+s11_[1]+s11_[2]+s11_[3]+s11_[4]+s11_[5]+s11_[6]+s11_[7]+s11_[8]+s11_[9]+s11_[10]+s11_[11]+s11_[12]+s11_[13]+s11_[14]+s11_[15]+s11_[16]+s11_[17]+s11_[18]+s11_[19]+s11_[20]+s11_[21]+s11_[22]+s11_[23]+s11_[24]+s11_[25]+s11_[26]+s11_[27]+s11_[28]+s11_[29]+s11_[30]+s11_[31]; \
         s0_[12] = s12_[0]+s12_[1]+s12_[2]+s12_[3]+s12_[4]+s12_[5]+s12_[6]+s12_[7]+s12_[8]+s12_[9]+s12_[10]+s12_[11]+s12_[12]+s12_[13]+s12_[14]+s12_[15]+s12_[16]+s12_[17]+s12_[18]+s12_[19]+s12_[20]+s12_[21]+s12_[22]+s12_[23]+s12_[24]+s12_[25]+s12_[26]+s12_[27]+s12_[28]+s12_[29]+s12_[30]+s12_[31]; \
         s0_[13] = s13_[0]+s13_[1]+s13_[2]+s13_[3]+s13_[4]+s13_[5]+s13_[6]+s13_[7]+s13_[8]+s13_[9]+s13_[10]+s13_[11]+s13_[12]+s13_[13]+s13_[14]+s13_[15]+s13_[16]+s13_[17]+s13_[18]+s13_[19]+s13_[20]+s13_[21]+s13_[22]+s13_[23]+s13_[24]+s13_[25]+s13_[26]+s13_[27]+s13_[28]+s13_[29]+s13_[30]+s13_[31]; \
         s0_[14] = s14_[0]+s14_[1]+s14_[2]+s14_[3]+s14_[4]+s14_[5]+s14_[6]+s14_[7]+s14_[8]+s14_[9]+s14_[10]+s14_[11]+s14_[12]+s14_[13]+s14_[14]+s14_[15]+s14_[16]+s14_[17]+s14_[18]+s14_[19]+s14_[20]+s14_[21]+s14_[22]+s14_[23]+s14_[24]+s14_[25]+s14_[26]+s14_[27]+s14_[28]+s14_[29]+s14_[30]+s14_[31]; \
         s0_[15] = s15_[0]+s15_[1]+s15_[2]+s15_[3]+s15_[4]+s15_[5]+s15_[6]+s15_[7]+s15_[8]+s15_[9]+s15_[10]+s15_[11]+s15_[12]+s15_[13]+s15_[14]+s15_[15]+s15_[16]+s15_[17]+s15_[18]+s15_[19]+s15_[20]+s15_[21]+s15_[22]+s15_[23]+s15_[24]+s15_[25]+s15_[26]+s15_[27]+s15_[28]+s15_[29]+s15_[30]+s15_[31]; \
      }
   #endif
   #ifndef ATL_vvrsum32
      #define ATL_vvrsum32(s0_, s1_, s2_, s3_, s4_, s5_, s6_, s7_, s8_, s9_, s10_, s11_, s12_, s13_, s14_, s15_, s16_, s17_, s18_, s19_, s20_, s21_, s22_, s23_, s24_, s25_, s26_, s27_, s28_, s29_, s30_, s31_)\
      { \
         s0_[0] = s0_[0]+s0_[1]+s0_[2]+s0_[3]+s0_[4]+s0_[5]+s0_[6]+s0_[7]+s0_[8]+s0_[9]+s0_[10]+s0_[11]+s0_[12]+s0_[13]+s0_[14]+s0_[15]+s0_[16]+s0_[17]+s0_[18]+s0_[19]+s0_[20]+s0_[21]+s0_[22]+s0_[23]+s0_[24]+s0_[25]+s0_[26]+s0_[27]+s0_[28]+s0_[29]+s0_[30]+s0_[31]; \
         s0_[1] = s1_[0]+s1_[1]+s1_[2]+s1_[3]+s1_[4]+s1_[5]+s1_[6]+s1_[7]+s1_[8]+s1_[9]+s1_[10]+s1_[11]+s1_[12]+s1_[13]+s1_[14]+s1_[15]+s1_[16]+s1_[17]+s1_[18]+s1_[19]+s1_[20]+s1_[21]+s1_[22]+s1_[23]+s1_[24]+s1_[25]+s1_[26]+s1_[27]+s1_[28]+s1_[29]+s1_[30]+s1_[31]; \
         s0_[2] = s2_[0]+s2_[1]+s2_[2]+s2_[3]+s2_[4]+s2_[5]+s2_[6]+s2_[7]+s2_[8]+s2_[9]+s2_[10]+s2_[11]+s2_[12]+s2_[13]+s2_[14]+s2_[15]+s2_[16]+s2_[17]+s2_[18]+s2_[19]+s2_[20]+s2_[21]+s2_[22]+s2_[23]+s2_[24]+s2_[25]+s2_[26]+s2_[27]+s2_[28]+s2_[29]+s2_[30]+s2_[31]; \
         s0_[3] = s3_[0]+s3_[1]+s3_[2]+s3_[3]+s3_[4]+s3_[5]+s3_[6]+s3_[7]+s3_[8]+s3_[9]+s3_[10]+s3_[11]+s3_[12]+s3_[13]+s3_[14]+s3_[15]+s3_[16]+s3_[17]+s3_[18]+s3_[19]+s3_[20]+s3_[21]+s3_[22]+s3_[23]+s3_[24]+s3_[25]+s3_[26]+s3_[27]+s3_[28]+s3_[29]+s3_[30]+s3_[31]; \
         s0_[4] = s4_[0]+s4_[1]+s4_[2]+s4_[3]+s4_[4]+s4_[5]+s4_[6]+s4_[7]+s4_[8]+s4_[9]+s4_[10]+s4_[11]+s4_[12]+s4_[13]+s4_[14]+s4_[15]+s4_[16]+s4_[17]+s4_[18]+s4_[19]+s4_[20]+s4_[21]+s4_[22]+s4_[23]+s4_[24]+s4_[25]+s4_[26]+s4_[27]+s4_[28]+s4_[29]+s4_[30]+s4_[31]; \
         s0_[5] = s5_[0]+s5_[1]+s5_[2]+s5_[3]+s5_[4]+s5_[5]+s5_[6]+s5_[7]+s5_[8]+s5_[9]+s5_[10]+s5_[11]+s5_[12]+s5_[13]+s5_[14]+s5_[15]+s5_[16]+s5_[17]+s5_[18]+s5_[19]+s5_[20]+s5_[21]+s5_[22]+s5_[23]+s5_[24]+s5_[25]+s5_[26]+s5_[27]+s5_[28]+s5_[29]+s5_[30]+s5_[31]; \
         s0_[6] = s6_[0]+s6_[1]+s6_[2]+s6_[3]+s6_[4]+s6_[5]+s6_[6]+s6_[7]+s6_[8]+s6_[9]+s6_[10]+s6_[11]+s6_[12]+s6_[13]+s6_[14]+s6_[15]+s6_[16]+s6_[17]+s6_[18]+s6_[19]+s6_[20]+s6_[21]+s6_[22]+s6_[23]+s6_[24]+s6_[25]+s6_[26]+s6_[27]+s6_[28]+s6_[29]+s6_[30]+s6_[31]; \
         s0_[7] = s7_[0]+s7_[1]+s7_[2]+s7_[3]+s7_[4]+s7_[5]+s7_[6]+s7_[7]+s7_[8]+s7_[9]+s7_[10]+s7_[11]+s7_[12]+s7_[13]+s7_[14]+s7_[15]+s7_[16]+s7_[17]+s7_[18]+s7_[19]+s7_[20]+s7_[21]+s7_[22]+s7_[23]+s7_[24]+s7_[25]+s7_[26]+s7_[27]+s7_[28]+s7_[29]+s7_[30]+s7_[31]; \
         s0_[8] = s8_[0]+s8_[1]+s8_[2]+s8_[3]+s8_[4]+s8_[5]+s8_[6]+s8_[7]+s8_[8]+s8_[9]+s8_[10]+s8_[11]+s8_[12]+s8_[13]+s8_[14]+s8_[15]+s8_[16]+s8_[17]+s8_[18]+s8_[19]+s8_[20]+s8_[21]+s8_[22]+s8_[23]+s8_[24]+s8_[25]+s8_[26]+s8_[27]+s8_[28]+s8_[29]+s8_[30]+s8_[31]; \
         s0_[9] = s9_[0]+s9_[1]+s9_[2]+s9_[3]+s9_[4]+s9_[5]+s9_[6]+s9_[7]+s9_[8]+s9_[9]+s9_[10]+s9_[11]+s9_[12]+s9_[13]+s9_[14]+s9_[15]+s9_[16]+s9_[17]+s9_[18]+s9_[19]+s9_[20]+s9_[21]+s9_[22]+s9_[23]+s9_[24]+s9_[25]+s9_[26]+s9_[27]+s9_[28]+s9_[29]+s9_[30]+s9_[31]; \
         s0_[10] = s10_[0]+s10_[1]+s10_[2]+s10_[3]+s10_[4]+s10_[5]+s10_[6]+s10_[7]+s10_[8]+s10_[9]+s10_[10]+s10_[11]+s10_[12]+s10_[13]+s10_[14]+s10_[15]+s10_[16]+s10_[17]+s10_[18]+s10_[19]+s10_[20]+s10_[21]+s10_[22]+s10_[23]+s10_[24]+s10_[25]+s10_[26]+s10_[27]+s10_[28]+s10_[29]+s10_[30]+s10_[31]; \
         s0_[11] = s11_[0]+s11_[1]+s11_[2]+s11_[3]+s11_[4]+s11_[5]+s11_[6]+s11_[7]+s11_[8]+s11_[9]+s11_[10]+s11_[11]+s11_[12]+s11_[13]+s11_[14]+s11_[15]+s11_[16]+s11_[17]+s11_[18]+s11_[19]+s11_[20]+s11_[21]+s11_[22]+s11_[23]+s11_[24]+s11_[25]+s11_[26]+s11_[27]+s11_[28]+s11_[29]+s11_[30]+s11_[31]; \
         s0_[12] = s12_[0]+s12_[1]+s12_[2]+s12_[3]+s12_[4]+s12_[5]+s12_[6]+s12_[7]+s12_[8]+s12_[9]+s12_[10]+s12_[11]+s12_[12]+s12_[13]+s12_[14]+s12_[15]+s12_[16]+s12_[17]+s12_[18]+s12_[19]+s12_[20]+s12_[21]+s12_[22]+s12_[23]+s12_[24]+s12_[25]+s12_[26]+s12_[27]+s12_[28]+s12_[29]+s12_[30]+s12_[31]; \
         s0_[13] = s13_[0]+s13_[1]+s13_[2]+s13_[3]+s13_[4]+s13_[5]+s13_[6]+s13_[7]+s13_[8]+s13_[9]+s13_[10]+s13_[11]+s13_[12]+s13_[13]+s13_[14]+s13_[15]+s13_[16]+s13_[17]+s13_[18]+s13_[19]+s13_[20]+s13_[21]+s13_[22]+s13_[23]+s13_[24]+s13_[25]+s13_[26]+s13_[27]+s13_[28]+s13_[29]+s13_[30]+s13_[31]; \
         s0_[14] = s14_[0]+s14_[1]+s14_[2]+s14_[3]+s14_[4]+s14_[5]+s14_[6]+s14_[7]+s14_[8]+s14_[9]+s14_[10]+s14_[11]+s14_[12]+s14_[13]+s14_[14]+s14_[15]+s14_[16]+s14_[17]+s14_[18]+s14_[19]+s14_[20]+s14_[21]+s14_[22]+s14_[23]+s14_[24]+s14_[25]+s14_[26]+s14_[27]+s14_[28]+s14_[29]+s14_[30]+s14_[31]; \
         s0_[15] = s15_[0]+s15_[1]+s15_[2]+s15_[3]+s15_[4]+s15_[5]+s15_[6]+s15_[7]+s15_[8]+s15_[9]+s15_[10]+s15_[11]+s15_[12]+s15_[13]+s15_[14]+s15_[15]+s15_[16]+s15_[17]+s15_[18]+s15_[19]+s15_[20]+s15_[21]+s15_[22]+s15_[23]+s15_[24]+s15_[25]+s15_[26]+s15_[27]+s15_[28]+s15_[29]+s15_[30]+s15_[31]; \
         s0_[16] = s16_[0]+s16_[1]+s16_[2]+s16_[3]+s16_[4]+s16_[5]+s16_[6]+s16_[7]+s16_[8]+s16_[9]+s16_[10]+s16_[11]+s16_[12]+s16_[13]+s16_[14]+s16_[15]+s16_[16]+s16_[17]+s16_[18]+s16_[19]+s16_[20]+s16_[21]+s16_[22]+s16_[23]+s16_[24]+s16_[25]+s16_[26]+s16_[27]+s16_[28]+s16_[29]+s16_[30]+s16_[31]; \
         s0_[17] = s17_[0]+s17_[1]+s17_[2]+s17_[3]+s17_[4]+s17_[5]+s17_[6]+s17_[7]+s17_[8]+s17_[9]+s17_[10]+s17_[11]+s17_[12]+s17_[13]+s17_[14]+s17_[15]+s17_[16]+s17_[17]+s17_[18]+s17_[19]+s17_[20]+s17_[21]+s17_[22]+s17_[23]+s17_[24]+s17_[25]+s17_[26]+s17_[27]+s17_[28]+s17_[29]+s17_[30]+s17_[31]; \
         s0_[18] = s18_[0]+s18_[1]+s18_[2]+s18_[3]+s18_[4]+s18_[5]+s18_[6]+s18_[7]+s18_[8]+s18_[9]+s18_[10]+s18_[11]+s18_[12]+s18_[13]+s18_[14]+s18_[15]+s18_[16]+s18_[17]+s18_[18]+s18_[19]+s18_[20]+s18_[21]+s18_[22]+s18_[23]+s18_[24]+s18_[25]+s18_[26]+s18_[27]+s18_[28]+s18_[29]+s18_[30]+s18_[31]; \
         s0_[19] = s19_[0]+s19_[1]+s19_[2]+s19_[3]+s19_[4]+s19_[5]+s19_[6]+s19_[7]+s19_[8]+s19_[9]+s19_[10]+s19_[11]+s19_[12]+s19_[13]+s19_[14]+s19_[15]+s19_[16]+s19_[17]+s19_[18]+s19_[19]+s19_[20]+s19_[21]+s19_[22]+s19_[23]+s19_[24]+s19_[25]+s19_[26]+s19_[27]+s19_[28]+s19_[29]+s19_[30]+s19_[31]; \
         s0_[20] = s20_[0]+s20_[1]+s20_[2]+s20_[3]+s20_[4]+s20_[5]+s20_[6]+s20_[7]+s20_[8]+s20_[9]+s20_[10]+s20_[11]+s20_[12]+s20_[13]+s20_[14]+s20_[15]+s20_[16]+s20_[17]+s20_[18]+s20_[19]+s20_[20]+s20_[21]+s20_[22]+s20_[23]+s20_[24]+s20_[25]+s20_[26]+s20_[27]+s20_[28]+s20_[29]+s20_[30]+s20_[31]; \
         s0_[21] = s21_[0]+s21_[1]+s21_[2]+s21_[3]+s21_[4]+s21_[5]+s21_[6]+s21_[7]+s21_[8]+s21_[9]+s21_[10]+s21_[11]+s21_[12]+s21_[13]+s21_[14]+s21_[15]+s21_[16]+s21_[17]+s21_[18]+s21_[19]+s21_[20]+s21_[21]+s21_[22]+s21_[23]+s21_[24]+s21_[25]+s21_[26]+s21_[27]+s21_[28]+s21_[29]+s21_[30]+s21_[31]; \
         s0_[22] = s22_[0]+s22_[1]+s22_[2]+s22_[3]+s22_[4]+s22_[5]+s22_[6]+s22_[7]+s22_[8]+s22_[9]+s22_[10]+s22_[11]+s22_[12]+s22_[13]+s22_[14]+s22_[15]+s22_[16]+s22_[17]+s22_[18]+s22_[19]+s22_[20]+s22_[21]+s22_[22]+s22_[23]+s22_[24]+s22_[25]+s22_[26]+s22_[27]+s22_[28]+s22_[29]+s22_[30]+s22_[31]; \
         s0_[23] = s23_[0]+s23_[1]+s23_[2]+s23_[3]+s23_[4]+s23_[5]+s23_[6]+s23_[7]+s23_[8]+s23_[9]+s23_[10]+s23_[11]+s23_[12]+s23_[13]+s23_[14]+s23_[15]+s23_[16]+s23_[17]+s23_[18]+s23_[19]+s23_[20]+s23_[21]+s23_[22]+s23_[23]+s23_[24]+s23_[25]+s23_[26]+s23_[27]+s23_[28]+s23_[29]+s23_[30]+s23_[31]; \
         s0_[24] = s24_[0]+s24_[1]+s24_[2]+s24_[3]+s24_[4]+s24_[5]+s24_[6]+s24_[7]+s24_[8]+s24_[9]+s24_[10]+s24_[11]+s24_[12]+s24_[13]+s24_[14]+s24_[15]+s24_[16]+s24_[17]+s24_[18]+s24_[19]+s24_[20]+s24_[21]+s24_[22]+s24_[23]+s24_[24]+s24_[25]+s24_[26]+s24_[27]+s24_[28]+s24_[29]+s24_[30]+s24_[31]; \
         s0_[25] = s25_[0]+s25_[1]+s25_[2]+s25_[3]+s25_[4]+s25_[5]+s25_[6]+s25_[7]+s25_[8]+s25_[9]+s25_[10]+s25_[11]+s25_[12]+s25_[13]+s25_[14]+s25_[15]+s25_[16]+s25_[17]+s25_[18]+s25_[19]+s25_[20]+s25_[21]+s25_[22]+s25_[23]+s25_[24]+s25_[25]+s25_[26]+s25_[27]+s25_[28]+s25_[29]+s25_[30]+s25_[31]; \
         s0_[26] = s26_[0]+s26_[1]+s26_[2]+s26_[3]+s26_[4]+s26_[5]+s26_[6]+s26_[7]+s26_[8]+s26_[9]+s26_[10]+s26_[11]+s26_[12]+s26_[13]+s26_[14]+s26_[15]+s26_[16]+s26_[17]+s26_[18]+s26_[19]+s26_[20]+s26_[21]+s26_[22]+s26_[23]+s26_[24]+s26_[25]+s26_[26]+s26_[27]+s26_[28]+s26_[29]+s26_[30]+s26_[31]; \
         s0_[27] = s27_[0]+s27_[1]+s27_[2]+s27_[3]+s27_[4]+s27_[5]+s27_[6]+s27_[7]+s27_[8]+s27_[9]+s27_[10]+s27_[11]+s27_[12]+s27_[13]+s27_[14]+s27_[15]+s27_[16]+s27_[17]+s27_[18]+s27_[19]+s27_[20]+s27_[21]+s27_[22]+s27_[23]+s27_[24]+s27_[25]+s27_[26]+s27_[27]+s27_[28]+s27_[29]+s27_[30]+s27_[31]; \
         s0_[28] = s28_[0]+s28_[1]+s28_[2]+s28_[3]+s28_[4]+s28_[5]+s28_[6]+s28_[7]+s28_[8]+s28_[9]+s28_[10]+s28_[11]+s28_[12]+s28_[13]+s28_[14]+s28_[15]+s28_[16]+s28_[17]+s28_[18]+s28_[19]+s28_[20]+s28_[21]+s28_[22]+s28_[23]+s28_[24]+s28_[25]+s28_[26]+s28_[27]+s28_[28]+s28_[29]+s28_[30]+s28_[31]; \
         s0_[29] = s29_[0]+s29_[1]+s29_[2]+s29_[3]+s29_[4]+s29_[5]+s29_[6]+s29_[7]+s29_[8]+s29_[9]+s29_[10]+s29_[11]+s29_[12]+s29_[13]+s29_[14]+s29_[15]+s29_[16]+s29_[17]+s29_[18]+s29_[19]+s29_[20]+s29_[21]+s29_[22]+s29_[23]+s29_[24]+s29_[25]+s29_[26]+s29_[27]+s29_[28]+s29_[29]+s29_[30]+s29_[31]; \
         s0_[30] = s30_[0]+s30_[1]+s30_[2]+s30_[3]+s30_[4]+s30_[5]+s30_[6]+s30_[7]+s30_[8]+s30_[9]+s30_[10]+s30_[11]+s30_[12]+s30_[13]+s30_[14]+s30_[15]+s30_[16]+s30_[17]+s30_[18]+s30_[19]+s30_[20]+s30_[21]+s30_[22]+s30_[23]+s30_[24]+s30_[25]+s30_[26]+s30_[27]+s30_[28]+s30_[29]+s30_[30]+s30_[31]; \
         s0_[31] = s31_[0]+s31_[1]+s31_[2]+s31_[3]+s31_[4]+s31_[5]+s31_[6]+s31_[7]+s31_[8]+s31_[9]+s31_[10]+s31_[11]+s31_[12]+s31_[13]+s31_[14]+s31_[15]+s31_[16]+s31_[17]+s31_[18]+s31_[19]+s31_[20]+s31_[21]+s31_[22]+s31_[23]+s31_[24]+s31_[25]+s31_[26]+s31_[27]+s31_[28]+s31_[29]+s31_[30]+s31_[31]; \
      }
   #endif
#endif
/*
 * If it isn't defined already (fast sys-spec vers), define
 *    vsplatI (0 <= I < VL) using vector indexing.
 * This may be horribly slow or great, depending on how smart the compiler is.
 */
#if ATL_VLEN == 2
   #ifndef ATL_vsplat0
   #define ATL_vsplat0(d_, s_) d_[0] = d_[1] = s_[0]
   #endif
   #ifndef ATL_vsplat1
   #define ATL_vsplat1(d_, s_) d_[0] = d_[1] = s_[1]
   #endif
#elif ATL_VLEN == 4
   #ifndef ATL_vsplat0
   #define ATL_vsplat0(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3] = s_[0]
   #endif
   #ifndef ATL_vsplat1
   #define ATL_vsplat1(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3] = s_[1]
   #endif
   #ifndef ATL_vsplat2
   #define ATL_vsplat2(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3] = s_[2]
   #endif
   #ifndef ATL_vsplat3
   #define ATL_vsplat3(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3] = s_[3]
   #endif
#elif ATL_VLEN == 8
   #ifndef ATL_vsplat0
   #define ATL_vsplat0(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7] = s_[0]
   #endif
   #ifndef ATL_vsplat1
   #define ATL_vsplat1(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7] = s_[1]
   #endif
   #ifndef ATL_vsplat2
   #define ATL_vsplat2(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7] = s_[2]
   #endif
   #ifndef ATL_vsplat3
   #define ATL_vsplat3(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7] = s_[3]
   #endif
   #ifndef ATL_vsplat4
   #define ATL_vsplat4(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7] = s_[4]
   #endif
   #ifndef ATL_vsplat5
   #define ATL_vsplat5(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7] = s_[5]
   #endif
   #ifndef ATL_vsplat6
   #define ATL_vsplat6(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7] = s_[6]
   #endif
   #ifndef ATL_vsplat7
   #define ATL_vsplat7(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7] = s_[7]
   #endif
#elif ATL_VLEN == 16
   #ifndef ATL_vsplat0
   #define ATL_vsplat0(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[0]
   #endif
   #ifndef ATL_vsplat1
   #define ATL_vsplat1(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[1]
   #endif
   #ifndef ATL_vsplat2
   #define ATL_vsplat2(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[2]
   #endif
   #ifndef ATL_vsplat3
   #define ATL_vsplat3(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[3]
   #endif
   #ifndef ATL_vsplat4
   #define ATL_vsplat4(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[4]
   #endif
   #ifndef ATL_vsplat5
   #define ATL_vsplat5(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[5]
   #endif
   #ifndef ATL_vsplat6
   #define ATL_vsplat6(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[6]
   #endif
   #ifndef ATL_vsplat7
   #define ATL_vsplat7(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[7]
   #endif
   #ifndef ATL_vsplat8
   #define ATL_vsplat8(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[8]
   #endif
   #ifndef ATL_vsplat9
   #define ATL_vsplat9(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[9]
   #endif
   #ifndef ATL_vsplat10
   #define ATL_vsplat10(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[10]
   #endif
   #ifndef ATL_vsplat11
   #define ATL_vsplat11(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[11]
   #endif
   #ifndef ATL_vsplat12
   #define ATL_vsplat12(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[12]
   #endif
   #ifndef ATL_vsplat13
   #define ATL_vsplat13(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[13]
   #endif
   #ifndef ATL_vsplat14
   #define ATL_vsplat14(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[14]
   #endif
   #ifndef ATL_vsplat15
   #define ATL_vsplat15(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15] = s_[15]
   #endif
#elif ATL_VLEN == 32
   #ifndef ATL_vsplat0
   #define ATL_vsplat0(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[0]
   #endif
   #ifndef ATL_vsplat1
   #define ATL_vsplat1(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[1]
   #endif
   #ifndef ATL_vsplat2
   #define ATL_vsplat2(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[2]
   #endif
   #ifndef ATL_vsplat3
   #define ATL_vsplat3(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[3]
   #endif
   #ifndef ATL_vsplat4
   #define ATL_vsplat4(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[4]
   #endif
   #ifndef ATL_vsplat5
   #define ATL_vsplat5(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[5]
   #endif
   #ifndef ATL_vsplat6
   #define ATL_vsplat6(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[6]
   #endif
   #ifndef ATL_vsplat7
   #define ATL_vsplat7(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[7]
   #endif
   #ifndef ATL_vsplat8
   #define ATL_vsplat8(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[8]
   #endif
   #ifndef ATL_vsplat9
   #define ATL_vsplat9(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[9]
   #endif
   #ifndef ATL_vsplat10
   #define ATL_vsplat10(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[10]
   #endif
   #ifndef ATL_vsplat11
   #define ATL_vsplat11(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[11]
   #endif
   #ifndef ATL_vsplat12
   #define ATL_vsplat12(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[12]
   #endif
   #ifndef ATL_vsplat13
   #define ATL_vsplat13(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[13]
   #endif
   #ifndef ATL_vsplat14
   #define ATL_vsplat14(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[14]
   #endif
   #ifndef ATL_vsplat15
   #define ATL_vsplat15(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[15]
   #endif
   #ifndef ATL_vsplat16
   #define ATL_vsplat16(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[16]
   #endif
   #ifndef ATL_vsplat17
   #define ATL_vsplat17(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[17]
   #endif
   #ifndef ATL_vsplat18
   #define ATL_vsplat18(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[18]
   #endif
   #ifndef ATL_vsplat19
   #define ATL_vsplat19(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[19]
   #endif
   #ifndef ATL_vsplat20
   #define ATL_vsplat20(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[20]
   #endif
   #ifndef ATL_vsplat21
   #define ATL_vsplat21(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[21]
   #endif
   #ifndef ATL_vsplat22
   #define ATL_vsplat22(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[22]
   #endif
   #ifndef ATL_vsplat23
   #define ATL_vsplat23(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[23]
   #endif
   #ifndef ATL_vsplat24
   #define ATL_vsplat24(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[24]
   #endif
   #ifndef ATL_vsplat25
   #define ATL_vsplat25(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[25]
   #endif
   #ifndef ATL_vsplat26
   #define ATL_vsplat26(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[26]
   #endif
   #ifndef ATL_vsplat27
   #define ATL_vsplat27(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[27]
   #endif
   #ifndef ATL_vsplat28
   #define ATL_vsplat28(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[28]
   #endif
   #ifndef ATL_vsplat29
   #define ATL_vsplat29(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[29]
   #endif
   #ifndef ATL_vsplat30
   #define ATL_vsplat30(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[30]
   #endif
   #ifndef ATL_vsplat31
   #define ATL_vsplat31(d_, s_) \
      d_[0]=d_[1]=d_[2]=d_[3]=d_[4]=d_[5]=d_[6]=d_[7]=d_[8]=d_[9]=d_[10]=d_[11]=d_[12]=d_[13]=d_[14]=d_[15]=d_[16]=d_[17]=d_[18]=d_[19]=d_[20]=d_[21]=d_[22]=d_[23]=d_[24]=d_[25]=d_[26]=d_[27]=d_[28]=d_[29]=d_[30]=d_[31] = s_[31]
   #endif
#endif
/*
 * If we don't have one defined, write slow version that should work with
 * any gcc-compatible compiler
 */
#ifndef ATL_vrsum1
   #define ATL_vrsum1(d_, s_) \
   {  TYPE mem_[ATL_VLEN] __attribute__ ((aligned (ATL_VLENb)));\
      int i_; \
      ATL_vst(mem_, s_); \
      d_ = *mem_; \
      for (i_=1; i_ < ATL_VLEN; i_++) \
         d_ += mem_[i_]; \
   }
#endif

#endif  /* end multiple-inclusion guard */
