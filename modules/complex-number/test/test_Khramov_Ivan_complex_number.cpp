// Copyright 2024 Khramov Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Khramov_Ivan_ComplexNumberTest, Check_Setter_Getter) {
    // Arrange
    double re1 = 2.0;
    double im1 = 3.0;
    double re2 = 1.5;
    double im2 = 3.2;
    // Act
    ComplexNumber z(re1, im1);
    z.setRe(re2);
    z.setIm(im2);
    // Assert
    EXPECT_EQ(re2, z.getRe());
    EXPECT_EQ(im2, z.getIm());
}

TEST(Khramov_Ivan_ComplexNumberTest, Check_Commutativity) {
    // Arrange
    double re1 = 2.0;
    double im1 = 3.0;
    double re2 = 1.5;
    double im2 = 4.5;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    // Assert
    EXPECT_EQ(z1 + z2, z2 + z1);
}

TEST(Khramov_Ivan_ComplexNumberTest, Check_Distributivity) {
    // Arrange
    double re = 2.5;
    double im = 3.1;

    // Act
    ComplexNumber z1(re, im);

    // Assert
    EXPECT_EQ(z1*(z1 + z1), z1*z1 + z1*z1);
}


TEST(Khramov_Ivan_ComplexNumberTest, Check_Sum_Opposites_For_Zero) {
    // Arrange
    double re = 2.5;
    double im = 3.1;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(-re, -im);

    ComplexNumber z3 = z1 + z2;

    // Assert
    EXPECT_EQ(0.0, z3.getRe());
    EXPECT_EQ(0.0, z3.getIm());
}

TEST(Khramov_Ivan_ComplexNumberTest, Check_Mult_On_Zero) {
    // Arrange
    double re = 2.5;
    double im = 3.1;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(0.0, 0.0);

    ComplexNumber z3 = z1 * z2;

    // Assert
    EXPECT_EQ(0.0, z3.getRe());
    EXPECT_EQ(0.0, z3.getIm());
}

TEST(Khramov_Ivan_ComplexNumberTest, Assert_Divide_By_Zero) {
    // Arrange
    double re = 2.5;
    double im = 3.1;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(0.0, 0.0);

    // Assert
    ASSERT_ANY_THROW(z1 / z2);
}
