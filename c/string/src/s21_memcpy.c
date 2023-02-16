#include "s21_string.h"

// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    if (n) {
        unsigned char *d = (unsigned char *)dest;
        const unsigned char *s = (const unsigned char *)src;
        while (n--) {
            *d = *s;
            d++;
            s++;
        }
    }
    return dest;
}
