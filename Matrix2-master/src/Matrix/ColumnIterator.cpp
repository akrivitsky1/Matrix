//
// Created by mfbut on 11/17/2019.
//

#include "ColumnIterator.h"
#include "ConstColumnIterator.h"
#include "Matrix.h"

Matrix::ColumnIterator::ColumnIterator(Matrix* matrix, int col) : matrix(matrix), col(col) {

}

Matrix::ColumnIterator::operator ConstColumnIterator() const {
    return ConstColumnIterator(matrix, col);
}

Matrix::ConstVectorRef Matrix::ColumnIterator::operator*() const {
    return const_cast<const Matrix*>(matrix)->colAt(col);
}

Matrix::ColumnIterator::value_type Matrix::ColumnIterator::operator*() {
    return VectorRef(*matrix, col);
}



Matrix::ConstVectorRef  Matrix::ColumnIterator::operator[](int offset) const {
    return const_cast<const Matrix*>(matrix)->colAt(col + offset);
}

Matrix::ColumnIterator::value_type Matrix::ColumnIterator::operator[](int offset) {
    return VectorRef(*matrix, col + offset);
}

Matrix::ColumnIterator& Matrix::ColumnIterator::operator++() {
    col++;
    return *this;
}

const Matrix::ColumnIterator Matrix::ColumnIterator::operator++(int) {
    col++;
    return *this;
}

Matrix::ColumnIterator& Matrix::ColumnIterator::operator--() {
    col--;
    return *this;
}

const Matrix::ColumnIterator Matrix::ColumnIterator::operator--(int) {
    col--;
    return *this;
}

Matrix::ColumnIterator& Matrix::ColumnIterator::operator+=(int amount) {
    col += amount;
    return *this;
}

Matrix::ColumnIterator Matrix::ColumnIterator::operator+(int amount) const {
    return ColumnIterator(matrix,col+amount);
}

Matrix::ColumnIterator& Matrix::ColumnIterator::operator-=(int amount) {
    col -= amount;
    return *this;
}

Matrix::ColumnIterator Matrix::ColumnIterator::operator-(int amount) const {
    return ColumnIterator(matrix,col-amount);
}

Matrix::ColumnIterator::difference_type Matrix::ColumnIterator::operator-(const ColumnIterator& rhs) {
    return col - rhs.col;
}

bool Matrix::ColumnIterator::operator==(const ColumnIterator& rhs) const {
    return matrix == rhs.matrix && col == rhs.col;
}

bool Matrix::ColumnIterator::operator!=(const ColumnIterator& rhs) const {
    return matrix != rhs.matrix || col != rhs.col;
}

bool Matrix::ColumnIterator::operator<(const ColumnIterator& rhs) const {
    return col < rhs.col;
}

bool Matrix::ColumnIterator::operator<=(const ColumnIterator& rhs) const {
    return col <= rhs.col;
}

bool Matrix::ColumnIterator::operator>(const ColumnIterator& rhs) const {
    return col > rhs.col;
}

bool Matrix::ColumnIterator::operator>=(const ColumnIterator& rhs) const {
    return col >= rhs.col;
}