#ifndef SRC_S21_TESTCASES_H_
#define SRC_S21_TESTCASES_H_

#include <float.h>
#include <limits.h>
#include <math.h>

#define NMAX 13

int int_testcases[NMAX] = {INT_MIN, INT_MAX, 1, -2, 3, 4, 5, -15, 20, 14, 7, 3};

double lf_testcases[NMAX] = {
    0.001, -0.02, 0.3, -0.45, 0.51,     -1.2,      3.4,
    5.6,   -8.7,  9.0, NAN,   INFINITY, -INFINITY,
};

double fmod_testcases[NMAX] = {NAN,  INFINITY, -INFINITY, 3.5,  1.6,   2, -2.8,
                               -101, 57,       0.67,      -8.7, -0.45, 0};

#endif  // SRC_S21_TESTCASES_H_
