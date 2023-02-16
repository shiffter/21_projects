#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *s21_strchr(const char *str, int c) {
    char *s = (char *) str;
    while (*s && *s != c) {
            s++;
    }
    if (*s != c)
        s = s21_NULL;
    return s;
}
