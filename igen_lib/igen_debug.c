#include <mpfr.h>
#include <stdio.h>
#include "igen_debug.h"

#define PRECISION_DOUBLE 53

void igen_print_error(const char* msg) {
#if DEBUG
    fprintf(stderr, msg);
#endif
}

int _debug_is_around_zero (f64_I a) {
    return a.lo > 0.0 && a.up > 0.0;
}

void _debug_around_zero_f64(f64_I a) {
    if (_debug_is_around_zero(a)) {
        fprintf(stderr, "Interval is around zero. Possible lost of precision.\n");
    }
}

static long getCorrectBits(f64_I x) {
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
        r = PRECISION_DOUBLE;
    }
    else {
        r = mpfr_get_exp(xl) - mpfr_get_exp(delta);
    }
    mpfr_clears(xl, xu, delta, (mpfr_ptr) 0);

    return r;
}

long _debug_get_lost_bits(f64_I x) {
    if (_debug_is_around_zero(x)) {
        return -1;
    }
    return PRECISION_DOUBLE - getCorrectBits(x);
}

int _debug_lost_precision_f64(f64_I a) {
    static int curr_bits_lost = 2;
    int bits_lost = _debug_get_lost_bits(a);
    if (bits_lost > curr_bits_lost) {
        curr_bits_lost = bits_lost;
        fprintf(stderr, "Interval lost more than %d bits.\n", curr_bits_lost);
        return 1;
    }

    return 0;
}

int _debug_get_max_lost_bits_array(f64_I* x, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        int lost_bits = _debug_get_lost_bits(x[i]);
        if (lost_bits > max) {
            max = lost_bits;
        }
    }
    return max;
}

double _debug_get_avg_lost_bits_array(f64_I* x, int n) {
    double sum = 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
        int lost_bits = _debug_get_lost_bits(x[i]);
        if (lost_bits > 0) {
            sum += lost_bits;
            d++;
        }
    }

    return sum / d;
}