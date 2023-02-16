#include "s21_string.h"

// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *buf = (unsigned char *)str;
    // старшие 24 бита усекаются и сохраняются только младшие 8 бит
    const unsigned char x = c;
    while (n--) {
        *buf = x;
        buf++;
    }
    return str;
}
