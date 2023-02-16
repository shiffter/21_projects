#include "test.h"

START_TEST(s21_strerror_test1) {
    s21_size_t i = 0;
    while (i < 135) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
        i++;
    }
} END_TEST

Suite *s21_Suite_strerror() {
    Suite *s;
    s = suite_create("Strerror Unit Test");

    TCase *tc1_s21_strerror = tcase_create("test1_s21_strerror");

    tcase_add_test(tc1_s21_strerror, s21_strerror_test1);

    suite_add_tcase(s, tc1_s21_strerror);

  return s;
}
