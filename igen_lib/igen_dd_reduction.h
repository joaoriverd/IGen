#pragma once

#include "igen_dd_lib.h"
#include "igen_big_accumulator.h"

/// Accumulator types
typedef struct {
    acc_f64_big_t up;
    acc_f64_big_t lo;
} acc_ddi_t;

/// Accumulate
static void _isum_accumulate_dd(acc_ddi_t* acc, dd_I a) {
    u_ddi* _a = (u_ddi*) &a;
    insert(&acc->up, _a->uh);
    insert(&acc->up, _a->ul);
    insert(&acc->lo, _a->lh);
    insert(&acc->lo, _a->ll);
}

/// Init the accumulator
static void _isum_init_dd(acc_ddi_t* acc, dd_I a) {
    /* Here we clean the buffers and init first value */
    init(&acc->up);
    init(&acc->lo);
    _isum_accumulate_dd(acc, a);
}

/// Final reduction
static dd_I _isum_reduce_dd(acc_ddi_t* acc) {
    dd_I sum = _ia_set_pointed_dd(0.0, 0.0);
    dd_I t1, t2, t3;

    unsigned min_index = acc->up.min_index < acc->lo.min_index ? acc->up.min_index : acc->lo.min_index;
    unsigned max_index = acc->up.max_index > acc->lo.max_index ? acc->up.max_index : acc->lo.max_index;
    for (unsigned i = min_index; i <= max_index; i++) {
        t1  = _ia_set_dd(acc->lo.even_bucket[i], -0.0, acc->up.even_bucket[i], 0.0);
        t2  = _ia_set_dd(acc->lo.odd_bucket[i] , -0.0, acc->up.odd_bucket[i] , 0.0);
        t3  = _ia_add_dd(t1, t2);
        sum = _ia_add_dd(sum, t3);
    }
    return sum;
}