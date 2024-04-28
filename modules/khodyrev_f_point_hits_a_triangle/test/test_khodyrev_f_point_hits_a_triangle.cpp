// Copyright 2024 Khodyrev Fedor

#include <gtest/gtest.h>

#include "include/point_hits_a_triangle.h"

TEST(Khodyrev_Fedor_Point_Hits_A_Triangle, Invalid_Input_Data) {
    Point v1(0, 1);
    Point v2(0, 2);
    Point v3(0, 3);

    Triangle triangle(v1, v2, v3);
    EXPECT_ANY_THROW(triangle.isValid());
}

TEST(Khodyrev_Fedor_Point_Hits_A_Triangle, Validation_Test) {
    Point v1(0, 0);
    Point v2(6, 2);
    Point v3(4, 6);

    Triangle triangle(v1, v2, v3);
    EXPECT_EQ(triangle.isValid(), true);
}

TEST(Khodyrev_Fedor_Point_Hits_A_Triangle, Right_Angled_Triangle_Test) {
    Point v1(0, 0);
    Point v2(0, 4);
    Point v3(3, 0);

    Triangle triangle(v1, v2, v3);
    Point point(1, 1);

    EXPECT_EQ(triangle.isInside(point), true);
}

TEST(Khodyrev_Fedor_Point_Hits_A_Triangle, Isosceles_Triangle_Test) {
    Point v1(0, 0);
    Point v2(4, 0);
    Point v3(2, 3);

    Triangle triangle(v1, v2, v3);
    Point point(2, 2);

    EXPECT_EQ(triangle.isInside(point), true);
}

TEST(Khodyrev_Fedor_Point_Hits_A_Triangle, Point_Is_Not_In_Triangle) {
    Point v1(0, 0);
    Point v2(4, 0);
    Point v3(2, 3);

    Triangle triangle(v1, v2, v3);
    Point point(10, 10);

    EXPECT_EQ(triangle.isInside(point), false);
}

TEST(Khodyrev_Fedor_Point_Hits_A_Triangle, Point_Is_Top) {
    Point v1(0, 0);
    Point v2(4, 0);
    Point v3(2, 3);

    Triangle triangle(v1, v2, v3);
    Point point(0, 0);

    EXPECT_EQ(triangle.isInside(point), true);
}

TEST(Khodyrev_Fedor_Point_Hits_A_Triangle, Check_Equality_Operator) {
    Point v1(0, 1);
    Point v2(0, 1);
    Point v3(1, 0);

    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v2 == v3);
}
