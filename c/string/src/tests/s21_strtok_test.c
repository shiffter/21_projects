#include "test.h"

START_TEST(s21_strtok_test1) {
    char str1[] = "Hello, my name is ALEX!";
    char str2[] = "Hello, my name is ALEX!";
    char *delim = " ";

    char *res1 = s21_strtok(str1, delim);
    char *res2 = strtok(str2, delim);
    ck_assert_str_eq(res1, res2);
    while (res1 != s21_NULL && res2 != NULL) {
        res1 = s21_strtok(s21_NULL, delim);
        res2 = strtok(NULL, delim);
        if (res1 && res2) {
            ck_assert_str_eq(res1, res2);
        } else {
            ck_assert_ptr_eq(res1, res2);
        }
    }
} END_TEST

START_TEST(s21_strtok_test2) {
    char str1[] = "Hello, my name is ALEX!";
    char str2[] = "Hello, my name is ALEX!";
    char *delim = " lm";

    char *res1 = s21_strtok(str1, delim);
    char *res2 = strtok(str2, delim);
    ck_assert_str_eq(res1, res2);
    while (res1 != s21_NULL && res2 != NULL) {
        res1 = s21_strtok(s21_NULL, delim);
        res2 = strtok(NULL, delim);
        if (res1 && res2) {
            ck_assert_str_eq(res1, res2);
        } else {
            ck_assert_ptr_eq(res1, res2);
        }
    }
} END_TEST

START_TEST(s21_strtok_test3) {
    char str1[] = "- This, a sample string.";
    char str2[] = "- This, a sample string.";
    char *delim = " ,.-";

    char *res1 = s21_strtok(str1, delim);
    char *res2 = strtok(str2, delim);
    ck_assert_str_eq(res1, res2);
    while (res1 != s21_NULL && res2 != NULL) {
        res1 = s21_strtok(s21_NULL, delim);
        res2 = strtok(NULL, delim);
        if (res1 && res2) {
            ck_assert_str_eq(res1, res2);
        } else {
            ck_assert_ptr_eq(res1, res2);
        }
    }
} END_TEST

Suite *s21_Suite_strtok() {
    Suite *s;

    s = suite_create("Strtok Unit Test");

    TCase *tc1_s21_strtok = tcase_create("test1_s21_strtok");
    TCase *tc2_s21_strtok = tcase_create("test2_s21_strtok");
    TCase *tc3_s21_strtok = tcase_create("test3_s21_strtok");

    tcase_add_test(tc1_s21_strtok, s21_strtok_test1);
    tcase_add_test(tc2_s21_strtok, s21_strtok_test2);
    tcase_add_test(tc3_s21_strtok, s21_strtok_test3);

    suite_add_tcase(s, tc1_s21_strtok);
    suite_add_tcase(s, tc2_s21_strtok);
    suite_add_tcase(s, tc3_s21_strtok);

    return s;
}
