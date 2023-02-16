#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
    s21_size_t common_len;
    common_len = s21_strlen(src) + s21_strlen(str) + 1;
    char* res = s21_NULL;
    if (src) {
        res = (char *)malloc(sizeof(char) * common_len);
        s21_size_t i = 0;
        while (i < start_index) {
            res[i] = *src;
            i++;
            src++;
        }
        while (*str) {
            res[i] = *str;
            i++;
            str++;
        }
        while (*src) {
            res[i] = *src;
            src++;
            i++;
            }
        res[i] = '\0';
    }
    return (void*)res;
}
