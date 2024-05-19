//
// Created by mfbut on 11/20/2019.
//

#include <algorithm>
#include <functional>
#include "MatrixTesting.h"
#include "gmock/gmock.h"

TEST_F(MatrixTesting, MatrixRowColAtRead) {
  using namespace ::testing;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};

  const int numRows = ans.size(), numCols = ans.front().size();
  Matrix::Matrix mat1(ans);

  for (int row = 0; row < numRows; ++row) {
    for (int col = 0; col < numCols; ++col) {
      ASSERT_EQ(mat1.at(row, col), ans.at(row).at(col));
      ASSERT_TRUE(mat1 == ans);
    }
  }
}

TEST_F(MatrixTesting, MatrixRowColAtWrite) {
  using namespace ::testing;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};

  const int numRows = ans.size(), numCols = ans.front().size();
  Matrix::Matrix mat1(ans);

  auto& ansRef = ans.at(2).at(1);
  auto& givenRef = mat1.at(2, 1);

  for (int row = 0; row < numRows; ++row) {
    for (int col = 0; col < numCols; ++col) {
      ASSERT_EQ(mat1.at(row, col), ans.at(row).at(col));
      ASSERT_EQ(givenRef, ansRef);
      mat1.at(row, col) += 14;
      ans.at(row).at(col) += 14;
      ASSERT_EQ(mat1.at(row, col), ans.at(row).at(col));
      ASSERT_EQ(givenRef, ansRef);
      ASSERT_TRUE(mat1 == ans);
    }
  }
}

TEST_F(MatrixTesting, MatrixRowAtRead) {
  using namespace ::testing;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};

  const int numRows = ans.size();
  Matrix::Matrix mat1(ans);

  ASSERT_TRUE(mat1 == ans);

  for (int row = 0; row < numRows; ++row) {
    ASSERT_THAT(mat1.rowAt(row), ElementsAreArray(ans.at(row)));
    ASSERT_TRUE(mat1 == ans);
  }
}
TEST_F(MatrixTesting, MatrixBracketRead) {
  using namespace ::testing;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};

  const int numRows = ans.size();
  Matrix::Matrix mat1(ans);

  ASSERT_TRUE(mat1 == ans);

  for (int row = 0; row < numRows; ++row) {
    ASSERT_THAT(mat1[row], ElementsAreArray(ans.at(row)));
    ASSERT_TRUE(mat1 == ans);
  }
}

TEST_F(MatrixTesting, MatrixRowAtWrite) {
  using namespace ::testing;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};

  const int numRows = ans.size();
  Matrix::Matrix mat1(ans);

  ASSERT_TRUE(mat1 == ans);
  for (int row = 0; row < numRows; ++row) {
    auto& curRow = ans.at(row);
    std::vector<Matrix::Matrix::element_type> newRow(curRow);
    std::transform(newRow.begin(), newRow.end(), curRow.rbegin(), newRow.begin(), std::plus<>());
    mat1.rowAt(row) = Matrix::Vector(newRow);
    curRow = newRow;
    ASSERT_THAT(mat1.rowAt(row), ElementsAreArray(ans.at(row)));
    ASSERT_TRUE(mat1 == ans);
  }
}
TEST_F(MatrixTesting, MatrixBracketWrite) {
  using namespace ::testing;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};

  const int numRows = ans.size();
  Matrix::Matrix mat1(ans);

  ASSERT_TRUE(mat1 == ans);
  for (int row = 0; row < numRows; ++row) {
    auto& curRow = ans.at(row);
    std::vector<Matrix::Matrix::element_type> newRow(curRow);
    std::transform(newRow.begin(), newRow.end(), curRow.rbegin(), newRow.begin(), std::plus<>());
    mat1.rowAt(row) = Matrix::Vector(newRow);
    curRow = newRow;
    ASSERT_THAT(mat1[row], ElementsAreArray(ans.at(row)));
    ASSERT_TRUE(mat1 == ans);
  }
}

TEST_F(MatrixTesting, MatrixColAtRead) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  const int numRows = ans.size(), numCols = ans.front().size();
  Matrix::Matrix mat1(ans);
  answer_type cols(ans.front().size(), std::vector<elem_type>(ans.size()));

  for (int row = 0; row < numRows; ++row) {
    for (int col = 0; col < numCols; ++col) {
      cols.at(col).at(row) = ans.at(row).at(col);
    }
  }


  ASSERT_TRUE(mat1 == ans);

  for (int col = 0; col < numCols; ++col) {
    ASSERT_THAT(mat1.colAt(col), ElementsAreArray(cols.at(col)));
    ASSERT_TRUE(mat1 == ans);
  }
}

TEST_F(MatrixTesting, MatrixColAtWrite) {
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type ans{{10, 20},
                  {30, 40},
                  {45, 50},
                  {100, 200}};
  const int numRows = ans.size(), numCols = ans.front().size();
  Matrix::Matrix mat1(ans);
  answer_type cols(ans.front().size(), std::vector<elem_type>(ans.size()));

  for (int row = 0; row < numRows; ++row) {
    for (int col = 0; col < numCols; ++col) {
      cols.at(col).at(row) = ans.at(row).at(col);
    }
  }


  ASSERT_TRUE(mat1 == ans);
  for (int col = 0; col < numCols; ++col) {
    auto& curCol = cols.at(col);
    mat1.colAt(col) += Matrix::Vector(curCol);
    std::transform(curCol.begin(), curCol.end(), curCol.begin(), curCol.begin(), std::plus<>());
    ASSERT_THAT(mat1.colAt(col), ElementsAreArray(cols.at(col)));
  }
}

TEST_F(MatrixTesting, RowIterate){
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type vals(5, std::vector<elem_type>(6, 7));
  Matrix::Matrix mat(vals);
  answer_type ans(5, std::vector<elem_type>(6, 10));

  for(auto row : mat){
    row += 3;
  }

  ASSERT_TRUE(mat == ans);
}

TEST_F(MatrixTesting, ColIterate){
  using namespace ::testing;
  using elem_type = Matrix::Matrix::element_type;
  answer_type vals(5, std::vector<elem_type>(6, 7));
  Matrix::Matrix mat(vals);
  answer_type ans(5, std::vector<elem_type>(6, 10));

  for(auto itr = mat.colBegin(); itr != mat.colEnd(); ++itr){
    *itr += 3;
  }

  ASSERT_TRUE(mat == ans);
}
