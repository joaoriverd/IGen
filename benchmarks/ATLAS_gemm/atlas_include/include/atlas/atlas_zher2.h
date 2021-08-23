/*
 * This file generated on line 445 of /home/joao/Documents/libraries/linear_algebra/atlas3.10.3/ATLAS/build_debug/..//tune/blas/ger/r2hgen.c
 */
#ifndef ATLAS_ZSYR2_H
   #define ATLAS_ZSYR2_H

#include "atlas_zr2.h"

#define ATL_s2U_NU 6

#define ATL_s2L_NU 6

#define ATL_GetPartS2(A_, lda_, mb_, nb_) { (mb_) = 1092; (nb_) = 6; }
#define ATL_MIN_RESTRICTED_M 0
#define ATL_URGERK ATL_zger2k__900002
static void ATL_GENGERK(ATL_CINT M, ATL_CINT N, const TYPE *X,
                        const TYPE *Y, const TYPE *W, const TYPE *Z,
                        TYPE *A, ATL_CINT lda)
{
   int nu, minM, minN, i, FNU, aX, aX2A, aY, aW, aZ;
   ATL_INT CEL;
   ATL_r2kern_t gerk;
   const TYPE one[2] = {ATL_rone, ATL_rzero};
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
             ATL_zger2k_Nlt8(M, nr, one, X, 1, Y+(n+n), 1, one, W, 1, Z+(n+n), 1, A+(n+n)*lda, lda);
      } /* end if (FNU) */
      else
         gerk(M, N, X, Y, W, Z, A, lda);
   } /* end if can call optimized kernel */
   else
      ATL_zger2k_Mlt16(M, N, one, X, 1, Y, 1, one, W, 1, Z, 1, A, lda);
}

#define ATL_HER2U_nu(A_, lda_, x_, y_, xt_, yt_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_)+(lda_), lda2_ = lda1_+(lda_)+(lda_), lda3_ = lda2_+(lda_)+(lda_), lda4_ = lda3_+(lda_)+(lda_), lda5_ = lda4_+(lda_)+(lda_); \
   const TYPE x0r=*(x_), x0i=(x_)[1], x1r=(x_)[2], x1i=(x_)[3], x2r=(x_)[4], x2i=(x_)[5], x3r=(x_)[6], x3i=(x_)[7], x4r=(x_)[8], x4i=(x_)[9], x5r=(x_)[10], x5i=(x_)[11]; \
   const TYPE xt0r=*(xt_), xt0i=(xt_)[1], xt1r=(xt_)[2], xt1i=(xt_)[3], xt2r=(xt_)[4], xt2i=(xt_)[5], xt3r=(xt_)[6], xt3i=(xt_)[7], xt4r=(xt_)[8], xt4i=(xt_)[9], xt5r=(xt_)[10], xt5i=(xt_)[11]; \
   const TYPE y0r=*(y_), y0i=(y_)[1], y1r=(y_)[2], y1i=(y_)[3], y2r=(y_)[4], y2i=(y_)[5], y3r=(y_)[6], y3i=(y_)[7], y4r=(y_)[8], y4i=(y_)[9], y5r=(y_)[10], y5i=(y_)[11]; \
   const TYPE yt0r=*(yt_), yt0i=(yt_)[1], yt1r=(yt_)[2], yt1i=(yt_)[3], yt2r=(yt_)[4], yt2i=(yt_)[5], yt3r=(yt_)[6], yt3i=(yt_)[7], yt4r=(yt_)[8], yt4i=(yt_)[9], yt5r=(yt_)[10], yt5i=(yt_)[11]; \
   aa[lda0_+0] += x0r*yt0r-x0i*yt0i + y0r*xt0r-y0i*xt0i; \
   aa[lda0_+1] = 0.0; \
   aa[lda1_+0] += x0r*yt1r-x0i*yt1i + y0r*xt1r-y0i*xt1i; \
   aa[lda1_+1] += x0r*yt1i+x0i*yt1r + y0r*xt1i+y0i*xt1r; \
   aa[lda1_+2] += x1r*yt1r-x1i*yt1i + y1r*xt1r-y1i*xt1i; \
   aa[lda1_+3] = 0.0; \
   aa[lda2_+0] += x0r*yt2r-x0i*yt2i + y0r*xt2r-y0i*xt2i; \
   aa[lda2_+1] += x0r*yt2i+x0i*yt2r + y0r*xt2i+y0i*xt2r; \
   aa[lda2_+2] += x1r*yt2r-x1i*yt2i + y1r*xt2r-y1i*xt2i; \
   aa[lda2_+3] += x1r*yt2i+x1i*yt2r + y1r*xt2i+y1i*xt2r; \
   aa[lda2_+4] += x2r*yt2r-x2i*yt2i + y2r*xt2r-y2i*xt2i; \
   aa[lda2_+5] = 0.0; \
   aa[lda3_+0] += x0r*yt3r-x0i*yt3i + y0r*xt3r-y0i*xt3i; \
   aa[lda3_+1] += x0r*yt3i+x0i*yt3r + y0r*xt3i+y0i*xt3r; \
   aa[lda3_+2] += x1r*yt3r-x1i*yt3i + y1r*xt3r-y1i*xt3i; \
   aa[lda3_+3] += x1r*yt3i+x1i*yt3r + y1r*xt3i+y1i*xt3r; \
   aa[lda3_+4] += x2r*yt3r-x2i*yt3i + y2r*xt3r-y2i*xt3i; \
   aa[lda3_+5] += x2r*yt3i+x2i*yt3r + y2r*xt3i+y2i*xt3r; \
   aa[lda3_+6] += x3r*yt3r-x3i*yt3i + y3r*xt3r-y3i*xt3i; \
   aa[lda3_+7] = 0.0; \
   aa[lda4_+0] += x0r*yt4r-x0i*yt4i + y0r*xt4r-y0i*xt4i; \
   aa[lda4_+1] += x0r*yt4i+x0i*yt4r + y0r*xt4i+y0i*xt4r; \
   aa[lda4_+2] += x1r*yt4r-x1i*yt4i + y1r*xt4r-y1i*xt4i; \
   aa[lda4_+3] += x1r*yt4i+x1i*yt4r + y1r*xt4i+y1i*xt4r; \
   aa[lda4_+4] += x2r*yt4r-x2i*yt4i + y2r*xt4r-y2i*xt4i; \
   aa[lda4_+5] += x2r*yt4i+x2i*yt4r + y2r*xt4i+y2i*xt4r; \
   aa[lda4_+6] += x3r*yt4r-x3i*yt4i + y3r*xt4r-y3i*xt4i; \
   aa[lda4_+7] += x3r*yt4i+x3i*yt4r + y3r*xt4i+y3i*xt4r; \
   aa[lda4_+8] += x4r*yt4r-x4i*yt4i + y4r*xt4r-y4i*xt4i; \
   aa[lda4_+9] = 0.0; \
   aa[lda5_+0] += x0r*yt5r-x0i*yt5i + y0r*xt5r-y0i*xt5i; \
   aa[lda5_+1] += x0r*yt5i+x0i*yt5r + y0r*xt5i+y0i*xt5r; \
   aa[lda5_+2] += x1r*yt5r-x1i*yt5i + y1r*xt5r-y1i*xt5i; \
   aa[lda5_+3] += x1r*yt5i+x1i*yt5r + y1r*xt5i+y1i*xt5r; \
   aa[lda5_+4] += x2r*yt5r-x2i*yt5i + y2r*xt5r-y2i*xt5i; \
   aa[lda5_+5] += x2r*yt5i+x2i*yt5r + y2r*xt5i+y2i*xt5r; \
   aa[lda5_+6] += x3r*yt5r-x3i*yt5i + y3r*xt5r-y3i*xt5i; \
   aa[lda5_+7] += x3r*yt5i+x3i*yt5r + y3r*xt5i+y3i*xt5r; \
   aa[lda5_+8] += x4r*yt5r-x4i*yt5i + y4r*xt5r-y4i*xt5i; \
   aa[lda5_+9] += x4r*yt5i+x4i*yt5r + y4r*xt5i+y4i*xt5r; \
   aa[lda5_+10] += x5r*yt5r-x5i*yt5i + y5r*xt5r-y5i*xt5i; \
   aa[lda5_+11] = 0.0; \
}
#define ATL_HER2L_nu(A_, lda_, x_, y_, xt_, yt_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_)+(lda_), lda2_ = lda1_+(lda_)+(lda_), lda3_ = lda2_+(lda_)+(lda_), lda4_ = lda3_+(lda_)+(lda_), lda5_ = lda4_+(lda_)+(lda_); \
   const TYPE x0r=*(x_), x0i=(x_)[1], x1r=(x_)[2], x1i=(x_)[3], x2r=(x_)[4], x2i=(x_)[5], x3r=(x_)[6], x3i=(x_)[7], x4r=(x_)[8], x4i=(x_)[9], x5r=(x_)[10], x5i=(x_)[11]; \
   const TYPE xt0r=*(xt_), xt0i=(xt_)[1], xt1r=(xt_)[2], xt1i=(xt_)[3], xt2r=(xt_)[4], xt2i=(xt_)[5], xt3r=(xt_)[6], xt3i=(xt_)[7], xt4r=(xt_)[8], xt4i=(xt_)[9], xt5r=(xt_)[10], xt5i=(xt_)[11]; \
   const TYPE y0r=*(y_), y0i=(y_)[1], y1r=(y_)[2], y1i=(y_)[3], y2r=(y_)[4], y2i=(y_)[5], y3r=(y_)[6], y3i=(y_)[7], y4r=(y_)[8], y4i=(y_)[9], y5r=(y_)[10], y5i=(y_)[11]; \
   const TYPE yt0r=*(yt_), yt0i=(yt_)[1], yt1r=(yt_)[2], yt1i=(yt_)[3], yt2r=(yt_)[4], yt2i=(yt_)[5], yt3r=(yt_)[6], yt3i=(yt_)[7], yt4r=(yt_)[8], yt4i=(yt_)[9], yt5r=(yt_)[10], yt5i=(yt_)[11]; \
   aa[lda0_+0] += x0r*yt0r-x0i*yt0i + y0r*xt0r-y0i*xt0i; \
   aa[lda0_+1] = 0.0; \
   aa[lda0_+2] += x1r*yt0r-x1i*yt0i + y1r*xt0r-y1i*xt0i; \
   aa[lda0_+3] += x1r*yt0i+x1i*yt0r + y1r*xt0i+y1i*xt0r; \
   aa[lda0_+4] += x2r*yt0r-x2i*yt0i + y2r*xt0r-y2i*xt0i; \
   aa[lda0_+5] += x2r*yt0i+x2i*yt0r + y2r*xt0i+y2i*xt0r; \
   aa[lda0_+6] += x3r*yt0r-x3i*yt0i + y3r*xt0r-y3i*xt0i; \
   aa[lda0_+7] += x3r*yt0i+x3i*yt0r + y3r*xt0i+y3i*xt0r; \
   aa[lda0_+8] += x4r*yt0r-x4i*yt0i + y4r*xt0r-y4i*xt0i; \
   aa[lda0_+9] += x4r*yt0i+x4i*yt0r + y4r*xt0i+y4i*xt0r; \
   aa[lda0_+10] += x5r*yt0r-x5i*yt0i + y5r*xt0r-y5i*xt0i; \
   aa[lda0_+11] += x5r*yt0i+x5i*yt0r + y5r*xt0i+y5i*xt0r; \
   aa[lda1_+2] += x1r*yt1r-x1i*yt1i + y1r*xt1r-y1i*xt1i; \
   aa[lda1_+3] = 0.0; \
   aa[lda1_+4] += x2r*yt1r-x2i*yt1i + y2r*xt1r-y2i*xt1i; \
   aa[lda1_+5] += x2r*yt1i+x2i*yt1r + y2r*xt1i+y2i*xt1r; \
   aa[lda1_+6] += x3r*yt1r-x3i*yt1i + y3r*xt1r-y3i*xt1i; \
   aa[lda1_+7] += x3r*yt1i+x3i*yt1r + y3r*xt1i+y3i*xt1r; \
   aa[lda1_+8] += x4r*yt1r-x4i*yt1i + y4r*xt1r-y4i*xt1i; \
   aa[lda1_+9] += x4r*yt1i+x4i*yt1r + y4r*xt1i+y4i*xt1r; \
   aa[lda1_+10] += x5r*yt1r-x5i*yt1i + y5r*xt1r-y5i*xt1i; \
   aa[lda1_+11] += x5r*yt1i+x5i*yt1r + y5r*xt1i+y5i*xt1r; \
   aa[lda2_+4] += x2r*yt2r-x2i*yt2i + y2r*xt2r-y2i*xt2i; \
   aa[lda2_+5] = 0.0; \
   aa[lda2_+6] += x3r*yt2r-x3i*yt2i + y3r*xt2r-y3i*xt2i; \
   aa[lda2_+7] += x3r*yt2i+x3i*yt2r + y3r*xt2i+y3i*xt2r; \
   aa[lda2_+8] += x4r*yt2r-x4i*yt2i + y4r*xt2r-y4i*xt2i; \
   aa[lda2_+9] += x4r*yt2i+x4i*yt2r + y4r*xt2i+y4i*xt2r; \
   aa[lda2_+10] += x5r*yt2r-x5i*yt2i + y5r*xt2r-y5i*xt2i; \
   aa[lda2_+11] += x5r*yt2i+x5i*yt2r + y5r*xt2i+y5i*xt2r; \
   aa[lda3_+6] += x3r*yt3r-x3i*yt3i + y3r*xt3r-y3i*xt3i; \
   aa[lda3_+7] = 0.0; \
   aa[lda3_+8] += x4r*yt3r-x4i*yt3i + y4r*xt3r-y4i*xt3i; \
   aa[lda3_+9] += x4r*yt3i+x4i*yt3r + y4r*xt3i+y4i*xt3r; \
   aa[lda3_+10] += x5r*yt3r-x5i*yt3i + y5r*xt3r-y5i*xt3i; \
   aa[lda3_+11] += x5r*yt3i+x5i*yt3r + y5r*xt3i+y5i*xt3r; \
   aa[lda4_+8] += x4r*yt4r-x4i*yt4i + y4r*xt4r-y4i*xt4i; \
   aa[lda4_+9] = 0.0; \
   aa[lda4_+10] += x5r*yt4r-x5i*yt4i + y5r*xt4r-y5i*xt4i; \
   aa[lda4_+11] += x5r*yt4i+x5i*yt4r + y5r*xt4i+y5i*xt4r; \
   aa[lda5_+10] += x5r*yt5r-x5i*yt5i + y5r*xt5r-y5i*xt5i; \
   aa[lda5_+11] = 0.0; \
}

#endif
