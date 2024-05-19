cmake_minimum_required(VERSION 3.14)
project(MatrixTesting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED)
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
endif ()
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
add_subdirectory(Vector)
add_subdirectory(Matrix)

add_executable(MatrixTester test_main.cpp)
target_link_libraries(MatrixTester VectorTesting MatrixTesting)
