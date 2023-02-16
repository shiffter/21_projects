#include "test.h"

START_TEST(s21_trim_test1) {
    const char *src = "My string";
    const char *trim = "sd";
    char *res;
    res = s21_trim(src, trim);
    char right[] = "My string";
    ck_assert_str_eq(right, res);
    free(res);
} END_TEST

START_TEST(s21_trim_test2) {
    char src[] = "\n\t\v\r\fMy stringsw\n\t\v\r\f";
    char trim[] = "";
    void *res;
    char right[] = "My stringsw";
    res = s21_trim(src, trim);
    ck_assert_str_eq(res, right);
    free(res);
} END_TEST


START_TEST(s21_trim_test3) {
    char src[] = "My string";
    char trim[] = "Mg";
    void *res;
    char right[] = "y strin";
    res = s21_trim(src, trim);
    ck_assert_str_eq(res, right);
    free(res);
} END_TEST

Suite *s21_Suite_trim() {
    Suite *s;

    s = suite_create("Trim Unit Test");

    TCase *tc1_s21_trim = tcase_create("test1_s21_trim");
    TCase *tc2_s21_trim = tcase_create("test2_s21_trim");
    TCase *tc3_s21_trim = tcase_create("test3_s21_trim");

    tcase_add_test(tc1_s21_trim, s21_trim_test1);
    tcase_add_test(tc2_s21_trim, s21_trim_test2);
    tcase_add_test(tc3_s21_trim, s21_trim_test3);

    suite_add_tcase(s, tc1_s21_trim);
    suite_add_tcase(s, tc2_s21_trim);
    suite_add_tcase(s, tc3_s21_trim);

    return s;
}
