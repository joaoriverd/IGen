unsigned int counter_add_sc = 0.0;
unsigned int counter_mul_sc = 0.0;
unsigned int counter_div_sc = 0.0;
unsigned int counter_add_ve = 0.0;
unsigned int counter_mul_ve = 0.0;
unsigned int counter_div_ve = 0.0;

void verify_DFT64();
void accuracy_DFT64();
void benchmark();
void benchmark_f64i_ss();
void count_flops();

int main() {
#ifdef IGEN_LIB_VECTORIZED
    /* Verify soundness */
    verify_DFT64();

    /* Measure accuracy */
    accuracy_DFT64();

    /* Measure Runtime */
    benchmark();
#else
    verify_DFT64();
    benchmark_f64i_ss();
#endif

    return 0;
}
