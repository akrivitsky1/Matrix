//
// Created by mfbut on 11/19/2019.
//

#ifndef ECS_36B_HOMEWORK_MATRIXCONSTRUCTORTESTS_CPP
#define ECS_36B_HOMEWORK_MATRIXCONSTRUCTORTESTS_CPP
#include <vector>
#include "Matrix.h"
#include "MatrixTesting.h"
#include "gmock/gmock.h"

TEST_F(MatrixTesting, DimensionsAndValues) {
  using namespace ::testing;
  Matrix::Matrix mat1(3, 4, 5);
  answer_type ans(3, {5, 5, 5, 5});
  EXPECT_TRUE(mat1 == ans);
}

TEST_F(MatrixTesting, DimensionsOnly) {
  using namespace ::testing;
  Matrix::Matrix mat1(15, 3, 0);
  answer_type ans(15, {0, 0, 0});
  EXPECT_TRUE(mat1 == ans);
}

TEST_F(MatrixTesting, StdVectorOfStdVectorOfElementType) {
  using namespace ::testing;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};

  Matrix::Matrix mat1(ans);
  EXPECT_TRUE(mat1 == ans);
}

TEST_F(MatrixTesting, StdVectorOfMatrixVector) {
  using namespace ::testing;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  std::vector<Matrix::Vector> initializer(ans.begin(), ans.end());

  Matrix::Matrix mat1(initializer);
  EXPECT_TRUE(mat1 == ans);
}

TEST_F(MatrixTesting, StdVectorOfMatrixConstVectorRef) {
  using namespace ::testing;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  std::vector<Matrix::Vector> vectors(ans.begin(), ans.end());
  std::vector<Matrix::ConstVectorRef> initializer(vectors.begin(), vectors.end());

  Matrix::Matrix mat1(initializer);
  EXPECT_TRUE(mat1 == ans);
}

TEST_F(MatrixTesting, StdVectorOfMatrixVectorRef) {
  using namespace ::testing;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  std::vector<Matrix::Vector> vectors(ans.begin(), ans.end());
  std::vector<Matrix::VectorRef> initializer(vectors.begin(), vectors.end());

  Matrix::Matrix mat1(initializer);
  EXPECT_TRUE(mat1 == ans);
}

TEST_F(MatrixTesting, MatrixIdentity) {
  using namespace ::testing;
  answer_type ans1{{1, 0, 0},
                   {0, 1, 0},
                   {0, 0, 1}},
      ans2{{1, 0, 0, 0},
           {0, 1, 0, 0},
           {0, 0, 1, 0},
           {0, 0, 0, 1}
  };

  Matrix::Matrix mat1 = Matrix::Matrix::ident(3),
  mat2 = Matrix::Matrix::ident(4);

  EXPECT_TRUE(mat1 == ans1);
  EXPECT_TRUE(mat2 == ans2);
}

#endif //ECS_36B_HOMEWORK_MATRIXCONSTRUCTORTESTS_CPP
