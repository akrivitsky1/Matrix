//
// Created by mfbut on 11/21/2019.
//

#include "MatrixTesting.h"
#include "gmock/gmock.h"
TEST_F(MatrixTesting, MatrixOperatorNegate) {
  using namespace ::testing;
  answer_type values{{10, 20},
                     {30, 40},
                     {45, 50},
                     {100, 200}};
  answer_type answer{{-10, -20},
                     {-30, -40},
                     {-45, -50},
                     {-100, -200}};

  Matrix::Matrix mat1(values);
  ASSERT_TRUE(-mat1 == answer);
  ASSERT_TRUE(mat1 == values);
}

TEST_F(MatrixTesting, MatrixPlusEqualMatrix) {
  using namespace ::testing;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  answer_type rhs{{100, 200},
                  {300, 400},
                  {500, 600},
                  {700, 800}};
  answer_type answer{{110, 220},
                     {330, 440},
                     {545, 650},
                     {800, 1000}};

  Matrix::Matrix mat1(lhs), mat2(rhs);
  auto& ref = mat1 += mat2;
  ASSERT_TRUE(mat1 == answer);
  ASSERT_EQ(&mat1, &ref);
}

TEST_F(MatrixTesting, MatrixPlusMatrix) {
  using namespace ::testing;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  answer_type rhs{{100, 200},
                  {300, 400},
                  {500, 600},
                  {700, 800}};
  answer_type answer{{110, 220},
                     {330, 440},
                     {545, 650},
                     {800, 1000}};

  Matrix::Matrix mat1(lhs), mat2(rhs);
  auto sum = mat1 + mat2;
  ASSERT_TRUE(sum == answer);
}

TEST_F(MatrixTesting, MatrixMinusEqualMatrix) {
  using namespace ::testing;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  answer_type rhs{{100, 200},
                  {300, 400},
                  {500, 600},
                  {700, 800}};
  answer_type answer{{-90, -180},
                     {-270, -360},
                     {-455, -550},
                     {-600, -600}};

  Matrix::Matrix mat1(lhs), mat2(rhs);
  auto& ref = mat1 -= mat2;
  ASSERT_TRUE(mat1 == answer);
  ASSERT_EQ(&mat1, &ref);
}

TEST_F(MatrixTesting, MatrixMinusMatrix) {
  using namespace ::testing;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  answer_type rhs{{100, 200},
                  {300, 400},
                  {500, 600},
                  {700, 800}};
  answer_type answer{{-90, -180},
                     {-270, -360},
                     {-455, -550},
                     {-600, -600}};

  Matrix::Matrix mat1(lhs), mat2(rhs);
  auto diff = mat1 - mat2;
  ASSERT_TRUE(diff == answer);
}

TEST_F(MatrixTesting, MatrixTimesEqualMatrix) {
  using namespace ::testing;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  answer_type rhs{{100, 200, 300},
                  {400, 500, 600}};

  answer_type answer{{9000, 12000, 15000},
                     {19000, 26000, 33000},
                     {24500, 34000, 43500},
                     {90000, 120000, 150000}};

  Matrix::Matrix mat1(lhs), mat2(rhs);
  auto& ref = mat1 *= mat2;
  ASSERT_TRUE(mat1 == answer);
  ASSERT_EQ(&mat1, &ref);
}

TEST_F(MatrixTesting, MatrixTimesMatrix) {
  using namespace ::testing;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  answer_type rhs{{100, 200, 300},
                  {400, 500, 600}};

  answer_type answer{{9000, 12000, 15000},
                     {19000, 26000, 33000},
                     {24500, 34000, 43500},
                     {90000, 120000, 150000}};

  Matrix::Matrix mat1(lhs), mat2(rhs);
  auto prod = mat1 * mat2;
  ASSERT_TRUE(prod == answer);
}

TEST_F(MatrixTesting, MatrixPlusEqualScalar) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  elem_type rhs(100);
  answer_type answer{{110, 120},
                     {130, 140},
                     {145, 150},
                     {200, 300}};

  Matrix::Matrix mat1(lhs);
  auto& ref = mat1 += rhs;
  ASSERT_TRUE(mat1 == answer);
  ASSERT_EQ(&mat1, &ref);
}

TEST_F(MatrixTesting, MatrixPlusScalar) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  elem_type rhs(100);
  answer_type answer{{110, 120},
                     {130, 140},
                     {145, 150},
                     {200, 300}};

  Matrix::Matrix mat1(lhs);
  auto sum = mat1 + rhs;
  ASSERT_TRUE(sum == answer);
}

TEST_F(MatrixTesting, MatrixMinusEqualScalar) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  elem_type rhs(10);
  answer_type answer{{0, 10},
                     {20, 30},
                     {35, 40},
                     {90, 190}};

  Matrix::Matrix mat1(lhs);
  auto& ref = mat1 -= rhs;
  ASSERT_TRUE(mat1 == answer);
  ASSERT_EQ(&mat1, &ref);
}

TEST_F(MatrixTesting, MatrixMinusScalar) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  elem_type rhs(10);
  answer_type answer{{0, 10},
                     {20, 30},
                     {35, 40},
                     {90, 190}};

  Matrix::Matrix mat1(lhs);
  auto diff = mat1 - rhs;
  ASSERT_TRUE(diff == answer);
}

TEST_F(MatrixTesting, MatrixTimesEqualScalar) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  elem_type rhs(10);
  answer_type answer{{100, 200},
                     {300, 400},
                     {450, 500},
                     {1000, 2000}};

  Matrix::Matrix mat1(lhs);
  auto& ref = mat1 *= rhs;
  ASSERT_TRUE(mat1 == answer);
  ASSERT_EQ(&mat1, &ref);
}

TEST_F(MatrixTesting, MatrixTimesScalar) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;

  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  elem_type rhs(2);

  answer_type answer{{20, 40},
                     {60, 80},
                     {90, 100},
                     {200, 400}};

  Matrix::Matrix mat1(lhs);
  auto prod = mat1 * rhs;
  ASSERT_TRUE(prod == answer);
}

TEST_F(MatrixTesting, ScalarPlusMatrix) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  elem_type rhs(100);
  answer_type answer{{110, 120},
                     {130, 140},
                     {145, 150},
                     {200, 300}};

  Matrix::Matrix mat1(lhs);
  auto sum = rhs + mat1;
  ASSERT_TRUE(sum == answer);
}

TEST_F(MatrixTesting, ScalarMinusMatrix) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  elem_type rhs(10);
  answer_type answer{{0, -10},
                     {-20, -30},
                     {-35, -40},
                     {-90, -190}};

  Matrix::Matrix mat1(lhs);
  auto diff = rhs - mat1;
  ASSERT_TRUE(diff == answer);
}

TEST_F(MatrixTesting, ScalarTimesMatrix) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;

  answer_type lhs{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  elem_type rhs(2);

  answer_type answer{{20, 40},
                     {60, 80},
                     {90, 100},
                     {200, 400}};

  Matrix::Matrix mat1(lhs);
  auto prod = rhs * mat1;
  ASSERT_TRUE(prod == answer);
}
