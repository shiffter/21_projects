#include "test.h"

START_TEST(s21_determinant_test) {
  matrix_t matrix_1 = INIT_M;
  s21_create_matrix(4, 4, &matrix_1);
  double D = 0.0;
  double det_res = -263610;
  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = MATR[i][j];
    }
  }
  ck_assert_int_eq(0, s21_determinant(&matrix_1, &D));
  ck_assert_double_eq(det_res, D);
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_determinant_test_fail) {
  matrix_t matrix_1 = INIT_M;
  s21_create_matrix(2, 3, &matrix_1);
  double D = 3.13;
  ck_assert_int_eq(2, s21_determinant(&matrix_1, &D));
  s21_remove_matrix(&matrix_1);
}
END_TEST

Suite *s21_Suite_determinant() {
  Suite *s;

  s = suite_create("Determinant of matrix unit test");

  TCase *tc1_s21_determinant_test = tcase_create("Determinant of matrix");
  TCase *tc2_s21_determinant_test_fail = tcase_create("fail test");

  tcase_add_test(tc1_s21_determinant_test, s21_determinant_test);
  tcase_add_test(tc2_s21_determinant_test_fail, s21_determinant_test_fail);

  suite_add_tcase(s, tc1_s21_determinant_test);
  suite_add_tcase(s, tc2_s21_determinant_test_fail);

  return s;
}
