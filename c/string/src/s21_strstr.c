#include "s21_string.h"

/*  Находит первое вхождение всей строки needle (не включая завершающий нулевой символ)
    , которая появляется в строке haystack.
*/
char *s21_strstr(const char *haystack, const char *needle) {
    if (!*needle) return (char *)haystack;
    const char* res = s21_NULL;
    int len = s21_strlen(needle);
    while (*haystack) {
        if (*haystack == *needle) {
            const char* buff = haystack;
            int counter = 0;
            while (*buff == *needle && *needle) {
                needle++;
                buff++;
                counter++;
            }
            if (counter == len) {
                res = (char*) haystack;
            } else {
                continue;
            }
        }
        haystack++;
    }
    return (char *)res;
}
