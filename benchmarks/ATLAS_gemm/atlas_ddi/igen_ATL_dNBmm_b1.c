#include "igen_dd_lib.h"
#include <atlas_misc.h>

#include "igen_dd_immintrin.h"
void ATL_dJIK56x56x56TN56x56x0_a1_b1(const int M, const int N, const int K,
                                     dd_I alpha, const dd_I *__restrict A,
                                     const int lda, const dd_I *__restrict B,
                                     const int ldb, dd_I beta,
                                     dd_I *__restrict C, const int ldc)

{
  const int Mb = (M >> 2) << 2;
  const int Nb = (N >> 1) << 1;
  const dd_I *stM = A + (56 * (Mb));
  const dd_I *stN = B + (56 * (Nb));
  const dd_I *pfA = stM;
  const int incAm = 3 * 56;
  const int incAn = -(56 * (Mb));
  const int incBm = -56;
  const int incBn = 2 * 56;
  const int incCn = ((((ldc) << 1)) - (Mb));
  dd_I *pC0 = C;
  dd_I *pC1 = pC0 + (ldc);
  const dd_I *pA0 = A;
  const dd_I *pB0 = B;
  int k;
  ddi_4 rA0;
  ddi_4 rA1;
  ddi_4 rA2;
  ddi_4 rA3;
  ddi_4 rB0;
  ddi_4 rB1;
  ddi_4 t0;
  ddi_4 rC0_0;
  ddi_4 rC1_0;
  ddi_4 rC2_0;
  ddi_4 rC3_0;
  ddi_4 rC0_1;
  ddi_4 rC1_1;
  ddi_4 rC2_1;
  ddi_4 rC3_1;

  ddi_4 rc00;

  do {
    do {
      rC0_0 = _igen_dd_mm256_setzero_pd();
      rC1_0 = _igen_dd_mm256_setzero_pd();
      rC2_0 = _igen_dd_mm256_setzero_pd();
      rC3_0 = _igen_dd_mm256_setzero_pd();

      rc00 = _igen_dd_mm256_loadu_pd(pC0);

      t0 = _igen_dd_mm256_broadcast_sd(&beta);
      rc00 = _igen_dd_mm256_mul_pd(rc00, t0);

      rC0_1 = _igen_dd_mm256_setzero_pd();
      rC1_1 = _igen_dd_mm256_setzero_pd();
      rC2_1 = _igen_dd_mm256_setzero_pd();
      rC3_1 = _igen_dd_mm256_setzero_pd();
      for (k = 0; k < 56; k += 4) {
        rA0 = _igen_dd_mm256_load_pd(pA0);
        rB0 = _igen_dd_mm256_load_pd(pB0);
        rA1 = _igen_dd_mm256_load_pd(pA0 + 56);
        rA2 = _igen_dd_mm256_load_pd(pA0 + 2 * 56);
        rA3 = _igen_dd_mm256_load_pd(pA0 + 3 * 56);
        rB1 = _igen_dd_mm256_load_pd(pB0 + 56);

        t0 = _igen_dd_mm256_mul_pd(rA0, rB0);
        rC0_0 = _igen_dd_mm256_add_pd(rC0_0, t0);
        t0 = _igen_dd_mm256_mul_pd(rA1, rB0);
        rC1_0 = _igen_dd_mm256_add_pd(rC1_0, t0);
        t0 = _igen_dd_mm256_mul_pd(rA2, rB0);
        rC2_0 = _igen_dd_mm256_add_pd(rC2_0, t0);
        t0 = _igen_dd_mm256_mul_pd(rA3, rB0);
        rC3_0 = _igen_dd_mm256_add_pd(rC3_0, t0);
        t0 = _igen_dd_mm256_mul_pd(rA0, rB1);
        rC0_1 = _igen_dd_mm256_add_pd(rC0_1, t0);
        t0 = _igen_dd_mm256_mul_pd(rA1, rB1);
        rC1_1 = _igen_dd_mm256_add_pd(rC1_1, t0);
        t0 = _igen_dd_mm256_mul_pd(rA2, rB1);
        rC2_1 = _igen_dd_mm256_add_pd(rC2_1, t0);
        t0 = _igen_dd_mm256_mul_pd(rA3, rB1);
        rC3_1 = _igen_dd_mm256_add_pd(rC3_1, t0);

        pA0 += 4;
        pB0 += 4;
      }

      t0 = _igen_dd_mm256_loadu_pd(pC1);

      rC0_0 = _igen_dd_mm256_hadd_pd(rC0_0, rC1_0);
      rC2_0 = _igen_dd_mm256_hadd_pd(rC2_0, rC3_0);

      rC3_0 = _igen_dd_mm256_broadcast_sd(&beta);
      t0 = _igen_dd_mm256_mul_pd(t0, rC3_0);

      rC1_0 = _igen_dd_mm256_permute2f128_pd(rC0_0, rC2_0, 32);

      rC0_0 = _igen_dd_mm256_permute2f128_pd(rC0_0, rC2_0, 49);
      (__builtin_prefetch((void *)(pfA), ((1) >> 2) & 1, (1) & 3));

      rC0_0 = _igen_dd_mm256_add_pd(rC0_0, rC1_0);

      rC0_0 = _igen_dd_mm256_add_pd(rC0_0, rc00);

      _igen_dd_mm256_storeu_pd(pC0, rC0_0);

      rC0_1 = _igen_dd_mm256_hadd_pd(rC0_1, rC1_1);
      rC2_1 = _igen_dd_mm256_hadd_pd(rC2_1, rC3_1);
      rC1_1 = _igen_dd_mm256_permute2f128_pd(rC0_1, rC2_1, 32);

      rC0_1 = _igen_dd_mm256_permute2f128_pd(rC0_1, rC2_1, 49);

      rC0_1 = _igen_dd_mm256_add_pd(rC0_1, rC1_1);

      rC0_1 = _igen_dd_mm256_add_pd(rC0_1, t0);

      pfA += 8;
      _igen_dd_mm256_storeu_pd(pC1, rC0_1);

      pC0 += 4;
      pC1 += 4;
      pA0 += incAm;
      pB0 += incBm;
    } while (pA0 != stM);
    pC0 += incCn;
    pC1 += incCn;
    pA0 += incAn;
    pB0 += incBn;
  } while (pB0 != stN);
}
