//
// Created by mfbut on 11/17/2019.
//

#include <algorithm>
#include "Vector.h"
#include "ConstBaseVector.h"
#include <iostream>

Matrix::ConstVectorIterator Matrix::ConstBaseVector::begin() const {
    return ConstVectorIterator(this,0);
}

Matrix::ConstVectorIterator Matrix::ConstBaseVector::end() const {
    return ConstVectorIterator(this, this->size());
}

Matrix::Vector Matrix::ConstBaseVector::operator-() const {
    Vector negated(*this);
    for(auto& value: negated){
        value = -value;
    }
    return negated;
}

Matrix::Vector Matrix::ConstBaseVector::operator+(const ConstBaseVector& rhs) {
    Vector sum(*this);
    auto sum_itr = sum.begin();
    auto rhs_itr = rhs.begin();
    for(;sum_itr != sum.end() and rhs_itr!= rhs.end(); ++sum_itr, ++rhs_itr){
        *sum_itr += *rhs_itr;
    }
    return sum;
}

Matrix::Vector Matrix::ConstBaseVector::operator-(const ConstBaseVector& rhs) {
    Vector difference(*this);
    auto neg_itr = difference.begin();
    auto rhs_itr = rhs.begin();
    for(;neg_itr != difference.end() and rhs_itr!= rhs.end(); ++neg_itr, ++rhs_itr){
        *neg_itr -= *rhs_itr;
    }
    return difference;
}

Matrix::Vector Matrix::ConstBaseVector::operator*(const ConstBaseVector& rhs) const {
    ConstBaseVector::value_type temp = 0;
    auto mult_itr = this->begin();
    auto rhs_itr = rhs.begin();
    for(;mult_itr != this->end() and rhs_itr != rhs.end(); ++mult_itr, ++rhs_itr){
        temp += (*mult_itr) * (*rhs_itr);
    }
    return Vector (1,temp);
}

Matrix::Vector Matrix::ConstBaseVector::operator+(const ConstBaseVector::value_type& rhs) const {
    Vector sum(*this);
    auto sum_itr = sum.begin();
    for(;sum_itr != sum.end(); ++sum_itr){
        *sum_itr += rhs;
    }
    return sum;
}

Matrix::Vector Matrix::ConstBaseVector::operator-(const ConstBaseVector::value_type& rhs) const {
    Vector difference(*this);
    auto diff_itr = difference.begin();
    for(;diff_itr != difference.end(); ++diff_itr){
        *diff_itr -= rhs;
    }
    return difference;
}

Matrix::Vector Matrix::ConstBaseVector::operator*(const ConstBaseVector::value_type& rhs) const {
    Vector multiplication(*this);
    auto mult_itr = multiplication.begin();
    for(;mult_itr != multiplication.end(); ++mult_itr){
        *mult_itr *= rhs;
    }
    return multiplication;
}

bool Matrix::ConstBaseVector::operator==(const ConstBaseVector& rhs) const {
    Vector equal(*this);
    auto equal_itr = equal.begin();
    auto rhs_itr = rhs.begin();
    for(;equal_itr != equal.end() and rhs_itr != rhs.end(); ++equal_itr, ++rhs_itr){
        if(*equal_itr != *rhs_itr){
            return false;
        }
    }
    return true;
}

bool Matrix::ConstBaseVector::operator!=(const ConstBaseVector& rhs) const {
    Vector equal(*this);
    auto equal_itr = equal.begin();
    auto rhs_itr = rhs.begin();
    for(;equal_itr != equal.end() and rhs_itr != rhs.end(); ++equal_itr, ++rhs_itr){
        if(*equal_itr != *rhs_itr){
            return true;
        }
    }
    return false;
}

Matrix::Vector Matrix::operator+(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs) {
    Vector sum(rhs);
    auto rhs_itr = rhs.begin();
    auto sum_itr = sum.begin();
    for(;sum_itr != sum.end() and rhs_itr!= rhs.end(); ++rhs_itr, sum_itr++){
        *sum_itr = *rhs_itr + lhs;
    }
    return sum;
}

Matrix::Vector Matrix::operator-(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs) {
    Vector difference(rhs);
    auto rhs_itr = rhs.begin();
    auto diff_itr = difference.begin();
    for(;diff_itr != difference.end() and rhs_itr!= rhs.end(); ++rhs_itr, diff_itr++){
        *diff_itr = lhs - *rhs_itr;
    }
    return difference;
}

Matrix::Vector Matrix::operator*(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs) {
    Vector multiplication(rhs);
    auto rhs_itr = rhs.begin();
    auto mult_itr = multiplication.begin();
    for(;mult_itr != multiplication.end() and rhs_itr!= rhs.end(); ++rhs_itr, mult_itr++){
        *mult_itr = *rhs_itr * lhs;
    }
    return multiplication;
}
