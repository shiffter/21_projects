#include "test.h"

START_TEST(s21_remove_matrix_test) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
}
END_TEST

Suite *s21_Suite_remove_matrix() {
  Suite *s;

  s = suite_create("Remove matrix unit test");

  TCase *tc1_s21_remove_matrix_test = tcase_create("remove matrix");

  tcase_add_test(tc1_s21_remove_matrix_test, s21_remove_matrix_test);

  suite_add_tcase(s, tc1_s21_remove_matrix_test);

  return s;
}
