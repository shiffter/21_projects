#include "test.h"

START_TEST(s21_create_matrix_test) {
  matrix_t matrix = INIT_M;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &matrix));
  ck_assert_int_eq(3, matrix.rows);
  ck_assert_int_eq(3, matrix.columns);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_int_eq(0, matrix.matrix[i][j]);
  }
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_fail) {
  matrix_t matrix = INIT_M;
  ck_assert_int_eq(1, s21_create_matrix(3, 0, &matrix));
  ck_assert_int_eq(1, s21_create_matrix(0, 1, &matrix));
  ck_assert_int_eq(1, s21_create_matrix(0, 0, &matrix));
}
END_TEST

Suite *s21_Suite_create_matrix() {
  Suite *s;

  s = suite_create("Create matrix unit test");

  TCase *tc1_s21_create_matrix_test = tcase_create("create matrix");
  TCase *tc2_s21_create_matrix_test_fail = tcase_create("fail create matrix");

  tcase_add_test(tc1_s21_create_matrix_test, s21_create_matrix_test);
  tcase_add_test(tc2_s21_create_matrix_test_fail, s21_create_matrix_test_fail);

  suite_add_tcase(s, tc1_s21_create_matrix_test);
  suite_add_tcase(s, tc2_s21_create_matrix_test_fail);

  return s;
}
