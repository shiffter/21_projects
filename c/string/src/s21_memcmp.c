#include "s21_string.h"

// Сравнивает первые n байтов str1 и str2. |
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int res = 0;
    if (n) {
        const unsigned char *pstr1 = (const unsigned char *)str1;
        const unsigned char *pstr2 = (const unsigned char*)str2;
        while (n--) {
            if (*pstr1 != *pstr2)
                res = (*pstr1 - *pstr2);
            pstr1++;
            pstr2++;
        }
    }
    return res;
}
