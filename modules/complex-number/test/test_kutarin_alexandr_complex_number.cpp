// Copyright 2024 Kutarin Alexandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kutarin_Alexandr_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    // Assert

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Kutarin_Alexandr_ComplexNumberTest, Can_Get_Input_Data) {
    // Arrange
    double expectedRe = 1.4;
    double expectedIm = 2.7;
    ComplexNumber z(expectedRe, expectedIm);

    // Act & Assert
    EXPECT_EQ(expectedRe, z.getRe());
    EXPECT_EQ(expectedIm, z.getIm());
}

TEST(Kutarin_Alexandr_ComplexNumberTest, Can_Sum) {
    double re1 = 1.4;
    double im1 = 1.1;
    ComplexNumber z1(re1, im1);
    double re2 = 0.4;
    double im2 = 2.7;
    ComplexNumber z2(re2, im2);
    double re3 = 1.4;
    double im3 = 3.6;
    ComplexNumber z3(re3, im3);
    EXPECT_EQ(1, 1);
}

TEST(Kutarin_Alexandr_ComplexNumberTest, Can_Add_Negative_Numbers) {
    // Arrange
    double re1 = -1.4;
    double im1 = -1.1;
    double re2 = -0.4;
    double im2 = -2.7;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    double expectedRe = re1 + re2;
    double expectedIm = im1 + im2;

    // Act
    ComplexNumber result = z1 + z2;

    // Assert
    EXPECT_EQ(expectedRe, result.getRe());
    EXPECT_EQ(expectedIm, result.getIm());
}

TEST(Kutarin_Alexandr_ComplexNumberTest, Can_Subtract_Negative_Numbers) {
    // Arrange
    double re1 = -1.4;
    double im1 = -1.1;
    double re2 = -0.4;
    double im2 = -2.7;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    double expectedRe = re1 - re2;
    double expectedIm = im1 - im2;

    // Act
    ComplexNumber result = z1 - z2;

    // Assert
    EXPECT_EQ(expectedRe, result.getRe());
    EXPECT_EQ(expectedIm, result.getIm());
}

TEST(Kutarin_Alexandr_ComplexNumberTest, Cant_Devide_by_zero) {
    double re1 = 9.3;
    double im1 = 1.0;
    ComplexNumber z1(re1, im1);
    double re2 = 0.0;
    double im2 = 0.0;
    ComplexNumber z2(re2, im2);
    ASSERT_ANY_THROW(z1 / z2);
}

TEST(Kutarin_Alexandr_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange
    double re1 = 1.4;
    double im1 = 1.1;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(0.0, 0.0);
    double expectedRe = 0.0;
    double expectedIm = 0.0;

    // Act
    ComplexNumber result = z1 * z2;

    // Assert
    EXPECT_EQ(expectedRe, result.getRe());
    EXPECT_EQ(expectedIm, result.getIm());
}
