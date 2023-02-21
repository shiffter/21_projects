#include "test.h"

START_TEST(s21_calc_complements_test) {
  matrix_t matrix_1 = INIT_M, res = INIT_M;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &res);
  static const double result[3][3] = {
      {-1217.8697959, 668.07813, 106.625},
      {-45.5, -11.74815, -1.875},
      {-15.040844, -49.5472, -0.619815},
  };

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = const_matr[i][j];
      res.matrix[i][j] = 0;
    }
  }

  ck_assert_int_eq(0, s21_calc_complements(&matrix_1, &res));
  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      ck_assert_double_eq_tol(res.matrix[i][j], result[i][j], 1e-6);
    }
  }
  s21_remove_matrix(&res);
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_calc_complements_test_fail) {
  matrix_t matrix_1 = INIT_M, matrix_2 = INIT_M, res = INIT_M;
  s21_create_matrix(2, 3, &matrix_1);
  s21_create_matrix(-2, 5, &matrix_2);
  ck_assert_int_eq(2, s21_calc_complements(&matrix_1, &res));
  s21_remove_matrix(&matrix_1);
  ck_assert_int_eq(1, s21_calc_complements(&matrix_2, &res));
  matrix_2.matrix = NULL;
  ck_assert_int_eq(1, s21_calc_complements(&matrix_2, &res));
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *s21_Suite_calc_complements() {
  Suite *s;

  s = suite_create("Calculation complements of matrix unit test");

  TCase *tc1_s21_calc_complements_test =
      tcase_create("Calcculation complements of matrix");
  TCase *tc2_s21_calc_complements_test_fail = tcase_create("fail test");

  tcase_add_test(tc1_s21_calc_complements_test, s21_calc_complements_test);
  tcase_add_test(tc2_s21_calc_complements_test_fail,
                 s21_calc_complements_test_fail);

  suite_add_tcase(s, tc1_s21_calc_complements_test);
  suite_add_tcase(s, tc2_s21_calc_complements_test_fail);

  return s;
}
