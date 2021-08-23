#pragma once

#include "util.h"

///
/// This is a configuration file for benchmark.cpp only. Do not include in your project.
///

#define NUMREP          30
#define CYCLES_REQUIRED 1e7
#define CONFIG_FLOAT    double
#define ALIGN           32 // for vectorized code

/* Edit the signature of the functions to bench accordingly */
typedef void (*funPtr)(const enum CBLAS_ORDER Order,
                       const enum CBLAS_TRANSPOSE TA, const enum CBLAS_TRANSPOSE TB,
                       const int M, const int N, const int K,
                       const f64_I  alpha, const f64_I *A, const int lda,
                       const f64_I *B, const int ldb, const f64_I  beta,
                       f64_I *C, const int ldc);

/* Declare global variables here */
static f64_I *A, *B, *C;
static int n;
static f64_I alpha, beta;

/* Add parameters of function to function call in bench */
#define func_call(f) f(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, alpha, A, n, B, n, beta, C, n)

/* initialize necessary variables */
#define initGlobalVariables(size) {        \
    int i;                                 \
    n = size;                              \
    int sizeofa = n * n;                   \
    int sizeofx = n * n;                   \
    int sizeofy = n * n;                   \
    build(A, n*n);                         \
    build(B, n*n);                         \
    build(C, n*n);                         \
                                           \
    for (i=0; i<sizeofa; i++) {            \
          double r = getRandNum(-10, 10);  \
          A[i] = _ia_set_epsilon_f64(r);   \
    }                                      \
                                           \
    for (i=0; i<sizeofx; i++) {            \
          double r = getRandNum(-10, 10);  \
          B[i] = _ia_set_epsilon_f64(r);   \
    }                                      \
                                           \
    for (i=0; i<sizeofy; i++) {            \
          double r = getRandNum(-10, 10);  \
          C[i] = _ia_set_epsilon_f64(r);   \
    }                                      \
                                           \
    alpha = _ia_cast_int_to_f64(1);        \
    beta  = _ia_cast_int_to_f64(1);        \
}

#define freeVariables() { \
      destroy(A);        \
      destroy(B);        \
      destroy(C);        \
}

/* specify formula to calculate flops */
static double getFlops() {
    return (2.0*n*n*n + 2*n*n);
}


#include "benchmark_inline.h"