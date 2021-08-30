#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "igen_lib.h"
#include "igen_dd_lib.h"

#define MNIST_NN_INPUT_SIZE  784   /* Size of the input image */
#define MNIST_NN_OUTPUT_SIZE  10   /* Size of the output (there are only 10 digits; from 0 to 9) */
#define NUM_INPUT_FILES      100
#define ALIGN                 32

using namespace std;

enum enum_mnist_nn {
    MNIST_NN_3_50 = 0,
    MNIST_NN_4_1024,
    MNIST_NN_6_20,
    MNIST_NN_6_50,
    MNIST_NN_6_100,
    MNIST_NN_6_200,
    MNIST_NN_9_100,
    MNIST_NN_9_200
};

static const vector<string> mnist_nets = {
        "../mnist/mnist_nets/mnist_relu_3_50.txt",
        "../mnist/mnist_nets/mnist_relu_4_1024.txt",
        "../mnist/mnist_nets/mnist_relu_6_20.txt",
        "../mnist/mnist_nets/mnist_relu_6_50.txt",
        "../mnist/mnist_nets/mnist_relu_6_100.txt",
        "../mnist/mnist_nets/mnist_relu_6_200.txt",
        "../mnist/mnist_nets/mnist_relu_9_100.txt",
        "../../../benchmarks/FFNN_mnist/mnist/mnist_nets/mnist_relu_9_200.txt"
 };

static const string mnist_images_path = "../../../benchmarks/FFNN_mnist/mnist/mnist_images/";

static string get_mnist_image (int id) {
    return mnist_images_path + "img" + to_string(id) + ".txt";
}

static string get_test_name(enum_mnist_nn type) {
    switch (type) {
        case MNIST_NN_3_50  : return  "MNIST_NN_3_50"  ;  break;
        case MNIST_NN_4_1024: return  "MNIST_NN_4_1024";  break;
        case MNIST_NN_6_20  : return  "MNIST_NN_6_20"  ;  break;
        case MNIST_NN_6_50  : return  "MNIST_NN_6_50"  ;  break;
        case MNIST_NN_6_100 : return  "MNIST_NN_6_100" ;  break;
        case MNIST_NN_6_200 : return  "MNIST_NN_6_200" ;  break;
        case MNIST_NN_9_100 : return  "MNIST_NN_9_100" ;  break;
        case MNIST_NN_9_200 : return  "MNIST_NN_9_200" ;  break;
    }
}

static void assign(dd_I & lhs, double rhs, double eps = 0.0) {
    if (rhs == 0.0) {
        lhs = _ia_set_pointed_dd(0.0, 0.0);
    }
    else {
        double ulp = (nextafter(rhs, INFINITY) - rhs) / exp2(53);
        lhs = _ia_set_dd(-rhs, -0.0, rhs, ulp);
    }
}

static void assign(f64_I & lhs, double rhs, double eps = 0.0) {
    if (rhs == 0.0) {
        lhs = _ia_set_pointed_f64(0.0);
    }
    else {
        lhs = _ia_set_epsilon_f64(rhs);
    }
}

static void assign(double& lhs, double rhs, double eps = 0.0) {
    lhs = rhs;
}

static double getNextDouble(ifstream& f) {
    double d;
    char c;

    while ((f.peek() < '0' || f.peek() > '9') && f.peek() != '-') {
        c = f.get();

        if (c ==  EOF) {
            cerr << "End of file reached" << endl;
            break;
        }
    }
    f >> d;

    if (f.fail()) {
        cerr << "An error occur when extracting double" << endl;
    }

    return d;
}

template<typename T>
class mnistFFNN {
public:
    T**     W;       /* W[i] is the matrix of weights of layer i */
    T**     b;       /* b[i] is the bias vector of layer i       */
    int num_l;       /* number of layers                         */
    int num_n;       /* number of neurones                       */
    int  n_in;       /* size of inputs                           */
    int n_out;       /* size of output                           */
    enum_mnist_nn t; /* Type of ffnn                             */

    static void setParametersNN(int& num_l, int& num_n, int& n_in, int& n_out, enum_mnist_nn type) {
        n_in  = MNIST_NN_INPUT_SIZE;
        n_out = MNIST_NN_OUTPUT_SIZE;

        switch (type) {
            case MNIST_NN_3_50  : num_l = 3; num_n =   50; break;
            case MNIST_NN_4_1024: num_l = 4; num_n = 1024; break;
            case MNIST_NN_6_20  : num_l = 6; num_n =   20; break;
            case MNIST_NN_6_50  : num_l = 6; num_n =   50; break;
            case MNIST_NN_6_100 : num_l = 6; num_n =  100; break;
            case MNIST_NN_6_200 : num_l = 6; num_n =  200; break;
            case MNIST_NN_9_100 : num_l = 9; num_n =  100; break;
            case MNIST_NN_9_200 : num_l = 9; num_n =  200; break;
        }
    }

    static void freeNN(T**& W, T**& b, int num_l) {
        for (int l = 0; l < num_l; ++l) {
            free(W[l]);
            free(b[l]);
        }
        free(W);
        free(b);
    }

    static void allocateNN (T**& W, T**& b, int num_l, int num_n, int n_in, int n_out) {
        /* Allocate space for W and b based */
        W = static_cast<T**>(malloc(num_l * sizeof(T*)));
        b = static_cast<T**>(malloc(num_l * sizeof(T*)));

        /* First layer */
        W[0] = static_cast<T*>(aligned_alloc(ALIGN, n_in * num_n * sizeof(T)));
        /* Hidden layers */
        for (int l = 1; l < num_l-1; ++l) {
            W[l] = static_cast<T*>(aligned_alloc(ALIGN, num_n * num_n * sizeof(T)));
        }
        /* Output layer */
        W[num_l-1] = static_cast<T*>(aligned_alloc(ALIGN, num_n * n_out * sizeof(T)));

        /* Bias */
        for (int l = 0; l < num_l; ++l) {
            b[l] = static_cast<T*>(aligned_alloc(ALIGN, num_n * sizeof(T)));
        }
    }

public:

    mnistFFNN() = default;
    mnistFFNN(enum_mnist_nn type) : t(type) {
        setParametersNN(num_l, num_n, n_in, n_out, type);
        allocateNN(W, b, num_l, num_n, n_in, n_out);

        /* Open file with NN model */
        ifstream f;
        f.open(mnist_nets[type]);
        if (!f.is_open()) {
            cerr << "Error opening NN file" << endl;
            exit(1);
        }


        /* Fill weight and bias vectors */
        for (int l = 0; l < num_l; ++l) {
            for (int n = 0; n < num_n; ++n) {

                /* Handle last layer */
                if (l == num_l-1 && n == MNIST_NN_OUTPUT_SIZE) { break; }

                int num_input = n_in;
                if (l > 0) {
                    /* The hidden layers have an input size equal to the neuron size */
                    num_input = num_n;
                }

                for (int m = 0; m < num_input; ++m) {
                    assign(W[l][n*num_input + m], getNextDouble(f));
                }
            }

            /* Get the bias of the current layer */
            for (int n = 0; n < num_n; ++n) {
                /* Handle last layer */
                if (l == num_l-1 && n == MNIST_NN_OUTPUT_SIZE) { break; }
                assign(b[l][n], getNextDouble(f));
            }
        }
    }

    ~mnistFFNN() {
        freeNN(W, b, num_l);
    }
};

template <typename T>
double parseImageMnist(T* x, int id) {
    double num_image;

    /* Open file with input values */
    ifstream f;
    f.open(get_mnist_image(id));
    if (!f.is_open()) {
        cerr << "Error opening input file" << endl;
        exit(1);
    }

    /* Get the number in the mnist image */
    num_image = getNextDouble(f);
    getNextDouble(f); /* Ignore next values */

    /* Fill input vector */
    for (int i = 0; i < MNIST_NN_INPUT_SIZE; ++i) {
        assign(x[i], getNextDouble(f));
        /* Ignore next double */
        getNextDouble(f);
    }

    return num_image;
}