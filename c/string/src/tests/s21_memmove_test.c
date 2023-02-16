#include "test.h"

START_TEST(s21_memmove_test1) {
    char dest[] = "foo-bar";
    s21_size_t n = 4;
    char *res = s21_memmove(dest + 3, dest + 4, n);

    ck_assert_str_eq(res, memmove(dest + 3, dest + 4, n));
} END_TEST

START_TEST(s21_memmove_test2) {
    char dest[] = "stackoverflow";
    s21_size_t n = 7;
    char *res = s21_memmove(dest + 5, dest, n);

    ck_assert_str_eq(res, memmove(dest + 5, dest, n));
} END_TEST

START_TEST(s21_memmove_test3) {
    char dest[50] = "stackoverflow";
    s21_size_t n = strlen(dest);
    char *res = s21_memmove(dest + 4, dest, n);

    ck_assert_str_eq(res, memmove(dest + 4, dest, n));
} END_TEST

START_TEST(s21_memmove_test4) {
    char dest[50] = "stackoverflow";
    s21_size_t n = 0;
    char *res = s21_memmove(dest, dest, n);

    ck_assert_str_eq(res, memmove(dest, dest, n));
} END_TEST

START_TEST(s21_memmove_test5) {
    char dest[50] = "stackoverflow";
    s21_size_t n = 2;
    char *res = s21_memmove(dest + 1, dest + 9, n);

    ck_assert_str_eq(res, memmove(dest + 1, dest + 9, n));
} END_TEST

Suite *s21_Suite_memmove() {
    Suite *s;
    s = suite_create("Memmove Unit Test");

    TCase *tc1_s21_memmove = tcase_create("test1_s21_memmove");
    TCase *tc2_s21_memmove = tcase_create("test2_s21_memmove");
    TCase *tc3_s21_memmove = tcase_create("test3_s21_memmove");
    TCase *tc4_s21_memmove = tcase_create("test4_s21_memmove");
    TCase *tc5_s21_memmove = tcase_create("test5_s21_memmove");

    tcase_add_test(tc1_s21_memmove, s21_memmove_test1);
    tcase_add_test(tc2_s21_memmove, s21_memmove_test2);
    tcase_add_test(tc3_s21_memmove, s21_memmove_test3);
    tcase_add_test(tc4_s21_memmove, s21_memmove_test4);
    tcase_add_test(tc5_s21_memmove, s21_memmove_test5);

    suite_add_tcase(s, tc1_s21_memmove);
    suite_add_tcase(s, tc2_s21_memmove);
    suite_add_tcase(s, tc3_s21_memmove);
    suite_add_tcase(s, tc4_s21_memmove);
    suite_add_tcase(s, tc5_s21_memmove);

  return s;
}
