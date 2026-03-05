#include "Matrix.h"
#include <gtest/gtest.h>

using namespace Vectors;




TEST(MatrixTest, ElementAccess){
    Matrix m(3,3);

    m[0] = 3.5;
    m[5] = 4.0;


    EXPECT_DOUBLE_EQ(m[0],3.5);
    EXPECT_DOUBLE_EQ(m[5],4.0);
}