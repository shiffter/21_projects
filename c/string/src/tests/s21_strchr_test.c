#include "test.h"

START_TEST(s21_strchr_test1) {
    char str[] = "0123456789abcdef";
    int c = '5';

    char *res = s21_strchr(str, c);

    ck_assert_str_eq(res, strchr(str, c));
} END_TEST

START_TEST(s21_strchr_test2) {
    char str[] = "0123456789abcdef";
    int c = ' ';

    char *res = s21_strchr(str, c);

    ck_assert_ptr_eq(res, strchr(str, c));
} END_TEST

START_TEST(s21_strchr_test3) {
    char str[] = "";
    int c = ' ';

    char *res = s21_strchr(str, c);

    ck_assert_ptr_eq(res, strchr(str, c));
} END_TEST

START_TEST(s21_strchr_test4) {
    char str[] = "Hello";
    int c = 0;

    char *res = s21_strchr(str, c);

    ck_assert_ptr_eq(res, strchr(str, c));
} END_TEST

START_TEST(s21_strchr_test5) {
    char str1[] = "abc";
    int n = 'a';
    ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
} END_TEST

START_TEST(s21_strchr_test6) {
    char str1[] = "abc";
    int n = 'd';
    ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
} END_TEST

START_TEST(s21_strchr_test7) {
    char str1[] = "abc";
    int n = '1';
    ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
} END_TEST

START_TEST(s21_strchr_test8) {
    char str1[] = "abc";
    int n = '\\';
    ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
} END_TEST

Suite *s21_Suite_strchr() {
    Suite *s;

    s = suite_create("Strchr Unit Test");

    TCase *tc1_s21_strchr = tcase_create("test1_s21_strchr");
    TCase *tc2_s21_strchr = tcase_create("test2_s21_strchr");
    TCase *tc3_s21_strchr = tcase_create("test3_s21_strchr");
    TCase *tc4_s21_strchr = tcase_create("test4_s21_strchr");
    TCase *tc5_s21_strchr = tcase_create("test5_s21_strchr");
    TCase *tc6_s21_strchr = tcase_create("test6_s21_strchr");
    TCase *tc7_s21_strchr = tcase_create("test7_s21_strchr");
    TCase *tc8_s21_strchr = tcase_create("test8_s21_strchr");

    tcase_add_test(tc1_s21_strchr, s21_strchr_test1);
    tcase_add_test(tc2_s21_strchr, s21_strchr_test2);
    tcase_add_test(tc3_s21_strchr, s21_strchr_test3);
    tcase_add_test(tc4_s21_strchr, s21_strchr_test4);
    tcase_add_test(tc5_s21_strchr, s21_strchr_test5);
    tcase_add_test(tc6_s21_strchr, s21_strchr_test6);
    tcase_add_test(tc7_s21_strchr, s21_strchr_test7);
    tcase_add_test(tc8_s21_strchr, s21_strchr_test8);

    suite_add_tcase(s, tc1_s21_strchr);
    suite_add_tcase(s, tc2_s21_strchr);
    suite_add_tcase(s, tc3_s21_strchr);
    suite_add_tcase(s, tc4_s21_strchr);
    suite_add_tcase(s, tc5_s21_strchr);
    suite_add_tcase(s, tc6_s21_strchr);
    suite_add_tcase(s, tc7_s21_strchr);
    suite_add_tcase(s, tc8_s21_strchr);

    return s;
}
