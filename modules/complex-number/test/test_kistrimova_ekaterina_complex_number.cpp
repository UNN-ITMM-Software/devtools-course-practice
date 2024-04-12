// Copyright 2024 Kistrimova Ekaterina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kistrimova_Ekaterina_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Kistrimova_Ekaterina_ComplexNumberTest, check_sum_opposites_is_zero) {
    // Arrange
    double re = 5.8;
    double im = 2.3;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(-re, -im);

    ComplexNumber res = z1 + z2;

    // Assert
    EXPECT_EQ(0.0, res.getRe());
    EXPECT_EQ(0.0, res.getIm());
}

TEST(Kistrimova_Ekaterina_ComplexNumberTest, check_multiplication_is_zero) {
    // Arrange
    double re = 5.8;
    double im = 2.3;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(0.0, 0.0);

    ComplexNumber res = z1 * z2;

    // Assert
    EXPECT_EQ(0.0, res.getRe());
    EXPECT_EQ(0.0, res.getIm());
}

TEST(Kistrimova_Ekaterina_ComplexNumberTest, check_divide_is_zero) {
    // Arrange
    double re = 5.8;
    double im = 2.3;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(0.0, 0.0);

    // Assert
    ASSERT_ANY_THROW(z1 / z2);
}

TEST(Kistrimova_Ekaterina_ComplexNumberTest, check_invertion_is_zero) {
    // Arrange
    double re = 5.8;
    double im = 2.3;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(-re, -im);
    ComplexNumber z3(0.0, 0.0);
    ComplexNumber res = z3 - z1;

    // Assert
    ASSERT_EQ(z2.getRe(), res.getRe());
    ASSERT_EQ(z2.getIm(), res.getIm());
}

TEST(Kistrimova_Ekaterina_ComplexNumberTest, check_commutativity) {
    // Arrange
    double re1 = 5.8;
    double im1 = 2.2;
    double re2 = 4.7;
    double im2 = 3.3;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    // Assert
    EXPECT_EQ(z1 + z2, z2 + z1);
}

TEST(Kistrimova_Ekaterina_ComplexNumberTest, check_distributivity) {
    // Arrange
    double re = 5.8;
    double im = 2.3;

    // Act
    ComplexNumber z1(re, im);

    // Assert
    EXPECT_EQ(z1*(z1 + z1), z1*z1 + z1*z1);
}
