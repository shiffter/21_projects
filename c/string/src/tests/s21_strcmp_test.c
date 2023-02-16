#include "test.h"

START_TEST(s21_strcmp_test1) {
    const char *str1 = "Hello world\0";
    const char *str2 = "Hello world\0";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

START_TEST(s21_strcmp_test2) {
    const char *str1 = "Hello world\0";
    const char *str2 = "Hello world\n\0";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

START_TEST(s21_strcmp_test3) {
    const char *str1 = "Hello world\n\0";
    const char *str2 = "a\n\0";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST


START_TEST(s21_strcmp_test4) {
    const char *str1 = "a\n\0";
    const char *str2 = " \n\0";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

START_TEST(s21_strcmp_test5) {
    const char *str1 = " \0";
    const char *str2 = " \0";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

START_TEST(s21_strcmp_test6) {
    const char *str1 = "\0";
    const char *str2 = "\n\0";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

START_TEST(s21_strcmp_test7) {
    const char *str1 = "\n\0";
    const char *str2 = "\n\0";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

START_TEST(s21_strcmp_test8) {
    const char *str1 = "\0";
    const char *str2 = "\0";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

Suite *s21_Suite_strcmp() {
    Suite *s;
    s = suite_create("Strcmp Unit Test");

    TCase *tc1_s21_strcmp = tcase_create("test1_s21_strcmp");
    TCase *tc2_s21_strcmp = tcase_create("test2_s21_strcmp");
    TCase *tc3_s21_strcmp = tcase_create("test3_s21_strcmp");
    TCase *tc4_s21_strcmp = tcase_create("test4_s21_strcmp");
    TCase *tc5_s21_strcmp = tcase_create("test5_s21_strcmp");
    TCase *tc6_s21_strcmp = tcase_create("test6_s21_strcmp");
    TCase *tc7_s21_strcmp = tcase_create("test7_s21_strcmp");
    TCase *tc8_s21_strcmp = tcase_create("test8_s21_strcmp");

    tcase_add_test(tc1_s21_strcmp, s21_strcmp_test1);
    tcase_add_test(tc2_s21_strcmp, s21_strcmp_test2);
    tcase_add_test(tc3_s21_strcmp, s21_strcmp_test3);
    tcase_add_test(tc4_s21_strcmp, s21_strcmp_test4);
    tcase_add_test(tc5_s21_strcmp, s21_strcmp_test5);
    tcase_add_test(tc6_s21_strcmp, s21_strcmp_test6);
    tcase_add_test(tc7_s21_strcmp, s21_strcmp_test7);
    tcase_add_test(tc8_s21_strcmp, s21_strcmp_test8);


    suite_add_tcase(s, tc1_s21_strcmp);
    suite_add_tcase(s, tc2_s21_strcmp);
    suite_add_tcase(s, tc3_s21_strcmp);
    suite_add_tcase(s, tc4_s21_strcmp);
    suite_add_tcase(s, tc5_s21_strcmp);
    suite_add_tcase(s, tc6_s21_strcmp);
    suite_add_tcase(s, tc7_s21_strcmp);
    suite_add_tcase(s, tc8_s21_strcmp);

    return s;
}
