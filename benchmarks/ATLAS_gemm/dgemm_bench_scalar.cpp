#include <iostream>
extern "C" {
#include "cblas.h"
}
#include "benchmark/benchmark_config1.h"
#include "write_csv.h"

using namespace std;

const string real_perf_file_name     = "../results/real_perf_baseline_vec.csv";

void benchmark_dgemm_scalar() {
    vector<double> perf_results;

    cout << endl << "dgemm_benchmark_scalar started:" << endl;
    stats_t runtime_stat;
    double perf;

    for (int i = 56*1; i <= 56*11; i+=56*2) {
        runtime_stat = getCycles(cblas_dgemm, i);
        perf         = runtime_stat.flops / runtime_stat.avrg;
        perf_results.push_back(perf);
        cout << i << " " << perf <<  " " << runtime_stat.avrg << endl;
    }

    /* Create csv files with the results */
    store_results_csv(perf_results, real_perf_file_name);
}

