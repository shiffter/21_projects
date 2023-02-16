#include "s21_string.h"

// Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t counter = 0;
    int flag = 0;
    for (; *str1 && flag == 0; str1++) {
        const char *tmp = str2;
        for (; *tmp && *str1 != *tmp; tmp++) {
            }
        if (*tmp)
            flag = 1;
        if (flag == 0)
            counter++;
        }
    return counter;
}
