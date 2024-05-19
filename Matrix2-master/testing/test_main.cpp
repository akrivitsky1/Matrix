//
// Created by mfbut on 11/14/2019.
//

#include "gtest/gtest.h"


/*
 * If you do not want to build the tests contained in a specific file
 * comment out the include below
 * and comment out the files in  either
 * testing/Matrix/CMakeLists.txt
 * or
 * testing/Vector/CMakeLists.txt
 */
//vector tests
#include "VectorConstructorTests.cpp"
#include "ConstBaseVectorTests.cpp"
#include "BaseVectorTests.cpp"
#include "VectorRefTesting.cpp"

//matrix tests
#include "MatrixConstructorTests.cpp"
#include "MatrixElementAccessTests.cpp"
#include "MatrixArithmeticOperatorTests.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
