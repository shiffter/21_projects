#include "s21_string.h"

// Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    if (n) {
        char *d = dest;
        const char *s = src;
        int flag = 0;
        do {
            if ((*d++ = *s++) == 0) {
                while (--n != 0)
                    *d++ = 0;
                flag = 1;
            }
        } while (--n != 0 && flag == 0);
    }
    return dest;
}
