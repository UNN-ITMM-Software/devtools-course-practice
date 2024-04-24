// Copyright 2024 Musaev Ilgar

#include <gtest/gtest.h>
#include <tuple>
#include "include/complex_number.h"

TEST(Musaev_Ilgar_ComplexNumberAdditionTest, Addition) {
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(4.0, 6.0);
    ComplexNumber sum = z1 + z2;
    EXPECT_DOUBLE_EQ(sum.getRe(), 5.0);
    EXPECT_DOUBLE_EQ(sum.getIm(), 8.0);
}

TEST(Musaev_Ilgar_ComplexNumberSubtractionTest, Subtraction) {
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(4.0, 6.0);
    ComplexNumber difference = z1 - z2;
    EXPECT_DOUBLE_EQ(difference.getRe(), -1.0);
    EXPECT_DOUBLE_EQ(difference.getIm(), -3.0);
}

TEST(Musaev_Ilgar_ComplexNumberMultiplicationTest, Multiplication) {
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(5.0, 6.0);
    ComplexNumber multiplication = z1 * z2;
    EXPECT_DOUBLE_EQ(multiplication.getRe(), -3.0);
    EXPECT_DOUBLE_EQ(multiplication.getIm(), 12.0);
}

TEST(Musaev_Ilgar_ComplexNumberDivisionTest, Division) {
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(5.0, 6.0);
    ComplexNumber division = z1 / z2;
    EXPECT_DOUBLE_EQ(division.getRe(), 0.84);
    EXPECT_DOUBLE_EQ(division.getIm(), 0.18);
}

TEST(Musaev_Ilgar_ComplexNumberAdditionTest, AdditionWithFractions) {
    ComplexNumber z1(2.5, 3.5);
    ComplexNumber z2(4.5, 5.5);
    ComplexNumber sum = z1 + z2;
    EXPECT_DOUBLE_EQ(sum.getRe(), 6.0);
    EXPECT_DOUBLE_EQ(sum.getIm(), 8.0);
}

TEST(Musaev_Ilgar_ComplexNumberSubTest, SubWithFractions) {
    ComplexNumber z1(5.5, 8.5);
    ComplexNumber z2(6.5, 7.5);
    ComplexNumber difference = z1 - z2;
    EXPECT_DOUBLE_EQ(difference.getRe(), 2.0);
    EXPECT_DOUBLE_EQ(difference.getIm(), 2.0);
}
