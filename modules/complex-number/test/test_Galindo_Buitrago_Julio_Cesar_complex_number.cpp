// Copyright 2021 Galindo Buitrago Julio Cesar

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Galindo_Julio_ComplexNumberTest, Distributive_property) {
    // Arrange
    double re1 = -6.9;
    double im1 = 4.2;
    double re2 = 7.9;
    double im2 = 4.5;
    double re3 = -5.3;
    double im3 = 9.3;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);
    ComplexNumber res1 = z1 * (z2 + z3);
    ComplexNumber res2 = (z1 * z2) + (z1 * z3);

    // Assert
    ASSERT_EQ(res1, res2);
}

TEST(Galindo_Julio_ComplexNumberTest, Adition_operation) {
    // Arrange
    double re1 = 0;
    double im1 = 0;
    double re2 = 7.3;
    double im2 = 4.9;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber res = z1 + z2;

    // Assert
    ASSERT_DOUBLE_EQ(z2.getRe(), res.getRe());
    ASSERT_DOUBLE_EQ(z2.getIm(), res.getIm());
}

TEST(Galindo_Julio_ComplexNumberTest, NonEqual_Division) {
    // Arrange
    double re1 = 9.3;
    double im1 = 5.9;
    double re2 = -6.2;
    double im2 = 7.7;
    double re3 = -2.3;
    double im3 = 8.9;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);
    ComplexNumber res1 = z1 / (z2 - z3);
    ComplexNumber res2 = (z1 - z2) / z3;

    // Assert
    EXPECT_NE(res1, res2);
}
