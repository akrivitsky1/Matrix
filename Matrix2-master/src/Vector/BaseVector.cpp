//
// Created by mfbut on 11/14/2019.
//

#include <functional>
#include <algorithm>
#include "BaseVector.h"
#include "Vector.h"
#include "ConstVectorIterator.h"
#include "VectorIterator.h"
#include "Matrix.h"

Matrix::BaseVector::operator Matrix() const {
    Matrix temp(this->size(),1);
    for(int i = 0; i < temp.getNumRows(); i++){
        temp[i][0] = this->at(i);
    }
    return temp;
}

Matrix::VectorIterator Matrix::BaseVector::begin() {
    return VectorIterator(this,0);
}

Matrix::VectorIterator Matrix::BaseVector::end() {
    return VectorIterator(this, this->size());
}

Matrix::ConstVectorIterator Matrix::BaseVector::begin() const {
    return ConstVectorIterator(this,0);
}

Matrix::ConstVectorIterator Matrix::BaseVector::end() const {
    return ConstVectorIterator(this,this->size());
}

Matrix::ConstVectorIterator Matrix::BaseVector::cbegin() const {
    return ConstVectorIterator(this, 0);
}

Matrix::ConstVectorIterator Matrix::BaseVector::cend() const {
    return ConstVectorIterator(this, this->size());
}

Matrix::BaseVector& Matrix::BaseVector::operator+=(const ConstBaseVector& rhs) {
    auto member_itr = (*this).begin();
    auto rhs_itr = rhs.begin();
    for(;rhs_itr!= rhs.end() and member_itr != (*this).end();++rhs_itr, member_itr++){
        *member_itr += *rhs_itr;
    }
    return *this;
}

Matrix::BaseVector& Matrix::BaseVector::operator-=(const ConstBaseVector& rhs) {
    auto member_itr = (*this).begin();
    auto rhs_itr = rhs.begin();
    for(;rhs_itr!= rhs.end() and member_itr != (*this).end();++rhs_itr, ++member_itr){
        *member_itr -= *rhs_itr;
    }
    return *this;
}

Matrix::BaseVector& Matrix::BaseVector::operator+=(const BaseVector::value_type& rhs) {
    auto member_itr = (*this).begin();
    for(;member_itr != (*this).end(); member_itr++){
        *member_itr += rhs;
    }
    return *this;
}

Matrix::BaseVector& Matrix::BaseVector::operator-=(const BaseVector::value_type& rhs) {
    auto member_itr = (*this).begin();
    for(;member_itr != (*this).end(); member_itr++){
        *member_itr -= rhs;
    }
    return *this;
}

Matrix::BaseVector& Matrix::BaseVector::operator*=(const BaseVector::value_type& rhs) {
    auto member_itr = (*this).begin();
    for(;member_itr != (*this).end(); member_itr++){
        *member_itr *= rhs;
    }
    return *this;
}












