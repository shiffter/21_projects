#include "test.h"

START_TEST(s21_mult_matrix_test) {
  matrix_t matrix_1 = INIT_M, matrix_2 = INIT_M, res = INIT_M;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &res);
  s21_create_matrix(3, 3, &matrix_2);
  static const double const_matr2[3][3] = {
      {0.5535, 0, -13.4316},
      {31.4757, -15.247449, 455.0508},
      {0, 46.125, -289.00449},
  };

  static const double const_result[3][3] = {
      {0.083025, -167.895, 1049.9616036},
      {-125.33938497, 5751.1389840129, -37634.92066548},
      {393.44625, -3803.1492375, 28323.25566129},
  };

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = const_matr[i][j];
      matrix_2.matrix[i][j] = const_matr2[i][j];
    }
  }

  ck_assert_int_eq(0, s21_mult_matrix(&matrix_1, &matrix_2, &res));
  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      ck_assert_double_eq_tol(res.matrix[i][j], const_result[i][j], 1e-6);
    }
  }
  s21_remove_matrix(&res);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_mult_matrix_test_fail) {
  matrix_t matrix_1 = INIT_M, matrix_2 = INIT_M, res = INIT_M;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 2, &matrix_2);
  ck_assert_int_eq(0, s21_mult_matrix(&matrix_1, &matrix_2, &res));
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res);
}
END_TEST

Suite *s21_Suite_mult_matrix() {
  Suite *s;

  s = suite_create("Mult matrix unit test");

  TCase *tc1_s21_mult_matrix_test = tcase_create("mult matrix");
  TCase *tc2_s21_mult_matrix_test_fail = tcase_create("fail unit test");

  tcase_add_test(tc1_s21_mult_matrix_test, s21_mult_matrix_test);
  tcase_add_test(tc2_s21_mult_matrix_test_fail, s21_mult_matrix_test_fail);

  suite_add_tcase(s, tc1_s21_mult_matrix_test);
  suite_add_tcase(s, tc2_s21_mult_matrix_test_fail);

  return s;
}
