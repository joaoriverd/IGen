#include "atlas_lvl3.h"
#include "atlas_misc.h"
#include "igen_dd_lib.h"

#include "atlas_cacheedge.h"
void ATL_dGEMM2NN(const int M, const int N, const int K, dd_I alpha,
                  const dd_I *A, const int lda, const dd_I *B, const int ldb,
                  dd_I beta, dd_I *C, const int ldc) {
  int DOCOPY;

  static const int CE_maxK =
      (((3145728 / sizeof(dd_I)) - (56 * 56)) / (56 * (56 + 56))) * 56;

  int Kp;
  int k = K;

  dd_I ONE = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  dd_I bet = beta;

  MMINTR mm1;
  MMINTR mm2;
  MMINTR mmNC;
  if (!M || !N || !K) {
    return;
  }

  if (N >= M || (K <= 56 + 56 && M > 56 && N > 56)) {
    mm1 = ATL_dmmJIK;
    mm2 = ATL_dmmIJK;
    mmNC = ATL_dNCmmJIK;
  } else {
    mm1 = ATL_dmmIJK;
    mm2 = ATL_dmmJIK;
    mmNC = ATL_dNCmmIJK;
  }

  if ((M <= 56 || N <= 56) && ((K >> 4) > 168))

  {
    mm2 = mm1;
    mm1 = ATL_dmmJITcp;
  }

  if (K <= 168) {
    DOCOPY = M * N >= 157304 / K;

  } else {
    if (N <= 168) {
      if (M <= 168) {
        DOCOPY = M * N >= 31360 / K;
      } else {
        DOCOPY = M * N >= 5600 / K;
      }
    } else {
      if (M <= 168) {
        DOCOPY = M * N >= 5600 / K;
      } else {
        DOCOPY = M * N >= 148877 / K;
      }
    }
  }

  if (!DOCOPY) {

    if (K <= 4 && M > 40) {
      if (!ATL_dmmJKI(CblasNoTrans, CblasNoTrans, M, N, K, alpha, A, lda, B,
                      ldb, beta, C, ldc)) {
        return;
      }
    }
    mm1 = mm2 = mmNC;
  }

  Kp = ((CE_maxK) > (K) ? (K) : (CE_maxK));

  if (Kp < 56) {
    Kp = K;
  }

  if (K == Kp)

  {
    Kp = ((67108864 / sizeof(dd_I)) - 56 * 56) / (56 + 56);
    if (Kp > K || Kp < 56) {
      Kp = K;
    }
  }
  do {
    if (mm1(CblasNoTrans, CblasNoTrans, M, N, Kp, alpha, A, lda, B, ldb, bet, C,
            ldc)) {
      if (mm2(CblasNoTrans, CblasNoTrans, M, N, Kp, alpha, A, lda, B, ldb, bet,
              C, ldc)) {
        if (ATL_dmmJITcp(CblasNoTrans, CblasNoTrans, -M, N, Kp, alpha, A, lda,
                         B, ldb, bet, C, ldc)) {
          if (!(mmNC(CblasNoTrans, CblasNoTrans, M, N, Kp, alpha, A, lda, B,
                     ldb, bet, C, ldc) == 0)) {
            ATL_xerbla(0,
                       "/home/joao/Documents/repo/icompes/benchmarks/"
                       "ATLAS_gemm/atlas_source/__prep.c",
                       "assertion %s failed, line %d of file %s\n",
                       "mmNC(CblasNoTrans, CblasNoTrans, M, N, Kp, alpha, A, "
                       "lda, B, ldb, bet, C, ldc) == 0",
                       301,
                       "/home/joao/Documents/repo/icompes/benchmarks/"
                       "ATLAS_gemm/atlas_source/__prep.c");
          }
        }
      }
    };

    bet = ONE;
    A += (Kp * lda);
    B += (Kp);
    k -= Kp;
    if (Kp > k) {
      Kp = k;
    }
  } while (k);
}
