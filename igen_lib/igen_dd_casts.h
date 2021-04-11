#pragma once
#include "stdio.h"
#include "igen_dd_types.h"

///
/// Casts from interval to interval
///
static dd_I _ia_cast_f32_to_dd(f32_I x) {
    /* This is exactly representable. Thus, simply assign the endpoints as they are. */
    u_ddi r;
    r.lh = (double) x.lo;
    r.ll = 0.0;
    r.uh = (double) x.up;
    r.ul = 0.0;
    return r.v;
}

static dd_I _ia_cast_f64_to_dd(f64_I x) {
    /* This is exactly representable. Thus, simply assign the endpoints as they are. */
    u_ddi r;
    u_f64i* _x = (u_f64i*) &x;
    r.lh = _x->lo;
    r.ll = 0.0;
    r.uh = _x->up;
    r.ul = 0.0;
    return r.v;
}

static f32_I _ia_cast_dd_to_f32(dd_I x) {
    /* This will be converted into a vcvtsd2ss (x86) or fcvt (ARM). Both use the rounding mode control bits. Thus,
     * it is fine to assign endpoints directly. */
    f32_I r;
    u_ddi* _x = (u_ddi*) &x;
    r.lo = (float) _x->lh;
    r.up = (float) _x->uh;
    return r;
}

static f64_I _ia_cast_dd_to_f64(dd_I x) {
    /* This is exactly representable. Thus, simply assign the endpoints as they are. */
    u_f64i r;
    u_ddi* _x = (u_ddi*) &x;
    r.lo = _x->lh;
    r.up = _x->uh;
    return r.v;
}

///
/// Casts from integer to double-double interval
///
static dd_I _ia_cast_int_to_dd(int x) {
    u_ddi r;
    r.lh = (double) (-x);
    r.ll = 0.0;
    r.uh = (double) x;
    r.ul = 0.0;
    return r.v;
}

static dd_I _ia_cast_uint_to_dd(unsigned int x) {
    u_ddi r;
    r.lh = (double) (-x);
    r.ll = 0.0;
    r.uh = (double) x;
    r.ul = 0.0;
    return r.v;
}

static dd_I _ia_cast_long_to_dd(long x) {
    /* todo: Make this more precised.
     * This can lose some precision since long can be exactly represented in double-double
     * but not necessarily in double */
    u_ddi r;
    r.lh = (double) (-x);
    r.ll = 0.0;
    r.uh = (double) x;
    r.ul = 0.0;
    return r.v;
}

static dd_I _ia_cast_ulong_to_dd(unsigned long x) {
    /* todo: Make this more precised.
     * This can lose some precision since long can be exactly represented in double-double
     * but not necessarily in double */
    u_ddi r;
    r.lh = (double) (-x);
    r.ll = 0.0;
    r.uh = (double) x;
    r.ul = 0.0;
    return r.v;
}

///
/// Casts from double-double interval to integer
///
static int _ia_cast_dd_to_int(dd_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    u_ddi* _x = (u_ddi*) &x;
    return (int) _x->uh;
}

static unsigned int _ia_cast_dd_to_uint(dd_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    u_ddi* _x = (u_ddi*) &x;
    return (unsigned int) _x->uh;
}

static unsigned long _ia_cast_dd_to_ulong(dd_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    u_ddi* _x = (u_ddi*) &x;
    return (unsigned long) _x->uh;
}

static long _ia_cast_dd_to_long(dd_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    u_ddi* _x = (u_ddi*) &x;
    return (long) _x->uh;
}