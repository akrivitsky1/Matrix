cmake_minimum_required(VERSION 3.14)
project(MatrixVectorTesting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(VectorTesting STATIC
        VectorTesting.cpp VectorTesting.h
        VectorConstructorTests.cpp
        ConstBaseVectorTests.cpp
        BaseVectorTests.cpp
        VectorRefTesting.cpp)
target_link_libraries(VectorTesting PUBLIC MatrixVector gtest gmock )
target_compile_options(VectorTesting PRIVATE -Wall -Werror -Wextra)
target_include_directories(VectorTesting PUBLIC .)
