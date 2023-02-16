#include "s21_string.h"

/*  Выполняет поиск первого вхождения символа c (беззнаковый тип)
    в первых n байтах строки, на которую указывает аргумент str.
*/
void *s21_memchr(const void *str, int c, s21_size_t n) {
    void *res = s21_NULL;
    if (n) {
        const unsigned char *buf = str;
        unsigned char x = (unsigned char)c;
        do {
            if (*buf == x)
                res = (void*)buf;
            buf++;
        } while (--n && !res);
    }
    return res;
}
