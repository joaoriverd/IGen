#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <cmath>
#include <cfenv>
#include <mpfr.h>
#include "util.h"

using namespace std;

typedef union {
    struct {
        unsigned long mantissa : 52;
        unsigned int  exp      : 11;
        unsigned int  sign     : 1;
    };
    double d;
} uBitsDouble;

ostream& operator<<(ostream& out, f64_I _c) {
    u_f64i c = { .v = _c};
    out << "[" << -c.lo << ", " << c.up << "]";
    return out;
}

double getRandNum(double min, double max) {
    return (max - min) * ( (double)(rand() + 1) / (double)RAND_MAX ) + min;
}

void initArrRandom(double* a, int size, int max_val) {
    for (int i = 0; i < size; ++i) {
        a[i] = getRandNum(-max_val, max_val);
    }
}

double getRandDenormal() {
    uBitsDouble num;

    /* Subnormals have exponent zero */
    num.exp = 0b00000000000;

    /* Random sign */
    num.sign = (rand() > RAND_MAX/2 ) ? 1U : 0U;

    /* Start filling the bits of the mantissa randomly */
    for (int i = 0; i < 52; ++i) {
        num.mantissa <<= 1U;
        num.mantissa += (rand() > RAND_MAX/2 ) ? 1U : 0U;
    }

    return num.d;
}

f64_I getRandomInterval (double min, double max, double maxLength) {
    u_f64i r;

    r.up = getRandNum(min, max);
    double lower = r.up - getRandNum(0.0, maxLength);
    r.lo = - ( ( lower > min ) ? lower : min );

    return  r.v;
}

f64_I getRandomDenormalInterval (bool positive = false) {
    double t1 = getRandDenormal();
    double t2 = getRandDenormal();

    if (positive) {
        t1 = fabs(t1);
        t2 = fabs(t2);
    }

    f64_I r = _ia_set_f64(-fmin(t1, t2), fmax(t1, t2));

    return  r;
}

double getLow(f64_I a) {
    return _ia_get_lo_f64(a);
}

double getUp(f64_I a) {
    return _ia_get_up_f64(a);
}

double getCenter(f64_I _a) {
    u_f64i a = {.v = _a};
    return (a.up - a.lo) / 2.0;
}

int isInside(f64_I a, f64_I b) {
    return getLow(b) <= getLow(a) && getUp(b) >= getUp(a);
}

int isInside(double s, f64_I a) {
    return s <= getUp(a) && s >= getLow(a);
}

int isNanInterval(f64_I _a) {
    u_f64i a = {.v = _a};
    return isnan(a.up) || isnan(a.lo);
}

void seedRand () {
    srand(time(0));
}

f64_I set_epsilon_interval(double a) {
    u_f64i r;
    r.up =  nextafter(a,  INFINITY);
    r.lo = -nextafter(a, -INFINITY);
    return r.v;
}

long getCorrectBits(f64_I _x) {
    u_f64i x = {.v = _x};
    #define MPFR_HIGH_PRECISION 250
    mpfr_t xl, xu, delta;
    mpfr_init2(xl,    MPFR_HIGH_PRECISION);
    mpfr_init2(xu,    MPFR_HIGH_PRECISION);
    mpfr_init2(delta, MPFR_HIGH_PRECISION);
    mpfr_set_d(xl, -x.lo, MPFR_RNDD);
    mpfr_set_d(xu,  x.up, MPFR_RNDU);
    mpfr_sub(delta, xu, xl, MPFR_RNDU);

    long r;
    if (mpfr_zero_p(delta)) {
//        r = -1;
        r = 53;
    }
    else {
        r = mpfr_get_exp(xl) - mpfr_get_exp(delta);
    }

    mpfr_clears(xl, xu, delta, (mpfr_ptr) 0);

    return r;
}
