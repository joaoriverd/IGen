#include <mpfi.h>
#include <crlibm.h>
#include <fenv.h>
#include "igen_lib.h"
#include "igen_dd_lib.h"
#include "mpreal.h"

using mpfr::mpreal;

/* These functions should be called using round-to-nearest mode */

#define MPFI_HIGH_PRECISION 250

double cospi(double x) {
    int rm = fegetround();
    fesetround(FE_TONEAREST);
    double r = cospi_rn(x);
    fesetround(rm);
    return r;
}

double sinpi(double x) {
    int rm = fegetround();
    fesetround(FE_TONEAREST);
    double r = sinpi_rn(x);
    fesetround(rm);
    return r;
}

f64_I cospi(f64_I x) {
    return _ia_set_pointed_f64(cospi(_ia_get_up_f64(x)));
}

f64_I sinpi(f64_I x) {
    return _ia_set_pointed_f64(sinpi(_ia_get_up_f64(x)));
}

dd_I cospi(dd_I x_in) {
    return _ia_set_pointed_dd(cospi(_ia_get_up_dd(x_in)), 0.0);
}

dd_I sinpi(dd_I x_in) {
    return _ia_set_pointed_dd(sinpi(_ia_get_up_dd(x_in)), 0.0);
}

mpreal cospi(mpreal x) {
    mpreal r = cospi(x.toDouble());
    return r;
}

mpreal sinpi(mpreal x) {
    mpreal r = sinpi(x.toDouble());
    return r;
}