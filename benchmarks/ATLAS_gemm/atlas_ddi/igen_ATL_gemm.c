#include "atlas_cacheedge.h"
#include "atlas_lvl3.h"
#include "atlas_misc.h"
#include "igen_dd_lib.h"
#include <stdarg.h>
#include <stdio.h>
void ATL_dgemm(const enum CBLAS_TRANSPOSE TA, const enum CBLAS_TRANSPOSE TB,
               const int M, const int N, const int K, dd_I alpha, const dd_I *A,
               const int lda, const dd_I *B, const int ldb, dd_I beta, dd_I *C,
               const int ldc)

{
  if (!M || !N) {
    return;
  }
  dd_I _t1 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  int _t2 = (_ia_cmpeq_dd(alpha, _t1));
  int _t3 = _ia_cvt2tb(!K);
  if (_ia_or_tb(_t2, _t3)) {

    dd_I _t4 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    if (_ia_cmpeq_dd(beta, _t4)) {
      ATL_dgezero(M, N, C, ldc);
    } else {
      dd_I _t5 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
      if (_ia_cmpneq_dd(beta, _t5)) {
        ATL_dgescal_bX(M, N, beta, C, ldc);
      }
    }
    return;
  }
  if (TA == CblasNoTrans) {
    if (TB == CblasNoTrans) {
      ATL_dGEMM2NN(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

    } else {
      ATL_dGEMM2NT(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
    }
  } else {
    if (TB == CblasNoTrans) {
      ATL_dGEMM2TN(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

    } else {
      ATL_dGEMM2TT(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
    }
  }
}
