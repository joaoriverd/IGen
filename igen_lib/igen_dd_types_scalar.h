#pragma once

#include "igen_types.h"

/* double-double type */
typedef struct {
    double h;
    double l;
} dd_t;

/* Interval double-double type */
typedef union {
    struct { dd_t lo; dd_t up; };
    struct { double lh, ll, uh, ul; };
} dd_I;

/* Interval double-double type */
typedef union {
    dd_I v;
    struct { double lh, ll, uh, ul; };
} u_ddi;