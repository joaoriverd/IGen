#include "igen_immintrin.h"
#include "igen_lib.h"
#include "igen_math.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

static f64_I _y1[1024];
static f64_I _y2[1024];
static void WeightedSum_v1(f64_I *W, f64_I *b, f64_I *x, f64_I *y, int n_in,
                           int num_n) {

  int i = 0;
  for (; i + 8 < num_n; i += 8) {
    f64_I y0;
    f64_I y1;
    f64_I y2;
    f64_I y3;
    f64_I y4;
    f64_I y5;
    f64_I y6;
    f64_I y7;
    y0 = b[i + 0];
    y4 = b[i + 4];
    y1 = b[i + 1];
    y5 = b[i + 5];
    y2 = b[i + 2];
    y6 = b[i + 6];
    y3 = b[i + 3];
    y7 = b[i + 7];
    for (int j = 0; j < n_in; ++j) {
      f64_I _t1 = _ia_mul_f64(W[(i + 0) * n_in + j], x[j]);
      y0 = _ia_add_f64(y0, _t1);
      f64_I _t2 = _ia_mul_f64(W[(i + 4) * n_in + j], x[j]);
      y4 = _ia_add_f64(y4, _t2);
      f64_I _t3 = _ia_mul_f64(W[(i + 1) * n_in + j], x[j]);
      y1 = _ia_add_f64(y1, _t3);
      f64_I _t4 = _ia_mul_f64(W[(i + 5) * n_in + j], x[j]);
      y5 = _ia_add_f64(y5, _t4);
      f64_I _t5 = _ia_mul_f64(W[(i + 2) * n_in + j], x[j]);
      y2 = _ia_add_f64(y2, _t5);
      f64_I _t6 = _ia_mul_f64(W[(i + 6) * n_in + j], x[j]);
      y6 = _ia_add_f64(y6, _t6);
      f64_I _t7 = _ia_mul_f64(W[(i + 3) * n_in + j], x[j]);
      y3 = _ia_add_f64(y3, _t7);
      f64_I _t8 = _ia_mul_f64(W[(i + 7) * n_in + j], x[j]);
      y7 = _ia_add_f64(y7, _t8);
    }
    y[i + 0] = y0;
    y[i + 4] = y4;
    y[i + 1] = y1;
    y[i + 5] = y5;
    y[i + 2] = y2;
    y[i + 6] = y6;
    y[i + 3] = y3;
    y[i + 7] = y7;
  }

  for (; i < num_n; ++i) {
    y[i] = b[i];
    for (int j = 0; j < n_in; ++j) {
      f64_I _t9 = _ia_mul_f64(W[i * n_in + j], x[j]);
      y[i] = _ia_add_f64(y[i], _t9);
    }
  }
}

static void WeightedSum_v2(f64_I *W, f64_I *b, f64_I *x, f64_I *y, int n_in,
                           int num_n) {

  for (int i = 0; i < num_n; i += 2) {
    f64_I y00;
    f64_I y01;
    f64_I y02;
    f64_I y03;
    f64_I y10;
    f64_I y11;
    f64_I y12;
    f64_I y13;
    for (int j = 0; j < n_in; j += 4) {
      f64_I _t10 = _ia_mul_f64(W[(i + 0) * n_in + j + 0], x[j + 0]);
      y00 = _ia_add_f64(y00, _t10);
      f64_I _t11 = _ia_mul_f64(W[(i + 0) * n_in + j + 1], x[j + 1]);
      y01 = _ia_add_f64(y01, _t11);
      f64_I _t12 = _ia_mul_f64(W[(i + 0) * n_in + j + 2], x[j + 2]);
      y02 = _ia_add_f64(y02, _t12);
      f64_I _t13 = _ia_mul_f64(W[(i + 0) * n_in + j + 3], x[j + 3]);
      y03 = _ia_add_f64(y03, _t13);

      f64_I _t14 = _ia_mul_f64(W[(i + 1) * n_in + j + 0], x[j + 0]);
      y10 = _ia_add_f64(y10, _t14);
      f64_I _t15 = _ia_mul_f64(W[(i + 1) * n_in + j + 1], x[j + 1]);
      y11 = _ia_add_f64(y11, _t15);
      f64_I _t16 = _ia_mul_f64(W[(i + 1) * n_in + j + 2], x[j + 2]);
      y12 = _ia_add_f64(y12, _t16);
      f64_I _t17 = _ia_mul_f64(W[(i + 1) * n_in + j + 3], x[j + 3]);
      y13 = _ia_add_f64(y13, _t17);
    }
    f64_I _t18 = _ia_add_f64(b[i + 0], y00);
    f64_I _t19 = _ia_add_f64(_t18, y01);
    f64_I _t20 = _ia_add_f64(_t19, y02);
    y[i + 0] = _ia_add_f64(_t20, y03);
    f64_I _t21 = _ia_add_f64(b[i + 1], y10);
    f64_I _t22 = _ia_add_f64(_t21, y11);
    f64_I _t23 = _ia_add_f64(_t22, y12);
    y[i + 1] = _ia_add_f64(_t23, y13);
  }
}

inline f64_I hsum_double_avx(m256di_2 v) {
  m256di_1 vlow = _igen_mm256_castpd256_pd128(v);
  m256di_1 vhigh = _igen_mm256_extractf128_pd(v, 1);
  vlow = _igen_mm_add_pd(vlow, vhigh);

  m256di_1 high64 = _igen_mm_unpackhi_pd(vlow, vlow);
  m256di_1 _t24 = _igen_mm_add_sd(vlow, high64);
  f64_I _ret;
  _ret = _igen_mm_cvtsd_f64(_t24);
  return _ret;
}

static void WeightedSum(f64_I *W, f64_I *b, f64_I *x, f64_I *y, int n_in,
                        int num_n) {

  for (int i = 0; i < num_n; i += 2) {
    m256di_2 y0 = _igen_mm256_setzero_pd();
    m256di_2 y1 = _igen_mm256_setzero_pd();
    for (int j = 0; j < n_in; j += 4) {
      m256di_2 Wi0j0 = _igen_mm256_load_pd(&W[(i + 0) * n_in + j + 0]);
      m256di_2 Wi1j0 = _igen_mm256_load_pd(&W[(i + 1) * n_in + j + 0]);
      m256di_2 x_j0 = _igen_mm256_load_pd(&x[j + 0]);
      y0 = _igen_mm256_fmadd_pd(Wi0j0, x_j0, y0);
      y1 = _igen_mm256_fmadd_pd(Wi1j0, x_j0, y1);
    }
    f64_I _t25 = hsum_double_avx(y0);
    y[i + 0] = _ia_add_f64(b[i + 0], _t25);
    f64_I _t26 = hsum_double_avx(y1);
    y[i + 1] = _ia_add_f64(b[i + 1], _t26);
  }
}

static void sigmoid_exp(f64_I *y, int n) {
  for (int i = 0; i < n; ++i) {
    f64_I _t27 = _ia_neg_f64(y[i]);
    f64_I _t28 = _ia_set_f64(-5.0, 5.0);
    f64_I _t29 = _ia_mul_f64(_t27, _t28);
    f64_I _t30 = _ia_set_f64(-1.0, 1.0);
    f64_I _t31 = _ia_exp_f64(_t29);
    f64_I _t32 = _ia_add_f64(_t30, _t31);
    y[i] = _ia_div_f64(y[i], _t32);
  }
}

static void sigmoid_relu(f64_I *y, int n) {
  for (int i = 0; i < n; ++i) {

    f64_I _t33 = _ia_set_f64(-0.0, 0.0);
    f64_I _t34 = _ia_set_f64(-0.0, 0.0);
    y[i] = _ia_cmpgt_f64(y[i], _t33) ? y[i] : _t34;
  }
}

static void processLayer(f64_I *W, f64_I *b, f64_I *x, f64_I *y, int n_in,
                         int num_n) {
  WeightedSum(W, b, x, y, n_in, num_n);
  sigmoid_exp(y, num_n);
}
void FFNN_Vec(f64_I **W, f64_I **b, f64_I *x, f64_I *y, int n_in, int n_out,
              int num_l, int num_n) {
  f64_I *ptr_y1 = _y1;
  f64_I *ptr_y2 = _y2;

  processLayer(W[0], b[0], x, ptr_y1, n_in, num_n);

  for (int l = 1; l < num_l - 1; ++l) {
    processLayer(W[l], b[l], ptr_y1, ptr_y2, num_n, num_n);
    f64_I *t = ptr_y1;
    ptr_y1 = ptr_y2;
    ptr_y2 = t;
  }

  processLayer(W[num_l - 1], b[num_l - 1], ptr_y1, ptr_y2, num_n, n_out);

  for (int i = 0; i < n_out; ++i) {
    y[i] = ptr_y2[i];
  }
}
