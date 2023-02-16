#include "test.h"

START_TEST(s21_memcmp_test1) {
    char dest[11]= "Biba Boba";
    char src[13] = "Biba Boba  ";
    s21_size_t n = 11;

    int res1 = s21_memcmp(dest, src, n);
    int res2 = memcmp(dest, src, n);

    ck_assert_int_eq(res1, res2);
} END_TEST

START_TEST(s21_memcmp_test2) {
    float dest[]= {0.5, 0.6, 0.7, 0.8, 1.0};
    float src[] = {0.5, 0.6, 0.7, 0.8, 1.0};
    s21_size_t n = sizeof(dest);

    int res1 = s21_memcmp(dest, src, n);
    int res2 = memcmp(dest, src, n);

    ck_assert_int_eq(res1, res2);
} END_TEST

START_TEST(s21_memcmp_test3) {
    int dest[]= {5, 6, 7, 8, 1};
    int src[] = {5, 6, 7, 8, 1};
    s21_size_t n = 0;

    int res1 = s21_memcmp(dest, src, n);
    int res2 = memcmp(dest, src, n);

    ck_assert_int_eq(res1, res2);
} END_TEST

Suite *s21_Suite_memcmp() {
    Suite *s;
    s = suite_create("Memcmp Unit Test");

    TCase *tc1_s21_memcmp = tcase_create("test1_s21_memcmp");
    TCase *tc2_s21_memcmp = tcase_create("test2_s21_memcmp");
    TCase *tc3_s21_memcmp = tcase_create("test3_s21_memcmp");

    tcase_add_test(tc1_s21_memcmp, s21_memcmp_test1);
    tcase_add_test(tc2_s21_memcmp, s21_memcmp_test2);
    tcase_add_test(tc3_s21_memcmp, s21_memcmp_test3);

    suite_add_tcase(s, tc1_s21_memcmp);
    suite_add_tcase(s, tc2_s21_memcmp);
    suite_add_tcase(s, tc3_s21_memcmp);

  return s;
}
