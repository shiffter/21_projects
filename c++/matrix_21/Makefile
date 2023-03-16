CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c++17 -lstdc++ -pedantic
UBUTU_FLAGS = -lpthread -lsubunit -lrt
TEST_FLAGS = -lgtest -lstdc++ -lm
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
MY_LIB = s21_matrix_cpp.a
NAME = runTest

SRCS = $(wildcard *.cc)
OBJF = $(SRCS:%.cc=objf/%.o)

SRCSTEST = $(wildcard tests/*.cc)
OBJSTEST 	= 	$(SRCSTEST:%.cc=objs_test/%.o)
OBJTESTDIR 	= 	objs_test objs_test/tests

UNAME := $(shell uname)
all: $(MY_LIB) 
	# rm -rf /objf


test: $(OBJSTEST)
	$(CC) $(OBJSTEST) $(TEST_FLAGS) -o ./tests/$(NAME) $(GCOV_FLAGS)
	./tests/$(NAME)

gcov_report: test
	lcov -t "$(REPORT_NAME)" -o objs_test/$(REPORT_NAME).info -c -d .
	genhtml objs_test/$(REPORT_NAME).info -o finish
# test:
# 	cd tests && $(CC) *.cc $(TEST_FLAGS) -o test && ./test

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

objf/%.o: %.cc
	@mkdir -p objf/
	$(CC) -o $@ -c $< $(CFLAGS)

objs_test/%.o: %.cc
	@mkdir -p $(OBJTESTDIR)
	$(CC) -o $@ -c $<  $(GCOV_FLAGS) #$(TEST_FLAGS) #$(CFLAGS)

lint:
	clang-format -i *.h *.cc


html:
ifeq ($(UNAME), Linux)
	firefox finish/index.html
endif
ifeq ($(UNAME), Darwin)
	open finish/index.html
endif

