// Copyright 2024 Kulikov Artem

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kulikov_Artem_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Kulikov_Artem_ComplexNumberTest, Can_Sum_Two_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 5.0;
    double re2 = 3.0;
    double im2 = 2.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_EQ(re1 + re2, z.getRe());
    EXPECT_EQ(im1 + im2, z.getIm());
}

TEST(Kulikov_Artem_ComplexNumberTest, Can_Subtract_Two_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 5.0;
    double re2 = 3.0;
    double im2 = 2.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z = z1 - z2;

    // Assert
    EXPECT_EQ(re1 - re2, z.getRe());
    EXPECT_EQ(im1 - im2, z.getIm());
}

TEST(Kulikov_Artem_ComplexNumberTest, Can_Multiply_Two_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 5.0;
    double re2 = 3.0;
    double im2 = 2.28;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_EQ((re1 * re2) - (im1 * im2), z.getRe());
    EXPECT_EQ((re1 * im2) + (re2 * im1), z.getIm());
}

TEST(Kulikov_Artem_ComplexNumberTest, Can_Divide_Two_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 5.0;
    double re2 = 3.0;
    double im2 = 2.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z = z1 / z2;

    // Assert
    double denom = re2 * re2 + im2 * im2;
    EXPECT_DOUBLE_EQ((re1 * re2 + im1 * im2) / denom, z.getRe());
    EXPECT_DOUBLE_EQ((im1 * re2 - re1 * im2) / denom, z.getIm());
}

TEST(Kulikov_Artem_ComplexNumberTest, Cant_Divide_By_Zero) {
    // Arrange
    double re1 = 5.0;
    double im1 = 6.9;
    double re2 = 0.0;
    double im2 = 0.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act & Assert
    EXPECT_THROW(z1 / z2, std::string);
}
