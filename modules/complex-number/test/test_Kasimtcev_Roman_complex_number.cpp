// Copyright 2024 Kasimtcev Roman

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kasimtcev_Roman_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
TEST(Kasimtcev_Roman_ComplexNumberTest, Can_Complex_Add) {
    // Arrange
    double re1 = 5.0, re2 = 3.0;
    double im1 = 3.0, im2 = 5.0;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_EQ(re1 + re2, z.getRe());
    EXPECT_EQ(im1 + im2, z.getIm());
}
TEST(Kasimtcev_Roman_ComplexNumberTest, Can_Complex_Subtract) {
    // Arrange
    double re1 = 3.0, re2 = 5.0;
    double im1 = 5.0, im2 = 3.0;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 - z2;

    // Assert
    EXPECT_EQ(re1 - re2, z.getRe());
    EXPECT_EQ(im1 - im2, z.getIm());
}
TEST(Kasimtcev_Roman_ComplexNumberTest, Can_Complex_Multiply) {
    // Arrange
    double re1 = 5.0, re2 = -7.0;
    double im1 = -7.0, im2 = 5.0;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_EQ(re1 * re2 - im1 * im2, z.getRe());
    EXPECT_EQ(re1 * im2 + re2 * im1, z.getIm());
}
TEST(Kasimtcev_Roman_ComplexNumberTest, Can_Complex_Divide) {
    // Arrange
    double re1 = 100.0, re2 = 1.0;
    double im1 = 2.0, im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 / z2;

    // Assert
    EXPECT_EQ(re1, z.getRe());
    EXPECT_EQ(im1, z.getIm());
}
TEST(Kasimtcev_Roman_ComplexNumberTest, Can_Complex_Multiply_Drob) {
    // Arrange
    double re1 = 1.1, re2 = 3.3;
    double im1 = 2.2, im2 = -4.4;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_DOUBLE_EQ(re1 * re2 - im1 * im2, z.getRe());
    EXPECT_DOUBLE_EQ(re1 * im2 + re2 * im1, z.getIm());
}
TEST(Kasimtcev_Roman_ComplexNumberTest, Can_Complex_Divide_Drob) {
    // Arrange
    double re1 = 100.7, re2 = 0.5;
    double im1 = 2.9, im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 / z2;

    // Assert
    EXPECT_DOUBLE_EQ(re1 / re2, z.getRe());
    EXPECT_DOUBLE_EQ(im1 / re2, z.getIm());
}
TEST(Kasimtcev_Roman_ComplexNumberTestt, Can_Complex_Divide_Drob_By_Zero) {
    // Arrange
    double re = 2.5;
    double im = 3.1;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(0.0, 0.0);

    // Assert
    ASSERT_ANY_THROW(z1 / z2);
}


