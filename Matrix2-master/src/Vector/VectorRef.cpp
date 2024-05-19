//
// Created by mfbut on 11/16/2019.
//

#include "VectorRef.h"
#include "Matrix.h"

Matrix::VectorRef::VectorRef(BaseVector& orig) : ConstVectorRef(orig) {

}

Matrix::VectorRef::VectorRef(Matrix& matrix, int col) : ConstVectorRef(matrix,col) {

}

int Matrix::VectorRef::size() const {
    return elements.size();
}

Matrix::BaseVector::value_type& Matrix::VectorRef::at(int index) {
    return *elements.at(index);
}

const Matrix::BaseVector::value_type& Matrix::VectorRef::at(int index) const {
    return *elements.at(index);
}

Matrix::BaseVector::value_type& Matrix::VectorRef::operator[](int index) {
    return *elements.at(index);
}

const Matrix::BaseVector::value_type& Matrix::VectorRef::operator[](int index) const {
    return *elements.at(index);
}

Matrix::VectorRef& Matrix::VectorRef::operator=(const BaseVector& rhs) {
    for(int i = 0; i < rhs.size(); i++){
        this->at(i) = rhs[i];
    }
    return *this;
}





