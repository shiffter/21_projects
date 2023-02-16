C_FLags=-Wall -Werror -Wextra -std=c11

all: s21_grep

build: s21_grep test

s21_grep: s21_grep.c
	gcc $(C_FLags) s21_grep.c -o s21_grep

test: s21_grep
	sh test_grep.sh

style: s21_grep.c
	python3 ../../materials/linters/cpplint.py --extensions=c *.c

clean:
	rm -rf s21_grep
