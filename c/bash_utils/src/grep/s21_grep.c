#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 10000
#define SBUFF 1000

struct flags {
    int e, i, v, c, l, n, h, s, f, o, files, empty;
};

void get_flags(int argc, char** argv, char* pattern, struct flags* flag);
void goin_file(int argc, char** argv, char* pattern, struct flags flag);
void search_str(char** argv, FILE* fp, char* pattern, int file_index,
               struct flags flag);
int search_files(int argc, char** argv, struct flags flag);
void get_patt_e(int* counter, char* pattern, char* optarg,
                   struct flags* flag);
void get_patt_f(int* counter, char* pattern, char* optarg,
                   struct flags* flag);

int main(int argc, char** argv) {
    struct flags flag = {0};
    char pattern[SBUFF] = {0};

    if (argc > 1) {
        get_flags(argc, argv, pattern, &flag);
        goin_file(argc, argv, pattern, flag);
    }
    return 0;
}

void get_flags(int argc, char** argv, char* pattern, struct flags* flag) {
    int counter = 0, result = 0, files_in;

    while ((result = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) !=
           -1) {
        switch (result) {
            case 'e':
                get_patt_e(&counter, pattern, optarg, flag);
                flag->e = 1;
                break;
            case 'i':
                flag->i = 1;
                break;
            case 'v':
                flag->v = 1;
                break;
            case 'c':
                flag->c = 1;
                break;
            case 'l':
                flag->l = 1;
                break;
            case 'n':
                flag->n = 1;
                break;
            case 'h':
                flag->h = 1;
                break;
            case 's':
                flag->s = 1;
                break;
            case 'f':
                get_patt_f(&counter, pattern, optarg, flag);
                flag->f = 1;
                break;
            case 'o':
                flag->o = 1;
                break;
        }
    }
    files_in = search_files(argc, argv, *flag);
    if ((files_in < argc - 1) && !(flag->h)) flag->files = 1;
    if (!(flag->e) && !(flag->f)) {
        if (argv[files_in - 1][0] != '\0')
            strcat(pattern, argv[files_in - 1]);
        else
            strcat(pattern, ".");
    }
    if ((flag->empty)) flag->o = 0;
}

void goin_file(int argc, char** argv, char* pattern, struct flags flag) {
    FILE* fp = NULL;
    for (int i = search_files(argc, argv, flag); i < argc; ++i) {
        if ((fp = fopen(argv[i], "r")) != NULL) {
            fseek(fp, 0, SEEK_SET);
            search_str(argv, fp, pattern, i, flag);
            fclose(fp);
        } else if (!(flag.s)) {
            printf("s21_grep: %s: No such file or directory\n", argv[i]);
        }
    }
}

void search_str(char** argv, FILE* fp, char* pattern, int file_index,
               struct flags flag) {
    char line[BUFF] = {0};
    int status, number_lines = 0, matching_lines = 0;
    int cflags = REG_EXTENDED;
    regex_t compiled;
    regmatch_t pm[1];

    if (flag.i) cflags |= REG_ICASE;
    regcomp(&compiled, pattern, cflags);
    while (fgets(line, BUFF, fp) != NULL) {
        ++number_lines;
        if (flag.o && !flag.v) {
            status = regexec(&compiled, line, 1, pm, 0);
            if (status == REG_NOMATCH) continue;
            ++matching_lines;
            char* ptr = line;
            if (flag.files && !flag.c && !flag.l && !flag.h)
                printf("%s:", argv[file_index]);
            if (flag.n && !flag.c && !flag.l) printf("%d:", number_lines);
            while (status != REG_NOMATCH) {
                if (pm->rm_so == pm->rm_eo) break;
                if (!flag.c && !flag.l) {
                    printf("%.*s\n", (int)(pm->rm_eo - pm->rm_so),
                           &ptr[pm->rm_so]);
                }
                ptr = &ptr[pm->rm_eo];
                status = regexec(&compiled, ptr, 1, pm, REG_NOTBOL);
            }
        } else {
            status = regexec(&compiled, line, 1, pm, 0);
            if (flag.v) {
                if (status != REG_NOMATCH) continue;
            } else {
                if (status == REG_NOMATCH) continue;
            }
            ++matching_lines;
            if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = 0;
            if (!flag.c && !flag.l) {
                if (flag.files) printf("%s:", argv[file_index]);
                if (flag.n) printf("%d:", number_lines);
                printf("%s\n", line);
            }
        }
    }
    regfree(&compiled);
    if (flag.c) {
        if (flag.files) printf("%s:", argv[file_index]);
        if (flag.l && matching_lines)
            printf("1\n");
        else
            printf("%d\n", matching_lines);
    }
    if (flag.l && matching_lines) printf("%s\n", argv[file_index]);
}

int search_files(int argc, char** argv, struct flags flag) {
    char *e_ptr = NULL, *f_ptr = NULL;
    int i = 1;

    while (i < argc) {
        if (argv[i][0] == '-') {
            e_ptr = strchr(argv[i], 'e');
            f_ptr = strchr(argv[i], 'f');
            if (e_ptr && f_ptr) {
                if (e_ptr > f_ptr) {
                    ++f_ptr;
                    if (*f_ptr == '\0') ++i;
                } else {
                    ++e_ptr;
                    if (*e_ptr == '\0') ++i;
                }
            } else if (e_ptr) {
                ++e_ptr;
                if (*e_ptr == '\0') ++i;
            } else if (f_ptr) {
                ++f_ptr;
                if (*f_ptr == '\0') ++i;
            }
            ++i;
        } else {
            break;
        }
    }
    return (flag.e || flag.f) ? i : i + 1;
}

void get_patt_e(int* counter, char* pattern, char* optarg,
                   struct flags* flag) {
    if (*counter > 0) strcat(pattern, "|");
    *counter = *counter + 1;
    if (*optarg == '\0') {
        flag->empty = 1;
        strcat(pattern, ".");
    } else {
        strcat(pattern, optarg);
    }
}

void get_patt_f(int* counter, char* pattern, char* optarg,
                   struct flags* flag) {
    FILE* file = NULL;
    char line[SBUFF] = {0};

    if ((file = fopen(optarg, "r"))) {
        fseek(file, 0, SEEK_SET);
        while (fgets(line, SBUFF, file) != NULL) {
            if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = 0;
            if (*counter > 0) strcat(pattern, "|");
            if (*line == '\0') {
                flag->empty = 1;
                strcat(pattern, ".");
            } else {
                strcat(pattern, line);
            }
            *counter = *counter + 1;
        }
        fclose(file);
    } else {
        printf("s21_grep: %s: No such file\n", optarg);
        exit(1);
    }
}
