#ifndef MATRIX_H
#define MATRIX_H


namespace Vectors{
    class Matrix{
        float *arr;
        unsigned int n;
        unsigned int m;
    
        public:
            Matrix();
            Matrix(int n, int m, float* matrix);
            Matrix(int n, int m);
            Matrix(const Matrix&);
            Matrix(Matrix&&);
    
            unsigned int GetN() const;
            unsigned int GetM() const;
            float& operator[](int i);
            float operator[](int i) const;
            Matrix operator+(const Matrix& b) const;
            Matrix operator-(const Matrix& b) const;
            Matrix operator*(const Matrix& b) const;
            Matrix& operator=(const Matrix& b);
            Matrix& operator+=(const Matrix& b);
            Matrix& operator-=(const Matrix& b);
            Matrix& operator*=(const Matrix& b);
            int getSize();
            void show();
            float* getData();
            
    
            ~Matrix();
    };

    class Vec3{
        
        public:
            float x;
            float y;
            float z;
            Vec3(double x, double y, double z);
            Vec3();
            Vec3 operator+(const Vec3&);
            Vec3 operator-(const Vec3&);
            Vec3& operator=(const Vec3&);
            Vec3& operator+=(const Vec3&);
            Vec3& operator-=(const Vec3&);
            Vec3 operator*(const float);
            Vec3& normalize();
    };

    class Vec4: public Vec3{
        int t;
        public:
            Vec4();
            Vec4(double x, double y, double z, double t);
    };
    Vec3 Cross(const Vec3&, const Vec3&);
}

#endif