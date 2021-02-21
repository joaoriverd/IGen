//double read_sensor ( double:0.125 a ) {
//double c = 5.0 + 0.25t;
//return a + c ;
//}

void mvm_redu (double* A, double* x, double* y, int n) {
#pragma igen reduce y
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            y[i] = y[i] + A[i*n + j] * x[j];
        }
    }
}
