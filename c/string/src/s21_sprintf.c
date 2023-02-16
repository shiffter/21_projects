#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
    int a = 0;
    info info;
    va_list ap;
    va_start(ap, format);
    char *str_buf = str;
    char *next = s21_NULL;
    while (*format) {
        if (*format != '%') {
            *str_buf = *format;
            str_buf++;
            a++;
            format++;
        } else {
            next = get_info(format, &info);
            str_buf = fill_arr(str_buf, &ap, &a, &info);
            format = next + 1;
        }
    }
    *str_buf = 0;
    va_end(ap);
    return a;
}
