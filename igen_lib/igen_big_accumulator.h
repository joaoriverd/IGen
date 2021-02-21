#pragma once
#include <string.h> // for memset

#define BUFFER_SIZE 2048 // Complete array with al possible exponent values of double precision

typedef union {
    unsigned long u;
    double d;
} bitDouble;

static unsigned get_exp(double a) {
    bitDouble _a;
    _a.d = a;
    _a.u = (_a.u & 0x7FFFFFFFFFFFFFFFu);
    return _a.u >> 52u;
}

static unsigned is_even (double a) {
    bitDouble _a;
    _a.d = a;
    _a.u = (_a.u & 0x01u);
    return _a.u;
}

static unsigned get_lsb (double a) {
    bitDouble _a;
    _a.d = a;
    _a.u = (_a.u & 0x01u);
    return _a.u;
}

/// Get the bucket index based on the exponent
int get_bucket_index(double d) {
    return (int) get_exp(d);
}

typedef struct {
    double even_bucket[BUFFER_SIZE];
    double odd_bucket[BUFFER_SIZE];
    /* stats */
    unsigned min_index; // = BUFFER_SIZE;
    unsigned max_index; // = 0;
} acc_f64_big_t;

void insert(acc_f64_big_t* acc, double d) {
    unsigned i = get_bucket_index(d);
    double   t = d;

    double* bucket = is_even(t) ? acc->even_bucket : acc->odd_bucket;
    while (bucket[i] != 0.0) {
        t += bucket[i];
        bucket[i] = 0.0;
        i = get_bucket_index(t);
        bucket = is_even(t) ? acc->even_bucket : acc->odd_bucket;

        /* Update info */
        acc->min_index = acc->min_index < i ? acc->min_index : i;
        acc->max_index = acc->max_index > i ? acc->max_index : i;
    }


    /* Update info */
    acc->min_index = acc->min_index < i ? acc->min_index : i;
    acc->max_index = acc->max_index > i ? acc->max_index : i;

    bucket[i] = t;
}

void init(acc_f64_big_t* acc) {
    acc->min_index = BUFFER_SIZE;
    acc->max_index = 0;
    memset(acc->even_bucket, 0, BUFFER_SIZE*sizeof(double));
    memset(acc->odd_bucket , 0, BUFFER_SIZE*sizeof(double));
}

double reduce(acc_f64_big_t* acc) {
    double sum = 0.0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        sum = sum + acc->even_bucket[i] + acc->odd_bucket[i];
    }
    return sum;
}