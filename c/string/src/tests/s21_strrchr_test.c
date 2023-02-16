#include "test.h"

START_TEST(s21_strrchr_test1) {
    char *str = "Hello, world!";
    int c = 'o';

    char *res = s21_strrchr(str, c);

    ck_assert_str_eq(res, strrchr(str, c));
} END_TEST

START_TEST(s21_strrchr_test2) {
    char *str = "Hello, world!";
    int c = 'a';

    char *res = s21_strrchr(str, c);

    ck_assert_ptr_eq(res, strrchr(str, c));
} END_TEST

START_TEST(s21_strrchr_test3) {
    char *str = "Hello, world!";
    int c = 0;

    char *res = s21_strrchr(str, c);

    ck_assert_str_eq(res, strrchr(str, c));
} END_TEST

START_TEST(s21_strrchr_test4) {
    char *str = "";
    int c = 47;

    char *res = s21_strrchr(str, c);

    ck_assert_ptr_eq(res, strrchr(str, c));
} END_TEST

START_TEST(s21_strrchr_test5) {
    char *str = "";
    int c = 0;

    char *res = s21_strrchr(str, c);

    ck_assert_ptr_eq(res, strrchr(str, c));
} END_TEST

START_TEST(s21_strrchr_test6) {
    char *str = "fwefewgwf";
    int c = 0;

    char *res = s21_strrchr(str, c);

    ck_assert_ptr_eq(res, strrchr(str, c));
} END_TEST

START_TEST(s21_strrchr_test7) {
    char str1[] = "abcdefghijklmnopqrst";
    int n = 't';
    ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
} END_TEST

START_TEST(s21_strrchr_test8) {
    char str1[] = "abcdefghijklmnopqrst";
    int n = '1';
    ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
} END_TEST

Suite *s21_Suite_strrchr() {
    Suite *s;

    s = suite_create("Strrchr Unit Test");

    TCase *tc1_s21_strrchr = tcase_create("test1_s21_strrchr");
    TCase *tc2_s21_strrchr = tcase_create("test2_s21_strrchr");
    TCase *tc3_s21_strrchr = tcase_create("test3_s21_strrchr");
    TCase *tc4_s21_strrchr = tcase_create("test4_s21_strrchr");
    TCase *tc5_s21_strrchr = tcase_create("test5_s21_strrchr");
    TCase *tc6_s21_strrchr = tcase_create("test6_s21_strrchr");
    TCase *tc7_s21_strrchr = tcase_create("test7_s21_strrchr");
    TCase *tc8_s21_strrchr = tcase_create("test8_s21_strrchr");

    tcase_add_test(tc1_s21_strrchr, s21_strrchr_test1);
    tcase_add_test(tc2_s21_strrchr, s21_strrchr_test2);
    tcase_add_test(tc3_s21_strrchr, s21_strrchr_test3);
    tcase_add_test(tc4_s21_strrchr, s21_strrchr_test4);
    tcase_add_test(tc5_s21_strrchr, s21_strrchr_test5);
    tcase_add_test(tc6_s21_strrchr, s21_strrchr_test6);
    tcase_add_test(tc7_s21_strrchr, s21_strrchr_test7);
    tcase_add_test(tc8_s21_strrchr, s21_strrchr_test8);

    suite_add_tcase(s, tc1_s21_strrchr);
    suite_add_tcase(s, tc2_s21_strrchr);
    suite_add_tcase(s, tc3_s21_strrchr);
    suite_add_tcase(s, tc4_s21_strrchr);
    suite_add_tcase(s, tc5_s21_strrchr);
    suite_add_tcase(s, tc6_s21_strrchr);
    suite_add_tcase(s, tc7_s21_strrchr);
    suite_add_tcase(s, tc8_s21_strrchr);

    return s;
}
