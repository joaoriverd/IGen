#pragma once
#include "igen_immintrin_types.h"
#include "igen_lib.h"

///
/// Auxiliary functions
///
static f64i_simd4 _igen_op_m256d_rearrange_pd(f64i_simd4 a) {
    f64i_simd4 dst;
    dst._0 = _mm256_unpacklo_pd(a._0, a._1);
    dst._1 = _mm256_unpackhi_pd(a._0, a._1);
    return dst;
}

///
/// Interval SIMD intrinsics hand optimized
///

static f64i_simd2 _igen_op_mm_load_sd(const f64_I *mem_addr) {
    f64i_simd2 dst;
    __m128d t;
    t = _mm_load_pd((double*)mem_addr);
#ifdef __clang__
    dst._0 = _mm256_zextpd128_pd256(t);
#else
    dst._0 = _mm256_setzero_pd();
    dst._0 = _mm256_castpd128_pd256(t);
#endif
    return dst;
}

static f64i_simd4 _igen_op_mm256_add_pd(f64i_simd4 _a, f64i_simd4 _b) {
    f64i_simd4 dst;
    dst._0 = _a._0 + _b._0;
    dst._1 = _a._1 + _b._1;
    return dst;
}

static f64i_simd4 _igen_op_mm256_mul_pd_v1(f64i_simd4 _a, f64i_simd4 _b) {
    f64i_simd4 dst, a, b;

    a = _igen_op_m256d_rearrange_pd(_a);
    b = _igen_op_m256d_rearrange_pd(_b);

    __m256d t1_up, t2_up, t3_up, t4_up;
    __m256d t1_lo, t2_lo, t3_lo, t4_lo;

    t1_up = a._1 *  b._1;
    t2_up = a._1 * -b._0;
    t3_up = a._0 * -b._1;
    t4_up = a._0 *  b._0;

    t1_lo = a._1 * -b._1;
    t2_lo = a._1 *  b._0;
    t3_lo = a._0 *  b._1;
    t4_lo = a._0 * -b._0;

    __m256d up1, up2, lo1, lo2;
    lo1 = _mm256_max_pd(t1_lo, t3_lo);
    lo2 = _mm256_max_pd(t2_lo, t4_lo);
    up1 = _mm256_max_pd(t1_up, t3_up);
    up2 = _mm256_max_pd(t2_up, t4_up);
    dst._0 = _mm256_max_pd(lo1, lo2);
    dst._1 = _mm256_max_pd(up1, up2);

    /* Make interleave format */
    return _igen_op_m256d_rearrange_pd(dst);
}

static f64i_simd4 _igen_op_mm256_mul_pd_v2(f64i_simd4 _a, f64i_simd4 _b) {
    f64i_simd4 dst, a, b;

    a = _igen_op_m256d_rearrange_pd(_a);
    b = _igen_op_m256d_rearrange_pd(_b);

    __m256d t1_up, t2_up, t3_up, t4_up;
    __m256d t1_lo, t2_lo, t3_lo, t4_lo;

    t1_up = a._1 *  b._1;
    t2_up = a._1 * -b._0;
    t3_up = a._0 * -b._1;
    t4_up = a._0 *  b._0;

    __m256d up1, up2, lo1, lo2;
    lo1 = _mm256_min_pd(t1_up, t3_up);
    lo2 = _mm256_min_pd(t2_up, t4_up);
    up1 = _mm256_max_pd(t1_up, t3_up);
    up2 = _mm256_max_pd(t2_up, t4_up);
    dst._0 = -_mm256_min_pd(lo1, lo2);
    dst._1 =  _mm256_max_pd(up1, up2);

    /* Adjust lower bound since everything was rounded upward (at most 1 ulp error) */
    const __m256d eps = _mm256_set1_pd(DBL_MIN);
    dst._0 += eps;

    /* Make interleave format */
    return _igen_op_m256d_rearrange_pd(dst);
}

static f64i_simd4 _igen_op_mm256_mul_pd(f64i_simd4 a, f64i_simd4 b) {
    return _igen_op_mm256_mul_pd_v2(a, b);
}

static f64i_simd4 _igen_op_mm256_sub_pd(f64i_simd4 _a, f64i_simd4 _b) {
    f64i_simd4 neg_b, dst;
    neg_b._0 = _mm256_permute_pd(_b._0, 0b0101);
    neg_b._1 = _mm256_permute_pd(_b._1, 0b0101);
    dst._0 = _a._0 + neg_b._0;
    dst._1 = _a._1 + neg_b._1;
    return dst;
}

static f64i_simd4 _igen_op_mm256_fmadd_pd(f64i_simd4 a, f64i_simd4 b, f64i_simd4 c) {
    f64i_simd4 dst;
    f64i_simd4 t1 = _igen_op_mm256_mul_pd(a, b);
    dst = _igen_op_mm256_add_pd(t1, c);
    return dst;
}

#ifdef __OPTIMIZE__
static f64i_simd4 _igen_op_mm256_shuffle_pd(f64i_simd4 _a, f64i_simd4 _b, int imm8) {

    f64i_simd4 dst;
    unsigned imm8_lo, imm8_up;
    unsigned bit0 = ((imm8 >> 0) & 1) << 0;
    unsigned bit1 = ((imm8 >> 1) & 1) << 4;
    unsigned bit2 = ((imm8 >> 2) & 1) << 0;
    unsigned bit3 = ((imm8 >> 3) & 1) << 4;
    imm8_lo = bit0 | bit1 | 0b00100000;
    imm8_up = bit2 | bit3 | 0b00100000;

    dst._0  = _mm256_permute2f128_pd(_a._0, _b._0, imm8_lo);
    dst._1  = _mm256_permute2f128_pd(_a._1, _b._1, imm8_up);

    return dst;
}
#endif

static f64i_simd4 _igen_op_mm256_permute2f128_pd(f64i_simd4 _a, f64i_simd4 _b, int imm8) {
    f64i_simd4 dst;
    unsigned imm8_lo = ((imm8 >> 0) & 0b1111);
    unsigned imm8_up = ((imm8 >> 4) & 0b1111);

    switch (imm8_lo) {
        case 0:
            dst._0 = _a._0;
            break;
        case 1:
            dst._0 = _a._1;
            break;
        case 2:
            dst._0 = _b._0;
            break;
        case 3:
            dst._0 = _b._1;
            break;
        default: dst._0 = _mm256_setzero_pd();
    }

    switch (imm8_up) {
        case 0:
            dst._1 = _a._0;
            break;
        case 1:
            dst._1 = _a._1;
            break;
        case 2:
            dst._1 = _b._0;
            break;
        case 3:
            dst._1 = _b._1;
            break;
        default: dst._1 = _mm256_setzero_pd();
    }

    return dst;
}

static f64i_simd4 _igen_op_mm256_loadu_pd(const f64_I *mem_addr) {
    f64i_simd4 dst;
    double* mem_addr_d = (double*)mem_addr;
    dst._0 = _mm256_loadu_pd(mem_addr_d + 0);
    dst._1 = _mm256_loadu_pd(mem_addr_d + 4);
    return dst;
}

static f64i_simd4 _igen_op_mm256_load_pd(const f64_I *mem_addr) {
    f64i_simd4 dst;
    double* mem_addr_d = (double*)mem_addr;
    dst._0 = _mm256_load_pd(mem_addr_d + 0);
    dst._1 = _mm256_load_pd(mem_addr_d + 4);
    return dst;
}

static void _igen_op_mm256_storeu_pd(f64_I *mem_addr, f64i_simd4 _a) {
    double* mem_addr_d = (double*)mem_addr;
    _mm256_storeu_pd(mem_addr_d + 0, _a._0);
    _mm256_storeu_pd(mem_addr_d + 4, _a._1);
}

static f64i_simd4 _igen_op_mm256_unpackhi_pd(f64i_simd4 _a, f64i_simd4 _b) {
    f64i_simd4 dst;
    dst._0 = _mm256_permute2f128_pd(_a._0, _b._0, 0b00110001);
    dst._1 = _mm256_permute2f128_pd(_a._1, _b._1, 0b00110001);
    return dst;
}

static f64i_simd4 _igen_op_mm256_unpacklo_pd(f64i_simd4 _a, f64i_simd4 _b) {
    f64i_simd4 dst;
    dst._0 = _mm256_permute2f128_pd(_a._0, _b._0, 0b00100000);
    dst._1 = _mm256_permute2f128_pd(_a._1, _b._1, 0b00100000);
    return dst;
}

static f64i_simd4 _igen_op_mm256_set_pd(f64_I _e3, f64_I _e2, f64_I _e1, f64_I _e0) {
    f64i_simd4 dst;
    u_f64i* e0  = (u_f64i*) &_e0;
    u_f64i* e1  = (u_f64i*) &_e1;
    u_f64i* e2  = (u_f64i*) &_e2;
    u_f64i* e3  = (u_f64i*) &_e3;
    dst._0  = _mm256_set_pd(e1->up, e1->lo, e0->up, e0->lo);
    dst._1  = _mm256_set_pd(e3->up, e3->lo, e2->up, e2->lo);

    return dst;
}

static f64i_simd2 _igen_op_mm256_castpd256_pd128(f64i_simd4 _a) {
    f64i_simd2 r;
    r._0 = _a._0;
    return r;
}

static f64i_simd4 _igen_op_mm256_broadcast_sd(const f64_I *mem_addr) {
    f64i_simd4 dst;
    __m256d lo, up;
    double* mem_addr_d = (double*)mem_addr;
    lo = _mm256_broadcast_sd(mem_addr_d);
    up = _mm256_broadcast_sd(mem_addr_d + 1);
    dst._0 = _mm256_unpacklo_pd(lo,up);
    dst._1 = dst._0;
    return dst;
}

static f64i_simd4 _igen_op_mm256_broadcastsd_pd(f64i_simd2 a) {
    f64i_simd4 dst;
    dst._0 = _mm256_permute4x64_pd(a._0, 0b01000100);
    dst._1 = dst._0;
    return dst;
}

static f64i_simd4 _igen_op_mm256_set1_pd(f64_I _a) {
    f64i_simd4 dst;
    u_f64i* a   = (u_f64i*) &_a;
    dst._0  = _mm256_set_pd(a->up, a->lo, a->up, a->lo);
    dst._1  = _mm256_set_pd(a->up, a->lo, a->up, a->lo);
    return dst;
}

static f64i_simd2 _igen_op_mm256_extractf128_pd(f64i_simd4 _a, int imm8) {
    f64i_simd2 dst;

    switch (((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1)) {
        case 0:
            dst._0 = _a._0;
            break;
        case 1:
            dst._0 = _a._1;
            break;
    }

    return dst;
}

static f64i_simd2 _igen_op_mm_add_pd(f64i_simd2 _a, f64i_simd2 _b) {
    f64i_simd2 dst;
    dst._0 = _a._0 + _b._0;
    return dst;
}

static f64i_simd2 _igen_op_mm_unpackhi_pd(f64i_simd2 _a, f64i_simd2 _b) {
    f64i_simd2 dst;
    dst._0 = _mm256_permute2f128_pd(_a._0, _b._0, 0b00110001);
    return dst;
}

static f64_I _igen_op_mm_cvtsd_f64(f64i_simd2 _a) {
    return _mm256_castpd256_pd128(_a._0);
}