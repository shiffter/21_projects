all: 
	g++ *.cpp && ./a.out


test: clean_test
	cd test; cmake CMakeLists.txt; make; ./runTests

clean_test:
	rm -rf ./test/runTests
