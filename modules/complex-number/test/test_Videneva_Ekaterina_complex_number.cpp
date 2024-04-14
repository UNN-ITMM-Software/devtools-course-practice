// Copyright 2024 Videneva Ekaterina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Videneva_Ekaterina_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Videneva_Ekaterina_ComplexNumberTest, Can_Multiply_ComplexNumbers) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);

    ComplexNumber result = z1 * z2;

    EXPECT_EQ(-5.0, result.getRe());
    EXPECT_EQ(10.0, result.getIm());
}

TEST(Videneva_Ekaterina_ComplexNumberTest, Can_Sum_ComplexNumbers) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(1.0, 4.0);

    ComplexNumber result = z1 + z2;

    EXPECT_EQ(3.0, result.getRe());
    EXPECT_EQ(7.0, result.getIm());
}

TEST(Videneva_Ekaterina_ComplexNumberTest, Can_Subtraction_ComplexNumbers) {
    ComplexNumber z1(4.1, -2.1);
    ComplexNumber z2(2.5, -1.1);
    ComplexNumber result = z1 - z2;

    EXPECT_DOUBLE_EQ(1.6, result.getRe());
    EXPECT_DOUBLE_EQ(-1.0, result.getIm());
}


TEST(Videneva_Ekaterina_ComplexNumberTest, Division_Of_Complex_Numbers) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(4.0, 3.0);

    ComplexNumber result = z1 / z2;

    EXPECT_DOUBLE_EQ(result.getRe(), 0.4);
    EXPECT_DOUBLE_EQ(result.getIm(), 0.2);
}

TEST(Videneva_Ekaterina_ComplexNumberTest, Can_Create_Copy_ComplexNumbers) {
    ComplexNumber z1(1.0, 3.0);
    ComplexNumber z2(z1);

    ASSERT_TRUE(z1 == z2);
}

TEST(Videneva_Ekaterina_ComplexNumberTest, Division_By_Zero_ComplexNumbers) {
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(0.0, 0.0);

    ASSERT_ANY_THROW(z1 / z2);
}

TEST(Videneva_Ekaterina_ComplexNumberTest, Mult_By_Zero_ComplexNumbers) {
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(0.0, 0.0);

    ComplexNumber result1 = z1 * z2;

    EXPECT_DOUBLE_EQ(result1.getRe(), 0.0);
    EXPECT_DOUBLE_EQ(result1.getIm(), 0.0);
}
