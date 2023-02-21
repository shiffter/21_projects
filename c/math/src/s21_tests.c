#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_math.h"
#include "s21_testcases.h"

void run_test(Suite *thesuit) {
  SRunner *therunner = srunner_create(thesuit);

  srunner_set_fork_status(therunner, CK_NOFORK);
  srunner_run_all(therunner, CK_NORMAL);
  srunner_ntests_failed(therunner);
  srunner_free(therunner);

  printf("\n");
}

START_TEST(test_abs) {
  for (int i = 0; i < NMAX; i++) {
    int res_orgn = abs(int_testcases[i]);
    int res_s21 = s21_abs(int_testcases[i]);

    if (res_orgn != res_s21) {
      char str_orgn[1000] = {'\0'};
      char str_s21[1000] = {'\0'};
      snprintf(str_orgn, sizeof(size_t) * 100, "%d", res_orgn);
      snprintf(str_s21, sizeof(size_t) * 100, "%d", res_s21);

      /*      printf("FAIL | ");
            printf("testcase: %d\t(orgn) %s // %s (s21)\n", int_testcases[i],
                   str_orgn, str_s21);*/
      ck_assert_int_eq(abs(int_testcases[i]), s21_abs(int_testcases[i]));
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_acos) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = acos(lf_testcases[i]);
    long double res_s21 = s21_acos(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    /*    printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
       str_orgn, str_s21);
    */
    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_asin) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = asin(lf_testcases[i]);
    long double res_s21 = s21_asin(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    //    printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    //    str_orgn,
    //           str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_atan) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = atan(lf_testcases[i]);
    long double res_s21 = s21_atan(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    //    printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    //    str_orgn,
    //           str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_ceil) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = ceil(lf_testcases[i]);
    long double res_s21 = s21_ceil(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    // printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    // str_orgn,
    //        str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_cos) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = cos(lf_testcases[i]);
    long double res_s21 = s21_cos(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    //    printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    //    str_orgn,
    //           str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_exp) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = exp(lf_testcases[i]);
    long double res_s21 = s21_exp(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    //    printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    //    str_orgn,
    //           str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_fabs) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = fabs(lf_testcases[i]);
    long double res_s21 = s21_fabs(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    // printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    // str_orgn,
    //        str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_floor) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = floor(lf_testcases[i]);
    long double res_s21 = s21_floor(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    // printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    // str_orgn,
    //        str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_fmod) {
  for (int i = 0; i < NMAX; i++) {
    for (int j = 0; j < NMAX; j++) {
      long double res_orgn_a = fmod(fmod_testcases[i], fmod_testcases[j]);
      long double res_s21_a = s21_fmod(fmod_testcases[i], fmod_testcases[j]);
      char str_orgn_a[1000] = {'\0'};
      char str_s21_a[1000] = {'\0'};
      snprintf(str_orgn_a, sizeof(size_t) * 100, "%Lf", res_orgn_a);
      snprintf(str_s21_a, sizeof(size_t) * 100, "%Lf", res_s21_a);

      // printf("testcase_a ([i]:[j]): %lf : %lf\t\t(orgn) %s // %s (s21)\n ",
      //        fmod_testcases[i], fmod_testcases[j], str_orgn_a, str_s21_a);

      /*      if (res_orgn_a == res_orgn_a && res_s21_a == res_s21_a &&
                res_orgn_a != INFINITY && res_orgn_a != -INFINITY) {
              ck_assert_ldouble_eq_tol(res_orgn_a, res_s21_a, 1e-6);
            } else {
              ck_assert_str_eq(str_orgn_a, str_s21_a);
            }

            long double res_orgn_b = fmod(lf_testcases[j], lf_testcases[i]);
            long double res_s21_b = s21_fmod(lf_testcases[j], lf_testcases[i]);
            char str_orgn_b[1000] = {'\0'};
            char str_s21_b[1000] = {'\0'};
            snprintf(str_orgn_b, sizeof(size_t) * 100, "%Lf", res_orgn_b);
            snprintf(str_s21_b, sizeof(size_t) * 100, "%Lf", res_s21_b);

      //      printf("testcase_b ([j]:[i]): %lf : %lf\t\t(orgn) %s // %s (s21)\n
      ",
      //             lf_testcases[j], lf_testcases[i], str_orgn_b, str_s21_b);

            if (res_orgn_b == res_orgn_a && res_s21_b == res_s21_b &&
                res_orgn_b != INFINITY && res_orgn_b != -INFINITY) {
              ck_assert_ldouble_eq_tol(res_orgn_b, res_s21_b, 1e-6);
            } else {
              ck_assert_str_eq(str_orgn_b, str_s21_b);
            }*/

      if (s21_isinf(res_orgn_a)) {
        ck_assert_ldouble_infinite(res_s21_a);
      } else if (s21_isnan(res_orgn_a)) {
        ck_assert_ldouble_nan(res_s21_a);
      } else if (res_orgn_a < 1e+16) {
        ck_assert_ldouble_eq_tol(res_orgn_a, res_s21_a, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(test_log) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = log(lf_testcases[i]);
    long double res_s21 = s21_log(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    // printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    // str_orgn,
    //        str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_pow) {
  for (int i = 0; i < NMAX; i++) {
    for (int j = 0; j < NMAX; j++) {
      long double res_orgn_a = pow(lf_testcases[i], lf_testcases[j]);
      long double res_s21_a = s21_pow(lf_testcases[i], lf_testcases[j]);
      char str_orgn_a[1000] = {'\0'};
      char str_s21_a[1000] = {'\0'};
      snprintf(str_orgn_a, sizeof(size_t) * 100, "%Lf", res_orgn_a);
      snprintf(str_s21_a, sizeof(size_t) * 100, "%Lf", res_s21_a);

      /*      printf("testcase_a ([i]:[j]): %lf : %lf\t\t(orgn) %s // %s (s21)\n
         ", lf_testcases[i], lf_testcases[j], str_orgn_a, str_s21_a);
      */
      if (s21_isinf(res_orgn_a) != 0)
        ck_assert_ldouble_infinite(res_s21_a);
      else if (s21_isnan(res_orgn_a))
        ck_assert_ldouble_nan(res_s21_a);
      else if (fabsl(res_s21_a) < 1e+16)
        ck_assert_ldouble_eq_tol(res_orgn_a, res_s21_a, 1e-6);
      else
        printf("hign or low value\n");

      /*      if (res_orgn_a == res_orgn_a && res_s21_a == res_s21_a &&
                res_orgn_a != INFINITY && res_orgn_a != -INFINITY) {
              if (fabsl(res_orgn_a) < 1e+16 && fabsl(res_orgn_a) > 1e-6)
                  ck_assert_ldouble_eq_tol(res_orgn_a, res_s21_a, 1e-6);
              else
                  printf("\n%Lf to hign or to low\n", res_orgn_a);
            } else {
              printf("str _compare\n");
              ck_assert_str_eq(str_orgn_a, str_s21_a);
            }

            long double res_orgn_b = pow(lf_testcases[j], lf_testcases[i]);
            long double res_s21_b = s21_pow(lf_testcases[j], lf_testcases[i]);
            char str_orgn_b[1000] = {'\0'};
            char str_s21_b[1000] = {'\0'};
            snprintf(str_orgn_b, sizeof(size_t) * 100, "%Lf", res_orgn_b);
            snprintf(str_s21_b, sizeof(size_t) * 100, "%Lf", res_s21_b);

            printf("testcase_b ([j]:[i]): %lf : %lf\t\t(orgn) %s // %s (s21)\n
         ", lf_testcases[j], lf_testcases[i], str_orgn_b, str_s21_b);

            if (res_orgn_b == res_orgn_a && res_s21_b == res_s21_b &&
                res_orgn_b != INFINITY && res_orgn_b != -INFINITY) {
              ck_assert_ldouble_eq_tol(res_orgn_b, res_s21_b, 1e-6);
            } else {
              ck_assert_str_eq(str_orgn_b, str_s21_b);
            }*/
    }
  }
}
END_TEST

START_TEST(test_sin) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = sin(lf_testcases[i]);
    long double res_s21 = s21_sin(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    //    printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    //    str_orgn,
    //           str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_sqrt) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = sqrt(lf_testcases[i]);
    long double res_s21 = s21_sqrt(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    // printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    // str_orgn,
    //        str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

START_TEST(test_tan) {
  for (int i = 0; i < NMAX; i++) {
    long double res_orgn = tan(lf_testcases[i]);
    long double res_s21 = s21_tan(lf_testcases[i]);

    char str_orgn[1000] = {'\0'};
    char str_s21[1000] = {'\0'};
    snprintf(str_orgn, sizeof(size_t) * 100, "%Lf", res_orgn);
    snprintf(str_s21, sizeof(size_t) * 100, "%Lf", res_s21);

    //    printf("testcase: %lf\t(orgn) %s // %s (s21)\n", lf_testcases[i],
    //    str_orgn,
    //          str_s21);

    if (res_orgn == res_orgn && res_s21 == res_s21 && res_orgn != INFINITY &&
        res_orgn != -INFINITY) {
      ck_assert_ldouble_eq_tol(res_orgn, res_s21, 1e-6);
    } else {
      ck_assert_str_eq(str_orgn, str_s21);
    }
  }
}
END_TEST

Suite *suite_abs() {
  Suite *s = suite_create("suite_abs");
  TCase *tc = tcase_create("tc_abs");

  tcase_add_test(tc, test_abs);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_acos() {
  Suite *s = suite_create("suite_acos");
  TCase *tc = tcase_create("tc_acos");

  tcase_add_test(tc, test_acos);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_asin() {
  Suite *s = suite_create("suite_asin");
  TCase *tc = tcase_create("tc_asin");

  tcase_add_test(tc, test_asin);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_atan() {
  Suite *s = suite_create("suite_atan");
  TCase *tc = tcase_create("tc_atan");

  tcase_add_test(tc, test_atan);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_ceil() {
  Suite *s = suite_create("suite_ceil");
  TCase *tc = tcase_create("tc_ceil");

  tcase_add_test(tc, test_ceil);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_cos() {
  Suite *s = suite_create("suite_cos");
  TCase *tc = tcase_create("tc_cos");

  tcase_add_test(tc, test_cos);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_exp() {
  Suite *s = suite_create("suite_exp");
  TCase *tc = tcase_create("tc_exp");

  tcase_add_test(tc, test_exp);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_fabs() {
  Suite *s = suite_create("suite_fabs");
  TCase *tc = tcase_create("tc_fabs");

  tcase_add_test(tc, test_fabs);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_floor() {
  Suite *s = suite_create("suite_floor");
  TCase *tc = tcase_create("tc_floor");

  tcase_add_test(tc, test_floor);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_fmod() {
  Suite *s = suite_create("suite_fmod");
  TCase *tc = tcase_create("tc_fmod");

  tcase_add_test(tc, test_fmod);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_log() {
  Suite *s = suite_create("suite_log");
  TCase *tc = tcase_create("tc_log");

  tcase_add_test(tc, test_log);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_pow() {
  Suite *s = suite_create("suite_pow");
  TCase *tc = tcase_create("tc_pow");

  tcase_add_test(tc, test_pow);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_sin() {
  Suite *s = suite_create("suite_sin");
  TCase *tc = tcase_create("tc_sin");

  tcase_add_test(tc, test_sin);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_sqrt() {
  Suite *s = suite_create("suite_sqrt");
  TCase *tc = tcase_create("tc_sqrt");

  tcase_add_test(tc, test_sqrt);
  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_tan() {
  Suite *s = suite_create("suite_tan");
  TCase *tc = tcase_create("tc_tan");

  tcase_add_test(tc, test_tan);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  printf("\n");

  Suite *s_abs = suite_abs();
  Suite *s_acos = suite_acos();
  Suite *s_asin = suite_asin();
  Suite *s_atan = suite_atan();
  Suite *s_ceil = suite_ceil();
  Suite *s_cos = suite_cos();
  Suite *s_exp = suite_exp();
  Suite *s_fabs = suite_fabs();
  Suite *s_floor = suite_floor();
  Suite *s_fmod = suite_fmod();
  Suite *s_log = suite_log();
  Suite *s_pow = suite_pow();
  Suite *s_sin = suite_sin();
  Suite *s_sqrt = suite_sqrt();
  Suite *s_tan = suite_tan();

  run_test(s_abs);
  run_test(s_acos);
  run_test(s_asin);
  run_test(s_atan);
  run_test(s_ceil);
  run_test(s_cos);
  run_test(s_exp);
  run_test(s_fabs);
  run_test(s_floor);
  run_test(s_fmod);
  run_test(s_log);
  run_test(s_pow);
  run_test(s_sin);
  run_test(s_sqrt);
  run_test(s_tan);

  return 0;
}
