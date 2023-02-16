#include "test.h"

START_TEST(s21_strstr_test1) {
    char str1[] = "01234abc56789";
    char str2[] = "789";

    char *res = s21_strstr(str1, str2);

    ck_assert_str_eq(res, strstr(str1, str2));
} END_TEST

START_TEST(s21_strstr_test2) {
    char str1[] = "01234abc56789";
    char str2[] = "abc";

    char *res = s21_strstr(str1, str2);

    ck_assert_str_eq(res, strstr(str1, str2));
    } END_TEST

START_TEST(s21_strstr_test3) {
    char str1[] = "01234abc56789";
    char str2[] = "123";

    char *res = s21_strstr(str1, str2);

    ck_assert_str_eq(res, strstr(str1, str2));
} END_TEST
START_TEST(s21_strstr_test4) {
    char str1[] = "01234abc56789";
    char str2[] = "bc89";

    char *res = s21_strstr(str1, str2);

    ck_assert_ptr_eq(res, strstr(str1, str2));
} END_TEST

START_TEST(s21_strstr_test5) {
    char str1[] = "01234abc56789";
    char str2[] = "0";

    char *res = s21_strstr(str1, str2);

    ck_assert_str_eq(res, strstr(str1, str2));
} END_TEST

START_TEST(s21_strstr_test6) {
    char str1[] = "01234abc56789";
    char str2[] = "56789123";

    char *res = s21_strstr(str1, str2);

    ck_assert_ptr_eq(res, strstr(str1, str2));
} END_TEST

START_TEST(s21_strstr_test7) {
    char str1[] = "";
    char str2[] = "12";

    char *res = s21_strstr(str1, str2);

    ck_assert_ptr_eq(res, strstr(str1, str2));
} END_TEST

START_TEST(s21_strstr_test8) {
    char str1[] = "12";
    char str2[] = "12";

    char *res = s21_strstr(str1, str2);

    ck_assert_ptr_eq(res, strstr(str1, str2));
} END_TEST

START_TEST(s21_strstr_test9) {
    char str1[] = "12";
    char str2[] = "";

    char *res = s21_strstr(str1, str2);

    ck_assert_str_eq(res, strstr(str1, str2));
} END_TEST

START_TEST(s21_strstr_test10) {
    char str1[] = "";
    char str2[] = "";

    char *res = s21_strstr(str1, str2);

    ck_assert_str_eq(res, strstr(str1, str2));
} END_TEST

Suite *s21_Suite_strstr() {
    Suite *s;

    s = suite_create("Strstr Unit Test");

    TCase *tc1_s21_strstr = tcase_create("test1_s21_strcspn");
    TCase *tc2_s21_strstr = tcase_create("test2_s21_strcspn");
    TCase *tc3_s21_strstr = tcase_create("test3_s21_strcspn");
    TCase *tc4_s21_strstr = tcase_create("test4_s21_strcspn");
    TCase *tc5_s21_strstr = tcase_create("test5_s21_strcspn");
    TCase *tc6_s21_strstr = tcase_create("test6_s21_strcspn");
    TCase *tc7_s21_strstr = tcase_create("test7_s21_strcspn");
    TCase *tc8_s21_strstr = tcase_create("test8_s21_strcspn");
    TCase *tc9_s21_strstr = tcase_create("test9_s21_strcspn");
    TCase *tc10_s21_strstr = tcase_create("test10_s21_strcspn");

    tcase_add_test(tc1_s21_strstr, s21_strstr_test1);
    tcase_add_test(tc2_s21_strstr, s21_strstr_test2);
    tcase_add_test(tc3_s21_strstr, s21_strstr_test3);
    tcase_add_test(tc4_s21_strstr, s21_strstr_test4);
    tcase_add_test(tc5_s21_strstr, s21_strstr_test5);
    tcase_add_test(tc6_s21_strstr, s21_strstr_test6);
    tcase_add_test(tc7_s21_strstr, s21_strstr_test7);
    tcase_add_test(tc8_s21_strstr, s21_strstr_test8);
    tcase_add_test(tc9_s21_strstr, s21_strstr_test9);
    tcase_add_test(tc10_s21_strstr, s21_strstr_test10);

    suite_add_tcase(s, tc1_s21_strstr);
    suite_add_tcase(s, tc2_s21_strstr);
    suite_add_tcase(s, tc3_s21_strstr);
    suite_add_tcase(s, tc4_s21_strstr);
    suite_add_tcase(s, tc5_s21_strstr);
    suite_add_tcase(s, tc6_s21_strstr);
    suite_add_tcase(s, tc7_s21_strstr);
    suite_add_tcase(s, tc8_s21_strstr);
    suite_add_tcase(s, tc9_s21_strstr);
    suite_add_tcase(s, tc10_s21_strstr);

    return s;
}
