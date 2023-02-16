#include "test.h"

START_TEST(s21_to_uplow_test1) {
    char dest[1000]= "Biba Boba";
    char *res1 = s21_to_upper(dest);
    ck_assert_str_eq(res1, "BIBA BOBA");
    char *res2 = s21_to_lower(dest);
    ck_assert_str_eq(res2, "biba boba");
    free(res1);
    free(res2);
} END_TEST

START_TEST(s21_to_uplow_test2) {
    char *dest = s21_NULL;
    char *res1 = s21_to_upper(dest);
    ck_assert_ptr_eq(res1, NULL);
    char *res2 = s21_to_lower(dest);
    ck_assert_ptr_eq(res2, NULL);
    free(res1);
    free(res2);
} END_TEST

Suite *s21_Suite_to_uplow() {
    Suite *s;
    s = suite_create("To_uplow Unit test");

    TCase *tc1_s21_to_uplow = tcase_create("test1_s21_to_uplow");
    TCase *tc2_s21_to_uplow = tcase_create("test2_s21_to_uplow");

    tcase_add_test(tc1_s21_to_uplow, s21_to_uplow_test1);
    tcase_add_test(tc2_s21_to_uplow, s21_to_uplow_test2);

    suite_add_tcase(s, tc1_s21_to_uplow);
    suite_add_tcase(s, tc2_s21_to_uplow);

  return s;
}
