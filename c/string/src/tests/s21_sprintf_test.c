#include "test.h"

START_TEST(s21_sprintf_test1_d) {  // int n = 777;
    int n = 777;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%d", n);
    int b = sprintf(str2, "%d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test2_d) {  // int n = 000;
    int n = 000;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%d", n);
    int b = sprintf(str2, "%d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test3_d) {  // int n = -123
    int n = -123;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%d", n);
    int b = sprintf(str2, "%d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test4_d) {  // int n = 0, " %d"
    int n = 0;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, " %d", n);
    int b = sprintf(str2, " %d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test5_d) {  // int n = -0, " %d"
    int n = -0;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, " %d", n);
    int b = sprintf(str2, " %d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test6_d) {  // int n = 123, " %+d"
    int n = 123;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, " %+d", n);
    int b = sprintf(str2, " %+d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test7_d) {  // int n = 123, "%+d"
    int n = 123;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%+d", n);
    int b = sprintf(str2, "%+d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test8_d) {  // int n = 123, "-d%"
    int n = 123;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%-d", n);
    int b = sprintf(str2, "%-d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test9_d) {  // int n = 123, " %-d"
    int n = 123;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, " %-d", n);
    int b = sprintf(str2, " %-d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test10_d) {  // int n = 123, " %-10d"
    int n = 123;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%-10d", n);
    int b = sprintf(str2, "%-10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test11_d) {  // int n = 100, "%10d"
    int n = 100;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%10d", n);
    int b = sprintf(str2, "%10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test12_d) {  // int n = 100, "%+10d"
    int n = 100;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%+10d", n);
    int b = sprintf(str2, "%+10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test13_d) {  // int n = 100, " %+10d"
    int n = 100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%d", n);
    int b = sprintf(str2, "%d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test14_d) {  // int n = 100, ".20d"
    int n = 100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.20d", n);
    int b = sprintf(str2, "%.20d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test15_d) {  // int n = 100, "%+.20d"
    int n = -100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%++++++++++++++++.20d", n);
    int b = sprintf(str2, "%+.20d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test16_d) {  // int n = 100, "%+-.20d"
    int n = 100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%+----.20d", n);
    int b = sprintf(str2, "%+-.20d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test17_d) {  // int n = -0, "%+.10d"
    int n = -0;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%+.10d", n);
    int b = sprintf(str2, "%+.10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test18_d) {  // int n = -9990, "%10d"
    int n = -9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%10d", n);
    int b = sprintf(str2, "%10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test19_d) {  // int n = -9990, "+-.%10d"
    int n = -9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% +-.10d", n);
    int b = sprintf(str2, "%+-.10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test20_d) {  // int n = -9990, "% -10d"
    int n = -9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% -10d", n);
    int b = sprintf(str2, "% -10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test21_d) {  // int n = 9990, "% 10d"
    int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% 10d", n);
    int b = sprintf(str2, "% 10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test22_d) {  // int n = -9990, "% 10d"
    int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% 2d", n);
    int b = sprintf(str2, "% 2d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test23_d) {  // int n = 9990, "%-.09d"
    int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-.09d..", n);
    int b = sprintf(str2, "%-.09d..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test24_d) {  // int n = 9990, "%-.09d"
    int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.d..", n);
    int b = sprintf(str2, "%.d..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test25_d) {  // int n = 9990, "%-+.10ld.."
    long int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+.10ld..", n);
    int b = sprintf(str2, "%-+.10ld..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test26_d) {  // int n = -9990, "%-+.10hd.."
    short int n = -9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+.10hd..", n);
    int b = sprintf(str2, "%-+.10hd..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

// Тесты %s
START_TEST(s21_sprintf_test1_s) {  // "%s%c","BIBA_BOBA", 'q'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%s%c", "BIBA_BOBA", 'q');
    int b = sprintf(str2, "%s%c", "BIBA_BOBA", 'q');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test2_s) {  //  %s%c","BIBA_BOBA", 'q'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %s%c", "BIBA_BOBA", 'q');
    int b = sprintf(str2, " %s%c", "BIBA_BOBA", 'q');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test3_s) {  // " %s%c"," ", ' '
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %s%c", " ", ' ');
    int b = sprintf(str2, " %s%c", " ", ' ');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test4_s) {  // " %10s%10c"," ",'q'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %10s%-10lc", " ", 'q');
    int b = sprintf(str2, " %10s%-10lc", " ", 'q');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test5_s) {  // " %10s", "GO TO B   "
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %10s", "GO TO B   ");
    int b = sprintf(str2, " %10s", "GO TO B   ");

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test6_s) {  // " %10s","GO TO B  W ")
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %10s", "GO TO B  W ");
    int b = sprintf(str2, " %10s", "GO TO B  W ");

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test7_s) {  // "GO TO SHORT  ", 'W'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-10s%1c", "GO TO SHORT  ", 'W');
    int b = sprintf(str2, " %-10s%1c", "GO TO SHORT  ", 'W');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST


START_TEST(s21_sprintf_test8_s) {  // " %-10s%-1c","GO TO SHORT  ",'W'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-10s%-1c", "GO TO SHORT  ", 'W');
    int b = sprintf(str2, " %-10s%-1c", "GO TO SHORT  ", 'W');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test9_s) {  // " %-10s%-10c","GO TO SHORT  ",'W'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-10s%-10c", "GO TO SHORT  ", 'W');
    int b = sprintf(str2, " %-10s%-10c", "GO TO SHORT  ", 'W');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test10_s) {  // " %-s1%9c", "GO TO SHORT", 'W'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-s1%9c", "GO TO SHORT", 'W');
    int b = sprintf(str2, " %-s1%9c", "GO TO SHORT", 'W');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test11_s) {  // " %-.1s%9c", "GO TO S H O R T", 'W'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-.1s%1c", "GO TO S H O R T", 'W');
    int b = sprintf(str2, " %-.1s%1c", "GO TO S H O R T", 'W');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test12_s) {  // " %-.1s%1c%.1d%.1lu%.1hu.....wqwq", "GO TO S H O R T", 'W', i, l, us);
    short int i = 10;
    unsigned long l = 100;
    unsigned short us = 20;
    long int li = 100;
    short int si = 20;

    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);
    int b = sprintf(str2, " %-.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq", L"GO TO S H O R T", 'W', i, l, us, li, si);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test13_s) {  // " %-.1s%1c%.1d%.1lu%.1hu.....wqwq", "GO TO S H O R T", 'W', i, l, us);
    short int i = 10;
    unsigned long l = 100;
    unsigned short us = 20;
    long int li = 100;
    short int si = 20;

    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %%%-.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);
    int b = sprintf(str2, " %%%-.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test14_s) {  // " %-.1s%1c%.1d%.1lu%.1hu.....wqwq", "GO TO S H O R T", 'W', i, l, us);
    short int i = 10;
    unsigned long l = 100;
    unsigned short us = 20;

    long int li = 100;
    short int si = 20;

    char str1[120];
    char str2[120];

    int a = s21_sprintf(str1, " %%%-50ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);
    int b = sprintf(str2, " %%%-50ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test15_s) {  // " %-.1s%1c%.1d%.1lu%.1hu.....wqwq", "GO TO S H O R T", 'W', i, l, us);
    short int i = 10;
    unsigned long l = 100;
    unsigned short us = 20;
    long int li = 100;
    short int si = 20;

    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %%%15.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);
    int b = sprintf(str2, " %%%15.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

// Тесты %u
START_TEST(s21_sprintf_test1_u) {  // unsigned int n = 7777777; "%u"
    unsigned int n = 7777777;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%u", n);
    int b = sprintf(str2, "%u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test2_u) {  // unsigned int n = 000000; "%u"
    unsigned int n = 000000;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%u", n);
    int b = sprintf(str2, "%u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test3_u) {  // unsigned int n = -100; "%u"
    unsigned int n = -100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%u", n);
    int b = sprintf(str2, "%u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test4_u) {  // unsigned int n = 0, " %u"
    unsigned int n = 0;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, " %u", n);
    int b = sprintf(str2, " %u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test5_u) {  // unsigned int n = 7777777, " %u"
    unsigned int n = 7777777;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %u", n);
    int b = sprintf(str2, " %u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test6_u) {  // unsigned int n = 123, " %-u"
    unsigned int n = 777777;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-u", n);
    int b = sprintf(str2, " %-u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test7_u) {  // unsigned int n = -0, " %-u"
    unsigned int  n = -0;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-u", n);
    int b = sprintf(str2, " %-u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test8_u) {  // unsigned int n = 12322; "%-10u"
    unsigned int n = 12322;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%-10u", n);
    int b = sprintf(str2, "%-10u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test9_u) {  // unsigned int n = 10023;, " %-10u"
    unsigned int n = 10023;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%-10u", n);
    int b = sprintf(str2, "%-10u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test10_u) {  // unsigned int n = 100, "%10u"
    unsigned int n = 10000;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%10u", n);
    int b = sprintf(str2, "%10u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test11_u) {  // unsigned int n = 100;, "%.20u"
    unsigned int n = 100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.20u", n);
    int b = sprintf(str2, "%.20u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test12_u) {  // unsigned int n = 102220;, "%-.20d"
    unsigned int n = 102220;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-.20u", n);
    int b = sprintf(str2, "%-.20u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test13_u) {  // unsigned int n = 100; "%.20u"
    unsigned int n = 100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.20u", n);
    int b = sprintf(str2, "%.20u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test14_u) {  // unsigned int n = 9990;  "%.u.."
    unsigned int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.u..", n);
    int b = sprintf(str2, "%.u..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test15_u) {  // unsigned int n = 00001;  "%.01uVADIM   PAPA""
    unsigned int n = 00001;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.01uVADIM   PAPA", n);
    int b = sprintf(str2, "%.01uVADIM   PAPA", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test16_u) {  // unsigned int n = 00001;  "%.0uVADIM   PAPA""
    unsigned int n = 00001;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %.0uVADIM   PAPA", n);
    int b = sprintf(str2, " %.0uVADIM   PAPA", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test17_u) {  // unsigned int n = 00001;  "%%%.01uVADIM   PAPA"
    unsigned int n = 00001;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%%%.01uVADIM   PAPA", n);
    int b = sprintf(str2, "%%%.01uVADIM   PAPA", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test18_u) {  // int n = 9990, "%-+.10ld.."
    unsigned long int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-.01lu.!.", n);
    int b = sprintf(str2, "%-.01lu.!.", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test19_u) {  // int n = 9990, "%-+.10ld.."
    unsigned short int n = -9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-.0hui.!.", n);
    int b = sprintf(str2, "%-.0hui.!.", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

// Тесты  %f
START_TEST(s21_sprintf_test1_f) {  // float n = 777;  "%f"
    double n = 777;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%f", n);
    int b = sprintf(str2, "%f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test2_f) {  // float n = 000; "%f"
    double n = 000;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%f", n);
    int b = sprintf(str2, "%f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test3_f) {  // float n = -777; "%f"
    double n = -777;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%f", n);
    int b = sprintf(str2, "%f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test4_f) {  // float n = -0000; "%f"
    double n = -0000;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%f", n);
    int b = sprintf(str2, "%f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test5_f) {  // float n = -0000; "%+-f"
    double n = -0000;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%+-f", n);
    int b = sprintf(str2, "%+-f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test6_f) {  // float n = -022200; " % f"
    double n = -022200;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %f", n);
    int b = sprintf(str2, " %f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test7_f) {  // float n = -022200; "100--/0\n%.2f"
    double n = -022200;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "100--/0\n%.2f", n);
    int b = sprintf(str2, "100--/0\n%.2f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test8_f) {  // float n = 02.212200; "%-+.10lf.."
    double n = 02.212200;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+.10lf..", n);
    int b = sprintf(str2, "%-+.10lf..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test9_f) {  // float n = 02.212200;, "%-+.10lf.."
    double n = 02.212200;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+.10lf..", n);
    int b = sprintf(str2, "%-+.10lf..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test10_f) {  // float n = -99.290, "% -10f"
    double n = -99.290;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% -10f", n);
    int b = sprintf(str2, "% -10f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test11_f) {  // float n = -99.290, "% -10f"
    double n = 99.290;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% -10f", n);
    int b = sprintf(str2, "% -10f", n);

    ck_assert_int_eq(a, b);
    ck_assert_pstr_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test12_f) {  // int n = -9990, "%-+.10hd.."
    double n = -9.1990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+.10f..", n);
    int b = sprintf(str2, "%-+.10f..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test13_f) {  // int n = -9990, "%-+.10hd.."
    double n = -9.199000000000214324;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+20.11f..", n);
    int b = sprintf(str2, "%-+20.11f..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test14_f) {  // int n = -9990, "%-+.10hd.."
    double n = -9.199000000000214324;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%20.14f..", n);
    int b = sprintf(str2, "%20.14f..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test15_f) {  // int n = -9990, "%-+.10hd.."
    double n = -0.0;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%f", n);
    int b = sprintf(str2, "%f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

Suite *s21_Suite_sprintf() {
    Suite *s;

    s = suite_create("Sprintf Unit Test");

    TCase *tc1_s21_sprintf_test1_f = tcase_create("test1_s21_strsprintf_f");
    TCase *tc2_s21_sprintf_test2_f = tcase_create("test2_s21_strsprintf_f");
    TCase *tc3_s21_sprintf_test3_f = tcase_create("test3_s21_strsprintf_f");
    TCase *tc4_s21_sprintf_test4_f = tcase_create("test4_s21_strsprintf_f");
    TCase *tc5_s21_sprintf_test5_f = tcase_create("test5_s21_strsprintf_f");
    TCase *tc6_s21_sprintf_test6_f = tcase_create("test6_s21_strsprintf_f");
    TCase *tc7_s21_sprintf_test7_f = tcase_create("test7_s21_strsprintf_f");
    TCase *tc8_s21_sprintf_test8_f = tcase_create("test8_s21_strsprintf_f");
    TCase *tc9_s21_sprintf_test9_f = tcase_create("test9_s21_strsprintf_f");
    TCase *tc10_s21_sprintf_test10_f = tcase_create("test10_s21_strsprintf_f");
    TCase *tc11_s21_sprintf_test11_f = tcase_create("test11_s21_strsprintf_f");
    TCase *tc12_s21_sprintf_test12_f = tcase_create("test12_s21_strsprintf_f");
    TCase *tc13_s21_sprintf_test13_f = tcase_create("test13_s21_strsprintf_f");
    TCase *tc14_s21_sprintf_test14_f = tcase_create("test14_s21_strsprintf_f");
    TCase *tc15_s21_sprintf_test15_f = tcase_create("test15_s21_strsprintf_f");

    tcase_add_test(tc1_s21_sprintf_test1_f, s21_sprintf_test1_f);
    tcase_add_test(tc2_s21_sprintf_test2_f, s21_sprintf_test2_f);
    tcase_add_test(tc3_s21_sprintf_test3_f, s21_sprintf_test3_f);
    tcase_add_test(tc4_s21_sprintf_test4_f, s21_sprintf_test4_f);
    tcase_add_test(tc5_s21_sprintf_test5_f, s21_sprintf_test5_f);
    tcase_add_test(tc6_s21_sprintf_test6_f, s21_sprintf_test6_f);
    tcase_add_test(tc7_s21_sprintf_test7_f, s21_sprintf_test7_f);
    tcase_add_test(tc8_s21_sprintf_test8_f, s21_sprintf_test8_f);
    tcase_add_test(tc9_s21_sprintf_test9_f, s21_sprintf_test9_f);
    tcase_add_test(tc10_s21_sprintf_test10_f, s21_sprintf_test10_f);
    tcase_add_test(tc11_s21_sprintf_test11_f, s21_sprintf_test11_f);
    tcase_add_test(tc12_s21_sprintf_test12_f, s21_sprintf_test12_f);
    tcase_add_test(tc13_s21_sprintf_test13_f, s21_sprintf_test13_f);
    tcase_add_test(tc14_s21_sprintf_test14_f, s21_sprintf_test14_f);
    tcase_add_test(tc15_s21_sprintf_test15_f, s21_sprintf_test15_f);

    suite_add_tcase(s, tc1_s21_sprintf_test1_f);
    suite_add_tcase(s, tc2_s21_sprintf_test2_f);
    suite_add_tcase(s, tc3_s21_sprintf_test3_f);
    suite_add_tcase(s, tc4_s21_sprintf_test4_f);
    suite_add_tcase(s, tc5_s21_sprintf_test5_f);
    suite_add_tcase(s, tc6_s21_sprintf_test6_f);
    suite_add_tcase(s, tc7_s21_sprintf_test7_f);
    suite_add_tcase(s, tc8_s21_sprintf_test8_f);
    suite_add_tcase(s, tc9_s21_sprintf_test9_f);
    suite_add_tcase(s, tc10_s21_sprintf_test10_f);
    suite_add_tcase(s, tc11_s21_sprintf_test11_f);
    suite_add_tcase(s, tc12_s21_sprintf_test12_f);
    suite_add_tcase(s, tc13_s21_sprintf_test13_f);
    suite_add_tcase(s, tc14_s21_sprintf_test14_f);
    suite_add_tcase(s, tc15_s21_sprintf_test15_f);

    TCase *tc1_s21_sprintf_test1_d = tcase_create("test1_s21_strsprintf");
    TCase *tc2_s21_sprintf_test2_d = tcase_create("test2_s21_strsprintf");
    TCase *tc3_s21_sprintf_test3_d = tcase_create("test3_s21_strsprintf");
    TCase *tc4_s21_sprintf_test4_d = tcase_create("test4_s21_strsprintf");
    TCase *tc5_s21_sprintf_test5_d = tcase_create("test5_s21_strsprintf");
    TCase *tc6_s21_sprintf_test6_d = tcase_create("test6_s21_strsprintf");
    TCase *tc7_s21_sprintf_test7_d = tcase_create("test7_s21_strsprintf");
    TCase *tc8_s21_sprintf_test8_d = tcase_create("test8_s21_strsprintf");
    TCase *tc9_s21_sprintf_test9_d = tcase_create("test9_s21_strsprintf");
    TCase *tc10_s21_sprintf_test10_d = tcase_create("test10_s21_strsprintf");
    TCase *tc11_s21_sprintf_test11_d = tcase_create("test11_s21_strsprintf");
    TCase *tc12_s21_sprintf_test12_d = tcase_create("test12_s21_strsprintf");
    TCase *tc13_s21_sprintf_test13_d = tcase_create("test13_s21_strsprintf");
    TCase *tc14_s21_sprintf_test14_d = tcase_create("test14_s21_strsprintf");
    TCase *tc15_s21_sprintf_test15_d = tcase_create("test15_s21_strsprintf");
    TCase *tc16_s21_sprintf_test16_d = tcase_create("test16_s21_strsprintf");
    TCase *tc17_s21_sprintf_test17_d = tcase_create("test17_s21_strsprintf");
    TCase *tc18_s21_sprintf_test18_d = tcase_create("test18_s21_strsprintf");
    TCase *tc19_s21_sprintf_test19_d = tcase_create("test19_s21_strsprintf");
    TCase *tc20_s21_sprintf_test20_d = tcase_create("test20_s21_strsprintf");
    TCase *tc21_s21_sprintf_test21_d = tcase_create("test21_s21_strsprintf");
    TCase *tc22_s21_sprintf_test22_d = tcase_create("test22_s21_strsprintf");
    TCase *tc23_s21_sprintf_test23_d = tcase_create("test23_s21_strsprintf");
    TCase *tc24_s21_sprintf_test24_d = tcase_create("test24_s21_strsprintf");
    TCase *tc25_s21_sprintf_test25_d = tcase_create("test25_s21_strsprintf");
    TCase *tc26_s21_sprintf_test26_d = tcase_create("test26_s21_strsprintf");

    tcase_add_test(tc1_s21_sprintf_test1_d, s21_sprintf_test1_d);
    tcase_add_test(tc2_s21_sprintf_test2_d, s21_sprintf_test2_d);
    tcase_add_test(tc3_s21_sprintf_test3_d, s21_sprintf_test3_d);
    tcase_add_test(tc4_s21_sprintf_test4_d, s21_sprintf_test4_d);
    tcase_add_test(tc5_s21_sprintf_test5_d, s21_sprintf_test5_d);
    tcase_add_test(tc6_s21_sprintf_test6_d, s21_sprintf_test6_d);
    tcase_add_test(tc7_s21_sprintf_test7_d, s21_sprintf_test7_d);
    tcase_add_test(tc8_s21_sprintf_test8_d, s21_sprintf_test8_d);
    tcase_add_test(tc9_s21_sprintf_test9_d, s21_sprintf_test9_d);
    tcase_add_test(tc10_s21_sprintf_test10_d, s21_sprintf_test10_d);
    tcase_add_test(tc11_s21_sprintf_test11_d, s21_sprintf_test11_d);
    tcase_add_test(tc12_s21_sprintf_test12_d, s21_sprintf_test12_d);
    tcase_add_test(tc13_s21_sprintf_test13_d, s21_sprintf_test13_d);
    tcase_add_test(tc14_s21_sprintf_test14_d, s21_sprintf_test14_d);
    tcase_add_test(tc15_s21_sprintf_test15_d, s21_sprintf_test15_d);
    tcase_add_test(tc16_s21_sprintf_test16_d, s21_sprintf_test16_d);
    tcase_add_test(tc17_s21_sprintf_test17_d, s21_sprintf_test17_d);
    tcase_add_test(tc18_s21_sprintf_test18_d, s21_sprintf_test18_d);
    tcase_add_test(tc19_s21_sprintf_test19_d, s21_sprintf_test19_d);
    tcase_add_test(tc20_s21_sprintf_test20_d, s21_sprintf_test20_d);
    tcase_add_test(tc21_s21_sprintf_test21_d, s21_sprintf_test21_d);
    tcase_add_test(tc22_s21_sprintf_test22_d, s21_sprintf_test22_d);
    tcase_add_test(tc23_s21_sprintf_test23_d, s21_sprintf_test23_d);
    tcase_add_test(tc24_s21_sprintf_test24_d, s21_sprintf_test24_d);
    tcase_add_test(tc25_s21_sprintf_test25_d, s21_sprintf_test25_d);
    tcase_add_test(tc26_s21_sprintf_test26_d, s21_sprintf_test26_d);

    suite_add_tcase(s, tc1_s21_sprintf_test1_d);
    suite_add_tcase(s, tc2_s21_sprintf_test2_d);
    suite_add_tcase(s, tc3_s21_sprintf_test3_d);
    suite_add_tcase(s, tc4_s21_sprintf_test4_d);
    suite_add_tcase(s, tc5_s21_sprintf_test5_d);
    suite_add_tcase(s, tc6_s21_sprintf_test6_d);
    suite_add_tcase(s, tc7_s21_sprintf_test7_d);
    suite_add_tcase(s, tc8_s21_sprintf_test8_d);
    suite_add_tcase(s, tc9_s21_sprintf_test9_d);
    suite_add_tcase(s, tc10_s21_sprintf_test10_d);
    suite_add_tcase(s, tc11_s21_sprintf_test11_d);
    suite_add_tcase(s, tc12_s21_sprintf_test12_d);
    suite_add_tcase(s, tc13_s21_sprintf_test13_d);
    suite_add_tcase(s, tc14_s21_sprintf_test14_d);
    suite_add_tcase(s, tc15_s21_sprintf_test15_d);
    suite_add_tcase(s, tc16_s21_sprintf_test16_d);
    suite_add_tcase(s, tc17_s21_sprintf_test17_d);
    suite_add_tcase(s, tc18_s21_sprintf_test18_d);
    suite_add_tcase(s, tc19_s21_sprintf_test19_d);
    suite_add_tcase(s, tc20_s21_sprintf_test20_d);
    suite_add_tcase(s, tc21_s21_sprintf_test21_d);
    suite_add_tcase(s, tc22_s21_sprintf_test22_d);
    suite_add_tcase(s, tc23_s21_sprintf_test23_d);
    suite_add_tcase(s, tc24_s21_sprintf_test24_d);
    suite_add_tcase(s, tc25_s21_sprintf_test25_d);
    suite_add_tcase(s, tc26_s21_sprintf_test26_d);

    TCase *tc1_s21_sprintf_test1_s = tcase_create("test1_s21_strsprintf_s");
    TCase *tc2_s21_sprintf_test2_s = tcase_create("test2_s21_strsprintf_s");
    TCase *tc3_s21_sprintf_test3_s = tcase_create("test3_s21_strsprintf_s");
    TCase *tc4_s21_sprintf_test4_s = tcase_create("test4_s21_strsprintf_s");
    TCase *tc5_s21_sprintf_test5_s = tcase_create("test5_s21_strsprintf_s");
    TCase *tc6_s21_sprintf_test6_s = tcase_create("test6_s21_strsprintf_s");
    TCase *tc7_s21_sprintf_test7_s = tcase_create("test7_s21_strsprintf_s");
    TCase *tc8_s21_sprintf_test8_s = tcase_create("test8_s21_strsprintf_s");
    TCase *tc9_s21_sprintf_test9_s = tcase_create("test9_s21_strsprintf_s");
    TCase *tc10_s21_sprintf_test10_s = tcase_create("test10_s21_strsprintf_s");
    TCase *tc11_s21_sprintf_test11_s = tcase_create("test11_s21_strsprintf_s");
    TCase *tc12_s21_sprintf_test12_s = tcase_create("test12_s21_strsprintf_s");
    TCase *tc13_s21_sprintf_test13_s = tcase_create("test13_s21_strsprintf_s");
    TCase *tc14_s21_sprintf_test14_s = tcase_create("test14_s21_strsprintf_s");
    TCase *tc15_s21_sprintf_test15_s = tcase_create("test15_s21_strsprintf_s");

    tcase_add_test(tc1_s21_sprintf_test1_s, s21_sprintf_test1_s);
    tcase_add_test(tc2_s21_sprintf_test2_s, s21_sprintf_test2_s);
    tcase_add_test(tc3_s21_sprintf_test3_s, s21_sprintf_test3_s);
    tcase_add_test(tc4_s21_sprintf_test4_s, s21_sprintf_test4_s);
    tcase_add_test(tc5_s21_sprintf_test5_s, s21_sprintf_test5_s);
    tcase_add_test(tc6_s21_sprintf_test6_s, s21_sprintf_test6_s);
    tcase_add_test(tc7_s21_sprintf_test7_s, s21_sprintf_test7_s);
    tcase_add_test(tc8_s21_sprintf_test8_s, s21_sprintf_test8_s);
    tcase_add_test(tc9_s21_sprintf_test9_s, s21_sprintf_test9_s);
    tcase_add_test(tc10_s21_sprintf_test10_s, s21_sprintf_test10_s);
    tcase_add_test(tc11_s21_sprintf_test11_s, s21_sprintf_test11_s);
    tcase_add_test(tc12_s21_sprintf_test12_s, s21_sprintf_test12_s);
    tcase_add_test(tc13_s21_sprintf_test13_s, s21_sprintf_test13_s);
    tcase_add_test(tc14_s21_sprintf_test14_s, s21_sprintf_test14_s);
    tcase_add_test(tc15_s21_sprintf_test15_s, s21_sprintf_test15_s);

    suite_add_tcase(s, tc1_s21_sprintf_test1_s);
    suite_add_tcase(s, tc2_s21_sprintf_test2_s);
    suite_add_tcase(s, tc3_s21_sprintf_test3_s);
    suite_add_tcase(s, tc4_s21_sprintf_test4_s);
    suite_add_tcase(s, tc5_s21_sprintf_test5_s);
    suite_add_tcase(s, tc6_s21_sprintf_test6_s);
    suite_add_tcase(s, tc7_s21_sprintf_test7_s);
    suite_add_tcase(s, tc8_s21_sprintf_test8_s);
    suite_add_tcase(s, tc9_s21_sprintf_test9_s);
    suite_add_tcase(s, tc10_s21_sprintf_test10_s);
    suite_add_tcase(s, tc11_s21_sprintf_test11_s);
    suite_add_tcase(s, tc12_s21_sprintf_test12_s);
    suite_add_tcase(s, tc13_s21_sprintf_test13_s);
    suite_add_tcase(s, tc14_s21_sprintf_test14_s);
    suite_add_tcase(s, tc15_s21_sprintf_test15_s);

    TCase *tc1_s21_sprintf_test1_u = tcase_create("test1_s21_strsprintf_u");
    TCase *tc2_s21_sprintf_test2_u = tcase_create("test2_s21_strsprintf_u");
    TCase *tc3_s21_sprintf_test3_u = tcase_create("test3_s21_strsprintf_u");
    TCase *tc4_s21_sprintf_test4_u = tcase_create("test4_s21_strsprintf_u");
    TCase *tc5_s21_sprintf_test5_u = tcase_create("test5_s21_strsprintf_u");
    TCase *tc6_s21_sprintf_test6_u = tcase_create("test6_s21_strsprintf_u");
    TCase *tc7_s21_sprintf_test7_u = tcase_create("test7_s21_strsprintf_u");
    TCase *tc8_s21_sprintf_test8_u = tcase_create("test8_s21_strsprintf_u");
    TCase *tc9_s21_sprintf_test9_u = tcase_create("test9_s21_strsprintf_u");
    TCase *tc10_s21_sprintf_test10_u = tcase_create("test10_s21_strsprintf_u");
    TCase *tc11_s21_sprintf_test11_u = tcase_create("test11_s21_strsprintf_u");
    TCase *tc12_s21_sprintf_test12_u = tcase_create("test12_s21_strsprintf_u");
    TCase *tc13_s21_sprintf_test13_u = tcase_create("test13_s21_strsprintf_u");
    TCase *tc14_s21_sprintf_test14_u = tcase_create("test14_s21_strsprintf_u");
    TCase *tc15_s21_sprintf_test15_u = tcase_create("test14_s21_strsprintf_u");
    TCase *tc16_s21_sprintf_test16_u = tcase_create("test16_s21_strsprintf_u");
    TCase *tc17_s21_sprintf_test17_u = tcase_create("test17_s21_strsprintf_u");
    TCase *tc18_s21_sprintf_test18_u = tcase_create("test18_s21_strsprintf_u");
    TCase *tc19_s21_sprintf_test19_u = tcase_create("test19_s21_strsprintf_u");

    tcase_add_test(tc1_s21_sprintf_test1_u, s21_sprintf_test1_u);
    tcase_add_test(tc2_s21_sprintf_test2_u, s21_sprintf_test2_u);
    tcase_add_test(tc3_s21_sprintf_test3_u, s21_sprintf_test3_u);
    tcase_add_test(tc4_s21_sprintf_test4_u, s21_sprintf_test4_u);
    tcase_add_test(tc5_s21_sprintf_test5_u, s21_sprintf_test5_u);
    tcase_add_test(tc6_s21_sprintf_test6_u, s21_sprintf_test6_u);
    tcase_add_test(tc7_s21_sprintf_test7_u, s21_sprintf_test7_u);
    tcase_add_test(tc8_s21_sprintf_test8_u, s21_sprintf_test8_u);
    tcase_add_test(tc9_s21_sprintf_test9_u, s21_sprintf_test9_u);
    tcase_add_test(tc10_s21_sprintf_test10_u, s21_sprintf_test10_u);
    tcase_add_test(tc11_s21_sprintf_test11_u, s21_sprintf_test11_u);
    tcase_add_test(tc12_s21_sprintf_test12_u, s21_sprintf_test12_u);
    tcase_add_test(tc13_s21_sprintf_test13_u, s21_sprintf_test13_u);
    tcase_add_test(tc14_s21_sprintf_test14_u, s21_sprintf_test14_u);
    tcase_add_test(tc15_s21_sprintf_test15_u, s21_sprintf_test15_u);
    tcase_add_test(tc16_s21_sprintf_test16_u, s21_sprintf_test16_u);
    tcase_add_test(tc17_s21_sprintf_test17_u, s21_sprintf_test17_u);
    tcase_add_test(tc18_s21_sprintf_test18_u, s21_sprintf_test18_u);
    tcase_add_test(tc19_s21_sprintf_test19_u, s21_sprintf_test19_u);

    suite_add_tcase(s, tc1_s21_sprintf_test1_u);
    suite_add_tcase(s, tc2_s21_sprintf_test2_u);
    suite_add_tcase(s, tc3_s21_sprintf_test3_u);
    suite_add_tcase(s, tc4_s21_sprintf_test4_u);
    suite_add_tcase(s, tc5_s21_sprintf_test5_u);
    suite_add_tcase(s, tc6_s21_sprintf_test6_u);
    suite_add_tcase(s, tc7_s21_sprintf_test7_u);
    suite_add_tcase(s, tc8_s21_sprintf_test8_u);
    suite_add_tcase(s, tc9_s21_sprintf_test9_u);
    suite_add_tcase(s, tc10_s21_sprintf_test10_u);
    suite_add_tcase(s, tc11_s21_sprintf_test11_u);
    suite_add_tcase(s, tc12_s21_sprintf_test12_u);
    suite_add_tcase(s, tc13_s21_sprintf_test13_u);
    suite_add_tcase(s, tc14_s21_sprintf_test14_u);
    suite_add_tcase(s, tc15_s21_sprintf_test15_u);
    suite_add_tcase(s, tc16_s21_sprintf_test16_u);
    suite_add_tcase(s, tc17_s21_sprintf_test17_u);
    suite_add_tcase(s, tc18_s21_sprintf_test18_u);
    suite_add_tcase(s, tc19_s21_sprintf_test19_u);

    return s;
}
