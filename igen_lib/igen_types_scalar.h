#pragma once

typedef struct sIntervalFloat {
    float lo;
    float up;
} f32_I;

typedef struct sIntervalDouble {
    double lo;
    double up;
} f64_I;

/* For compatibility */
typedef union {
    f64_I v;
    struct { double lo, up; };
} u_f64i;