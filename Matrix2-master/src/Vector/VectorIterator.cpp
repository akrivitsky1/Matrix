//
// Created by mfbut on 11/14/2019.
//

#include "VectorIterator.h"
#include "ConstColumnIterator.h"

Matrix::VectorIterator::VectorIterator(BaseVector* vector, int pos) {
    this->vector = vector;
    position = pos;
}

Matrix::VectorIterator::operator ConstVectorIterator() const {
    return ConstVectorIterator(vector,position);
}

Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator*() {
    return vector->at(position);
}

const Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator*() const {
    return vector->at(position);
}

const Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator[](int offset) const {
    return vector->at(position- offset);
}

Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator[](int offset) {
    return vector->at(position- offset);
}

Matrix::VectorIterator& Matrix::VectorIterator::operator++() {
    position++;
    return *this;
}

const Matrix::VectorIterator Matrix::VectorIterator::operator++(int) {
    position++;
    return *this;
}

Matrix::VectorIterator& Matrix::VectorIterator::operator--() {
    position--;
    return *this;
}

const Matrix::VectorIterator Matrix::VectorIterator::operator--(int) {
    position--;
    return *this;
}

Matrix::VectorIterator& Matrix::VectorIterator::operator+=(int amount) {
    position+=amount;
    return *this;
}

Matrix::VectorIterator Matrix::VectorIterator::operator+(int amount) const {
    return VectorIterator(vector, position + amount);
}

Matrix::VectorIterator& Matrix::VectorIterator::operator-=(int amount) {
    position-=amount;
    return *this;
}

Matrix::VectorIterator Matrix::VectorIterator::operator-(int amount) const {
    return VectorIterator(vector, position - amount);
}

Matrix::VectorIterator::difference_type Matrix::VectorIterator::operator-(const VectorIterator& rhs) {
    return position - rhs.position;
}

bool Matrix::VectorIterator::operator==(const VectorIterator& rhs) const {
    if(vector == rhs.vector && position == rhs.position){
        return true;
    }
    return false;
}

bool Matrix::VectorIterator::operator!=(const VectorIterator& rhs) const {
    if(vector == rhs.vector && position == rhs.position){
        return false;
    }
    return true;
}

bool Matrix::VectorIterator::operator<(const VectorIterator& rhs) const {
    return position < rhs.position;

}

bool Matrix::VectorIterator::operator<=(const VectorIterator& rhs) const {
    return position <= rhs.position;

}

bool Matrix::VectorIterator::operator>(const VectorIterator& rhs) const {
    return position > rhs.position;

}

bool Matrix::VectorIterator::operator>=(const VectorIterator& rhs) const {
    return position > rhs.position;

}






