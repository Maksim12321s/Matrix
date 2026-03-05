#include "Matrix.h"
#include <gtest/gtest.h>

using namespace Vectors;


TEST(MatrixTest, ConstructorDimensions) {
    Matrix m(5, 10);
    EXPECT_EQ(m.GetN(), 5); 
    EXPECT_EQ(m.GetM(), 10);
}


TEST(MatrixTest, ElementAccess) {
    Matrix m(3, 3);
    
    m[0] = 1.5;
    m[8] = 2.5; 

    EXPECT_DOUBLE_EQ(m[0], 1.5);
    EXPECT_DOUBLE_EQ(m[8], 2.5);
}

TEST(MatrixTest, Addition) {
    Matrix a(2, 2);
    Matrix b(2, 2);
    
    for(int i = 0; i < 4; ++i) {
        a[i] = 1.0;
        b[i] = 2.0;
    }

    Matrix c = a + b;

    EXPECT_DOUBLE_EQ(c[0], 3.0);
    EXPECT_DOUBLE_EQ(c[3], 3.0);
}

TEST(MatrixTest, DeepCopyCheck) {
    Matrix a(2, 2);
    a[0] = 100.0;
    
    Matrix b = a; 
    b[0] = 500.0; 

    EXPECT_DOUBLE_EQ(a[0], 100.0);
    EXPECT_DOUBLE_EQ(b[0], 500.0);
}
TEST(MatrixTest, OutOfBoundsDeath) {
    Matrix m(2, 2); 

    EXPECT_DEATH(m[4], "");
    EXPECT_DEATH(m[-1], "");
}