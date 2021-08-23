#include "atlas_misc.h"
#include "igen_lib.h"

#include "cblas.h"

#include "atlas_level1.h"
#include "atlas_level2.h"
#include "atlas_level3.h"

void cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TA,
                 const enum CBLAS_TRANSPOSE TB, const int M, const int N,
                 const int K, f64_I alpha, const f64_I *A, const int lda,
                 const f64_I *B, const int ldb, f64_I beta, f64_I *C,
                 const int ldc) {
  int info = 2000;

  if (M < 0) {
    info = cblas_errprn(4, info, "M cannot be less than zero 0,; is set to %d.",
                        M);
  }
  if (N < 0) {
    info = cblas_errprn(5, info, "N cannot be less than zero 0,; is set to %d.",
                        N);
  }
  if (K < 0) {
    info = cblas_errprn(6, info, "K cannot be less than zero 0,; is set to %d.",
                        K);
  }

  if (Order == CblasRowMajor) {
    if (TA == CblasNoTrans) {
      if ((lda < K) || (lda < 1)) {
        info = cblas_errprn(9, info, "lda must be >= MAX(K,1): lda=%d K=%d",
                            lda, K);
      }
    } else {
      if (TA != CblasConjTrans && TA != CblasTrans) {
        info = cblas_errprn(2, info,
                            "TransA must be %d, %d or %d, but is set to %d",
                            CblasNoTrans, CblasTrans, CblasConjTrans, TA);
      }
      if ((lda < M) || (lda < 1)) {
        info = cblas_errprn(9, info, "lda must be >= MAX(M,1): lda=%d M=%d",
                            lda, M);
      }
    }
    if (TB == CblasNoTrans) {
      if ((ldb < N) || (ldb < 1)) {
        info = cblas_errprn(11, info, "ldb must be >= MAX(N,1): ldb=%d N=%d",
                            ldb, N);
      }
    } else {
      if (TB != CblasConjTrans && TB != CblasTrans) {
        info = cblas_errprn(3, info,
                            "TransB must be %d, %d or %d, but is set to %d",
                            CblasNoTrans, CblasTrans, CblasConjTrans, TB);
      }
      if ((ldb < K) || (ldb < 1)) {
        info = cblas_errprn(11, info, "ldb must be >= MAX(K,1): ldb=%d K=%d",
                            ldb, K);
      }
    }
    if ((ldc < N) || (ldc < 1)) {
      info = cblas_errprn(14, info, "ldc must be >= MAX(N,1): ldc=%d N=%d", ldc,
                          N);
    }
  } else {
    if (Order == CblasColMajor) {
      if (TA == CblasNoTrans) {
        if ((lda < M) || (lda < 1)) {
          info = cblas_errprn(9, info, "lda must be >= MAX(M,1): lda=%d M=%d",
                              lda, M);
        }
      } else {
        if (TA != CblasConjTrans && TA != CblasTrans) {
          info = cblas_errprn(2, info,
                              "TransA must be %d, %d or %d, but is set to %d",
                              CblasNoTrans, CblasTrans, CblasConjTrans, TA);
        }
        if ((lda < K) || (lda < 1)) {
          info = cblas_errprn(9, info, "lda must be >= MAX(K,1): lda=%d K=%d",
                              lda, K);
        }
      }
      if (TB == CblasNoTrans) {
        if ((ldb < K) || (ldb < 1)) {
          info = cblas_errprn(11, info, "ldb must be >= MAX(K,1): ldb=%d K=%d",
                              ldb, K);
        }
      } else {
        if (TB != CblasConjTrans && TB != CblasTrans) {
          info = cblas_errprn(3, info,
                              "TransB must be %d, %d or %d, but is set to %d",
                              CblasNoTrans, CblasTrans, CblasConjTrans, TB);
        }
        if ((ldb < N) || (ldb < 1)) {
          info = cblas_errprn(11, info, "ldb must be >= MAX(N,1): ldb=%d N=%d",
                              ldb, N);
        }
      }
      if ((ldc < M) || (ldc < 1)) {
        info = cblas_errprn(14, info, "ldc must be >= MAX(M,1): ldc=%d M=%d",
                            ldc, M);
      }
    } else {
      info = cblas_errprn(1, info, "Order must be %d or %d, but is set to %d",
                          CblasRowMajor, CblasColMajor, Order);
    }
  }
  if (info != 2000) {
    cblas_xerbla(info, "cblas_dgemm", "");
    return;
  }

  f64_I _t1 = _ia_set_f64(-0.0, 0.0);
  int _t2 = _ia_cvt2tb(A == B && M == N && TA != TB && lda == ldb);
  int _t3 = _ia_cmpeq_f64(beta, _t1);
  if (_ia_and_tb(_t2, _t3)) {
    ATL_dsyrk(CblasUpper, (Order == CblasColMajor) ? TA : TB, N, K, alpha, A,
              lda, beta, C, ldc);
    ATL_dsyreflect(CblasUpper, N, C, ldc);
    return;
  }
  if (Order == CblasColMajor) {
    ATL_dgemm(TA, TB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
  } else {
    ATL_dgemm(TB, TA, N, M, K, alpha, B, ldb, A, lda, beta, C, ldc);
  }
}
