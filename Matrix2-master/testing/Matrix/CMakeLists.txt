cmake_minimum_required(VERSION 3.14)
project(MatrixVectorTesting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(MatrixTesting STATIC
        MatrixTesting.cpp MatrixTesting.h
        MatrixConstructorTests.cpp
        MatrixElementAccessTests.cpp
        MatrixArithmeticOperatorTests.cpp)
target_link_libraries(MatrixTesting PUBLIC MatrixMatrix gtest gmock )
target_compile_options(MatrixTesting PRIVATE -Wall -Werror -Wextra)
target_include_directories(MatrixTesting PUBLIC .)
