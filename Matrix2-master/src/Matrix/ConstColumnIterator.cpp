//
// Created by mfbut on 11/17/2019.
//

#include "ConstColumnIterator.h"
#include "Matrix.h"

Matrix::ConstColumnIterator::ConstColumnIterator(const Matrix* matrix, int col): matrix(matrix), col(col) {

}


Matrix::ConstColumnIterator::value_type Matrix::ConstColumnIterator::operator*() const {
    return ConstVectorRef(*matrix, col);
}

Matrix::ConstColumnIterator::value_type Matrix::ConstColumnIterator::operator[](int offset) const {
    return ConstVectorRef(*matrix, col + offset);
}

Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator++() {
    col++;
    return *this;
}

const Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator++(int) {
    col++;
    return *this;
}

Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator--() {
    col--;
    return *this;
}

const Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator--(int) {
    col--;
    return *this;
}

Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator+=(int amount) {
    col += amount;
    return *this;
}

Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator+(int amount) const {
    return ConstColumnIterator(matrix,col+amount);
}

Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator-=(int amount) {
    col -= amount;
    return *this;
}

Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator-(int amount) const {
    return ConstColumnIterator(matrix,col-amount);
}

Matrix::ConstColumnIterator::difference_type Matrix::ConstColumnIterator::operator-(const ConstColumnIterator& rhs) {
    return col - rhs.col;
}

bool Matrix::ConstColumnIterator::operator==(const ConstColumnIterator& rhs) const {
    return matrix == rhs.matrix && col == rhs.col;
}

bool Matrix::ConstColumnIterator::operator!=(const ConstColumnIterator& rhs) const {
    return matrix != rhs.matrix || col != rhs.col;
}

bool Matrix::ConstColumnIterator::operator<(const ConstColumnIterator& rhs) const {
    return col < rhs.col;
}

bool Matrix::ConstColumnIterator::operator<=(const ConstColumnIterator& rhs) const {
    return col <= rhs.col;
}

bool Matrix::ConstColumnIterator::operator>(const ConstColumnIterator& rhs) const {
    return col > rhs.col;
}

bool Matrix::ConstColumnIterator::operator>=(const ConstColumnIterator& rhs) const {
    return col >= rhs.col;
}
