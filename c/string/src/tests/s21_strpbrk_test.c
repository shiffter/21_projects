#include "test.h"

START_TEST(s21_strpbrk_test1) {
    char str1[] = "01234abc56789";
    char str2[] = "7a9";

    char *res = s21_strpbrk(str1, str2);

    ck_assert_str_eq(res, strpbrk(str1, str2));
} END_TEST

START_TEST(s21_strpbrk_test2) {
    char str1[] = "01234abc56789";
    char str2[] = "k";

    char *res = s21_strpbrk(str1, str2);

    ck_assert_ptr_eq(res, strpbrk(str1, str2));
} END_TEST

Suite *s21_Suite_strbprk() {
    Suite *s;

    s = suite_create("Strstr Unit Test");

    TCase *tc1_s21_strpbrk = tcase_create("test1_s21_strpbrk");
    TCase *tc2_s21_strpbrk = tcase_create("test2_s21_strpbrk");

    tcase_add_test(tc1_s21_strpbrk, s21_strpbrk_test1);
    tcase_add_test(tc2_s21_strpbrk, s21_strpbrk_test2);

    suite_add_tcase(s, tc1_s21_strpbrk);
    suite_add_tcase(s, tc2_s21_strpbrk);

    return s;
}

