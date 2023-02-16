#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
    char *buffer;
    char *res = s21_NULL;
    char *null_str = "";
    char del[] = " \n\t\v\r\f";
    if (trim_chars == s21_NULL || *trim_chars == *null_str) {
        trim_chars = del;
    }
    if (src) {
        s21_size_t begin_trim_len;
        begin_trim_len = s21_strspn(src, trim_chars);
        src += begin_trim_len;
        s21_size_t str_len = s21_strlen(src);
        res = (char*)malloc(sizeof(char) * str_len + 1);
        buffer = (char*)res;
        while (*src) {
            *res = *src;
            res++;
            src++;
        }
        *res = '\0';
        res--;
        int ch = *res;
        while (s21_strchr(trim_chars, ch) && str_len > 0) {
            *res = '\0';
            res--;
            ch = (int)*res;
            str_len--;
        }
        res = buffer;
    }
    return (void*)res;
}
