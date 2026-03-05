#include <gtest/gtest.h>
#include "Matrix.h" 
using namespace Vectors;
TEST(Vec3Test, DefaultConstructor) {
    Vec3 v;
    EXPECT_EQ(v.x, 0);
    EXPECT_EQ(v.y, 0);
    EXPECT_EQ(v.z, 0);
}

TEST(Vec3Test, ParameterizedConstructor) {
    Vec3 v(1.0, -2.0, 3.0);
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, -2);
    EXPECT_EQ(v.z, 3);
}

TEST(Vec3Test, ConstructorTruncation) {
    Vec3 v(1.9, 2.5, -3.9);
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
    EXPECT_EQ(v.z, -3);
}

TEST(Vec3Test, OperatorPlus) {
    Vec3 v1(1, 2, 3);
    Vec3 v2(4, 5, 6);
    Vec3 res = v1 + v2;

    EXPECT_EQ(res.x, 5);
    EXPECT_EQ(res.y, 7);
    EXPECT_EQ(res.z, 9);
}

TEST(Vec3Test, OperatorMinus) {
    Vec3 v1(10, 20, 30);
    Vec3 v2(1, 2, 3);
    Vec3 res = v1 - v2;

    EXPECT_EQ(res.x, 9);
    EXPECT_EQ(res.y, 18);
    EXPECT_EQ(res.z, 27);
}

TEST(Vec3Test, OperatorMinusNegativeResult) {
    Vec3 v1(0, 0, 0);
    Vec3 v2(1, 1, 1);
    Vec3 res = v1 - v2;

    EXPECT_EQ(res.x, -1);
    EXPECT_EQ(res.y, -1);
    EXPECT_EQ(res.z, -1);
}

TEST(Vec3Test, OperatorAssignment) {
    Vec3 v1(100, 200, 300);
    Vec3 v2;
    
    v2 = v1;

    EXPECT_EQ(v2.x, 100);
    EXPECT_EQ(v2.y, 200);
    EXPECT_EQ(v2.z, 300);

    v1.x = 0;
    EXPECT_EQ(v2.x, 100);
}

TEST(Vec3Test, OperatorAssignmentSelf) {
    Vec3 v1(5, 5, 5);
    v1 = v1;
    EXPECT_EQ(v1.x, 5);
}

TEST(Vec3Test, OperatorPlusEquals) {
    Vec3 v1(1, 1, 1);
    Vec3 v2(2, 2, 2);
    
    v1 += v2;

    EXPECT_EQ(v1.x, 3);
    EXPECT_EQ(v1.y, 3);
    EXPECT_EQ(v1.z, 3);

    EXPECT_EQ(v2.x, 2);
}

TEST(Vec3Test, OperatorMinusEquals) {
    Vec3 v1(5, 5, 5);
    Vec3 v2(1, 1, 1);
    
    v1 -= v2;

    EXPECT_EQ(v1.x, 4);
    EXPECT_EQ(v1.y, 4);
    EXPECT_EQ(v1.z, 4);
}

TEST(Vec3Test, ChainedOperations) {
    Vec3 v1(1, 1, 1);
    Vec3 v2(1, 1, 1);
    Vec3 v3(1, 1, 1);

    (v1 += v2) += v3;

    EXPECT_EQ(v1.x, 3);
    EXPECT_EQ(v1.y, 3);
    EXPECT_EQ(v1.z, 3);
}