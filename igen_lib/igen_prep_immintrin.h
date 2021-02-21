#pragma once

#include <immintrin.h>

#ifdef _mm_cvtsi32_ss
#undef _mm_cvtsi32_ss
__m128 _mm_cvtsi32_ss(__m128 _a, int b);
#endif
#ifdef _mm_cvtsi64_ss
#undef _mm_cvtsi64_ss
__m128 _mm_cvtsi64_ss(__m128 _a, long b);
#endif
#ifdef _mm_cvtpi32_ps
#undef _mm_cvtpi32_ps
__m128 _mm_cvtpi32_ps(__m128 _a, __m64 _b);
#endif
#ifdef _mm_cvtpi16_ps
#undef _mm_cvtpi16_ps
__m128 _mm_cvtpi16_ps(__m64 _a);
#endif
#ifdef _mm_cvtpu16_ps
#undef _mm_cvtpu16_ps
__m128 _mm_cvtpu16_ps(__m64 _a);
#endif
#ifdef _mm_cvtpi8_ps
#undef _mm_cvtpi8_ps
__m128 _mm_cvtpi8_ps(__m64 _a);
#endif
#ifdef _mm_cvtpu8_ps
#undef _mm_cvtpu8_ps
__m128 _mm_cvtpu8_ps(__m64 _a);
#endif
#ifdef _mm_cvtpi32x2_ps
#undef _mm_cvtpi32x2_ps
__m128 _mm_cvtpi32x2_ps(__m64 _a, __m64 _b);
#endif
#ifdef _mm_add_ss
#undef _mm_add_ss
__m128 _mm_add_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_add_ps
#undef _mm_add_ps
__m128 _mm_add_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_sub_ss
#undef _mm_sub_ss
__m128 _mm_sub_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_sub_ps
#undef _mm_sub_ps
__m128 _mm_sub_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_mul_ss
#undef _mm_mul_ss
__m128 _mm_mul_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_mul_ps
#undef _mm_mul_ps
__m128 _mm_mul_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_div_ss
#undef _mm_div_ss
__m128 _mm_div_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_div_ps
#undef _mm_div_ps
__m128 _mm_div_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_sqrt_ss
#undef _mm_sqrt_ss
__m128 _mm_sqrt_ss(__m128 _a);
#endif
#ifdef _mm_sqrt_ps
#undef _mm_sqrt_ps
__m128 _mm_sqrt_ps(__m128 _a);
#endif
#ifdef _mm_rcp_ss
#undef _mm_rcp_ss
__m128 _mm_rcp_ss(__m128 _a);
#endif
#ifdef _mm_rcp_ps
#undef _mm_rcp_ps
__m128 _mm_rcp_ps(__m128 _a);
#endif
#ifdef _mm_rsqrt_ss
#undef _mm_rsqrt_ss
__m128 _mm_rsqrt_ss(__m128 _a);
#endif
#ifdef _mm_rsqrt_ps
#undef _mm_rsqrt_ps
__m128 _mm_rsqrt_ps(__m128 _a);
#endif
#ifdef _mm_min_ss
#undef _mm_min_ss
__m128 _mm_min_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_min_ps
#undef _mm_min_ps
__m128 _mm_min_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_max_ss
#undef _mm_max_ss
__m128 _mm_max_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_max_ps
#undef _mm_max_ps
__m128 _mm_max_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_and_ps
#undef _mm_and_ps
__m128 _mm_and_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_andnot_ps
#undef _mm_andnot_ps
__m128 _mm_andnot_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_or_ps
#undef _mm_or_ps
__m128 _mm_or_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_xor_ps
#undef _mm_xor_ps
__m128 _mm_xor_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpeq_ss
#undef _mm_cmpeq_ss
__m128 _mm_cmpeq_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpeq_ps
#undef _mm_cmpeq_ps
__m128 _mm_cmpeq_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmplt_ss
#undef _mm_cmplt_ss
__m128 _mm_cmplt_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmplt_ps
#undef _mm_cmplt_ps
__m128 _mm_cmplt_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmple_ss
#undef _mm_cmple_ss
__m128 _mm_cmple_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmple_ps
#undef _mm_cmple_ps
__m128 _mm_cmple_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpgt_ss
#undef _mm_cmpgt_ss
__m128 _mm_cmpgt_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpgt_ps
#undef _mm_cmpgt_ps
__m128 _mm_cmpgt_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpge_ss
#undef _mm_cmpge_ss
__m128 _mm_cmpge_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpge_ps
#undef _mm_cmpge_ps
__m128 _mm_cmpge_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpneq_ss
#undef _mm_cmpneq_ss
__m128 _mm_cmpneq_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpneq_ps
#undef _mm_cmpneq_ps
__m128 _mm_cmpneq_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpnlt_ss
#undef _mm_cmpnlt_ss
__m128 _mm_cmpnlt_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpnlt_ps
#undef _mm_cmpnlt_ps
__m128 _mm_cmpnlt_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpnle_ss
#undef _mm_cmpnle_ss
__m128 _mm_cmpnle_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpnle_ps
#undef _mm_cmpnle_ps
__m128 _mm_cmpnle_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpngt_ss
#undef _mm_cmpngt_ss
__m128 _mm_cmpngt_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpngt_ps
#undef _mm_cmpngt_ps
__m128 _mm_cmpngt_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpnge_ss
#undef _mm_cmpnge_ss
__m128 _mm_cmpnge_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpnge_ps
#undef _mm_cmpnge_ps
__m128 _mm_cmpnge_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpord_ss
#undef _mm_cmpord_ss
__m128 _mm_cmpord_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpord_ps
#undef _mm_cmpord_ps
__m128 _mm_cmpord_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpunord_ss
#undef _mm_cmpunord_ss
__m128 _mm_cmpunord_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cmpunord_ps
#undef _mm_cmpunord_ps
__m128 _mm_cmpunord_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_comieq_ss
#undef _mm_comieq_ss
int _mm_comieq_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_comilt_ss
#undef _mm_comilt_ss
int _mm_comilt_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_comile_ss
#undef _mm_comile_ss
int _mm_comile_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_comigt_ss
#undef _mm_comigt_ss
int _mm_comigt_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_comige_ss
#undef _mm_comige_ss
int _mm_comige_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_comineq_ss
#undef _mm_comineq_ss
int _mm_comineq_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_ucomieq_ss
#undef _mm_ucomieq_ss
int _mm_ucomieq_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_ucomilt_ss
#undef _mm_ucomilt_ss
int _mm_ucomilt_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_ucomile_ss
#undef _mm_ucomile_ss
int _mm_ucomile_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_ucomigt_ss
#undef _mm_ucomigt_ss
int _mm_ucomigt_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_ucomige_ss
#undef _mm_ucomige_ss
int _mm_ucomige_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_ucomineq_ss
#undef _mm_ucomineq_ss
int _mm_ucomineq_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_cvtss_si32
#undef _mm_cvtss_si32
int _mm_cvtss_si32(__m128 _a);
#endif
#ifdef _mm_cvt_ss2si
#undef _mm_cvt_ss2si
int _mm_cvt_ss2si(__m128 _a);
#endif
#ifdef _mm_cvtss_si64
#undef _mm_cvtss_si64
long _mm_cvtss_si64(__m128 _a);
#endif
#ifdef _mm_cvtss_f32
#undef _mm_cvtss_f32
float _mm_cvtss_f32(__m128 _a);
#endif
#ifdef _mm_cvtps_pi32
#undef _mm_cvtps_pi32
__m64 _mm_cvtps_pi32(__m128 _a);
#endif
#ifdef _mm_cvt_ps2pi
#undef _mm_cvt_ps2pi
__m64 _mm_cvt_ps2pi(__m128 _a);
#endif
#ifdef _mm_cvttss_si32
#undef _mm_cvttss_si32
int _mm_cvttss_si32(__m128 _a);
#endif
#ifdef _mm_cvtt_ss2si
#undef _mm_cvtt_ss2si
int _mm_cvtt_ss2si(__m128 _a);
#endif
#ifdef _mm_cvttss_si64
#undef _mm_cvttss_si64
long _mm_cvttss_si64(__m128 _a);
#endif
#ifdef _mm_cvttps_pi32
#undef _mm_cvttps_pi32
__m64 _mm_cvttps_pi32(__m128 _a);
#endif
#ifdef _mm_cvtt_ps2pi
#undef _mm_cvtt_ps2pi
__m64 _mm_cvtt_ps2pi(__m128 _a);
#endif
#ifdef _mm_cvtps_pi16
#undef _mm_cvtps_pi16
__m64 _mm_cvtps_pi16(__m128 _a);
#endif
#ifdef _mm_cvtps_pi8
#undef _mm_cvtps_pi8
__m64 _mm_cvtps_pi8(__m128 _a);
#endif
#ifdef _mm_set_ss
#undef _mm_set_ss
__m128 _mm_set_ss(float a);
#endif
#ifdef _mm_set1_ps
#undef _mm_set1_ps
__m128 _mm_set1_ps(float a);
#endif
#ifdef _mm_set_ps1
#undef _mm_set_ps1
__m128 _mm_set_ps1(float a);
#endif
#ifdef _mm_set_ps
#undef _mm_set_ps
__m128 _mm_set_ps(float e3, float e2, float e1, float e0);
#endif
#ifdef _mm_setr_ps
#undef _mm_setr_ps
__m128 _mm_setr_ps(float e3, float e2, float e1, float e0);
#endif
#ifdef _mm_setzero_ps
#undef _mm_setzero_ps
__m128 _mm_setzero_ps();
#endif
#ifdef _mm_load_ss
#undef _mm_load_ss
__m128 _mm_load_ss(float const * mem_addr);
#endif
#ifdef _mm_load1_ps
#undef _mm_load1_ps
__m128 _mm_load1_ps(float const * mem_addr);
#endif
#ifdef _mm_load_ps1
#undef _mm_load_ps1
__m128 _mm_load_ps1(float const * mem_addr);
#endif
#ifdef _mm_load_ps
#undef _mm_load_ps
__m128 _mm_load_ps(float const * mem_addr);
#endif
#ifdef _mm_loadu_ps
#undef _mm_loadu_ps
__m128 _mm_loadu_ps(float const * mem_addr);
#endif
#ifdef _mm_loadr_ps
#undef _mm_loadr_ps
__m128 _mm_loadr_ps(float const * mem_addr);
#endif
#ifdef _mm_stream_ps
#undef _mm_stream_ps
void _mm_stream_ps(float * mem_addr, __m128 _a);
#endif
#ifdef _mm_store_ss
#undef _mm_store_ss
void _mm_store_ss(float * mem_addr, __m128 _a);
#endif
#ifdef _mm_store1_ps
#undef _mm_store1_ps
void _mm_store1_ps(float * mem_addr, __m128 _a);
#endif
#ifdef _mm_store_ps1
#undef _mm_store_ps1
void _mm_store_ps1(float * mem_addr, __m128 _a);
#endif
#ifdef _mm_store_ps
#undef _mm_store_ps
void _mm_store_ps(float * mem_addr, __m128 _a);
#endif
#ifdef _mm_storeu_ps
#undef _mm_storeu_ps
void _mm_storeu_ps(float * mem_addr, __m128 _a);
#endif
#ifdef _mm_storer_ps
#undef _mm_storer_ps
void _mm_storer_ps(float * mem_addr, __m128 _a);
#endif
#ifdef _mm_move_ss
#undef _mm_move_ss
__m128 _mm_move_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_shuffle_ps
#undef _mm_shuffle_ps
__m128 _mm_shuffle_ps(__m128 _a, __m128 _b, unsigned int imm8);
#endif
#ifdef _mm_unpackhi_ps
#undef _mm_unpackhi_ps
__m128 _mm_unpackhi_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_unpacklo_ps
#undef _mm_unpacklo_ps
__m128 _mm_unpacklo_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_movehl_ps
#undef _mm_movehl_ps
__m128 _mm_movehl_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_movelh_ps
#undef _mm_movelh_ps
__m128 _mm_movelh_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_movemask_ps
#undef _mm_movemask_ps
int _mm_movemask_ps(__m128 _a);
#endif
#ifdef _mm_cvtepi32_pd
#undef _mm_cvtepi32_pd
__m128d _mm_cvtepi32_pd(__m128i _a);
#endif
#ifdef _mm_cvtsi32_sd
#undef _mm_cvtsi32_sd
__m128d _mm_cvtsi32_sd(__m128d _a, int b);
#endif
#ifdef _mm_cvtsi64_sd
#undef _mm_cvtsi64_sd
__m128d _mm_cvtsi64_sd(__m128d _a, long b);
#endif
#ifdef _mm_cvtsi64x_sd
#undef _mm_cvtsi64x_sd
__m128d _mm_cvtsi64x_sd(__m128d _a, long b);
#endif
#ifdef _mm_cvtepi32_ps
#undef _mm_cvtepi32_ps
__m128 _mm_cvtepi32_ps(__m128i _a);
#endif
#ifdef _mm_cvtpi32_pd
#undef _mm_cvtpi32_pd
__m128d _mm_cvtpi32_pd(__m64 _a);
#endif
#ifdef _mm_add_sd
#undef _mm_add_sd
__m128d _mm_add_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_add_pd
#undef _mm_add_pd
__m128d _mm_add_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_div_sd
#undef _mm_div_sd
__m128d _mm_div_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_div_pd
#undef _mm_div_pd
__m128d _mm_div_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_max_sd
#undef _mm_max_sd
__m128d _mm_max_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_max_pd
#undef _mm_max_pd
__m128d _mm_max_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_min_sd
#undef _mm_min_sd
__m128d _mm_min_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_min_pd
#undef _mm_min_pd
__m128d _mm_min_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_mul_sd
#undef _mm_mul_sd
__m128d _mm_mul_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_mul_pd
#undef _mm_mul_pd
__m128d _mm_mul_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_sqrt_sd
#undef _mm_sqrt_sd
__m128d _mm_sqrt_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_sqrt_pd
#undef _mm_sqrt_pd
__m128d _mm_sqrt_pd(__m128d _a);
#endif
#ifdef _mm_sub_sd
#undef _mm_sub_sd
__m128d _mm_sub_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_sub_pd
#undef _mm_sub_pd
__m128d _mm_sub_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_and_pd
#undef _mm_and_pd
__m128d _mm_and_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_andnot_pd
#undef _mm_andnot_pd
__m128d _mm_andnot_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_or_pd
#undef _mm_or_pd
__m128d _mm_or_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_xor_pd
#undef _mm_xor_pd
__m128d _mm_xor_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpeq_sd
#undef _mm_cmpeq_sd
__m128d _mm_cmpeq_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmplt_sd
#undef _mm_cmplt_sd
__m128d _mm_cmplt_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmple_sd
#undef _mm_cmple_sd
__m128d _mm_cmple_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpgt_sd
#undef _mm_cmpgt_sd
__m128d _mm_cmpgt_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpge_sd
#undef _mm_cmpge_sd
__m128d _mm_cmpge_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpord_sd
#undef _mm_cmpord_sd
__m128d _mm_cmpord_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpunord_sd
#undef _mm_cmpunord_sd
__m128d _mm_cmpunord_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpneq_sd
#undef _mm_cmpneq_sd
__m128d _mm_cmpneq_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpnlt_sd
#undef _mm_cmpnlt_sd
__m128d _mm_cmpnlt_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpnle_sd
#undef _mm_cmpnle_sd
__m128d _mm_cmpnle_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpngt_sd
#undef _mm_cmpngt_sd
__m128d _mm_cmpngt_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpnge_sd
#undef _mm_cmpnge_sd
__m128d _mm_cmpnge_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpeq_pd
#undef _mm_cmpeq_pd
__m128d _mm_cmpeq_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmplt_pd
#undef _mm_cmplt_pd
__m128d _mm_cmplt_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmple_pd
#undef _mm_cmple_pd
__m128d _mm_cmple_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpgt_pd
#undef _mm_cmpgt_pd
__m128d _mm_cmpgt_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpge_pd
#undef _mm_cmpge_pd
__m128d _mm_cmpge_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpord_pd
#undef _mm_cmpord_pd
__m128d _mm_cmpord_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpunord_pd
#undef _mm_cmpunord_pd
__m128d _mm_cmpunord_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpneq_pd
#undef _mm_cmpneq_pd
__m128d _mm_cmpneq_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpnlt_pd
#undef _mm_cmpnlt_pd
__m128d _mm_cmpnlt_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpnle_pd
#undef _mm_cmpnle_pd
__m128d _mm_cmpnle_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpngt_pd
#undef _mm_cmpngt_pd
__m128d _mm_cmpngt_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cmpnge_pd
#undef _mm_cmpnge_pd
__m128d _mm_cmpnge_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_comieq_sd
#undef _mm_comieq_sd
int _mm_comieq_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_comilt_sd
#undef _mm_comilt_sd
int _mm_comilt_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_comile_sd
#undef _mm_comile_sd
int _mm_comile_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_comigt_sd
#undef _mm_comigt_sd
int _mm_comigt_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_comige_sd
#undef _mm_comige_sd
int _mm_comige_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_comineq_sd
#undef _mm_comineq_sd
int _mm_comineq_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_ucomieq_sd
#undef _mm_ucomieq_sd
int _mm_ucomieq_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_ucomilt_sd
#undef _mm_ucomilt_sd
int _mm_ucomilt_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_ucomile_sd
#undef _mm_ucomile_sd
int _mm_ucomile_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_ucomigt_sd
#undef _mm_ucomigt_sd
int _mm_ucomigt_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_ucomige_sd
#undef _mm_ucomige_sd
int _mm_ucomige_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_ucomineq_sd
#undef _mm_ucomineq_sd
int _mm_ucomineq_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_cvtpd_ps
#undef _mm_cvtpd_ps
__m128 _mm_cvtpd_ps(__m128d _a);
#endif
#ifdef _mm_cvtps_pd
#undef _mm_cvtps_pd
__m128d _mm_cvtps_pd(__m128 _a);
#endif
#ifdef _mm_cvtpd_epi32
#undef _mm_cvtpd_epi32
__m128i _mm_cvtpd_epi32(__m128d _a);
#endif
#ifdef _mm_cvtsd_si32
#undef _mm_cvtsd_si32
int _mm_cvtsd_si32(__m128d _a);
#endif
#ifdef _mm_cvtsd_si64
#undef _mm_cvtsd_si64
long _mm_cvtsd_si64(__m128d _a);
#endif
#ifdef _mm_cvtsd_si64x
#undef _mm_cvtsd_si64x
long _mm_cvtsd_si64x(__m128d _a);
#endif
#ifdef _mm_cvtsd_ss
#undef _mm_cvtsd_ss
__m128 _mm_cvtsd_ss(__m128 _a, __m128d _b);
#endif
#ifdef _mm_cvtsd_f64
#undef _mm_cvtsd_f64
double _mm_cvtsd_f64(__m128d _a);
#endif
#ifdef _mm_cvtss_sd
#undef _mm_cvtss_sd
__m128d _mm_cvtss_sd(__m128d _a, __m128 _b);
#endif
#ifdef _mm_cvttpd_epi32
#undef _mm_cvttpd_epi32
__m128i _mm_cvttpd_epi32(__m128d _a);
#endif
#ifdef _mm_cvttsd_si32
#undef _mm_cvttsd_si32
int _mm_cvttsd_si32(__m128d _a);
#endif
#ifdef _mm_cvttsd_si64
#undef _mm_cvttsd_si64
long _mm_cvttsd_si64(__m128d _a);
#endif
#ifdef _mm_cvttsd_si64x
#undef _mm_cvttsd_si64x
long _mm_cvttsd_si64x(__m128d _a);
#endif
#ifdef _mm_cvtps_epi32
#undef _mm_cvtps_epi32
__m128i _mm_cvtps_epi32(__m128 _a);
#endif
#ifdef _mm_cvttps_epi32
#undef _mm_cvttps_epi32
__m128i _mm_cvttps_epi32(__m128 _a);
#endif
#ifdef _mm_cvtpd_pi32
#undef _mm_cvtpd_pi32
__m64 _mm_cvtpd_pi32(__m128d _a);
#endif
#ifdef _mm_cvttpd_pi32
#undef _mm_cvttpd_pi32
__m64 _mm_cvttpd_pi32(__m128d _a);
#endif
#ifdef _mm_set_sd
#undef _mm_set_sd
__m128d _mm_set_sd(double a);
#endif
#ifdef _mm_set1_pd
#undef _mm_set1_pd
__m128d _mm_set1_pd(double a);
#endif
#ifdef _mm_set_pd1
#undef _mm_set_pd1
__m128d _mm_set_pd1(double a);
#endif
#ifdef _mm_set_pd
#undef _mm_set_pd
__m128d _mm_set_pd(double e1, double e0);
#endif
#ifdef _mm_setr_pd
#undef _mm_setr_pd
__m128d _mm_setr_pd(double e1, double e0);
#endif
#ifdef _mm_setzero_pd
#undef _mm_setzero_pd
__m128d _mm_setzero_pd();
#endif
#ifdef _mm_load_pd
#undef _mm_load_pd
__m128d _mm_load_pd(double const * mem_addr);
#endif
#ifdef _mm_load1_pd
#undef _mm_load1_pd
__m128d _mm_load1_pd(double const * mem_addr);
#endif
#ifdef _mm_load_pd1
#undef _mm_load_pd1
__m128d _mm_load_pd1(double const * mem_addr);
#endif
#ifdef _mm_loadr_pd
#undef _mm_loadr_pd
__m128d _mm_loadr_pd(double const * mem_addr);
#endif
#ifdef _mm_loadu_pd
#undef _mm_loadu_pd
__m128d _mm_loadu_pd(double const * mem_addr);
#endif
#ifdef _mm_load_sd
#undef _mm_load_sd
__m128d _mm_load_sd(double const * mem_addr);
#endif
#ifdef _mm_loadh_pd
#undef _mm_loadh_pd
__m128d _mm_loadh_pd(__m128d _a, double const * mem_addr);
#endif
#ifdef _mm_loadl_pd
#undef _mm_loadl_pd
__m128d _mm_loadl_pd(__m128d _a, double const * mem_addr);
#endif
#ifdef _mm_stream_pd
#undef _mm_stream_pd
void _mm_stream_pd(double * mem_addr, __m128d _a);
#endif
#ifdef _mm_store_sd
#undef _mm_store_sd
void _mm_store_sd(double * mem_addr, __m128d _a);
#endif
#ifdef _mm_store1_pd
#undef _mm_store1_pd
void _mm_store1_pd(double * mem_addr, __m128d _a);
#endif
#ifdef _mm_store_pd1
#undef _mm_store_pd1
void _mm_store_pd1(double * mem_addr, __m128d _a);
#endif
#ifdef _mm_store_pd
#undef _mm_store_pd
void _mm_store_pd(double * mem_addr, __m128d _a);
#endif
#ifdef _mm_storeu_pd
#undef _mm_storeu_pd
void _mm_storeu_pd(double * mem_addr, __m128d _a);
#endif
#ifdef _mm_storer_pd
#undef _mm_storer_pd
void _mm_storer_pd(double * mem_addr, __m128d _a);
#endif
#ifdef _mm_storeh_pd
#undef _mm_storeh_pd
void _mm_storeh_pd(double * mem_addr, __m128d _a);
#endif
#ifdef _mm_storel_pd
#undef _mm_storel_pd
void _mm_storel_pd(double * mem_addr, __m128d _a);
#endif
#ifdef _mm_unpackhi_pd
#undef _mm_unpackhi_pd
__m128d _mm_unpackhi_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_unpacklo_pd
#undef _mm_unpacklo_pd
__m128d _mm_unpacklo_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_movemask_pd
#undef _mm_movemask_pd
int _mm_movemask_pd(__m128d _a);
#endif
#ifdef _mm_shuffle_pd
#undef _mm_shuffle_pd
__m128d _mm_shuffle_pd(__m128d _a, __m128d _b, int imm8);
#endif
#ifdef _mm_move_sd
#undef _mm_move_sd
__m128d _mm_move_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_castpd_ps
#undef _mm_castpd_ps
__m128 _mm_castpd_ps(__m128d _a);
#endif
#ifdef _mm_castpd_si128
#undef _mm_castpd_si128
__m128i _mm_castpd_si128(__m128d _a);
#endif
#ifdef _mm_castps_pd
#undef _mm_castps_pd
__m128d _mm_castps_pd(__m128 _a);
#endif
#ifdef _mm_castps_si128
#undef _mm_castps_si128
__m128i _mm_castps_si128(__m128 _a);
#endif
#ifdef _mm_castsi128_pd
#undef _mm_castsi128_pd
__m128d _mm_castsi128_pd(__m128i _a);
#endif
#ifdef _mm_castsi128_ps
#undef _mm_castsi128_ps
__m128 _mm_castsi128_ps(__m128i _a);
#endif
#ifdef _cvtsh_ss
#undef _cvtsh_ss
float _cvtsh_ss(__mmask16 a);
#endif
#ifdef _cvtss_sh
#undef _cvtss_sh
__mmask16 _cvtss_sh(float a, int rounding);
#endif
#ifdef _mm_cvtph_ps
#undef _mm_cvtph_ps
__m128 _mm_cvtph_ps(__m128i _a);
#endif
#ifdef _mm_cvtps_ph
#undef _mm_cvtps_ph
__m128i _mm_cvtps_ph(__m128 _a, int rounding);
#endif
#ifdef _mm_addsub_ps
#undef _mm_addsub_ps
__m128 _mm_addsub_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_addsub_pd
#undef _mm_addsub_pd
__m128d _mm_addsub_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_hadd_pd
#undef _mm_hadd_pd
__m128d _mm_hadd_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_hadd_ps
#undef _mm_hadd_ps
__m128 _mm_hadd_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_hsub_pd
#undef _mm_hsub_pd
__m128d _mm_hsub_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_hsub_ps
#undef _mm_hsub_ps
__m128 _mm_hsub_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_movedup_pd
#undef _mm_movedup_pd
__m128d _mm_movedup_pd(__m128d _a);
#endif
#ifdef _mm_loaddup_pd
#undef _mm_loaddup_pd
__m128d _mm_loaddup_pd(double const * mem_addr);
#endif
#ifdef _mm_movehdup_ps
#undef _mm_movehdup_ps
__m128 _mm_movehdup_ps(__m128 _a);
#endif
#ifdef _mm_moveldup_ps
#undef _mm_moveldup_ps
__m128 _mm_moveldup_ps(__m128 _a);
#endif
#ifdef _mm_blend_pd
#undef _mm_blend_pd
__m128d _mm_blend_pd(__m128d _a, __m128d _b, int imm8);
#endif
#ifdef _mm_blend_ps
#undef _mm_blend_ps
__m128 _mm_blend_ps(__m128 _a, __m128 _b, int imm8);
#endif
#ifdef _mm_blendv_pd
#undef _mm_blendv_pd
__m128d _mm_blendv_pd(__m128d _a, __m128d _b, __m128d _mask);
#endif
#ifdef _mm_blendv_ps
#undef _mm_blendv_ps
__m128 _mm_blendv_ps(__m128 _a, __m128 _b, __m128 _mask);
#endif
#ifdef _mm_dp_pd
#undef _mm_dp_pd
__m128d _mm_dp_pd(__m128d _a, __m128d _b, int imm8);
#endif
#ifdef _mm_dp_ps
#undef _mm_dp_ps
__m128 _mm_dp_ps(__m128 _a, __m128 _b, int imm8);
#endif
#ifdef _mm_extract_ps
#undef _mm_extract_ps
int _mm_extract_ps(__m128 _a, int imm8);
#endif
#ifdef _mm_insert_ps
#undef _mm_insert_ps
__m128 _mm_insert_ps(__m128 _a, __m128 _b, int imm8);
#endif
#ifdef _mm_round_pd
#undef _mm_round_pd
__m128d _mm_round_pd(__m128d _a, int rounding);
#endif
#ifdef _mm_floor_pd
#undef _mm_floor_pd
__m128d _mm_floor_pd(__m128d _a);
#endif
#ifdef _mm_ceil_pd
#undef _mm_ceil_pd
__m128d _mm_ceil_pd(__m128d _a);
#endif
#ifdef _mm_round_ps
#undef _mm_round_ps
__m128 _mm_round_ps(__m128 _a, int rounding);
#endif
#ifdef _mm_floor_ps
#undef _mm_floor_ps
__m128 _mm_floor_ps(__m128 _a);
#endif
#ifdef _mm_ceil_ps
#undef _mm_ceil_ps
__m128 _mm_ceil_ps(__m128 _a);
#endif
#ifdef _mm_round_sd
#undef _mm_round_sd
__m128d _mm_round_sd(__m128d _a, __m128d _b, int rounding);
#endif
#ifdef _mm_floor_sd
#undef _mm_floor_sd
__m128d _mm_floor_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_ceil_sd
#undef _mm_ceil_sd
__m128d _mm_ceil_sd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_round_ss
#undef _mm_round_ss
__m128 _mm_round_ss(__m128 _a, __m128 _b, int rounding);
#endif
#ifdef _mm_floor_ss
#undef _mm_floor_ss
__m128 _mm_floor_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm_ceil_ss
#undef _mm_ceil_ss
__m128 _mm_ceil_ss(__m128 _a, __m128 _b);
#endif
#ifdef _mm256_add_pd
#undef _mm256_add_pd
__m256d _mm256_add_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_add_ps
#undef _mm256_add_ps
__m256 _mm256_add_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_addsub_pd
#undef _mm256_addsub_pd
__m256d _mm256_addsub_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_addsub_ps
#undef _mm256_addsub_ps
__m256 _mm256_addsub_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_and_pd
#undef _mm256_and_pd
__m256d _mm256_and_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_and_ps
#undef _mm256_and_ps
__m256 _mm256_and_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_andnot_pd
#undef _mm256_andnot_pd
__m256d _mm256_andnot_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_andnot_ps
#undef _mm256_andnot_ps
__m256 _mm256_andnot_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_blend_pd
#undef _mm256_blend_pd
__m256d _mm256_blend_pd(__m256d _a, __m256d _b, int imm8);
#endif
#ifdef _mm256_blend_ps
#undef _mm256_blend_ps
__m256 _mm256_blend_ps(__m256 _a, __m256 _b, int imm8);
#endif
#ifdef _mm256_blendv_pd
#undef _mm256_blendv_pd
__m256d _mm256_blendv_pd(__m256d _a, __m256d _b, __m256d _mask);
#endif
#ifdef _mm256_blendv_ps
#undef _mm256_blendv_ps
__m256 _mm256_blendv_ps(__m256 _a, __m256 _b, __m256 _mask);
#endif
#ifdef _mm256_div_pd
#undef _mm256_div_pd
__m256d _mm256_div_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_div_ps
#undef _mm256_div_ps
__m256 _mm256_div_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_dp_ps
#undef _mm256_dp_ps
__m256 _mm256_dp_ps(__m256 _a, __m256 _b, int imm8);
#endif
#ifdef _mm256_hadd_pd
#undef _mm256_hadd_pd
__m256d _mm256_hadd_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_hadd_ps
#undef _mm256_hadd_ps
__m256 _mm256_hadd_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_hsub_pd
#undef _mm256_hsub_pd
__m256d _mm256_hsub_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_hsub_ps
#undef _mm256_hsub_ps
__m256 _mm256_hsub_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_max_pd
#undef _mm256_max_pd
__m256d _mm256_max_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_max_ps
#undef _mm256_max_ps
__m256 _mm256_max_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_min_pd
#undef _mm256_min_pd
__m256d _mm256_min_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_min_ps
#undef _mm256_min_ps
__m256 _mm256_min_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_mul_pd
#undef _mm256_mul_pd
__m256d _mm256_mul_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_mul_ps
#undef _mm256_mul_ps
__m256 _mm256_mul_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_or_pd
#undef _mm256_or_pd
__m256d _mm256_or_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_or_ps
#undef _mm256_or_ps
__m256 _mm256_or_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_shuffle_pd
#undef _mm256_shuffle_pd
__m256d _mm256_shuffle_pd(__m256d _a, __m256d _b, int imm8);
#endif
#ifdef _mm256_shuffle_ps
#undef _mm256_shuffle_ps
__m256 _mm256_shuffle_ps(__m256 _a, __m256 _b, int imm8);
#endif
#ifdef _mm256_sub_pd
#undef _mm256_sub_pd
__m256d _mm256_sub_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_sub_ps
#undef _mm256_sub_ps
__m256 _mm256_sub_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_xor_pd
#undef _mm256_xor_pd
__m256d _mm256_xor_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_xor_ps
#undef _mm256_xor_ps
__m256 _mm256_xor_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm_cmp_pd
#undef _mm_cmp_pd
__m128d _mm_cmp_pd(__m128d _a, __m128d _b, int imm8);
#endif
#ifdef _mm256_cmp_pd
#undef _mm256_cmp_pd
__m256d _mm256_cmp_pd(__m256d _a, __m256d _b, int imm8);
#endif
#ifdef _mm_cmp_ps
#undef _mm_cmp_ps
__m128 _mm_cmp_ps(__m128 _a, __m128 _b, int imm8);
#endif
#ifdef _mm256_cmp_ps
#undef _mm256_cmp_ps
__m256 _mm256_cmp_ps(__m256 _a, __m256 _b, int imm8);
#endif
#ifdef _mm_cmp_sd
#undef _mm_cmp_sd
__m128d _mm_cmp_sd(__m128d _a, __m128d _b, int imm8);
#endif
#ifdef _mm_cmp_ss
#undef _mm_cmp_ss
__m128 _mm_cmp_ss(__m128 _a, __m128 _b, int imm8);
#endif
#ifdef _mm256_cvtepi32_pd
#undef _mm256_cvtepi32_pd
__m256d _mm256_cvtepi32_pd(__m128i _a);
#endif
#ifdef _mm256_cvtepi32_ps
#undef _mm256_cvtepi32_ps
__m256 _mm256_cvtepi32_ps(__m256i _a);
#endif
#ifdef _mm256_cvtpd_ps
#undef _mm256_cvtpd_ps
__m128 _mm256_cvtpd_ps(__m256d _a);
#endif
#ifdef _mm256_cvtps_epi32
#undef _mm256_cvtps_epi32
__m256i _mm256_cvtps_epi32(__m256 _a);
#endif
#ifdef _mm256_cvtps_pd
#undef _mm256_cvtps_pd
__m256d _mm256_cvtps_pd(__m128 _a);
#endif
#ifdef _mm256_cvttpd_epi32
#undef _mm256_cvttpd_epi32
__m128i _mm256_cvttpd_epi32(__m256d _a);
#endif
#ifdef _mm256_cvtpd_epi32
#undef _mm256_cvtpd_epi32
__m128i _mm256_cvtpd_epi32(__m256d _a);
#endif
#ifdef _mm256_cvttps_epi32
#undef _mm256_cvttps_epi32
__m256i _mm256_cvttps_epi32(__m256 _a);
#endif
#ifdef _mm256_extractf128_ps
#undef _mm256_extractf128_ps
__m128 _mm256_extractf128_ps(__m256 _a, int imm8);
#endif
#ifdef _mm256_extractf128_pd
#undef _mm256_extractf128_pd
__m128d _mm256_extractf128_pd(__m256d _a, int imm8);
#endif
#ifdef _mm256_permutevar_ps
#undef _mm256_permutevar_ps
__m256 _mm256_permutevar_ps(__m256 _a, __m256i _b);
#endif
#ifdef _mm_permutevar_ps
#undef _mm_permutevar_ps
__m128 _mm_permutevar_ps(__m128 _a, __m128i _b);
#endif
#ifdef _mm256_permute_ps
#undef _mm256_permute_ps
__m256 _mm256_permute_ps(__m256 _a, int imm8);
#endif
#ifdef _mm_permute_ps
#undef _mm_permute_ps
__m128 _mm_permute_ps(__m128 _a, int imm8);
#endif
#ifdef _mm256_permutevar_pd
#undef _mm256_permutevar_pd
__m256d _mm256_permutevar_pd(__m256d _a, __m256i _b);
#endif
#ifdef _mm_permutevar_pd
#undef _mm_permutevar_pd
__m128d _mm_permutevar_pd(__m128d _a, __m128i _b);
#endif
#ifdef _mm256_permute_pd
#undef _mm256_permute_pd
__m256d _mm256_permute_pd(__m256d _a, int imm8);
#endif
#ifdef _mm_permute_pd
#undef _mm_permute_pd
__m128d _mm_permute_pd(__m128d _a, int imm8);
#endif
#ifdef _mm256_permute2f128_ps
#undef _mm256_permute2f128_ps
__m256 _mm256_permute2f128_ps(__m256 _a, __m256 _b, int imm8);
#endif
#ifdef _mm256_permute2f128_pd
#undef _mm256_permute2f128_pd
__m256d _mm256_permute2f128_pd(__m256d _a, __m256d _b, int imm8);
#endif
#ifdef _mm256_broadcast_ss
#undef _mm256_broadcast_ss
__m256 _mm256_broadcast_ss(float const * mem_addr);
#endif
#ifdef _mm_broadcast_ss
#undef _mm_broadcast_ss
__m128 _mm_broadcast_ss(float const * mem_addr);
#endif
#ifdef _mm256_broadcast_sd
#undef _mm256_broadcast_sd
__m256d _mm256_broadcast_sd(double const * mem_addr);
#endif
#ifdef _mm256_broadcast_ps
#undef _mm256_broadcast_ps
__m256 _mm256_broadcast_ps(__m128 * _mem_addr);
#endif
#ifdef _mm256_broadcast_pd
#undef _mm256_broadcast_pd
__m256d _mm256_broadcast_pd(__m128d * _mem_addr);
#endif
#ifdef _mm256_insertf128_ps
#undef _mm256_insertf128_ps
__m256 _mm256_insertf128_ps(__m256 _a, __m128 _b, int imm8);
#endif
#ifdef _mm256_insertf128_pd
#undef _mm256_insertf128_pd
__m256d _mm256_insertf128_pd(__m256d _a, __m128d _b, int imm8);
#endif
#ifdef _mm256_load_pd
#undef _mm256_load_pd
__m256d _mm256_load_pd(double const * mem_addr);
#endif
#ifdef _mm256_store_pd
#undef _mm256_store_pd
void _mm256_store_pd(double * mem_addr, __m256d _a);
#endif
#ifdef _mm256_load_ps
#undef _mm256_load_ps
__m256 _mm256_load_ps(float const * mem_addr);
#endif
#ifdef _mm256_store_ps
#undef _mm256_store_ps
void _mm256_store_ps(float * mem_addr, __m256 _a);
#endif
#ifdef _mm256_loadu_pd
#undef _mm256_loadu_pd
__m256d _mm256_loadu_pd(double const * mem_addr);
#endif
#ifdef _mm256_storeu_pd
#undef _mm256_storeu_pd
void _mm256_storeu_pd(double * mem_addr, __m256d _a);
#endif
#ifdef _mm256_loadu_ps
#undef _mm256_loadu_ps
__m256 _mm256_loadu_ps(float const * mem_addr);
#endif
#ifdef _mm256_storeu_ps
#undef _mm256_storeu_ps
void _mm256_storeu_ps(float * mem_addr, __m256 _a);
#endif
#ifdef _mm256_maskload_pd
#undef _mm256_maskload_pd
__m256d _mm256_maskload_pd(double const * mem_addr, __m256i _mask);
#endif
#ifdef _mm256_maskstore_pd
#undef _mm256_maskstore_pd
void _mm256_maskstore_pd(double * mem_addr, __m256i _mask, __m256d _a);
#endif
#ifdef _mm_maskload_pd
#undef _mm_maskload_pd
__m128d _mm_maskload_pd(double const * mem_addr, __m128i _mask);
#endif
#ifdef _mm_maskstore_pd
#undef _mm_maskstore_pd
void _mm_maskstore_pd(double * mem_addr, __m128i _mask, __m128d _a);
#endif
#ifdef _mm256_maskload_ps
#undef _mm256_maskload_ps
__m256 _mm256_maskload_ps(float const * mem_addr, __m256i _mask);
#endif
#ifdef _mm256_maskstore_ps
#undef _mm256_maskstore_ps
void _mm256_maskstore_ps(float * mem_addr, __m256i _mask, __m256 _a);
#endif
#ifdef _mm_maskload_ps
#undef _mm_maskload_ps
__m128 _mm_maskload_ps(float const * mem_addr, __m128i _mask);
#endif
#ifdef _mm_maskstore_ps
#undef _mm_maskstore_ps
void _mm_maskstore_ps(float * mem_addr, __m128i _mask, __m128 _a);
#endif
#ifdef _mm256_movehdup_ps
#undef _mm256_movehdup_ps
__m256 _mm256_movehdup_ps(__m256 _a);
#endif
#ifdef _mm256_moveldup_ps
#undef _mm256_moveldup_ps
__m256 _mm256_moveldup_ps(__m256 _a);
#endif
#ifdef _mm256_movedup_pd
#undef _mm256_movedup_pd
__m256d _mm256_movedup_pd(__m256d _a);
#endif
#ifdef _mm256_stream_pd
#undef _mm256_stream_pd
void _mm256_stream_pd(double * mem_addr, __m256d _a);
#endif
#ifdef _mm256_stream_ps
#undef _mm256_stream_ps
void _mm256_stream_ps(float * mem_addr, __m256 _a);
#endif
#ifdef _mm256_rcp_ps
#undef _mm256_rcp_ps
__m256 _mm256_rcp_ps(__m256 _a);
#endif
#ifdef _mm256_rsqrt_ps
#undef _mm256_rsqrt_ps
__m256 _mm256_rsqrt_ps(__m256 _a);
#endif
#ifdef _mm256_sqrt_pd
#undef _mm256_sqrt_pd
__m256d _mm256_sqrt_pd(__m256d _a);
#endif
#ifdef _mm256_sqrt_ps
#undef _mm256_sqrt_ps
__m256 _mm256_sqrt_ps(__m256 _a);
#endif
#ifdef _mm256_round_pd
#undef _mm256_round_pd
__m256d _mm256_round_pd(__m256d _a, int rounding);
#endif
#ifdef _mm256_round_ps
#undef _mm256_round_ps
__m256 _mm256_round_ps(__m256 _a, int rounding);
#endif
#ifdef _mm256_unpackhi_pd
#undef _mm256_unpackhi_pd
__m256d _mm256_unpackhi_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_unpackhi_ps
#undef _mm256_unpackhi_ps
__m256 _mm256_unpackhi_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_unpacklo_pd
#undef _mm256_unpacklo_pd
__m256d _mm256_unpacklo_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_unpacklo_ps
#undef _mm256_unpacklo_ps
__m256 _mm256_unpacklo_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_testz_pd
#undef _mm256_testz_pd
int _mm256_testz_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_testc_pd
#undef _mm256_testc_pd
int _mm256_testc_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_testnzc_pd
#undef _mm256_testnzc_pd
int _mm256_testnzc_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm_testz_pd
#undef _mm_testz_pd
int _mm_testz_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_testc_pd
#undef _mm_testc_pd
int _mm_testc_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_testnzc_pd
#undef _mm_testnzc_pd
int _mm_testnzc_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm256_testz_ps
#undef _mm256_testz_ps
int _mm256_testz_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_testc_ps
#undef _mm256_testc_ps
int _mm256_testc_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_testnzc_ps
#undef _mm256_testnzc_ps
int _mm256_testnzc_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm_testz_ps
#undef _mm_testz_ps
int _mm_testz_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_testc_ps
#undef _mm_testc_ps
int _mm_testc_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_testnzc_ps
#undef _mm_testnzc_ps
int _mm_testnzc_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm256_movemask_pd
#undef _mm256_movemask_pd
int _mm256_movemask_pd(__m256d _a);
#endif
#ifdef _mm256_movemask_ps
#undef _mm256_movemask_ps
int _mm256_movemask_ps(__m256 _a);
#endif
#ifdef _mm256_setzero_pd
#undef _mm256_setzero_pd
__m256d _mm256_setzero_pd();
#endif
#ifdef _mm256_setzero_ps
#undef _mm256_setzero_ps
__m256 _mm256_setzero_ps();
#endif
#ifdef _mm256_set_pd
#undef _mm256_set_pd
__m256d _mm256_set_pd(double e3, double e2, double e1, double e0);
#endif
#ifdef _mm256_set_ps
#undef _mm256_set_ps
__m256 _mm256_set_ps(float e7, float e6, float e5, float e4, float e3, float e2, float e1, float e0);
#endif
#ifdef _mm256_setr_pd
#undef _mm256_setr_pd
__m256d _mm256_setr_pd(double e3, double e2, double e1, double e0);
#endif
#ifdef _mm256_setr_ps
#undef _mm256_setr_ps
__m256 _mm256_setr_ps(float e7, float e6, float e5, float e4, float e3, float e2, float e1, float e0);
#endif
#ifdef _mm256_set1_pd
#undef _mm256_set1_pd
__m256d _mm256_set1_pd(double a);
#endif
#ifdef _mm256_set1_ps
#undef _mm256_set1_ps
__m256 _mm256_set1_ps(float a);
#endif
#ifdef _mm256_castpd_ps
#undef _mm256_castpd_ps
__m256 _mm256_castpd_ps(__m256d _a);
#endif
#ifdef _mm256_castps_pd
#undef _mm256_castps_pd
__m256d _mm256_castps_pd(__m256 _a);
#endif
#ifdef _mm256_castps_si256
#undef _mm256_castps_si256
__m256i _mm256_castps_si256(__m256 _a);
#endif
#ifdef _mm256_castpd_si256
#undef _mm256_castpd_si256
__m256i _mm256_castpd_si256(__m256d _a);
#endif
#ifdef _mm256_castsi256_ps
#undef _mm256_castsi256_ps
__m256 _mm256_castsi256_ps(__m256i _a);
#endif
#ifdef _mm256_castsi256_pd
#undef _mm256_castsi256_pd
__m256d _mm256_castsi256_pd(__m256i _a);
#endif
#ifdef _mm256_castps256_ps128
#undef _mm256_castps256_ps128
__m128 _mm256_castps256_ps128(__m256 _a);
#endif
#ifdef _mm256_castpd256_pd128
#undef _mm256_castpd256_pd128
__m128d _mm256_castpd256_pd128(__m256d _a);
#endif
#ifdef _mm256_castps128_ps256
#undef _mm256_castps128_ps256
__m256 _mm256_castps128_ps256(__m128 _a);
#endif
#ifdef _mm256_castpd128_pd256
#undef _mm256_castpd128_pd256
__m256d _mm256_castpd128_pd256(__m128d _a);
#endif
#ifdef _mm256_zextps128_ps256
#undef _mm256_zextps128_ps256
__m256 _mm256_zextps128_ps256(__m128 _a);
#endif
#ifdef _mm256_zextpd128_pd256
#undef _mm256_zextpd128_pd256
__m256d _mm256_zextpd128_pd256(__m128d _a);
#endif
#ifdef _mm256_floor_ps
#undef _mm256_floor_ps
__m256 _mm256_floor_ps(__m256 _a);
#endif
#ifdef _mm256_ceil_ps
#undef _mm256_ceil_ps
__m256 _mm256_ceil_ps(__m256 _a);
#endif
#ifdef _mm256_floor_pd
#undef _mm256_floor_pd
__m256d _mm256_floor_pd(__m256d _a);
#endif
#ifdef _mm256_ceil_pd
#undef _mm256_ceil_pd
__m256d _mm256_ceil_pd(__m256d _a);
#endif
#ifdef _mm_undefined_ps
#undef _mm_undefined_ps
__m128 _mm_undefined_ps();
#endif
#ifdef _mm_undefined_pd
#undef _mm_undefined_pd
__m128d _mm_undefined_pd();
#endif
#ifdef _mm256_undefined_ps
#undef _mm256_undefined_ps
__m256 _mm256_undefined_ps();
#endif
#ifdef _mm256_undefined_pd
#undef _mm256_undefined_pd
__m256d _mm256_undefined_pd();
#endif
#ifdef _mm256_set_m128
#undef _mm256_set_m128
__m256 _mm256_set_m128(__m128 _hi, __m128 _lo);
#endif
#ifdef _mm256_set_m128d
#undef _mm256_set_m128d
__m256d _mm256_set_m128d(__m128d _hi, __m128d _lo);
#endif
#ifdef _mm256_setr_m128
#undef _mm256_setr_m128
__m256 _mm256_setr_m128(__m128 _lo, __m128 _hi);
#endif
#ifdef _mm256_setr_m128d
#undef _mm256_setr_m128d
__m256d _mm256_setr_m128d(__m128d _lo, __m128d _hi);
#endif
#ifdef _mm256_loadu2_m128
#undef _mm256_loadu2_m128
__m256 _mm256_loadu2_m128(float const * hiaddr, float const * loaddr);
#endif
#ifdef _mm256_loadu2_m128d
#undef _mm256_loadu2_m128d
__m256d _mm256_loadu2_m128d(double const * hiaddr, double const * loaddr);
#endif
#ifdef _mm256_storeu2_m128
#undef _mm256_storeu2_m128
void _mm256_storeu2_m128(float * hiaddr, float * loaddr, __m256 _a);
#endif
#ifdef _mm256_storeu2_m128d
#undef _mm256_storeu2_m128d
void _mm256_storeu2_m128d(double * hiaddr, double * loaddr, __m256d _a);
#endif
#ifdef _mm_broadcastsd_pd
#undef _mm_broadcastsd_pd
__m128d _mm_broadcastsd_pd(__m128d _a);
#endif
#ifdef _mm256_broadcastsd_pd
#undef _mm256_broadcastsd_pd
__m256d _mm256_broadcastsd_pd(__m128d _a);
#endif
#ifdef _mm_broadcastss_ps
#undef _mm_broadcastss_ps
__m128 _mm_broadcastss_ps(__m128 _a);
#endif
#ifdef _mm256_broadcastss_ps
#undef _mm256_broadcastss_ps
__m256 _mm256_broadcastss_ps(__m128 _a);
#endif
#ifdef _mm_i32gather_pd
#undef _mm_i32gather_pd
__m128d _mm_i32gather_pd(double const * base_addr, __m128i _vindex, int scale);
#endif
#ifdef _mm256_i32gather_pd
#undef _mm256_i32gather_pd
__m256d _mm256_i32gather_pd(double const * base_addr, __m128i _vindex, int scale);
#endif
#ifdef _mm_i32gather_ps
#undef _mm_i32gather_ps
__m128 _mm_i32gather_ps(float const * base_addr, __m128i _vindex, int scale);
#endif
#ifdef _mm256_i32gather_ps
#undef _mm256_i32gather_ps
__m256 _mm256_i32gather_ps(float const * base_addr, __m256i _vindex, int scale);
#endif
#ifdef _mm_i64gather_pd
#undef _mm_i64gather_pd
__m128d _mm_i64gather_pd(double const * base_addr, __m128i _vindex, int scale);
#endif
#ifdef _mm256_i64gather_pd
#undef _mm256_i64gather_pd
__m256d _mm256_i64gather_pd(double const * base_addr, __m256i _vindex, int scale);
#endif
#ifdef _mm_i64gather_ps
#undef _mm_i64gather_ps
__m128 _mm_i64gather_ps(float const * base_addr, __m128i _vindex, int scale);
#endif
#ifdef _mm256_i64gather_ps
#undef _mm256_i64gather_ps
__m128 _mm256_i64gather_ps(float const * base_addr, __m256i _vindex, int scale);
#endif
#ifdef _mm_mask_i32gather_pd
#undef _mm_mask_i32gather_pd
__m128d _mm_mask_i32gather_pd(__m128d _src, double const * base_addr, __m128i _vindex, __m128d _mask, int scale);
#endif
#ifdef _mm256_mask_i32gather_pd
#undef _mm256_mask_i32gather_pd
__m256d _mm256_mask_i32gather_pd(__m256d _src, double const * base_addr, __m128i _vindex, __m256d _mask, int scale);
#endif
#ifdef _mm_mask_i32gather_ps
#undef _mm_mask_i32gather_ps
__m128 _mm_mask_i32gather_ps(__m128 _src, float const * base_addr, __m128i _vindex, __m128 _mask, int scale);
#endif
#ifdef _mm256_mask_i32gather_ps
#undef _mm256_mask_i32gather_ps
__m256 _mm256_mask_i32gather_ps(__m256 _src, float const * base_addr, __m256i _vindex, __m256 _mask, int scale);
#endif
#ifdef _mm_mask_i64gather_pd
#undef _mm_mask_i64gather_pd
__m128d _mm_mask_i64gather_pd(__m128d _src, double const * base_addr, __m128i _vindex, __m128d _mask, int scale);
#endif
#ifdef _mm256_mask_i64gather_pd
#undef _mm256_mask_i64gather_pd
__m256d _mm256_mask_i64gather_pd(__m256d _src, double const * base_addr, __m256i _vindex, __m256d _mask, int scale);
#endif
#ifdef _mm_mask_i64gather_ps
#undef _mm_mask_i64gather_ps
__m128 _mm_mask_i64gather_ps(__m128 _src, float const * base_addr, __m128i _vindex, __m128 _mask, int scale);
#endif
#ifdef _mm256_mask_i64gather_ps
#undef _mm256_mask_i64gather_ps
__m128 _mm256_mask_i64gather_ps(__m128 _src, float const * base_addr, __m256i _vindex, __m128 _mask, int scale);
#endif
#ifdef _mm256_permute4x64_pd
#undef _mm256_permute4x64_pd
__m256d _mm256_permute4x64_pd(__m256d _a, int imm8);
#endif
#ifdef _mm256_permutevar8x32_ps
#undef _mm256_permutevar8x32_ps
__m256 _mm256_permutevar8x32_ps(__m256 _a, __m256i _idx);
#endif
#ifdef _mm_fmadd_pd
#undef _mm_fmadd_pd
__m128d _mm_fmadd_pd(__m128d _a, __m128d _b, __m128d _c);
#endif
#ifdef _mm256_fmadd_pd
#undef _mm256_fmadd_pd
__m256d _mm256_fmadd_pd(__m256d _a, __m256d _b, __m256d _c);
#endif
#ifdef _mm_fmadd_ps
#undef _mm_fmadd_ps
__m128 _mm_fmadd_ps(__m128 _a, __m128 _b, __m128 _c);
#endif
#ifdef _mm256_fmadd_ps
#undef _mm256_fmadd_ps
__m256 _mm256_fmadd_ps(__m256 _a, __m256 _b, __m256 _c);
#endif
#ifdef _mm_fmadd_sd
#undef _mm_fmadd_sd
__m128d _mm_fmadd_sd(__m128d _a, __m128d _b, __m128d _c);
#endif
#ifdef _mm_fmadd_ss
#undef _mm_fmadd_ss
__m128 _mm_fmadd_ss(__m128 _a, __m128 _b, __m128 _c);
#endif
#ifdef _mm_fmaddsub_pd
#undef _mm_fmaddsub_pd
__m128d _mm_fmaddsub_pd(__m128d _a, __m128d _b, __m128d _c);
#endif
#ifdef _mm256_fmaddsub_pd
#undef _mm256_fmaddsub_pd
__m256d _mm256_fmaddsub_pd(__m256d _a, __m256d _b, __m256d _c);
#endif
#ifdef _mm_fmaddsub_ps
#undef _mm_fmaddsub_ps
__m128 _mm_fmaddsub_ps(__m128 _a, __m128 _b, __m128 _c);
#endif
#ifdef _mm256_fmaddsub_ps
#undef _mm256_fmaddsub_ps
__m256 _mm256_fmaddsub_ps(__m256 _a, __m256 _b, __m256 _c);
#endif
#ifdef _mm_fmsub_pd
#undef _mm_fmsub_pd
__m128d _mm_fmsub_pd(__m128d _a, __m128d _b, __m128d _c);
#endif
#ifdef _mm256_fmsub_pd
#undef _mm256_fmsub_pd
__m256d _mm256_fmsub_pd(__m256d _a, __m256d _b, __m256d _c);
#endif
#ifdef _mm_fmsub_ps
#undef _mm_fmsub_ps
__m128 _mm_fmsub_ps(__m128 _a, __m128 _b, __m128 _c);
#endif
#ifdef _mm256_fmsub_ps
#undef _mm256_fmsub_ps
__m256 _mm256_fmsub_ps(__m256 _a, __m256 _b, __m256 _c);
#endif
#ifdef _mm_fmsub_sd
#undef _mm_fmsub_sd
__m128d _mm_fmsub_sd(__m128d _a, __m128d _b, __m128d _c);
#endif
#ifdef _mm_fmsub_ss
#undef _mm_fmsub_ss
__m128 _mm_fmsub_ss(__m128 _a, __m128 _b, __m128 _c);
#endif
#ifdef _mm_fmsubadd_pd
#undef _mm_fmsubadd_pd
__m128d _mm_fmsubadd_pd(__m128d _a, __m128d _b, __m128d _c);
#endif
#ifdef _mm256_fmsubadd_pd
#undef _mm256_fmsubadd_pd
__m256d _mm256_fmsubadd_pd(__m256d _a, __m256d _b, __m256d _c);
#endif
#ifdef _mm_fmsubadd_ps
#undef _mm_fmsubadd_ps
__m128 _mm_fmsubadd_ps(__m128 _a, __m128 _b, __m128 _c);
#endif
#ifdef _mm256_fmsubadd_ps
#undef _mm256_fmsubadd_ps
__m256 _mm256_fmsubadd_ps(__m256 _a, __m256 _b, __m256 _c);
#endif
#ifdef _mm_fnmadd_pd
#undef _mm_fnmadd_pd
__m128d _mm_fnmadd_pd(__m128d _a, __m128d _b, __m128d _c);
#endif
#ifdef _mm256_fnmadd_pd
#undef _mm256_fnmadd_pd
__m256d _mm256_fnmadd_pd(__m256d _a, __m256d _b, __m256d _c);
#endif
#ifdef _mm_fnmadd_ps
#undef _mm_fnmadd_ps
__m128 _mm_fnmadd_ps(__m128 _a, __m128 _b, __m128 _c);
#endif
#ifdef _mm256_fnmadd_ps
#undef _mm256_fnmadd_ps
__m256 _mm256_fnmadd_ps(__m256 _a, __m256 _b, __m256 _c);
#endif
#ifdef _mm_fnmadd_sd
#undef _mm_fnmadd_sd
__m128d _mm_fnmadd_sd(__m128d _a, __m128d _b, __m128d _c);
#endif
#ifdef _mm_fnmadd_ss
#undef _mm_fnmadd_ss
__m128 _mm_fnmadd_ss(__m128 _a, __m128 _b, __m128 _c);
#endif
#ifdef _mm_fnmsub_pd
#undef _mm_fnmsub_pd
__m128d _mm_fnmsub_pd(__m128d _a, __m128d _b, __m128d _c);
#endif
#ifdef _mm256_fnmsub_pd
#undef _mm256_fnmsub_pd
__m256d _mm256_fnmsub_pd(__m256d _a, __m256d _b, __m256d _c);
#endif
#ifdef _mm_fnmsub_ps
#undef _mm_fnmsub_ps
__m128 _mm_fnmsub_ps(__m128 _a, __m128 _b, __m128 _c);
#endif
#ifdef _mm256_fnmsub_ps
#undef _mm256_fnmsub_ps
__m256 _mm256_fnmsub_ps(__m256 _a, __m256 _b, __m256 _c);
#endif
#ifdef _mm_fnmsub_sd
#undef _mm_fnmsub_sd
__m128d _mm_fnmsub_sd(__m128d _a, __m128d _b, __m128d _c);
#endif
#ifdef _mm_fnmsub_ss
#undef _mm_fnmsub_ss
__m128 _mm_fnmsub_ss(__m128 _a, __m128 _b, __m128 _c);
#endif
#ifdef _castf32_u32
#undef _castf32_u32
unsigned int _castf32_u32(float a);
#endif
#ifdef _castf64_u64
#undef _castf64_u64
long _castf64_u64(double a);
#endif
#ifdef _castu32_f32
#undef _castu32_f32
float _castu32_f32(unsigned int a);
#endif
#ifdef _castu64_f64
#undef _castu64_f64
double _castu64_f64(long a);
#endif
#ifdef _mm_acos_pd
#undef _mm_acos_pd
__m128d _mm_acos_pd(__m128d _a);
#endif
#ifdef _mm_acos_ps
#undef _mm_acos_ps
__m128 _mm_acos_ps(__m128 _a);
#endif
#ifdef _mm_acosh_pd
#undef _mm_acosh_pd
__m128d _mm_acosh_pd(__m128d _a);
#endif
#ifdef _mm_acosh_ps
#undef _mm_acosh_ps
__m128 _mm_acosh_ps(__m128 _a);
#endif
#ifdef _mm_asin_pd
#undef _mm_asin_pd
__m128d _mm_asin_pd(__m128d _a);
#endif
#ifdef _mm_asin_ps
#undef _mm_asin_ps
__m128 _mm_asin_ps(__m128 _a);
#endif
#ifdef _mm_asinh_pd
#undef _mm_asinh_pd
__m128d _mm_asinh_pd(__m128d _a);
#endif
#ifdef _mm_asinh_ps
#undef _mm_asinh_ps
__m128 _mm_asinh_ps(__m128 _a);
#endif
#ifdef _mm_atan_pd
#undef _mm_atan_pd
__m128d _mm_atan_pd(__m128d _a);
#endif
#ifdef _mm_atan_ps
#undef _mm_atan_ps
__m128 _mm_atan_ps(__m128 _a);
#endif
#ifdef _mm_atan2_pd
#undef _mm_atan2_pd
__m128d _mm_atan2_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_atan2_ps
#undef _mm_atan2_ps
__m128 _mm_atan2_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_atanh_pd
#undef _mm_atanh_pd
__m128d _mm_atanh_pd(__m128d _a);
#endif
#ifdef _mm_atanh_ps
#undef _mm_atanh_ps
__m128 _mm_atanh_ps(__m128 _a);
#endif
#ifdef _mm_cbrt_pd
#undef _mm_cbrt_pd
__m128d _mm_cbrt_pd(__m128d _a);
#endif
#ifdef _mm_cbrt_ps
#undef _mm_cbrt_ps
__m128 _mm_cbrt_ps(__m128 _a);
#endif
#ifdef _mm_cdfnorm_pd
#undef _mm_cdfnorm_pd
__m128d _mm_cdfnorm_pd(__m128d _a);
#endif
#ifdef _mm_cdfnorm_ps
#undef _mm_cdfnorm_ps
__m128 _mm_cdfnorm_ps(__m128 _a);
#endif
#ifdef _mm_cdfnorminv_pd
#undef _mm_cdfnorminv_pd
__m128d _mm_cdfnorminv_pd(__m128d _a);
#endif
#ifdef _mm_cdfnorminv_ps
#undef _mm_cdfnorminv_ps
__m128 _mm_cdfnorminv_ps(__m128 _a);
#endif
#ifdef _mm_cexp_ps
#undef _mm_cexp_ps
__m128 _mm_cexp_ps(__m128 _a);
#endif
#ifdef _mm_clog_ps
#undef _mm_clog_ps
__m128 _mm_clog_ps(__m128 _a);
#endif
#ifdef _mm_cos_pd
#undef _mm_cos_pd
__m128d _mm_cos_pd(__m128d _a);
#endif
#ifdef _mm_cos_ps
#undef _mm_cos_ps
__m128 _mm_cos_ps(__m128 _a);
#endif
#ifdef _mm_cosd_pd
#undef _mm_cosd_pd
__m128d _mm_cosd_pd(__m128d _a);
#endif
#ifdef _mm_cosd_ps
#undef _mm_cosd_ps
__m128 _mm_cosd_ps(__m128 _a);
#endif
#ifdef _mm_cosh_pd
#undef _mm_cosh_pd
__m128d _mm_cosh_pd(__m128d _a);
#endif
#ifdef _mm_cosh_ps
#undef _mm_cosh_ps
__m128 _mm_cosh_ps(__m128 _a);
#endif
#ifdef _mm_csqrt_ps
#undef _mm_csqrt_ps
__m128 _mm_csqrt_ps(__m128 _a);
#endif
#ifdef _mm_erf_pd
#undef _mm_erf_pd
__m128d _mm_erf_pd(__m128d _a);
#endif
#ifdef _mm_erf_ps
#undef _mm_erf_ps
__m128 _mm_erf_ps(__m128 _a);
#endif
#ifdef _mm_erfc_pd
#undef _mm_erfc_pd
__m128d _mm_erfc_pd(__m128d _a);
#endif
#ifdef _mm_erfc_ps
#undef _mm_erfc_ps
__m128 _mm_erfc_ps(__m128 _a);
#endif
#ifdef _mm_erfcinv_pd
#undef _mm_erfcinv_pd
__m128d _mm_erfcinv_pd(__m128d _a);
#endif
#ifdef _mm_erfcinv_ps
#undef _mm_erfcinv_ps
__m128 _mm_erfcinv_ps(__m128 _a);
#endif
#ifdef _mm_erfinv_pd
#undef _mm_erfinv_pd
__m128d _mm_erfinv_pd(__m128d _a);
#endif
#ifdef _mm_erfinv_ps
#undef _mm_erfinv_ps
__m128 _mm_erfinv_ps(__m128 _a);
#endif
#ifdef _mm_exp_pd
#undef _mm_exp_pd
__m128d _mm_exp_pd(__m128d _a);
#endif
#ifdef _mm_exp_ps
#undef _mm_exp_ps
__m128 _mm_exp_ps(__m128 _a);
#endif
#ifdef _mm_exp10_pd
#undef _mm_exp10_pd
__m128d _mm_exp10_pd(__m128d _a);
#endif
#ifdef _mm_exp10_ps
#undef _mm_exp10_ps
__m128 _mm_exp10_ps(__m128 _a);
#endif
#ifdef _mm_exp2_pd
#undef _mm_exp2_pd
__m128d _mm_exp2_pd(__m128d _a);
#endif
#ifdef _mm_exp2_ps
#undef _mm_exp2_ps
__m128 _mm_exp2_ps(__m128 _a);
#endif
#ifdef _mm_expm1_pd
#undef _mm_expm1_pd
__m128d _mm_expm1_pd(__m128d _a);
#endif
#ifdef _mm_expm1_ps
#undef _mm_expm1_ps
__m128 _mm_expm1_ps(__m128 _a);
#endif
#ifdef _mm_hypot_pd
#undef _mm_hypot_pd
__m128d _mm_hypot_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_hypot_ps
#undef _mm_hypot_ps
__m128 _mm_hypot_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_invcbrt_pd
#undef _mm_invcbrt_pd
__m128d _mm_invcbrt_pd(__m128d _a);
#endif
#ifdef _mm_invcbrt_ps
#undef _mm_invcbrt_ps
__m128 _mm_invcbrt_ps(__m128 _a);
#endif
#ifdef _mm_invsqrt_pd
#undef _mm_invsqrt_pd
__m128d _mm_invsqrt_pd(__m128d _a);
#endif
#ifdef _mm_invsqrt_ps
#undef _mm_invsqrt_ps
__m128 _mm_invsqrt_ps(__m128 _a);
#endif
#ifdef _mm_log_pd
#undef _mm_log_pd
__m128d _mm_log_pd(__m128d _a);
#endif
#ifdef _mm_log_ps
#undef _mm_log_ps
__m128 _mm_log_ps(__m128 _a);
#endif
#ifdef _mm_log10_pd
#undef _mm_log10_pd
__m128d _mm_log10_pd(__m128d _a);
#endif
#ifdef _mm_log10_ps
#undef _mm_log10_ps
__m128 _mm_log10_ps(__m128 _a);
#endif
#ifdef _mm_log1p_pd
#undef _mm_log1p_pd
__m128d _mm_log1p_pd(__m128d _a);
#endif
#ifdef _mm_log1p_ps
#undef _mm_log1p_ps
__m128 _mm_log1p_ps(__m128 _a);
#endif
#ifdef _mm_log2_pd
#undef _mm_log2_pd
__m128d _mm_log2_pd(__m128d _a);
#endif
#ifdef _mm_log2_ps
#undef _mm_log2_ps
__m128 _mm_log2_ps(__m128 _a);
#endif
#ifdef _mm_logb_pd
#undef _mm_logb_pd
__m128d _mm_logb_pd(__m128d _a);
#endif
#ifdef _mm_logb_ps
#undef _mm_logb_ps
__m128 _mm_logb_ps(__m128 _a);
#endif
#ifdef _mm_pow_pd
#undef _mm_pow_pd
__m128d _mm_pow_pd(__m128d _a, __m128d _b);
#endif
#ifdef _mm_pow_ps
#undef _mm_pow_ps
__m128 _mm_pow_ps(__m128 _a, __m128 _b);
#endif
#ifdef _mm_sin_pd
#undef _mm_sin_pd
__m128d _mm_sin_pd(__m128d _a);
#endif
#ifdef _mm_sin_ps
#undef _mm_sin_ps
__m128 _mm_sin_ps(__m128 _a);
#endif
#ifdef _mm_sincos_pd
#undef _mm_sincos_pd
__m128d _mm_sincos_pd(__m128d * _mem_addr, __m128d _a);
#endif
#ifdef _mm_sincos_ps
#undef _mm_sincos_ps
__m128 _mm_sincos_ps(__m128 * _mem_addr, __m128 _a);
#endif
#ifdef _mm_sind_pd
#undef _mm_sind_pd
__m128d _mm_sind_pd(__m128d _a);
#endif
#ifdef _mm_sind_ps
#undef _mm_sind_ps
__m128 _mm_sind_ps(__m128 _a);
#endif
#ifdef _mm_sinh_pd
#undef _mm_sinh_pd
__m128d _mm_sinh_pd(__m128d _a);
#endif
#ifdef _mm_sinh_ps
#undef _mm_sinh_ps
__m128 _mm_sinh_ps(__m128 _a);
#endif
#ifdef _mm_svml_ceil_pd
#undef _mm_svml_ceil_pd
__m128d _mm_svml_ceil_pd(__m128d _a);
#endif
#ifdef _mm_svml_ceil_ps
#undef _mm_svml_ceil_ps
__m128 _mm_svml_ceil_ps(__m128 _a);
#endif
#ifdef _mm_svml_floor_pd
#undef _mm_svml_floor_pd
__m128d _mm_svml_floor_pd(__m128d _a);
#endif
#ifdef _mm_svml_floor_ps
#undef _mm_svml_floor_ps
__m128 _mm_svml_floor_ps(__m128 _a);
#endif
#ifdef _mm_svml_round_pd
#undef _mm_svml_round_pd
__m128d _mm_svml_round_pd(__m128d _a);
#endif
#ifdef _mm_svml_round_ps
#undef _mm_svml_round_ps
__m128 _mm_svml_round_ps(__m128 _a);
#endif
#ifdef _mm_svml_sqrt_pd
#undef _mm_svml_sqrt_pd
__m128d _mm_svml_sqrt_pd(__m128d _a);
#endif
#ifdef _mm_svml_sqrt_ps
#undef _mm_svml_sqrt_ps
__m128 _mm_svml_sqrt_ps(__m128 _a);
#endif
#ifdef _mm_tan_pd
#undef _mm_tan_pd
__m128d _mm_tan_pd(__m128d _a);
#endif
#ifdef _mm_tan_ps
#undef _mm_tan_ps
__m128 _mm_tan_ps(__m128 _a);
#endif
#ifdef _mm_tand_pd
#undef _mm_tand_pd
__m128d _mm_tand_pd(__m128d _a);
#endif
#ifdef _mm_tand_ps
#undef _mm_tand_ps
__m128 _mm_tand_ps(__m128 _a);
#endif
#ifdef _mm_tanh_pd
#undef _mm_tanh_pd
__m128d _mm_tanh_pd(__m128d _a);
#endif
#ifdef _mm_tanh_ps
#undef _mm_tanh_ps
__m128 _mm_tanh_ps(__m128 _a);
#endif
#ifdef _mm_trunc_pd
#undef _mm_trunc_pd
__m128d _mm_trunc_pd(__m128d _a);
#endif
#ifdef _mm_trunc_ps
#undef _mm_trunc_ps
__m128 _mm_trunc_ps(__m128 _a);
#endif
#ifdef _mm256_acos_pd
#undef _mm256_acos_pd
__m256d _mm256_acos_pd(__m256d _a);
#endif
#ifdef _mm256_acos_ps
#undef _mm256_acos_ps
__m256 _mm256_acos_ps(__m256 _a);
#endif
#ifdef _mm256_acosh_pd
#undef _mm256_acosh_pd
__m256d _mm256_acosh_pd(__m256d _a);
#endif
#ifdef _mm256_acosh_ps
#undef _mm256_acosh_ps
__m256 _mm256_acosh_ps(__m256 _a);
#endif
#ifdef _mm256_asin_pd
#undef _mm256_asin_pd
__m256d _mm256_asin_pd(__m256d _a);
#endif
#ifdef _mm256_asin_ps
#undef _mm256_asin_ps
__m256 _mm256_asin_ps(__m256 _a);
#endif
#ifdef _mm256_asinh_pd
#undef _mm256_asinh_pd
__m256d _mm256_asinh_pd(__m256d _a);
#endif
#ifdef _mm256_asinh_ps
#undef _mm256_asinh_ps
__m256 _mm256_asinh_ps(__m256 _a);
#endif
#ifdef _mm256_atan_pd
#undef _mm256_atan_pd
__m256d _mm256_atan_pd(__m256d _a);
#endif
#ifdef _mm256_atan_ps
#undef _mm256_atan_ps
__m256 _mm256_atan_ps(__m256 _a);
#endif
#ifdef _mm256_atan2_pd
#undef _mm256_atan2_pd
__m256d _mm256_atan2_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_atan2_ps
#undef _mm256_atan2_ps
__m256 _mm256_atan2_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_atanh_pd
#undef _mm256_atanh_pd
__m256d _mm256_atanh_pd(__m256d _a);
#endif
#ifdef _mm256_atanh_ps
#undef _mm256_atanh_ps
__m256 _mm256_atanh_ps(__m256 _a);
#endif
#ifdef _mm256_cbrt_pd
#undef _mm256_cbrt_pd
__m256d _mm256_cbrt_pd(__m256d _a);
#endif
#ifdef _mm256_cbrt_ps
#undef _mm256_cbrt_ps
__m256 _mm256_cbrt_ps(__m256 _a);
#endif
#ifdef _mm256_cdfnorm_pd
#undef _mm256_cdfnorm_pd
__m256d _mm256_cdfnorm_pd(__m256d _a);
#endif
#ifdef _mm256_cdfnorm_ps
#undef _mm256_cdfnorm_ps
__m256 _mm256_cdfnorm_ps(__m256 _a);
#endif
#ifdef _mm256_cdfnorminv_pd
#undef _mm256_cdfnorminv_pd
__m256d _mm256_cdfnorminv_pd(__m256d _a);
#endif
#ifdef _mm256_cdfnorminv_ps
#undef _mm256_cdfnorminv_ps
__m256 _mm256_cdfnorminv_ps(__m256 _a);
#endif
#ifdef _mm256_cexp_ps
#undef _mm256_cexp_ps
__m256 _mm256_cexp_ps(__m256 _a);
#endif
#ifdef _mm256_clog_ps
#undef _mm256_clog_ps
__m256 _mm256_clog_ps(__m256 _a);
#endif
#ifdef _mm256_cos_pd
#undef _mm256_cos_pd
__m256d _mm256_cos_pd(__m256d _a);
#endif
#ifdef _mm256_cos_ps
#undef _mm256_cos_ps
__m256 _mm256_cos_ps(__m256 _a);
#endif
#ifdef _mm256_cosd_pd
#undef _mm256_cosd_pd
__m256d _mm256_cosd_pd(__m256d _a);
#endif
#ifdef _mm256_cosd_ps
#undef _mm256_cosd_ps
__m256 _mm256_cosd_ps(__m256 _a);
#endif
#ifdef _mm256_cosh_pd
#undef _mm256_cosh_pd
__m256d _mm256_cosh_pd(__m256d _a);
#endif
#ifdef _mm256_cosh_ps
#undef _mm256_cosh_ps
__m256 _mm256_cosh_ps(__m256 _a);
#endif
#ifdef _mm256_csqrt_ps
#undef _mm256_csqrt_ps
__m256 _mm256_csqrt_ps(__m256 _a);
#endif
#ifdef _mm256_erf_pd
#undef _mm256_erf_pd
__m256d _mm256_erf_pd(__m256d _a);
#endif
#ifdef _mm256_erf_ps
#undef _mm256_erf_ps
__m256 _mm256_erf_ps(__m256 _a);
#endif
#ifdef _mm256_erfc_pd
#undef _mm256_erfc_pd
__m256d _mm256_erfc_pd(__m256d _a);
#endif
#ifdef _mm256_erfc_ps
#undef _mm256_erfc_ps
__m256 _mm256_erfc_ps(__m256 _a);
#endif
#ifdef _mm256_erfcinv_pd
#undef _mm256_erfcinv_pd
__m256d _mm256_erfcinv_pd(__m256d _a);
#endif
#ifdef _mm256_erfcinv_ps
#undef _mm256_erfcinv_ps
__m256 _mm256_erfcinv_ps(__m256 _a);
#endif
#ifdef _mm256_erfinv_pd
#undef _mm256_erfinv_pd
__m256d _mm256_erfinv_pd(__m256d _a);
#endif
#ifdef _mm256_erfinv_ps
#undef _mm256_erfinv_ps
__m256 _mm256_erfinv_ps(__m256 _a);
#endif
#ifdef _mm256_exp_pd
#undef _mm256_exp_pd
__m256d _mm256_exp_pd(__m256d _a);
#endif
#ifdef _mm256_exp_ps
#undef _mm256_exp_ps
__m256 _mm256_exp_ps(__m256 _a);
#endif
#ifdef _mm256_exp10_pd
#undef _mm256_exp10_pd
__m256d _mm256_exp10_pd(__m256d _a);
#endif
#ifdef _mm256_exp10_ps
#undef _mm256_exp10_ps
__m256 _mm256_exp10_ps(__m256 _a);
#endif
#ifdef _mm256_exp2_pd
#undef _mm256_exp2_pd
__m256d _mm256_exp2_pd(__m256d _a);
#endif
#ifdef _mm256_exp2_ps
#undef _mm256_exp2_ps
__m256 _mm256_exp2_ps(__m256 _a);
#endif
#ifdef _mm256_expm1_pd
#undef _mm256_expm1_pd
__m256d _mm256_expm1_pd(__m256d _a);
#endif
#ifdef _mm256_expm1_ps
#undef _mm256_expm1_ps
__m256 _mm256_expm1_ps(__m256 _a);
#endif
#ifdef _mm256_hypot_pd
#undef _mm256_hypot_pd
__m256d _mm256_hypot_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_hypot_ps
#undef _mm256_hypot_ps
__m256 _mm256_hypot_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_invcbrt_pd
#undef _mm256_invcbrt_pd
__m256d _mm256_invcbrt_pd(__m256d _a);
#endif
#ifdef _mm256_invcbrt_ps
#undef _mm256_invcbrt_ps
__m256 _mm256_invcbrt_ps(__m256 _a);
#endif
#ifdef _mm256_invsqrt_pd
#undef _mm256_invsqrt_pd
__m256d _mm256_invsqrt_pd(__m256d _a);
#endif
#ifdef _mm256_invsqrt_ps
#undef _mm256_invsqrt_ps
__m256 _mm256_invsqrt_ps(__m256 _a);
#endif
#ifdef _mm256_log_pd
#undef _mm256_log_pd
__m256d _mm256_log_pd(__m256d _a);
#endif
#ifdef _mm256_log_ps
#undef _mm256_log_ps
__m256 _mm256_log_ps(__m256 _a);
#endif
#ifdef _mm256_log10_pd
#undef _mm256_log10_pd
__m256d _mm256_log10_pd(__m256d _a);
#endif
#ifdef _mm256_log10_ps
#undef _mm256_log10_ps
__m256 _mm256_log10_ps(__m256 _a);
#endif
#ifdef _mm256_log1p_pd
#undef _mm256_log1p_pd
__m256d _mm256_log1p_pd(__m256d _a);
#endif
#ifdef _mm256_log1p_ps
#undef _mm256_log1p_ps
__m256 _mm256_log1p_ps(__m256 _a);
#endif
#ifdef _mm256_log2_pd
#undef _mm256_log2_pd
__m256d _mm256_log2_pd(__m256d _a);
#endif
#ifdef _mm256_log2_ps
#undef _mm256_log2_ps
__m256 _mm256_log2_ps(__m256 _a);
#endif
#ifdef _mm256_logb_pd
#undef _mm256_logb_pd
__m256d _mm256_logb_pd(__m256d _a);
#endif
#ifdef _mm256_logb_ps
#undef _mm256_logb_ps
__m256 _mm256_logb_ps(__m256 _a);
#endif
#ifdef _mm256_pow_pd
#undef _mm256_pow_pd
__m256d _mm256_pow_pd(__m256d _a, __m256d _b);
#endif
#ifdef _mm256_pow_ps
#undef _mm256_pow_ps
__m256 _mm256_pow_ps(__m256 _a, __m256 _b);
#endif
#ifdef _mm256_sin_pd
#undef _mm256_sin_pd
__m256d _mm256_sin_pd(__m256d _a);
#endif
#ifdef _mm256_sin_ps
#undef _mm256_sin_ps
__m256 _mm256_sin_ps(__m256 _a);
#endif
#ifdef _mm256_sincos_pd
#undef _mm256_sincos_pd
__m256d _mm256_sincos_pd(__m256d * _mem_addr, __m256d _a);
#endif
#ifdef _mm256_sincos_ps
#undef _mm256_sincos_ps
__m256 _mm256_sincos_ps(__m256 * _mem_addr, __m256 _a);
#endif
#ifdef _mm256_sind_pd
#undef _mm256_sind_pd
__m256d _mm256_sind_pd(__m256d _a);
#endif
#ifdef _mm256_sind_ps
#undef _mm256_sind_ps
__m256 _mm256_sind_ps(__m256 _a);
#endif
#ifdef _mm256_sinh_pd
#undef _mm256_sinh_pd
__m256d _mm256_sinh_pd(__m256d _a);
#endif
#ifdef _mm256_sinh_ps
#undef _mm256_sinh_ps
__m256 _mm256_sinh_ps(__m256 _a);
#endif
#ifdef _mm256_svml_ceil_pd
#undef _mm256_svml_ceil_pd
__m256d _mm256_svml_ceil_pd(__m256d _a);
#endif
#ifdef _mm256_svml_ceil_ps
#undef _mm256_svml_ceil_ps
__m256 _mm256_svml_ceil_ps(__m256 _a);
#endif
#ifdef _mm256_svml_floor_pd
#undef _mm256_svml_floor_pd
__m256d _mm256_svml_floor_pd(__m256d _a);
#endif
#ifdef _mm256_svml_floor_ps
#undef _mm256_svml_floor_ps
__m256 _mm256_svml_floor_ps(__m256 _a);
#endif
#ifdef _mm256_svml_round_pd
#undef _mm256_svml_round_pd
__m256d _mm256_svml_round_pd(__m256d _a);
#endif
#ifdef _mm256_svml_round_ps
#undef _mm256_svml_round_ps
__m256 _mm256_svml_round_ps(__m256 _a);
#endif
#ifdef _mm256_svml_sqrt_pd
#undef _mm256_svml_sqrt_pd
__m256d _mm256_svml_sqrt_pd(__m256d _a);
#endif
#ifdef _mm256_svml_sqrt_ps
#undef _mm256_svml_sqrt_ps
__m256 _mm256_svml_sqrt_ps(__m256 _a);
#endif
#ifdef _mm256_tan_pd
#undef _mm256_tan_pd
__m256d _mm256_tan_pd(__m256d _a);
#endif
#ifdef _mm256_tan_ps
#undef _mm256_tan_ps
__m256 _mm256_tan_ps(__m256 _a);
#endif
#ifdef _mm256_tand_pd
#undef _mm256_tand_pd
__m256d _mm256_tand_pd(__m256d _a);
#endif
#ifdef _mm256_tand_ps
#undef _mm256_tand_ps
__m256 _mm256_tand_ps(__m256 _a);
#endif
#ifdef _mm256_tanh_pd
#undef _mm256_tanh_pd
__m256d _mm256_tanh_pd(__m256d _a);
#endif
#ifdef _mm256_tanh_ps
#undef _mm256_tanh_ps
__m256 _mm256_tanh_ps(__m256 _a);
#endif
#ifdef _mm256_trunc_pd
#undef _mm256_trunc_pd
__m256d _mm256_trunc_pd(__m256d _a);
#endif
#ifdef _mm256_trunc_ps
#undef _mm256_trunc_ps
__m256 _mm256_trunc_ps(__m256 _a);
#endif
#ifdef _mm256_cvtph_ps
#undef _mm256_cvtph_ps
__m256 _mm256_cvtph_ps(__m128i _a);
#endif
#ifdef _mm256_cvtps_ph
#undef _mm256_cvtps_ph
__m128i _mm256_cvtps_ph(__m256 _a, int rounding);
#endif
#ifdef _mm256_cvtss_f32
#undef _mm256_cvtss_f32
float _mm256_cvtss_f32(__m256 _a);
#endif
#ifdef _mm256_cvtsd_f64
#undef _mm256_cvtsd_f64
double _mm256_cvtsd_f64(__m256d _a);
#endif
#ifdef _mm512_acos_pd
#undef _mm512_acos_pd
__m512d _mm512_acos_pd(__m512d _a);
#endif
#ifdef _mm512_mask_acos_pd
#undef _mm512_mask_acos_pd
__m512d _mm512_mask_acos_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_acos_ps
#undef _mm512_acos_ps
__m512 _mm512_acos_ps(__m512 _a);
#endif
#ifdef _mm512_mask_acos_ps
#undef _mm512_mask_acos_ps
__m512 _mm512_mask_acos_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_acosh_pd
#undef _mm512_acosh_pd
__m512d _mm512_acosh_pd(__m512d _a);
#endif
#ifdef _mm512_mask_acosh_pd
#undef _mm512_mask_acosh_pd
__m512d _mm512_mask_acosh_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_acosh_ps
#undef _mm512_acosh_ps
__m512 _mm512_acosh_ps(__m512 _a);
#endif
#ifdef _mm512_mask_acosh_ps
#undef _mm512_mask_acosh_ps
__m512 _mm512_mask_acosh_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_asin_pd
#undef _mm512_asin_pd
__m512d _mm512_asin_pd(__m512d _a);
#endif
#ifdef _mm512_mask_asin_pd
#undef _mm512_mask_asin_pd
__m512d _mm512_mask_asin_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_asin_ps
#undef _mm512_asin_ps
__m512 _mm512_asin_ps(__m512 _a);
#endif
#ifdef _mm512_mask_asin_ps
#undef _mm512_mask_asin_ps
__m512 _mm512_mask_asin_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_asinh_pd
#undef _mm512_asinh_pd
__m512d _mm512_asinh_pd(__m512d _a);
#endif
#ifdef _mm512_mask_asinh_pd
#undef _mm512_mask_asinh_pd
__m512d _mm512_mask_asinh_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_asinh_ps
#undef _mm512_asinh_ps
__m512 _mm512_asinh_ps(__m512 _a);
#endif
#ifdef _mm512_mask_asinh_ps
#undef _mm512_mask_asinh_ps
__m512 _mm512_mask_asinh_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_atan2_pd
#undef _mm512_atan2_pd
__m512d _mm512_atan2_pd(__m512d _a, __m512d _b);
#endif
#ifdef _mm512_mask_atan2_pd
#undef _mm512_mask_atan2_pd
__m512d _mm512_mask_atan2_pd(__m512d _src, __mmask8 k, __m512d _a, __m512d _b);
#endif
#ifdef _mm512_atan2_ps
#undef _mm512_atan2_ps
__m512 _mm512_atan2_ps(__m512 _a, __m512 _b);
#endif
#ifdef _mm512_mask_atan2_ps
#undef _mm512_mask_atan2_ps
__m512 _mm512_mask_atan2_ps(__m512 _src, __mmask16 k, __m512 _a, __m512 _b);
#endif
#ifdef _mm512_atan_pd
#undef _mm512_atan_pd
__m512d _mm512_atan_pd(__m512d _a);
#endif
#ifdef _mm512_mask_atan_pd
#undef _mm512_mask_atan_pd
__m512d _mm512_mask_atan_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_atan_ps
#undef _mm512_atan_ps
__m512 _mm512_atan_ps(__m512 _a);
#endif
#ifdef _mm512_mask_atan_ps
#undef _mm512_mask_atan_ps
__m512 _mm512_mask_atan_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_atanh_pd
#undef _mm512_atanh_pd
__m512d _mm512_atanh_pd(__m512d _a);
#endif
#ifdef _mm512_mask_atanh_pd
#undef _mm512_mask_atanh_pd
__m512d _mm512_mask_atanh_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_atanh_ps
#undef _mm512_atanh_ps
__m512 _mm512_atanh_ps(__m512 _a);
#endif
#ifdef _mm512_mask_atanh_ps
#undef _mm512_mask_atanh_ps
__m512 _mm512_mask_atanh_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_cbrt_pd
#undef _mm512_cbrt_pd
__m512d _mm512_cbrt_pd(__m512d _a);
#endif
#ifdef _mm512_mask_cbrt_pd
#undef _mm512_mask_cbrt_pd
__m512d _mm512_mask_cbrt_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_cbrt_ps
#undef _mm512_cbrt_ps
__m512 _mm512_cbrt_ps(__m512 _a);
#endif
#ifdef _mm512_mask_cbrt_ps
#undef _mm512_mask_cbrt_ps
__m512 _mm512_mask_cbrt_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_cdfnorm_pd
#undef _mm512_cdfnorm_pd
__m512d _mm512_cdfnorm_pd(__m512d _a);
#endif
#ifdef _mm512_mask_cdfnorm_pd
#undef _mm512_mask_cdfnorm_pd
__m512d _mm512_mask_cdfnorm_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_cdfnorm_ps
#undef _mm512_cdfnorm_ps
__m512 _mm512_cdfnorm_ps(__m512 _a);
#endif
#ifdef _mm512_mask_cdfnorm_ps
#undef _mm512_mask_cdfnorm_ps
__m512 _mm512_mask_cdfnorm_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_cdfnorminv_pd
#undef _mm512_cdfnorminv_pd
__m512d _mm512_cdfnorminv_pd(__m512d _a);
#endif
#ifdef _mm512_mask_cdfnorminv_pd
#undef _mm512_mask_cdfnorminv_pd
__m512d _mm512_mask_cdfnorminv_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_cdfnorminv_ps
#undef _mm512_cdfnorminv_ps
__m512 _mm512_cdfnorminv_ps(__m512 _a);
#endif
#ifdef _mm512_mask_cdfnorminv_ps
#undef _mm512_mask_cdfnorminv_ps
__m512 _mm512_mask_cdfnorminv_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_ceil_pd
#undef _mm512_ceil_pd
__m512d _mm512_ceil_pd(__m512d _a);
#endif
#ifdef _mm512_mask_ceil_pd
#undef _mm512_mask_ceil_pd
__m512d _mm512_mask_ceil_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_ceil_ps
#undef _mm512_ceil_ps
__m512 _mm512_ceil_ps(__m512 _a);
#endif
#ifdef _mm512_mask_ceil_ps
#undef _mm512_mask_ceil_ps
__m512 _mm512_mask_ceil_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_cos_pd
#undef _mm512_cos_pd
__m512d _mm512_cos_pd(__m512d _a);
#endif
#ifdef _mm512_mask_cos_pd
#undef _mm512_mask_cos_pd
__m512d _mm512_mask_cos_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_cos_ps
#undef _mm512_cos_ps
__m512 _mm512_cos_ps(__m512 _a);
#endif
#ifdef _mm512_mask_cos_ps
#undef _mm512_mask_cos_ps
__m512 _mm512_mask_cos_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_cosd_pd
#undef _mm512_cosd_pd
__m512d _mm512_cosd_pd(__m512d _a);
#endif
#ifdef _mm512_mask_cosd_pd
#undef _mm512_mask_cosd_pd
__m512d _mm512_mask_cosd_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_cosd_ps
#undef _mm512_cosd_ps
__m512 _mm512_cosd_ps(__m512 _a);
#endif
#ifdef _mm512_mask_cosd_ps
#undef _mm512_mask_cosd_ps
__m512 _mm512_mask_cosd_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_cosh_pd
#undef _mm512_cosh_pd
__m512d _mm512_cosh_pd(__m512d _a);
#endif
#ifdef _mm512_mask_cosh_pd
#undef _mm512_mask_cosh_pd
__m512d _mm512_mask_cosh_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_cosh_ps
#undef _mm512_cosh_ps
__m512 _mm512_cosh_ps(__m512 _a);
#endif
#ifdef _mm512_mask_cosh_ps
#undef _mm512_mask_cosh_ps
__m512 _mm512_mask_cosh_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_erf_pd
#undef _mm512_erf_pd
__m512d _mm512_erf_pd(__m512d _a);
#endif
#ifdef _mm512_mask_erf_pd
#undef _mm512_mask_erf_pd
__m512d _mm512_mask_erf_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_erfc_pd
#undef _mm512_erfc_pd
__m512d _mm512_erfc_pd(__m512d _a);
#endif
#ifdef _mm512_mask_erfc_pd
#undef _mm512_mask_erfc_pd
__m512d _mm512_mask_erfc_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_erf_ps
#undef _mm512_erf_ps
__m512 _mm512_erf_ps(__m512 _a);
#endif
#ifdef _mm512_mask_erf_ps
#undef _mm512_mask_erf_ps
__m512 _mm512_mask_erf_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_erfc_ps
#undef _mm512_erfc_ps
__m512 _mm512_erfc_ps(__m512 _a);
#endif
#ifdef _mm512_mask_erfc_ps
#undef _mm512_mask_erfc_ps
__m512 _mm512_mask_erfc_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_erfinv_pd
#undef _mm512_erfinv_pd
__m512d _mm512_erfinv_pd(__m512d _a);
#endif
#ifdef _mm512_mask_erfinv_pd
#undef _mm512_mask_erfinv_pd
__m512d _mm512_mask_erfinv_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_erfinv_ps
#undef _mm512_erfinv_ps
__m512 _mm512_erfinv_ps(__m512 _a);
#endif
#ifdef _mm512_mask_erfinv_ps
#undef _mm512_mask_erfinv_ps
__m512 _mm512_mask_erfinv_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_erfcinv_pd
#undef _mm512_erfcinv_pd
__m512d _mm512_erfcinv_pd(__m512d _a);
#endif
#ifdef _mm512_mask_erfcinv_pd
#undef _mm512_mask_erfcinv_pd
__m512d _mm512_mask_erfcinv_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_erfcinv_ps
#undef _mm512_erfcinv_ps
__m512 _mm512_erfcinv_ps(__m512 _a);
#endif
#ifdef _mm512_mask_erfcinv_ps
#undef _mm512_mask_erfcinv_ps
__m512 _mm512_mask_erfcinv_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_exp10_pd
#undef _mm512_exp10_pd
__m512d _mm512_exp10_pd(__m512d _a);
#endif
#ifdef _mm512_mask_exp10_pd
#undef _mm512_mask_exp10_pd
__m512d _mm512_mask_exp10_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_exp10_ps
#undef _mm512_exp10_ps
__m512 _mm512_exp10_ps(__m512 _a);
#endif
#ifdef _mm512_mask_exp10_ps
#undef _mm512_mask_exp10_ps
__m512 _mm512_mask_exp10_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_exp2_pd
#undef _mm512_exp2_pd
__m512d _mm512_exp2_pd(__m512d _a);
#endif
#ifdef _mm512_mask_exp2_pd
#undef _mm512_mask_exp2_pd
__m512d _mm512_mask_exp2_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_exp2_ps
#undef _mm512_exp2_ps
__m512 _mm512_exp2_ps(__m512 _a);
#endif
#ifdef _mm512_mask_exp2_ps
#undef _mm512_mask_exp2_ps
__m512 _mm512_mask_exp2_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_exp_pd
#undef _mm512_exp_pd
__m512d _mm512_exp_pd(__m512d _a);
#endif
#ifdef _mm512_mask_exp_pd
#undef _mm512_mask_exp_pd
__m512d _mm512_mask_exp_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_exp_ps
#undef _mm512_exp_ps
__m512 _mm512_exp_ps(__m512 _a);
#endif
#ifdef _mm512_mask_exp_ps
#undef _mm512_mask_exp_ps
__m512 _mm512_mask_exp_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_expm1_pd
#undef _mm512_expm1_pd
__m512d _mm512_expm1_pd(__m512d _a);
#endif
#ifdef _mm512_mask_expm1_pd
#undef _mm512_mask_expm1_pd
__m512d _mm512_mask_expm1_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_expm1_ps
#undef _mm512_expm1_ps
__m512 _mm512_expm1_ps(__m512 _a);
#endif
#ifdef _mm512_mask_expm1_ps
#undef _mm512_mask_expm1_ps
__m512 _mm512_mask_expm1_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_floor_pd
#undef _mm512_floor_pd
__m512d _mm512_floor_pd(__m512d _a);
#endif
#ifdef _mm512_mask_floor_pd
#undef _mm512_mask_floor_pd
__m512d _mm512_mask_floor_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_floor_ps
#undef _mm512_floor_ps
__m512 _mm512_floor_ps(__m512 _a);
#endif
#ifdef _mm512_mask_floor_ps
#undef _mm512_mask_floor_ps
__m512 _mm512_mask_floor_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_hypot_pd
#undef _mm512_hypot_pd
__m512d _mm512_hypot_pd(__m512d _a, __m512d _b);
#endif
#ifdef _mm512_mask_hypot_pd
#undef _mm512_mask_hypot_pd
__m512d _mm512_mask_hypot_pd(__m512d _src, __mmask8 k, __m512d _a, __m512d _b);
#endif
#ifdef _mm512_hypot_ps
#undef _mm512_hypot_ps
__m512 _mm512_hypot_ps(__m512 _a, __m512 _b);
#endif
#ifdef _mm512_mask_hypot_ps
#undef _mm512_mask_hypot_ps
__m512 _mm512_mask_hypot_ps(__m512 _src, __mmask16 k, __m512 _a, __m512 _b);
#endif
#ifdef _mm512_invsqrt_pd
#undef _mm512_invsqrt_pd
__m512d _mm512_invsqrt_pd(__m512d _a);
#endif
#ifdef _mm512_mask_invsqrt_pd
#undef _mm512_mask_invsqrt_pd
__m512d _mm512_mask_invsqrt_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_invsqrt_ps
#undef _mm512_invsqrt_ps
__m512 _mm512_invsqrt_ps(__m512 _a);
#endif
#ifdef _mm512_mask_invsqrt_ps
#undef _mm512_mask_invsqrt_ps
__m512 _mm512_mask_invsqrt_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_log10_pd
#undef _mm512_log10_pd
__m512d _mm512_log10_pd(__m512d _a);
#endif
#ifdef _mm512_mask_log10_pd
#undef _mm512_mask_log10_pd
__m512d _mm512_mask_log10_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_log10_ps
#undef _mm512_log10_ps
__m512 _mm512_log10_ps(__m512 _a);
#endif
#ifdef _mm512_mask_log10_ps
#undef _mm512_mask_log10_ps
__m512 _mm512_mask_log10_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_log1p_pd
#undef _mm512_log1p_pd
__m512d _mm512_log1p_pd(__m512d _a);
#endif
#ifdef _mm512_mask_log1p_pd
#undef _mm512_mask_log1p_pd
__m512d _mm512_mask_log1p_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_log1p_ps
#undef _mm512_log1p_ps
__m512 _mm512_log1p_ps(__m512 _a);
#endif
#ifdef _mm512_mask_log1p_ps
#undef _mm512_mask_log1p_ps
__m512 _mm512_mask_log1p_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_log2_pd
#undef _mm512_log2_pd
__m512d _mm512_log2_pd(__m512d _a);
#endif
#ifdef _mm512_mask_log2_pd
#undef _mm512_mask_log2_pd
__m512d _mm512_mask_log2_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_log_pd
#undef _mm512_log_pd
__m512d _mm512_log_pd(__m512d _a);
#endif
#ifdef _mm512_mask_log_pd
#undef _mm512_mask_log_pd
__m512d _mm512_mask_log_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_log_ps
#undef _mm512_log_ps
__m512 _mm512_log_ps(__m512 _a);
#endif
#ifdef _mm512_mask_log_ps
#undef _mm512_mask_log_ps
__m512 _mm512_mask_log_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_logb_pd
#undef _mm512_logb_pd
__m512d _mm512_logb_pd(__m512d _a);
#endif
#ifdef _mm512_mask_logb_pd
#undef _mm512_mask_logb_pd
__m512d _mm512_mask_logb_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_logb_ps
#undef _mm512_logb_ps
__m512 _mm512_logb_ps(__m512 _a);
#endif
#ifdef _mm512_mask_logb_ps
#undef _mm512_mask_logb_ps
__m512 _mm512_mask_logb_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_nearbyint_pd
#undef _mm512_nearbyint_pd
__m512d _mm512_nearbyint_pd(__m512d _a);
#endif
#ifdef _mm512_mask_nearbyint_pd
#undef _mm512_mask_nearbyint_pd
__m512d _mm512_mask_nearbyint_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_nearbyint_ps
#undef _mm512_nearbyint_ps
__m512 _mm512_nearbyint_ps(__m512 _a);
#endif
#ifdef _mm512_mask_nearbyint_ps
#undef _mm512_mask_nearbyint_ps
__m512 _mm512_mask_nearbyint_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_pow_pd
#undef _mm512_pow_pd
__m512d _mm512_pow_pd(__m512d _a, __m512d _b);
#endif
#ifdef _mm512_mask_pow_pd
#undef _mm512_mask_pow_pd
__m512d _mm512_mask_pow_pd(__m512d _src, __mmask8 k, __m512d _a, __m512d _b);
#endif
#ifdef _mm512_pow_ps
#undef _mm512_pow_ps
__m512 _mm512_pow_ps(__m512 _a, __m512 _b);
#endif
#ifdef _mm512_mask_pow_ps
#undef _mm512_mask_pow_ps
__m512 _mm512_mask_pow_ps(__m512 _src, __mmask16 k, __m512 _a, __m512 _b);
#endif
#ifdef _mm512_recip_pd
#undef _mm512_recip_pd
__m512d _mm512_recip_pd(__m512d _a);
#endif
#ifdef _mm512_mask_recip_pd
#undef _mm512_mask_recip_pd
__m512d _mm512_mask_recip_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_recip_ps
#undef _mm512_recip_ps
__m512 _mm512_recip_ps(__m512 _a);
#endif
#ifdef _mm512_mask_recip_ps
#undef _mm512_mask_recip_ps
__m512 _mm512_mask_recip_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_rint_pd
#undef _mm512_rint_pd
__m512d _mm512_rint_pd(__m512d _a);
#endif
#ifdef _mm512_mask_rint_pd
#undef _mm512_mask_rint_pd
__m512d _mm512_mask_rint_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_rint_ps
#undef _mm512_rint_ps
__m512 _mm512_rint_ps(__m512 _a);
#endif
#ifdef _mm512_mask_rint_ps
#undef _mm512_mask_rint_ps
__m512 _mm512_mask_rint_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_svml_round_pd
#undef _mm512_svml_round_pd
__m512d _mm512_svml_round_pd(__m512d _a);
#endif
#ifdef _mm512_mask_svml_round_pd
#undef _mm512_mask_svml_round_pd
__m512d _mm512_mask_svml_round_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_sin_pd
#undef _mm512_sin_pd
__m512d _mm512_sin_pd(__m512d _a);
#endif
#ifdef _mm512_mask_sin_pd
#undef _mm512_mask_sin_pd
__m512d _mm512_mask_sin_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_sin_ps
#undef _mm512_sin_ps
__m512 _mm512_sin_ps(__m512 _a);
#endif
#ifdef _mm512_mask_sin_ps
#undef _mm512_mask_sin_ps
__m512 _mm512_mask_sin_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_sinh_pd
#undef _mm512_sinh_pd
__m512d _mm512_sinh_pd(__m512d _a);
#endif
#ifdef _mm512_mask_sinh_pd
#undef _mm512_mask_sinh_pd
__m512d _mm512_mask_sinh_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_sinh_ps
#undef _mm512_sinh_ps
__m512 _mm512_sinh_ps(__m512 _a);
#endif
#ifdef _mm512_mask_sinh_ps
#undef _mm512_mask_sinh_ps
__m512 _mm512_mask_sinh_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_sind_pd
#undef _mm512_sind_pd
__m512d _mm512_sind_pd(__m512d _a);
#endif
#ifdef _mm512_mask_sind_pd
#undef _mm512_mask_sind_pd
__m512d _mm512_mask_sind_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_sind_ps
#undef _mm512_sind_ps
__m512 _mm512_sind_ps(__m512 _a);
#endif
#ifdef _mm512_mask_sind_ps
#undef _mm512_mask_sind_ps
__m512 _mm512_mask_sind_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_tan_pd
#undef _mm512_tan_pd
__m512d _mm512_tan_pd(__m512d _a);
#endif
#ifdef _mm512_mask_tan_pd
#undef _mm512_mask_tan_pd
__m512d _mm512_mask_tan_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_tan_ps
#undef _mm512_tan_ps
__m512 _mm512_tan_ps(__m512 _a);
#endif
#ifdef _mm512_mask_tan_ps
#undef _mm512_mask_tan_ps
__m512 _mm512_mask_tan_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_tand_pd
#undef _mm512_tand_pd
__m512d _mm512_tand_pd(__m512d _a);
#endif
#ifdef _mm512_mask_tand_pd
#undef _mm512_mask_tand_pd
__m512d _mm512_mask_tand_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_tand_ps
#undef _mm512_tand_ps
__m512 _mm512_tand_ps(__m512 _a);
#endif
#ifdef _mm512_mask_tand_ps
#undef _mm512_mask_tand_ps
__m512 _mm512_mask_tand_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_tanh_pd
#undef _mm512_tanh_pd
__m512d _mm512_tanh_pd(__m512d _a);
#endif
#ifdef _mm512_mask_tanh_pd
#undef _mm512_mask_tanh_pd
__m512d _mm512_mask_tanh_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_tanh_ps
#undef _mm512_tanh_ps
__m512 _mm512_tanh_ps(__m512 _a);
#endif
#ifdef _mm512_mask_tanh_ps
#undef _mm512_mask_tanh_ps
__m512 _mm512_mask_tanh_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_trunc_pd
#undef _mm512_trunc_pd
__m512d _mm512_trunc_pd(__m512d _a);
#endif
#ifdef _mm512_mask_trunc_pd
#undef _mm512_mask_trunc_pd
__m512d _mm512_mask_trunc_pd(__m512d _src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_trunc_ps
#undef _mm512_trunc_ps
__m512 _mm512_trunc_ps(__m512 _a);
#endif
#ifdef _mm512_mask_trunc_ps
#undef _mm512_mask_trunc_ps
__m512 _mm512_mask_trunc_ps(__m512 _src, __mmask16 k, __m512 _a);
#endif
#ifdef _mm512_sincos_pd
#undef _mm512_sincos_pd
__m512d _mm512_sincos_pd(__m512d * _cos_res, __m512d _a);
#endif
#ifdef _mm512_mask_sincos_pd
#undef _mm512_mask_sincos_pd
__m512d _mm512_mask_sincos_pd(__m512d * _cos_res, __m512d _sin_src, __m512d _cos_src, __mmask8 k, __m512d _a);
#endif
#ifdef _mm512_sincos_ps
#undef _mm512_sincos_ps
__m512 _mm512_sincos_ps(__m512 * _cos_res, __m512 _a);
#endif
#ifdef _mm512_mask_sincos_ps
#undef _mm512_mask_sincos_ps
__m512 _mm512_mask_sincos_ps(__m512 * _cos_res, __m512 _sin_src, __m512 _cos_src, __mmask16 k, __m512 _a);
#endif