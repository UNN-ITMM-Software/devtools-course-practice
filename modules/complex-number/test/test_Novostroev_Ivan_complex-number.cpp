// Copyright 2024 Novostroev Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Novostroev_Ivan_ComplexNumberTest, Divide_By_Zero) {
    double re1 = 1.8, im1 = 2.3;
    double re2 = 0.0, im2 = 0.0;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_THROW(z1 / z2, std::string);
}

TEST(Novostroev_Ivan_ComplexNumberTest, Multiply_ComplexNumbers) {
    double re1 = 2.1, im1 = 1.2;
    double re2 = 4.1, im2 = 3.1;

    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber res = z1 * z2;

    ASSERT_EQ(re1 * re2 - im1 * im2, res.getRe());
    ASSERT_EQ(re1 * im2 + re2 * im1, res.getIm());
}

TEST(Novostroev_Ivan_ComplexNumberTest, Divide_ComplexNumbers) {
    double re1 = 4.2, im1 = 3.6;
    double re2 = 3.9, im2 = 2.1;

    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber res = z1 / z2;

    ASSERT_EQ((re1*re2 + im1*im2) / (re2*re2 + im2*im2), res.getRe());
    ASSERT_EQ((im1*re2 - re1*im2) / (re2*re2 + im2*im2), res.getIm());
}

TEST(Novostroev_Ivan_ComplexNumberTest, Check_Equality) {
    double re1 = 2.2, im1 = 1.5;
    double re2 = 2.2, im2 = 1.5;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_TRUE(z1 == z2);
}

TEST(Novostroev_Ivan_ComplexNumberTest, Add) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3 = z1 + z2;

    ASSERT_EQ(z3.getRe(), 4);
    ASSERT_EQ(z3.getIm(), 6);
}

TEST(Novostroev_Ivan_ComplexNumberTest, Subtract) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3 = z1 - z2;

    ASSERT_EQ(z3.getRe(), -2);
    ASSERT_EQ(z3.getIm(), -2);
}

TEST(Novostroev_Ivan_ComplexNumberTest, Compare) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3(1, 2);

    ASSERT_TRUE(z1 == z3);
    ASSERT_TRUE(z1 != z2);
}

TEST(Novostroev_Ivan_ComplexNumberTest, Change) {
    ComplexNumber z1(1, 2);
    z1.setRe(3);
    z1.setIm(4);

    ASSERT_EQ(z1.getRe(), 3);
    ASSERT_EQ(z1.getIm(), 4);
}

TEST(Novostroev_Ivan_ComplexNumberTest, Create_Copy) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(z1);

    ASSERT_TRUE(z1 == z2);
}

TEST(Novostroev_Ivan_ComplexNumberTest, Create_Default) {
    ComplexNumber z1;

    ASSERT_EQ(z1.getRe(), 0);
    ASSERT_EQ(z1.getIm(), 0);
}

TEST(Novostroev_Ivan_ComplexNumberTest, DivisionOperatorWithFractions) {
    ComplexNumber z1(2.25, 5.25);
    ComplexNumber z2(-2.25, 5.25);

    ComplexNumber z3 = z1 / z2;

    ASSERT_NEAR(z3.getRe(), 0.6, 0.1);
    ASSERT_NEAR(z3.getIm(), -0.7, 0.1);
    ASSERT_ANY_THROW(ComplexNumber() / ComplexNumber());
}
