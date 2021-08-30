#include <cfenv>
#include <iostream>
#include <iomanip>
#include <mpfr.h>
#include <cfloat>
#include "igen_lib.h"
#include "igen_dd_lib.h"
#include "util.h"
#include "parse_mnist_nn.h"
#include "write_csv.h"

using namespace std;

const string accuracy_file_name = "../results/accuracy_ffnn200.csv";

#define MPFR_HIGH_PRECISION 250

void FFNN(f64_I **W, f64_I **b, f64_I *x, f64_I *y, int n_in, int n_out, int num_l, int num_n);
void FFNN(dd_I  **W, dd_I **b , dd_I *x , dd_I *y , int n_in, int n_out, int num_l, int num_n);

static long getCorrectBits(dd_I x_in) {
    mpfr_t xl, xu, delta;
    mpfr_init2(xl,    MPFR_HIGH_PRECISION);
    mpfr_init2(xu,    MPFR_HIGH_PRECISION);
    mpfr_init2(delta, MPFR_HIGH_PRECISION);

    u_ddi x = { .v = x_in };
    mpfr_set_d(xl, -x.lh, MPFR_RNDD);
    mpfr_set_d(xu,  x.uh, MPFR_RNDU);
    mpfr_add_d(xl, xl, -x.ll, MPFR_RNDD);
    mpfr_add_d(xu, xu,  x.ul, MPFR_RNDU);
    mpfr_sub(delta, xu, xl, MPFR_RNDU);

    long correctBits;
    if (mpfr_zero_p(delta)) {
        correctBits = 106;
    }
    else {
        correctBits = mpfr_get_exp(xl) - mpfr_get_exp(delta);
    }

    if (correctBits > 106) {
        correctBits = 106;
    }

    return correctBits;
}

class accuracy_stat {
    size_t distribution[107];

    double sum_correct  = 0.0;
    double num_elements = 0.0;
    double max_correct  = 0.0;
    double min_correct  = INFINITY;

    double sum_min_correct  = 0.0;
    double num_min_elements = 0.0;

public:
    accuracy_stat() : distribution() { /* Init array with zeros */ }

    template<typename T>
    void add_interval(T a) {
        size_t correct_bits = getCorrectBits(a);

        distribution[correct_bits]++;
        sum_correct += correct_bits;
        num_elements++;

        if (correct_bits > max_correct) {
            max_correct = correct_bits;
        }

        if (correct_bits < min_correct) {
            min_correct = correct_bits;
        }
    }

    double getAverageCorrectBits() const {
        return sum_correct / num_elements;
    }

    double getMaxCorrect() const {
        return max_correct;
    }

    double getMinCorrectAvrg() const {
        return sum_min_correct / num_min_elements;
    }

    double getMinCorrect() const {
        return min_correct;
    }

    void resetMinDetection() {
        sum_min_correct += min_correct;
        num_min_elements++;
        min_correct  = INFINITY;
    }

    void print_stats() {
        /* Print in a box plot format */
        vector<std::size_t> box = getBoxWithWhisker();

        cout << setw(5) << left << box[0];
        cout << setw(5) << left << box[1];
        cout << setw(5) << left << box[2];
        cout << setw(5) << left << box[3];
        cout << setw(5) << left << box[4];
        cout << endl;
    }

    vector<size_t> getBoxWithWhisker() {
        vector<size_t> box_whisker;

        size_t min, q1 = 0, q2 = 0, q3 = 0, max;
        min = min_correct;
        max = max_correct;

        /* Determine quartiles */
        size_t sum = 0;
        size_t quartile = num_elements/4;
        for (int i = 0; i < 107; i++) {
            sum += distribution[i];

            if (q1 == 0 && sum >  quartile) {
                q1 = i;
            }

            if (q2 == 0 && sum > 2*quartile) {
                q2 = i;
            }

            if (q3 == 0 && sum > 3*quartile) {
                q3 = i;
            }
        }

        box_whisker.push_back(min);
        box_whisker.push_back(q1 );
        box_whisker.push_back(q2 );
        box_whisker.push_back(q3 );
        box_whisker.push_back(max);
        return box_whisker;
    }
};

void set_epsilon(f64_I& f, double a) {
    f = _ia_set_epsilon_f64(a);
}

void set_epsilon(dd_I& f, double a) {
    f = _ia_set_epsilon_dd(a,0.0);
}

template<typename T>
void run_accuracy_test(enum_mnist_nn type, accuracy_stat& stat) {
    static __attribute__((aligned(32))) T X[MNIST_NN_INPUT_SIZE ];
    static __attribute__((aligned(32))) T Y[MNIST_NN_OUTPUT_SIZE];

    /* Load neural network */
    mnistFFNN<T> nn(type);

    for (int n = 0; n < NUM_INPUT_FILES; n++) {
        /* Parse input file */
        parseImageMnist(X, n);

        /* Run Kernel */
        FFNN(nn.W, nn.b, X, Y, nn.n_in, nn.n_out, nn.num_l, nn.num_n);

        /* Update stats */
        for (int j = 0; j < MNIST_NN_OUTPUT_SIZE; j++) {
            stat.add_interval(Y[j]);
        }
    }
}

void accuracy_ffnn() {
    cout << "Running accuracy test." << endl;

    enum_mnist_nn test = MNIST_NN_9_200;

    accuracy_stat stat_f64;
    accuracy_stat stat_ddi;
    accuracy_stat stat_bst;
    accuracy_stat stat_fil;
    accuracy_stat stat_gal;

    /* Run test with dyn range of 4 and 20 bits */
    fesetround(FE_UPWARD);
    run_accuracy_test<f64_I>( test, stat_f64);
    run_accuracy_test<dd_I >( test, stat_ddi);
    fesetround(FE_TONEAREST);

    /* Print results */
    cout << "precision of " << get_test_name(test) << ":" << endl;
    stat_f64.print_stats();
    stat_ddi.print_stats();
    stat_bst.print_stats();
    stat_fil.print_stats();
    stat_gal.print_stats();


    /* Create csv files with the results of accuracy */
    vector<vector<size_t>> accuracy_results;
    accuracy_results.push_back(stat_f64.getBoxWithWhisker());
    accuracy_results.push_back(stat_ddi.getBoxWithWhisker() );
    store_results_csv(accuracy_results, accuracy_file_name);
}