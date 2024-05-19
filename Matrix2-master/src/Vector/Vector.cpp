//
// Created by mfbut on 11/14/2019.
//

#include "Vector.h"


Matrix::Vector::Vector(const ConstBaseVector& orig)  {
    elements.reserve(orig.size());
    for(auto element : orig){
        elements.push_back((element));
    }
}

Matrix::Vector::Vector(int numElements, const BaseVector::value_type& value) {
    elements.resize(numElements);
    for(unsigned long i = 0; i < elements.size(); i++){
        elements.at(i) = value;
    }

}

Matrix::Vector::Vector(int numElements) {
    elements.resize(numElements);
    for(unsigned long i = 0; i < elements.size(); i++){
        elements.at(i) = 0;
    }
}

Matrix::Vector::Vector(const std::vector<value_type>& values) {
    elements.resize(values.size());
    for(unsigned long i = 0; i < elements.size(); i++){
        elements.at(i) = values.at(i);
    }
}

Matrix::Vector::Vector() {
    elements.resize(1);
    elements.at(0) = 0;
}

int Matrix::Vector::size() const {
    return elements.size();
}

Matrix::BaseVector::value_type& Matrix::Vector::at(int index) {
    return elements.at(index);
}

const Matrix::BaseVector::value_type& Matrix::Vector::at(int index) const {
    return elements.at(index);
}

Matrix::BaseVector::value_type& Matrix::Vector::operator[](int index) {
    return elements.at(index);
}

const Matrix::BaseVector::value_type& Matrix::Vector::operator[](int index) const {
    return elements.at(index);
}

Matrix::Vector& Matrix::Vector::operator=(const ConstBaseVector& rhs) {
    for(int i = 0; i < rhs.size(); i++){
        this->at(i) = rhs[i];
    }
    return *this;
}










