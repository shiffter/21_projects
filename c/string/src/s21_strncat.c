#include "s21_string.h"

/*  Добавляет строку, на которую указывает src, в конец строки, 
    на которую указывает dest, длиной до n символов.
*/
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    if (n) {
        char *buf1 = dest;
        const char *buf2 = src;
        while (*buf1)
            buf1++;
        while (*buf2 && n--) {
            *buf1 = *buf2;
            buf1++;
            buf2++;
        }
        *buf1 = 0;
    }
    return dest;
}
