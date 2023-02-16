#include "test.h"

START_TEST(s21_insert_test1) {
    char src[] = "My string";
    char str[] = "aloha!";
    s21_size_t start_index = 3;
    void *res;
    char right[] = "My aloha!string";
    res = s21_insert(src, str, start_index);
    ck_assert_str_eq(res, right);
    free(res);
} END_TEST

START_TEST(s21_insert_test2) {
    char str1[] = "";
    char str2[] = "check";
    s21_size_t start = 0;
    char *res;
    char right[] = "check";
    res = s21_insert(str1, str2, start);
    ck_assert_str_eq(res, right);
    free(res);
} END_TEST


START_TEST(s21_insert_test3) {
    char str1[] = "Ma string";
    char str2[] = "";
    s21_size_t start = 5;
    char *res;
    char right[] = "Ma string";
    res = s21_insert(str1, str2, start);
    ck_assert_str_eq(right, res);
    free(res);
} END_TEST

Suite *s21_Suite_insert() {
    Suite *s;

    s = suite_create("Insert Unit Test");

    TCase *tc1_s21_insert = tcase_create("test1_s21_insert");
    TCase *tc2_s21_insert = tcase_create("test2_s21_insert");
    TCase *tc3_s21_insert = tcase_create("test3_s21_insert");

    tcase_add_test(tc1_s21_insert, s21_insert_test1);
    tcase_add_test(tc2_s21_insert, s21_insert_test2);
    tcase_add_test(tc3_s21_insert, s21_insert_test3);

    suite_add_tcase(s, tc1_s21_insert);
    suite_add_tcase(s, tc2_s21_insert);
    suite_add_tcase(s, tc3_s21_insert);

    return s;
}
