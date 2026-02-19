#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int n, int m):n(n),m(m){
    matr = new float*[n];
    opError= false;
    for(int i = 0; i < n; i++){
        matr[i] = new float[m];
        for(int j = 0; j < m; j++){
            matr[i][j] = 0;
        }
    }
}

int Matrix::GetN() const{
    return n;
}

int Matrix::GetM() const{
    return m;
}

void Matrix::Show() const{  
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << matr[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

Matrix& Matrix::operator+(Matrix& a){
    if(n != a.n  || m != a.m){
        opError = true;
        return *this;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matr[i][j] += a.matr[i][j];
        }
    }
    return *this;
}
Matrix& Matrix::operator-(Matrix& a){
    if(n != a.n  || m != a.m){
        opError = true;
        return *this;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matr[i][j] -= a.matr[i][j];
        }
    }
    return *this;
}
Matrix& Matrix::operator=(Matrix& a){
    for(int i = 0; i < n; i++){
        delete[] matr[i];
    }
    delete[] matr;
    n = a.n;
    m = a.m;
    
    matr = new float*[n];
    for(int i = 0; i < n; i++){
        matr[i] = new float[m];
        for(int j = 0; j < m; j++){
            matr[i][j] = a.matr[i][j];
        }
    }
    return *this;
}
float* Matrix::operator[](int i) {
    return matr[i];
}
bool Matrix::operator()(std::vector<float>& a){
    if(a.size() != n*m){
        return false;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matr[i][j] = a[i*m + j];
        }
    }
    std::cout << std::endl;
    return true;
}
Matrix& Matrix::operator*(Matrix& a){
    if(m != a.n){
        return a;
    }
    Matrix* rez = new Matrix(n,a.m);
    Matrix& NewMatrix = *rez;

    for(int i = 0; i < NewMatrix.n; i++){
        for(int j = 0; j < NewMatrix.m; j++){
            NewMatrix[i][j] = 0;
            for(int s =0; s < this->m; s++){
                NewMatrix[i][j] +=  matr[i][s] * a.matr[s][j];
            } 
        }
    }
    return *rez; 
}
Matrix& Matrix::operator*(float a){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matr[i][j] *= a;
        }
    }
    return *this;
}
float* Matrix::data() const{
    float* data = new float[n*m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            data[i*n + j] = matr[i][j];
        }
    }
    return data;
}

void Matrix::MakeTraspanent(){
    int temp = m;
    m = n;
    n = temp;
    float** New = new float*[m];
    for(int i = 0; i < n; i++){
        New[i] = new float[n];
        for(int j = 0; j < m; j++){
            New[i][j] = matr[j][i];
        }
    }
    for(int i = 0; i < m; i++){
        delete[] matr[i];
    }
    delete[] matr;
    matr = New;
    
    
}

Matrix::~Matrix(){
    for(int i = 0; i < n; i++){
        delete[] matr[i];
    }
    delete[] matr;
}