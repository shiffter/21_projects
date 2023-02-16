#include "test.h"

START_TEST(s21_memset_test1) {
    char dest[20]= "Biba";
    int c = ' ';
    s21_size_t n = 3;

    char *res = s21_memset(dest, c, n);

    ck_assert_str_eq(res, memset(dest, c, n));
} END_TEST

START_TEST(s21_memset_test2) {
    int dest[10]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int c = 48;
    s21_size_t n = sizeof(dest);

    int *res1 = s21_memset(dest, c, n);
    int *res2 = memset(dest, c, n);
    for (s21_size_t i = 0; i < 10; i++)
        ck_assert_int_eq(res1[i], res2[i]);
} END_TEST

Suite *s21_Suite_memset() {
    Suite *s;
    s = suite_create("Memset Unit Test");

    TCase *tc1_s21_memset = tcase_create("test1_s21_memset");
    TCase *tc2_s21_memset = tcase_create("test2_s21_memset");

    tcase_add_test(tc1_s21_memset, s21_memset_test1);
    tcase_add_test(tc2_s21_memset, s21_memset_test2);

    suite_add_tcase(s, tc1_s21_memset);
    suite_add_tcase(s, tc2_s21_memset);

  return s;
}
