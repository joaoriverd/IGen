#pragma once
/// Todo: Add support for single precision

#include "igen_lib.h"
#include "igen_dd_lib.h"

/// Accumulator types
typedef dd_I acc_f64i_t;
typedef dd_I acc_f32i_t;

/// Init the accumulator
static void _isum_init_f64(acc_f64i_t* acc, f64_I a) {
    u_f64i* _a = (u_f64i*) &a;
    *acc = _ia_set_dd(_a->lo, -0.0, _a->up, 0.0);
}

/// Accumulate
static void _isum_accumulate_f64(acc_f64i_t* acc, f64_I a) {
    *acc = _ia_add_dd_f64i(*acc, a);
}

/// Final reduction
static f64_I _isum_reduce_f64(acc_f64i_t* acc) {
    u_ddi* _acc = (u_ddi*) acc;
    u_f64i r;
    r.up = _acc->uh;
    r.lo = _acc->lh;
    return r.v;
}