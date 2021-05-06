#pragma once
#include <math.h>
#include <fenv.h>
#include <stdio.h>
#include <float.h>
#include "igen_dd_types.h"
#include "igen_logic.h"
#include "igen_lib.h"
#include "igen_dd_casts.h"

#define SHIFT_POW 27  // ceil(53/2) for binary64.
//#define USE_ROUND_TO_NEAREST

///
/// Error-free transformations
///
static dd_t veltkampSplit(double x) {
    static unsigned long C = (1UL << SHIFT_POW) + 1;
    double gamma = C * x;
    double delta = x - gamma;
    dd_t r;
    r.h = gamma + delta;
    r.l = x - r.h;
    return r;
}

static dd_t fastTwoSum(double a, double b) {
#ifdef USE_ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    double s = a + b;
    double z = s - a;
    double t = b - z;

#ifdef USE_ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_t r;
    r.h = s;
    r.l = t;

    return r;
}

static dd_t twoSum(double a, double b) {
#ifdef USE_ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    double s  = a + b;
    double a_ = s - b;
    double b_ = s - a_;
    double da = a - a_;
    double db = b - b_;
    double t  = da + db;

#ifdef USE_ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_t r;
    r.h = s;
    r.l = t;
    return r;
}

/// twoMul. Flops = 3 when FMA is available. Otherwise 17.
static dd_t twoMul(double _a, double _b) {
#ifdef USE_ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif
#ifdef __FMA__
    double s = _a * _b;
    double t = fma(_a, _b, -s);
#else
    dd_t a = veltkampSplit(_a);
    dd_t b = veltkampSplit(_b);
    double s   = _a * _b;
    double t_1 =  -s + a.h * b.h;
    double t_2 = t_1 + a.h * b.l;
    double t_3 = t_2 + a.l * b.h;
    double t   = t_3 + a.l * b.l;

#endif

#ifdef USE_ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    dd_t r;
    r.h = s;
    r.l = t;
    return r;
}

///
/// Auxiliary comparison functions
///
static int dd_cmpgt(dd_t a, dd_t b) {
    return b.h - a.h < a.l - b.l;
}

static int dd_cmpgeq(dd_t a, dd_t b) {
    return b.h - a.h <= a.l - b.l;
}

static int dd_cmpeq(dd_t a, dd_t b) {
    return dd_cmpgeq(a, b) && dd_cmpgeq(b, a);
}

static int dd_cmpgt_(double ah, double al, double bh, double bl) {
    return bh - ah < al - bl;
}

static int dd_cmpgeq_(double ah, double al, double bh, double bl) {
    /* todo: check if this works */
    return bh - ah <= al - bl;
}

static int dd_cmpeq_(double ah, double al, double bh, double bl) {
    return !dd_cmpgt_(ah, al, bh, bl) && !dd_cmpgt_(bh, bl, ah, al);
}

/// Accurate addition of two DD numbers
/// (sh, sl) ← 2Sum(ah, bh)
/// (th, tl) ← 2Sum(al, bl)
/// c ← RN(sl + th)
/// (vh, vl) ← Fast2Sum(sh, c)
/// w ← RN(tl + vl)
/// (zh, zl) ← Fast2Sum(vh, w)
/// return (zh, zl)
static dd_t dd_add(dd_t a, dd_t b) {
    dd_t s   = twoSum(a.h, b.h);
    dd_t t   = twoSum(a.l, b.l);
    double c = s.l + t.h;
    dd_t v   = fastTwoSum(s.h, c);
    double w = t.l + v.l;
    dd_t z   = fastTwoSum(v.h, w);
    return z;
}

/// Accurate multiplication of two DD numbers without FMA
/// 1: (ch,cl) ← 2Prod(ah,bh)
/// 2: t1 ← RN(ah · bl)
/// 3: t2 ← RN(al · bh)
/// 4: c2 ← RN(t1 + t2)
/// 5: c3 ← RN(cl + c2)
/// 6: (zh, zl) ← Fast2Sum(ch,c3)
/// 7: return (zh, zl)
/// FLOPS: 24
static dd_t dd_mul(dd_t a, dd_t b) {
    dd_t c    = twoMul(a.h, b.h);
    double t1 = a.h * b.l;
    double t2 = a.l * b.h;
    double c2 = t1 + t2;
    double c3 = c.l + c2;
    dd_t   z  = fastTwoSum(c.h,c3);
    return z;
}

/// Reciprocal of a DD numbers
/// 1: th ← RN(1/yh)
/// 2: rh ← RN(1 - yh*th)  // exact using fma
/// 3: rl ← RN(0 - yl*th)
/// 4: (eh, el) ← Fast2Sum(rh,rl)
/// 5: (δh, δl) ← DWTimesFP(eh, el, th)
/// 6: (mh, ml) ← DWPlusFP(δh, δl, th)
/// return (mh, ml)
static dd_t dd_reciprocal(dd_t y) {
    double yh = y.h;
    double yl = y.l;
#ifdef __FMA__
    double th = 1.0 / yh;
    double rh = fma(-yh, th, 1.0);
    double rl = fma(-yl, th, 0.0);
    dd_t    e = fastTwoSum(rh, rl);
    dd_t  _th = {th, 0.0};
    dd_t    d = dd_mul(e, _th);
    dd_t    m = dd_add(d, _th);
    return m;
#else
    fprintf(stderr, "Error: double-double division not supported without FMA.\n");
    return y;
#endif
}

static dd_t dd_neg(dd_t a) {
    dd_t r;
    r.h = -a.h;
    r.l = -a.l;
    return r;
}

static dd_t dd_max(dd_t a, dd_t b) {
    return dd_cmpgt(a, b) ? a : b;
}

static dd_t dd_max4(dd_t a1, dd_t a2, dd_t a3, dd_t a4) {
    dd_t t1 = dd_max(a1, a2);
    dd_t t2 = dd_max(a3, a4);
    dd_t r  = dd_max(t1, t2);
    return r;
}

static dd_t dd_set(double h, double l) {
    dd_t t;
    t.h = h;
    t.l = l;
    return t;
}

///
/// Basic operations on intervals double-double
///
static dd_I _ia_set_dd(double loh, double lol, double uph, double upl) {
    dd_I a;
    a.lo.h = loh;
    a.lo.l = lol;
    a.up.h = uph;
    a.up.l = upl;
    return a;
}

static dd_I _ia_add_dd(dd_I a, dd_I b) {
    dd_I r;
    r.up = dd_add(a.up, b.up);
    r.lo = dd_add(a.lo, b.lo);
    return r;
}

static dd_I _ia_sub_dd(dd_I a, dd_I b) {
    dd_I r;
    r.up = dd_add(a.up, b.lo);
    r.lo = dd_add(a.lo, b.up);
    return r;
}

static dd_I _ia_mul_dd(dd_I a, dd_I b) {
    dd_I r;
    dd_t _a_up = dd_neg(a.up);
    dd_t _a_lo = dd_neg(a.lo);

    /* Get upper bound */
    dd_t u1 = dd_mul( a.up,  b.up);
    dd_t u2 = dd_mul(_a_up,  b.lo);
    dd_t u3 = dd_mul(_a_lo,  b.up);
    dd_t u4 = dd_mul( a.lo,  b.lo);
    r.up = dd_max4(u1, u2, u3, u4);

    /* Get lower bound */
    dd_t l1 = dd_mul(_a_up,  b.up);
    dd_t l2 = dd_mul( a.up,  b.lo);
    dd_t l3 = dd_mul( a.lo,  b.up);
    dd_t l4 = dd_mul(_a_lo,  b.lo);
    r.lo = dd_max4(l1, l2, l3, l4);

    return r;
}

static dd_I _ia_div_dd(dd_I a, dd_I b) {
    dd_I res;
    int bNoZero = (b.up.h < 0.0 || (b.up.h == 0.0 && b.up.l < 0.0)) || (b.lo.h < 0.0 || (b.lo.h == 0.0 && b.lo.l <  0.0));

    if (bNoZero) {
        dd_I inv_b;
        inv_b.lo = dd_reciprocal(dd_neg(b.up));
        inv_b.up = dd_reciprocal(dd_neg(b.lo));
        res = _ia_mul_dd(a, inv_b);
    }
    else {
        res = _ia_set_dd(INFINITY, -0.0, INFINITY, 0.0);
    }

    return res;
}

static dd_I _ia_neg_dd(dd_I a) {
    dd_I r;
    r.up = a.lo;
    r.lo = a.up;
    return r;
}

static dd_I _ia_cvt_i2dd(int x) {
    return _ia_set_dd(-x, 0, x, 0);
}

///
/// Comparison on intervals
///
static bool_I _ia_cmpgt_dd(dd_I a, dd_I b) {
    /* Todo: Check if it is faster using purely intrinsics */
    u_ddi _a = { .v = a };
    u_ddi _b = { .v = b };

    if ( dd_cmpgt_ (-_a.lh, -_a.ll, _b.uh,  _b.ul) ) { return TRUE_I;  }
    if ( dd_cmpgeq_(-_b.lh, -_b.ll, _a.uh,  _a.ul) ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpg_dd\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmplt_dd(dd_I a, dd_I b) {
    return _ia_cmpgt_dd(b, a);
}

static bool_I _ia_cmpge_dd(dd_I a, dd_I b) {
    u_ddi _a = { .v = a };
    u_ddi _b = { .v = b };

    if ( dd_cmpgeq_(-_a.lh, -_a.ll, _b.uh,  _b.ul) ) { return TRUE_I;  }
    if ( dd_cmpgt_ (-_b.lh, -_b.ll, _a.uh,  _a.ul) ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpg_dd\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmple_dd(dd_I a, dd_I b) {
    return _ia_cmple_dd(b, a);
}

static bool_I _ia_cmpneq_dd(dd_I a, dd_I b) {
    /* Ideally, intervals should not be compared for equality */
    u_ddi _a = { .v = a };
    u_ddi _b = { .v = b };

    if ( dd_cmpeq_(_a.uh, _a.ul, -_a.lh, -_a.ll) &&
         dd_cmpeq_(_b.uh, _b.ul, -_b.lh, -_b.ll) &&
         dd_cmpeq_(_a.uh, _a.ul,  _b.uh, _b.ul)) {
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

    if ( dd_cmpeq_(_a.uh, _a.ul, -_a.lh, -_a.ll) &&
         dd_cmpeq_(_b.uh, _b.ul, -_b.lh, -_b.ll) &&
         dd_cmpeq_(_a.uh, _a.ul,  _b.uh, _b.ul)) {
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
    return _ia_add_dd(a, t1);
}

static dd_I _ia_set_pointed_dd(double h, double l) {
    return _ia_set_dd(-h,-l,h,l);
}

static dd_I _ia_set_pointed_h_dd(double h) {
    return _ia_set_dd(-h,-0.0,h,0.0);
}

static dd_I _ia_set_epsilon_dd(double h, double l) {
    return _ia_set_dd(-h,-l,h,l+DBL_MIN);
}

static dd_I _ia_zero_dd() {
    return _ia_set_dd(-0.0,-0.0,0.0,0.0);
}

static dd_I _ia_one_dd() {
    return _ia_set_dd(-01.0,-0.0,1.0,0.0);
}

static double _ia_get_lo_dd(dd_I a) {
    /* Normalize first */
    dd_t r = twoSum(a.lh, a.ll);
    return -r.h;
}

static double _ia_get_up_dd(dd_I a) {
    /* Normalize first */
    dd_t r = twoSum(a.uh, a.ul);
    return r.h;
}