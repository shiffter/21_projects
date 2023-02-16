#include "s21_string.h"

// Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.|
char *s21_strpbrk(const char *str1, const char *str2) {
    char* res = s21_NULL;
    int flag = 0;
    while (*str1 && flag == 0) {
        const char *a = str2;
        while (*a != *str1 && *a)
            a++;
        if (*a) {
            res = (char*)str1;
            flag = 1;
        } else {
            ++str1;
        }
    }
    return res;
}
