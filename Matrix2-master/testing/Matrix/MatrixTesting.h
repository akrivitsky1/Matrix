//
// Created by mfbut on 11/17/2019.
//

#ifndef ECS_36B_HOMEWORK_MATRIXTESTING_H
#define ECS_36B_HOMEWORK_MATRIXTESTING_H
#include <vector>
#include <iostream>
#include "Matrix.h"
#include "gtest/gtest.h"
 class MatrixTesting : public ::testing::Test{
  public:
  using answer_type = std::vector<std::vector<Matrix::Matrix::element_type>>;
};

::testing::AssertionResult operator==(const Matrix::Matrix& given,
    const MatrixTesting::answer_type& answer);
std::ostream& operator << (std::ostream& out, const MatrixTesting::answer_type& answer);
std::ostream& operator << (std::ostream& out, const Matrix::Matrix& matrix);

#endif //ECS_36B_HOMEWORK_MATRIXTESTING_H
