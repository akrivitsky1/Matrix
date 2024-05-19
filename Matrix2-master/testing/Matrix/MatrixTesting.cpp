//
// Created by mfbut on 11/17/2019.
//

#include "MatrixTesting.h"

::testing::AssertionResult operator==(const Matrix::Matrix& given, const MatrixTesting::answer_type& answer) {
  const int answerNumRows = answer.size(), answerNumCols = answer.front().size();
  if (given.getNumRows() != answerNumRows) {
    return ::testing::AssertionFailure() << "Given matrix has incorrect number of rows.\n"
                                            "It should have " << answerNumRows <<
                                         "rows but actually has " << given.getNumRows() << " rows." << std::endl;
  } else if (given.getNumCols() != answerNumCols) {
    return ::testing::AssertionFailure() << "Given matrix has incorrect number of columns.\n"
                                            "It should have " << answerNumCols <<
                                         "columns but actually has " << given.getNumCols() << " rows." << std::endl;
  } else {
    for (int row = 0; row < answerNumRows; ++row) {
      for (int col = 0; col < answerNumCols; ++col) {
        if (answer.at(row).at(col) != given.at(row, col)) {
          return ::testing::AssertionFailure() <<
                                               "\nGiven matrix:\n" /*<< given*/ << std::endl <<
                                               "Does not match expected matrix:\n" << std::endl <<
                                               "First mismatch occurs at position: " << row << ", " << col << "."
                                               << std::endl <<
                                               "The given matrix has " << given.at(row, col)
                                               << " there but it should be " <<
                                               answer.at(row).at(col) << '.'  << std::endl;
        }
      }
    }
  }
  return ::testing::AssertionSuccess();
}

std::ostream& operator<<(std::ostream& out, const MatrixTesting::answer_type& answer) {
  for (const auto& row : answer) {
    for (const auto& element : row) {
      out << element << ' ';
    }
    out << std::endl;
  }
  return out;
}

std::ostream& operator<<(std::ostream& out, const Matrix::Matrix& matrix) {
  for (const auto& row : matrix) {
    for (const auto& element : row) {
      out << element << ' ';
    }
    out << std::endl;
  }
  return out;
}
