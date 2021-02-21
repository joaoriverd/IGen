#pragma once

#include <interval/interval.hpp>

// no_rounding is not safe (even is bounds are kept negated)
//typedef filib::interval<double,filib::no_rounding,filib::i_mode_normal> f64i_fil;
typedef filib::interval<double,filib::native_onesided_global,filib::i_mode_normal> f64i_fil;
