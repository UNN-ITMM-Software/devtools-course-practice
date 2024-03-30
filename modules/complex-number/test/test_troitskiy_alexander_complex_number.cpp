// Copyright 2024 Troitskiy Alexander

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Troitskiy_Alexander_ComplexNumberTest, ConstructorAndGetters) {
    ComplexNumber z1;
    EXPECT_DOUBLE_EQ(z1.getRe(), 0.0);
    EXPECT_DOUBLE_EQ(z1.getIm(), 0.0);

    ComplexNumber z2(3.0, -4.0);
    EXPECT_DOUBLE_EQ(z2.getRe(), 3.0);
    EXPECT_DOUBLE_EQ(z2.getIm(), -4.0);

    ComplexNumber z3(z2);
    EXPECT_DOUBLE_EQ(z3.getRe(), 3.0);
    EXPECT_DOUBLE_EQ(z3.getIm(), -4.0);

    z1.setRe(2.5);
    z1.setIm(1.5);
    EXPECT_DOUBLE_EQ(z1.getRe(), 2.5);
    EXPECT_DOUBLE_EQ(z1.getIm(), 1.5);
}
TEST(Troitskiy_Alexander_ComplexNumberAdditionTest, Addition) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);

    ComplexNumber sum = z1 + z2;
    EXPECT_DOUBLE_EQ(sum.getRe(), 4.0);
    EXPECT_DOUBLE_EQ(sum.getIm(), 6.0);
}

TEST(Troitskiy_Alexander_ComplexNumberSubtractionTest, Subtraction) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);

    ComplexNumber difference = z1 - z2;
    EXPECT_DOUBLE_EQ(difference.getRe(), -2.0);
    EXPECT_DOUBLE_EQ(difference.getIm(), -2.0);
}

TEST(Troitskiy_Alexander_ComplexNumberMultiplicationTest, Multiplication) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);

    ComplexNumber multiplication = z1 * z2;
    EXPECT_DOUBLE_EQ(multiplication.getRe(), -5.0);
    EXPECT_DOUBLE_EQ(multiplication.getIm(), 10.0);
}

TEST(Troitskiy_Alexander_ComplexNumberDivisionTest, Division) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);

    ComplexNumber division = z1 / z2;
    EXPECT_DOUBLE_EQ(division.getRe(), 0.44);
    EXPECT_DOUBLE_EQ(division.getIm(), 0.08);
}
TEST(Troitskiy_Alexander_ComplexNumberAdditionTest, AdditionWithFractions) {
    ComplexNumber z1(1.5, 2.5);
    ComplexNumber z2(3.5, 4.5);

    ComplexNumber sum = z1 + z2;
    EXPECT_DOUBLE_EQ(sum.getRe(), 5.0);
    EXPECT_DOUBLE_EQ(sum.getIm(), 7.0);
}

TEST(Troitskiy_Alexander_ComplexNumberSubTest, SubWithFractions) {
    ComplexNumber z1(2.5, 3.5);
    ComplexNumber z2(1.5, 2.5);

    ComplexNumber difference = z1 - z2;
    EXPECT_DOUBLE_EQ(difference.getRe(), 1.0);
    EXPECT_DOUBLE_EQ(difference.getIm(), 1.0);
}

TEST(Troitskiy_Alexander_ComplexNumberMultTest, MultWithFractions) {
    ComplexNumber z1(1.5, 2.5);
    ComplexNumber z2(3.5, 4.5);

    ComplexNumber multiplication = z1 * z2;
    EXPECT_DOUBLE_EQ(multiplication.getRe(), -6);
    EXPECT_DOUBLE_EQ(multiplication.getIm(), 15.5);
}

TEST(Troitskiy_Alexander_ComplexNumberDivisionTest, DivisionWithFractions) {
    ComplexNumber z1(1.5, 2.5);
    ComplexNumber z2(3.0, 2.0);

    ComplexNumber division = z1 / z2;
    EXPECT_NEAR(division.getRe(), 0.73, 0.01);
    EXPECT_NEAR(division.getIm(), 0.34, 0.01);
}
