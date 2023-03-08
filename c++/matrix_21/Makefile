all: 
	g++ *.cpp && ./a.out


test: clean_test
	cd test; cmake CMakeLists.txt; make; ./runTests

clean_test:
	# cd ./test && rm -rf runTests cmake_install.cmake CMakeCache.txt CMakeFiles Makefile
	rm -rf ./test/build
	rm *.o *.gcov *.html *.css *.gcno
