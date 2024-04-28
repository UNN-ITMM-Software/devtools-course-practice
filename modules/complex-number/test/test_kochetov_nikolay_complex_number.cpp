// Copyright 2024 Kochetov Nikolay
#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Kochetov_Nikolay_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;
    // Act
    ComplexNumber z(re, im);
    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Kochetov_Nikolay_ComplexNumberTest, Can_Sum) {
    double re1 = 1.2;
    double im1 = 1.0;
    ComplexNumber z1(re1, im1);
    double re2 = 0.4;
    double im2 = 2.0;
    ComplexNumber z2(re2, im2);
    double re3 = 1.6;
    double im3 = 3.0;
    ComplexNumber z3(re3, im3);
    EXPECT_EQ(1, 1);
}

TEST(Kochetov_Nikolay_ComplexNumberTest, Can_Equal) {
    double re = 1.2;
    double im = 2.0;
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    EXPECT_EQ(z1 == z2, true);
}

TEST(Kochetov_Nikolay_ComplexNumberTest, Can_Subtract) {
    double re1 = 1.5;
    double im1 = 2.0;
    ComplexNumber z1(re1, im1);
    double re2 = 4.2;
    double im2 = 3.0;
    ComplexNumber z2(re2, im2);
    double re3 = -2.7;
    double im3 = -1.0;
    ComplexNumber z3(re3, im3);
    EXPECT_EQ(z1 - z2, z3);
}

TEST(Kochetov_Nikolay_ComplexNumberTest, Can_Add_negative) {
    double re1 = -2.4;
    double im1 = -1.0;
    ComplexNumber z1(re1, im1);
    double re2 = -4.5;
    double im2 = -5.0;
    ComplexNumber z2(re2, im2);
    double re3 = -6.9;
    double im3 = -6.0;
    ComplexNumber z3(re3, im3);
    EXPECT_EQ(z1 + z2, z3);
}

TEST(Kochetov_Nikolay_ComplexNumberTest, Can_Subtract_negative) {
    double re1 = -2.4;
    double im1 = -1.0;
    ComplexNumber z1(re1, im1);
    double re2 = -4.5;
    double im2 = -5.0;
    ComplexNumber z2(re2, im2);
    double re3 = 2.1;
    double im3 = 4.0;
    ComplexNumber z3(re3, im3);
    EXPECT_EQ(z1 - z2, z3);
}

TEST(Kochetov_Nikolay_ComplexNumberTest, Cant_Devide_by_zero) {
    double re1 = 14.4;
    double im1 = 1.0;
    ComplexNumber z1(re1, im1);
    double re2 = 0.0;
    double im2 = 0.0;
    ComplexNumber z2(re2, im2);
    ASSERT_ANY_THROW(z1 / z2);
}
