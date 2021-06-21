// Copyright 2021 Ikromov Inom

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Ikromov_Inom_Complex_Number_Test_1, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Ikromov_Inom_Complex_Number_Test_2, Can_Multiplicate_Any) {
    // Arrange
    double re_1 = 2.0;
    double im_1 = 3.0;
    double re_2 = -1.0;
    double im_2 = -2.0;

    // Act
    ComplexNumber z_1(re_1, im_1);
    ComplexNumber z_2(re_2, im_2);
    z_2 = z_1 * z_2;

    // Assert
    EXPECT_EQ(4.0, z_2.getRe());
    EXPECT_EQ(-7.0, z_2.getIm());
}

TEST(Ikromov_Inom_Complex_Number_Test_3, Can_Divide_Any) {
    // Arrange
    double re_1 = 4.0;
    double im_1 = 2.0;
    double re_2 = -2.0;
    double im_2 = -1.0;

    // Act
    ComplexNumber z_1(re_1, im_1);
    ComplexNumber z_2(re_2, im_2);
    z_2 = z_1 / z_2;

    // Assert
    EXPECT_EQ(-2.0, z_2.getRe());
    EXPECT_EQ(0.0, z_2.getIm());
}
