CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -pedantic -std=c11
GCOV_FLAGS	=	-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS	=	-lcheck -lm -lpthread 
FLAGS		=	$(CFLAGS) $(CHECK_FLAGS) $(GCOV_FLAGS)
GFLAGS		=	$(CFLAGS) $(CHECK_FLAGS)

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	CHECK_FLAGS += -lsubunit -lrt
endif

vpath			%.c functions

SRCS 		= 	$(wildcard functions/s21_*.c)
OBJF		=	$(SRCS:%.c=objf/%.o)
DEPENDS		=	$(OBJF:%.o=%.d)

#for tests
SRCTEST		=	$(wildcard tests/*.c)
OBJSTEST	=	$(SRCTEST:%.c=objf/%.o)
DEPENDSTEST	=	$(OBJSTEST:%.o=%.d)
OBJTESTDIR	=	 objf/functions objf/tests

MYLIB		=	s21_matrix.a
NAME		=	test
REPORT_NAME =	report

all: $(MYLIB)
	rm -r ./objf

test: $(OBJSTEST) $(MYLIB)
	rm -rf $(wildcard objs_test/*.gcda objs_test/tests/*.gcda)
	$(CC) $(OBJSTEST) $(OBJF) -o $(NAME) $(GFLAGS) #after FLAGS switch to GFLAGS
	./$(NAME)	
# -include $(DEPENDS) $(DEPENDSTEST)

clean:
	rm -rf ./objf/ *.o s21_matrix.a test ./finish 
 
$(MYLIB): $(OBJF)
	ar rc $(MYLIB) $(OBJF)
	ranlib $(MYLIB)

objf/%.o: %.c
	@mkdir -p objf/functions
	@mkdir -p objf/tests
	$(CC) -MMD -o $@ -c $< $(CFLAGS)

gcov_report: CFLAGS += $(CHECK_FLAGS) $(GCOV_FLAGS)
	

gcov_report: clean test
	./$(NAME)
	lcov -t "$(REPORT_NAME)" -o objf/$(REPORT_NAME).info -c -d .
	genhtml objf/$(REPORT_NAME).info -o finish

lint:
	clang-format -i s21_matrix.h Makefile ./functions/*.c tests/*.c tests/*.h

h: 
ifeq ($(UNAME), Linux)
	firefox finish/index.html
endif
ifeq ($(UNAME), Darwin)
	open finish/index.html
endif
