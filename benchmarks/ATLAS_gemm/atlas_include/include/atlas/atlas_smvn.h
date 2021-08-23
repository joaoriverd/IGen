#ifndef ATLAS_SMVN_L0_H
#define ATLAS_SMVN_L0_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

#endif
void ATL_smvnk__900002(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__900002_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

static ATL_mvkern_t ATL_GetMVNKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, int *DOTBASED,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 16;   *minN = 4;
   *mu = 16;     *nu = 4;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 32768;
   *mvk_b0 = ATL_smvnk__900002_b0;
   *DOTBASED = 0;
   return(ATL_smvnk__900002);
}

#define ATL_GetPartMVN(A_, lda_, mb_, nb_) { *(mb_) = 3264; *(nb_) = 4; }

#endif  /* end protection around header file contents */
