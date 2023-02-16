#include "test.h"

START_TEST(s21_strncat_test1) {
    const char *src = "0123456789";
    char dest[50] = "Numbers: ";
    s21_size_t n = 10;

    char *res = s21_strncat(dest, src, n);

    ck_assert_str_eq(res, strncat(dest, src, n));
} END_TEST

START_TEST(s21_strncat_test2) {
    const char *src = "\n";
    char dest[50] = "Numbers: ";
    s21_size_t n = 10;

    char *res = s21_strncat(dest, src, n);

    ck_assert_str_eq(res, strncat(dest, src, n));
} END_TEST

START_TEST(s21_strncat_test3) {
    const char *src = "\0";
    char dest[50] = "\n";
    s21_size_t n = 10;

    char *res = s21_strncat(dest, src, n);

    ck_assert_str_eq(res, strncat(dest, src, n));
} END_TEST

START_TEST(s21_strncat_test4) {
    const char *src = "world!";
    char dest[50] = "Hello, ";
    s21_size_t n = 0;

    char *res = s21_strncat(dest, src, n);

    ck_assert_str_eq(res, strncat(dest, src, n));
} END_TEST

START_TEST(s21_strncat_test5) {
    const char *src = "world!";
    char dest[50] = "Hello, ";
    s21_size_t n = 3;

    char *res = s21_strncat(dest, src, n);

    ck_assert_str_eq(res, strncat(dest, src, n));
} END_TEST

Suite *s21_Suite_strncat() {
    Suite *s;

    s = suite_create("Strncat Unit Test");

    TCase *tc1_s21_strncat = tcase_create("test1_s21_strncat");
    TCase *tc2_s21_strncat = tcase_create("test2_s21_strncat");
    TCase *tc3_s21_strncat = tcase_create("test3_s21_strncat");
    TCase *tc4_s21_strncat = tcase_create("test4_s21_strncat");
    TCase *tc5_s21_strncat = tcase_create("test5_s21_strncat");

    tcase_add_test(tc1_s21_strncat, s21_strncat_test1);
    tcase_add_test(tc2_s21_strncat, s21_strncat_test2);
    tcase_add_test(tc3_s21_strncat, s21_strncat_test3);
    tcase_add_test(tc4_s21_strncat, s21_strncat_test4);
    tcase_add_test(tc5_s21_strncat, s21_strncat_test5);

    suite_add_tcase(s, tc1_s21_strncat);
    suite_add_tcase(s, tc2_s21_strncat);
    suite_add_tcase(s, tc3_s21_strncat);
    suite_add_tcase(s, tc4_s21_strncat);
    suite_add_tcase(s, tc5_s21_strncat);

    return s;
}
