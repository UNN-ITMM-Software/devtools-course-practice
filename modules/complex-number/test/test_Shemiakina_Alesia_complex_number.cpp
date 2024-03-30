// Copyright 2024 Alesia Shemiakina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Alesia_Shemiakina_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Alesia_Shemiakina_ComplexNumberTest, Can_Multiply) {
    // Arrange
    double re1 = 2.1, re2 = 1.5;
    double im1 = 2.0, im2 = -3.0;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_EQ(re1 * re2 - im1 * im2, z.getRe());
    EXPECT_EQ(re1 * im2 + re2 * im1, z.getIm());
}

TEST(Alesia_Shemiakina_ComplexNumberTest, Can_Divide) {
    // Arrange
    double re1 = 10.6, re2 = 1.0;
    double im1 = 2.0, im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 / z2;

    // Assert
    EXPECT_EQ(re1, z.getRe());
    EXPECT_EQ(im1, z.getIm());
}

TEST(Alesia_Shemiakina_ComplexNumberTest, Check_Commutativity) {
    // Arrange
    double re1 = 3.0, re2 = 2.5;
    double im1 = 4.0, im2 = 3.5;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_EQ(z1 + z2, z2 + z1);
}

TEST(Alesia_Shemiakina_ComplexNumberTest, Check_Distributivity) {
    // Arrange
    double re = 4.1;
    double im = 3.5;

    // Act
    ComplexNumber z1(re, im);

    // Assert
    EXPECT_EQ(z1*(z1 + z1), z1*z1 + z1*z1);
}

TEST(Alesia_Shemiakina_ComplexNumberTest, Check_Mult_On_Zero) {
    // Arrange
    double re = 2.1;
    double im = 3.5;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(0.0, 0.0);

    ComplexNumber z3 = z1 * z2;

    // Assert
    EXPECT_EQ(0.0, z3.getRe());
    EXPECT_EQ(0.0, z3.getIm());
}

TEST(Alesia_Shemiakina_ComplexNumberTest, Check_Divide_On_Zero) {
    // Arrange
    double re = 2.1;
    double im = 3.5;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(0.0, 0.0);

    // Assert
    ASSERT_ANY_THROW(z1 / z2);
}
