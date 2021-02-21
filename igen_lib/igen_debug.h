#pragma once

#include "igen_types.h"

#ifdef __cplusplus
extern "C" {
#endif

long _debug_get_lost_bits(f64_I x);
int _debug_is_around_zero(f64_I a);
void _debug_around_zero_f64(f64_I a);
int _debug_lost_precision_f64(f64_I a);
int _debug_get_max_lost_bits_array(f64_I* x, int n);
double _debug_get_avg_lost_bits_array(f64_I* x, int n);
void igen_print_error(const char* msg);

#ifdef __cplusplus
}
#endif