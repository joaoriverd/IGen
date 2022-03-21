#pragma once
#include <stdio.h>
#include <fenv.h>
#include <math.h>
#include <mpfr.h>
#include <mpfi.h>
#include "igen_dd_lib.h"

//#define DEBUG
#define MPFR_MATH_HIGH_PRECISION 150
#ifdef DEBUG
#define igen_print_error(msg) fprintf(stderr, msg);
#else
#define igen_print_error(msg)
#endif

static const u_ddi NAN_ddi = {NAN, NAN, NAN, NAN};

/// Using MPFR for double-double math libraries

static dd_I _ia_sqrt_dd(dd_I _op) {
    u_ddi* op = (u_ddi*) &_op;

    /* Check that operand is in allowed range */
    if (op->lh > 0 || op->uh < 0) {
        igen_print_error("Error: Domain error in sqrt_dd.\n");
        return NAN_ddi.v;
    }

    /* Sqrt is monotonic. Apply function directly to lower and upper bounds. */
    int rm = fegetround();
    fesetround(FE_TONEAREST);
    u_ddi res;

    /* Transform to MPFR interval */
    u_ddi x = { .v = _op };
    mpfr_t xl, xu;
    mpfr_init2(xl,    MPFR_MATH_HIGH_PRECISION);
    mpfr_init2(xu,    MPFR_MATH_HIGH_PRECISION);
    mpfr_set_d(xl, -x.lh, MPFR_RNDD);
    mpfr_set_d(xu,  x.uh, MPFR_RNDU);
    mpfr_add_d(xl, xl, -x.ll, MPFR_RNDD);
    mpfr_add_d(xu, xu,  x.ul, MPFR_RNDU);

    /* Sqrt of lower bounds */
    mpfr_sqrt(xl, xl, MPFR_RNDD);
    mpfr_sqrt(xu, xu, MPFR_RNDU);

    /* Convert to double-double */
    double r_lh, r_ll, r_uh, r_ul;
    r_lh = mpfr_get_d(xl, MPFR_RNDD);
    r_uh = mpfr_get_d(xu, MPFR_RNDU);
    mpfr_add_d(xl, xl, -r_lh, MPFR_RNDD);
    mpfr_add_d(xu, xu, -r_uh, MPFR_RNDD);
    r_ll = mpfr_get_d(xl, MPFR_RNDD);
    r_ul = mpfr_get_d(xu, MPFR_RNDU);

    res.lh = -r_lh;
    res.ll = -r_ll;
    res.uh =  r_uh;
    res.ul =  r_ul;

    mpfr_clears(xl, xu, (mpfr_ptr) 0);

    fesetround(rm);
    return res.v;
}

static dd_I _ia_abs_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_floor_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_max_dd(dd_I a, dd_I b) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_min_dd(dd_I a, dd_I b) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_ceil_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_exp_dd(dd_I _op) {
    u_ddi* op = (u_ddi*) &_op;

    /* Exp is monotonic. Apply function directly to lower and upper bounds. */
    int rm = fegetround();
    fesetround(FE_TONEAREST);
    u_ddi res;

    /* Transform to MPFR interval */
    u_ddi x = { .v = _op };
    mpfr_t xl, xu;
    mpfr_init2(xl,    MPFR_MATH_HIGH_PRECISION);
    mpfr_init2(xu,    MPFR_MATH_HIGH_PRECISION);
    mpfr_set_d(xl, -x.lh, MPFR_RNDD);
    mpfr_set_d(xu,  x.uh, MPFR_RNDU);
    mpfr_add_d(xl, xl, -x.ll, MPFR_RNDD);
    mpfr_add_d(xu, xu,  x.ul, MPFR_RNDU);

    /* Sqrt of lower bounds */
    mpfr_exp(xl, xl, MPFR_RNDD);
    mpfr_exp(xu, xu, MPFR_RNDU);

    /* Convert to double-double */
    double r_lh, r_ll, r_uh, r_ul;
    r_lh = mpfr_get_d(xl, MPFR_RNDD);
    r_uh = mpfr_get_d(xu, MPFR_RNDU);
    mpfr_add_d(xl, xl, -r_lh, MPFR_RNDD);
    mpfr_add_d(xu, xu, -r_uh, MPFR_RNDD);
    r_ll = mpfr_get_d(xl, MPFR_RNDD);
    r_ul = mpfr_get_d(xu, MPFR_RNDU);

    res.lh = -r_lh;
    res.ll = -r_ll;
    res.uh =  r_uh;
    res.ul =  r_ul;

    mpfr_clears(xl, xu, (mpfr_ptr) 0);

    fesetround(rm);
    return res.v;
}

static dd_I _ia_expm1_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_log_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_log2_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_log10_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_log1p_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_sin_dd(dd_I _op) {

    /* Sqrt is monotonic. Apply function directly to lower and upper bounds. */
    int rm = fegetround();
    fesetround(FE_TONEAREST);
    u_ddi res;

    /* Transform to MPFR interval */
    u_ddi x = { .v = _op };
    mpfr_t xl, xu;
    mpfr_init2(xl,    MPFR_MATH_HIGH_PRECISION);
    mpfr_init2(xu,    MPFR_MATH_HIGH_PRECISION);
    mpfr_set_d(xl, -x.lh, MPFR_RNDD);
    mpfr_set_d(xu,  x.uh, MPFR_RNDU);
    mpfr_add_d(xl, xl, -x.ll, MPFR_RNDD);
    mpfr_add_d(xu, xu,  x.ul, MPFR_RNDU);

    mpfi_t x_mpfi;
    x_mpfi->right = *xu;
    x_mpfi->left  = *xl;

    /* Sqrt of lower bounds */
    mpfi_sin(x_mpfi, x_mpfi);

    *xl = x_mpfi->left;
    *xu = x_mpfi->right;

    /* Convert to double-double */
    double r_lh, r_ll, r_uh, r_ul;
    r_lh = mpfr_get_d(xl, MPFR_RNDD);
    r_uh = mpfr_get_d(xu, MPFR_RNDU);
    mpfr_add_d(xl, xl, -r_lh, MPFR_RNDD);
    mpfr_add_d(xu, xu, -r_uh, MPFR_RNDD);
    r_ll = mpfr_get_d(xl, MPFR_RNDD);
    r_ul = mpfr_get_d(xu, MPFR_RNDU);

    res.lh = -r_lh;
    res.ll = -r_ll;
    res.uh =  r_uh;
    res.ul =  r_ul;

    mpfr_clears(xl, xu, (mpfr_ptr) 0);

    fesetround(rm);
    return res.v;
}

static dd_I _ia_cos_dd(dd_I _op) {
    /* Sqrt is monotonic. Apply function directly to lower and upper bounds. */
    int rm = fegetround();
    fesetround(FE_TONEAREST);
    u_ddi res;

    /* Transform to MPFR interval */
    u_ddi x = { .v = _op };
    mpfr_t xl, xu;
    mpfr_init2(xl,    MPFR_MATH_HIGH_PRECISION);
    mpfr_init2(xu,    MPFR_MATH_HIGH_PRECISION);
    mpfr_set_d(xl, -x.lh, MPFR_RNDD);
    mpfr_set_d(xu,  x.uh, MPFR_RNDU);
    mpfr_add_d(xl, xl, -x.ll, MPFR_RNDD);
    mpfr_add_d(xu, xu,  x.ul, MPFR_RNDU);

    mpfi_t x_mpfi;
    x_mpfi->right = *xu;
    x_mpfi->left  = *xl;

    /* Sqrt of lower bounds */
    mpfi_cos(x_mpfi, x_mpfi);

    *xl = x_mpfi->left;
    *xu = x_mpfi->right;

    /* Convert to double-double */
    double r_lh, r_ll, r_uh, r_ul;
    r_lh = mpfr_get_d(xl, MPFR_RNDD);
    r_uh = mpfr_get_d(xu, MPFR_RNDU);
    mpfr_add_d(xl, xl, -r_lh, MPFR_RNDD);
    mpfr_add_d(xu, xu, -r_uh, MPFR_RNDD);
    r_ll = mpfr_get_d(xl, MPFR_RNDD);
    r_ul = mpfr_get_d(xu, MPFR_RNDU);

    res.lh = -r_lh;
    res.ll = -r_ll;
    res.uh =  r_uh;
    res.ul =  r_ul;

    mpfr_clears(xl, xu, (mpfr_ptr) 0);

    fesetround(rm);
    return res.v;
}

static dd_I _ia_tan_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_asin_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_acos_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_atan_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_sinh_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}

static dd_I _ia_cosh_dd(dd_I op) {
    fprintf(stderr, "Error: Operation not supported.\n");
    return NAN_ddi.v;
}