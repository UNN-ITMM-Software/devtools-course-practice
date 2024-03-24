// Copyright 2024 Ivanchenko Aleksei

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Ivanchenko_Aleksei_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
TEST(Ivanchenko_Aleksei_ComplexNumberTest, Can_Set_And_Get) {
    // Arrange
    double re = 1.0;
    double im = 2.0;

    // Act
    ComplexNumber z(0, 0);
    z.setRe(1);
    z.setIm(2);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
TEST(Ivanchenko_Aleksei_ComplexNumberTest, Can_Add) {
    // Arrange
    double re1 = 1.0, re2 = 3.0;
    double im1 = 2.0, im2 = -4.0;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_EQ(re1 + re2, z.getRe());
    EXPECT_EQ(im1 + im2, z.getIm());
}
TEST(Ivanchenko_Aleksei_ComplexNumberTest, Can_Subtract) {
    // Arrange
    double re1 = 1.0, re2 = 3.0;
    double im1 = 2.0, im2 = -4.0;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 - z2;

    // Assert
    EXPECT_EQ(re1 - re2, z.getRe());
    EXPECT_EQ(im1 - im2, z.getIm());
}
TEST(Ivanchenko_Aleksei_ComplexNumberTest, Can_Multiply) {
    // Arrange
    double re1 = 1.0, re2 = 3.0;
    double im1 = 2.0, im2 = -4.0;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_EQ(re1 * re2 - im1 * im2, z.getRe());
    EXPECT_EQ(re1 * im2 + re2 * im1, z.getIm());
}