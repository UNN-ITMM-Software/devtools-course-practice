// Copyright 2021 Skripal Andrey

#include <gtest/gtest.h>
#include <utility>
#include "include/intersection_line.h"

TEST(Intersection_line, Check_intersect) {
    int a = 1;
    int b = 2;
    int c = 0;
    int d = -3;
    std::pair<int, int>  x(1, 1);
    std::pair<int, int>  y(2, 2);
    Line l(x, y);
    ASSERT_NO_THROW(l.intersect(a, b, c, d));
}

TEST(Intersection_line, Check_area) {
    std::pair<int, int>  a(2, 5);
    std::pair<int, int>  b(4, 8);
    std::pair<int, int>  c(2, 2);
    std::pair<int, int>  x(1, 1);
    std::pair<int, int>  y(2, 2);
    Line l(x, y);
    ASSERT_NO_THROW(l.area(a, b, c));
}

TEST(Intersection_line, Check_constructor) {
    std::pair<int, int>  a(5, 5);
    std::pair<int, int>  b(5, 8);
    ASSERT_NO_THROW(Line(a, b));
}

TEST(Intersection_line, Intersect_true) {
    std::pair<int, int>  a(0, 4);
    std::pair<int, int>  b(4, 0);
    std::pair<int, int>  c(1, 1);
    std::pair<int, int>  d(8, 9);
    Line l1(a, b);
    Line l2(c, d);
    bool tmp = l1.intersection(l2);
    ASSERT_EQ(true, tmp);
}

TEST(Intersection_line, Intersect_false) {
    std::pair<int, int>  a(0, 5);
    std::pair<int, int>  b(5, 10);
    std::pair<int, int>  c(0, 0);
    std::pair<int, int>  d(-4, 9);
    Line l1(a, b);
    Line l2(c, d);
    bool tmp = l1.intersection(l2);
    ASSERT_EQ(false, tmp);
}

TEST(Intersection_line, Bounding_box) {
    std::pair<int, int>  a(0, 5);
    std::pair<int, int>  b(5, 0);
    std::pair<int, int>  c(-1, 6);
    std::pair<int, int>  d(-3, 8);
    Line l1(a, b);
    Line l2(c, d);
    bool tmp = l1.intersection(l2);
    ASSERT_EQ(false, tmp);
}

TEST(Intersection_line, Equal_line) {
    std::pair<int, int>  a(0, 5);
    std::pair<int, int>  b(10, 0);
    Line l1(a, b);
    Line l2(a, b);
    bool tmp = l1.intersection(l2);
    ASSERT_EQ(true, tmp);
}
