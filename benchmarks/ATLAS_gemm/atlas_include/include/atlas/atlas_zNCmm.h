#ifndef ZMM_H
   #define ZMM_H

   #define ATL_mmMULADD
   #define ATL_mmLAT 8
   #define ATL_mmMU  12
   #define ATL_mmNU  1
   #define ATL_mmKU  6
   #define MB 24
   #define NB 24
   #define KB 24
   #define NBNB 576
   #define MBNB 576
   #define MBKB 576
   #define NBKB 576
   #define NB2 48
   #define NBNB2 1152

   #define ATL_MulByNB(N_) ((N_) * 24)
   #define ATL_DivByNB(N_) ((N_) / 24)
   #define ATL_MulByNBNB(N_) ((N_) * 576)

#endif
