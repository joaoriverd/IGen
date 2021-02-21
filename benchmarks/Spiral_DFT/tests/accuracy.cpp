#include <cfenv>
#include <iostream>
#include <vector>
#include <mpfr.h>
#include <cfloat>
#include <bits/stdc++.h>
#include "igen_lib.h"
#include "igen_dd_lib.h"
#include "util.h"
#include "random_range.h"
#include "boost_common.h"
#include "gaol_common.h"
#include "filib_common.h"
#include "write_csv.h"
#include "yalaa_wrap.h"

using namespace std;

const string accuracy_file_name = "../results/accuracy_dft64.csv";

#define MPFR_HIGH_PRECISION 250
#define NUM_RUNS_ACCURACY 100
#define MIN_EXPONENT_INPUTS (-4) // 2^{-5}
#define PERCENTAGE_NEGATIVE 50

#define SIZE                    (64*2)
#define DFT64                 DFT64
#define init_DFT64       init_DFT64
#define init_DFT64_bst   init_DFT64_bst
#define init_DFT64_fil   init_DFT64_fil
#define init_DFT64_gal   init_DFT64_gal
#define init_DFT64_yalaa init_DFT64_yalaa

void init_DFT64(f64_I);
void init_DFT64(dd_I);
void DFT64(f64_I  *, f64_I *);
void DFT64(dd_I   *, dd_I  *);

void init_DFT64_bst();
void init_DFT64_fil();
void init_DFT64_gal();
void init_DFT64_yalaa();
void DFT64(f64i_bst  *, f64i_bst  *);
void DFT64(f64i_fil *, f64i_fil  *);
void DFT64(f64i_gal *, f64i_gal  *);
void DFT64(yalaa_af0 *, yalaa_af0  *);

static long getCorrectBits(f64i_fil x) {
    f64_I a = _ia_set_f64(-x.inf(), x.sup());
    long cb =  getCorrectBits(a);
    if (cb > 52) {
        getCorrectBits(a);
    }
    return cb;
}

static long getCorrectBits(f64i_gal x) {
    f64_I a = _ia_set_f64(-x.left(), x.right());
    return getCorrectBits(a);
}

static long getCorrectBits(f64i_bst x) {
    f64_I a = _ia_set_f64(-x.lower(), x.upper());
    return getCorrectBits(a);
}

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

static long getCorrectBits(yalaa_af0 x_in) {
    auto filib_var =  yalaa::to_iv(x_in.v);
    f64_I a = _ia_set_f64(-filib_var.inf(), filib_var.sup());
    return getCorrectBits(a);
}

static __attribute__((aligned(32))) f64_I  X_f64i[SIZE];
static __attribute__((aligned(32))) f64_I  Y_f64i[SIZE];
static __attribute__((aligned(32))) dd_I   X_ddi [SIZE];
static __attribute__((aligned(32))) dd_I   Y_ddi [SIZE];

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
        double avrg = getAverageCorrectBits();

        cout << setw(9)  << left << avrg;
        cout << setw(5)  << left << box[0];
        cout << setw(5)  << left << box[1];
        cout << setw(5)  << left << box[2];
        cout << setw(5)  << left << box[3];
        cout << setw(5)  << left << box[4];
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

void set_epsilon(f64i_bst& f, double a) {
    f.set(a, a + DBL_MIN);
}

void set_epsilon(f64i_gal& f, double a) {
    f = f64i_gal(a, a + DBL_MIN);
}

void set_epsilon(f64i_fil& f, double a) {
    f = f64i_fil(a, nextafter(a, INFINITY));
}

void set_epsilon(yalaa_af0& f, double a) {
    f = yalaa_af0(a);
}

void set_epsilon(f64_I& f, double a) {
    f = _ia_set_epsilon_f64(a);
}

void set_epsilon(dd_I& f, double a) {
//    double h1 = a;
//    double h2 = a + DBL_EPSILON;
//    f = _ia_set_dd(-h1, 0.0, h2, 0.0); /* Decreasing precision of ddi */
    f = _ia_set_epsilon_dd(a,0.0);
}

void run_accuracy_test(size_t dyn_range, accuracy_stat& stat_f64i, accuracy_stat& stat_ddi) {
    for (int n = 0; n < NUM_RUNS_ACCURACY; n++) {
        /* Init arrays */
        for (int i = 0; i < SIZE; ++i) {
            double r = getRandomDouble(MIN_EXPONENT_INPUTS, dyn_range, PERCENTAGE_NEGATIVE);
            X_f64i[i] = _ia_set_epsilon_f64(r);
            X_ddi [i] = _ia_set_epsilon_dd(r,0);
        }

        /* Run Baseline */
        fesetround(FE_UPWARD);
        DFT64(Y_f64i, X_f64i);
        DFT64(Y_ddi, X_ddi);
        fesetround(FE_TONEAREST);

        for (int j = 0; j < SIZE; j++) {
            stat_f64i.add_interval(Y_f64i[j]);
            stat_ddi.add_interval(Y_ddi[j]);
        }
    }
}

template<typename T>
void run_accuracy_test(size_t dyn_range, accuracy_stat& stat) {
    static __attribute__((aligned(32))) T X[SIZE];
    static __attribute__((aligned(32))) T Y[SIZE];
    std::vector<accuracy_stat> stats_vec;

    /* To test with same inputs for all tests */
    restartRandomGenSeed();

    for (int n = 0; n < NUM_RUNS_ACCURACY; n++) {
        /* Init arrays */
        for (int i = 0; i < SIZE; ++i) {
            double r = getRandomDouble(MIN_EXPONENT_INPUTS, dyn_range, PERCENTAGE_NEGATIVE);
            set_epsilon(X[i], r);
        }

        /* Run Kernel */
        DFT64(Y, X);

        /* Update stats */
        for (int j = 0; j < SIZE; j++) {
            stat.add_interval(Y[j]);
        }
        //stat.resetMinDetection();
    }
}

void accuracy_DFT64() {
    initRandomSeed();

    /* Init DFT */
    //init_DFT64_yalaa();
    fesetround(FE_UPWARD);
    f64_I a_f64i;
    dd_I  a_ddi;
    init_DFT64(a_f64i);
    init_DFT64(a_ddi);
    init_DFT64_bst();
    init_DFT64_gal();
    fesetround(FE_DOWNWARD);
    init_DFT64_fil();

    accuracy_stat dyn4_f64i ,  dyn20_f64i;
    accuracy_stat dyn4_ddi  ,   dyn20_ddi;
    accuracy_stat dyn4_boost, dyn20_boost;
    accuracy_stat dyn4_gaol ,  dyn20_gaol;
    accuracy_stat dyn4_filib, dyn20_filib;

    /* Run test with dyn range of 4 and 20 bits */
    fesetround(FE_UPWARD);
    run_accuracy_test<f64_I>     ( 4 , dyn4_f64i );
    run_accuracy_test<dd_I>      ( 4 , dyn4_ddi  );
    run_accuracy_test<f64i_bst>  ( 4 , dyn4_boost);
    run_accuracy_test<f64i_gal>  ( 4 , dyn4_gaol );
    fesetround(FE_DOWNWARD);
    run_accuracy_test<f64i_fil>  ( 4 , dyn4_filib);

    fesetround(FE_UPWARD);
    run_accuracy_test<f64_I>     ( 20, dyn20_f64i );
    run_accuracy_test<dd_I>      ( 20, dyn20_ddi  );
    run_accuracy_test<f64i_bst>  ( 20, dyn20_boost);
    run_accuracy_test<f64i_gal>  ( 20, dyn20_gaol );
    fesetround(FE_DOWNWARD);
    run_accuracy_test<f64i_fil>  ( 20, dyn20_filib);
    fesetround(FE_TONEAREST);

    /* Try with affine arithmetic */
    //accuracy_stat yalaa_stat;
    //run_accuracy_test<yalaa_af0> ( 4, yalaa_stat);

    /* Print results */
    cout << "precision dyn range = 4:" << endl;
    dyn4_f64i .print_stats();
    dyn4_ddi  .print_stats();
    dyn4_boost.print_stats();
    dyn4_filib.print_stats();
    dyn4_gaol. print_stats();
    //yalaa_stat. print_stats();
    cout << endl;

    cout << "precision dyn range = 20:" << endl;
    dyn20_f64i .print_stats();
    dyn20_ddi  .print_stats();
    dyn20_boost.print_stats();
    dyn20_filib.print_stats();
    dyn20_gaol. print_stats();
    cout << endl;

    /* Create csv files with the results of accuracy */
    vector<vector<size_t>> accuracy_results;
    accuracy_results.push_back(dyn4_f64i.getBoxWithWhisker());
    accuracy_results.push_back(dyn4_ddi.getBoxWithWhisker() );
    store_results_csv(accuracy_results, accuracy_file_name);
}
