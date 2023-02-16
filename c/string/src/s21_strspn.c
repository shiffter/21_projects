#include "s21_string.h"

// Вычисляет длину начального сегмента str1, который полностью состоит из символов str2.
s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t l = 0;
    const char *buf2 = s21_NULL;
    int flag = 0;
    for (; *str1; str1++) {
        for (buf2 = str2; *buf2 && *buf2 != *str1; buf2++) {
        }
        if (!*buf2)
            flag = 1;
        if (flag == 0)
            l++;
    }
    return l;
}
