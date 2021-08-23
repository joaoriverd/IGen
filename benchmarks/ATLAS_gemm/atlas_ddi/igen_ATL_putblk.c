#include "atlas_lvl3.h"
#include "atlas_misc.h"
#include "igen_dd_lib.h"

void ATL_dputblk_b1(int M, int N, dd_I *V, dd_I *C, int ldc, dd_I beta0) {
  dd_I *st0 = V + (M * N);
  dd_I *st1 = V + (M);
  ldc -= M;
  do {

    do {
      *C = _ia_add_dd(*C, *V);
      C++;
    } while (++V != st1);
    st1 += M;
    C += ldc;
  } while (V != st0);
}
