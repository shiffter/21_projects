#include "s21_string.h"
#include <stdlib.h>

void *s21_to_lower(const char *str) {
    char *res = s21_NULL;
    if (str) {
        s21_size_t len = s21_strlen(str) + 1;
        res = malloc(len);
        if (res) {
            s21_size_t i = 0;
            while (i < len - 1) {
                if (*str >= 'A' && *str <= 'Z') {
                    res[i++] = (*str++ + 'a' - 'A');
                } else {
                    res[i++] = *str++;
                }
            }
            res[i] = '\0';
        }
    }
    return res;
}
