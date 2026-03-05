#ifndef MATRIX_H
#define MATRIX_H


namespace Vectors{
    class Matrix{
        double *arr;
        unsigned int n;
        unsigned int m;
    
        public:
            Matrix();
            Matrix(int n, int m, double* matrix);
            Matrix(int n, int m);
            Matrix(const Matrix&);
            Matrix(Matrix&&);
    
            unsigned int GetN() const;
            unsigned int GetM() const;
            double& operator[](int i);
            double operator[](int i) const;
            Matrix operator+(const Matrix& b) const;
            Matrix operator-(const Matrix& b) const;
            Matrix operator*(const Matrix& b) const;
            Matrix& operator=(const Matrix& b);
            Matrix& operator+=(const Matrix& b);
            Matrix& operator-=(const Matrix& b);
            Matrix& operator*=(const Matrix& b);

            void show();
    
            ~Matrix();
    };

    class Vec3{
    };

    class Vec4{

    };
};

#endif