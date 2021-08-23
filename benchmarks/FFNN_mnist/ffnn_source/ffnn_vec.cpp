#include <math.h>
#include <immintrin.h>

#define MAX_LAYER_SIZE 1024

/* Auxiliary arrays */
static double _y1[MAX_LAYER_SIZE];
static double _y2[MAX_LAYER_SIZE];

///
/// \param W : Matrix of weights of layer
/// \param b : bias vector
/// \param x : Input values of the layer.
/// \param y : Output values.
/// \param n_in: size of input vector x
/// \param num_n: number of neurones in layer
static void WeightedSum_v1(double* W, double* b, double* x, double* y, int n_in, int num_n) {
    /* Perform matrix vector product */
    int i = 0;
    for (; i + 8 < num_n; i += 8) {
        double y0,y1,y2,y3;
        double y4,y5,y6,y7;
        y0 = b[i+0];  y4 = b[i+4];
        y1 = b[i+1];  y5 = b[i+5];
        y2 = b[i+2];  y6 = b[i+6];
        y3 = b[i+3];  y7 = b[i+7];
        for (int j = 0; j < n_in; ++j) {
            y0 += W[(i+0)*n_in + j]*x[j];  y4 += W[(i+4)*n_in + j]*x[j];
            y1 += W[(i+1)*n_in + j]*x[j];  y5 += W[(i+5)*n_in + j]*x[j];
            y2 += W[(i+2)*n_in + j]*x[j];  y6 += W[(i+6)*n_in + j]*x[j];
            y3 += W[(i+3)*n_in + j]*x[j];  y7 += W[(i+7)*n_in + j]*x[j];
        }
        y[i+0] = y0; y[i+4] = y4;
        y[i+1] = y1; y[i+5] = y5;
        y[i+2] = y2; y[i+6] = y6;
        y[i+3] = y3; y[i+7] = y7;
    }

    /* Handle remaining */
    for (; i < num_n; ++i) {
        y[i] = b[i];
        for (int j = 0; j < n_in; ++j) {
            y[i] += W[i*n_in + j]*x[j];
        }
    }
}

static void WeightedSum_v2(double* W, double* b, double* x, double* y, int n_in, int num_n) {
    /* Handle remaining */
    for (int i = 0; i < num_n; i+=2) {
        double y00, y01, y02, y03;
        double y10, y11, y12, y13;
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

inline double hsum_double_avx(__m256d v) {
    __m128d vlow  = _mm256_castpd256_pd128(v);
    __m128d vhigh = _mm256_extractf128_pd(v, 1); // high 128
    vlow  = _mm_add_pd(vlow, vhigh);     // reduce down to 128

    __m128d high64 = _mm_unpackhi_pd(vlow, vlow);
    return  _mm_cvtsd_f64(_mm_add_sd(vlow, high64));  // reduce to scalar
}

static void WeightedSum(double* W, double* b, double* x, double* y, int n_in, int num_n) {
    /* Handle remaining */
    for (int i = 0; i < num_n; i+=2) {
        __m256d y0 = _mm256_setzero_pd();
        __m256d y1 = _mm256_setzero_pd();
        for (int j = 0; j < n_in; j+=4) {
            __m256d Wi0j0 = _mm256_load_pd(&W[(i+0)*n_in + j+0]);
            __m256d Wi1j0 = _mm256_load_pd(&W[(i+1)*n_in + j+0]);
            __m256d  x_j0 = _mm256_load_pd(&x[j+0]);
            y0 = _mm256_fmadd_pd(Wi0j0, x_j0, y0);
            y1 = _mm256_fmadd_pd(Wi1j0, x_j0, y1);
        }
        y[i+0] = b[i+0] + hsum_double_avx(y0);
        y[i+1] = b[i+1] + hsum_double_avx(y1);
    }
}


static void sigmoid_exp(double* y, int n) {
    for (int i = 0; i < n; ++i) {
        y[i] = y[i] / (1.0 + exp(-y[i]*5.0));
    }
}

static void sigmoid_relu(double* y, int n) {
    for (int i = 0; i < n; ++i) {
//        y[i] = fmax(0.0, y[i]);
        y[i] = y[i] > 0.0 ? y[i] : 0.0;
    }
}

static void processLayer(double* W, double* b, double* x, double* y, int n_in, int num_n) {
    WeightedSum(W, b, x, y, n_in, num_n);
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
void FFNN_Vec(double** W, double**b, double* x, double* y, int n_in, int n_out, int num_l,  int num_n) {
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
