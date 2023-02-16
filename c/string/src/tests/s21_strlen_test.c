#include "test.h"

START_TEST(s21_strlen_test1) {
    s21_size_t length1 = s21_strlen("Hello world");

    ck_assert_uint_eq(length1, strlen("Hello world"));
} END_TEST

START_TEST(s21_strlen_test2) {
    s21_size_t length2 = s21_strlen("Hello world\n");

    ck_assert_uint_eq(length2, strlen("Hello world\n"));
} END_TEST

START_TEST(s21_strlen_test3) {
    s21_size_t length3 = s21_strlen("a\n");

    ck_assert_uint_eq(length3, strlen("a\n"));
} END_TEST

START_TEST(s21_strlen_test4) {
    s21_size_t length4 = s21_strlen(" \n");

    ck_assert_uint_eq(length4, strlen(" \n"));
} END_TEST

START_TEST(s21_strlen_test5) {
    s21_size_t length5 = s21_strlen(" ");

    ck_assert_uint_eq(length5, strlen(" "));
} END_TEST

START_TEST(s21_strlen_test6) {
    s21_size_t length6 = s21_strlen("\n");

    ck_assert_uint_eq(length6, strlen("\n"));
} END_TEST

START_TEST(s21_strlen_test7) {
    s21_size_t length7 = s21_strlen("");

    ck_assert_uint_eq(length7, strlen(""));
} END_TEST

Suite *s21_Suite_strlen() {
    Suite *s;

    s = suite_create("Strlen Unit Test");

    TCase *tc1_s21_strlen = tcase_create("test1_s21_strlen");
    TCase *tc2_s21_strlen = tcase_create("test2_s21_strlen");
    TCase *tc3_s21_strlen = tcase_create("test3_s21_strlen");
    TCase *tc4_s21_strlen = tcase_create("test4_s21_strlen");
    TCase *tc5_s21_strlen = tcase_create("test5_s21_strlen");
    TCase *tc6_s21_strlen = tcase_create("test6_s21_strlen");
    TCase *tc7_s21_strlen = tcase_create("test7_s21_strlen");

    tcase_add_test(tc1_s21_strlen, s21_strlen_test1);
    tcase_add_test(tc2_s21_strlen, s21_strlen_test2);
    tcase_add_test(tc3_s21_strlen, s21_strlen_test3);
    tcase_add_test(tc4_s21_strlen, s21_strlen_test4);
    tcase_add_test(tc5_s21_strlen, s21_strlen_test5);
    tcase_add_test(tc6_s21_strlen, s21_strlen_test6);
    tcase_add_test(tc7_s21_strlen, s21_strlen_test7);

    suite_add_tcase(s, tc1_s21_strlen);
    suite_add_tcase(s, tc2_s21_strlen);
    suite_add_tcase(s, tc3_s21_strlen);
    suite_add_tcase(s, tc4_s21_strlen);
    suite_add_tcase(s, tc5_s21_strlen);
    suite_add_tcase(s, tc6_s21_strlen);
    suite_add_tcase(s, tc7_s21_strlen);

    return s;
}
