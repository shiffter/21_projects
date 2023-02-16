#include <getopt.h>
#include <stdio.h>

struct flags {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
};

void get_flags(int argc, char** argv, struct flags* flag);
void in_file(int argc, char** argv, struct flags flag);
void output_print(FILE* fp, struct flags flag);

int main(int argc, char** argv) {
    struct flags flag = {0};

    if (argc > 1) {
        get_flags(argc, argv, &flag);
        in_file(argc, argv, flag);
    }
    return 0;
}

void get_flags(int argc, char** argv, struct flags* flag) {
    int result = 0;
    const struct option long_options[] = {{"number-nonblank", 0, &flag->b, 1},
                                          {"number", 0, &flag->n, 1},
                                          {"squeeze-blank", 0, &flag->s, 1},
                                          {NULL, 0, NULL, 0}};

    while ((result = getopt_long(argc, argv, "benstvET", long_options, NULL)) !=
           -1) {
        switch (result) {
            case 'b':
                flag->b = 1;
                break;
            case 'e':
                flag->v = 1;
                flag->e = 1;
                break;
            case 'E':
                flag->e = 1;
                break;
            case 'n':
                flag->n = 1;
                break;
            case 's':
                flag->s = 1;
                break;
            case 't':
                flag->v = 1;
                flag->t = 1;
                break;
            case 'T':
                flag->t = 1;
                break;
            case 'v':
                flag->v = 1;
                break;
        }
    }
    if (flag->b) flag->n = 0;
}

void in_file(int argc, char** argv, struct flags flag) {
    FILE* file = NULL;

    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] != '-') {
            if ((file = fopen(argv[i], "r")) != NULL) {
                fseek(file, 0, SEEK_SET);
                output_print(file, flag);
                fclose(file);
            } else {
                printf("s21_cat: %s: No such file\n", argv[i]);
            }
        }
    }
}

void output_print(FILE* file, struct flags flag) {
    int number = 0, new_line = 1;
    char pr_ch = 0, ch = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (flag.s) {
            if (pr_ch == '\n' && ch == '\n') {
                ch = fgetc(file);
                if (ch != '\n') {
                    if (flag.n) printf("%6d\t", ++number);
                    flag.e ? printf("$\n") : printf("\n");
                } else {
                    continue;
                }
            }
            pr_ch = ch;
        }
        if (flag.n) {
            if (new_line) {
                printf("%6d\t", ++number);
                new_line = 0;
            }
            if (ch == '\n') new_line = 1;
        }
        if (flag.b) {
            if (new_line && ch != '\n') {
                printf("%6d\t", ++number);
                new_line = 0;
            }
            if (ch == '\n') new_line = 1;
        }
        if (flag.e) {
            if (ch == '\n') printf("$");
        }
        if (flag.t) {
            if (ch == '\t') {
                printf("^I");
                continue;
            }
        }
        if (flag.v) {
            if (ch <= 31 && ch != 10 && ch != 9) {
                printf("^");
                ch += 64;
            }
            if (ch == 127) {
                printf("^");
                ch -= 64;
            }
        }
        printf("%c", ch);
    }
}
