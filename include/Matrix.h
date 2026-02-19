#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix{
    float** matr;
    int n;
    int m;
    bool opError;
public:
    
    float* data() const;
    int GetN() const;
    int GetM() const;
    Matrix(int n, int m);
    Matrix() : Matrix(1,1){};
    void MakeTraspanent();
    void Show() const;
    Matrix& Reverse() const;
    float Determinent();
    Matrix& operator+(Matrix& a);
    Matrix& operator-(Matrix& a);
    Matrix& operator*(Matrix& a);
    Matrix& operator=(Matrix& a);
    bool operator()(std::vector<float>& a);
    float* operator[](int i);
    ~Matrix();
};
#endif