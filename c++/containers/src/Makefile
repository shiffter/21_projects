CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++17 -lstdc++ -pedantic
UBUNTU_FLAGS = -lpthread -lsubunit -lrt
TEST_FLAGS = -lgtest -lstdc++ 
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
MY_LIB = s21_containers.a
NAME = runTest
COMMON_LIB = -lm

SRCS = $(wildcard vector/*.cc) $(wildcard list/*.cc)
OBJF = $(SRCS:%.cc=objf/%.o)

SRCSTEST = $(wildcard tests/*.cc)
OBJSTEST 	= 	$(SRCSTEST:%.cc=objs_test/%.o)
OBJTESTDIR 	= 	objs_test objs_test/tests
REPORT_NAME = report

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += $(UBUNTU_FLAGS)
endif

all: clean gcov_report html

s21_containers.a: $(MY_LIB) 

test: $(OBJSTEST)
	$(CC) $(OBJSTEST) $(TEST_FLAGS) $(COMMON_LIB) -o ./tests/$(NAME) $(GCOV_FLAGS)
	./tests/$(NAME)

gcov_report: test
	lcov -t "$(REPORT_NAME)" -o objs_test/$(REPORT_NAME).info -c -d .
	genhtml objs_test/$(REPORT_NAME).info -o finish

clean: clean_test
	rm -rf $(MY_LIB)
	rm -rf finish

clean_test:
	rm -rf ./test/build
	rm -rf ./objf
	rm -rf $(OBJTESTDIR)


$(MY_LIB): $(OBJF)
	ar rc $(MY_LIB) $(OBJF)
	ranlib $(MY_LIB)

create_dir:
	mkdir ./objf
	mkdir objf/vector && mkdir ./objf/list

objf/%.o: %.cc create_dir
	$(CC) -o $@ -c $< $(CFLAGS)

objs_test/%.o: %.cc
	@mkdir -p $(OBJTESTDIR)
	$(CC) -o $@ -c $< $(GCOV_FLAGS)

lint:
	clang-format -i *.h *.cc ./tests/*

leaks: test
ifeq ($(UNAME), Linux)
	valgrind --leak-check=full --track-origins=yes --read-inline-info=yes --show-leak-kinds=all -s ./tests/$(NAME)
endif
ifeq ($(UNAME), Darwin)
	leaks --atExit ./tests/$(NAME)
endif

html:
ifeq ($(UNAME), Linux)
	firefox finish/index.html
endif
ifeq ($(UNAME), Darwin)
	open finish/index.html
endif
