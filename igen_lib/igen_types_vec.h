#pragma once

#include <immintrin.h>

typedef __m128d f64_I;
typedef struct { float lo, up; } f32_I;

typedef union {
    f64_I v;
    struct { double lo, up; };
} u_f64i;