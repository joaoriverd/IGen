#include <iostream>
extern "C" {
#include "cblas.h"
}
#include "benchmark/benchmark_config3.h"
#include "write_csv.h"

using namespace std;

const string interval_perf_file_name = "../results/interval_perf_ddi_vv.csv";
const string real_perf_file_name     = "../results/real_perf_ddi_vv.csv";

void benchmark_dgemm_ddi() {
    vector<double> perf_interval;
    vector<double> real_perf;

    cout << endl << "dgemm_benchmark_ddi started:" << endl;
    stats_t runtime_stat;
    double perf1, perf2;

    for (int i = 56*1; i <= 56*11; i+=56*2) {
        runtime_stat = getCycles(cblas_dgemm, i);
        perf1        = runtime_stat.flops / runtime_stat.avrg;
        cout << i << " " << perf1 << endl;

        /* Calculate real performance */
        double cost_add = 40.0;
        double cost_mul = 114.0;
        double flops = runtime_stat.flops;
        perf2 = (0.5*flops*cost_add + 0.5*flops*cost_mul) / runtime_stat.avrg;

        /* Save results */
        perf_interval.push_back(perf1);
        real_perf.push_back(perf2);
    }

    /* Create csv files with the results */
    store_results_csv(perf_interval, interval_perf_file_name);
    store_results_csv(real_perf    , real_perf_file_name);
}

