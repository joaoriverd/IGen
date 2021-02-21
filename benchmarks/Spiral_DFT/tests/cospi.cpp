#include <mpfi.h>
#include <crlibm.h>
#include <fenv.h>
#include "igen_lib.h"
#include "igen_dd_lib.h"
#include "boost_common.h"
#include "filib_common.h"
#include "gaol_common.h"
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

f64i_bst cospi(f64i_bst x) {
    f64i_bst y;
    f64_I _y;
    f64_I x_igen = _ia_set_f64(-x.lower(), x.upper());
    _y = cospi(x_igen);
    y.set(_ia_get_lo_f64(_y), _ia_get_up_f64(_y));
    return y;
}

f64i_bst sinpi(f64i_bst x) {
    f64i_bst y;
    f64_I _y;
    f64_I x_igen = _ia_set_f64(-x.lower(), x.upper());
    _y = sinpi(x_igen);
    y.set(_ia_get_lo_f64(_y), _ia_get_up_f64(_y));
    return y;
}

f64i_fil cospi(f64i_fil x) {
    f64i_fil y;
    f64_I _y;
    f64_I x_igen = _ia_set_f64(-x.inf(), x.sup());
    _y = cospi(x_igen);
    y = f64i_fil(_ia_get_lo_f64(_y), _ia_get_up_f64(_y));
    return y;
}

f64i_fil sinpi(f64i_fil x) {
    f64i_fil y;
    f64_I _y;
    f64_I x_igen = _ia_set_f64(-x.inf(), x.sup());
    _y = sinpi(x_igen);
    y = f64i_fil(_ia_get_lo_f64(_y), _ia_get_up_f64(_y));
    return y;
}

f64i_gal cospi(f64i_gal x) {
    f64i_gal y;
    f64_I _y;
    f64_I x_igen = _ia_set_f64(-x.left(), x.right());
    _y = cospi(x_igen);
    y = f64i_gal(_ia_get_lo_f64(_y), _ia_get_up_f64(_y));
    return y;
}

f64i_gal sinpi(f64i_gal x) {
    f64i_gal y;
    f64_I _y;
    f64_I x_igen = _ia_set_f64(-x.left(), x.right());
    _y = sinpi(x_igen);
    y = f64i_gal(_ia_get_lo_f64(_y), _ia_get_up_f64(_y));
    return y;
}

mpreal cospi(mpreal x) {
    mpreal r = cospi(x.toDouble());
    return r;
}

mpreal sinpi(mpreal x) {
    mpreal r = sinpi(x.toDouble());
    return r;
}