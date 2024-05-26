// Copyright 2024 Bodrov Daniil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bodrov_Daniil_ComplexNumberTest, Can_Check_Equality_Between_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 5.0;
    double re2 = 5.0;
    double im2 = 5.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act & Assert
    EXPECT_TRUE(z1 == z2);
}

TEST(Bodrov_Daniil_ComplexNumberTest, Can_Check_Inequality_Between_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 5.0;
    double re2 = 10.0;
    double im2 = 5.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act & Assert
    EXPECT_TRUE(z1 != z2);
}

TEST(Bodrov_Daniil_ComplexNumberTest, Can_Get_Real_Part_Of_Number) {
    // Arrange
    double re = 3.0;
    double im = 2.0;

    ComplexNumber z(re, im);

    // Act & Assert
    EXPECT_EQ(re, z.getRe());
}

TEST(Bodrov_Daniil_ComplexNumberTest, Can_Get_Imaginary_Part_Of_Number) {
    // Arrange
    double re = 3.0;
    double im = 2.0;

    ComplexNumber z(re, im);

    // Act & Assert
    EXPECT_EQ(im, z.getIm());
}

TEST(Bodrov_Daniil_ComplexNumberTest, Can_Sum_Two_Numbers) {
    // Arrange
    double re1 = 8.0;
    double im1 = 2.5;
    double re2 = 3.5;
    double im2 = 1.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_EQ(re1 + re2, z.getRe());
    EXPECT_EQ(im1 + im2, z.getIm());
}

TEST(Bodrov_Daniil_ComplexNumberTest, Can_Subtract_Two_Numbers) {
    // Arrange
    double re1 = 8.0;
    double im1 = 2.5;
    double re2 = 3.5;
    double im2 = 1.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z = z1 - z2;

    // Assert
    EXPECT_EQ(re1 - re2, z.getRe());
    EXPECT_EQ(im1 - im2, z.getIm());
}

TEST(Bodrov_Daniil_ComplexNumberTest, Can_Multiply_Two_Numbers) {
    // Arrange
    double re1 = 8.0;
    double im1 = 2.5;
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

TEST(Bodrov_Daniil_ComplexNumberTest, Can_Divide_Two_Numbers) {
    // Arrange
    double re1 = 8.0;
    double im1 = 2.5;
    double re2 = 4.0;
    double im2 = 1.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z = z1 / z2;

    // Assert
    double denom = re2 * re2 + im2 * im2;
    EXPECT_DOUBLE_EQ((re1 * re2 + im1 * im2) / denom, z.getRe());
    EXPECT_DOUBLE_EQ((im1 * re2 - re1 * im2) / denom, z.getIm());
}

TEST(Bodrov_Daniil_ComplexNumberTest, Cant_Divide_By_Zero) {
    // Arrange
    double re1 = 8.0;
    double im1 = 2.5;
    double re2 = 0.0;
    double im2 = 0.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act & Assert
    EXPECT_THROW(z1 / z2, std::string);
}
