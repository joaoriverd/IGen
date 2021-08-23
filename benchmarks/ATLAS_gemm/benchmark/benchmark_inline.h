#pragma once
#include <iostream>
#include <list>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "tsc.h"
#include "helpers.h"

using namespace std;
static double x1;
#define LAT_ADD 4.0
#define LAT_ERR 0.15

class stats_t {
public:
    double avrg;
    double min;
    double max;
    double media;
    double flops;

    stats_t() : avrg(0), min(0), max(0), media(0) {}
    ~stats_t() = default;

    void createStats(std::list<double> values, double fps) {
        flops = fps;
        /* Determine min and max */
        values.sort();
        max = values.front();
        min = values.back();

        /* Calculate average */
        double sum = 0.0;
        for (double& val : values) {
            sum += val;
        }
        avrg = sum / values.size();
    }

};

/// Check that the benchmark infrastructure works by testing
/// the latency of addition instructions.
static bool validate_runtime_environment() {
    const int iter = 10000;
    const int warmup_iter = 10000;

    /* First warm up the cpu */
    for (int i = 0; i < warmup_iter; ++i) {
        for (int j = 0; j < iter; j++) {
            x1 += x1;
        }
    }

    /* Start bench */
    double start = start_tsc();
    for (int j = 0; j < iter; j++) {
        x1 += x1;
    }
    double cycles = stop_tsc(start);
    double add_lat = cycles / iter;

    return (add_lat > LAT_ADD + LAT_ERR) || (add_lat < LAT_ADD - LAT_ERR);
}

static size_t getNumRuns(funPtr fun) {
    myInt64 start, end, overhead;
    double cycles;

    init_tsc();
    overhead = get_tsc_overhead();
    size_t num_runs = 2, multiplier = 1;

    //Cache warm-up
    // RDTSCP reads ts register guaranteeing that the execution of all the code
    // we wanted to measure is completed. This way we avoid including the
    // execution of a CPUID in between. The last CPUID guarantees no other
    // instruction can be scheduled before it (and so also before RDTSCP)

    do{
        num_runs = num_runs * multiplier;

        start = start_tsc();
        for(size_t i = 0; i < num_runs; i++) {
            func_call(fun);
        }
        end = stop_tsc(start);
        if (end > overhead)
            end -= overhead;

        cycles = (double) end;
        multiplier = ceil ( (CYCLES_REQUIRED) / (cycles)  + 1.0 );

    }while (multiplier > 2);

    return num_runs;
}

static stats_t getCycles(funPtr fun, size_t size) {
    myInt64 start, end, overhead;
    size_t num_runs;
    double cycles;
    list< double > cyclesList;

    /* Before starting validate that the timing is ok */
    bool error = validate_runtime_environment();
    if (error) {
        cerr << "The timings are not correct. Is Turbo Boost disabled?" << endl;
//        exit(0);
    }

    /* Init all variables */
    initGlobalVariables(size);
    overhead = get_tsc_overhead();
    num_runs = getNumRuns(fun);

    /* Benchmark function */
    for (int k = 0; k < NUMREP; k++) {
        start = start_tsc();
        for (int i = 0; i < num_runs; ++i) {
            func_call(fun);
        }
        end = stop_tsc(start);
        end -= overhead;

        cycles = ((double) end) / num_runs;
        cyclesList.push_back(cycles);
    }

    /* Get stats */
    stats_t perf_stats;
    perf_stats.createStats(cyclesList, getFlops());
    freeVariables();

    return perf_stats;
}

//static stats_t getPerf(funPtr fun, size_t size) {
//    stats_t cycles_stats = getCycles(fun, size);
//    cycles_stats.flops = getFlops();
//
////    perf_stats.avrg = flops / cycles_stats.avrg;
////    perf_stats.max = flops / cycles_stats.min;
////    perf_stats.min = flops / cycles_stats.max;
//
//    return perf_stats;
//}