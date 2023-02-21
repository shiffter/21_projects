#include "test.h"

START_TEST(s21_eq_matrix_test) {
  matrix_t matrix_1, matrix_2;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  ck_assert_int_eq(matrix_1.columns, matrix_2.columns);
  ck_assert_int_eq(matrix_1.rows, matrix_2.rows);
  ck_assert_int_eq(1, s21_eq_matrix(&matrix_1, &matrix_2));
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_test_fail) {
  matrix_t matrix_1, matrix_2;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 2, &matrix_2);
  ck_assert_int_eq(0, s21_eq_matrix(&matrix_1, &matrix_2));
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  double count = 0.3;
  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = count;
      count += 0.68;
    }
  }
  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      if (i == matrix_2.rows - 1 && j == matrix_2.columns - 1) {
        matrix_2.matrix[j][i] = 0.69;
      } else {
        matrix_2.matrix[i][j] = count;
        count += 0.68;
      }
    }
  }
  ck_assert_int_eq(0, s21_eq_matrix(&matrix_1, &matrix_2));
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  matrix_t *null_p = NULL;

  ck_assert_int_eq(0, s21_eq_matrix(null_p, null_p));
}
END_TEST

Suite *s21_Suite_eq_matrix() {
  Suite *s;

  s = suite_create("Compare matrix unit test");

  TCase *tc1_s21_eq_matrix_test = tcase_create("compare identical matrix");
  TCase *tc2_s21_eq_matrix_test_fail =
      tcase_create("compare not identical matrix");

  tcase_add_test(tc1_s21_eq_matrix_test, s21_eq_matrix_test);
  tcase_add_test(tc2_s21_eq_matrix_test_fail, s21_eq_matrix_test_fail);

  suite_add_tcase(s, tc1_s21_eq_matrix_test);
  suite_add_tcase(s, tc2_s21_eq_matrix_test_fail);

  return s;
}
