#pragma once
#include "stdio.h"
#include "igen_types.h"

///
/// Casts from interval to interval
///
static f64_I _ia_cast_f32_to_f64(f32_I x) {
    /* This is exactly representable. Thus, simply assign the endpoints as they are. */
    u_f64i r;
    r.lo = (double) x.lo;
    r.up = (double) x.up;
    return r.v;
}

static f32_I _ia_cast_f64_to_f32(f64_I x) {
    /* This will be converted into a vcvtsd2ss (x86) or fcvt (ARM). Both use the rounding mode control bits. Thus,
     * it is fine to assign endpoints directly. */
    f32_I r;
    u_f64i* _x = (u_f64i*) &x;
    r.lo = (float) _x->lo;
    r.up = (float) _x->up;
    return r;
}

///
/// Casts from integer to interval
///
static f64_I _ia_cast_int_to_f64(int x) {
    u_f64i r;
    r.lo = (double) (-x);
    r.up = (double) x;
    return r.v;
}

static f64_I _ia_cast_uint_to_f64(unsigned int x) {
    u_f64i r;
    r.lo = (double) (-x);
    r.up = (double) x;
    return r.v;
}

static f64_I _ia_cast_long_to_f64(long x) {
    u_f64i r;
    r.lo = (double) (-x);
    r.up = (double) x;
    return r.v;
}

static f64_I _ia_cast_ulong_to_f64(unsigned long x) {
    u_f64i r;
    r.lo = (double) (-x);
    r.up = (double) x;
    return r.v;
}

static f32_I _ia_cast_int_to_f32(int x) {
    f32_I r;
    r.lo = (float) (-x);
    r.up = (float) x;
    return r;
}

static f32_I _ia_cast_uint_to_f32(unsigned int x) {
    f32_I r;
    r.lo = (float) (-x);
    r.up = (float) x;
    return r;
}

static f32_I _ia_cast_long_to_f32(long x) {
    f32_I r;
    r.lo = (float) (-x);
    r.up = (float) x;
    return r;
}

static f32_I _ia_cast_ulong_to_f32(unsigned long x) {
    f32_I r;
    r.lo = (float) (-x);
    r.up = (float) x;
    return r;
}

///
/// Casts from interval to integer
///
static int _ia_cast_f64_to_int(f64_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    u_f64i* _x = (u_f64i*) &x;
    return (int) _x->up;
}

static unsigned int _ia_cast_f64_to_uint(f64_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    u_f64i* _x = (u_f64i*) &x;
    return (unsigned int) _x->up;
}

static unsigned long _ia_cast_f64_to_ulong(f64_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    u_f64i* _x = (u_f64i*) &x;
    return (unsigned long) _x->up;
}

static long _ia_cast_f64_to_long(f64_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    u_f64i* _x = (u_f64i*) &x;
    return (long) _x->up;
}

static int _ia_cast_f32_to_int(f32_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    return (int) x.up;
}

static unsigned int _ia_cast_f32_to_uint(f32_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    return (unsigned int) x.up;
}

static unsigned long _ia_cast_f32_to_ulong(f32_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    return (unsigned long) x.up;
}

static long _ia_cast_f32_to_long(f32_I x) {
    /* This is not properly supported. What is the right way to handle
     * casts from interval to scalar? */
    fprintf(stderr, "Cast from interval to scalar. Upper bound returned.\n");
    return (long) x.up;
}