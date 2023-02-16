#include "s21_string.h"
#include <stdio.h>

void init(info *s) {
    s->flag1 = 0;
    s->flag2 = 0;
    s->flag3 = 0;
    s->width = -1;
    s->precision = -1;
    s->type = 0;
    s->length = 0;
}

// void print_s(info *s) {
//     printf("type = %c\nflag1 = %d\nflag2 = %d\nflag3 = %d\nwidth = %d\nprecision = %d\nlength = %c\n",
//             s->type, s->flag1, s->flag2, s->flag3, s->width, s->precision, s->length);
// }

void swap(char *x, char *y) {
    char buf = *x;
    *x = *y;
    *y = buf;
}

void reverse(char *str) {
    int len = s21_strlen(str);
    int start = 0, end = len - 1;
    while (start < end) {
        swap(str + start, str + end);
        start++;
        end--;
    }
}

char *check_plus(char *arr, info *s, int sign) {
    if (s->flag2 && sign) {
        *arr = '+';
        arr++;
    }
    return arr;
}

int num_len(long long int number) {
    int len = 0;
    if (!number) len++;
    while (number) {
        len++;
        number /= 10;
    }
    return len;
}

char *input_symbol(char *a, int count, int c, int *n) {
    while (count) {
        *a = c;
        a++;
        count--;
        *n += 1;
    }
    return a;
}

char *check_space(char *arr, info *s, int sign) {
    if (s->flag3 && sign && !s->flag2) {
        *arr = ' ';
        arr++;
    }
    return arr;
}

char *check_minus(long long int num, char *a, info *s, int sign) {
    int len = s->precision > num_len(num) ? s->precision : num_len(num);
    if (s->flag3 && sign) len++;
    int cd = 1;
    if (s->flag2 && !s->flag1) cd++;
    if (s->flag1 && s->width > len && s->width > s->precision) {
        int count;
        if (s->flag2)
            count = sign ? s->width - len - 1 : s->width - len - cd;
        else
            count = sign ? s->width - len : s->width - len - cd;
        while (count) {
            *a = ' ';
            a++;
            count--;
        }
    }
    return a;
}

char *check_width(long long int num, char *a, info *s, int sign) {
    int len = s->precision > num_len(num) ? s->precision : num_len(num);
    if (s->flag3 && sign) len++;
    int cd = 1;
    if (s->flag2 && !s->flag1 && sign) cd++;
    if (!s->flag1 && s->width > len && s->width > s->precision) {
        int count;
        if (s->flag2)
            count = sign ? s->width - len - 1 : s->width - len - cd;
        else
            count = sign ? s->width - len : s->width - len - cd;
        while (count) {
            *a = ' ';
            a++;
            count--;
        }
    }
    return a;
}

char *check_precision(long long int num, char *a, info *s) {
    int len = num_len(num);
    if (s->precision > len) {
        int count = s->precision - len;
        while (count) {
            *a = '0';
            a++;
            count--;
        }
    }
    return a;
}

char * itoch(long long int num, char *arr, info *s) {
    char *a = arr;
    int isPos = 1;
    long long int numcpy = num;
    if (num < 0) {
        isPos = 0;
        num *= -1;
    }
    a = check_minus(num, a, s, isPos);
    if (!num) {
        *a = '0';
        a++;
    }
    while (num) {
        int buf = num % 10;
        *a++ = buf + '0';
        num /= 10;
    }
    a = check_precision(numcpy, a, s);
    a = check_space(a, s, isPos);
    if (numcpy && !isPos) {
        *a = '-';
        a++;
    }
    a = check_plus(a, s, isPos);
    a = check_width(numcpy, a, s, isPos);
    return a;
}

char* utoch(unsigned long num, char *arr, info *s) {
    char *a = arr;
    unsigned numcpy = num;
    int isPos = 1;
    s->flag2 = 0;
    a = check_minus(num, a, s, isPos);
    if (!num) {
        *a = '0';
        a++;
    }
    while (num) {
        int buf = num % 10;
        *a++ = buf + '0';
        num /= 10;
    }
    a = check_precision(numcpy, a, s);
    a = check_width(numcpy, a, s, isPos);
    return a;
}

int istype(const char *c) {
    int res = 0;
    if (*c == 'c' || *c == 'd' || *c == 'i' ||
        *c == 'f' || *c == 's' || *c == 'u')
        res = 1;
    return res;
}

void ipart_to_str(char *str, double intpart, int glag) {
    char *a = str;
    if (intpart < 0) intpart = -intpart;
    unsigned long long int ipart = (unsigned long long)intpart;
    if (!ipart && !glag) {
        *str = '0';
        str++;
    }
    while (ipart) {
        int buf = ipart % 10;
        *str++ = buf + '0';
        ipart /= 10;
    }
    reverse(a);
}

int n_tu(int number, int count) {
    int result = 1;
    while (count-- > 0)
        result *= number;
    return result;
}

void dpart_to_str(char *str, double fractpart, info *s) {
    int flag = 1;
    char *a = str;
    int prec = 6;
    if (s->precision >= 0) prec = s->precision;
    if (fractpart < 0) {
        fractpart = -fractpart;
    }
    double num = fractpart;
    double fff = fractpart * 10 / 10 * 10;
    double fff2 = 1.0;
    if ((fff2 - fff) * n_tu(10, 10) > 1.0)    {
            *a++ = '0';
            prec--;
            fractpart *= 10.0;
            num = fractpart;
            fff = fractpart * 10 / 10 * 10;
    }
    while (prec-- > 0) {
        if ((fff2 - fff) * n_tu(10, 10) > 1.0) {
            *a++ = '0';
        }
        fractpart *= 10.0;
        fff = fractpart * 10 / 10 * 10;
        num = fractpart;
    }
    fractpart = round(num * 10);
    ipart_to_str(a, fractpart, flag);
}

void connect(char *dest, char *str1, char *str2, info *s, int sign) {
    int count1 = (s->precision >= 0) ? s->precision : 6;
    str2[count1] = '\0';
    int cd = ((s->flag2 && sign) || !sign) ? 2 : 1;
    s21_size_t sumlen = (s->precision != -2 && s->precision != 0) ?
        s21_strlen(str1) + s21_strlen(str2) + cd : s21_strlen(str1) + cd - 1;
    if (s->precision > 0 && s->precision < (int)s21_strlen(str2))
        sumlen -= (s->precision - s21_strlen(str1) - 1);
    int count2 = (s->width > (int)sumlen) ? s->width - sumlen : 0;
    if (!s->flag2 && s->flag3 && sign) {
        *dest = ' ';
        dest++;
    }
    if (!s->flag1) {
        while (count2) {
            *dest = ' ';
            dest++;
            count2--;
        }
    }
    if (s->flag2 && sign) {
        *dest = '+';
        dest++;
    }
    if (!sign) {
        *dest = '-';
        dest++;
    }
    while (*str1) {
        *dest = *str1;
        str1++;
        dest++;
    }
    if (s->precision != -2) {
        if (s->precision != 0)
            *dest++ = '.';
        while (*str2 && count1) {
            *dest = *str2;
            str2++;
            dest++;
            count1--;
        }
    }
    if (s->flag1) {
        int count3 = (s->width > (int)sumlen) ? s->width - sumlen : 0;
        if (s->flag3 && count3)
            count3--;
        while (count3) {
            *dest = ' ';
            dest++;
            count3--;
        }
    }
}

void ftostr(double num, char *arr, info *s) {
    char intp[256] = {'\0'};
    char dp[256] = {'\0'};
    int flag = 0;
    int isPos = 1;
    if (num < 0 || signbit(num) != 0) isPos = 0;
    char *a = arr;
    int intpart = num;
    double fractpart = num - intpart;
    ipart_to_str(intp, intpart, flag);
    dpart_to_str(dp, fractpart, s);
    connect(a, intp, dp, s, isPos);
}

int istype_l(const char *c) {
    int res = 0;
    if (*c == 'c' || *c == 'd' || *c == 'i' || *c == 's' || *c == 'u')
        res = 1;
    return res;
}

char* find_type(const char *format, info *s) {
    int res = 0;
    char *buf = (char *)format;
    if (*buf == '%') s->type = '%';
    while (*buf && *buf != '%') {
        if (istype(buf)) {
            s->type = *buf;
            res = 1;
        } else {
            s->type = 'n';
        }
        if (res) break;
        buf++;
    }
    return buf;
}

int is_number(const char *format) {
    int res = 0;
    if (*format >= '0' && *format <= '9')
        res = 1;
    return res;
}

int itos(const char *format, int *length) {
    *length = 0;
    const char* start = format;
    int result = 0;
    int pow = 1;
    while (is_number(format)) {
        *length += 1;
        format++;
    }
    format--;
    do {
        result += pow * (*format -'0');
        pow *= 10;
    } while (format-- != start);
    return result;
}

int ispoint(const char *format) {
    int res = 0;
    if (*format == '.')
        res = 1;
    return res;
}

int islength(const char *format) {
    int res = 0;
    if ((*format == 'l' || *format == 'h') && istype_l(format + 1)) {
        res = 1;
    }
    return res;
}

char* get_info(const char *format, info *s) {
    init(s);
    format++;
    char *stop = find_type(format, s);
    while (*format && *format != '%' && format != stop) {
        if (*format == ' ' && format < stop) {
            s->flag3 = 1;
            while (*(format + 1) == ' ')
                format++;
        }
        if (*format == '+') {
            s->flag2 = 1;
            while (*(format + 1) == '+')
                format++;
        }
        if (*format == '-') {
            s->flag1 = 1;
            while (*(format + 1) == '-')
                format++;
        }
        if (is_number(format)) {
            int len_w = 0;
            s->width = itos(format, &len_w);
            format += len_w;
        }
        if (ispoint(format) && *(format + 1)) {
            if (is_number(format + 1)) {
                int len_p = 0;
                s->precision = itos(format + 1, &len_p);
                format += len_p;
            } else {
                s->precision = -2;
            }
        }
        if (islength(format)) {
            s->length = *format;
        }
        format++;
    }
    return stop;
}

char* fill_a(char *str, char *arr, int *n) {
    while (*arr) {
        *str = *arr;
        arr++;
        str++;
        *n += 1;
    }
    return str;
}

int approve(info *s) {
    int res = 0;
    if ((s->precision == -1 && s->width == -1) || (s->precision > 0 && (!s->width || s->width == -1))
        || (s->width > 0 && s->precision == -1) || (s->width > 0 && s->precision > 0)
        || (s->precision == -1 && !s->width))
        res = 1;
    return res;
}

char* fill_str(char* str, char *string, int* n, info *s) {
    int len = s21_strlen(string);
    if (s->width != -1 && !s->flag1) {
        int lencpy1;
        lencpy1 = (s->precision > 0 && s->precision < len) ? len - s->precision : len;
        if (!s->precision || s->precision == -2) lencpy1 = 0;
        int count1 = s->width > lencpy1 ? s->width - lencpy1 : 0;
        if (s->width < s->precision && s->width > len) count1 = s->width - len;
        if (s->width > s->precision && s->precision > 0) count1 = s->width - s->precision;
        str = input_symbol(str, count1, ' ', n);
    }
    if (approve(s)) {
        int count = (s->precision >= 0 && s->precision < len) ? s->precision : len;
        while (*string && count) {
            *str = *string;
            str++;
            string++;
            *n += 1;
            count--;
        }
    }
    if (s->width != -1 && s->flag1) {
        int lencpy2;
        lencpy2 = ((s->precision > 0 && s->precision < len)) ? len - s->precision : len;
        if (!s->precision || s->precision == -2) lencpy2 = 0;
        int count3 = (s->width > lencpy2) ? s->width - lencpy2 : 0;
        if (s->width < s->precision && s->width > len) count3 = s->width - len;
        if (s->width > s->precision && s->precision > 0) count3 = s->width - s->precision;
        str = input_symbol(str, count3, ' ', n);
    }
    return str;
}

s21_size_t strlen_wch(wchar_t *str) {
    wchar_t *p = str;
    while (*p) {
        p++;
    }
    return (p - str);
}

char* fill_str_long(char* str, wchar_t *string, int* n, info *s) {
    int len = strlen_wch(string);
    if (s->width != -1 && !s->flag1) {
        int lencpy1;
        lencpy1 = (s->precision > 0 && s->precision < len) ? len - s->precision : len;
        if (!s->precision || s->precision == -2) lencpy1 = 0;
        int count1 = s->width > lencpy1 ? s->width - lencpy1 : 0;
        if (s->width < s->precision && s->width > len) count1 = s->width - len;
        if (s->width > s->precision && s->precision > 0) count1 = s->width - s->precision;
        str = input_symbol(str, count1, ' ', n);
    }
    if (approve(s)) {
        int count = (s->precision >= 0 && s->precision < len) ? s->precision : len;
        while (*string && count) {
            *str = (wchar_t)(*string);
            str++;
            string++;
            *n += 1;
            count--;
        }
    }
    if (s->width != -1 && s->flag1) {
        int lencpy2;
        lencpy2 = ((s->precision > 0 && s->precision < len)) ? len - s->precision : len;
        if (!s->precision || s->precision == -2) lencpy2 = 0;
        int count3 = (s->width > lencpy2) ? s->width - lencpy2 : 0;
        if (s->width < s->precision && s->width > len) count3 = s->width - len;
        if (s->width > s->precision && s->precision > 0) count3 = s->width - s->precision;
        str = input_symbol(str, count3, ' ', n);
    }
    return str;
}

char* fill_symb(char* str, int c, int* n, info *s) {
    if (s->width != -1 && !s->flag1) {
        int count1 = s->width ? s->width - 1 : s->width;
        str = input_symbol(str, count1, ' ', n);
    }
    *str = c;
    str++;
    *n += 1;
    if (s->width != -1 && s->flag1) {
        int count3 = s->width ? s->width - 1 : s->width;
        str = input_symbol(str, count3, ' ', n);
    }
    return str;
}

char* fill_symb_long(char* str, wint_t c, int* n, info *s) {
    if (s->width != -1 && !s->flag1) {
        int count1 = s->width ? s->width - 1 : s->width;
        str = input_symbol(str, count1, ' ', n);
    }
    *str = c;
    str++;
    *n += 1;
    if (s->width != -1 && s->flag1) {
        int count3 = s->width ? s->width - 1 : s->width;
        str = input_symbol(str, count3, ' ', n);
    }
    return str;
}

char* fill_arr(char *str, va_list *ap, int *a, info *inf) {
    switch (inf->type) {
        case 'c': {
            if (inf->length == 'l') {
                wint_t c = va_arg(*ap, wint_t);
                str = fill_symb_long(str, c, a, inf);
            } else {
                int c = va_arg(*ap, int);
                str = fill_symb(str, c, a, inf);
            }
            break;
        }
        case 'd':
        case 'i': {
            long int d = 0;
            int flag = 1;
            if (inf->length == 'l') {
                d = va_arg(*ap, long int);
            } else if (inf->length == 'h') {
                d = va_arg(*ap, int);
                d = (short int)d;
            } else {
                d = va_arg(*ap, int);
            }
            if (!d && (inf->precision == 0 || inf->precision == -2)) {
                if (!inf->flag2) flag = 0;
                if (inf->flag2) flag = -1;
            }
            if (flag == 1) {
                char arr_d[256] = {'\0'};
                itoch(d, arr_d, inf);
                reverse(arr_d);
                str = fill_a(str, arr_d, a);
            }
            if (flag == -1) {
                str = input_symbol(str, 1, '+', a);
            }
            break;
        }
        case 'f': {
            double f = va_arg(*ap, double);
            char arr_f[256] = {'\0'};
            ftostr(f, arr_f, inf);
            str = fill_a(str, arr_f, a);
            break;
        }
        case 's': {
            if (inf->length == 'l') {
                wchar_t *string = va_arg(*ap, wchar_t *);
                str = fill_str_long(str, string, a, inf);
            } else {
                char *string = va_arg(*ap, char *);
                str = fill_str(str, string, a, inf);
            }
            break;
        }
        case 'u': {
            unsigned long int u = 0;
            if (inf->length == 'l') {
                u = va_arg(*ap, unsigned long int);
            } else if (inf->length == 'h') {
                u = va_arg(*ap, int);
                u = (unsigned short int)u;
            } else {
                u = va_arg(*ap, unsigned);
            }
            char arr_u[256] = {'\0'};
            utoch(u, arr_u, inf);
            reverse(arr_u);
            str = fill_a(str, arr_u, a);
            break;
        }
        case '%': {
            *str++ = '%';
            *a += 1;
            break;
        }
    }
    return str;
}
