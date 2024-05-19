//
// Created by mfbut on 11/17/2019.
//


#include "ConstRowIterator.h"
#include "Matrix.h"

Matrix::ConstRowIterator::ConstRowIterator(const Matrix* matrix, int row): matrix(matrix), row(row) {

}

Matrix::ConstRowIterator::value_type Matrix::ConstRowIterator::operator*() const {
    return (*matrix)[row];
}

Matrix::ConstRowIterator::value_type Matrix::ConstRowIterator::operator[](int offset) const {
    return (*matrix)[row + offset];
}

Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator++() {
    row++;
    return *this;
}

const Matrix::ConstRowIterator Matrix::ConstRowIterator::operator++(int) {
    row++;
    return *this;
}

Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator--() {
    row--;
    return *this;
}

const Matrix::ConstRowIterator Matrix::ConstRowIterator::operator--(int) {
    row--;
    return *this;
}

Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator+=(int amount) {
    row += amount;
    return *this;
}

Matrix::ConstRowIterator Matrix::ConstRowIterator::operator+(int amount) const {
    return ConstRowIterator(matrix,row+amount);
}

Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator-=(int amount) {
    row -= amount;
    return *this;
}

Matrix::ConstRowIterator Matrix::ConstRowIterator::operator-(int amount) const {
    return ConstRowIterator(matrix,row-amount);
}

Matrix::ConstRowIterator::difference_type Matrix::ConstRowIterator::operator-(const ConstRowIterator& rhs) {
    return row - rhs.row;
}

bool Matrix::ConstRowIterator::operator==(const ConstRowIterator& rhs) const {
    return matrix == rhs.matrix && row == rhs.row;
}

bool Matrix::ConstRowIterator::operator!=(const ConstRowIterator& rhs) const {
    return matrix != rhs.matrix || row != rhs.row;
}

bool Matrix::ConstRowIterator::operator<(const ConstRowIterator& rhs) const {
    return row < rhs.row;
}

bool Matrix::ConstRowIterator::operator<=(const ConstRowIterator& rhs) const {
    return row <= rhs.row;
}

bool Matrix::ConstRowIterator::operator>(const ConstRowIterator& rhs) const {
    return row > rhs.row;
}

bool Matrix::ConstRowIterator::operator>=(const ConstRowIterator& rhs) const {
    return row >= rhs.row;
}

