#pragma once

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
                       const double  alpha, const double *A, const int lda,
                       const double *B, const int ldb, const double  beta,
                       double *C, const int ldc);

/* Declare global variables here */
static double *A, *B, *C;
static int n;
static double alpha = 1.0, beta = 1.0;

/* Add parameters of function to function call in bench */
#define func_call(f) f(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, alpha, A, n, B, n, beta, C, n)

/* initialize necessary variables */
#define initGlobalVariables(size) {  \
    int i;                           \
    n = size;                        \
    int sizeofa = n * n;             \
    int sizeofx = n * n;             \
    int sizeofy = n * n;             \
    build(A, n*n);                   \
    build(B, n*n);                   \
    build(C, n*n);                   \
                                     \
    for (i=0; i<sizeofa; i++)        \
        A[i] = i%3+1;                \
                                     \
    for (i=0; i<sizeofx; i++)        \
        B[i] = i%3+1;                \
                                     \
    for (i=0; i<sizeofy; i++)        \
        C[i] = i%3+1;                \
}

#define freeVariables() { \
      destroy(A);        \
      destroy(B);        \
      destroy(C);        \
}

/* specify formula to calculate flops */
static double getFlops() {
    return 2.0*n*n*n + 2*n*n;
}


#include "benchmark_inline.h"
