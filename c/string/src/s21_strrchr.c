#include "s21_string.h"

/*  Выполняет поиск последнего вхождения символа c (беззнаковый тип) 
    в строке, на которую указывает аргумент str.
*/
char *s21_strrchr(const char *str, int c) {
    const char *buf = str;
    while (*buf)
        buf++;
    while (buf != str && *buf != c) {
        buf--;
    }
    if (*buf != c)
        buf = s21_NULL;
    return (char *)buf;
}
