OUTDIR = $(shell cd ../build && pwd)
UNAME = $(shell uname -s)
CC = gcc -Wall -Werror -Wextra -std=c11
OUTNAME = "tests"
OUTNAME2 = "2tests"
OUTNAME3 = "3tests"

ifeq ($(UNAME),Darwin)
	FLAGSS = -lcheck -lm -lpthread -fprofile-arcs
endif
ifeq ($(UNAME),Linux)
	FLAGSS = -lcheck -lsubunit -lrt -lm -lpthread -fprofile-arcs
endif


all: cleanall build 

build: style test gcov_report s21_math.a

rebuild: cleanall all

gcov_report:
	gcov -b -l -p -c *.gcno
	gcovr -g -k -r . --html --html-details -o coverage_report.html

test: s21_tests.c s21_math_fortests.o
	$(CC) s21_tests.c s21_math_fortests.o $(FLAGSS) -o $(OUTNAME)
	./$(OUTNAME)

s21_math.a: s21_math.o
	ar -rcs s21_math.a s21_math.o
	ranlib s21_math.a

s21_math_fortests.o: s21_math.c
	$(CC) -c --coverage s21_math.c -o s21_math_fortests.o

s21_math.o: s21_math.c
	$(CC) -c s21_math.c

style:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	cp ../materials/linters/cpplint.py cpplint.py
	python3 cpplint.py --extension=c *.c *.h

clean:
	/bin/rm -rf *.o

cleanall:
	/bin/rm -rf *.o *.a *.so $(OUTNAME) $(OUTNAME2) $(OUTNAME3) coverage* *.gcno *.gcda *.gcov *.dSYM *.cfg *.py
