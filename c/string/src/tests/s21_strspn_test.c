#include "test.h"

START_TEST(s21_strspn_test1) {
    char *str1 = "Hello, world!";
    char *str2 = "hel";

    s21_size_t res = s21_strspn(str1, str2);

    ck_assert_uint_eq(res, strspn(str1, str2));
} END_TEST

START_TEST(s21_strspn_test2) {
    char *str1 = "0123456789";
    char *str2 = "210";

    s21_size_t res = s21_strspn(str1, str2);

    ck_assert_uint_eq(res, strspn(str1, str2));
} END_TEST

START_TEST(s21_strspn_test3) {
    char *str1 = "0123456789";
    char *str2 = "987";

    s21_size_t res = s21_strspn(str1, str2);

    ck_assert_uint_eq(res, strspn(str1, str2));
} END_TEST

START_TEST(s21_strspn_test4) {
    char *str1 = "";
    char *str2 = "987";

    s21_size_t res = s21_strspn(str1, str2);

    ck_assert_uint_eq(res, strspn(str1, str2));
    } END_TEST

Suite *s21_Suite_strspn() {
    Suite *s;

    s = suite_create("Strspn Unit Test");

    TCase *tc1_s21_strspn = tcase_create("test1_s21_strspn");
    TCase *tc2_s21_strspn = tcase_create("test2_s21_strspn");
    TCase *tc3_s21_strspn = tcase_create("test3_s21_strspn");
    TCase *tc4_s21_strspn = tcase_create("test4_s21_strspn");

    tcase_add_test(tc1_s21_strspn, s21_strspn_test1);
    tcase_add_test(tc2_s21_strspn, s21_strspn_test2);
    tcase_add_test(tc3_s21_strspn, s21_strspn_test3);
    tcase_add_test(tc4_s21_strspn, s21_strspn_test4);

    suite_add_tcase(s, tc1_s21_strspn);
    suite_add_tcase(s, tc2_s21_strspn);
    suite_add_tcase(s, tc3_s21_strspn);
    suite_add_tcase(s, tc4_s21_strspn);


    return s;
}
