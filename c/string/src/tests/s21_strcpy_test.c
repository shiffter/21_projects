#include "test.h"

START_TEST(s21_strcpy_test1) {
    char dest[20]= "Biba";
    const char *src = "";

    ck_assert_str_eq(s21_strcpy(dest, src), strcpy(dest, src));
} END_TEST

START_TEST(s21_strcpy_test2) {
    char dest[30] = "Vadim lubit shishki";
    const char *src = "";

    ck_assert_str_eq(s21_strcpy(dest, src), strcpy(dest, src));
} END_TEST


START_TEST(s21_strcpy_test3) {
    char dest[30] = "DOROG PLOHIH NE BIVAET";
    const char *src = "(c) Ivan";

    ck_assert_str_eq(s21_strcpy(dest, src), strcpy(dest, src));
} END_TEST

Suite *s21_Suite_strcpy() {
    Suite *s;

    s = suite_create("Strcpy Unit Test");

    TCase *tc1_s21_strcpy = tcase_create("test1_s21_strcpy");
    TCase *tc2_s21_strcpy = tcase_create("test2_s21_strcpy");
    TCase *tc3_s21_strcpy = tcase_create("test3_s21_strcpy");

    tcase_add_test(tc1_s21_strcpy, s21_strcpy_test1);
    tcase_add_test(tc2_s21_strcpy, s21_strcpy_test2);
    tcase_add_test(tc3_s21_strcpy, s21_strcpy_test3);

    suite_add_tcase(s, tc1_s21_strcpy);
    suite_add_tcase(s, tc2_s21_strcpy);
    suite_add_tcase(s, tc3_s21_strcpy);

  return s;
}
