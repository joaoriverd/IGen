/*
 * This file generated on line 432 of /home/joao/Documents/libraries/linear_algebra/atlas3.10.3/ATLAS/build_debug/..//tune/blas/ger/r1hgen.c
 */
#ifndef ATLAS_DSYR1_L2_H
   #define ATLAS_DSYR1_L2_H

#include "atlas_dr1_L2.h"

#define ATL_s1U_NU 6

#define ATL_s1L_NU 6
#define ATL_MIN_RESTRICTED_M 8
#define ATL_URGERK ATL_dgerk__900008
static void ATL_GENGERK(ATL_CINT M, ATL_CINT N, const TYPE *X,
                        const TYPE *Y, TYPE *A, ATL_CINT lda)
{
   int nu, minM, minN, i, FNU, aX, aX2A, aY;
   ATL_INT CEL;
   ATL_r1kern_t gerk;
   gerk = ATL_GetR1Kern(M, N, A, lda, &i, &nu, &minM, &minN,
                        &aX, &aX2A, &aY, &FNU, &CEL);
   if (aX2A)
      aX = ((size_t)A) % ATL_Cachelen == ((size_t)X) % ATL_Cachelen;
   else
      aX = (aX) ? (((size_t)X)/aX)*aX == (size_t)X : 1;
   aY = (aY) ? (((size_t)Y)/aY)*aY == (size_t)Y : 1;
   if (M >= minM && N >= minN && aX && aY)
   {
      if (FNU)
      {
          ATL_CINT n = (N/nu)*nu, nr=N-n;
          gerk(M, n, X, Y, A, lda);
          if (nr)
             ATL_dgerk_axpy(M, nr, ATL_rone, X, 1, Y+n, 1, A+n*lda, lda);
      } /* end if (FNU) */
      else
         gerk(M, N, X, Y, A, lda);
   } /* end if can call optimized kernel */
   else
      ATL_dgerk_Mlt16(M, N, ATL_rone, X, 1, Y, 1, A, lda);
}

#define ATL_SYR1U_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_), lda2_ = lda1_+(lda_), lda3_ = lda2_+(lda_), lda4_ = lda3_+(lda_), lda5_ = lda4_+(lda_); \
   const TYPE x0_=*(x_), x1_=(x_)[1], x2_=(x_)[2], x3_=(x_)[3], x4_=(x_)[4], x5_=(x_)[5]; \
   const TYPE y0_=*(y_), y1_=(y_)[1], y2_=(y_)[2], y3_=(y_)[3], y4_=(y_)[4], y5_=(y_)[5]; \
   aa[lda0_+0] += x0_*y0_; \
   aa[lda1_+0] += x0_*y1_; \
   aa[lda1_+1] += x1_*y1_; \
   aa[lda2_+0] += x0_*y2_; \
   aa[lda2_+1] += x1_*y2_; \
   aa[lda2_+2] += x2_*y2_; \
   aa[lda3_+0] += x0_*y3_; \
   aa[lda3_+1] += x1_*y3_; \
   aa[lda3_+2] += x2_*y3_; \
   aa[lda3_+3] += x3_*y3_; \
   aa[lda4_+0] += x0_*y4_; \
   aa[lda4_+1] += x1_*y4_; \
   aa[lda4_+2] += x2_*y4_; \
   aa[lda4_+3] += x3_*y4_; \
   aa[lda4_+4] += x4_*y4_; \
   aa[lda5_+0] += x0_*y5_; \
   aa[lda5_+1] += x1_*y5_; \
   aa[lda5_+2] += x2_*y5_; \
   aa[lda5_+3] += x3_*y5_; \
   aa[lda5_+4] += x4_*y5_; \
   aa[lda5_+5] += x5_*y5_; \
}
#define ATL_SYR1L_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_), lda2_ = lda1_+(lda_), lda3_ = lda2_+(lda_), lda4_ = lda3_+(lda_), lda5_ = lda4_+(lda_); \
   const TYPE x0_=*(x_), x1_=(x_)[1], x2_=(x_)[2], x3_=(x_)[3], x4_=(x_)[4], x5_=(x_)[5]; \
   const TYPE y0_=*(y_), y1_=(y_)[1], y2_=(y_)[2], y3_=(y_)[3], y4_=(y_)[4], y5_=(y_)[5]; \
   aa[lda0_+0] += x0_*y0_; \
   aa[lda0_+1] += x1_*y0_; \
   aa[lda0_+2] += x2_*y0_; \
   aa[lda0_+3] += x3_*y0_; \
   aa[lda0_+4] += x4_*y0_; \
   aa[lda0_+5] += x5_*y0_; \
   aa[lda1_+1] += x1_*y1_; \
   aa[lda1_+2] += x2_*y1_; \
   aa[lda1_+3] += x3_*y1_; \
   aa[lda1_+4] += x4_*y1_; \
   aa[lda1_+5] += x5_*y1_; \
   aa[lda2_+2] += x2_*y2_; \
   aa[lda2_+3] += x3_*y2_; \
   aa[lda2_+4] += x4_*y2_; \
   aa[lda2_+5] += x5_*y2_; \
   aa[lda3_+3] += x3_*y3_; \
   aa[lda3_+4] += x4_*y3_; \
   aa[lda3_+5] += x5_*y3_; \
   aa[lda4_+4] += x4_*y4_; \
   aa[lda4_+5] += x5_*y4_; \
   aa[lda5_+5] += x5_*y5_; \
}

#endif
