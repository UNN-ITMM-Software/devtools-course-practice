// Copyright 2024 Platonova Maria
#include <gtest/gtest.h>
#include "include/Triangle.h"

TEST(TriangleTest, SideLengthCalculation) {
    Triangle triangle(0, 0, 3, 4, 0, 0);
    EXPECT_DOUBLE_EQ(triangle.sideLength(0, 0, 3, 4), 5);
    EXPECT_DOUBLE_EQ(triangle.sideLength(3, 4, 6, 8), 5);
}

TEST(TriangleTest, PerimeterCalculation) {
    Triangle triangle(0, 0, 3, 4, 6, 0);
    EXPECT_NEAR(triangle.perimeter(), 16.4953, 0.0001);
}

TEST(TriangleTest, AreaCalculation) {
    Triangle triangle1(0, 0, 3, 0, 3, 4);
    Triangle triangle2(0, 0, 3, 4, 6, 0);
    EXPECT_NEAR(triangle1.area(), 6, 0.0001);
    EXPECT_NEAR(triangle2.area(), 12, 0.0001);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}