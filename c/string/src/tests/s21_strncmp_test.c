#include "test.h"

START_TEST(s21_strncmp_test1) {
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, world!";
    s21_size_t n = 13;

    int res = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(res, strncmp(str1, str2, n));
} END_TEST

START_TEST(s21_strncmp_test2) {
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, world!";
    s21_size_t n = 10;

    int res = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(res, strncmp(str1, str2, n));
} END_TEST

START_TEST(s21_strncmp_test3) {
    const char str1[20] = "Hello";
    const char str2[20] = "Hello, world!";
    s21_size_t n = 10;

    int res = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(res, strncmp(str1, str2, n));
} END_TEST

START_TEST(s21_strncmp_test4) {
    const char str1[20] = "Hello, world!";
    const char str2[20] = "Hello";
    s21_size_t n = 10;

    int res = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(res, strncmp(str1, str2, n));
} END_TEST

START_TEST(s21_strncmp_test5) {
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello! BOB!";
    s21_size_t n = 10;

    int res = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(res, strncmp(str1, str2, n));
} END_TEST

START_TEST(s21_strncmp_test6) {
    const char *str1 = "Biva";
    const char *str2 = "Biva BBBB";
    s21_size_t n = 4;

    int res = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(res, strncmp(str1, str2, n));
} END_TEST

START_TEST(s21_strncmp_test7) {
    const char *str1 = "Gustav Mahler";
    const char *str2 = "Gust5v";
    s21_size_t n = 7;

    int res = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(res, strncmp(str1, str2, n));
} END_TEST

START_TEST(s21_strncmp_test8) {
    const char *str1 = "Gust1av Mahler";
    const char *str2 = "Gust5v";
    s21_size_t n = 5;

    int res = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(res, strncmp(str1, str2, n));
} END_TEST

START_TEST(s21_strncmp_test9) {
    const char *str1 = "GusT";
    const char *str2 = "Gust5v";
    s21_size_t n = 5;

    int res = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(res, strncmp(str1, str2, n));
} END_TEST

START_TEST(s21_strncmp_test10) {
    const char *str1 = "GusMahler";
    const char *str2 = "GustMv";
    s21_size_t n = 5;

    int res = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(res, strncmp(str1, str2, n));
} END_TEST

START_TEST(s21_strncmp_test11) {
    char str1[] = "1234";
    char str2[] = "123";
    int n = 4;
    int s21 = s21_strncmp(str1, str2, n);
    int s00 = strncmp(str1, str2, n);
    ck_assert_int_eq(s21, s00);
} END_TEST

START_TEST(s21_strncmp_test12) {
    char str1[] = "abc";
    char str2[] = "abcd";
    int n = 4;
    int s21 = s21_strncmp(str1, str2, n);
    int s00 = strncmp(str1, str2, n);
    ck_assert_int_eq(s21, s00);
} END_TEST

START_TEST(s21_strncmp_test13) {
    char str1[] = "abc";
    char str2[] = "abc";
    int n = 10;
    int s21 = s21_strncmp(str1, str2, n);
    int s00 = strncmp(str1, str2, n);
    ck_assert_int_eq(s21, s00);
} END_TEST

START_TEST(s21_strncmp_test14) {
    char str1[] = "Abc";
    char str2[] = "abc";
    int n = 10;
    int s21 = s21_strncmp(str1, str2, n);
    int s00 = strncmp(str1, str2, n);
    ck_assert_int_eq(s21, s00);
} END_TEST


Suite *s21_Suite_strncmp() {
    Suite *s;

    s = suite_create("Strncmp Unit Test");

    TCase *tc1_s21_strncmp = tcase_create("test1_s21_strncmp");
    TCase *tc2_s21_strncmp = tcase_create("test2_s21_strncmp");
    TCase *tc3_s21_strncmp = tcase_create("test3_s21_strncmp");
    TCase *tc4_s21_strncmp = tcase_create("test4_s21_strncmp");
    TCase *tc5_s21_strncmp = tcase_create("test5_s21_strncmp");
    TCase *tc6_s21_strncmp = tcase_create("test6_s21_strncmp");
    TCase *tc7_s21_strncmp = tcase_create("test7_s21_strncmp");
    TCase *tc8_s21_strncmp = tcase_create("test8_s21_strncmp");
    TCase *tc9_s21_strncmp = tcase_create("test9_s21_strncmp");
    TCase *tc10_s21_strncmp = tcase_create("test10_s21_strncmp");
    TCase *tc11_s21_strncmp = tcase_create("test11_s21_strncmp");
    TCase *tc12_s21_strncmp = tcase_create("test12_s21_strncmp");
    TCase *tc13_s21_strncmp = tcase_create("test13_s21_strncmp");
    TCase *tc14_s21_strncmp = tcase_create("test14_s21_strncmp");

    tcase_add_test(tc1_s21_strncmp, s21_strncmp_test1);
    tcase_add_test(tc2_s21_strncmp, s21_strncmp_test2);
    tcase_add_test(tc3_s21_strncmp, s21_strncmp_test3);
    tcase_add_test(tc4_s21_strncmp, s21_strncmp_test4);
    tcase_add_test(tc5_s21_strncmp, s21_strncmp_test5);
    tcase_add_test(tc6_s21_strncmp, s21_strncmp_test6);
    tcase_add_test(tc7_s21_strncmp, s21_strncmp_test7);
    tcase_add_test(tc8_s21_strncmp, s21_strncmp_test8);
    tcase_add_test(tc9_s21_strncmp, s21_strncmp_test9);
    tcase_add_test(tc10_s21_strncmp, s21_strncmp_test10);
    tcase_add_test(tc11_s21_strncmp, s21_strncmp_test11);
    tcase_add_test(tc12_s21_strncmp, s21_strncmp_test12);
    tcase_add_test(tc13_s21_strncmp, s21_strncmp_test13);
    tcase_add_test(tc14_s21_strncmp, s21_strncmp_test14);

    suite_add_tcase(s, tc1_s21_strncmp);
    suite_add_tcase(s, tc2_s21_strncmp);
    suite_add_tcase(s, tc3_s21_strncmp);
    suite_add_tcase(s, tc4_s21_strncmp);
    suite_add_tcase(s, tc5_s21_strncmp);
    suite_add_tcase(s, tc6_s21_strncmp);
    suite_add_tcase(s, tc7_s21_strncmp);
    suite_add_tcase(s, tc8_s21_strncmp);
    suite_add_tcase(s, tc9_s21_strncmp);
    suite_add_tcase(s, tc10_s21_strncmp);
    suite_add_tcase(s, tc11_s21_strncmp);
    suite_add_tcase(s, tc12_s21_strncmp);
    suite_add_tcase(s, tc13_s21_strncmp);
    suite_add_tcase(s, tc14_s21_strncmp);

    return s;
}
