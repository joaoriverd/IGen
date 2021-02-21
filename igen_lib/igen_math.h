#pragma once
#include <stdio.h>
#include <fenv.h>
#include <math.h>
#include <crlibm.h>
#include "rem_pio2_scs.h"
#include "igen_lib.h"
/* Note: All functions here assume that the current floating point rounding mode is towards +infinity */

#define PRINT_ERRORS 1
//#define RN_TEST // Not sound

static const f64_I NaN_I = { NAN, NAN };

/// Specialized vectorized function
#if defined(IGEN_LIB_VECTORIZED)
static f64_I _ia_sqrt_f64(f64_I op) {
    static __m128d lo_neg = {-1.0, 1.0};
    static __m128d lo_eps = {DBL_MIN, 0.0};
    op = op * lo_neg;
    __m128d res = _mm_sqrt_pd(op);
    res = res * lo_neg;
    res = res + lo_eps;
    return res;
}
#else
static f64_I _ia_sqrt_f64(f64_I _op) {
#ifdef IGEN_COUNTERS
    counter_div_sc++; //hectorr
#endif
    u_f64i* op = (u_f64i*) &_op;

    /* Check that operand is in allowed range */
    if (op->lo > 0 || op->up < 0) {
        #if PRINT_ERRORS
        fprintf(stderr, "Error: Domain error in sqrt_d. \n");
        #endif
        return NaN_I;
    }

    /* Sqrt is monotonic. Apply function directly to lower and upper bounds. */
    f64_I _res;
    u_f64i* res = (u_f64i*) &_res;
    double lower;
    res->up = sqrt(op->up);
    lower   = sqrt(-op->lo);

    /* Rounding mode is set upwards by default. Thus, adjust lower bound */
#ifndef RN_TEST
    if (lower*lower == -op->lo) {
        res->lo = -lower;
    }
    else {
        res->lo = -nextafter(lower, -1.0);
    }
#else
    res->lo = -lower;
#endif

    return _res;
}
#endif

static f64_I _ia_abs_f64(f64_I _op) {
    u_f64i* op = (u_f64i*) &_op;
    f64_I _r;
    u_f64i* r = (u_f64i*) &_r;
    /* Check for NaNs */
    if (isnan(op->up) || isnan(op->lo)) {
        return NaN_I;
    }

    if (-op->lo >= 0) {
        /* op already positive */
        *r = *op;
    }
    else if (op->up <= 0) {
        /* Interval is negative */
        r->lo = op->up;
        r->up = op->lo;
    }
    else {
        /* Interval contains zero */
        r->lo = 0;
        r->up = (op->up > op->lo)? op->up : op->lo;
    }

    return _r;
}

static f64_I _ia_floor_f64(f64_I _op) {
    u_f64i* op = (u_f64i*) &_op;

    /* Floor is monotonic */
    f64_I _res;
    u_f64i* res = (u_f64i*) &_res;
    res->up =  floor( op->up);
    res->lo = -floor(-op->lo);

    return _res;
}

static f64_I _ia_max_f64(f64_I _a, f64_I _b) {
    u_f64i* a = (u_f64i*) &_a;
    u_f64i* b = (u_f64i*) &_b;

    f64_I _res;
    u_f64i* res = (u_f64i*) &_res;
    res->lo = a->lo < b->lo ? a->lo : b->lo;
    res->up = a->up > b->up ? a->up : b->up;

    return _res;
}

static f64_I _ia_min_f64(f64_I _a, f64_I _b) {
    u_f64i* a = (u_f64i*) &_a;
    u_f64i* b = (u_f64i*) &_b;

    f64_I _res;
    u_f64i* res = (u_f64i*) &_res;
    res->lo = a->lo > b->lo ? a->lo : b->lo;
    res->up = a->up < b->up ? a->up : b->up;

    return _res;
}

static f64_I _ia_ceil_f64(f64_I _op) {
    u_f64i* op = (u_f64i*) &_op;

    /* Ceil is monotonic */
    f64_I _res;
    u_f64i* res = (u_f64i*) &_res;
    res->up =  ceil( op->up);
    res->lo = -ceil(-op->lo);

    return _res;
}

static f64_I _ia_exp_f64(f64_I _op) {
#pragma STDC FENV_ACCESS ON
    fesetround(FE_TONEAREST);

    /* exp is monotonic. Apply function directly to lower and upper bounds. */
    f64_I _res;
    u_f64i* op = (u_f64i*) &_op;
    u_f64i* res = (u_f64i*) &_res;
    res->up =  exp_ru( op->up);
    res->lo = -exp_rd(-op->lo);

    fesetround(FE_UPWARD);
    return _res;
}

static f64_I _ia_expm1_f64(f64_I _op) {
#pragma STDC FENV_ACCESS ON
    fesetround(FE_TONEAREST);

    /* exp is monotonic. Apply function directly to lower and upper bounds. */
    f64_I _res;
    u_f64i* op = (u_f64i*) &_op;
    u_f64i* res = (u_f64i*) &_res;
    res->up =  expm1_ru( op->up);
    res->lo = -expm1_rd(-op->lo);

    fesetround(FE_UPWARD);
    return _res;
}

static f64_I _ia_log_f64(f64_I _op) {
    f64_I _res;
    u_f64i* op = (u_f64i*) &_op;
    u_f64i* res = (u_f64i*) &_res;

    /* Check that operand is in allowed range */
    if (op->lo > 0 || op->up < 0) {
        #if PRINT_ERRORS
        fprintf(stderr, "Error: Domain error in _ia_log_f64. \n");
        #endif
        return NaN_I;
    }

    /* Block with different floating point environment */
    {
        #pragma STDC FENV_ACCESS ON
        int rm = fegetround();
        fesetround(FE_TONEAREST);

        /* log is monotonic. Apply function directly to lower and upper bounds. */
#ifndef RN_TEST
        res->up =  log_ru( op->up);
        res->lo = -log_rd(-op->lo);
#else
        res->up =  log_rn( op->up);
        res->lo = -log_rn(-op->lo);
#endif

        fesetround(rm);
    }

    return _res;
}

static f64_I _ia_log2_f64(f64_I _op) {
    f64_I _res;
    u_f64i* op = (u_f64i*) &_op;
    u_f64i* res = (u_f64i*) &_res;

    /* Check that operand is in allowed range */
    if (op->lo > 0 || op->up < 0) {
        fprintf(stderr, "Error: log of an interval containing negative values. \n");
        f64_I inf = {INFINITY, INFINITY};
        return inf;
    }

    /* Block with different floating point environment */
    {
#pragma STDC FENV_ACCESS ON
        fesetround(FE_TONEAREST);

        /* log is monotonic. Apply function directly to lower and upper bounds. */
        res->up =  log2_ru( op->up);
        res->lo = -log2_rd(-op->lo);

        fesetround(FE_UPWARD);
    }

    return _res;
}

static f64_I _ia_log10_f64(f64_I _op) {
    f64_I _res;
    u_f64i* op = (u_f64i*) &_op;
    u_f64i* res = (u_f64i*) &_res;

    /* Check that operand is in allowed range */
    if (op->lo > 0 || op->up < 0) {
        fprintf(stderr, "Error: log of an interval containing negative values. \n");
        f64_I inf = {INFINITY, INFINITY};
        return inf;
    }

    /* Block with different floating point environment */
    {
#pragma STDC FENV_ACCESS ON
        fesetround(FE_TONEAREST);

        /* log is monotonic. Apply function directly to lower and upper bounds. */
        res->up =  log10_ru( op->up);
        res->lo = -log10_rd(-op->lo);

        fesetround(FE_UPWARD);
    }

    return _res;
}

static f64_I _ia_log1p_f64(f64_I _op) {
    f64_I _res;
    u_f64i* op = (u_f64i*) &_op;
    u_f64i* res = (u_f64i*) &_res;

    /* Check that operand is in allowed range */
    if (op->lo > 1.0 || op->up < -1.0) {
        fprintf(stderr, "Error: log of an interval containing negative values. \n");
        f64_I inf = {INFINITY, INFINITY};
        return inf;
    }

    /* Block with different floating point environment */
    {
#pragma STDC FENV_ACCESS ON
        fesetround(FE_TONEAREST);

        /* log is monotonic. Apply function directly to lower and upper bounds. */
        res->up =  log1p_ru( op->up);
        res->lo = -log1p_rd(-op->lo);

        fesetround(FE_UPWARD);
    }

    return _res;
}

static f64_I _ia_sin_f64(f64_I _op) {
    u_f64i* op = (u_f64i*) &_op;

    /* Check for NaNs */
    if (isnan(op->up) || isnan(op->lo)) {
        return NaN_I;
    }

    f64_I _r = {-1.0, 1.0};
    u_f64i* r = (u_f64i*) &_r;
    double length = op->up + op->lo;
    if (length > PI_TIMES_2) {
        f64_I ones = {1.0, 1.0};
        return ones;
    }

    /* Determine the quadrant. */
    double x_lo = -op->lo;
    double x_up =  op->up;
    unsigned int q_lo = trig_quadrant(x_lo);
    unsigned int q_up = trig_quadrant(x_up);
    double tmp1, tmp2;


    /* Block with different floating point environment */
    {
        #pragma STDC FENV_ACCESS ON
        fesetround(FE_TONEAREST);
        switch (q_lo) {
            case 0:
                switch (q_up) {
                    case 0:
                        if (length > M_PI) {
                            r->lo = -1.0;
                            r->up =  1.0;
                        }
                        else {
                            r->lo = sin_rd(x_lo);
                            r->up = sin_ru(x_up);
                        }
                        break;
                    case 1:
                        tmp1 = sin_rd(x_lo);
                        tmp2 = sin_rd(x_up);
                        r->lo = tmp1 < tmp2 ? tmp1 : tmp2;
                        r->up = 1.0;
                        break;
                    case 2:
                        r->lo = sin_rd(x_up);
                        r->up = 1.0;
                        break;
                    case 3:
                        r->lo = -1.0;
                        r->up =  1.0;
                        break;
                    default: break;
                }
                break;
            case 1:
                switch (q_up) {
                    case 0:
                        tmp1 = sin_ru(x_lo);
                        tmp2 = sin_ru(x_up);
                        r->lo = -1.0;
                        r->up = tmp1 > tmp2 ? tmp1 : tmp2;
                        break;
                    case 1:
                        if (length > M_PI) {
                            r->lo = -1.0;
                            r->up =  1.0;
                        }
                        else {
                            r->lo = sin_rd(x_up);
                            r->up = sin_ru(x_lo);
                        }
                        break;
                    case 2:
                        r->lo = sin_rd(x_up);
                        r->up = sin_ru(x_lo);
                        break;
                    case 3:
                        r->lo = -1.0;
                        r->up = sin_ru(x_lo);
                        break;
                    default: break;
                }
                break;
            case 2:
                switch (q_up) {
                    case 0:
                        r->lo = -1.0;
                        r->up = sin_ru(x_up);
                        break;
                    case 1:
                        r->lo = -1.0;
                        r->up =  1.0;
                        break;
                    case 2:
                        if (length > M_PI) {
                            r->lo = -1.0;
                            r->up =  1.0;
                        }
                        else {
                            r->lo = sin_rd(x_up);
                            r->up = sin_ru(x_lo);
                        }
                        break;
                    case 3:
                        tmp1 = sin_ru(x_lo);
                        tmp2 = sin_ru(x_up);
                        r->lo = -1.0;
                        r->up = tmp1 > tmp2 ? tmp1 : tmp2;
                        break;
                    default: break;
                }
                break;
            case 3:
                switch (q_up) {
                    case 0:
                        r->lo = sin_rd(x_lo);
                        r->up = sin_ru(x_up);
                        break;
                    case 1:
                        r->lo = sin_rd(x_lo);
                        r->up = 1.0;
                        break;
                    case 2:
                        tmp1 = sin_rd(x_lo);
                        tmp2 = sin_rd(x_up);
                        r->lo = tmp1 < tmp2 ? tmp1 : tmp2;
                        r->up = 1.0;
                        break;
                    case 3:
                        if (length > M_PI) {
                            r->lo = -1.0;
                            r->up =  1.0;
                        }
                        else {
                            r->lo = sin_rd(x_lo);
                            r->up = sin_ru(x_up);
                        }
                        break;
                    default: break;
                }
                break;
            default: break;
        }
        fesetround(FE_UPWARD);

    }


    r->lo = -r->lo;

    return _r;
}

static f64_I _ia_cos_f64(f64_I _op) {
    u_f64i* op = (u_f64i*) &_op;
    /* Temporary */
    op->up = op->up + M_PI_2;
    op->lo = op->lo - M_PI_2 + 0.000000001;

    return _ia_sin_f64(op->v);
}

static f64_I _ia_tan_f64(f64_I _op) {
    f64_I _r;
    u_f64i* op = (u_f64i*) &_op;
    u_f64i* r = (u_f64i*) &_r;

    /* Check for NaNs */
    if (isnan(op->up) || isnan(op->lo)) {
        return NaN_I;
    }

    double length = op->up + op->lo;
    if (length > M_PI) {
        f64_I inf = {INFINITY, INFINITY};
        return inf;
    }

    /* Determine the quadrant. */
    double x_lo = -op->lo;
    double x_up =  op->up;
    unsigned int q_lo = trig_quadrant(x_lo)&1;
    unsigned int q_up = trig_quadrant(x_up)&1;

    if (q_lo < q_up) {
        /* When lower bound is in q1 and upper bound in q2 */
        r->lo = -INFINITY;
        r->up =  INFINITY;
    }
    else {
        #pragma STDC FENV_ACCESS ON
        fesetround(FE_TONEAREST);
        r->lo = tan_rd(x_lo);
        r->up = tan_ru(x_up);
        fesetround(FE_UPWARD);
    }

    r->lo = -r->lo;

    return _r;
}

static f64_I _ia_asin_f64(f64_I _op) {
    f64_I _r;
    u_f64i* op = (u_f64i*) &_op;
    u_f64i* r = (u_f64i*) &_r;

    if (op->lo > 1.0 || op->up > 1.0 || op->lo < -1.0 || op->up < -1.0 ) {
        /* Argument out of range. Make interval NaN */
        #if PRINT_ERRORS
        fprintf(stderr, "Error: Domain error in _ia_asin_f64. \n");
        #endif
        return NaN_I;
    }

    double x_lo = -op->lo;
    double x_up =  op->up;
    /* Block with different floating point environment */
    {
        #pragma STDC FENV_ACCESS ON
        fesetround(FE_TONEAREST);
        r->lo = asin_rd(x_lo);
        r->up = asin_ru(x_up);
        fesetround(FE_UPWARD);
    }

    r->lo = -r->lo;
    return _r;
}

static f64_I _ia_acos_f64(f64_I _op) {

    return _op;
}

static f64_I _ia_atan_f64(f64_I _op) {
    f64_I _r;
    u_f64i* op = (u_f64i*) &_op;
    u_f64i* r = (u_f64i*) &_r;

    double x_lo = -op->lo;
    double x_up =  op->up;
    /* Block with different floating point environment */
    {
        #pragma STDC FENV_ACCESS ON
        fesetround(FE_TONEAREST);
        r->lo = atan_rd(x_lo);
        r->up = atan_ru(x_up);
        fesetround(FE_UPWARD);
    }

    r->lo = -r->lo;
    return _r;
}

static f64_I _ia_sinh_f64(f64_I _op) {
    #pragma STDC FENV_ACCESS ON
    fesetround(FE_TONEAREST);

    /* sinh is monotonic. Apply function directly to lower and upper bounds. */
    f64_I _res;
    u_f64i* op  = (u_f64i*) &_op;
    u_f64i* res = (u_f64i*) &_res;
    res->up =  sinh_ru(op->up);
    res->lo = -sinh_rd(-op->lo);

    fesetround(FE_UPWARD);
    return _res;
}

static f64_I _ia_cosh_f64(f64_I _op) {
    #pragma STDC FENV_ACCESS ON
    fesetround(FE_TONEAREST);

    f64_I _res;
    u_f64i* op  = (u_f64i*) &_op;
    u_f64i* res = (u_f64i*) &_res;

    /* Case distinction depending on monotonic region of the interval */
    if (op->lo < 0) {

        /* The interval is in a monotonic increasing regions. */
        res->up =  cosh_ru( op->up);
        res->lo = -cosh_rd(-op->lo);

    }
    else if (op->up < 0){

        /* The interval is in a monotonic decreasing regions. */
        res->up =  cosh_ru(-op->lo);
        res->lo = -cosh_rd( op->up);

    }
    else {

        /* Input interval contains zero */
        double op_up = (op->up > op->lo) ? op->up : op->lo;
        res->up = cosh_ru(op_up);
        res->lo = -1.0;

    }

    fesetround(FE_UPWARD);
    return _res;
}

///
/// Single-precision intervals
///
static f32_I _ia_sqrt_f32(f32_I op) {

    /* Check that operand is in allowed range */
    if (op.lo > 0 || op.up < 0) {
        fprintf(stderr, "Error: sqrt of an interval containing negative values. \n");
        f32_I inf = {INFINITY, INFINITY};
        return inf;
    }

    /* Sqrt is monotonic. Apply function directly to lower and upper bounds. */
    f32_I res;
    float lower;
    res.up = sqrtf(op.up);
    lower = sqrtf(-op.lo);

    /* Rounding mode is set upwards by default. Thus, adjust lower bound */
    if (lower*lower == -op.lo) {
        res.lo = -lower;
    }
    else {
        res.lo = -nextafterf(lower, -1.0f);
    }

    return res;
}

static f32_I _ia_abs_f32(f32_I op) {

    f32_I r;
    if (-op.lo >= 0) {
        /* op already positive */
        r = op;
    }
    else if (op.up <= 0) {
        /* Interval is negative */
        r.lo = op.up;
        r.up = op.lo;
    }
    else {
        /* Interval contains zero */
        r.lo = 0;
        r.up = (op.up > op.lo)? op.up : op.lo;
    }

    return r;
}

static f32_I _ia_floor_f32(f32_I op) {

    /* Floor is monotonic */
    f32_I res;
    res.up =  floorf( op.up);
    res.lo = -floorf(-op.lo);

    return res;
}

static f32_I _ia_ceil_f32(f32_I op) {

    /* Ceil is monotonic */
    f32_I res;
    res.up =  ceilf( op.up);
    res.lo = -ceilf(-op.lo);

    return res;
}

static f32_I _ia_exp_f32(f32_I op) {
    fprintf(stderr, "Error: _ia_exp_f32 not supported yet.\n");
    return op;
}

static f32_I _ia_log_f32(f32_I op) {
    fprintf(stderr, "Error: _ia_log_f32 not supported yet.\n");
    return op;
}

static f32_I _ia_sin_f32(f32_I op) {
    fprintf(stderr, "Error: _ia_sin_f32 not supported yet.\n");
    return op;
}

static f32_I _ia_cos_f32(f32_I op) {
    fprintf(stderr, "Error: _ia_cos_f32 not supported yet.\n");
    return op;
}

static f32_I _ia_tan_f32(f32_I op) {
    fprintf(stderr, "Error: _ia_tan_f32 not supported yet.\n");
    return op;
}

static f32_I _ia_asin_f32(f32_I op) {
    fprintf(stderr, "Error: _ia_asin_f32 not supported yet.\n");
    return op;
}

static f32_I _ia_acos_f32(f32_I op) {
    fprintf(stderr, "Error: _ia_acos_f32 not supported yet.\n");
    return op;
}

static f32_I _ia_atan_f32(f32_I op) {
    fprintf(stderr, "Error: _ia_atan_f32 not supported yet.\n");
    return op;
}

/* Todo: Make these functions portable for different archs. ( Some architectures may nos support 64-bit long (or even 32 bits) */
/* Todo: check if it is possible to reduce precision of rem_pio2_scs to only compute r[0] (integer part) correctly */