#include "math.h"

#define MAX_LAYER_SIZE 1024

/* Auxiliary arrays */
static double _y1[MAX_LAYER_SIZE];
static double _y2[MAX_LAYER_SIZE];

static void WeightedSum_opt(double* W, double* b, double* x, double* y, int n_in, int num_n) {
    /* Handle remaining */
    for (int i = 0; i < num_n; i+=2) {
        double y00 = 0.0, y01 = 0.0, y02 = 0.0, y03 = 0.0;
        double y10 = 0.0, y11 = 0.0, y12 = 0.0, y13 = 0.0;
        for (int j = 0; j < n_in; j+=4) {
            y00 += W[(i+0)*n_in + j+0] * x[j+0];
            y01 += W[(i+0)*n_in + j+1] * x[j+1];
            y02 += W[(i+0)*n_in + j+2] * x[j+2];
            y03 += W[(i+0)*n_in + j+3] * x[j+3];

            y10 += W[(i+1)*n_in + j+0] * x[j+0];
            y11 += W[(i+1)*n_in + j+1] * x[j+1];
            y12 += W[(i+1)*n_in + j+2] * x[j+2];
            y13 += W[(i+1)*n_in + j+3] * x[j+3];
        }
        y[i+0] = b[i+0] + y00 + y01 + y02 + y03;
        y[i+1] = b[i+1] + y10 + y11 + y12 + y13;
    }
}

///
/// \param W : Matrix of weights of layer
/// \param b : bias vector
/// \param x : Input values of the layer.
/// \param y : Output values.
/// \param n_in: size of input vector x
/// \param num_n: number of neurones in layer
static void WeightedSum(double* W, double* b, double* x, double* y, int n_in, int num_n) {
    /* Perform matrix vector product */
    for (int i = 0; i < num_n; ++i) {
        y[i] = b[i];                        // add bias
        for (int j = 0; j < n_in; ++j) {
            y[i] = y[i] + W[i*n_in + j]*x[j];
        }
    }
}

static void sigmoid_exp(double* y, int n) {
    for (int i = 0; i < n; ++i) {
        y[i] = y[i] / (1.0 + exp(-y[i]*5.0));
    }
}

static void sigmoid_relu(double* y, int n) {
    for (int i = 0; i < n; ++i) {
        y[i] = y[i] > 0.0 ? y[i] : 0.0;
    }
}

static void processLayer(double* W, double* b, double* x, double* y, int n_in, int num_n) {
    WeightedSum_opt(W, b, x, y, n_in, num_n);
    sigmoid_exp(y, num_n);
}

///
/// \param W : W[i] is the matrix of weights of layer i (the matrix is flatten into a vector).
/// \param b : b[i] is the bias' vector of layer i.
/// \param x : Input values to the network.
/// \param y : Output array.
/// \param n : Size of the input.
/// \param m : Size of the output.
/// \param num_l : Number of layers.
/// \param num_n : Number of neurons per layer (input and hidden layers).
void FFNN(double** W, double**b, double* x, double* y, int n_in, int n_out, int num_l,  int num_n) {
    double* ptr_y1 = _y1;
    double* ptr_y2 = _y2;

    /* Process first layer */
    processLayer(W[0], b[0], x, ptr_y1, n_in, num_n);

    /* Process hidden layers */
    for (int l = 1; l < num_l-1; ++l) {
        processLayer(W[l], b[l], ptr_y1, ptr_y2, num_n, num_n);
        double* t = ptr_y1;
        ptr_y1 = ptr_y2;
        ptr_y2 = t;
    }

    /* Process output layer */
    processLayer(W[num_l-1], b[num_l-1], ptr_y1, ptr_y2, num_n, n_out);

    /* Copy result to the output vector */
    for (int i = 0; i < n_out; ++i) {
        y[i] = ptr_y2[i];
    }
}
