#include "igen_lib.h"
#include "igen_math.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

static f64_I _y1[1024];
static f64_I _y2[1024];

static void WeightedSum_opt(f64_I *W, f64_I *b, f64_I *x, f64_I *y, int n_in,
                            int num_n) {

  for (int i = 0; i < num_n; i += 2) {
    f64_I y00 = {-0.0, 0.0};
    f64_I y01 = {-0.0, 0.0};
    f64_I y02 = {-0.0, 0.0};
    f64_I y03 = {-0.0, 0.0};
    f64_I y10 = {-0.0, 0.0};
    f64_I y11 = {-0.0, 0.0};
    f64_I y12 = {-0.0, 0.0};
    f64_I y13 = {-0.0, 0.0};
    for (int j = 0; j < n_in; j += 4) {
      f64_I _t1 = _ia_mul_f64(W[(i + 0) * n_in + j + 0], x[j + 0]);
      y00 = _ia_add_f64(y00, _t1);
      f64_I _t2 = _ia_mul_f64(W[(i + 0) * n_in + j + 1], x[j + 1]);
      y01 = _ia_add_f64(y01, _t2);
      f64_I _t3 = _ia_mul_f64(W[(i + 0) * n_in + j + 2], x[j + 2]);
      y02 = _ia_add_f64(y02, _t3);
      f64_I _t4 = _ia_mul_f64(W[(i + 0) * n_in + j + 3], x[j + 3]);
      y03 = _ia_add_f64(y03, _t4);

      f64_I _t5 = _ia_mul_f64(W[(i + 1) * n_in + j + 0], x[j + 0]);
      y10 = _ia_add_f64(y10, _t5);
      f64_I _t6 = _ia_mul_f64(W[(i + 1) * n_in + j + 1], x[j + 1]);
      y11 = _ia_add_f64(y11, _t6);
      f64_I _t7 = _ia_mul_f64(W[(i + 1) * n_in + j + 2], x[j + 2]);
      y12 = _ia_add_f64(y12, _t7);
      f64_I _t8 = _ia_mul_f64(W[(i + 1) * n_in + j + 3], x[j + 3]);
      y13 = _ia_add_f64(y13, _t8);
    }
    f64_I _t9 = _ia_add_f64(b[i + 0], y00);
    f64_I _t10 = _ia_add_f64(_t9, y01);
    f64_I _t11 = _ia_add_f64(_t10, y02);
    y[i + 0] = _ia_add_f64(_t11, y03);
    f64_I _t12 = _ia_add_f64(b[i + 1], y10);
    f64_I _t13 = _ia_add_f64(_t12, y11);
    f64_I _t14 = _ia_add_f64(_t13, y12);
    y[i + 1] = _ia_add_f64(_t14, y13);
  }
}
static void WeightedSum(f64_I *W, f64_I *b, f64_I *x, f64_I *y, int n_in,
                        int num_n) {

  for (int i = 0; i < num_n; ++i) {
    y[i] = b[i];
    for (int j = 0; j < n_in; ++j) {
      f64_I _t15 = _ia_mul_f64(W[i * n_in + j], x[j]);
      y[i] = _ia_add_f64(y[i], _t15);
    }
  }
}

static void sigmoid_exp(f64_I *y, int n) {
  for (int i = 0; i < n; ++i) {
    f64_I _t16 = _ia_neg_f64(y[i]);
    f64_I _t17 = _ia_set_f64(-5.0, 5.0);
    f64_I _t18 = _ia_mul_f64(_t16, _t17);
    f64_I _t19 = _ia_set_f64(-1.0, 1.0);
    f64_I _t20 = _ia_exp_f64(_t18);
    f64_I _t21 = _ia_add_f64(_t19, _t20);
    y[i] = _ia_div_f64(y[i], _t21);
  }
}

static void sigmoid_relu(f64_I *y, int n) {
  for (int i = 0; i < n; ++i) {
    f64_I _t22 = _ia_set_f64(-0.0, 0.0);
    f64_I _t23 = _ia_set_f64(-0.0, 0.0);
    y[i] = _ia_cmpgt_f64(y[i], _t22) ? y[i] : _t23;
  }
}

static void processLayer(f64_I *W, f64_I *b, f64_I *x, f64_I *y, int n_in,
                         int num_n) {
  WeightedSum_opt(W, b, x, y, n_in, num_n);
  sigmoid_exp(y, num_n);
}
void FFNN(f64_I **W, f64_I **b, f64_I *x, f64_I *y, int n_in, int n_out,
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
