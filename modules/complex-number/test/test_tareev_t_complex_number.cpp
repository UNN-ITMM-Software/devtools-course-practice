// Copyright 2021 Tareev Daniil

#include <gtest/gtest.h>

#include <string>
#include <limits>

#include "include/complex_number.h"

class CustomComplexNumberTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(CustomComplexNumberTest, create_zero_default) {
    // Arrange
    double re = 0.;
    double im = 0.;

    // Act
    ComplexNumber z;

    // Assert
    EXPECT_NEAR(re, z.getRe(), CustomComplexNumberTest::epsilon);
    EXPECT_NEAR(im, z.getIm(), CustomComplexNumberTest::epsilon);
}

TEST_F(CustomComplexNumberTest, create_in_place) {
    // Arrange
    double re = 12.5;
    double im = 14.123;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(z, ComplexNumber(re, im));
}

TEST_F(CustomComplexNumberTest, create_by_copy_constructor) {
    // Arrange
    ComplexNumber expected(67.2, 85.3);

    // Act
    ComplexNumber z(expected);

    // Assert
    EXPECT_EQ(expected, z);
}

TEST_F(CustomComplexNumberTest, math_operation_div) {
    // Arrange
    ComplexNumber divident(4, 6);
    ComplexNumber divider(1, 9);
    ComplexNumber expecetd(0.7073, -0.3658);

    // Act
    auto result = divident / divider;

    // Assert
    EXPECT_NEAR(expecetd.getRe(),
                result.getRe(),
                CustomComplexNumberTest::epsilon);
    EXPECT_NEAR(expecetd.getIm(),
                result.getIm(),
                CustomComplexNumberTest::epsilon);
}

TEST_F(CustomComplexNumberTest, math_operation_mul) {
    // Arrange
    ComplexNumber multiplier1(4.4, 6.3);
    ComplexNumber multiplier2(1.34, 9.98);
    ComplexNumber expecetd(-56.978, 52.354);

    // Act
    auto result = multiplier1 * multiplier2;

    // Assert
    EXPECT_NEAR(expecetd.getRe(),
                result.getRe(),
                CustomComplexNumberTest::epsilon);
    EXPECT_NEAR(expecetd.getIm(),
                result.getIm(),
                CustomComplexNumberTest::epsilon);
}

TEST_F(CustomComplexNumberTest, math_operation_add) {
    // Arrange
    ComplexNumber param1(4.4, 6.3);
    ComplexNumber param2(1.34, 9.98);
    ComplexNumber expecetd(5.74, 16.28);

    // Act
    auto result = param1 + param2;

    // Assert
    EXPECT_NEAR(expecetd.getRe(),
                result.getRe(),
                CustomComplexNumberTest::epsilon);
    EXPECT_NEAR(expecetd.getIm(),
                result.getIm(),
                CustomComplexNumberTest::epsilon);
}

TEST_F(CustomComplexNumberTest, math_operation_diff) {
    // Arrange
    ComplexNumber param1(4.4, 6.3);
    ComplexNumber param2(1.34, 9.98);
    ComplexNumber expecetd(3.06, -3.68);

    // Act
    auto result = param1 - param2;

    // Assert
    EXPECT_NEAR(expecetd.getRe(),
                result.getRe(),
                CustomComplexNumberTest::epsilon);
    EXPECT_NEAR(expecetd.getIm(),
                result.getIm(),
                CustomComplexNumberTest::epsilon);
}

TEST_F(CustomComplexNumberTest, stress_create_min_max_value) {
    // Arrange
    auto re = std::numeric_limits<double>::min();
    auto im = std::numeric_limits<double>::max();

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}