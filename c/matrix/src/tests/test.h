#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
/* #include "s21_matrix.a" */
#include "../s21_matrix.h"

Suite *s21_Suite_create_matrix();
Suite *s21_Suite_remove_matrix();
Suite *s21_Suite_eq_matrix();
Suite *s21_Suite_sum_matrix();
Suite *s21_Suite_sub_matrix();
Suite *s21_Suite_mult_number();
Suite *s21_Suite_mult_matrix();
Suite *s21_Suite_transpose();
Suite *s21_Suite_calc_complements();
Suite *s21_Suite_determinant();
Suite *s21_Suite_inverse_matrix();

static const double const_matr[3][3] = {
    {0.15, 0.0, -3.64},
    {8.53, -4.1321, 123.32},
    {0.0, 12.5, -78.321},
};

#endif // SRC_TESTS_TEST_H_
