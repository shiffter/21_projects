#include "test.h"

START_TEST(s21_inverse_matrix_test) {
  matrix_t matrix_1, res;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &res);
  static const double result[3][3] = {
      {2.13364, 0.0797133, 0.0263507},
      {-1.17043, 0.0205821, 0.0868038},
      {-0.186801, 0.003284, 0.00108588},
  };

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = const_matr[i][j];
      res.matrix[i][j] = 0;
    }
  }

  ck_assert_int_eq(0, s21_inverse_matrix(&matrix_1, &res));
  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      ck_assert_double_eq_tol(res.matrix[i][j], result[i][j], 1e-3);
    }
  }
  s21_remove_matrix(&res);
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_inverse_matrix_test_fail) {
  matrix_t matrix_1, res;
  s21_create_matrix(2, 3, &matrix_1);
  s21_create_matrix(3, 3, &res);

  ck_assert_int_eq(2, s21_inverse_matrix(&matrix_1, &res));
  s21_remove_matrix(&matrix_1);
}
END_TEST

Suite *s21_Suite_inverse_matrix() {
  Suite *s;

  s = suite_create("inversion matrix unit test");

  TCase *tc1_s21_inverse_matrix_test = tcase_create("inversion matrix");
  TCase *tc2_s21_inverse_matrix_test_fail = tcase_create("fail test");

  tcase_add_test(tc1_s21_inverse_matrix_test, s21_inverse_matrix_test);
  tcase_add_test(tc2_s21_inverse_matrix_test_fail,
                 s21_inverse_matrix_test_fail);

  suite_add_tcase(s, tc1_s21_inverse_matrix_test);
  suite_add_tcase(s, tc2_s21_inverse_matrix_test_fail);

  return s;
}
