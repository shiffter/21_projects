#include "test.h"

START_TEST(s21_strcat_test1) {
    char dest[20]= "Biba";
    const char *src = "andBoba";

    ck_assert_str_eq(s21_strcat(dest, src), strcat(dest, src));
} END_TEST

START_TEST(s21_strcat_test2) {
    char dest[20]= "Biba";
    const char *src = "";

    ck_assert_str_eq(s21_strcat(dest, src), strcat(dest, src));
} END_TEST

Suite *s21_Suite_strcat() {
    Suite *s;
    s = suite_create("Strcat Unit Test");

    TCase *tc1_s21_strcat = tcase_create("test1_s21_strcat");
    TCase *tc2_s21_strcat = tcase_create("test2_s21_strcat");

    tcase_add_test(tc1_s21_strcat, s21_strcat_test1);
    tcase_add_test(tc1_s21_strcat, s21_strcat_test2);

    suite_add_tcase(s, tc1_s21_strcat);
    suite_add_tcase(s, tc2_s21_strcat);

  return s;
}
