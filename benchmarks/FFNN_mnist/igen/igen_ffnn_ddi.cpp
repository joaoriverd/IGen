#include "igen_dd_lib.h"
#include "igen_dd_math.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

static dd_I _y1[1024];
static dd_I _y2[1024];

static void WeightedSum_opt(dd_I *W, dd_I *b, dd_I *x, dd_I *y, int n_in,
                            int num_n) {

  for (int i = 0; i < num_n; i += 2) {
    dd_I y00 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    dd_I y01 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    dd_I y02 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    dd_I y03 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    dd_I y10 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    dd_I y11 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    dd_I y12 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    dd_I y13 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    for (int j = 0; j < n_in; j += 4) {
      dd_I _t1 = _ia_mul_dd(W[(i + 0) * n_in + j + 0], x[j + 0]);
      y00 = _ia_add_dd(y00, _t1);
      dd_I _t2 = _ia_mul_dd(W[(i + 0) * n_in + j + 1], x[j + 1]);
      y01 = _ia_add_dd(y01, _t2);
      dd_I _t3 = _ia_mul_dd(W[(i + 0) * n_in + j + 2], x[j + 2]);
      y02 = _ia_add_dd(y02, _t3);
      dd_I _t4 = _ia_mul_dd(W[(i + 0) * n_in + j + 3], x[j + 3]);
      y03 = _ia_add_dd(y03, _t4);

      dd_I _t5 = _ia_mul_dd(W[(i + 1) * n_in + j + 0], x[j + 0]);
      y10 = _ia_add_dd(y10, _t5);
      dd_I _t6 = _ia_mul_dd(W[(i + 1) * n_in + j + 1], x[j + 1]);
      y11 = _ia_add_dd(y11, _t6);
      dd_I _t7 = _ia_mul_dd(W[(i + 1) * n_in + j + 2], x[j + 2]);
      y12 = _ia_add_dd(y12, _t7);
      dd_I _t8 = _ia_mul_dd(W[(i + 1) * n_in + j + 3], x[j + 3]);
      y13 = _ia_add_dd(y13, _t8);
    }
    dd_I _t9 = _ia_add_dd(b[i + 0], y00);
    dd_I _t10 = _ia_add_dd(_t9, y01);
    dd_I _t11 = _ia_add_dd(_t10, y02);
    y[i + 0] = _ia_add_dd(_t11, y03);
    dd_I _t12 = _ia_add_dd(b[i + 1], y10);
    dd_I _t13 = _ia_add_dd(_t12, y11);
    dd_I _t14 = _ia_add_dd(_t13, y12);
    y[i + 1] = _ia_add_dd(_t14, y13);
  }
}
static void WeightedSum(dd_I *W, dd_I *b, dd_I *x, dd_I *y, int n_in,
                        int num_n) {

  for (int i = 0; i < num_n; ++i) {
    y[i] = b[i];
    for (int j = 0; j < n_in; ++j) {
      dd_I _t15 = _ia_mul_dd(W[i * n_in + j], x[j]);
      y[i] = _ia_add_dd(y[i], _t15);
    }
  }
}

static void sigmoid_exp(dd_I *y, int n) {
  for (int i = 0; i < n; ++i) {
    dd_I _t16 = _ia_neg_dd(y[i]);
    dd_I _t17 = _ia_set_dd(-5.0, 0.0, 5.0, 0.0);
    dd_I _t18 = _ia_mul_dd(_t16, _t17);
    dd_I _t19 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
    dd_I _t20 = _ia_exp_dd(_t18);
    dd_I _t21 = _ia_add_dd(_t19, _t20);
    y[i] = _ia_div_dd(y[i], _t21);
  }
}

static void sigmoid_relu(dd_I *y, int n) {
  for (int i = 0; i < n; ++i) {
    dd_I _t22 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    dd_I _t23 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
    y[i] = _ia_cmpgt_dd(y[i], _t22) ? y[i] : _t23;
  }
}

static void processLayer(dd_I *W, dd_I *b, dd_I *x, dd_I *y, int n_in,
                         int num_n) {
  WeightedSum_opt(W, b, x, y, n_in, num_n);
  sigmoid_exp(y, num_n);
}
void FFNN(dd_I **W, dd_I **b, dd_I *x, dd_I *y, int n_in, int n_out, int num_l,
          int num_n) {
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
