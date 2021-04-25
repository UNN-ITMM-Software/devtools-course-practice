// Copyright 2021 Belik Julia

#include <gtest/gtest.h>
#include <utility>

#include "include/TrianglePoint.h"

TEST(TrianglePoint, Can_Create_Triangle) {
    std::pair<double, double>  a(0, 5);
    std::pair<double, double>  b(5, 0);
    std::pair<double, double>  c(0, 0);
    ASSERT_NO_THROW(Triangle(a, b, c));
}

TEST(TrianglePoint, Point_In) {
    std::pair<double, double>  a(0, 5);
    std::pair<double, double>  b(5, 0);
    std::pair<double, double>  c(0, 0);
    std::pair<double, double>  x(1, 1);
    bool tmp;
    Triangle tr(a, b, c);
    tmp = tr.isInside(x);
    ASSERT_EQ(true, tmp);
}

TEST(TrianglePoint, Point_Out) {
    std::pair<double, double>  a(0, 5);
    std::pair<double, double>  b(5, 0);
    std::pair<double, double>  c(0, 0);
    std::pair<double, double>  x(-1, -1);
    bool tmp;
    Triangle tr(a, b, c);
    tmp = tr.isInside(x);
    ASSERT_EQ(false, tmp);
}

TEST(TrianglePoint, Point_On_Side) {
    std::pair<double, double>  a(0, 5);
    std::pair<double, double>  b(5, 0);
    std::pair<double, double>  c(0, 0);
    std::pair<double, double>  x(0, 1);
    bool tmp;
    Triangle tr(a, b, c);
    tmp = tr.isInside(x);
    ASSERT_EQ(false, tmp);
}

TEST(TrianglePoint, Test_Line) {
    std::pair<double, double>  a(0, 5);
    std::pair<double, double>  b(0, 2);
    std::pair<double, double>  c(0, 0);
    std::pair<double, double>  x(0, 1);
    bool tmp;
    Triangle tr(a, b, c);
    tmp = tr.isInside(x);
    ASSERT_EQ(false, tmp);
}
