#include "igen_lib.h"
#include <iostream>
extern "C" {
#include "cblas.h"
}

#define min(x,y) (((x) < (y)) ? (x) : (y))

int dgemm_simple_ddi()
{
    dd_I *A, *B, *C;
    int m, n, k, i, j;
    dd_I alpha, beta;

    printf( "\n This example computes real matrix C=alpha*A*B+beta*C using \n"
            " cblas_dgemm, where A, B, and C are matrices and \n"
            " alpha and beta are dd_I precision scalars\n\n");

    n = 56*11;
    k = m = n;
    printf (" Initializing data for matrix multiplication C=A*B for matrix \n"
            " A(%ix%i) and matrix B(%ix%i)\n\n", m, k, k, n);
    alpha = _ia_cvt_i2dd(1); beta = _ia_cvt_i2dd(1);

    printf (" Allocating memory for matrices aligned on 64-byte boundary for better \n"
            " performance \n\n");
    A = (dd_I *)aligned_alloc(64, m*k*sizeof( dd_I ));
    B = (dd_I *)aligned_alloc(64, k*n*sizeof( dd_I ));
    C = (dd_I *)aligned_alloc(64, m*n*sizeof( dd_I ));
    if (A == NULL || B == NULL || C == NULL) {
        printf( "\n ERROR: Can't allocate memory for matrices. Aborting... \n\n");
        free(A);
        free(B);
        free(C);
        return 1;
    }

    printf (" Intializing matrix data \n\n");
    dd_I _01 = _ia_set_pointed_h_dd(0.1);
    for (i = 0; i < (m*k); i++) {
        A[i] = _ia_cvt_i2dd((i + 1));
        A[i] = _ia_add_dd(A[i], _01);
    }

    for (i = 0; i < (k*n); i++) {
        B[i] = _ia_cvt_i2dd((-i - 1));
        B[i] = _ia_add_dd(B[i], _01);
    }

    for (i = 0; i < (m*n); i++) {
        C[i] = _ia_cvt_i2dd(0);
    }

    printf (" Computing matrix product using Intel(R) MKL dgemm function via CBLAS interface \n\n");
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                m, n, k, alpha, A, k, B, n, beta, C, n);
    printf ("\n Computations completed.\n\n");

    printf (" Top left corner of matrix A: \n");
    for (i=0; i<min(m,6); i++) {
        for (j=0; j<min(k,6); j++) {
            printf ("[");
            printf ("%12.5f ", _ia_get_lo_dd(A[j+i*k]));
            printf ("%12.5f", _ia_get_up_dd(A[j+i*k]));
            printf ("]");
        }
        printf ("\n");
    }

    printf ("\n Top left corner of matrix B: \n");
    for (i=0; i<min(k,6); i++) {
        for (j=0; j<min(n,6); j++) {
            printf ("[");
            printf ("%12.5f ", _ia_get_lo_dd(B[j+i*n]));
            printf ("%12.5f" , _ia_get_up_dd(B[j+i*n]));
            printf ("]");
        }
        printf ("\n");
    }

    printf ("\n Top left corner of matrix C: \n");
    for (i=0; i<min(m,6); i++) {
        for (j=0; j<min(n,6); j++) {
            printf ("[");
            printf ("%12.5f ", _ia_get_lo_dd(C[j+i*n]));
            printf ("%12.5f" , _ia_get_up_dd(C[j+i*n]));
            printf ("]");
        }
        printf ("\n");
    }

    printf ("\n Deallocating memory \n\n");
    free(A);
    free(B);
    free(C);

    printf (" Example completed. \n\n");
    return 0;
}
