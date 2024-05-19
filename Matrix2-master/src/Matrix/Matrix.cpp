//
// Created by mfbut on 11/14/2019.
//

#include <algorithm>
#include <functional>
#include "Matrix.h"

Matrix::Matrix::Matrix(int numRows, int numCols, const Matrix::Matrix::element_type& val): data(numRows,Vector(numCols, val)), num_rows(numRows), num_cols(numCols){

}

Matrix::Matrix::Matrix(int numRows, int numCols) : data(numRows,Vector(numCols)),num_rows(numRows), num_cols(numCols) {

}

Matrix::Matrix::Matrix(const std::vector<std::vector<element_type>>& values) : data(values.size(),Vector(values[0].size())),num_rows(values.size()), num_cols(values[0].size()) {
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            data[i][j] = values[i][j];
        }
    }
}

Matrix::Matrix::Matrix(const std::vector<Vector>& values) : data(values),num_rows(values.size()), num_cols(values[0].size()) {

}

Matrix::Matrix::Matrix(const std::vector<ConstVectorRef>& values) : num_rows(values.size()), num_cols(values[0].size()) {
    for(int i = 0; i < num_rows; i++){
        data.emplace_back(num_cols);
        for(int j = 0; j < num_cols; j++){
            data[i][j] = values[i][j];
        }
    }
}

Matrix::Matrix::Matrix(const std::vector<VectorRef>& values): num_rows(values.size()), num_cols(values[0].size()) {
    for(int i = 0; i < num_rows; i++){
        data.emplace_back(num_cols);
        for(int j = 0; j < num_cols; j++){
            data[i][j] = values[i][j];
        }
    }
}

Matrix::Matrix Matrix::Matrix::ident(int dim) {
    auto temp = Matrix(dim,dim);
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(i == j){
                temp[i][j] = 1;
            }else {
                temp[i][j] = 0;
            }
        }
    }
    return temp;
}

int Matrix::Matrix::getNumRows() const {
    return num_rows;
}

int Matrix::Matrix::getNumCols() const {
    return num_cols;
}

Matrix::Matrix::element_type& Matrix::Matrix::at(int row, int col) {
    return data.at(row).at(col);
}

const Matrix::Matrix::element_type& Matrix::Matrix::at(int row, int col) const {
    return data.at(row).at(col);
}

Matrix::VectorRef Matrix::Matrix::rowAt(int row) {
    return VectorRef(data.at(row));
}

Matrix::ConstVectorRef Matrix::Matrix::rowAt(int row) const {
    return ConstVectorRef(data.at(row));
}

Matrix::VectorRef Matrix::Matrix::colAt(int col) {
    return VectorRef(*this, col);
}

Matrix::ConstVectorRef Matrix::Matrix::colAt(int col) const {
    return ConstVectorRef(*this, col);
}

Matrix::VectorRef Matrix::Matrix::operator[](int row) {
    return VectorRef(data[row]);
}

Matrix::ConstVectorRef Matrix::Matrix::operator[](int row) const {
    return ConstVectorRef(data[row]);
}

Matrix::Matrix::const_iterator Matrix::Matrix::begin() const {
    return ConstRowIterator(this, 0);
}

Matrix::Matrix::const_iterator Matrix::Matrix::end() const {
    return ConstRowIterator(this, num_rows);
}

Matrix::Matrix::iterator Matrix::Matrix::begin() {
    return RowIterator(this, 0);
}

Matrix::Matrix::iterator Matrix::Matrix::end() {
    return RowIterator(this, num_rows);
}

Matrix::Matrix::const_row_iterator Matrix::Matrix::rowBegin() const {
    return ConstRowIterator(this, 0);
}

Matrix::Matrix::const_row_iterator Matrix::Matrix::rowEnd() const {
    return ConstRowIterator(this, num_rows);
}

Matrix::Matrix::row_iterator Matrix::Matrix::rowBegin() {
    return RowIterator(this, 0);
}

Matrix::Matrix::row_iterator Matrix::Matrix::rowEnd() {
    return RowIterator(this, num_rows);
}

Matrix::Matrix::const_column_iterator Matrix::Matrix::colBegin() const {
    return ConstColumnIterator(this, 0);
}

Matrix::Matrix::const_column_iterator Matrix::Matrix::colEnd() const {
    return ConstColumnIterator(this, num_cols);
}

Matrix::Matrix::column_iterator Matrix::Matrix::colBegin() {
    return ColumnIterator(this, 0);
}

Matrix::Matrix::column_iterator Matrix::Matrix::colEnd() {
    return ColumnIterator(this, num_cols);
}

Matrix::Matrix Matrix::Matrix::operator-() const{
    Matrix temp(data);
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            temp[i][j] = -temp[i][j];
        }
    }
    return temp;
}

Matrix::Matrix& Matrix::Matrix::operator+=(const Matrix& rhs) {
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            data[i][j] += rhs[i][j];
        }
    }
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator+(const Matrix& rhs) {
    Matrix temp(data);
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            temp[i][j] += rhs[i][j];
        }
    }
    return temp;
}

Matrix::Matrix& Matrix::Matrix::operator-=(const Matrix& rhs) {
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            data[i][j] -= rhs[i][j];
        }
    }
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator-(const Matrix& rhs) {
    Matrix temp(data);
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            temp[i][j] -= rhs[i][j];
        }
    }
    return temp;
}

Matrix::Matrix& Matrix::Matrix::operator*=(const Matrix& rhs) {
    *this = *this * rhs;
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator*(const Matrix& rhs) {
    Matrix temp(num_rows,rhs.getNumCols(),0);
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < rhs.getNumCols(); j++){
            for(int k = 0; k < num_cols; k++){
                temp[i][j] += (*this)[i][k] * rhs[k][j];
            }
        }
    }
    return temp;
}

Matrix::Matrix& Matrix::Matrix::operator+=(const element_type& rhs) {
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            data[i][j] += rhs;
        }
    }
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator+(const element_type& rhs) const {
    Matrix temp(data);
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            temp[i][j] += rhs;
        }
    }
    return temp;
}

Matrix::Matrix& Matrix::Matrix::operator-=(const element_type& rhs) {
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            data[i][j] -= rhs;
        }
    }
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator-(const element_type& rhs) const{
    Matrix temp(data);
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            temp[i][j] -= rhs;
        }
    }
    return temp;
}

Matrix::Matrix& Matrix::Matrix::operator*=(const element_type& rhs) {
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            data[i][j] *= rhs;
        }
    }
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator*(const element_type& rhs) const{
    Matrix temp(data);
    for(int i = 0; i <num_rows; i++){
        for(int j = 0; j <num_cols; j++){
            temp[i][j] *= rhs;
        }
    }
    return temp;
}


Matrix::Matrix Matrix::operator+(const Matrix::element_type& lhs, const Matrix& rhs) {
    Matrix temp(rhs.getNumRows(),rhs.getNumCols(),lhs);
    for(int i = 0; i < rhs.getNumRows(); i++){
        for(int j = 0; j < rhs.getNumCols(); j++){
            temp[i][j] += rhs[i][j];
        }
    }
    return temp;
}

Matrix::Matrix Matrix::operator-(const Matrix::element_type& lhs, const Matrix& rhs) {
    Matrix temp(rhs.getNumRows(),rhs.getNumCols(),lhs);
    for(int i = 0; i < rhs.getNumRows(); i++){
        for(int j = 0; j < rhs.getNumCols(); j++){
            temp[i][j] -= rhs[i][j];
        }
    }
    return temp;
}

Matrix::Matrix Matrix::operator*(const Matrix::element_type& lhs, const Matrix& rhs) {
    Matrix temp(rhs.getNumRows(),rhs.getNumCols(),lhs);
    for(int i = 0; i < rhs.getNumRows(); i++){
        for(int j = 0; j < rhs.getNumCols(); j++){
            temp[i][j] *= rhs[i][j];
        }
    }
    return temp;
}



