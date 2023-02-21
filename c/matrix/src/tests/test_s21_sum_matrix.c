#include "test.h"

START_TEST(s21_sum_matrix_test) {
  matrix_t matrix_1 = INIT_M, matrix_2 = INIT_M, res = INIT_M;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = const_matr[i][j];
      matrix_2.matrix[i][j] = const_matr[i][j];
    }
  }

  ck_assert_int_eq(0, s21_sum_matrix(&matrix_1, &matrix_2, &res));
  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      ck_assert_double_eq(res.matrix[i][j], matrix_1.matrix[i][j] * 2);
    }
  }
  s21_remove_matrix(&res);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_sum_matrix_test_fail) {
  matrix_t matrix_1 = INIT_M, matrix_2 = INIT_M, res = INIT_M;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(2, 3, &matrix_2);
  ck_assert_int_eq(2, s21_sum_matrix(&matrix_1, &matrix_2, &res));
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *s21_Suite_sum_matrix() {
  Suite *s;

  s = suite_create("Sum matrix unit test");

  TCase *tc1_s21_sum_matrix_test = tcase_create("sum matrix");
  TCase *tc2_s21_sum_matrix_test_fail =
      tcase_create("sum not identical matrix");

  tcase_add_test(tc1_s21_sum_matrix_test, s21_sum_matrix_test);
  tcase_add_test(tc2_s21_sum_matrix_test_fail, s21_sum_matrix_test_fail);

  suite_add_tcase(s, tc1_s21_sum_matrix_test);
  suite_add_tcase(s, tc2_s21_sum_matrix_test_fail);

  return s;
}
