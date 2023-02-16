#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest.
char *s21_strcat(char *dest, const char *src) {
    if (*src) {
        char *d = dest;
        while (*d) d++;
        while (*src) {
            *d = *src;
            d++;
            src++;
        }
    *d = 0;
    }
    return dest;
}
