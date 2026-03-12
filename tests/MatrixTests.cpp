#include <gtest/gtest.h>
#include "Matrix.h"
using namespace Vectors;

TEST(MatrixTest, ConstructorAndGetters) {
    Matrix m(3, 4);
    EXPECT_EQ(m.GetN(), 3);
    EXPECT_EQ(m.GetM(), 4);
}

TEST(MatrixTest, ConstructorWithArray) {
    std::vector<float> data = {1.0, 2.0, 3.0, 4.0};
    Matrix m(2, 2, data.data());

    EXPECT_DOUBLE_EQ(m[0], 1.0);
    EXPECT_DOUBLE_EQ(m[1], 2.0);
    EXPECT_DOUBLE_EQ(m[2], 3.0);
    EXPECT_DOUBLE_EQ(m[3], 4.0);
}

TEST(MatrixTest, CopyConstructorDeepCopy) {
    Matrix a(2, 2);
    a[0] = 10.0;
    a[1] = 20.0;
    a[2] = 30.0;
    a[3] = 40.0;

    Matrix b(a);
    
    EXPECT_EQ(b.GetN(), 2);
    EXPECT_EQ(b.GetM(), 2);
    EXPECT_DOUBLE_EQ(b[0], 10.0);

    b[0] = 999.0;
    
    EXPECT_DOUBLE_EQ(a[0], 10.0);
    EXPECT_DOUBLE_EQ(b[0], 999.0);
}

TEST(MatrixTest, MoveConstructor) {
    Matrix a(2, 2);
    a[0] = 5.0;
    
    Matrix b(std::move(a));

    EXPECT_EQ(b.GetN(), 2);
    EXPECT_EQ(b.GetM(), 2);
    EXPECT_DOUBLE_EQ(b[0], 5.0);
}

TEST(MatrixTest, OperatorBracketsReadWrite) {
    Matrix m(3, 3);
    m[0] = 1.1;
    m[8] = 9.9;

    EXPECT_DOUBLE_EQ(m[0], 1.1);
    EXPECT_DOUBLE_EQ(m[8], 9.9);
    
    const Matrix cm(3, 3);
    double val = cm[0];
    EXPECT_DOUBLE_EQ(val, cm[0]);
}

TEST(MatrixTest, OperatorBracketsOutOfBoundsDeath) {
    Matrix m(2, 2);
    EXPECT_DEATH(m[4], "");
    EXPECT_DEATH(m[-1], "");
}

TEST(MatrixTest, OperatorPlus) {
    Matrix a(2, 2);
    Matrix b(2, 2);

    for (int i = 0; i < 4; ++i) {
        a[i] = i;
        b[i] = i * 2;
    }

    Matrix c = a + b;

    EXPECT_DOUBLE_EQ(c[0], 0.0);
    EXPECT_DOUBLE_EQ(c[1], 3.0);
    EXPECT_DOUBLE_EQ(c[2], 6.0);
    EXPECT_DOUBLE_EQ(c[3], 9.0);
}

TEST(MatrixTest, OperatorMinus) {
    Matrix a(2, 2);
    Matrix b(2, 2);

    for (int i = 0; i < 4; ++i) {
        a[i] = 10.0;
        b[i] = 4.0;
    }

    Matrix c = a - b;

    EXPECT_DOUBLE_EQ(c[0], 6.0);
    EXPECT_DOUBLE_EQ(c[3], 6.0);
}

TEST(MatrixTest, OperatorMultiplyMatrix) {
    Matrix a(2, 3);
    Matrix b(3, 2);

    a[0] = 1; a[1] = 2; a[2] = 3;
    a[3] = 4; a[4] = 5; a[5] = 6;

    b[0] = 7; b[1] = 8;
    b[2] = 9; b[3] = 1;
    b[4] = 2; b[5] = 3;

    Matrix c = a * b;

    EXPECT_EQ(c.GetN(), 2);
    EXPECT_EQ(c.GetM(), 2);

    EXPECT_DOUBLE_EQ(c[0], 31.0);
    EXPECT_DOUBLE_EQ(c[1], 19.0);
    EXPECT_DOUBLE_EQ(c[2], 85.0);
    EXPECT_DOUBLE_EQ(c[3], 55.0);
}

TEST(MatrixTest, OperatorAssignment) {
    Matrix a(2, 2);
    Matrix b(5, 5);
    
    b[0] = 100.0;
    a = b;

    EXPECT_EQ(a.GetN(), 5);
    EXPECT_EQ(a.GetM(), 5);
    EXPECT_DOUBLE_EQ(a[0], 100.0);

    b[0] = 0.0;
    EXPECT_DOUBLE_EQ(a[0], 100.0);

    a = a;
    EXPECT_DOUBLE_EQ(a[0], 100.0);
}

TEST(MatrixTest, OperatorPlusEquals) {
    Matrix a(2, 1);
    Matrix b(2, 1);
    
    a[0] = 1.0; a[1] = 2.0;
    b[0] = 3.0; b[1] = 4.0;

    a += b;

    EXPECT_DOUBLE_EQ(a[0], 4.0);
    EXPECT_DOUBLE_EQ(a[1], 6.0);
}

TEST(MatrixTest, OperatorMinusEquals) {
    Matrix a(2, 1);
    Matrix b(2, 1);
    
    a[0] = 10.0; a[1] = 20.0;
    b[0] = 3.0;  b[1] = 5.0;

    a -= b;

    EXPECT_DOUBLE_EQ(a[0], 7.0);
    EXPECT_DOUBLE_EQ(a[1], 15.0);
}

TEST(MatrixTest, OperatorMultiplyEquals) {
    Matrix a(2, 2);
    Matrix b(2, 2);

    a[0] = 1; a[1] = 0;
    a[2] = 0; a[3] = 1; 

    b[0] = 2; b[1] = 3;
    b[2] = 4; b[3] = 5;

    a *= b;

    EXPECT_DOUBLE_EQ(a[0], 2.0);
    EXPECT_DOUBLE_EQ(a[1], 3.0);
    EXPECT_DOUBLE_EQ(a[2], 4.0);
    EXPECT_DOUBLE_EQ(a[3], 5.0);
}

TEST(MatrixTest, DimensionsMismatchDeath) {
    Matrix a(2, 2);
    Matrix b(3, 3);
    
    EXPECT_DEATH(a + b, "");
    EXPECT_DEATH(a - b, "");
    EXPECT_DEATH(a += b, "");
    EXPECT_DEATH(a -= b, "");
}

TEST(MatrixTest, MultiplicationMismatchDeath) {
    Matrix a(2, 3);
    Matrix b(4, 2);
    
    EXPECT_DEATH(a * b, "");
}