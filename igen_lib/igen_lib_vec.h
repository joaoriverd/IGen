#pragma once

#include <immintrin.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include "igen_types_vec.h"
#include "igen_logic.h"

typedef __m128d f64v;

static const f64v zero = {0.0, 0.0};

///
/// Basic operations on vectorized f64i
///
static f64_I _ia_set_f64(double lo, double up) {
    return _mm_set_pd(up, lo);
}

static f64_I _ia_neg_f64(f64_I a) {
    return _mm_permute_pd(a, 0b01);
}

static f64_I _ia_add_f64(f64_I a, f64_I b) {
    return a + b;
}

static f64_I _ia_sub_f64(f64_I a, f64_I b) {
    f64_I _b = _ia_neg_f64(b);
    return a + _b;
}

static f64_I _ia_mul_f64_v1(f64_I a, f64_I b) {
    f64v nan = _mm_cmpunord_pd(a,b);

    f64v _a = -_mm_permute_pd(a, 0b01);
    f64v _b = -b;

    f64v u1 =   a *  b;
    f64v u2 =  _a *  b;
    f64v l1 =   a * _b;
    f64v l2 =  _a * _b;

    f64v u3 = _mm_max_pd(u1, u2);
    f64v l3 = _mm_max_pd(l1, l2);

    f64v t1 = _mm_unpacklo_pd(l3, u3);
    f64v t2 = _mm_unpackhi_pd(l3, u3);

    f64_I r = _mm_max_pd(t1, t2);

    return _mm_or_pd(r, nan);
}

static f64_I _ia_mul_f64_v2(f64_I _x, f64_I _y) {
    f64_I  _r;
    u_f64i* x = (u_f64i*) &_x;
    u_f64i* y = (u_f64i*) &_y;
    u_f64i* r = (u_f64i*) &_r;

    f64v nan = _mm_cmpunord_pd(_x,_y);
    __m128d x_neg_lo = _mm_xor_pd(_x, _mm_set_pd(0.0, -0.0));

    if (x->lo <= 0) {                     // x >= 0
        if (y->lo <= 0.0) {                   // y >= 0
//            r->lo = -x->lo * y->lo;      // r->lo = x->lo *< y->lo
//            r->up =  x->up * y->up;        // r->up = x->up *> y->up
            _r = x_neg_lo * _y;
        }
        else if (y->up <=0.0) {               // y <= 0
            r->lo =  x->up * y->lo;      // r->lo = x->up *< y->lo
            r->up = -x->lo * y->up;        // r->up = x->lo *> y->up
        }
        else {                                // 0 in y
            r->lo = x->up * y->lo;      // r->lo = x->up *< y->lo
            r->up = x->up * y->up;        // r->up = x->up *< y->up;
        }
    }
    else if (x->up <= 0.0) {              // x <= 0
        if (y->lo <= 0.0) {                   // y >= 0
            r->lo =  x->lo * y->up;      // r->lo = x->lo *< y->up
            r->up = -x->up * y->lo;        // r->up = x->up *> y->lo
        }
        else if (y->up <=0.0) {               // y <= 0
            r->lo = -x->up * y->up;      // r->lo = x->up *< y->up
            r->up =  x->lo * y->lo;        // r->up = x->lo *> y->lo
        }
        else {                                // 0 in y
            r->lo = x->lo * y->up;      // r->lo = x->lo *<= y->up
            r->up = x->lo * y->lo;        // r->up = x->lo *> y->lo
        }
    }
    else {                                // 0 in x
        if (y->lo <= 0.0) {                   // y >= 0
            r->lo = x->lo * y->up;      // r->lo = x->lo *< y->up
            r->up = x->up * y->up;        // r->up = x->up *> y->up
        }
        else if (y->up <=0.0) {               // y <= 0
            r->lo = x->up * y->lo;      // r->lo = x->up *< y->lo
            r->up = x->lo * y->lo;        // r->up = x->lo *> y->lo
        }
        else {
            double t1, t2;
            t1 = x->lo * y->up;
            t2 = x->up * y->lo;
            r->lo = (t1 > t2) ? t1 : t2;
            t1 = x->lo * y->lo;
            t2 = x->up * y->up;
            r->up = (t1 > t2) ? t1 : t2;
        }
    }

    return _mm_or_pd(_r, nan);
}

static f64_I _ia_mul_f64_v3(f64_I _x, f64_I _y) {
    f64_I  _r;
    u_f64i* x = (u_f64i*) &_x;
    u_f64i* y = (u_f64i*) &_y;
    u_f64i* r = (u_f64i*) &_r;

    f64v nan = _mm_cmpunord_pd(_x,_y);

    __m128d x_neg_lo = _mm_xor_pd(_x, _mm_set_pd(0.0, -0.0));
    __m128d x_neg_up = _mm_xor_pd(_x, _mm_set_pd(-0.0, 0.0));
    __m128d y_perm   = _mm_permute_pd(_y, 0b01);

    if (x->lo > 0) {
        if (x->up > 0) {
            if (y->lo > 0) {
                if (y->up > 0) {
                    double t1, t2;
                    t1 = x->lo * y->up;
                    t2 = x->up * y->lo;
                    r->lo = (t1 > t2) ? t1 : t2;
                    t1 = x->lo * y->lo;
                    t2 = x->up * y->up;
                    r->up = (t1 > t2) ? t1 : t2;
                } else {
                    r->lo = x->up * y->lo;
                    r->up = x->lo * y->lo;
                }
            } else {
                if (y->up > 0) {
                    r->lo = x->lo * y->up;
                    r->up = x->up * y->up;
                } else {
                    r->lo = -x->lo * y->lo;
                    r->up =  x->up * y->up;
                }
            }
        } else {
            if (y->lo > 0) {
                if (y->up > 0) {
                    r->lo = x->lo * y->up;
                    r->up = x->lo * y->lo;
                } else {
//                    r->lo = -x->up * y->up;
//                    r->up =  x->lo * y->lo;

                    _r = x_neg_up * _y;
                    _r = _mm_permute_pd(_r, 0b01);
                }
            } else {
                if (y->up > 0) {
//                    r->lo =  x->lo * y->up;
//                    r->up = -x->up * y->lo;
                    _r = x_neg_up * y_perm;
                } else {
                    r->lo = -x->lo * y->lo;
                    r->up =  x->up * y->up;
                }
            }
        }
    } else {
        if (x->up > 0) {
            if (y->lo > 0) {
                if (y->up > 0) {
                    r->lo = x->up * y->lo;
                    r->up = x->up * y->up;
                } else {
                    r->lo =  x->up * y->lo;
                    r->up = -x->lo * y->up;

//                    _x = _mm_xor_pd(_x, _mm_set_pd(0.0, -0.0));
//                    _x = _mm_permute_pd(_x, 0b01);
//                    _r = v * _y;
                }
            } else {
                if (y->up > 0) {
//                    r->lo = -x->lo * y->lo;
//                    r->up =  x->up * y->up;
//                    __m128d v = _mm_xor_pd(_x, _mm_set_pd(0.0, -0.0));
                    _r = x_neg_lo * _y;
                } else {
                    r->lo = -x->lo * y->lo;
                    r->up =  x->up * y->up;
                }
            }
        } else {
            r->lo = -x->lo * y->lo;
            r->up =  x->up * y->up;
        }
    }

    return _mm_or_pd(_r, nan);
}

static f64_I _ia_mul_f64_v4(f64_I xx, f64_I yy) {
    /* Less precised implementation but potentially faster */

    f64v nan = _mm_cmpunord_pd(xx,yy);
    __m128d xn01, x1n0, a, b, mxab, mnab, nmab, sw, res, r;

    xn01 = _mm_addsub_pd(_mm_setzero_pd(), xx);
    x1n0 = _mm_shuffle_pd(xn01, xn01, _MM_SHUFFLE2(0,1));
    a = _mm_mul_pd(xn01, yy);
    b = _mm_mul_pd(x1n0, yy);
    mxab = _mm_max_pd(a, b);
    mnab = _mm_min_pd(a, b);
    nmab = _mm_sub_pd(_mm_setzero_pd(), mnab);
    sw = _mm_shuffle_pd(nmab, nmab, _MM_SHUFFLE2(0,1));
    res = _mm_max_pd(mxab, sw);
    r = _mm_add_pd(res, _mm_set1_pd(DBL_MIN));

    return _mm_or_pd(r, nan);
}

static f64_I _ia_mul_f64(f64_I a, f64_I b) {
    return _ia_mul_f64_v1(a, b);
}

static f64_I _ia_div_f64(f64_I a, f64_I b) {
    u_f64i x = { .v = a };
    u_f64i y = { .v = b };

    /* Check for NaNs */
    if (isnan(x.up) || isnan(x.lo) || isnan(y.up) || isnan(y.lo)) {
        static const f64_I NaN_I = { NAN, NAN };
        return NaN_I;
    }

    u_f64i inv_y;
    if (y.up < 0.0 || -y.lo > 0.0) {
        /* Denominator does not include zero. Perform normal division */
        inv_y.lo = 1.0 / -y.up;
        inv_y.up = 1.0 / -y.lo;
    }
    else if (-y.lo < 0.0 && y.up > 0.0) {
        /* Denominator includes both, -0.0 and +0.0 */
        inv_y.lo = INFINITY;
        inv_y.up = INFINITY;
    }
    else {
        /* At least one of the limits has a zero (+0.0 or -0.0). */
        int isLoNeg = signbit(-y.lo) ? 1 : 0;
        int isUpNeg = signbit( y.up) ? 1 : 0;


        if ( isLoNeg == isUpNeg ) {
            /* Denominator only includes -0.0 or +0.0 but not both. */
            inv_y.lo = 1.0 / -y.up;
            inv_y.up = 1.0 / -y.lo;
        }
        else if ( isLoNeg && !isUpNeg ) {
            /* Denominator includes both, -0.0 and +0.0 */
            inv_y.lo =  INFINITY;
            inv_y.up =  INFINITY;
        }
        else {
            /* Denominator is malformed: [+n, -n] */
            fprintf(stderr, "Error: malformed interval\n");
            inv_y.lo =  INFINITY;
            inv_y.up =  INFINITY;
        }

    }
    return _ia_mul_f64(x.v, inv_y.v);
}

///
/// Basic operations on vectorized f32i
///
static f32_I _ia_set_f32(float lo, float up) {
    f32_I r;
    r.lo = lo;
    r.up = up;
    return r;
}

static f32_I _ia_neg_f32(f32_I x) {
    f32_I  r;
    r.up = x.lo;
    r.lo = x.up;
    return r;
}

static f32_I _ia_add_f32(f32_I x, f32_I y) {
    f32_I  r;
    r.up = x.up + y.up;
    r.lo = x.lo + y.lo;
    return r;
}

static f32_I _ia_sub_f32(f32_I x, f32_I y) {
    f32_I  r;
    r.up = x.up + y.lo;
    r.lo = x.lo + y.up;
    return r;
}

static f32_I _ia_mul_f32(f32_I x, f32_I y) {
    f32_I  r;

    float u1 =   x.up * y.up;
    float u2 =  -x.up * y.lo;
    float u3 =  -x.lo * y.up;
    float u4 =   x.lo * y.lo;
    float l1 =  -x.up * y.up;
    float l2 =   x.up * y.lo;
    float l3 =   x.lo * y.up;
    float l4 =  -x.lo * y.lo;

    float u12 = u1 > u2 ? u1 : u2;
    float u34 = u3 > u4 ? u3 : u4;
    float up  = u12 > u34 ? u12 : u34;

    float l12 = l1 > l2 ? l1 : l2;
    float l34 = l3 > l4 ? l3 : l4;
    float lo  = l12 > l34 ? l12 : l34;

    r.up = up;
    r.lo = lo;
    return r;
}

static f32_I _ia_div_f32(f32_I x, f32_I y) {

    f32_I inv_y;
    if (y.up < 0.f || -y.lo > 0.f) {
        /* Denominator does not include zero. Perform normal division */
        inv_y.lo = 1.f / -y.up;
        inv_y.up = 1.f / -y.lo;
    }
    else if (-y.lo < 0.f && y.up > 0.f) {
        /* Denominator includes both, -0.0 and +0.0 */
        inv_y.lo = INFINITY;
        inv_y.up = INFINITY;
    }
    else {
        /* At least one of the limits has a zero (+0.0 or -0.0). */
        int isLoNeg = signbit(-y.lo) ? 1 : 0;
        int isUpNeg = signbit( y.up) ? 1 : 0;


        if ( isLoNeg == isUpNeg ) {
            /* Denominator only includes -0.0 or +0.0 but not both. */
            inv_y.lo = 1.0f / -y.up;
            inv_y.up = 1.0f / -y.lo;
        }
        else if ( isLoNeg && !isUpNeg ) {
            /* Denominator includes both, -0.0 and +0.0 */
            inv_y.lo =  INFINITY;
            inv_y.up =  INFINITY;
        }
        else {
            /* Denominator is malformed: [+n, -n] */
            fprintf(stderr, "Error: malformed interval\n");
            inv_y.lo =  INFINITY;
            inv_y.up =  INFINITY;
        }

    }

    return _ia_mul_f32(x, inv_y);
}

///
/// Comparison on intervals
///
static bool_I _ia_cmplt_f64(f64_I _x, f64_I _y) {
    u_f64i x = { .v = _x};
    u_f64i y = { .v = _y};
    if ( x.up <  -y.lo ) { return TRUE_I;  }
    if (-x.lo >=  y.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmplt_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmple_f64(f64_I _x, f64_I _y) {
    u_f64i x = { .v = _x};
    u_f64i y = { .v = _y};
    if ( x.up <= -y.lo ) { return TRUE_I;  }
    if (-x.lo >   y.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmple_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpeq_f64(f64_I _x, f64_I _y) {
    u_f64i x = { .v = _x};
    u_f64i y = { .v = _y};
    if (-x.lo == x.up &&  x.up == y.up && y.up == -y.lo) { return TRUE_I; }
    if ( x.up < -y.lo || -x.lo > y.up) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpeq_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpneq_f64(f64_I _x, f64_I _y) {
    u_f64i x = { .v = _x};
    u_f64i y = { .v = _y};
    if (-x.lo == x.up && x.up == y.up && y.up == -y.lo) { return FALSE_I; }
    if ( x.up < -y.lo || -x.lo > y.up) { return TRUE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpneq_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpgt_f64(f64_I _x, f64_I _y) {
    u_f64i x = { .v = _x};
    u_f64i y = { .v = _y};
    if ( y.up <  -x.lo ) { return TRUE_I;  }
    if (-y.lo >=  x.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpgt_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpge_f64(f64_I _x, f64_I _y) {
    u_f64i x = { .v = _x};
    u_f64i y = { .v = _y};
    if ( y.up <= -x.lo ) { return TRUE_I;  }
    if (-y.lo >   x.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpge_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmplt_f32(f32_I x, f32_I y) {
    if ( x.up <  -y.lo ) { return TRUE_I;  }
    if (-x.lo >=  y.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmplt_f32\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmple_f32(f32_I x, f32_I y) {
    if ( x.up <= -y.lo ) { return TRUE_I;  }
    if (-x.lo >   y.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmple_f32\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpeq_f32(f32_I x, f32_I y) {
    if (-x.lo == x.up &&  x.up == y.up && y.up == -y.lo) { return TRUE_I; }
    if ( x.up < -y.lo || -x.lo > y.up) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpeq_f32\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpneq_f32(f32_I x, f32_I y) {
    if (-x.lo == x.up && x.up == y.up && y.up == -y.lo) { return FALSE_I; }
    if ( x.up < -y.lo || -x.lo > y.up) { return TRUE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpneq_f32\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpgt_f32(f32_I x, f32_I y){
    if ( y.up <  -x.lo ) { return TRUE_I;  }
    if (-y.lo >=  x.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpgt_f32\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpge_f32(f32_I x, f32_I y){
    if ( y.up <= -x.lo ) { return TRUE_I;  }
    if (-y.lo >   x.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpge_f32\n");
    return UNKNOWN_I;
}

///
/// Cast operations
///
static f64_I _ia_cvt_i2d(int x) {
    return _ia_set_f64(-x, x);
}

static f64_I _ia_cvt_l2d(long x) {
    return _ia_set_f64(-x, x);
}

static f32_I _ia_cvt_i2f(int x) {
    f32_I r;
    r.lo = -x;
    r.up =  x;
    return r;
}

static f32_I _ia_cvt_l2f(long x) {
    f32_I r;
    r.lo = -x;
    r.up =  x;
    return r;
}

static f64_I _ia_cvt_u2d(unsigned int x) {
    u_f64i r;
    r.lo = -((double)x);
    r.up =  x;
    return r.v;
}

static long _ia_cvt_d2l(f64_I x) {
    u_f64i r = { .v = x };
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    return (long) r.up;
}

///
/// Returns a float in the interval d. If more than one
/// float is found it will print an error.
///
static float _ia_reduce_d2f(f64_I d, double res) {
    fprintf(stderr, "Operation not supported.\n");
    return 0.0;
}

///
/// Set operations
///
static f64_I _ia_set_pointed_f64(double d) {
    return _ia_set_f64(-d,d);
}

static f64_I _ia_set_epsilon_f64(double d) {
    u_f64i r;
    r.lo = -d;
    r.up =  d + DBL_MIN;
    return r.v;
}

///
/// Special functions
///
static f64_I _ia_sqr_f64(f64_I a) {
    u_f64i res;
    res.v = _ia_mul_f64(a, a);
    if (res.lo > 0) {
        /* Lower bound is negative */
        res.lo = 0;
    }
    return res.v;
}

static f64_I _ia_fma_f64(f64_I x, f64_I y, f64_I z) {
    f64_I  r;
    fprintf(stderr, "Operation not supported.\n");
    return r;
}

static f64_I _ia_join_f64(f64_I x, f64_I y) {
    f64_I  r;
    fprintf(stderr, "Operation not supported.\n");
    return r;
}

static f64_I _ia_zero_f64() {
    return _mm_setzero_pd();
}

static f64_I _ia_one_f64() {
    return _mm_set_pd(-1.0, 1.0);
}

///
/// Auxiliary functions
///
static double _ia_get_lo_f64(f64_I a) {
    u_f64i r = { .v = a };
    return -r.lo;
}

static double _ia_get_up_f64(f64_I a) {
    u_f64i r = { .v = a };
    return r.up;
}