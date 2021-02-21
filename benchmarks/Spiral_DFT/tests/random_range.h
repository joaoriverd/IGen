#pragma once
#include <cstddef>

///
/// \param neg : Percentage of negative numbers (0-100)
/// \param min_exp : Minimum exponent to generate random number
/// \param dyn_range : Dynamic range in bits
/// \return random number r = [2^(min_exp), 2^(min_exp + dyn_range)]
///
double getRandomDouble(int min_exp, int dyn_range, size_t neg = 0);
void initRandomSeed();
void restartRandomGenSeed();