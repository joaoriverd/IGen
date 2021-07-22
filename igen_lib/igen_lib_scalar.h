#pragma once
#include <stdio.h>
#include <math.h>
#include <float.h>
#include "igen_types_scalar.h"
#include "igen_logic.h"
#include "igen_casts.h"

#ifdef DEBUG_MODE
#include "igen_debug.h"
#endif

///
/// Basic operations
///
static f32_I _ia_neg_f32(f32_I x) {
    f32_I  r;
    r.up = x.lo;
    r.lo = x.up;
    return r;
}

static f64_I _ia_neg_f64(f64_I x) {
    f64_I  r;
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

static f64_I _ia_add_f64(f64_I x, f64_I y) {
    f64_I  r;
    r.up = x.up + y.up;
    r.lo = x.lo + y.lo;

#ifdef DEBUG_MODE
    _debug_around_zero_f64(r);
    _debug_lost_precision_f64(r);
#endif

    return r;
}

static f32_I _ia_sub_f32(f32_I x, f32_I y) {
    f32_I  r;
    r.up = x.up + y.lo;
    r.lo = x.lo + y.up;
    return r;
}

static f64_I _ia_sub_f64(f64_I x, f64_I y) {
    f64_I  r;
    r.up = x.up + y.lo;
    r.lo = x.lo + y.up;

#ifdef DEBUG_MODE
    _debug_around_zero_f64(r);
    _debug_lost_precision_f64(r);
#endif

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

static f64_I _ia_mul_f64_v1(f64_I x, f64_I y) {
    f64_I  r;

    double u1 =   x.up * y.up;
    double u2 =  -x.up * y.lo;
    double u3 =  -x.lo * y.up;
    double u4 =   x.lo * y.lo;
    double l1 =  -x.up * y.up;
    double l2 =   x.up * y.lo;
    double l3 =   x.lo * y.up;
    double l4 =  -x.lo * y.lo;

    double u12 = u1 > u2 ? u1 : u2;
    double u34 = u3 > u4 ? u3 : u4;
    double up  = u12 > u34 ? u12 : u34;

    double l12 = l1 > l2 ? l1 : l2;
    double l34 = l3 > l4 ? l3 : l4;
    double lo  = l12 > l34 ? l12 : l34;

    r.up = up;
    r.lo = lo;
    return r;
}

static f64_I _ia_mul_f64_v2(f64_I x, f64_I y) {
    f64_I r;
    static const f64_I NaN_I = { NAN, NAN };

    if (x.lo <= 0) {                  // x >= 0
        if (y.lo <= 0.0) {            // y >= 0
            r.lo = -x.lo * y.lo;      // r.lo = x.lo *< y.lo
            r.up =  x.up * y.up;      // r.up = x.up *> y.up
        }
        else if (y.up <=0.0) {        // y <= 0
            r.lo =  x.up * y.lo;      // r.lo = x.up *< y.lo
            r.up = -x.lo * y.up;      // r.up = x.lo *> y.up
        }
        else {                        // 0 in y
            /* Check for NaN */
            if (isnan(x.lo)) {
                return NaN_I;
            }

            r.lo = x.up * y.lo;       // r.lo = x.up *< y.lo
            r.up = x.up * y.up;       // r.up = x.up *< y.up;
        }
    }
    else if (x.up <= 0.0) {           // x <= 0
        if (y.lo <= 0.0) {            // y >= 0
            r.lo =  x.lo * y.up;      // r.lo = x.lo *< y.up
            r.up = -x.up * y.lo;      // r.up = x.up *> y.lo
        }
        else if (y.up <=0.0) {        // y <= 0
            r.lo = -x.up * y.up;      // r.lo = x.up *< y.up
            r.up =  x.lo * y.lo;      // r.up = x.lo *> y.lo
        }
        else {                        // 0 in y
            /* Check for NaN */
            if (isnan(x.up)) {
                return NaN_I;
            }
            r.lo = x.lo * y.up;       // r.lo = x.lo *<= y.up
            r.up = x.lo * y.lo;       // r.up = x.lo *> y.lo
        }
    }
    else {                            // 0 in x
        if (y.lo <= 0.0) {            // y >= 0
            /* Check for NaN */
            if (isnan(y.lo)) {
                return NaN_I;
            }
            r.lo = x.lo * y.up;       // r.lo = x.lo *< y.up
            r.up = x.up * y.up;       // r.up = x.up *> y.up
        }
        else if (y.up <=0.0) {        // y <= 0
            /* Check for NaN */
            if (isnan(y.up)) {
                return NaN_I;
            }
            r.lo = x.up * y.lo;       // r.lo = x.up *< y.lo
            r.up = x.lo * y.lo;       // r.up = x.lo *> y.lo
        }
        else {
            double t1, t2;
            /* Check for NaNs */
            if (isnan(x.up) || isnan(x.lo) || isnan(y.up) || isnan(y.lo)) {
                static const f64_I NaN_I = { NAN, NAN };
                return NaN_I;
            }

            t1 = x.lo * y.up;
            t2 = x.up * y.lo;
            r.lo = (t1 > t2) ? t1 : t2;
            t1 = x.lo * y.lo;
            t2 = x.up * y.up;
            r.up = (t1 > t2) ? t1 : t2;
        }
    }

    return r;
}

static f64_I _ia_mul_f64_v3(f64_I x, f64_I y) {
    f64_I  r;

    /* Check for NaNs */
    if (isnan(x.up) || isnan(x.lo) || isnan(y.up) || isnan(y.lo)) {
        static const f64_I NaN_I = { NAN, NAN };
        return NaN_I;
    }

    if (x.lo > 0) {
        if (x.up > 0) {
            if (y.lo > 0) {
                if (y.up > 0) {
                    double t1, t2;
                    t1 = x.lo * y.up;
                    t2 = x.up * y.lo;
                    r.lo = (t1 > t2) ? t1 : t2;
                    t1 = x.lo * y.lo;
                    t2 = x.up * y.up;
                    r.up = (t1 > t2) ? t1 : t2;
                } else {
                    r.lo = x.up * y.lo;
                    r.up = x.lo * y.lo;
                }
            } else {
                if (y.up > 0) {
                    r.lo = x.lo * y.up;
                    r.up = x.up * y.up;
                } else {
                    r.lo = -x.lo * y.lo;
                    r.up =  x.up * y.up;
                }
            }
        } else {
            if (y.lo > 0) {
                if (y.up > 0) {
                    r.lo = x.lo * y.up;
                    r.up = x.lo * y.lo;
                } else {
                    r.lo = -x.up * y.up;
                    r.up =  x.lo * y.lo;
                }
            } else {
                if (y.up > 0) {
                    r.lo =  x.lo * y.up;
                    r.up = -x.up * y.lo;
                } else {
                    r.lo = -x.lo * y.lo;
                    r.up =  x.up * y.up;
                }
            }
        }
    } else {
        if (x.up > 0) {
            if (y.lo > 0) {
                if (y.up > 0) {
                    r.lo = x.up * y.lo;
                    r.up = x.up * y.up;
                } else {
                    r.lo =  x.up * y.lo;
                    r.up = -x.lo * y.up;
                }
            } else {
                if (y.up > 0) {
                    r.lo = -x.lo * y.lo;
                    r.up =  x.up * y.up;
                } else {
                    r.lo = -x.lo * y.lo;
                    r.up =  x.up * y.up;
                }
            }
        } else {
            r.lo = -x.lo * y.lo;
            r.up =  x.up * y.up;
        }
    }

#ifdef DEBUG_MODE
    _debug_around_zero_f64(r);
    _debug_lost_precision_f64(r);
#endif

    return r;
}

static f64_I _ia_mul_f64(f64_I x, f64_I y) {
    return _ia_mul_f64_v1(x, y);
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

static f64_I _ia_div_f64(f64_I x, f64_I y) {

    /* Check for NaNs */
    static const f64_I NaN_I = { NAN, NAN };
    if (isnan(x.up) || isnan(x.lo) || isnan(y.up) || isnan(y.lo)) {
        return NaN_I;
    }

    f64_I inv_y;
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

            /* Check that nominator does not include zero */
            if (-x.lo <= 0.0 && x.up >= 0.0) {
                return NaN_I;
            }
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

    return _ia_mul_f64(x, inv_y);
}

///
/// Comparison on intervals
///
static bool_I _ia_cmplt_f64(f64_I x, f64_I y) {
    if ( x.up <  -y.lo ) { return TRUE_I;  }
    if (-x.lo >=  y.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmplt_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmple_f64(f64_I x, f64_I y) {
    if ( x.up <= -y.lo ) { return TRUE_I;  }
    if (-x.lo >   y.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmple_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpeq_f64(f64_I x, f64_I y) {
    if (-x.lo == x.up &&  x.up == y.up && y.up == -y.lo) { return TRUE_I; }
    if ( x.up < -y.lo || -x.lo > y.up) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpeq_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpneq_f64(f64_I x, f64_I y) {
    if (-x.lo == x.up && x.up == y.up && y.up == -y.lo) { return FALSE_I; }
    if ( x.up < -y.lo || -x.lo > y.up) { return TRUE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpneq_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpgt_f64(f64_I x, f64_I y){
    if ( y.up <  -x.lo ) { return TRUE_I;  }
    if (-y.lo >=  x.up ) { return FALSE_I; }
    fprintf(stderr, "Error: Unknown state in _ia_cmpgt_f64\n");
    return UNKNOWN_I;
}

static bool_I _ia_cmpge_f64(f64_I x, f64_I y){
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
/// Returns a float in the interval d. If more than one
/// float is found it will print an error.
///
static float _ia_reduce_d2f(f64_I d, double res) {
    /* First negate to force the rounding to be in the other direction. */
    float lo = (float) (-d.lo);
    float up = (float) (-d.up);

    if (lo != up) {
        fprintf(stderr, "More than one float in double-precision interval\n");
    }

    return lo;
}

///
/// Set operations
///
static f64_I _ia_set_f64(double lo, double up) {
    f64_I r;
    r.lo = lo;
    r.up = up;
    return r;
}

static f32_I _ia_set_f32(float lo, float up) {
    f32_I r;
    r.lo = lo;
    r.up = up;
    return r;
}

static f64_I _ia_set_pointed_f64(double d) {
    f64_I r;
    r.lo = -d;
    r.up =  d;
    return r;
}

static f64_I _ia_set_epsilon_f64(double d) {
    f64_I r;
    r.lo = -d;
    r.up =  d + DBL_MIN;
    return r;
}

///
/// Special functions
///
static f64_I _ia_sqr_f64(f64_I a) {
    f64_I res = _ia_mul_f64(a, a);
    if (res.lo > 0) {
        /* Lower bound is negative */
        res.lo = 0;
    }
    return res;
}

static f64_I _ia_fma_f64(f64_I x, f64_I y, f64_I z) {
    f64_I  r;

    /* Check for NaNs */
    if (isnan(x.up) || isnan(x.lo) || isnan(y.up) || isnan(y.lo)) {
        static const f64_I NaN_I = { NAN, NAN };
        return NaN_I;
    }

    if (x.lo > 0) {
        if (x.up > 0) {
            if (y.lo > 0) {
                if (y.up > 0) {
                    double t1, t2;
                    t1 = x.lo * y.up;
                    t2 = x.up * y.lo;
                    r.lo = (t1 > t2) ? t1 : t2;
                    t1 = x.lo * y.lo;
                    t2 = x.up * y.up;
                    r.up = (t1 > t2) ? t1 : t2;

                    r.lo += z.lo;
                    r.up += z.up;
                } else {
                    r.lo = fma(x.up, y.lo, z.lo);
                    r.up = fma(x.lo, y.lo, z.up);
                }
            } else {
                if (y.up > 0) {
                    r.lo = fma(x.lo, y.up, z.lo);
                    r.up = fma(x.up, y.up, z.up);
                } else {
                    r.lo = fma(-x.lo, y.lo, z.lo);
                    r.up = fma( x.up, y.up, z.up);
                }
            }
        } else {
            if (y.lo > 0) {
                if (y.up > 0) {
                    r.lo = fma(x.lo, y.up, z.lo);
                    r.up = fma(x.lo, y.lo, z.up);
                } else {
                    r.lo = fma(-x.up, y.up, z.lo);
                    r.up = fma( x.lo, y.lo, z.up);
                }
            } else {
                if (y.up > 0) {
                    r.lo = fma( x.lo, y.up, z.lo);
                    r.up = fma(-x.up, y.lo, z.up);
                } else {
                    r.lo = fma(-x.lo, y.lo, z.lo);
                    r.up = fma( x.up, y.up, z.up);
                }
            }
        }
    } else {
        if (x.up > 0) {
            if (y.lo > 0) {
                if (y.up > 0) {
                    r.lo = fma(x.up, y.lo, z.lo);
                    r.up = fma(x.up, y.up, z.up);
                } else {
                    r.lo = fma( x.up, y.lo, z.lo);
                    r.up = fma(-x.lo, y.up, z.up);
                }
            } else {
                if (y.up > 0) {
                    r.lo = fma(-x.lo, y.lo, z.lo);
                    r.up = fma( x.up, y.up, z.up);
                } else {
                    r.lo = fma(-x.lo, y.lo, z.lo);
                    r.up = fma( x.up, y.up, z.up);
                }
            }
        } else {
            r.lo = fma(-x.lo, y.lo, z.lo);
            r.up = fma( x.up, y.up, z.up);
        }
    }

#ifdef DEBUG_MODE
    _debug_around_zero_f64(r);
    _debug_lost_precision_f64(r);
#endif

    return r;
}

static f64_I _ia_join_f64(f64_I x, f64_I y) {
    f64_I  r;
    r.up = x.up > y.up ? x.up : y.up;
    r.lo = x.lo > y.lo ? x.lo : y.lo;
    return r;
}

static f64_I _ia_zero_f64() {
    f64_I r = {-0.0, 0.0};
    return r;
}

static f64_I _ia_one_f64() {
    f64_I r = {-1.0, 1.0};
    return r;
}

///
/// Auxiliary functions
///
static double _ia_get_lo_f64(f64_I a) {
    return -a.lo;
}

static double _ia_get_up_f64(f64_I a) {
    return a.up;
}