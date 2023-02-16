#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    unsigned char *s1 = (unsigned char *)dest;
    const unsigned char *s2 = (const unsigned char *)src;
    void *result = dest;
    if (s1 == s2 || n == 0) {
        result = dest;
    } else if (s1 > s2 && s1 - s2 < (int)n) {
        int i = n - 1;
        while (i >= 0) {
            s1[i] = s2[i];
            i--;
        }
        result = dest;
    } else if (s2 > s1 && s2 - s1 > (int)n) {
        s21_size_t i = 0;
        while (i < n) {
            s1[i] = s2[i];
            i++;
        }
        result = dest;
    }
    s21_memcpy(result, src, n);
    return result;
}
