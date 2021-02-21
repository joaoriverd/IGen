#pragma once

#include <iostream>
#include "igen_lib.h"

#ifdef __cplusplus
 #define EXTERN
 std::ostream& operator<<(std::ostream& out, f64_I c);
#else
 #define EXTERN
 void printia(f64_I a);
#endif

EXTERN void initArrRandom(double* a, int size);
EXTERN double getRandNum(double min, double max);
EXTERN double getRandDenormal();
EXTERN f64_I getRandomInterval (double min, double max, double maxLength);
EXTERN f64_I getRandomDenormalInterval (bool positive);
EXTERN void icopy (f64_I* iX, double* X, int size, int err);
EXTERN void seedRand();
EXTERN double getLow(f64_I);
EXTERN double getUp(f64_I);
EXTERN double getCenter(f64_I);
EXTERN int isInside(f64_I, f64_I);
EXTERN int isInside(double, f64_I);
EXTERN int isNanInterval(f64_I);
EXTERN f64_I set_epsilon_interval(double a);
EXTERN long getCorrectBits(f64_I x);
