// Copyright 2021 Paranicheva Alyona

#include <gtest/gtest.h>

#include <cmath>

#include <iostream>
#include <utility>

#include "include/triangle.h"

TEST(Params_Triangle, Create_Triangle) {
    std::pair<double, double>  a(2.5, 0);
    std::pair<double, double>  b(0, 4.5);
    std::pair<double, double>  c(-1.5, 0);
    ASSERT_NO_THROW(Triangle(a, b, c));
}

TEST(Params_Triangle, Calculate_SideAB) {
    std::pair<double, double>  a(0, 0);
    std::pair<double, double>  b(0, 4);
    std::pair<double, double>  c(3, 0);
    Triangle tr(a, b, c);
    double sideAB = tr.SideAB();
    ASSERT_DOUBLE_EQ(4.0, sideAB);
}

TEST(Params_Triangle, Calculate_SideBC) {
    std::pair<double, double>  a(0, 0);
    std::pair<double, double>  b(0, 4);
    std::pair<double, double>  c(3, 0);
    Triangle tr(a, b, c);
    double sideBC = tr.SideBC();
    ASSERT_DOUBLE_EQ(5.0, sideBC);
}

TEST(Params_Triangle, Calculate_SideAC) {
    std::pair<double, double>  a(0, 0);
    std::pair<double, double>  b(0, 4);
    std::pair<double, double>  c(3, 0);
    Triangle tr(a, b, c);
    double sideAC = tr.SideAC();
    ASSERT_DOUBLE_EQ(3.0, sideAC);
}

TEST(Params_Triangle, Calculate_Perimeter) {
    std::pair<double, double>  a(0, 0);
    std::pair<double, double>  b(0, 4);
    std::pair<double, double>  c(3, 0);
    Triangle tr(a, b, c);
    double Perimeter = tr.Perimeter();
    ASSERT_DOUBLE_EQ(12.0, Perimeter);
}

TEST(Params_Triangle, Calculate_Area) {
    std::pair<double, double>  a(0, 0);
    std::pair<double, double>  b(0, 4);
    std::pair<double, double>  c(3, 0);
    Triangle tr(a, b, c);
    double Area = tr.Area();
    ASSERT_DOUBLE_EQ(6.0, Area);
}
