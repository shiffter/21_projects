CC = gcc

<<<<<<< HEAD
# TODO: add -std=c++17 -pedantic
CFLAGS = -Wall -Wextra -Werror -std=c++17 -pedantic
=======
CFLAGS = -Wall -Wextra -Werror
>>>>>>> c80a8d0c46ee55dcc5468f3539756e6818982abd
MY_LIB = s21_matrix_cpp.a
NAME = runTest

all: $(MY_LIB) 
	rm -rf /objf

test_run:
	cd test; mkdir build; cmake CMakeLists.txt -B ./build
	cd test/build && make 
	./test/build/runTests

clean: clean_test
	rm -rf $(MY_LIB)

clean_test:
	rm -rf ./test/build
	rm -rf ./objf

SRCS = $(wildcard *.cpp)
OBJF = $(SRCS:%.cpp=objf/%.o)

$(MY_LIB): $(OBJF)
	ar rc $(MY_LIB) $(OBJF)
	ranlib $(MY_LIB)

objf/%.o: %.cpp
	@mkdir -p objf/
	$(CC) -MMD -o $@ -c $< $(CFLAGS)

lint:
	clang-format -i *.h *.cpp
