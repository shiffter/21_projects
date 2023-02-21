#include "test.h"

START_TEST(s21_mult_number_test) {
  matrix_t matrix_1 = INIT_M, res = INIT_M;
  s21_create_matrix(3, 3, &matrix_1);
  double number = 3.69;
  static const double result[3][3] = {
      {0.5535, 0, -13.4316},
      {31.4757, -15.247449, 455.0508},
      {0, 46.125, -289.00449},
  };

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = const_matr[i][j];
    }
  }

  ck_assert_int_eq(0, s21_mult_number(&matrix_1, number, &res));
  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      ck_assert_double_eq_tol(res.matrix[i][j], result[i][j], 1e-6);
    }
  }
  s21_remove_matrix(&res);
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_mult_number_test_fail) {
  matrix_t matrix_1, res;
  s21_create_matrix(3, 0, &matrix_1);

  double num = 1.32;
  ck_assert_int_eq(1, s21_mult_number(&matrix_1, num, &res));
  s21_remove_matrix(&matrix_1);
}
END_TEST

Suite *s21_Suite_mult_number() {
  Suite *s;

  s = suite_create("Mult number matrix unit test");

  TCase *tc1_s21_mult_number_test = tcase_create("mult number on matrix");
  TCase *tc2_s21_mult_number_test_fail = tcase_create("fail unit test");

  tcase_add_test(tc1_s21_mult_number_test, s21_mult_number_test);
  tcase_add_test(tc2_s21_mult_number_test_fail, s21_mult_number_test_fail);

  suite_add_tcase(s, tc1_s21_mult_number_test);
  suite_add_tcase(s, tc2_s21_mult_number_test_fail);

  return s;
}
