cmake_minimum_required(VERSION 3.5)
# TODO: add
project(matrix_plus VERSION 0.1 LANGUAGES CXX)

# TODO: add
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Locate GTest
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(GTest  REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests test_check.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES}  Threads::Threads )
