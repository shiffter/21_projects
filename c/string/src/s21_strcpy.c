#include "s21_string.h"

// Копирует строку, на которую указывает src, в dest.
char *s21_strcpy(char *dest, const char *src) {
    char *d = dest;
    while (*src) {
        *d = *src;
        d++;
        src++;
    }
    *d = 0;
    return dest;
}
