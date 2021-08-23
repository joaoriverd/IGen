#ifndef ATLAS_PCA_H
   #define ATLAS_PCA_H
/*
 * Only x86 is known to be strongly ordered (ATLAS does not use the special
 * writes that make it weakly-ordered).
 */
   #define ATL_membarrier
   #if defined(ATL_GAS_x8632) || defined(ATL_GAS_x8632)
      #define ATL_USEPCA 1
   #elif defined(ATL_USEPCA)
      #undef ATL_USEPCA
   #endif

#endif
