#include "s21_string.h"

// Сравнивает не более первых n байтов str1 и str2. -1 if str1 < str2; 1 if str1 > str2; 0 is equal
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    char *s1 = (char *)str1;
    char *s2 = (char *)str2;
    int compare = 0;
    if (n) {
        while (*s1 && *s2 && --n && (*s1 - *s2) == 0) {
            s1++;
            s2++;
        }
        compare = *(unsigned char *)s1 - *(unsigned char * )s2;
    }
    return compare;
}
