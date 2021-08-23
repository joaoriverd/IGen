#include "atlas_lvl3.h"
#include "atlas_misc.h"
#include "atlas_prefetch.h"
#include "igen_lib.h"
static void ATL_drow2blkT_NB_a1(const int M, const int N, const f64_I *A,
                                const int lda, f64_I *V, f64_I alpha0)

{
  const int lda2 = lda << 1;
  int i;
  int j;
  f64_I *v = V;
  const f64_I *pA0 = A;
  const f64_I *pA1 = A + lda;
  f64_I alpha = alpha0;
  for (j = 56; j; j -= 2) {

    for (i = 0; i != 56;) {
      *v = pA0[i];
      v[1] = pA1[i];
      int _t1 = i++;
      (_t1, v += 56);
    }
    V += 2;
    v = V;
    pA0 += lda2;
    pA1 += lda2;
  }
}

static void ATL_drow2blkT_KB_a1(const int M, const int N, const f64_I *A,
                                const int lda, f64_I *V, f64_I alpha0) {
  const int n = N >> 1;
  const int lda2 = lda << 1;
  int i;
  int j;
  f64_I *v = V;
  const f64_I *pA0 = A;
  const f64_I *pA1 = A + lda;
  f64_I alpha = alpha0;

  for (j = n; j; j--) {
    for (i = 0; i != M;) {
      *v = pA0[i];
      v[1] = pA1[i];
      int _t2 = i++;
      (_t2, v += N);
    }
    V += 2;
    v = V;
    pA0 += lda2;
    pA1 += lda2;
  }
  if ((n << 1) != N) {
    for (i = 0; i != M;) {
      *v = pA0[i];
      int _t3 = i++;
      (_t3, v += N);
    }
  }
}

void ATL_drow2blkT_a1(const int N, const int nb, const f64_I *A, const int lda,
                      f64_I *V, f64_I alpha)

{
  const int Nb = ((N) / 56);
  const int incA = ((lda)*56);
  const int incV = ((nb)*56);
  int k;

  if (nb == 56) {
    for (k = 0; k != Nb;) {
      ATL_drow2blkT_NB_a1(Nb, 56, A, lda, V, alpha);
      int _t4 = k++;
      const double *_t5 = (_t4, A += incA);
      (_t5, V += incV);
    }

  } else {
    for (k = 0; k != Nb;) {
      ATL_drow2blkT_KB_a1(nb, 56, A, lda, V, alpha);
      int _t6 = k++;
      const double *_t7 = (_t6, A += incA);
      (_t7, V += incV);
    }
  }
  if ((k == N - ((Nb)*56))) {
    ATL_drow2blkT_KB_a1(nb, k, A, lda, V, alpha);
  }
}
void ATL_drow2blkT2_a1(const int M, const int N, const f64_I *A, const int lda,
                       f64_I *V, f64_I alpha) {
  const int Mb = ((M) / 56);
  const int Nb = ((N) / 56);
  const int mr = M - ((Mb)*56);
  const int nr = N - ((Nb)*56);
  const int incV = ((N)*56);
  const int incA = ((lda)*56) - M + mr;
  const int incVV = ((mr)*56);
  int i;
  int j;
  f64_I *v = V;
  f64_I *vv = V + Mb * incV;

  for (j = Nb; j; j--) {
    for (i = Mb; i;) {
      ATL_drow2blkT_NB_a1(56, 56, A, lda, v, alpha);
      int _t8 = i--;
      const double *_t9 = (_t8, A += 56);
      (_t9, v += incV);
    }
    if (mr) {
      ATL_drow2blkT_KB_a1(mr, 56, A, lda, vv, alpha);
      vv += incVV;
    }
    A += incA;
    V += 3136;
    v = V;
  }
  if (nr) {
    for (i = Mb; i;) {
      ATL_drow2blkT_KB_a1(56, nr, A, lda, v, alpha);
      int _t10 = i--;
      const double *_t11 = (_t10, A += 56);
      (_t11, v += incV);
    }
    if (mr) {
      ATL_drow2blkT_KB_a1(mr, nr, A, lda, vv, alpha);
    }
  }
}
