#include <iostream>
#include <sstream>
#include <ctime>
#include <list>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "igen_lib.h"
#include "igen_dd_lib.h"
#include "tsc_x86.h"
#include "parse_mnist_nn.h"
#include "write_csv.h"

using namespace std;

/* Test to perform */
const enum_mnist_nn test = MNIST_NN_9_200;
const int size_min =  40;
const int size_max = 200;
const int size_inc =  40;

const string interval_perf_file_name = "../results/interval_perf.csv";
const string real_perf_file_name     = "../results/real_perf_ffnn200.csv";
const string overhead_file_name      = "../results/overhead_ffnn200.csv";

const double cost_add_f64i  = 2;
const double cost_mul_f64i  = 14;
const double cost_add_ddi   = 40;
const double cost_mul_ddi   = 114;
const double n_adds_ffnn200 = 438800;
const double n_muls_ffnn200 = 438800;


void FFNN(double **W, double **b, double *x, double *y, int n_in, int n_out, int num_l, int num_n);
void FFNN(f64_I **W, f64_I **b, f64_I *x, f64_I *y, int n_in, int n_out, int num_l, int num_n);
void FFNN(dd_I  **W, dd_I **b , dd_I *x , dd_I *y , int n_in, int n_out, int num_l, int num_n);
void FFNN_Vec(double** W, double**b, double* x, double* y, int n_in, int n_out, int num_l,  int num_n);
void FFNN_Vec(f64_I **W, f64_I **b, f64_I *x, f64_I *y, int n_in, int n_out, int num_l, int num_n);
void FFNN_Vec(dd_I  **W, dd_I **b , dd_I *x , dd_I *y , int n_in, int n_out, int num_l, int num_n);

#define REP              30
#define CYCLES_REQUIRED 5e7
#define ALIGN            32
#define RUNS              2

enum eFunctions {
    DFT_base_vec,
    DFT_base_scl,
    DFT_f64i_vv,
    DFT_f64i_sv,
    DFT_ddi_vv,
    DFT_ddi_sv,
    DFT_f64i_boost,
    DFT_f64i_gaol,
    DFT_f64i_filib
};

template<typename T>
using funPtr =  void(*)(T**, T**, T*, T*, int, int, int, int);

template<typename T>
struct function_t {
    funPtr<T>        f;
    enum_mnist_nn type;
    string        name;

    function_t() = default;
    function_t(funPtr<T> f, enum_mnist_nn t, string n) : f(f), name(n), type(t) {}
    function_t(funPtr<T> f) : f(f) {}
};

template<typename T>
using functionsBench = vector<function_t<T>>;


template<typename T>
double getPerf(function_t<T> fun, int size = 200) {
    static __attribute__((aligned(32))) T X[MNIST_NN_INPUT_SIZE ];
    static __attribute__((aligned(32))) T Y[MNIST_NN_OUTPUT_SIZE];

    /* Load neural network */
    mnistFFNN<T> nn(fun.type);
    nn.num_n = size;

    // Cache warm-up
    // RDTSCP reads ts register guaranteeing that the execution of all the code
    // we wanted to measure is completed. This way we avoid including the
    // execution of a CPUID in between. The last CPUID guarantees no other
    // instruction can be scheduled before it (and so also before RDTSCP)

    unsigned long long start;
    unsigned long long end;
    unsigned long long overhead_tsc;
    double cycles;
    size_t num_runs = RUNS, multiplier = 1;

    init_tsc();
    overhead_tsc = get_tsc_overhead();

    do {
        num_runs = num_runs * multiplier;
        start = start_tsc();
        for (size_t i = 0; i < num_runs; i++) {
            fun.f(nn.W, nn.b, X, Y, nn.n_in, nn.n_out, nn.num_l, nn.num_n);
        }
        end = stop_tsc(start);
        if (end > overhead_tsc) { end -= overhead_tsc; }

        cycles = (double)end;
        multiplier = ceil((CYCLES_REQUIRED) / (cycles) + 1.0);
    } while (multiplier > 2);

    list<double> cycleList, flopList;

    // Actual performance measurements repeated REP times.
    for (int k = 0; k < REP; k++) {
        parseImageMnist(X, k); /* choose any file */
        start = start_tsc();
        for (int i = 0; i < num_runs; ++i) {
            fun.f(nn.W, nn.b, X, Y, nn.n_in, nn.n_out, nn.num_l, nn.num_n);
        }
        end  = stop_tsc(start);
        end -= overhead_tsc;

        cycles = ((double)end) / num_runs;

        cycleList.push_back(cycles);
    }

    cycleList.sort();
    flopList.sort();

    /* Calculate average */
    double avg_perf;
    double sum_cycles = 0.0;
    for (int k = 0; k < REP; k++) {
        sum_cycles += cycleList.front();
        cycleList.pop_front();
    }
    avg_perf = (sum_cycles / REP);
    return avg_perf;
}

template<typename T>
void measurePerformance(functionsBench<T>& funs, vector<vector<double>>& perf_results, vector<vector<double>>& cycl_results) {
    int num_l, num_n, n_in, n_out;
    mnistFFNN<T>::setParametersNN(num_l, num_n, n_in, n_out, test);

    for (auto& fun : funs){
        cout << endl;
        cout << setw(35) << left << fun.name;

        /* Get row of benchmark */
        vector<double> row_perf, row_cycl;
        for (int size = size_min; size <= size_max; size += size_inc) {
            double cycl  = getPerf(fun, size);
            double flops = 2 * size * (n_in + (num_l - 2)*size + n_out);
            double perf  = flops / cycl;
            row_cycl.push_back(cycl);
            row_perf.push_back(perf);
            cout << setw(15) << left << perf;
        }
        cycl_results.push_back(row_cycl);
        perf_results.push_back(row_perf);
    }
}

int bench_ffnn() {
    vector<vector<double>> perf_results;
    vector<vector<double>> cycl_results;
    vector<vector<double>> perf_interval;
    vector<double> overhead_ffnn200;
    vector<double> real_perf_ffnn200;

    functionsBench<double> base;
    functionsBench<f64_I>  f64i;
    functionsBench<dd_I>    ddi;

    /* Register baseline */
    base.push_back(function_t<double>(FFNN_Vec, test, "ffnn_base " + get_test_name(test) + " (avx)"));
    base.push_back(function_t<double>(FFNN    , test, "ffnn_base " + get_test_name(test)));

    /* Register igen double */
    f64i.push_back(function_t<f64_I>(FFNN_Vec, test, "ffnn_f64i " + get_test_name(test) + " (avx)"));
    f64i.push_back(function_t<f64_I>(FFNN    , test, "ffnn_f64i " + get_test_name(test)));

    /* Register igen dd */
    ddi .push_back (function_t<dd_I>(FFNN_Vec, test, "ffnn_ddi  " + get_test_name(test) + " (avx)"));
    ddi .push_back (function_t<dd_I>(FFNN    , test, "ffnn_ddi  " + get_test_name(test)));

    cout << "Starting FFNN runtime measurements (Baseline, IGen-(vv,sv,dd), Boost, Filib and Gaol): " << endl;

    /* Print the input size of DFTs */
    cout << setw(35) << left << "Benchmark";
    for (int i = size_min; i <= size_max; i+=size_inc) {
        cout << setw(15) << left << i;
    }

    /* Measure performance */
    fesetround(FE_TONEAREST);
    measurePerformance(base, perf_results, cycl_results);
    fesetround(FE_UPWARD);
    measurePerformance(f64i, perf_results, cycl_results);
    measurePerformance(ddi , perf_results, cycl_results);
    fesetround(FE_TONEAREST);
    cout << endl;

    /* Calculate overhead of IGen versions (f64i-sv, f64i-vv, ddi-sv and ddi-vv) compared to baseline */
    size_t ffnn200Colm = 4;
    overhead_ffnn200.push_back(perf_results[DFT_base_scl][ffnn200Colm] / perf_results[DFT_f64i_sv][ffnn200Colm]);
    overhead_ffnn200.push_back(perf_results[DFT_base_vec][ffnn200Colm] / perf_results[DFT_f64i_vv][ffnn200Colm]);
    overhead_ffnn200.push_back(perf_results[DFT_base_scl][ffnn200Colm] / perf_results[DFT_ddi_sv ][ffnn200Colm]);
    overhead_ffnn200.push_back(perf_results[DFT_base_vec][ffnn200Colm] / perf_results[DFT_ddi_vv ][ffnn200Colm]);

    /* Determine real performance of IGen versions (f64i-vv and ddi-vv) */
    double flops_ffnn200_f64i_vv = n_adds_ffnn200 * cost_add_f64i + n_muls_ffnn200 * cost_mul_f64i;
    double flops_ffnn200_ddi_vv  = n_adds_ffnn200 * cost_add_ddi  + n_muls_ffnn200 * cost_mul_ddi;
    real_perf_ffnn200.push_back(perf_results[DFT_base_vec][ffnn200Colm]);
    real_perf_ffnn200.push_back(flops_ffnn200_f64i_vv / cycl_results[DFT_f64i_vv][ffnn200Colm]);
    real_perf_ffnn200.push_back(flops_ffnn200_ddi_vv  / cycl_results[DFT_ddi_vv ][ffnn200Colm]);

    /* Get the performance of the interval versions only */
    for (int i = 0; i < perf_results.size(); i++) {
        if (i == DFT_base_vec || i == DFT_base_scl) { continue; }
        perf_interval.push_back(perf_results[i]);
    }

    /* Create csv files with the results */
    store_results_csv(perf_interval    , interval_perf_file_name);
    store_results_csv(overhead_ffnn200 , overhead_file_name);
    store_results_csv(real_perf_ffnn200, real_perf_file_name);

    return 0;
}

int bench_f64i_ss() {
    vector<vector<double>> perf_f64i_ss;
    vector<vector<double>> cycl_f64i_ss;

    /* Register igen-ss */
    functionsBench<f64_I>  f64i;
    f64i.push_back(function_t<f64_I>(FFNN, test, "ffnn_f64i " + get_test_name(test)));

    cout << "Starting FFNN runtime measurements (IGen-ss): " << endl;

    /* Print the input size of DFTs */
    cout << setw(35) << left << "Benchmark";
    for (int i = size_min; i <= size_max; i+=size_inc) {
        cout << setw(15) << left << i;
    }

    /* Measure performance */
    fesetround(FE_UPWARD);
    measurePerformance(f64i, perf_f64i_ss, cycl_f64i_ss);
    fesetround(FE_TONEAREST);
    cout << endl;

    /* Append dft_f64i_ss results to cvs file */
    store_results_csv(perf_f64i_ss, interval_perf_file_name, true);

    return 0;
}