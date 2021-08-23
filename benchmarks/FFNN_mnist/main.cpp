#include <string>
#include <iostream>

using namespace std;

unsigned int counter_add_sc;
unsigned int counter_mul_sc;
unsigned int counter_div_sc;
unsigned int counter_add_ve;
unsigned int counter_mul_ve;
unsigned int counter_div_ve;

#ifdef IGEN_LIB_VECTORIZED
string test_mode = "vectorized intervals (f64i = sse, ddi = avx)";
#else
string test_mode = "non-vectorized intervals (f64i = 2 x double, ddi = 4 x double)";
#endif

using namespace std;

void verify_ffnn();
void accuracy_ffnn();
void bench_ffnn();
void bench_f64i_ss();


int main(int argc, char * argv[]) {
    cout << "Testing: " << test_mode << endl << endl;

#ifdef IGEN_LIB_VECTORIZED
    /* Test soundness */
    verify_ffnn();

    /* Test accuracy */
    accuracy_ffnn();

    /* Test performance */
    bench_ffnn();
#else
    verify_ffnn();
    bench_f64i_ss();
#endif

    return 0;
}
