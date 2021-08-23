#include <cfenv>

void benchmark_dgemm_scalar();
void dgemm_simple();
void dgemm_simple_f64i();
void benchmark_dgemm_f64i();
void dgemm_simple_ddi();
void benchmark_dgemm_ddi();

int main() {
    /* Start bench */
#if defined(F64I_TEST)
    fesetround(FE_UPWARD);
    benchmark_dgemm_f64i();
    fesetround(FE_TONEAREST);
#elif defined(DDI_TEST)
    fesetround(FE_UPWARD);
    benchmark_dgemm_ddi();
    fesetround(FE_TONEAREST);
#else
    benchmark_dgemm_scalar();
#endif
    return 0;
}
