#include "atlas_lvl3.h"
#include "atlas_misc.h"
#include "igen_lib.h"

void ATL_dputblk_b1(int M, int N, f64_I *V, f64_I *C, int ldc, f64_I beta0) {
  f64_I *st0 = V + (M * N);
  f64_I *st1 = V + (M);
  ldc -= M;
  do {

    do {
      *C = _ia_add_f64(*C, *V);
      C++;
    } while (++V != st1);
    st1 += M;
    C += ldc;
  } while (V != st0);
}
