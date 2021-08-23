#ifndef ATLAS_ZR2_L1_H
#define ATLAS_ZR2_L1_H

#include "atlas_type.h"

typedef void (*ATL_r2kern_t)
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);
void ATL_zger2k__4
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);
void ATL_zger2k__2
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);
void ATL_zger2k__900002
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);

static ATL_r2kern_t ATL_GetR2Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   if ((((((((size_t)(A))) >> 5)) << 5)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 5)) << 5)) == ATL_MulBySize(lda))
      {
         *minM = 0;   *minN = 0;
         *mu = 2;     *nu = 3;
         *alignX = 32;  *alignY = 32;
         *ALIGNX2A = 0;
         *FNU = 1;
         *CacheElts = 2048;
         return(ATL_zger2k__4);
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 2)
         {
            if (M >= 4)
            {
               *minM = 4;   *minN = 2;
               *mu = 1;     *nu = 2;
               *alignX = 16;  *alignY = 8;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 2048;
               return(ATL_zger2k__2);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 4;   *minN = 2;
   *mu = 4;     *nu = 2;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 2048;
   return(ATL_zger2k__900002);
}

#define ATL_GetPartR2(A_, lda_, mb_, nb_) { (mb_) = 340; (nb_) = 2; }

#endif  /* end protection around header file contents */
