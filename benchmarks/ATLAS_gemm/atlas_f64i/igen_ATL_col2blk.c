#include "atlas_lvl3.h"
#include "atlas_misc.h"
#include "atlas_prefetch.h"
#include "igen_lib.h"

void ATL_dcol2blk_a1(const int M, const int N, const f64_I *A, const int lda,
                     f64_I *V, f64_I alpha0) {
  const int Mb = ((M) / 56);
  const int m = ((Mb)*56);
  const int mr = M - m;
  const int Nb = ((N) / 56);
  const int n = ((Nb)*56);
  const int nr = N - n;
  const int nb2 = 56 >> 1;
  const int incA = (lda << 1) - m;
  const int incV = (Mb ? (56 << 1) - Mb * 3136 : 0);
  const int incVv = (Mb ? (Mb - 1) * 3136 + ((mr)*56) : ((mr)*56));
  const int incV0 = ((nr)*56);
  const int incV1 = (Mb ? (56 << 1) - incV0 * Mb : (mr << 1));
  int ib;
  int jb;
  int i;
  int j;
  const f64_I *pA0 = A;
  const f64_I *pA1 = A + lda;
  f64_I *v0 = V;
  f64_I *vv = V + ((m)*56);
  f64_I alpha = alpha0;
  for (jb = Nb; jb;) {
    vv = v0 + ((m)*56);
    for (j = nb2; j;) {
      for (ib = Mb; ib;) {

        for (i = 0; i != 56; i++) {
          v0[i] = pA0[i];
          v0[56 + i] = pA1[i];
        }
        int _t5 = ib--;
        const double *_t6 = (_t5, pA0 += 56);
        const double *_t7 = (_t6, pA1 += 56);
        (_t7, v0 += 3136);
      }
      if (mr) {
        for (i = 0; i != mr; i++) {
          vv[i] = pA0[i];
          vv[mr + i] = pA1[i];
        }
        vv += mr << 1;
      }
      int _t2 = j--;
      double *_t3 = (_t2, v0 += incV);
      const double *_t4 = (_t3, pA0 += incA);
      (_t4, pA1 += incA);
    }
    int _t1 = jb--;
    (_t1, v0 += incVv);
  }

  if (nr) {
    v0 = V + Nb * 56 * M;
    vv = v0 + nr * m;
    for (j = jb = (nr >> 1); j;) {
      for (ib = Mb; ib;) {
        for (i = 0; i != 56; i++) {
          v0[i] = pA0[i];
          v0[i + 56] = pA1[i];
        }
        int _t11 = ib--;
        const double *_t12 = (_t11, pA0 += 56);
        const double *_t13 = (_t12, pA1 += 56);
        (_t13, v0 += incV0);
      }
      if (mr) {
        for (i = 0; i != mr; i++) {
          vv[i] = pA0[i];
          vv[i + mr] = pA1[i];
        }
        vv += mr << 1;
      }
      int _t8 = j--;
      const double *_t9 = (_t8, pA0 += incA);
      const double *_t10 = (_t9, pA1 += incA);
      (_t10, v0 += incV1);
    }
    if ((jb << 1) != nr) {
      for (ib = Mb; ib;) {
        for (i = 0; i != 56; i++) {
          v0[i] = pA0[i];
        }
        int _t14 = ib--;
        const double *_t15 = (_t14, pA0 += 56);
        (_t15, v0 += incV0);
      }
      if (mr) {
        for (i = 0; i != mr; i++) {
          vv[i] = pA0[i];
        }
      }
    }
  }
}

void ATL_dcol2blk2_a1(const int M, const int N, const f64_I *A, const int lda,
                      f64_I *V, f64_I alpha) {
  ATL_dcol2blk_a1(M, N, A, lda, V, alpha);
}
