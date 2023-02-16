#include "test.h"

START_TEST(s21_strcspn_test1) {
    char str1[] = "0123456789";
    char str2[] = "789";

    s21_size_t res = s21_strcspn(str1, str2);

    ck_assert_uint_eq(res, strcspn(str1, str2));
} END_TEST

START_TEST(s21_strcspn_test2) {
    char str1[] = "0123456789";
    char str2[] = "01234";

    s21_size_t res = s21_strcspn(str1, str2);

    ck_assert_uint_eq(res, strcspn(str1, str2));
} END_TEST

START_TEST(s21_strcspn_test3) {
    char str1[] = "012";
    char str2[] = "3";

    s21_size_t res = s21_strcspn(str1, str2);

    ck_assert_uint_eq(res, strcspn(str1, str2));
} END_TEST

Suite *s21_Suite_strcspn() {
    Suite *s;

    s = suite_create("Strcspn Unit Test");

    TCase *tc1_s21_strcspn = tcase_create("test1_s21_strcspn");
    TCase *tc2_s21_strcspn = tcase_create("test2_s21_strcspn");
    TCase *tc3_s21_strcspn = tcase_create("test3_s21_strcspn");

    tcase_add_test(tc1_s21_strcspn, s21_strcspn_test1);
    tcase_add_test(tc2_s21_strcspn, s21_strcspn_test2);
    tcase_add_test(tc3_s21_strcspn, s21_strcspn_test3);

    suite_add_tcase(s, tc1_s21_strcspn);
    suite_add_tcase(s, tc2_s21_strcspn);
    suite_add_tcase(s, tc3_s21_strcspn);

    return s;
}
