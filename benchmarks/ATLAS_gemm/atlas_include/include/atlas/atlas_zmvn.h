#ifndef ATLAS_ZMVN_L0_H
#define ATLAS_ZMVN_L0_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);

#endif
void ATL_zmvnk__900003(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_zmvnk__900003_b0(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_zmvnk__900002(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_zmvnk__900002_b0(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);

static ATL_mvkern_t ATL_GetMVNKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, int *DOTBASED,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 4)
         {
            if (M >= 8)
            {
               *minM = 8;   *minN = 4;
               *mu = 8;     *nu = 4;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 0;
               *mvk_b0 = ATL_zmvnk__900003_b0;
               *DOTBASED = 0;
               return(ATL_zmvnk__900003);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 8;   *minN = 4;
   *mu = 8;     *nu = 4;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 0;
   *mvk_b0 = ATL_zmvnk__900002_b0;
   *DOTBASED = 0;
   return(ATL_zmvnk__900002);
}

#define ATL_GetPartMVN(A_, lda_, mb_, nb_) { *(mb_) = 0; *(nb_) = 0; }

#endif  /* end protection around header file contents */
