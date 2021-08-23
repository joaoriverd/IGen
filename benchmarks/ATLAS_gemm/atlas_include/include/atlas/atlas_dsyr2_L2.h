/*
 * This file generated on line 445 of /home/joao/Documents/libraries/linear_algebra/atlas3.10.3/ATLAS/build_debug/..//tune/blas/ger/r2hgen.c
 */
#ifndef ATLAS_DSYR2_L2_H
   #define ATLAS_DSYR2_L2_H

#include "atlas_dr2_L2.h"

#define ATL_s2U_NU 10

#define ATL_s2L_NU 10
#define ATL_MIN_RESTRICTED_M 24
#define ATL_URGERK ATL_dger2k__900008
static void ATL_GENGERK(ATL_CINT M, ATL_CINT N, const TYPE *X,
                        const TYPE *Y, const TYPE *W, const TYPE *Z,
                        TYPE *A, ATL_CINT lda)
{
   int nu, minM, minN, i, FNU, aX, aX2A, aY, aW, aZ;
   ATL_INT CEL;
   ATL_r2kern_t gerk;
   gerk = ATL_GetR2Kern(M, N, A, lda, &i, &nu, &minM, &minN,
                        &aX, &aX2A, &aY, &FNU, &CEL);
   if (aX2A)
   {
      aX = ((size_t)A) % ATL_Cachelen == ((size_t)X) % ATL_Cachelen;
      aW = ((size_t)A) % ATL_Cachelen == ((size_t)W) % ATL_Cachelen;
   }   else
   {
      aW = (aX) ? (((size_t)W)/aX)*aX == (size_t)W : 1;
      aX = (aX) ? (((size_t)X)/aX)*aX == (size_t)X : 1;
   }
   aZ = (aY) ? (((size_t)Z)/aY)*aY == (size_t)Z : 1;
   aY = (aY) ? (((size_t)Y)/aY)*aY == (size_t)Y : 1;
   if (M >= minM && N >= minN && aX && aY && aW && aZ)
   {
      if (FNU)
      {
          ATL_CINT n = (N/nu)*nu, nr=N-n;
          gerk(M, n, X, Y, W, Z, A, lda);
          if (nr)
             ATL_dger2k_Nlt8(M, nr, ATL_rone, X, 1, Y+n, 1, ATL_rone, W, 1, Z+n, 1, A+n*lda, lda);
      } /* end if (FNU) */
      else
         gerk(M, N, X, Y, W, Z, A, lda);
   } /* end if can call optimized kernel */
   else
      ATL_dger2k_Mlt16(M, N, ATL_rone, X, 1, Y, 1, ATL_rone, W, 1, Z, 1, A, lda);
}

#define ATL_SYR2U_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_), lda2_ = lda1_+(lda_), lda3_ = lda2_+(lda_), lda4_ = lda3_+(lda_), lda5_ = lda4_+(lda_), lda6_ = lda5_+(lda_), lda7_ = lda6_+(lda_), lda8_ = lda7_+(lda_), lda9_ = lda8_+(lda_); \
   const TYPE x0_=*(x_), x1_=(x_)[1], x2_=(x_)[2], x3_=(x_)[3], x4_=(x_)[4], x5_=(x_)[5], x6_=(x_)[6], x7_=(x_)[7], x8_=(x_)[8], x9_=(x_)[9]; \
   const TYPE y0_=*(y_), y1_=(y_)[1], y2_=(y_)[2], y3_=(y_)[3], y4_=(y_)[4], y5_=(y_)[5], y6_=(y_)[6], y7_=(y_)[7], y8_=(y_)[8], y9_=(y_)[9]; \
   aa[lda0_+0] += x0_*y0_ + y0_*x0_; \
   aa[lda1_+0] += x0_*y1_ + y0_*x1_; \
   aa[lda1_+1] += x1_*y1_ + y1_*x1_; \
   aa[lda2_+0] += x0_*y2_ + y0_*x2_; \
   aa[lda2_+1] += x1_*y2_ + y1_*x2_; \
   aa[lda2_+2] += x2_*y2_ + y2_*x2_; \
   aa[lda3_+0] += x0_*y3_ + y0_*x3_; \
   aa[lda3_+1] += x1_*y3_ + y1_*x3_; \
   aa[lda3_+2] += x2_*y3_ + y2_*x3_; \
   aa[lda3_+3] += x3_*y3_ + y3_*x3_; \
   aa[lda4_+0] += x0_*y4_ + y0_*x4_; \
   aa[lda4_+1] += x1_*y4_ + y1_*x4_; \
   aa[lda4_+2] += x2_*y4_ + y2_*x4_; \
   aa[lda4_+3] += x3_*y4_ + y3_*x4_; \
   aa[lda4_+4] += x4_*y4_ + y4_*x4_; \
   aa[lda5_+0] += x0_*y5_ + y0_*x5_; \
   aa[lda5_+1] += x1_*y5_ + y1_*x5_; \
   aa[lda5_+2] += x2_*y5_ + y2_*x5_; \
   aa[lda5_+3] += x3_*y5_ + y3_*x5_; \
   aa[lda5_+4] += x4_*y5_ + y4_*x5_; \
   aa[lda5_+5] += x5_*y5_ + y5_*x5_; \
   aa[lda6_+0] += x0_*y6_ + y0_*x6_; \
   aa[lda6_+1] += x1_*y6_ + y1_*x6_; \
   aa[lda6_+2] += x2_*y6_ + y2_*x6_; \
   aa[lda6_+3] += x3_*y6_ + y3_*x6_; \
   aa[lda6_+4] += x4_*y6_ + y4_*x6_; \
   aa[lda6_+5] += x5_*y6_ + y5_*x6_; \
   aa[lda6_+6] += x6_*y6_ + y6_*x6_; \
   aa[lda7_+0] += x0_*y7_ + y0_*x7_; \
   aa[lda7_+1] += x1_*y7_ + y1_*x7_; \
   aa[lda7_+2] += x2_*y7_ + y2_*x7_; \
   aa[lda7_+3] += x3_*y7_ + y3_*x7_; \
   aa[lda7_+4] += x4_*y7_ + y4_*x7_; \
   aa[lda7_+5] += x5_*y7_ + y5_*x7_; \
   aa[lda7_+6] += x6_*y7_ + y6_*x7_; \
   aa[lda7_+7] += x7_*y7_ + y7_*x7_; \
   aa[lda8_+0] += x0_*y8_ + y0_*x8_; \
   aa[lda8_+1] += x1_*y8_ + y1_*x8_; \
   aa[lda8_+2] += x2_*y8_ + y2_*x8_; \
   aa[lda8_+3] += x3_*y8_ + y3_*x8_; \
   aa[lda8_+4] += x4_*y8_ + y4_*x8_; \
   aa[lda8_+5] += x5_*y8_ + y5_*x8_; \
   aa[lda8_+6] += x6_*y8_ + y6_*x8_; \
   aa[lda8_+7] += x7_*y8_ + y7_*x8_; \
   aa[lda8_+8] += x8_*y8_ + y8_*x8_; \
   aa[lda9_+0] += x0_*y9_ + y0_*x9_; \
   aa[lda9_+1] += x1_*y9_ + y1_*x9_; \
   aa[lda9_+2] += x2_*y9_ + y2_*x9_; \
   aa[lda9_+3] += x3_*y9_ + y3_*x9_; \
   aa[lda9_+4] += x4_*y9_ + y4_*x9_; \
   aa[lda9_+5] += x5_*y9_ + y5_*x9_; \
   aa[lda9_+6] += x6_*y9_ + y6_*x9_; \
   aa[lda9_+7] += x7_*y9_ + y7_*x9_; \
   aa[lda9_+8] += x8_*y9_ + y8_*x9_; \
   aa[lda9_+9] += x9_*y9_ + y9_*x9_; \
}
#define ATL_SYR2L_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_), lda2_ = lda1_+(lda_), lda3_ = lda2_+(lda_), lda4_ = lda3_+(lda_), lda5_ = lda4_+(lda_), lda6_ = lda5_+(lda_), lda7_ = lda6_+(lda_), lda8_ = lda7_+(lda_), lda9_ = lda8_+(lda_); \
   const TYPE x0_=*(x_), x1_=(x_)[1], x2_=(x_)[2], x3_=(x_)[3], x4_=(x_)[4], x5_=(x_)[5], x6_=(x_)[6], x7_=(x_)[7], x8_=(x_)[8], x9_=(x_)[9]; \
   const TYPE y0_=*(y_), y1_=(y_)[1], y2_=(y_)[2], y3_=(y_)[3], y4_=(y_)[4], y5_=(y_)[5], y6_=(y_)[6], y7_=(y_)[7], y8_=(y_)[8], y9_=(y_)[9]; \
   aa[lda0_+0] += x0_*y0_ + y0_*x0_; \
   aa[lda0_+1] += x1_*y0_ + y1_*x0_; \
   aa[lda0_+2] += x2_*y0_ + y2_*x0_; \
   aa[lda0_+3] += x3_*y0_ + y3_*x0_; \
   aa[lda0_+4] += x4_*y0_ + y4_*x0_; \
   aa[lda0_+5] += x5_*y0_ + y5_*x0_; \
   aa[lda0_+6] += x6_*y0_ + y6_*x0_; \
   aa[lda0_+7] += x7_*y0_ + y7_*x0_; \
   aa[lda0_+8] += x8_*y0_ + y8_*x0_; \
   aa[lda0_+9] += x9_*y0_ + y9_*x0_; \
   aa[lda1_+1] += x1_*y1_ + y1_*x1_; \
   aa[lda1_+2] += x2_*y1_ + y2_*x1_; \
   aa[lda1_+3] += x3_*y1_ + y3_*x1_; \
   aa[lda1_+4] += x4_*y1_ + y4_*x1_; \
   aa[lda1_+5] += x5_*y1_ + y5_*x1_; \
   aa[lda1_+6] += x6_*y1_ + y6_*x1_; \
   aa[lda1_+7] += x7_*y1_ + y7_*x1_; \
   aa[lda1_+8] += x8_*y1_ + y8_*x1_; \
   aa[lda1_+9] += x9_*y1_ + y9_*x1_; \
   aa[lda2_+2] += x2_*y2_ + y2_*x2_; \
   aa[lda2_+3] += x3_*y2_ + y3_*x2_; \
   aa[lda2_+4] += x4_*y2_ + y4_*x2_; \
   aa[lda2_+5] += x5_*y2_ + y5_*x2_; \
   aa[lda2_+6] += x6_*y2_ + y6_*x2_; \
   aa[lda2_+7] += x7_*y2_ + y7_*x2_; \
   aa[lda2_+8] += x8_*y2_ + y8_*x2_; \
   aa[lda2_+9] += x9_*y2_ + y9_*x2_; \
   aa[lda3_+3] += x3_*y3_ + y3_*x3_; \
   aa[lda3_+4] += x4_*y3_ + y4_*x3_; \
   aa[lda3_+5] += x5_*y3_ + y5_*x3_; \
   aa[lda3_+6] += x6_*y3_ + y6_*x3_; \
   aa[lda3_+7] += x7_*y3_ + y7_*x3_; \
   aa[lda3_+8] += x8_*y3_ + y8_*x3_; \
   aa[lda3_+9] += x9_*y3_ + y9_*x3_; \
   aa[lda4_+4] += x4_*y4_ + y4_*x4_; \
   aa[lda4_+5] += x5_*y4_ + y5_*x4_; \
   aa[lda4_+6] += x6_*y4_ + y6_*x4_; \
   aa[lda4_+7] += x7_*y4_ + y7_*x4_; \
   aa[lda4_+8] += x8_*y4_ + y8_*x4_; \
   aa[lda4_+9] += x9_*y4_ + y9_*x4_; \
   aa[lda5_+5] += x5_*y5_ + y5_*x5_; \
   aa[lda5_+6] += x6_*y5_ + y6_*x5_; \
   aa[lda5_+7] += x7_*y5_ + y7_*x5_; \
   aa[lda5_+8] += x8_*y5_ + y8_*x5_; \
   aa[lda5_+9] += x9_*y5_ + y9_*x5_; \
   aa[lda6_+6] += x6_*y6_ + y6_*x6_; \
   aa[lda6_+7] += x7_*y6_ + y7_*x6_; \
   aa[lda6_+8] += x8_*y6_ + y8_*x6_; \
   aa[lda6_+9] += x9_*y6_ + y9_*x6_; \
   aa[lda7_+7] += x7_*y7_ + y7_*x7_; \
   aa[lda7_+8] += x8_*y7_ + y8_*x7_; \
   aa[lda7_+9] += x9_*y7_ + y9_*x7_; \
   aa[lda8_+8] += x8_*y8_ + y8_*x8_; \
   aa[lda8_+9] += x9_*y8_ + y9_*x8_; \
   aa[lda9_+9] += x9_*y9_ + y9_*x9_; \
}

#endif
