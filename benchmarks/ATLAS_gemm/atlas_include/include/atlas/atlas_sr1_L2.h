#ifndef ATLAS_SR1_L2_H
#define ATLAS_SR1_L2_H

#include "atlas_type.h"

typedef void (*ATL_r1kern_t)
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);
void ATL_sgerk__900009
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);
void ATL_sgerk__900003
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);
void ATL_sgerk__900008
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
         if (N >= 12)
         {
            if (M >= 16)
            {
               *minM = 16;   *minN = 12;
               *mu = 16;     *nu = 12;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 57344;
               return(ATL_sgerk__900009);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 4)
         {
            if (M >= 16)
            {
               *minM = 16;   *minN = 4;
               *mu = 16;     *nu = 4;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 57344;
               return(ATL_sgerk__900003);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 16;   *minN = 12;
   *mu = 16;     *nu = 12;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 57344;
   return(ATL_sgerk__900008);
}

#define ATL_GetPartR1(A_, lda_, mb_, nb_) { (mb_) = 2192; (nb_) = 12; }

#endif  /* end protection around header file contents */
