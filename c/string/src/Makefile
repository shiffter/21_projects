CC	=	gcc
FLAGS	=	-Wall	-Werror	-Wextra
LFLAGS	=	-lcheck	-lm	-lpthread
RFLAGS	=	-fprofile-arcs	-ftest-coverage
TDIR	=	tests
EXEDIR	=	test_run/

all:	s21_string.a	test

all_peer:	s21_string_peer	test_peer	gcov_report

s21_string_peer:
	$(CC)	$(FLAGS)	-c	$(RFLAGS)	*.c
	ar	rcs	s21_string.a	*.o
	ranlib	s21_string.a
	rm	*.o

s21_string.a:
	$(CC)	$(FLAGS)	-c	*.c
	ar	rcs	s21_string.a	*.o
	ranlib	s21_string.a
	rm	*.o

test:
	$(CC)	$(FLAGS)	-c	$(TDIR)/*.c
	$(CC)	*.o	s21_string.a	$(LFLAGS)	-o	$(EXEDIR)test
	$(EXEDIR)test

test_peer:
	$(CC)	$(FLAGS)	-c	$(TDIR)/*.c
	$(CC)	$(RFLAGS)	*.o	s21_string.a	$(LFLAGS)	-o	$(EXEDIR)test
	$(EXEDIR)test
	rm	-rf	*.o

gcov_report:
	gcovr -r . --html --html-details -o coverage_report.html

rebuild:	clean	all

clean:
	rm	-rf	*.o	*.out	*.gcno	*.gcna *.html *.gcda *.css
	rm -rf test_run/test
	rm	-rf	*.a