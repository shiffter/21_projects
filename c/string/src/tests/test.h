#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../s21_string.h"

Suite *s21_Suite_memchr();
Suite *s21_Suite_memcmp();
Suite *s21_Suite_memcpy();
Suite *s21_Suite_memmove();
Suite *s21_Suite_memset();
Suite *s21_Suite_sprintf();
Suite *s21_Suite_strcat();
Suite *s21_Suite_strchr();
Suite *s21_Suite_strcmp();
Suite *s21_Suite_strcpy();
Suite *s21_Suite_strcspn();
Suite *s21_Suite_strerror();
Suite *s21_Suite_strlen();
Suite *s21_Suite_strncat();
Suite *s21_Suite_strncmp();
Suite *s21_Suite_strncpy();
Suite *s21_Suite_strbprk();
Suite *s21_Suite_strrchr();
Suite *s21_Suite_strspn();
Suite *s21_Suite_strstr();
Suite *s21_Suite_strtok();
Suite *s21_Suite_to_uplow();
Suite *s21_Suite_insert();
Suite *s21_Suite_trim();

#endif  // SRC_TESTS_TEST_H_
