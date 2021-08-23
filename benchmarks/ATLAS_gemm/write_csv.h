#pragma once

#include <vector>
#include <string>

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
void store_results_csv(const vector<vector<T>>& perf_results, const string& file_name, bool append = false) {
    ofstream perfFile;
    if (append) {
        perfFile.open (file_name, ios_base::app);
    }
    else {
        perfFile.open (file_name);
    }

    for (const vector<T>& row : perf_results) {
        for (const T& val : row) {
            perfFile << val;
            if (&val != &row.back()) {
                perfFile << ",";
            }
        }
        perfFile << "\n";
    }
    perfFile.close();
}


template<typename T>
void store_results_csv(const vector<T>& perf_results, const string& file_name, bool append = false) {
    ofstream perfFile;
    if (append) {
        perfFile.open (file_name, ios_base::app);
    }
    else {
        perfFile.open (file_name);
    }

    for (const T& val : perf_results) {
        perfFile << val;
        if (&val != &perf_results.back()) {
            perfFile << ",";
        }
    }
    perfFile << "\n";
    perfFile.close();
}
