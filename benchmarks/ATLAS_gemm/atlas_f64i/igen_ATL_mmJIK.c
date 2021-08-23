#include "atlas_lvl3.h"
#include "atlas_misc.h"
#include "igen_lib.h"
#include <stdlib.h>
void ATL_dmmJIK2(int K, int nMb, int nNb, int nKb, int ib, int jb, int kb,
                 f64_I alpha, const f64_I *pA0, const f64_I *B, int ldb,
                 f64_I *pB0, int incB, MAT2BLK B2blk, f64_I beta, f64_I *C,
                 int ldc, f64_I *pC, PUTBLK putblk, NBMM0 NBmm0) {
  const int incK = ((K)*56);
  const int incC = ((ldc - nMb) * 56);
  f64_I _t1 = _ia_set_f64(-0.0, 0.0);
  int _t2 = _ia_cvt2tb((putblk == ((void *)0)));
  int _t3 = (_ia_cmpeq_f64(beta, _t1));
  const int ZEROC = (_ia_and_tb(_t2, _t3));
  int i;
  int j = nNb;
  int ldpc;
  const f64_I *pA = pA0;
  f64_I _t4 = _ia_set_f64(-0.0, 0.0);
  f64_I cubeta = (putblk) ? _t4 : beta;
  f64_I *pB = pB0;
  f64_I *stB = pB0 + ((nKb)*3136);

  if (putblk) {
    ldpc = 56;
    if (!nKb && kb) {
      ATL_dgezero(56, 56, pC, 56);
    }
  } else {
    ldpc = ldc;
  }

  if (nNb) {
    do {
      if (B) {
        B2blk(K, 56, B, ldb, pB, alpha);
        B += incB;
      }
      if (nMb) {
        i = nMb;
        do {
          if (nKb) {
            f64_I _t5 = _ia_set_f64(-1.0, 1.0);
            NBmm0(56, 56, 56, _t5, pA, 56, pB, 56, beta, pC, ldpc);
            pA += 3136;
            pB += 3136;
            if (nKb != 1) {
              do {
                f64_I _t6 = _ia_set_f64(-1.0, 1.0);
                f64_I _t7 = _ia_set_f64(-1.0, 1.0);
                ATL_dJIK56x56x56TN56x56x0_a1_b1(56, 56, 56, _t6, pA, 56, pB, 56,
                                                _t7, pC, ldpc);
                pA += 3136;
                pB += 3136;
              } while (pB != stB);
            }
            if (kb) {
              f64_I _t8 = _ia_set_f64(-1.0, 1.0);
              f64_I _t9 = _ia_set_f64(-1.0, 1.0);
              ATL_dpKBmm(56, 56, kb, _t8, pA, kb, pB, kb, _t9, pC, ldpc);
              pA += ((kb)*56);
            }
          } else {
            if (ZEROC) {
              ATL_dgezero(56, 56, pC, ldpc);
            }
            if (kb) {
              f64_I _t10 = _ia_set_f64(-1.0, 1.0);
              ATL_dpKBmm(56, 56, kb, _t10, pA, kb, pB, kb, cubeta, pC, ldpc);
              pA += ((kb)*56);
            }
          }
          pB = pB0;
          if (putblk) {
            putblk(56, 56, pC, C, ldc, beta);
          } else {
            pC += 56;
          }
          C += 56;
        } while (--i);
      }
      if (ib) {
        if (putblk) {
          f64_I _t11 = _ia_set_f64(-0.0, 0.0);
          ATL_dIBNBmm(ib, K, pA, pB, _t11, pC, ib);
          putblk(ib, 56, pC, C, ldc, beta);
        } else {
          ATL_dIBNBmm(ib, K, pA, pB, beta, C, ldc);
        }
      }
      if (!B) {
        pB0 += incK;
        pB = pB0;
        stB += incK;
      }
      C += incC;
      if (!putblk) {
        pC = C;
      }
      pA = pA0;
    } while (--j);
  }
  if (jb) {
    if (B) {
      B2blk(K, jb, B, ldb, pB, alpha);
    }
    for (i = nMb; i; i--) {
      ATL_dMBJBmm(jb, K, pA, pB, cubeta, pC, ldpc);
      if (putblk) {
        putblk(56, jb, pC, C, ldc, beta);
      } else {
        pC += 56;
      }
      pA += incK;
      C += 56;
    }
    if (ib) {
      if (putblk) {
        f64_I _t12 = _ia_set_f64(-0.0, 0.0);
        ATL_dIBJBmm(ib, jb, K, pA, pB, _t12, pC, ib);
        putblk(ib, jb, pC, C, ldc, beta);
      } else {
        ATL_dIBJBmm(ib, jb, K, pA, pB, beta, C, ldc);
      }
    }
  }
}

int ATL_dmmJIK(const enum CBLAS_TRANSPOSE TA, const enum CBLAS_TRANSPOSE TB,
               const int M0, const int N, const int K, f64_I alpha,
               const f64_I *A, const int lda0, const f64_I *B, const int ldb0,
               f64_I beta, f64_I *C, const int ldc0)

{
  int M = M0;
  int nMb;
  int nNb;
  int nKb;
  int ib;
  int jb;
  int kb;
  int ib2;
  int h;
  int i;
  int j;
  int k;
  int m;
  int n;
  const size_t lda = lda0;
  const size_t ldb = ldb0;
  const size_t ldc = ldc0;
  const size_t incK = (((unsigned long)K) * 56);
  size_t incA;
  size_t incB;
  size_t incC;
  void *vB = ((void *)0);
  void *vC = ((void *)0);
  f64_I *pA;
  f64_I *pB;
  f64_I *pC;
  MAT2BLK A2blk;
  MAT2BLK B2blk;
  PUTBLK putblk;
  NBMM0 NBmm0;

  nMb = ((M) / 56);
  nNb = ((N) / 56);
  nKb = ((K) / 56);
  ib = M - ((nMb)*56);
  jb = N - ((nNb)*56);
  kb = K - ((nKb)*56);

  if (nKb < 12) {
    putblk = ((void *)0);
    pC = C;
    f64_I _t13 = _ia_set_f64(-1.0, 1.0);
    if ((_ia_cmpeq_f64(beta, _t13))) {
      NBmm0 = ATL_dJIK56x56x56TN56x56x0_a1_b1;
    } else {
      f64_I _t14 = _ia_set_f64(-0.0, 0.0);
      if ((_ia_cmpeq_f64(beta, _t14))) {
        NBmm0 = ATL_dJIK56x56x56TN56x56x0_a1_b0;
      } else {
        NBmm0 = ATL_dJIK56x56x56TN56x56x0_a1_bX;
      }
    }
  } else {
    NBmm0 = ATL_dJIK56x56x56TN56x56x0_a1_b0;
    vC = aligned_alloc(64, (((((unsigned long)(3136))) * sizeof(f64_I))) + 32);
    if (!vC) {
      int _ret;
      _ret = (-1);
      return _ret;
    }
    pC = (vC);
    f64_I _t15 = _ia_set_f64(-1.0, 1.0);
    if ((_ia_cmpeq_f64(beta, _t15))) {
      putblk = ATL_dputblk_b1;
    } else {
      f64_I _t16 = _ia_set_f64(-0.0, 0.0);
      if ((_ia_cmpeq_f64(beta, _t16))) {
        putblk = ATL_dputblk_b0;
      } else {
        f64_I _t17 = _ia_set_f64(1.0, -1.0);
        if ((_ia_cmpeq_f64(beta, _t17))) {
          putblk = ATL_dputblk_bn1;
        } else {
          putblk = ATL_dputblk_bX;
        }
      }
    }
  }

  if (K == 56 && TA == CblasTrans && lda == 56 &&
      ((((unsigned long)(A)) >> 5) << 5 == (unsigned long)(A))) {
    pA = (f64_I *)A;
    f64_I _t18 = _ia_set_f64(-1.0, 1.0);
    int _t19 = _ia_cvt2tb(TB == CblasNoTrans && ldb == 56);
    int _t20 = (_ia_cmpeq_f64(alpha, _t18));
    int _t21 = _ia_and_tb(_t19, _t20);
    int _t22 =
        _ia_cvt2tb(((((unsigned long)(B)) >> 5) << 5 == (unsigned long)(B)));
    if (_ia_and_tb(_t21, _t22)) {
      i = 3136;
      pB = (f64_I *)B;
      B = ((void *)0);
      B2blk = ((void *)0);
      incB = 0;
    } else {
      i = 3136 + incK;
      vB = aligned_alloc(64, (((((incK))) * sizeof(f64_I))) + 32);
      if (!vB) {
        if (vC) {
          free(vC);
        }
        int _ret;
        _ret = (-1);
        return _ret;
      }
      pB = (vB);
      if (TB == CblasNoTrans) {
        incB = ((ldb)*56);
        f64_I _t23 = _ia_set_f64(-1.0, 1.0);
        if ((_ia_cmpeq_f64(alpha, _t23))) {
          B2blk = ATL_dcol2blk_a1;
        } else {
          B2blk = ATL_dcol2blk_aX;
        }
      } else {
        incB = 56;
        f64_I _t24 = _ia_set_f64(-1.0, 1.0);
        if ((_ia_cmpeq_f64(alpha, _t24))) {
          B2blk = ATL_drow2blkT_a1;
        } else {
          B2blk = ATL_drow2blkT_aX;
        }
      }
    }
    ATL_dmmJIK2(K, nMb, nNb, nKb, ib, jb, kb, alpha, pA, B, ldb, pB, incB,
                B2blk, beta, C, ldc, pC, putblk, NBmm0);
    if (vB) {
      free(vB);
    }
    if (vC) {
      free(vC);
    }
    int _ret;
    _ret = (0);
    return _ret;
  }

  f64_I _t25 = _ia_set_f64(-1.0, 1.0);
  int _t26 = (_ia_cmpeq_f64(alpha, _t25));
  int _t27 = _ia_cvt2tb(M <= 56);
  int _t28 = _ia_cvt2tb(A == B && M == N && TA != TB && lda == ldb);
  int _t29 = (_ia_or_tb(_t26, _t27));
  if (_ia_and_tb(_t28, _t29)) {
    i = (((((unsigned long)(M * K))) * sizeof(f64_I)));
    f64_I _t30 = _ia_set_f64(-1.0, 1.0);
    int _t31 = !(_ia_cmpeq_f64(alpha, _t30));
    int _t32 = _ia_cvt2tb(pC == C);
    f64_I _t33 = _ia_set_f64(-0.0, 0.0);
    int _t34 = _ia_and_tb(_t31, _t32);
    int _t35 = !(_ia_cmpeq_f64(beta, _t33));
    if (_ia_and_tb(_t34, _t35)) {
      i += (((((unsigned long)(M * N))) * sizeof(f64_I)));
    }
    if (i <= 67108864) {
      vB = aligned_alloc(64, i + 32);
    }
    if (vB) {
      pA = (vB);
      if (TA == CblasNoTrans) {
        ATL_drow2blkT2_a1(M, K, A, lda, pA, alpha);
      } else {
        ATL_dcol2blk_a1(K, M, A, lda, pA, alpha);
      }

      f64_I _t36 = _ia_set_f64(-1.0, 1.0);
      if (!(_ia_cmpeq_f64(alpha, _t36))) {
        f64_I _t37 = _ia_set_f64(-0.0, 0.0);
        if ((_ia_cmpeq_f64(beta, _t37))) {
          h = ldc;
        } else {
          if (pC == C) {
            pC = pA + ((unsigned long)M) * K;
            h = M;
          } else {
            h = 56;
          }
        }
        f64_I _t38 = _ia_set_f64(-1.0, 1.0);
        f64_I _t39 = _ia_set_f64(-0.0, 0.0);
        ATL_dmmJIK2(K, nMb, nNb, nKb, ib, jb, kb, _t38, pA, ((void *)0), ldb,
                    pA, 0, ((void *)0), _t39, pC, h, pC, ((void *)0),
                    ATL_dJIK56x56x56TN56x56x0_a1_b0);

        ATL_dgescal_bX(M, N, alpha, pC, h);

        if (C != pC) {
          f64_I _t40 = _ia_set_f64(-1.0, 1.0);
          if ((_ia_cmpeq_f64(beta, _t40))) {
            ATL_dputblk_b1(M, N, pC, C, ldc, beta);
          } else {
            f64_I _t41 = _ia_set_f64(1.0, -1.0);
            if ((_ia_cmpeq_f64(beta, _t41))) {
              ATL_dputblk_bn1(M, N, pC, C, ldc, beta);
            } else {
              f64_I _t42 = _ia_set_f64(-0.0, 0.0);
              if ((_ia_cmpeq_f64(beta, _t42))) {
                ATL_dputblk_b0(M, N, pC, C, ldc, beta);
              } else {
                ATL_dputblk_bX(M, N, pC, C, ldc, beta);
              }
            }
          }
        }
      } else {
        ATL_dmmJIK2(K, nMb, nNb, nKb, ib, jb, kb, alpha, pA, ((void *)0), ldb,
                    pA, 0, ((void *)0), beta, C, ldc, pC, putblk, NBmm0);
      }
      free(vB);
      if (vC) {
        free(vC);
      }
      int _ret;
      _ret = (0);
      return _ret;
    }
  }
  i = 32 + (((((M * K + incK))) * sizeof(f64_I)));
  if (i <= 67108864) {
    vB = aligned_alloc(64, i);
  }
  if (!vB) {
    if (TA != CblasNoTrans && TB != CblasNoTrans) {
      if (vC) {
        free(vC);
      }
      int _ret;
      _ret = (1);
      return _ret;
    }
    if (ib) {
      n = nMb + 1;
    } else {
      n = nMb;
    }
    for (j = 2; !vB; j++) {
      k = n / j;
      if (k < 1) {
        break;
      }
      if (k * j < n) {
        k++;
      }
      h = 32 + ((((((k + 1) * incK))) * sizeof(f64_I)));
      if (h <= 67108864) {
        vB = aligned_alloc(64, h);
      }
    }
    if (!vB) {
      if (vC) {
        free(vC);
      }
      int _ret;
      _ret = (-1);
      return _ret;
    }
    n = k;
    m = ((n)*56);
    ib2 = 0;
  } else {
    n = nMb;
    m = M;
    ib2 = ib;
  }
  pB = (vB);
  if (TA == CblasNoTrans) {
    incA = m;
    f64_I _t43 = _ia_set_f64(-1.0, 1.0);
    if ((_ia_cmpeq_f64(alpha, _t43))) {
      A2blk = ATL_drow2blkT2_a1;
    } else {
      A2blk = ATL_drow2blkT2_aX;
    }
  } else {
    incA = lda * m;
    f64_I _t44 = _ia_set_f64(-1.0, 1.0);
    if ((_ia_cmpeq_f64(alpha, _t44))) {
      A2blk = ATL_dcol2blk2_a1;
    } else {
      A2blk = ATL_dcol2blk2_aX;
    }
  }
  if (TB == CblasNoTrans) {
    incB = ((ldb)*56);
    B2blk = ATL_dcol2blk_a1;
  } else {
    incB = 56;
    B2blk = ATL_drow2blkT_a1;
  }
  incC = m;

  pA = pB + incK;
  do {
    if (TA == CblasNoTrans) {
      A2blk(m, K, A, lda, pA, alpha);
    } else {
      A2blk(K, m, A, lda, pA, alpha);
    }
    ATL_dmmJIK2(K, n, nNb, nKb, ib2, jb, kb, alpha, pA, B, ldb, pB, incB, B2blk,
                beta, C, ldc, pC, putblk, NBmm0);
    M -= m;
    nMb -= n;
    if (M <= m) {
      ib2 = ib;
      m = M;
      n = nMb;
    }
    C += incC;
    A += incA;
    if (!putblk) {
      pC = C;
    }
  } while (M);
  free(vB);
  if (vC) {
    free(vC);
  }
  int _ret;
  _ret = (0);
  return _ret;
}
