//
// Created by mfbut on 11/14/2019.
//

#include "ConstVectorIterator.h"
#include "BaseVector.h"

Matrix::ConstVectorIterator::ConstVectorIterator(const ConstBaseVector* vector, int pos){
    this->vector = vector;
    position = pos;
}

const Matrix::ConstVectorIterator::value_type& Matrix::ConstVectorIterator::operator*() const {
    return vector->at(position);
}

const Matrix::ConstVectorIterator::value_type& Matrix::ConstVectorIterator::operator[](int offset) const {
    return vector->at(position - offset);

}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator++() {
    position++;
    return *this;
}

const Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator++(int) {
    position++;
    return *this;
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator--() {
    position--;
    return *this;
}

const Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator--(int) {
    position--;
    return *this;
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator+=(int amount) {
    position+=amount;
    return *this;
}

Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator+(int amount) const {
    return ConstVectorIterator(vector, position + amount);
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator-=(int amount) {
    position-=amount;
    return *this;
}

Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator-(int amount) const {
    return ConstVectorIterator(vector, position - amount);
}

Matrix::ConstVectorIterator::difference_type Matrix::ConstVectorIterator::operator-(const ConstVectorIterator& rhs) {
    return position - rhs.position;
}

bool Matrix::ConstVectorIterator::operator==(const ConstVectorIterator& rhs) const {
    if(vector == rhs.vector && position == rhs.position){
        return true;
    }
    return false;
}

bool Matrix::ConstVectorIterator::operator!=(const ConstVectorIterator& rhs) const {
    if(vector == rhs.vector && position == rhs.position){
        return false;
    }
    return true;
}

bool Matrix::ConstVectorIterator::operator<(const ConstVectorIterator& rhs) const {
    return position < rhs.position;
}

bool Matrix::ConstVectorIterator::operator<=(const ConstVectorIterator& rhs) const {
    return position <= rhs.position;
}

bool Matrix::ConstVectorIterator::operator>(const ConstVectorIterator& rhs) const {
    return position > rhs.position;
}

bool Matrix::ConstVectorIterator::operator>=(const ConstVectorIterator& rhs) const {
    return position > rhs.position;
}
