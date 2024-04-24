// Copyright 2024 Musaev Ilgar

#include <gtest/gtest.h>
#include <tuple>
#include "include/complex_number.h"

TEST(Musaev_Ilgar_ComplexNumberAdditionTest, Addition) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3 = z1 + z2;
    ASSERT_EQ(z3.getRe(), 4);
    ASSERT_EQ(z3.getIm(), 6);
}

TEST(Musaev_Ilgar_ComplexNumberSubtractionTest, Subtraction) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3 = z1 - z2;
    ASSERT_EQ(z3.getRe(), -2);
    ASSERT_EQ(z3.getIm(), -2);
}

TEST(Musaev_Ilgar_ComplexNumberMultiplicationTest, Multiplication) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3 = z1 * z2;
    ASSERT_EQ(z3.getRe(), -5);
    ASSERT_EQ(z3.getIm(), 10);
}

TEST(Musaev_Ilgar_ComplexNumberSubTest, SumWithFractions) {
    ComplexNumber z1(3.25, 4.75);
    ComplexNumber z2(-3.25, 4.75);
    ComplexNumber z3 = z1 + z2;
    ASSERT_DOUBLE_EQ(z3.getRe(), 0.0);
    ASSERT_DOUBLE_EQ(z3.getIm(), 9.5);
}

TEST(Musaev_Ilgar_ComplexNumberDivisionTest, Division) {
    ComplexNumber z1(2.25, 5.25);
    ComplexNumber z2(-2.25, 5.25);
    ComplexNumber z3 = z1 / z2;
    ASSERT_NEAR(z3.getRe(), 0.6, 0.1);
    ASSERT_NEAR(z3.getIm(), -0.7, 0.1);
}
