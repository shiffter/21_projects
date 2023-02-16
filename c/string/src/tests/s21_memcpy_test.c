#include "test.h"

START_TEST(s21_memcpy_test1) {
    char dest[20]= "Biba Boba";
    char src[20] = "Boba";
    s21_size_t n = 4;

    char *res = s21_memcpy(dest, src, n);

    ck_assert_str_eq(res, memcpy(dest, src, n));
} END_TEST

START_TEST(s21_memcpy_test2) {
    char dest[20]= "Biba Boba";
    char src[20] = "Boba";
    s21_size_t n = 0;

    char *res = s21_memcpy(dest, src, n);

    ck_assert_str_eq(res, memcpy(dest, src, n));
} END_TEST

START_TEST(s21_memcpy_test3) {
    char dest[20] = "";
    char src[20] = "Boba";
    s21_size_t n = 0;

    char *res = s21_memcpy(dest, src, n);

    ck_assert_ptr_eq(res, memcpy(dest, src, n));
} END_TEST

START_TEST(s21_memcpy_test4) {
    char dest[20] = "";
    char src[20] = "";
    s21_size_t n = 0;

    char *res = s21_memcpy(dest, src, n);

    ck_assert_ptr_eq(res, memcpy(dest, src, n));
} END_TEST

START_TEST(s21_memcpy_test5) {
    char dest[30] = "NURSULTAN NAZARBAEV";
    char src[20] = "";
    s21_size_t n = 0;

    char *res = s21_memcpy(dest, src, n);

    ck_assert_ptr_eq(res, memcpy(dest, src, n));
} END_TEST



Suite *s21_Suite_memcpy() {
    Suite *s;
    s = suite_create("Memcpy Unit Test");

    TCase *tc1_s21_memcpy = tcase_create("test1_s21_memcpy");
    TCase *tc2_s21_memcpy = tcase_create("test2_s21_memcpy");
    TCase *tc3_s21_memcpy = tcase_create("test3_s21_memcpy");
    TCase *tc4_s21_memcpy = tcase_create("test4_s21_memcpy");
    TCase *tc5_s21_memcpy = tcase_create("test5_s21_memcpy");

    tcase_add_test(tc1_s21_memcpy, s21_memcpy_test1);
    tcase_add_test(tc2_s21_memcpy, s21_memcpy_test2);
    tcase_add_test(tc3_s21_memcpy, s21_memcpy_test3);
    tcase_add_test(tc4_s21_memcpy, s21_memcpy_test4);
    tcase_add_test(tc5_s21_memcpy, s21_memcpy_test5);

    suite_add_tcase(s, tc1_s21_memcpy);
    suite_add_tcase(s, tc2_s21_memcpy);
    suite_add_tcase(s, tc3_s21_memcpy);
    suite_add_tcase(s, tc4_s21_memcpy);
    suite_add_tcase(s, tc5_s21_memcpy);


  return s;
}
