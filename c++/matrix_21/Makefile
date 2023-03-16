CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c++17 -pedantic


#For test
CHECK_FLAGS =	-lcheck -lm -lpthread
GCOV_FLAGS 	= 	-fprofile-arcs -ftest-coverage

FLAGS 		=	$(CFLAGS) $(CHECK_FLAGS) $(GCOV_FLAGS)
GFLAGS 		=	$(FLAGS)

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	CHECK_FLAGS += -lsubunit -lrt
endif

SRCS = $(wildcard *.cc)
OBJF = $(SRCS:%.cpp=objf/%.o)

SRCSTEST 	= 	$(wildcard s21_*.c tests/*.cc)
OBJSTEST 	= 	$(SRCSTEST:%.c=objs_test/%.o)
DEPENDSTEST = 	$(OBJSTEST:%.o=%.d)
OBJTESTDIR 	= 	objs_test objs_test/tests

MY_LIB = s21_matrix_cpp.a
NAME = test

-include $(DEPENDS) $(DEPENDSTEST)

all: $(MY_LIB) 
	rm -rf /objf

test: $(OBJSTEST)
	rm -rf $(wildcard objs_test/*.gcda objs_test/tests/*.gcda)
	$(CC) $(OBJSTEST) -o $(NAME) $(GFLAGS)


gcov_report: GFLAGS += -lgcov
gcov_report: test
	./$(NAME)
	lcov -t "$(REPORT_NAME)" -o objs_test/$(REPORT_NAME).info -c -d .
	genhtml objs_test/$(REPORT_NAME).info -o finish


test_run:
	cd test; mkdir build; cmake CMakeLists.txt -B ./build
	cd test/build && make 
	./test/build/runTests

clean: clean_gcov
	rm -rf objs *.a
clean_gcov:
	rm -rf objs_test *.info $(REPORT_NAME) $(NAME) finish


$(MY_LIB): $(OBJF)
	ar rc $(MY_LIB) $(OBJF)
	ranlib $(MY_LIB)

objf/%.o: %.cc
	@mkdir -p objf/
	$(CC) -MMD -o $@ -c $< $(CFLAGS)


objs_test/%.o: %.cc
	@mkdir -p $(OBJTESTDIR)
	$(CC) -MMD -o $@ -c $< $(FLAGS)


lint:
	clang-format -i *.h *.cpp
