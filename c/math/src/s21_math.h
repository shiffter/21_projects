#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

// #include <math.h>
#define s21_inf (__builtin_inff())
#define s21_minf -s21_inf
#define s21_nan (__builtin_nanf(""))
#define s21_isinf(x) __builtin_isinf_sign(x)
#define s21_isnan(x) __builtin_isnan(x)
#define s21_pi 3.14159265358979323846
#define s21_e 2.71828182845904523536
#define log_2 0.69314718055994
#define s21_pi2 1.57079632679489661923132169
#define s21_2pi 6.28318530717958647692528676655900
#define s21_eps 1e-6

// helpers
int count_digits(long long x);

// main
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_acos(double x);
unsigned long long int s21_fact(long int);
#endif  // SRC_S21_MATH_H_
