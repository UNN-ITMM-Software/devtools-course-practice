// Copyright 2024 Nikitin Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(test_nikitin_kirill_complex_number, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(test_nikitin_kirill_complex_number, Can_Divide_By_Zero) {
    // Arrange
    double re = 5.0;
    double im = 10.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber zero(0.0, 0.0);

    // Assert
    EXPECT_THROW(z / zero, std::string);
}

TEST(test_nikitin_kirill_complex_number, Can_Subtract_Negative_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 10.0;
    double re2 = -3.0;
    double im2 = -7.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber result = z1 - z2;

    // Assert
    EXPECT_EQ(re1 - re2, result.getRe());
    EXPECT_EQ(im1 - im2, result.getIm());
}

TEST(test_nikitin_kirill_complex_number, Can_Add_Negative_Numbers) {
    // Arrange
    double re1 = -5.0;
    double im1 = -10.0;
    double re2 = -3.0;
    double im2 = -7.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber result = z1 + z2;

    // Assert
    EXPECT_EQ(re1 + re2, result.getRe());
    EXPECT_EQ(im1 + im2, result.getIm());
}

TEST(test_nikitin_kirill_complex_number, Can_Subtract_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 10.0;
    double re2 = 3.0;
    double im2 = 7.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber result = z1 - z2;

    // Assert
    EXPECT_EQ(re1 - re2, result.getRe());
    EXPECT_EQ(im1 - im2, result.getIm());
}

TEST(test_nikitin_kirill_complex_number, Can_Add_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 10.0;
    double re2 = 3.0;
    double im2 = 7.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber result = z1 + z2;

    // Assert
    EXPECT_EQ(re1 + re2, result.getRe());
    EXPECT_EQ(im1 + im2, result.getIm());
}

TEST(test_nikitin_kirill_complex_number, Can_Find_Sum_Of_Two_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 10.0;
    double re2 = 3.0;
    double im2 = 7.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber result = z1 + z2;

    // Assert
    double expected_re = re1 + re2;
    double expected_im = im1 + im2;
    EXPECT_EQ(expected_re, result.getRe());
    EXPECT_EQ(expected_im, result.getIm());
}

TEST(test_nikitin_kirill_complex_number, Can_Compare_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 10.0;
    double re2 = 3.0;
    double im2 = 7.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_TRUE(z1 == z1);
    EXPECT_FALSE(z1 == z2);
}
