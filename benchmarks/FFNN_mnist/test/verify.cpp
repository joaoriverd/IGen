#include <iostream>
#include <cfenv>
#include "parse_mnist_nn.h"
#include "ffnn.h"
#include "igen_lib.h"

using namespace std;
void FFNN_Vec(double** W, double**b, double* x, double* y, int n_in, int n_out, int num_l,  int num_n);
void FFNN(f64_I **W, f64_I **b, f64_I *x, f64_I *y, int n_in, int n_out, int num_l, int num_n);
void FFNN_Vec(f64_I **W, f64_I **b, f64_I *x, f64_I *y, int n_in, int n_out, int num_l, int num_n);
void FFNN(dd_I **W , dd_I **b , dd_I *x , dd_I *y , int n_in, int n_out, int num_l, int num_n);
void FFNN_Vec(dd_I **W, dd_I **b, dd_I *x, dd_I *y, int n_in, int n_out, int num_l, int num_n);

void verify_ffnn() {
    cout << "Running sound verification: ";

    __attribute__((aligned(32))) double   X[MNIST_NN_INPUT_SIZE ];
    __attribute__((aligned(32))) double   Y[MNIST_NN_OUTPUT_SIZE];
    __attribute__((aligned(32))) f64_I   Xi[MNIST_NN_INPUT_SIZE ];
    __attribute__((aligned(32))) f64_I   Yi[MNIST_NN_OUTPUT_SIZE];
    __attribute__((aligned(32))) dd_I   Xdd[MNIST_NN_INPUT_SIZE ];
    __attribute__((aligned(32))) dd_I   Ydd[MNIST_NN_OUTPUT_SIZE];

    mnistFFNN<double> nn(MNIST_NN_9_200);
    mnistFFNN<f64_I> nni(MNIST_NN_9_200);
    mnistFFNN<dd_I> nndd(MNIST_NN_9_200);
    for (int id = 0; id < NUM_INPUT_FILES/5; id++) {
        fesetround(FE_TONEAREST);
        parseImageMnist(X, id);
        FFNN(nn.W, nn.b, X, Y, nn.n_in, nn.n_out, nn.num_l, nn.num_n);
        fesetround(FE_UPWARD);

        /* f64i */
        parseImageMnist(Xi, id);
        FFNN(nni.W, nni.b, Xi, Yi, nni.n_in, nni.n_out, nni.num_l, nni.num_n);

        /* ddi */
        parseImageMnist(Xdd, id);
        FFNN(nndd.W, nndd.b, Xdd, Ydd, nndd.n_in, nndd.n_out, nndd.num_l, nndd.num_n);

        /* Check that result is correct and bound not too big */
        for (int i = 0; i < MNIST_NN_OUTPUT_SIZE; ++i) {
            double Yd_l = _ia_get_lo_f64(Yi[i]);
            double Yd_u = _ia_get_up_f64(Yi[i]);
            double Ydd_l = _ia_get_lo_dd (Ydd[i]);
            double Ydd_u = _ia_get_up_dd (Ydd[i]);

            if (Ydd_l < Yd_l || Yd_u < Ydd_u) {
                cerr << "Error: DD losing more precision than double." << endl;
                exit(1);
            }

            if (Y[i] < Yd_l || Yd_u < Y[i]) {
                cerr << "Error: Test is not sound" << endl;
                exit(1);
            }
        }
    }

    cout << "Passed" << endl;
}