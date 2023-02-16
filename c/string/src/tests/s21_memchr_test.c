#include "test.h"

START_TEST(s21_memchr_test1) {
    char dest[10]= "Biba Boba";
    int c = ' ';
    s21_size_t n = 10;

    char *res = s21_memchr(dest, c, n);

    ck_assert_str_eq(res, memchr(dest, c, n));
} END_TEST

START_TEST(s21_memchr_test2) {
    char dest[9]= "BibaBoba";
    int c = 'a';
    s21_size_t n = 10;

    char *res = s21_memchr(dest, c, n);

    ck_assert_ptr_eq(res, memchr(dest, c, n));
} END_TEST

START_TEST(s21_memchr_test3) {
    char dest[9]= "BibaBoba";
    int c = ' ';
    s21_size_t n = 0;

    char *res = s21_memchr(dest, c, n);

    ck_assert_ptr_eq(res, memchr(dest, c, n));
} END_TEST

START_TEST(s21_memchr_test4) {
    char *dest = "";
    int c = 'a';
    s21_size_t n = 0;

    char *res = s21_memchr(dest, c, n);

    ck_assert_ptr_eq(res, memchr(dest, c, n));
} END_TEST

START_TEST(s21_memchr_test5) {
    char *dest = "";
    int c = 'o';
    s21_size_t n = 0;

    char *res = s21_memchr(dest, c, n);

    ck_assert_ptr_eq(res, memchr(dest, c, n));
} END_TEST

Suite *s21_Suite_memchr() {
    Suite *s;
    s = suite_create("Memchr Unit Test");

    TCase *tc1_s21_memchr = tcase_create("test1_s21_memchr");
    TCase *tc2_s21_memchr = tcase_create("test2_s21_memchr");
    TCase *tc3_s21_memchr = tcase_create("test3_s21_memchr");
    TCase *tc4_s21_memchr = tcase_create("test4_s21_memchr");
    TCase *tc5_s21_memchr = tcase_create("test4_s21_memchr");

    tcase_add_test(tc1_s21_memchr, s21_memchr_test1);
    tcase_add_test(tc2_s21_memchr, s21_memchr_test2);
    tcase_add_test(tc3_s21_memchr, s21_memchr_test3);
    tcase_add_test(tc4_s21_memchr, s21_memchr_test4);
    tcase_add_test(tc5_s21_memchr, s21_memchr_test5);

    suite_add_tcase(s, tc1_s21_memchr);
    suite_add_tcase(s, tc2_s21_memchr);
    suite_add_tcase(s, tc3_s21_memchr);
    suite_add_tcase(s, tc4_s21_memchr);
    suite_add_tcase(s, tc5_s21_memchr);

  return s;
}
