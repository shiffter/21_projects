#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#include <limits.h>

#define s21_NULL ((void *)0)

typedef long unsigned s21_size_t;

void *s21_memset(void *str, int c, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);
char *s21_strerror(int errnum);
char *s21_strchr(const char *str, int c);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strpbrk(const char *str1, const char *str2);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcat(char *dest, const char *src);
void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
int s21_sprintf(char *str, const char *format, ...);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

typedef struct info {
    char type;  // 'c', 'd', 'i', 'f', 's', 'u', '%'
    int flag1;  // for '-'
    int flag2;  // for '+'
    int flag3;  // for ' '
    int width;  // number
    int precision;  // number
    char length;  // 'l', 'h'
} info;

char* fill_arr(char *str, va_list *ap, int *a, info *inf);
char* fill_symb_long(char* str, wint_t c, int* n, info *s);
char* fill_symb(char* str, int c, int* n, info *s);
char* fill_str_long(char* str, wchar_t *string, int* n, info *s);
s21_size_t strlen_wch(wchar_t *str);
char* fill_str(char* str, char *string, int* n, info *s);
int approve(info *s);
char* fill_a(char *str, char *arr, int *n);
char* get_info(const char *format, info *s);
int islength(const char *format);
int ispoint(const char *format);
int itos(const char *format, int *length);
int is_number(const char *format);
char* find_type(const char *format, info *s);
int istype_l(const char *c);
void ftostr(double num, char *arr, info *s);
void connect(char *dest, char *str1, char *str2, info *s, int sign);
void dpart_to_str(char *str, double fractpart, info *s);
void ipart_to_str(char *str, double intpart, int glag);
int istype(const char *c);
char* utoch(unsigned long num, char *arr, info *s);
char* itoch(long long int num, char *arr, info *s);
char *check_precision(long long int num, char *a, info *s);
char *check_width(long long int num, char *a, info *s, int sign);
char *check_minus(long long int num, char *a, info *s, int sign);
char *check_space(char *arr, info *s, int sign);
char *input_symbol(char *a, int count, int c, int *n);
int num_len(long long int number);
char *check_plus(char *arr, info *s, int sign);
void reverse(char *str);
void swap(char *x, char *y);
void init(info *s);
int n_tu(int number, int count);
// void print_s(info *s);

#endif  // SRC_S21_STRING_H_
