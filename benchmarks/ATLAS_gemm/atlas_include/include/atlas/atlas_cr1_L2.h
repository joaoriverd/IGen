#ifndef ATLAS_CR1_L2_H
#define ATLAS_CR1_L2_H

#include "atlas_type.h"

typedef void (*ATL_r1kern_t)
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);
void ATL_cgerk__900008
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);
void ATL_cgerk__900007
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);

static ATL_r1kern_t ATL_GetR1Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 6)
         {
            if (M >= 8)
            {
               *minM = 8;   *minN = 6;
               *mu = 8;     *nu = 6;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 14336;
               return(ATL_cgerk__900008);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 8;   *minN = 6;
   *mu = 8;     *nu = 6;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 14336;
   return(ATL_cgerk__900007);
}

#define ATL_GetPartR1(A_, lda_, mb_, nb_) { (mb_) = 1016; (nb_) = 6; }

#endif  /* end protection around header file contents */
