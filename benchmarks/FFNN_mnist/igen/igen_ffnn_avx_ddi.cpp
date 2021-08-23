#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"
#include "igen_dd_math.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

static dd_I _y1[1024];
static dd_I _y2[1024];
static void WeightedSum_v1(dd_I *W, dd_I *b, dd_I *x, dd_I *y, int n_in,
                           int num_n) {

  int i = 0;
  for (; i + 8 < num_n; i += 8) {
    dd_I y0;
    dd_I y1;
    dd_I y2;
    dd_I y3;
    dd_I y4;
    dd_I y5;
    dd_I y6;
    dd_I y7;
    y0 = b[i + 0];
    y4 = b[i + 4];
    y1 = b[i + 1];
    y5 = b[i + 5];
    y2 = b[i + 2];
    y6 = b[i + 6];
    y3 = b[i + 3];
    y7 = b[i + 7];
    for (int j = 0; j < n_in; ++j) {
      dd_I _t1 = _ia_mul_dd(W[(i + 0) * n_in + j], x[j]);
      y0 = _ia_add_dd(y0, _t1);
      dd_I _t2 = _ia_mul_dd(W[(i + 4) * n_in + j], x[j]);
      y4 = _ia_add_dd(y4, _t2);
      dd_I _t3 = _ia_mul_dd(W[(i + 1) * n_in + j], x[j]);
      y1 = _ia_add_dd(y1, _t3);
      dd_I _t4 = _ia_mul_dd(W[(i + 5) * n_in + j], x[j]);
      y5 = _ia_add_dd(y5, _t4);
      dd_I _t5 = _ia_mul_dd(W[(i + 2) * n_in + j], x[j]);
      y2 = _ia_add_dd(y2, _t5);
      dd_I _t6 = _ia_mul_dd(W[(i + 6) * n_in + j], x[j]);
      y6 = _ia_add_dd(y6, _t6);
      dd_I _t7 = _ia_mul_dd(W[(i + 3) * n_in + j], x[j]);
      y3 = _ia_add_dd(y3, _t7);
      dd_I _t8 = _ia_mul_dd(W[(i + 7) * n_in + j], x[j]);
      y7 = _ia_add_dd(y7, _t8);
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
      dd_I _t9 = _ia_mul_dd(W[i * n_in + j], x[j]);
      y[i] = _ia_add_dd(y[i], _t9);
    }
  }
}

static void WeightedSum_v2(dd_I *W, dd_I *b, dd_I *x, dd_I *y, int n_in,
                           int num_n) {

  for (int i = 0; i < num_n; i += 2) {
    dd_I y00;
    dd_I y01;
    dd_I y02;
    dd_I y03;
    dd_I y10;
    dd_I y11;
    dd_I y12;
    dd_I y13;
    for (int j = 0; j < n_in; j += 4) {
      dd_I _t10 = _ia_mul_dd(W[(i + 0) * n_in + j + 0], x[j + 0]);
      y00 = _ia_add_dd(y00, _t10);
      dd_I _t11 = _ia_mul_dd(W[(i + 0) * n_in + j + 1], x[j + 1]);
      y01 = _ia_add_dd(y01, _t11);
      dd_I _t12 = _ia_mul_dd(W[(i + 0) * n_in + j + 2], x[j + 2]);
      y02 = _ia_add_dd(y02, _t12);
      dd_I _t13 = _ia_mul_dd(W[(i + 0) * n_in + j + 3], x[j + 3]);
      y03 = _ia_add_dd(y03, _t13);

      dd_I _t14 = _ia_mul_dd(W[(i + 1) * n_in + j + 0], x[j + 0]);
      y10 = _ia_add_dd(y10, _t14);
      dd_I _t15 = _ia_mul_dd(W[(i + 1) * n_in + j + 1], x[j + 1]);
      y11 = _ia_add_dd(y11, _t15);
      dd_I _t16 = _ia_mul_dd(W[(i + 1) * n_in + j + 2], x[j + 2]);
      y12 = _ia_add_dd(y12, _t16);
      dd_I _t17 = _ia_mul_dd(W[(i + 1) * n_in + j + 3], x[j + 3]);
      y13 = _ia_add_dd(y13, _t17);
    }
    dd_I _t18 = _ia_add_dd(b[i + 0], y00);
    dd_I _t19 = _ia_add_dd(_t18, y01);
    dd_I _t20 = _ia_add_dd(_t19, y02);
    y[i + 0] = _ia_add_dd(_t20, y03);
    dd_I _t21 = _ia_add_dd(b[i + 1], y10);
    dd_I _t22 = _ia_add_dd(_t21, y11);
    dd_I _t23 = _ia_add_dd(_t22, y12);
    y[i + 1] = _ia_add_dd(_t23, y13);
  }
}

inline dd_I hsum_double_avx(ddi_4 v) {
  ddi_2 vlow = _igen_dd_mm256_castpd256_pd128(v);
  ddi_2 vhigh = _igen_dd_mm256_extractf128_pd(v, 1);
  vlow = _igen_dd_mm_add_pd(vlow, vhigh);

  ddi_2 high64 = _igen_dd_mm_unpackhi_pd(vlow, vlow);
  ddi_2 _t24 = _igen_dd_mm_add_sd(vlow, high64);
  dd_I _ret;
  _ret = _igen_dd_mm_cvtsd_f64(_t24);
  return _ret;
}

static void WeightedSum(dd_I *W, dd_I *b, dd_I *x, dd_I *y, int n_in,
                        int num_n) {

  for (int i = 0; i < num_n; i += 2) {
    ddi_4 y0 = _igen_dd_mm256_setzero_pd();
    ddi_4 y1 = _igen_dd_mm256_setzero_pd();
    for (int j = 0; j < n_in; j += 4) {
      ddi_4 Wi0j0 = _igen_dd_mm256_load_pd(&W[(i + 0) * n_in + j + 0]);
      ddi_4 Wi1j0 = _igen_dd_mm256_load_pd(&W[(i + 1) * n_in + j + 0]);
      ddi_4 x_j0 = _igen_dd_mm256_load_pd(&x[j + 0]);
      y0 = _igen_dd_mm256_fmadd_pd(Wi0j0, x_j0, y0);
      y1 = _igen_dd_mm256_fmadd_pd(Wi1j0, x_j0, y1);
    }
    dd_I _t25 = hsum_double_avx(y0);
    y[i + 0] = _ia_add_dd(b[i + 0], _t25);
    dd_I _t26 = hsum_double_avx(y1);
    y[i + 1] = _ia_add_dd(b[i + 1], _t26);
  }
}

static void sigmoid_exp(dd_I *y, int n) {
  for (int i = 0; i < n; ++i) {
    dd_I _t27 = _ia_neg_dd(y[i]);
    dd_I _t28 = _ia_set_dd(-5.0, 0.0, 5.0, 0.0);
    dd_I _t29 = _ia_mul_dd(_t27, _t28);
    dd_I _t30 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
    dd_I _t31 = _ia_exp_dd(_t29);
    dd_I _t32 = _ia_add_dd(_t30, _t31);
    y[i] = _ia_div_dd(y[i], _t32);
  }
}

static void sigmoid_relu(dd_I *y, int n) {
  for (int i = 0; i < n; ++i) {

    dd_I _t33 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    dd_I _t34 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    y[i] = _ia_cmpgt_dd(y[i], _t33) ? y[i] : _t34;
  }
}

static void processLayer(dd_I *W, dd_I *b, dd_I *x, dd_I *y, int n_in,
                         int num_n) {
  WeightedSum(W, b, x, y, n_in, num_n);
  sigmoid_exp(y, num_n);
}
void FFNN_Vec(dd_I **W, dd_I **b, dd_I *x, dd_I *y, int n_in, int n_out,
              int num_l, int num_n) {
  dd_I *ptr_y1 = _y1;
  dd_I *ptr_y2 = _y2;

  processLayer(W[0], b[0], x, ptr_y1, n_in, num_n);

  for (int l = 1; l < num_l - 1; ++l) {
    processLayer(W[l], b[l], ptr_y1, ptr_y2, num_n, num_n);
    dd_I *t = ptr_y1;
    ptr_y1 = ptr_y2;
    ptr_y2 = t;
  }

  processLayer(W[num_l - 1], b[num_l - 1], ptr_y1, ptr_y2, num_n, n_out);

  for (int i = 0; i < n_out; ++i) {
    y[i] = ptr_y2[i];
  }
}
