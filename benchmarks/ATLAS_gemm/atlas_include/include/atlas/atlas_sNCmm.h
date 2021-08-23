#ifndef SMM_H
   #define SMM_H

   #define ATL_mmMULADD
   #define ATL_mmLAT 8
   #define ATL_mmMU  2
   #define ATL_mmNU  5
   #define ATL_mmKU  1
   #define MB 72
   #define NB 72
   #define KB 72
   #define NBNB 5184
   #define MBNB 5184
   #define MBKB 5184
   #define NBKB 5184
   #define NB2 144
   #define NBNB2 10368

   #define ATL_MulByNB(N_) ((N_) * 72)
   #define ATL_DivByNB(N_) ((N_) / 72)
   #define ATL_MulByNBNB(N_) ((N_) * 5184)

#endif
