// Copyright 2024 Vinokurov Ivan

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Vinokurov_Ivan_ComplexNumberTest, testDefaultConstructor) {
    ComplexNumber z;
    EXPECT_EQ(z.getRe(), 0.0);
    EXPECT_EQ(z.getIm(), 0.0);
}

TEST(Vinokurov_Ivan_ComplexNumberTest, testAddition) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(1.0, -1.0);
    ComplexNumber result = z1 + z2;
    EXPECT_EQ(result.getRe(), 3.0);
    EXPECT_EQ(result.getIm(), 2.0);
}

TEST(Vinokurov_Ivan_ComplexNumberTest, testSubtraction) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(1.0, -1.0);
    ComplexNumber result = z1 - z2;
    EXPECT_EQ(result.getRe(), 1.0);
    EXPECT_EQ(result.getIm(), 4.0);
}

TEST(Vinokurov_Ivan_ComplexNumberTest, testMultiplication) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(1.0, -1.0);
    ComplexNumber result = z1 * z2;
    EXPECT_EQ(result.getRe(), 5.0);
    EXPECT_EQ(result.getIm(), 1.0);
}

TEST(Vinokurov_Ivan_ComplexNumberTest, testDivision) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(1.0, -1.0);
    ComplexNumber result = z1 / z2;
    EXPECT_EQ(result.getRe(), 2.5);
    EXPECT_EQ(result.getIm(), 0.5);
}

TEST(Vinokurov_Ivan_ComplexNumberTest, testDivisionByZero) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(0.0, 0.0);
    EXPECT_THROW(z1 / z2, std::string);
}
