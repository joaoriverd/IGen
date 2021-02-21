#pragma once

#include "immintrin.h"

typedef __m256d dd_I;

typedef union {
    dd_I v;
    struct { double lh, ll, uh, ul; };
} u_ddi;
