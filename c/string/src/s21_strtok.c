#include "s21_string.h"

// Разбивает строку str на ряд токенов, разделенных delim.
char* s21_strtok(char *str, const char *delim) {
    static char *buffer;
    int token_len;
    int deliter_len;
    if (str != s21_NULL) {
        str += s21_strspn(str, delim);
    } else {
        str = buffer;
        if (*str == 0)
            return s21_NULL;
    }
    token_len = s21_strcspn(str, delim);
    deliter_len = s21_strspn((str + token_len), delim);
    str[token_len] = '\0';
    buffer = str + deliter_len + token_len;
    return str;
}
