#include "test.h"

START_TEST(s21_strncpy_test1) {
    char dst[50] = "L()RE";
    const char str1[50] = "SOR";
    s21_size_t n = 13;

    char *reslt = s21_strncpy(dst, str1, n);

    ck_assert_str_eq(reslt, strncpy(dst, str1, n));
} END_TEST

START_TEST(s21_strncpy_test2) {
    char dst[50] = "L()RE";
    const char str1[50] = "SOR";
    s21_size_t n = 2;

    char *reslt = s21_strncpy(dst, str1, n);

    ck_assert_str_eq(reslt, strncpy(dst, str1, n));
} END_TEST

START_TEST(s21_strncpy_test3) {
    char dst[50] = "L()RE";
    const char str1[50] = "SOR";
    s21_size_t n = 0;

    char *reslt = s21_strncpy(dst, str1, n);

    ck_assert_str_eq(reslt, strncpy(dst, str1, n));
} END_TEST

START_TEST(s21_strncpy_test4) {
    char dst[50] = "";
    const char str1[50] = "SOR";
    s21_size_t n = 0;

    char *reslt = s21_strncpy(dst, str1, n);

    ck_assert_ptr_eq(reslt, strncpy(dst, str1, n));
} END_TEST

START_TEST(s21_strncpy_test5) {
    char dst[50] = "";
    const char str1[50] = "SOR";
    s21_size_t n = 0;

    char *reslt = s21_strncpy(dst, str1, n);

    ck_assert_ptr_eq(reslt, strncpy(dst, str1, n));
} END_TEST

Suite *s21_Suite_strncpy() {
    Suite *s;

    s = suite_create("Strncpy Unit Test");

    TCase *tc1_s21_strncpy = tcase_create("test1_s21_strncpy");
    TCase *tc2_s21_strncpy = tcase_create("test2_s21_strncpy");
    TCase *tc3_s21_strncpy = tcase_create("test3_s21_strncpy");
    TCase *tc4_s21_strncpy = tcase_create("test4_s21_strncpy");
    TCase *tc5_s21_strncpy = tcase_create("test5_s21_strncpy");

    tcase_add_test(tc1_s21_strncpy, s21_strncpy_test1);
    tcase_add_test(tc2_s21_strncpy, s21_strncpy_test2);
    tcase_add_test(tc3_s21_strncpy, s21_strncpy_test3);
    tcase_add_test(tc4_s21_strncpy, s21_strncpy_test4);
    tcase_add_test(tc5_s21_strncpy, s21_strncpy_test5);

    suite_add_tcase(s, tc1_s21_strncpy);
    suite_add_tcase(s, tc2_s21_strncpy);
    suite_add_tcase(s, tc3_s21_strncpy);
    suite_add_tcase(s, tc4_s21_strncpy);
    suite_add_tcase(s, tc5_s21_strncpy);

    return s;
}
