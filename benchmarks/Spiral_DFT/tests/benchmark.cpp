#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cfloat>
#include <iomanip>
#include <cfenv>
#include "tsc_x86.h"
#include "include_tests.h"
#include "util.h"
#include "write_csv.h"
#include "yalaa_wrap.h"

using namespace std;

extern unsigned int counter_add_sc;
extern unsigned int counter_mul_sc;
extern unsigned int counter_add_ve;
extern unsigned int counter_mul_ve;
extern unsigned int counter_div_sc;
extern unsigned int counter_div_ve;

const string interval_perf_file_name = "../results/interval_perf.csv";
const string real_perf_file_name     = "../results/real_perf_dft64.csv";
const string overhead_file_name      = "../results/overhead_dft64.csv";

const double cost_add_f64i = 2;
const double cost_mul_f64i = 14;
const double cost_add_ddi  = 40;
const double cost_mul_ddi  = 114;
const double n_adds_dft64  = 944;
const double n_muls_dft64  = 288;

void reset_counters() {
#ifdef IGEN_COUNTERS
    counter_add_sc = 0.0;
    counter_mul_sc = 0.0;
    counter_add_ve = 0.0;
    counter_mul_ve = 0.0;
#endif
}

#define CYCLES_REQUIRED 5e7
#define REP 30
#define EPS (1e-3)

/* Initialize benchmark functions in this order */
enum eFunctions {
    DFT_base_vec,
    DFT_base_scl,
    DFT_f64i_vv,
    DFT_f64i_sv,
    DFT_ddi_vv,
    DFT_ddi_sv,
    DFT_f64i_boost,
    DFT_f64i_gaol,
    DFT_f64i_filib,
    DFT_f64i_yalaa
};

//#define N (64*2)

/* prototype of the function */
typedef void(*comp_func)(void*, void*);

double benchFun(comp_func f, int flops);
void   register_functions();
void   add_function(comp_func f, string name, int flop, eFunctions type, int);

struct fun_t {
    comp_func     f;
    eFunctions type;
    string     name;
    int       flops;
    int        size;
};

vector<fun_t> userFuncs;

int numFuncs = 0;

void build(void* &a, eFunctions type, int size) {
    /* Allocate the maximum size */
    if (type == DFT_base_scl || type == DFT_base_vec) {
        a = static_cast<void *>(aligned_alloc(32, (size*2)*sizeof(double)));
        auto* d = static_cast<double *>(a);
        for (int i = 0; i < (size*2); ++i) {
            double r = getRandNum(-10, 10);
            d[i] = r;
        }
    }
    if (type == DFT_f64i_sv || type == DFT_f64i_vv) {
        a = static_cast<void *>(aligned_alloc(32, (size*2)*sizeof(f64_I)));
        auto* d = static_cast<f64_I *>(a);
        for (int i = 0; i < (size*2); ++i) {
            double r = getRandNum(-10, 10);
            d[i] = _ia_set_f64(-r, r);
        }
    }
    if (type == DFT_ddi_sv || type == DFT_ddi_vv) {
        a = static_cast<void *>(aligned_alloc(32, (size*2)*sizeof(dd_I)));
        auto* d = static_cast<dd_I *>(a);
        for (int i = 0; i < (size*2); ++i) {
            double r = getRandNum(-10, 10);
            d[i] = _ia_set_dd(-r, 0, r, 0);
        }
    }
    if (type == DFT_f64i_boost) {
        a = static_cast<void *>(aligned_alloc(32, (size*2)*sizeof(f64i_bst)));
        auto* d = static_cast<f64i_bst *>(a);
        for (int i = 0; i < (size*2); ++i) {
            double r = getRandNum(-10, 10);
            d[i] = f64i_bst(r, r);
        }
    }
    if (type == DFT_f64i_filib) {
        a = static_cast<void *>(aligned_alloc(32, (size*2)*sizeof(f64i_fil)));
        auto* d = static_cast<f64i_fil *>(a);
        for (int i = 0; i < (size*2); ++i) {
            double r = getRandNum(-10, 10);
            d[i] = f64i_fil(-r, r);
        }
    }
    if (type == DFT_f64i_gaol) {
        a = static_cast<void *>(aligned_alloc(32, (size*2)*sizeof(f64i_gal)));
        auto* d = static_cast<f64i_gal *>(a);
        for (int i = 0; i < (size*2); ++i) {
            double r = getRandNum(-10, 10);
            d[i] = f64i_gal(-r, r);
        }
    }
    if (type == DFT_f64i_yalaa) {
//        a = static_cast<void *>(aligned_alloc(32, (size*2)*sizeof(yalaa_af0)));
        a = new yalaa_af0 [size*2];
        auto* d = static_cast<yalaa_af0 *>(a);
        for (int i = 0; i < (size*2); ++i) {
            double r = getRandNum(-10, 10);
            d[i] = r;
        }
    }
}

void destroy(void* m, eFunctions type) {
    if (type == DFT_f64i_yalaa) {
        delete[] (yalaa_af0*) m;
    }
    else {
        free(m);
    }
}

void register_functions() {

    add_function( AVX_DFT16_base , "AVX_DFT16_base" , 200 , DFT_base_vec, 16 );
    add_function( AVX_DFT32_base , "AVX_DFT32_base" , 496 , DFT_base_vec, 32 );
    add_function( AVX_DFT64_base , "AVX_DFT64_base" , 1232, DFT_base_vec, 64 );
    add_function( AVX_DFT128_base, "AVX_DFT128_base", 2912, DFT_base_vec, 128);
    add_function( AVX_DFT256_base, "AVX_DFT256_base", 7104, DFT_base_vec, 256);

    add_function( DFT16_base ,  "DFT16_base" , 176 , DFT_base_scl,16 );
    add_function( DFT32_base ,  "DFT32_base" , 544 , DFT_base_scl,32 );
    add_function( DFT64_base ,  "DFT64_base" , 1280, DFT_base_scl,64 );
    add_function( DFT128_base,  "DFT128_base", 3008, DFT_base_scl,128);
    add_function( DFT256_base,  "DFT256_base", 7168, DFT_base_scl,256);

    add_function( AVX_DFT16_f64i , "AVX_DFT16_f64i" , 200 , DFT_f64i_vv, 16 );
    add_function( AVX_DFT32_f64i , "AVX_DFT32_f64i" , 496 , DFT_f64i_vv, 32 );
    add_function( AVX_DFT64_f64i , "AVX_DFT64_f64i" , 1232, DFT_f64i_vv, 64 );
    add_function( AVX_DFT128_f64i, "AVX_DFT128_f64i", 2912, DFT_f64i_vv, 128);
    add_function( AVX_DFT256_f64i, "AVX_DFT256_f64i", 7104, DFT_f64i_vv, 256);

    add_function( DFT16_f64i ,  "DFT16_f64i" , 176 , DFT_f64i_sv,16 );
    add_function( DFT32_f64i ,  "DFT32_f64i" , 544 , DFT_f64i_sv,32 );
    add_function( DFT64_f64i ,  "DFT64_f64i" , 1280, DFT_f64i_sv,64 );
    add_function( DFT128_f64i,  "DFT128_f64i", 3008, DFT_f64i_sv,128);
    add_function( DFT256_f64i,  "DFT256_f64i", 7168, DFT_f64i_sv,256);

    add_function( AVX_DFT16_ddi , "AVX_DFT16_ddi ",  200 , DFT_ddi_vv , 16 );
    add_function( AVX_DFT32_ddi , "AVX_DFT32_ddi ",  496 , DFT_ddi_vv , 32 );
    add_function( AVX_DFT64_ddi , "AVX_DFT64_ddi ",  1232, DFT_ddi_vv , 64 );
    add_function( AVX_DFT128_ddi, "AVX_DFT128_ddi",  2912, DFT_ddi_vv , 128);
    add_function( AVX_DFT256_ddi, "AVX_DFT256_ddi",  7104, DFT_ddi_vv , 256);

    add_function( DFT16_ddi ,  "DFT16_ddi" ,  176 , DFT_ddi_vv ,16 );
    add_function( DFT32_ddi ,  "DFT32_ddi" ,  544 , DFT_ddi_vv ,32 );
    add_function( DFT64_ddi ,  "DFT64_ddi" ,  1280, DFT_ddi_vv ,64 );
    add_function( DFT128_ddi,  "DFT128_ddi",  3008, DFT_ddi_vv ,128);
    add_function( DFT256_ddi,  "DFT256_ddi",  7168, DFT_ddi_vv ,256);

    add_function( DFT16_boost ,  "DFT16_boost" ,  176 , DFT_f64i_boost, 16 );
    add_function( DFT32_boost ,  "DFT32_boost" ,  544 , DFT_f64i_boost, 32 );
    add_function( DFT64_boost ,  "DFT64_boost" ,  1280, DFT_f64i_boost, 64 );
    add_function( DFT128_boost,  "DFT128_boost",  3008, DFT_f64i_boost, 128);
    add_function( DFT256_boost,  "DFT256_boost",  7168, DFT_f64i_boost, 256);

    add_function( DFT16_gaol ,  "DFT16_gaol ",  176 , DFT_f64i_gaol , 16 );
    add_function( DFT32_gaol ,  "DFT32_gaol ",  544 , DFT_f64i_gaol , 32 );
    add_function( DFT64_gaol ,  "DFT64_gaol ",  1280, DFT_f64i_gaol , 64 );
    add_function( DFT128_gaol,  "DFT128_gaol",  3008, DFT_f64i_gaol , 128);
    add_function( DFT256_gaol,  "DFT256_gaol",  7168, DFT_f64i_gaol , 256);

    add_function( DFT16_filib ,  "DFT16_filib" ,  176 , DFT_f64i_filib, 16 );
    add_function( DFT32_filib ,  "DFT32_filib" ,  544 , DFT_f64i_filib, 32 );
    add_function( DFT64_filib ,  "DFT64_filib" ,  1280, DFT_f64i_filib, 64 );
    add_function( DFT128_filib,  "DFT128_filib",  3008, DFT_f64i_filib, 128);
    add_function( DFT256_filib,  "DFT256_filib",  7168, DFT_f64i_filib, 256);

    //add_function( DFT16_yalaa ,  "DFT16_yalaa" ,  176 , DFT_f64i_yalaa, 16 );
    //add_function( DFT32_yalaa ,  "DFT32_yalaa" ,  544 , DFT_f64i_yalaa, 32 );
    //add_function( DFT64_yalaa ,  "DFT64_yalaa" ,  1280, DFT_f64i_yalaa, 64 );
    //add_function( DFT128_yalaa,  "DFT128_yalaa",  3008, DFT_f64i_yalaa, 128);
    //add_function( DFT256_yalaa,  "DFT256_yalaa",  7168, DFT_f64i_yalaa, 256);
}

void add_function(comp_func f, string name, int flops, eFunctions type, int size) {
    fun_t fun;
    fun.f = f;
    fun.name = name;
    fun.flops = flops;
    fun.type = type;
    fun.size = size;
    userFuncs.push_back(fun);
    numFuncs++;
}

double benchFun(const fun_t fun) {
    double cycles     =  0;
    long   num_runs   = 30;
    double multiplier =  1;
    myInt64 start, end;

    void *X, *Y;
    build(X, fun.type, fun.size);
    build(Y, fun.type, fun.size);

    switch (fun.type) {
        case DFT_base_scl:
        case DFT_base_vec: fesetround(FE_TONEAREST); break;
        case DFT_f64i_vv :
        case DFT_f64i_sv :
        case DFT_ddi_vv  :
        case DFT_ddi_sv  : fesetround(FE_UPWARD); break;
        default: break;
    }

    /* Warm-up phase */
    do {
        num_runs = num_runs * multiplier;
        start = start_tsc();
        for (int i = 0; i < num_runs; i++) {
            fun.f(Y, X);
        }
        end = stop_tsc(start);
        cycles = (double)end;
        multiplier = (CYCLES_REQUIRED) / (cycles);
    } while (multiplier > 2);

    list<double> cyclesList;

    // Actual performance measurements repeated REP times.
    for (size_t j = 0; j < REP; j++) {
        start = start_tsc();
        for (int i = 0; i < num_runs; ++i) {
            fun.f(Y, X);
        }
        end = stop_tsc(start);

        cycles = ((double)end) / num_runs;
        cyclesList.push_back(cycles);
    }

    destroy(Y, fun.type);
    destroy(X, fun.type);
    cyclesList.sort();
    cycles = cyclesList.front();
    return  cycles;
}

void init_benchmarks() {
    double a;
    init_DFT16(a);
    init_DFT32(a);
    init_DFT64(a);
    init_DFT128(a);
    init_DFT256(a);

    f64_I a_f64i;
    init_DFT16(a_f64i);
    init_DFT32(a_f64i);
    init_DFT64(a_f64i);
    init_DFT128(a_f64i);
    init_DFT256(a_f64i);

    dd_I a_ddi;
    init_DFT16(a_ddi);
    init_DFT32(a_ddi);
    init_DFT64(a_ddi);
    init_DFT128(a_ddi);
    init_DFT256(a_ddi);

    init_DFT16_bst();
    init_DFT32_bst();
    init_DFT64_bst();
    init_DFT128_bst();
    init_DFT256_bst();

    init_DFT16_fil();
    init_DFT32_fil();
    init_DFT64_fil();
    init_DFT128_fil();
    init_DFT256_fil();

    init_DFT16_gal();
    init_DFT32_gal();
    init_DFT64_gal();
    init_DFT128_gal();
    init_DFT256_gal();

    init_AVX_DFT16(a);
    init_AVX_DFT32(a);
    init_AVX_DFT64(a);
    init_AVX_DFT128(a);
    init_AVX_DFT256(a);

    init_AVX_DFT16(a_f64i);
    init_AVX_DFT32(a_f64i);
    init_AVX_DFT64(a_f64i);
    init_AVX_DFT128(a_f64i);
    init_AVX_DFT256(a_f64i);

    init_AVX_DFT16(a_ddi);
    init_AVX_DFT32(a_ddi);
    init_AVX_DFT64(a_ddi);
    init_AVX_DFT128(a_ddi);
    init_AVX_DFT256(a_ddi);

    /* Affine arithmetic */
    //init_DFT16_yalaa();
    //init_DFT32_yalaa();
    //init_DFT64_yalaa();
    //init_DFT128_yalaa();
    //init_DFT256_yalaa();
}

void count_flops() {
    f64_I X[512];
    f64_I Y[512];

    init_benchmarks();
    reset_counters();

    cout << "Flops (adds, mults):" << endl;
    DFT16_f64i (Y, X); cout << counter_add_sc << ", " << counter_mul_sc << " (DFT16)"  << endl; reset_counters();
    DFT32_f64i (Y, X); cout << counter_add_sc << ", " << counter_mul_sc << " (DFT32)"  << endl; reset_counters();
    DFT64_f64i (Y, X); cout << counter_add_sc << ", " << counter_mul_sc << " (DFT64)"  << endl; reset_counters();
    DFT128_f64i(Y, X); cout << counter_add_sc << ", " << counter_mul_sc << " (DFT128)" << endl; reset_counters();
    DFT256_f64i(Y, X); cout << counter_add_sc << ", " << counter_mul_sc << " (DFT256)" << endl; reset_counters();

    AVX_DFT16_f64i (Y, X); cout << 4*counter_add_ve << ", " << 4*counter_mul_ve << " (AVX_DFT16)"  << endl; reset_counters();
    AVX_DFT32_f64i (Y, X); cout << 4*counter_add_ve << ", " << 4*counter_mul_ve << " (AVX_DFT32)"  << endl; reset_counters();
    AVX_DFT64_f64i (Y, X); cout << 4*counter_add_ve << ", " << 4*counter_mul_ve << " (AVX_DFT64)"  << endl; reset_counters();
    AVX_DFT128_f64i(Y, X); cout << 4*counter_add_ve << ", " << 4*counter_mul_ve << " (AVX_DFT128)" << endl; reset_counters();
    AVX_DFT256_f64i(Y, X); cout << 4*counter_add_ve << ", " << 4*counter_mul_ve << " (AVX_DFT256)" << endl; reset_counters();

}

int benchmark() {
    vector<vector<double>> perf_results;
    vector<vector<double>> cycl_results;
    vector<vector<double>> perf_interval;
    vector<vector<double>> perf_baseline;
    vector<double> overhead_dft64;
    vector<double> real_perf_dft64;

    /* Init DFT */
    fesetround(FE_UPWARD);
    init_benchmarks();
    register_functions();

    cout << "Starting DFT runtime measurements (Baseline, IGen-(vv,sv,dd), Boost, Filib and Gaol): ";
    if (numFuncs == 0) {
        cout << endl;
        cout << "No functions registered - nothing to do" << endl;
        return 0;
    }
    else {
        cout << numFuncs << " functions registered." << endl << endl;
    }

    /* Print the input size of DFTs */
    cout << setw(15) << left << "Benchmark";
    for (int i = 16; i <= 256; i*=2) {
        cout << setw(15) << left << i;
    }

    /* Run benchmarks and print results on the go */
    size_t numColmns = 5;
    for (int i = 0; i < numFuncs / numColmns; i++) {
        cout << endl;
        cout << setw(15) << left << userFuncs[i*numColmns].name;

        /* Get row of benchmark */
        vector<double> row_perf, row_cycl;
        for (int j = 0; j < numColmns; j++) {
            double cycl = benchFun(userFuncs[i*numColmns + j]);
            double perf = userFuncs[i*numColmns + j].flops / cycl;
            row_cycl.push_back(cycl);
            row_perf.push_back(perf);
            cout << setw(15) << left << perf;
        }
        cycl_results.push_back(row_cycl);
        perf_results.push_back(row_perf);
    }
    cout << endl;

    /* Calculate overhead of IGen versions (f64i-sv, f64i-vv, ddi-sv and ddi-vv) compared to baseline */
    size_t dft64Colm = 2;
    overhead_dft64.push_back(perf_results[DFT_base_scl][dft64Colm] / perf_results[DFT_f64i_sv][dft64Colm]);
    overhead_dft64.push_back(perf_results[DFT_base_vec][dft64Colm] / perf_results[DFT_f64i_vv][dft64Colm]);
    overhead_dft64.push_back(perf_results[DFT_base_scl][dft64Colm] / perf_results[DFT_ddi_sv ][dft64Colm]);
    overhead_dft64.push_back(perf_results[DFT_base_vec][dft64Colm] / perf_results[DFT_ddi_vv ][dft64Colm]);

    /* Determine real performance of IGen versions (f64i-vv and ddi-vv) */
    double flops_dft64_f64i_vv = n_adds_dft64 * cost_add_f64i + n_muls_dft64 * cost_mul_f64i;
    double flops_dft64_ddi_vv  = n_adds_dft64 * cost_add_ddi  + n_muls_dft64 * cost_mul_ddi;
    real_perf_dft64.push_back(perf_results[DFT_base_vec][dft64Colm]);
    real_perf_dft64.push_back(flops_dft64_f64i_vv / cycl_results[DFT_f64i_vv][dft64Colm]);
    real_perf_dft64.push_back(flops_dft64_ddi_vv  / cycl_results[DFT_ddi_vv ][dft64Colm]);

    /* Get the performance of the interval versions only */
    for (int i = 0; i < perf_results.size(); i++) {
        if (i == DFT_base_vec || i == DFT_base_scl) { continue; }
        perf_interval.push_back(perf_results[i]);
    }

    /* Create csv files with the results */
    store_results_csv(perf_interval  , interval_perf_file_name);
    store_results_csv(overhead_dft64 , overhead_file_name);
    store_results_csv(real_perf_dft64, real_perf_file_name);

    return 0;
}

int benchmark_f64i_ss() {
    vector<double> perf_f64i_ss;

    /* Add only f64i benchmarks */
    fesetround(FE_UPWARD);
    init_benchmarks();
    add_function( DFT16_f64i ,  "DFT16_f64i" , 176 , DFT_f64i_sv,16 );
    add_function( DFT32_f64i ,  "DFT32_f64i" , 544 , DFT_f64i_sv,32 );
    add_function( DFT64_f64i ,  "DFT64_f64i" , 1280, DFT_f64i_sv,64 );
    add_function( DFT128_f64i,  "DFT128_f64i", 3008, DFT_f64i_sv,128);
    add_function( DFT256_f64i,  "DFT256_f64i", 7168, DFT_f64i_sv,256);

    cout << "Starting DFT runtime measurements program: ";
    if (numFuncs == 0) {
        cout << endl;
        cout << "No functions registered - nothing to do" << endl;
        return 0;
    }
    else {
        cout << numFuncs << " functions registered." << endl << endl;
    }


    /* Print the input size of DFTs */
    cout << setw(15) << left << "Benchmark";
    for (int i = 16; i <= 256; i*=2) {
        cout << setw(15) << left << i;
    }

    /* Run benchmarks and print results on the go */
    size_t numColmns = 5;
    for (int i = 0; i < numFuncs / numColmns; i++) {
        cout << endl;
        cout << setw(15) << left << userFuncs[i*numColmns].name;

        /* Get row of benchmark */
        vector<double> row_perf, row_cycl;
        for (int j = 0; j < numColmns; j++) {
            double cycl = benchFun(userFuncs[i*numColmns + j]);
            double perf = userFuncs[i*numColmns + j].flops / cycl;
            row_cycl.push_back(cycl);
            perf_f64i_ss.push_back(perf);
            cout << setw(15) << left << perf;
        }
    }
    cout << endl;

    /* Append dft_f64i_ss results to cvs file */
    store_results_csv(perf_f64i_ss, interval_perf_file_name, true);
}