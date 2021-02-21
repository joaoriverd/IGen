#include <cfenv>
#include <iostream>
#include "igen_lib.h"
#include "igen_dd_lib.h"
#include "random_range.h"
#include "mpreal.h"

using mpfr::mpreal;

#define MPFR_PRECISION 2048
#define SIZE     (64*2)
#define NUM_RUNS 100
#define PASS     "\033[1;32mpass\033[0m"
#define FAIL     "\033[1;31mfail\033[0m"

/* Scalar DFT */
void init_DFT64(double);
void init_DFT64(f64_I);
void init_DFT64(dd_I);
void init_DFT64(mpreal);
void DFT64(double *, double*);
void DFT64(f64_I  *, f64_I *);
void DFT64(dd_I   *, dd_I  *);
void DFT64(mpreal *, mpreal*);

/* Vectorized DFT */
void init_AVX_DFT64(double);
void init_AVX_DFT64(f64_I);
void init_AVX_DFT64(dd_I);
void AVX_DFT64(double *, double*);
void AVX_DFT64(f64_I  *, f64_I *);
void AVX_DFT64(dd_I   *, dd_I  *);

enum enumVerifyTest {
    VerifyScalar = 0,
    VerifyVector
};

static __attribute__((aligned(32))) double X_dbl[SIZE];
static __attribute__((aligned(32))) double Y_dbl[SIZE];
static __attribute__((aligned(32))) f64_I  X_f64i[SIZE];
static __attribute__((aligned(32))) f64_I  Y_f64i[SIZE];
static __attribute__((aligned(32))) dd_I   X_ddi[SIZE];
static __attribute__((aligned(32))) dd_I   Y_ddi[SIZE];
static __attribute__((aligned(32))) mpreal X_mpfr[SIZE];
static __attribute__((aligned(32))) mpreal Y_mpfr[SIZE];


static mpreal dd2mpreal (double h, double l) {
    mpreal x = h;
    x += l;
    return x;
}

static u_ddi get_random_ddi() {
    fesetround(FE_UPWARD);
    double h = getRandomDouble(-5, 10, 50);
    double l = 0.0;//getRandomDouble(-58, 10, 50);
    u_ddi A_ddi;
    A_ddi.v  = _ia_set_pointed_dd(h, l);
    A_ddi.v  = _ia_add_dd(A_ddi.v, _ia_zero_dd());
    A_ddi.lh = -A_ddi.uh;
    A_ddi.ll = -A_ddi.ul;
    fesetround(FE_TONEAREST);
    return A_ddi;
}

static bool isSound(mpreal x_mpfr, u_ddi x_ddi) {
    mpreal x_ddi_l = dd2mpreal(-x_ddi.lh, -x_ddi.ll);
    mpreal x_ddi_u = dd2mpreal( x_ddi.uh,  x_ddi.ul);
    return x_ddi_l <=  x_mpfr && x_mpfr <= x_ddi_u;
}

static void verify_ia_add_dd () {
    initRandomSeed();

    for (int i = 0; i < 10000; i++) {
        u_ddi  a_ddi[16];
        mpreal a_mpfr[16];
        for (int j = 0; j < 16; j++) {
            a_ddi[j] = get_random_ddi();
            a_mpfr[j] = dd2mpreal(a_ddi[j].uh, a_ddi[j].ul);
        }

        fesetround(FE_UPWARD);
        a_ddi[0].v = _ia_add_dd(a_ddi[2*0].v, a_ddi[2*0+1].v);
        a_ddi[1].v = _ia_add_dd(a_ddi[2*1].v, a_ddi[2*1+1].v);
        a_ddi[2].v = _ia_add_dd(a_ddi[2*2].v, a_ddi[2*2+1].v);
        a_ddi[3].v = _ia_add_dd(a_ddi[2*3].v, a_ddi[2*3+1].v);
        a_ddi[4].v = _ia_add_dd(a_ddi[2*4].v, a_ddi[2*4+1].v);
        a_ddi[5].v = _ia_add_dd(a_ddi[2*5].v, a_ddi[2*5+1].v);
        a_ddi[6].v = _ia_add_dd(a_ddi[2*6].v, a_ddi[2*6+1].v);
        a_ddi[7].v = _ia_add_dd(a_ddi[2*7].v, a_ddi[2*7+1].v);

        a_ddi[0].v = _ia_add_dd(a_ddi[2*0].v, a_ddi[2*0+1].v);
        a_ddi[1].v = _ia_add_dd(a_ddi[2*1].v, a_ddi[2*1+1].v);
        a_ddi[2].v = _ia_add_dd(a_ddi[2*2].v, a_ddi[2*2+1].v);
        a_ddi[3].v = _ia_add_dd(a_ddi[2*3].v, a_ddi[2*3+1].v);

        a_ddi[0].v = _ia_add_dd(a_ddi[2*0].v, a_ddi[2*0+1].v);
        a_ddi[1].v = _ia_add_dd(a_ddi[2*1].v, a_ddi[2*1+1].v);

        a_ddi[0].v = _ia_add_dd(a_ddi[2*0].v, a_ddi[2*0+1].v);

        fesetround(FE_TONEAREST);
        a_mpfr[0] = a_mpfr[2*0] + a_mpfr[2*0+1];
        a_mpfr[1] = a_mpfr[2*1] + a_mpfr[2*1+1];
        a_mpfr[2] = a_mpfr[2*2] + a_mpfr[2*2+1];
        a_mpfr[3] = a_mpfr[2*3] + a_mpfr[2*3+1];
        a_mpfr[4] = a_mpfr[2*4] + a_mpfr[2*4+1];
        a_mpfr[5] = a_mpfr[2*5] + a_mpfr[2*5+1];
        a_mpfr[6] = a_mpfr[2*6] + a_mpfr[2*6+1];
        a_mpfr[7] = a_mpfr[2*7] + a_mpfr[2*7+1];

        a_mpfr[0] = a_mpfr[2*0] + a_mpfr[2*0+1];
        a_mpfr[1] = a_mpfr[2*1] + a_mpfr[2*1+1];
        a_mpfr[2] = a_mpfr[2*2] + a_mpfr[2*2+1];
        a_mpfr[3] = a_mpfr[2*3] + a_mpfr[2*3+1];

        a_mpfr[0] = a_mpfr[2*0] + a_mpfr[2*0+1];
        a_mpfr[1] = a_mpfr[2*1] + a_mpfr[2*1+1];

        a_mpfr[0] = a_mpfr[2*0] + a_mpfr[2*0+1];

        mpreal t1_mpfr = a_mpfr[0];
        double a_dbl_1 = t1_mpfr.toDouble();
        t1_mpfr = t1_mpfr - a_dbl_1;
        double a_dbl_2 = t1_mpfr.toDouble();
        t1_mpfr = t1_mpfr - a_dbl_2;
        double a_dbl_3 = t1_mpfr.toDouble();
        t1_mpfr = t1_mpfr - a_dbl_3;
        double a_dbl_4 = t1_mpfr.toDouble();

        if (!isSound(a_mpfr[0], a_ddi[0])) {
            std::cout <<  FAIL << std::endl;
        }
    }
}

static void init_DFT_all() {
    fesetround(FE_TONEAREST);
    double a_dbl;
    mpreal a_mpfr;
    f64_I  a_f64i;
    dd_I   a_ddi;
    init_DFT64(a_dbl);
    init_DFT64(a_mpfr);
    init_AVX_DFT64(a_dbl);

    fesetround(FE_UPWARD);
    init_DFT64(a_f64i);
    init_DFT64(a_ddi);
    init_AVX_DFT64(a_f64i);
    init_AVX_DFT64(a_ddi);
    fesetround(FE_TONEAREST);
}

static void init_DFT_input() {
    for (int i = 0; i < SIZE; ++i) {
        double r = getRandomDouble(-5, 10, 50);
        X_dbl[i]  = r;
        X_f64i[i] = _ia_set_pointed_f64(r);
        X_ddi[i]  = _ia_set_pointed_dd(r, 0);
        X_mpfr[i] = r;
    }
}

static void run_DFT(enumVerifyTest test) {
    if (test == VerifyScalar) {
        fesetround(FE_TONEAREST);
        DFT64(Y_dbl, X_dbl);
        DFT64(Y_mpfr, X_mpfr);
        fesetround(FE_UPWARD);
        DFT64(Y_f64i, X_f64i);
        DFT64(Y_ddi, X_ddi);
        fesetround(FE_TONEAREST);
    }
    else {
        fesetround(FE_TONEAREST);
        AVX_DFT64(Y_dbl, X_dbl);
        fesetround(FE_UPWARD);
        AVX_DFT64(Y_f64i, X_f64i);
        AVX_DFT64(Y_ddi, X_ddi);
        fesetround(FE_TONEAREST);
    }
}

void verify_DFT64(enumVerifyTest test) {
    std::cout << "Running sound verification " << ((test == VerifyScalar) ? "(scl)" : "(vec)") << ": ";

    initRandomSeed();
    init_DFT_all();

    for (int nr = 0; nr < NUM_RUNS; nr++) {
        init_DFT_input();
        run_DFT(test);

        /* Check that result is sound */
        for (int i = 0; i < SIZE; ++i) {
            double Y_f64i_l = _ia_get_lo_f64(Y_f64i[i]);
            double Y_f64i_u = _ia_get_up_f64(Y_f64i[i]);
            double Y_ddi_l  = _ia_get_lo_dd(Y_ddi[i]);
            double Y_ddi_u  = _ia_get_up_dd(Y_ddi[i]);
            u_ddi Y_uddi = {.v = Y_ddi[i]};

            /* Check that ddi is inside f64i result */
            if (Y_ddi_l < Y_f64i_l || Y_f64i_u < Y_ddi_u) {
                std::cout << FAIL << std::endl;
                return;
            }

            /* Check that dbl is inside f64i result */
            if (Y_dbl[i] < Y_f64i_l || Y_f64i_u < Y_dbl[i]) {
                std::cout << FAIL << std::endl;
                return;
            }

            /* Check that mpfr (high precision) is inside ddi result */
            if (test == VerifyScalar && !isSound(Y_mpfr[i], Y_uddi)) {
                std::cout << FAIL << std::endl;
                return;
            }
        }
    }

    std::cout <<  PASS << std::endl;
}

void verify_DFT64() {
    mpreal::set_default_prec(MPFR_PRECISION);
    verify_DFT64(VerifyScalar);
    verify_DFT64(VerifyVector);
}