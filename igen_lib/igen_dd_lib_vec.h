#pragma once
#include <immintrin.h>
#include <math.h>
#include <fenv.h>
#include <stdio.h>
#include <float.h>
#include "igen_dd_types_vec.h"
#include "igen_logic.h"
#include "igen_lib.h"
#include "igen_dd_casts.h"

typedef struct {
    __m256d _1;
    __m256d _2;
} dd_ddavx_I;

typedef __m256d dd_v;

typedef struct {
    dd_v h;
    dd_v l;
} dd2_v;

///
/// Error-free transformations
///
static dd2_v fastTwoSum(dd_v a, dd_v b) {
#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s = a + b;
    dd_v z = s - a;
    dd_v t = b - z;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd2_v r;
    r.h = s;
    r.l = t;
    return r;
}

static dd2_v twoSum(dd_v a, dd_v b) {
#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s  = a + b;
    dd_v a_ = s - b;
    dd_v b_ = s - a_;
    dd_v da = a - a_;
    dd_v db = b - b_;
    dd_v t  = da + db;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd2_v r;
    r.h = s;
    r.l = t;
    return r;
}

static dd2_v twoMul(dd_v a, dd_v b) {
#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s  = a * b;
    dd_v t  = _mm256_fmsub_pd(a, b, s);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    dd2_v r;
    r.h = s;
    r.l = t;

    return r;
}

///
/// Vector operations on double-doubles
///
static dd_v _vec_addh_dd(dd_v a, dd_v b) {
    dd2_v s  = twoSum(a, b);
    dd_v _a  = _mm256_permute_pd(a, 0b0101);
    dd_v  v  = _a + s.l;
    dd2_v z  = fastTwoSum(s.h, v);
    dd_v  z_hl = _mm256_unpacklo_pd(z.h, z.l);
    return z_hl;
}

static dd_v _vec_add_dd(dd_v a, dd_v b) {
    dd2_v s_t  = twoSum(a, b);
    dd_v  th   = _mm256_permute_pd(s_t.h, 0b0101);
    dd_v  tl   = _mm256_permute_pd(s_t.l, 0b0101);
    dd_v  c    = s_t.l + th;
    dd2_v v    = fastTwoSum(s_t.h, c);
    dd_v  w    = tl + v.l;
    dd2_v z    = fastTwoSum(v.h, w);
    dd_v  z_hl = _mm256_unpacklo_pd(z.h, z.l);
    return z_hl;
}

/// Addition double-double with double
static dd_v _vec_add_dd_d(dd_v a, dd_v b) {
    dd2_v s_t  = twoSum(a, b);
    dd_v  al   = _mm256_permute_pd(a, 0b0101);
    dd_v  c    = s_t.l + al;
    dd2_v z    = fastTwoSum(s_t.h, c);
    dd_v  z_hl = _mm256_unpacklo_pd(z.h, z.l);
    return z_hl;
}

static dd_ddavx_I _vec_add2_dd(dd_v a1, dd_v b1, dd_v a2, dd_v b2) {
    dd_v  ah = _mm256_unpacklo_pd(a1, a2);
    dd_v  al = _mm256_unpackhi_pd(a1, a2);
    dd_v  bh = _mm256_unpacklo_pd(b1, b2);
    dd_v  bl = _mm256_unpackhi_pd(b1, b2);

    dd2_v s  = twoSum(ah, bh);
    dd2_v t  = twoSum(al, bl);
    dd_v  c  = s.l + t.h;
    dd2_v v  = fastTwoSum(s.h, c);
    dd_v  w  = t.l + v.l;
    dd2_v z  = fastTwoSum(v.h, w);

    dd_ddavx_I r;
    r._1 = _mm256_unpacklo_pd(z.h, z.l);
    r._2 = _mm256_unpackhi_pd(z.h, z.l);
    return r;
}

static dd_v _vec_mulh_dd (dd_v a, dd_v b) {
    dd2_v c    = twoMul(a, b);
    dd_v _a    = _mm256_permute_pd(a, 0b0101);
    dd_v cl2   = _mm256_fmadd_pd(_a, b, c.l);
    dd2_v z    = fastTwoSum(c.h, cl2);
    dd_v  z_hl = _mm256_unpacklo_pd(z.h, z.l);
    return z_hl;
}

static dd_v _vec_mul_dd(dd_v a, dd_v b) {
    dd2_v c   = twoMul(a, b);
    dd_v  tl0 = _mm256_permute_pd(c.h, 0b0101);
    dd_v _a   = _mm256_permute_pd(a,   0b0101);
    dd_v _b   = _mm256_permute_pd(b,   0b0101);
    dd_v  tl1 = _mm256_fmadd_pd( a, _b, tl0);
    dd_v  cl2 = _mm256_fmadd_pd(_a,  b, tl1);
    dd_v  cl3 = c.l + cl2;
    dd2_v z   = fastTwoSum(c.h, cl3);
    dd_v  z_hl = _mm256_unpacklo_pd(z.h, z.l);
    return z_hl;
}

static dd_ddavx_I _vec_mul2_dd(dd_v a1, dd_v b1, dd_v a2, dd_v b2) {
    dd_v  ah = _mm256_unpacklo_pd(a1, a2);
    dd_v  al = _mm256_unpackhi_pd(a1, a2);
    dd_v  bh = _mm256_unpacklo_pd(b1, b2);
    dd_v  bl = _mm256_unpackhi_pd(b1, b2);

    dd2_v c   = twoMul(ah, bh);
    dd_v  tl0 = al * bl;
    dd_v  tl1 = _mm256_fmadd_pd(ah, bl, tl0);
    dd_v  cl2 = _mm256_fmadd_pd(al, bh, tl1);
    dd_v  cl3 = c.l + cl2;
    dd2_v z   = fastTwoSum(c.h, cl3);

    dd_ddavx_I r;
    r._1 = _mm256_unpacklo_pd(z.h, z.l);
    r._2 = _mm256_unpackhi_pd(z.h, z.l);

    return r;
}

static dd2_v _vec_mul2_dd_2(dd_v ah, dd_v al, dd_v bh, dd_v bl) {
    dd2_v c   = twoMul(ah, bh);
    dd_v  tl0 = al * bl;
    dd_v  tl1 = _mm256_fmadd_pd(ah, bl, tl0);
    dd_v  cl2 = _mm256_fmadd_pd(al, bh, tl1);
    dd_v  cl3 = c.l + cl2;
    dd2_v z   = fastTwoSum(c.h, cl3);
    return z;
}

static dd_v _vec_reciprocal_dd(dd_v b) {
    dd_v  oz   = _mm256_set_pd(0.0, 1.0, 0.0, 1.0);
    dd_v  th   = _mm256_permute_pd(1.0 / b, 0b0000);
    dd_v  r    = _mm256_fnmadd_pd(b, th, oz);
    dd_v  rl   = _mm256_permute_pd(r, 0b1111);
    dd2_v e    = fastTwoSum(r, rl);
    dd_v  e_hl = _mm256_unpacklo_pd(e.h, e.l);
    dd_v  d    = _vec_mulh_dd(e_hl, th);
    dd_v  m    = _vec_addh_dd(d, th);
    return m;
}

static dd_v _vec_div_dd(dd_v a, dd_v b) {
    dd_v  m  = _vec_reciprocal_dd(b);
    dd_v  z  = _vec_mul_dd(a, m);
    return z;
}

static dd_v _vec_max_dd(dd_v a, dd_v b) {

    dd_v minf, mask1, mask2, _a, _b, c;

    /* Create -inf vector */
    minf  = _mm256_set1_pd(-1.0/0.0);

    mask1 = _mm256_cmp_pd(a, b, _CMP_GE_OQ);
    mask2 = _mm256_cmp_pd(a, b, _CMP_LE_OQ);

    mask1 = _mm256_unpacklo_pd(mask1, mask1);
    mask2 = _mm256_unpacklo_pd(mask2, mask2);

    _a = _mm256_blendv_pd(minf, a, mask1);
    _b = _mm256_blendv_pd(minf, b, mask2);

    c = _mm256_max_pd(_a, _b);

    return c;
}

///
/// Auxiliary comparison functions
///
static int dd_cmpgt(double ah, double al, double bh, double bl) {
    return bh - ah < al - bl;
}

static int dd_cmpgeq(double ah, double al, double bh, double bl) {
    /* todo: check if this works */
    return bh - ah <= al - bl;
}

static int dd_cmpeq(double ah, double al, double bh, double bl) {
    return !dd_cmpgt(ah, al, bh, bl) && !dd_cmpgt(bh, bl, ah, al);
}

///
/// Basic operations on intervals double-double
///
static dd_I _ia_set_dd(double loh, double lol, double uph, double upl) {
    return _mm256_set_pd(upl, uph, lol, loh);
}

static dd_I _ia_add_dd(dd_I a, dd_I b) {
    return _vec_add_dd(a, b);
}

static dd_I _ia_sub_dd(dd_I a, dd_I b) {
    dd_I _b = _mm256_permute4x64_pd(b, 0b01001110);
    return _vec_add_dd(a,_b);
}

static dd_I _ia_mul_dd(dd_I a, dd_I b) {
    dd_I _b = _mm256_permute4x64_pd(b, 0b01001110);

    dd_ddavx_I _r_up = _vec_mul2_dd(a,  b, a, -_b);
    dd_ddavx_I _r_lo = _vec_mul2_dd(a, -b, a,  _b);

    dd_I r_up = _vec_max_dd(_r_up._1, _r_up._2);
    dd_I r_lo = _vec_max_dd(_r_lo._1, _r_lo._2);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1 = _mm256_permute2f128_pd(r_lo, r_up, 0b00100000);
    dd_I c2 = _mm256_permute2f128_pd(r_lo, r_up, 0b00110001);
    dd_I c  = _vec_max_dd(c1, c2);

    return c;
}

static dd_I _ia_div_dd(dd_I a, dd_I b) {
    dd_I res;
    u_ddi _b = { .v = b};
    int bNoZero = (_b.uh < 0.0 || (_b.uh == 0.0 && _b.ul <  0.0)) || (_b.lh < 0.0 || (_b.lh == 0.0 && _b.ll <  0.0));

    if (bNoZero) {
        dd_I one = _ia_set_dd(-1.0, -0.0, -1.0, -0.0);
        dd_I inv_b = _vec_div_dd(one, b);
        inv_b = _mm256_permute4x64_pd(inv_b, 0b01001110);
        res = _ia_mul_dd(a, inv_b);
    }
    else {
        res = _ia_set_dd(INFINITY, -0.0, INFINITY, 0.0);
    }

    return res;
}

static dd_I _ia_neg_dd(dd_I a) {
    return _mm256_permute4x64_pd(a, 0b01001110);
}

static dd_I _ia_cvt_i2dd(int x) {
    return _ia_set_dd(-x, 0, x, 0);
}

///
/// Comparison on intervals
///
static bool_I _ia_cmpgt_dd(dd_I a, dd_I b) {

    /* Todo: Check if this is faster using purely intrinsics */
    u_ddi _a = { .v = a };
    u_ddi _b = { .v = b };

    if ( dd_cmpgt (-_a.lh, -_a.ll, _b.uh,  _b.ul) ) { return TRUE_I;  }
    if ( dd_cmpgeq(-_b.lh, -_b.ll, _a.uh,  _a.ul) ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpg_dd\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmplt_dd(dd_I a, dd_I b) {
    return _ia_cmpgt_dd(b, a);
}

static bool_I _ia_cmpge_dd(dd_I a, dd_I b) {
    u_ddi _a = { .v = a };
    u_ddi _b = { .v = b };

    if ( dd_cmpgeq(-_a.lh, -_a.ll, _b.uh,  _b.ul) ) { return TRUE_I;  }
    if ( dd_cmpgt (-_b.lh, -_b.ll, _a.uh,  _a.ul) ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpg_dd\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmple_dd(dd_I a, dd_I b) {
    return _ia_cmpge_dd(b, a);
}

static bool_I _ia_cmpneq_dd(dd_I a, dd_I b) {
    /* Ideally, intervals should not be compared for equality */
    u_ddi _a = { .v = a };
    u_ddi _b = { .v = b };

    if ( dd_cmpeq(_a.uh, _a.ul, -_a.lh, -_a.ll) &&
         dd_cmpeq(_b.uh, _b.ul, -_b.lh, -_b.ll) &&
         dd_cmpeq(_a.uh, _a.ul,  _b.uh, _b.ul)) {
        return FALSE_I;
    }
    else if (_ia_cmplt_dd(a,b) || _ia_cmpgt_dd(a,b)) {
        return TRUE_I;
    }

    fprintf(stderr, "Error: Unknown state in _ia_cmpneq_dd\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpeq_dd(dd_I a, dd_I b) {
    /* Ideally, intervals should not be compared for equality */
    u_ddi _a = { .v = a };
    u_ddi _b = { .v = b };

    if ( dd_cmpeq(_a.uh, _a.ul, -_a.lh, -_a.ll) &&
         dd_cmpeq(_b.uh, _b.ul, -_b.lh, -_b.ll) &&
         dd_cmpeq(_a.uh, _a.ul,  _b.uh, _b.ul)) {
        return TRUE_I;
    }
    else if (_ia_cmplt_dd(a,b) || _ia_cmpgt_dd(a,b)) {
        return FALSE_I;
    }

    fprintf(stderr, "Error: Unknown state in _ia_cmpeq_dd\n");
    return UNKNOWN_I;
}

///
/// Other special functions
///
static dd_I _ia_add_dd_f64i(dd_I a, f64_I b) {
    u_f64i* _b = (u_f64i*) &b;
    dd_I t1 = _ia_set_dd(_b->lo, -0.0, _b->up, 0.0);
    return _vec_add_dd_d(a, t1);
}

static double _ia_get_lo_dd(dd_I a) {
    u_ddi _a = { .v = a };
    return -_a.lh;
}

static double _ia_get_up_dd(dd_I a) {
    u_ddi _a = { .v = a };
    return _a.uh;
}

static dd_I _ia_set_pointed_dd(double h, double l) {
    return _ia_set_dd(-h,-l,h,l);
}

static dd_I _ia_set_pointed_h_dd(double h) {
    return _ia_set_dd(-h,-0.0,h,0.0);
}

static dd_I _ia_set_epsilon_dd(double h, double l) {
    if (l != 0.0) {
        return _ia_set_dd(-h,-l,h,l+DBL_MIN);
    }
    else {
        double ulp = (nextafter(h, INFINITY) - h) / exp2(53);
        return _ia_set_dd(-h, -0.0, h, ulp);
    }
}

static dd_I _ia_zero_dd() {
    return _ia_set_dd(-0.0,-0.0,0.0,0.0);
}

static dd_I _ia_one_dd() {
    return _ia_set_dd(-1.0,-0.0,1.0,0.0);
}