#include "Matrix.h"
#include <cassert>
#include <iostream>
using namespace Vectors;


Matrix::Matrix(int n, int m): n(n), m(m){
    arr = new double[n*m];
    for(int i = 0; i < n*m; i++){
        arr[i] = 0;
    }
}

Matrix::Matrix(int n, int m, double *matrix):n(n), m(m){
    arr = new double[n * m];
    
    for (int i = 0; i < n * m; ++i) {
        arr[i] = matrix[i];
    }
}

Matrix::Matrix(const Matrix& copy):n(copy.n),m(copy.m){
    arr = new double[n*m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i*m + j] = copy.arr[i*m + j];
        }
    }
}

Matrix::Matrix():Matrix(1,1){

}

Matrix::Matrix(Matrix&& temp):n(temp.n), m(temp.m){
    arr = temp.arr;
    temp.arr = nullptr;
}


double& Matrix::operator[](int i){
    assert((n * m > i) && (i >= 0));
    return arr[i];
}

double Matrix::operator[](int i) const{
    assert((n * m > i) && (i >= 0));
    return arr[i];
}

Vectors::Matrix Matrix::operator+(const Matrix& b) const{
    assert((n == b.n) && (m == b.m));
    Matrix rez(n,m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            rez[i*m + j] = arr[i*m + j] + b[i*m + j];
        }
    }
    return rez;
}
Vectors::Matrix Matrix::operator-(const Matrix& b) const{
    assert((n == b.n) && (m == b.m));
    Matrix rez(n,m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            rez[i*m + j] = arr[i*m + j] - b[i*m + j];
        }
    }
    return rez;
}
Vectors::Matrix Matrix::operator*(const Matrix& b) const{
    assert(m == b.n);
    unsigned int newN = n;
    unsigned int newM = b.m;
    Matrix rez(newN, newM);
    for(int i = 0; i < newN; i++){
        for(int j = 0; j < newM; j++){
            for(int k =0; k < m; k++){
                rez[i*newM + j] += arr[i*m + k] * b[k*b.m + j];
            }
        }
    }
    return rez;
}

Vectors::Matrix& Matrix::operator=(const Matrix& b){
    if(this == &b) return *this;
    delete[] arr;

    n = b.n;
    m = b.m;

    arr = new double[n*m];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i*m + j] = b[i*m + j];
        }
    }
    return *this;
}

Vectors::Matrix& Matrix::operator+=(const Matrix& b){
    *this = *this + b;
    return *this;
}

Vectors::Matrix& Matrix::operator-=(const Matrix& b){
    *this = *this - b;
    return *this;
}

Vectors::Matrix& Matrix::operator*=(const Matrix& b){
    *this = (*this)*b;
    return *this;
}

unsigned int Matrix::GetN() const{
    return n;
}


unsigned int Matrix::GetM() const{
    return m;
}

void Matrix::show(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << arr[i*m + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------" << std::endl;
}

Matrix::~Matrix(){
    delete[] arr;
}