// Copyright 2024 Kozlov Mikhail

#include <gtest/gtest.h>
#include "include/complex_number.h"



TEST(Kozlov_Mikhail_ComplexNumberTest, Addition) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber result = z1 + z2;
    EXPECT_DOUBLE_EQ(result.getRe(), 4.0);
    EXPECT_DOUBLE_EQ(result.getIm(), 6.0);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, Subtraction) {
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(1.0, 2.0);
    ComplexNumber result = z1 - z2;
    EXPECT_DOUBLE_EQ(result.getRe(), 2.0);
    EXPECT_DOUBLE_EQ(result.getIm(), 2.0);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, Multiplication) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber result = z1 * z2;
    EXPECT_DOUBLE_EQ(result.getRe(), -5.0);
    EXPECT_DOUBLE_EQ(result.getIm(), 10.0);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, DivisionByZero) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(0.0, 0.0);
    EXPECT_THROW(z1 / z2, std::string);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, Division) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, 1.0);
    ComplexNumber result = z1 / z2;
    EXPECT_DOUBLE_EQ(result.getRe(), 1.5);
    EXPECT_DOUBLE_EQ(result.getIm(), 0.5);
}



TEST(Kozlov_Mikhail_ComplexNumberTest, Equality) {
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(3.0, 4.0);
    EXPECT_TRUE(z1 == z2);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, Inequality) {
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(1.0, 2.0);
    EXPECT_TRUE(z1 != z2);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, MultiplicationByZero) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber zero(0.0, 0.0);
    ComplexNumber result = z1 * zero;
    EXPECT_DOUBLE_EQ(result.getRe(), 0.0);
    EXPECT_DOUBLE_EQ(result.getIm(), 0.0);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, CreationOfNegativeNumber) {
    ComplexNumber z(-1.0, -2.0);
    EXPECT_DOUBLE_EQ(z.getRe(), -1.0);
    EXPECT_DOUBLE_EQ(z.getIm(), -2.0);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, AdditionOfNegativeNumbers) {
    ComplexNumber z1(-1.0, -2.0);
    ComplexNumber z2(-3.0, -4.0);
    ComplexNumber result = z1 + z2;
    EXPECT_DOUBLE_EQ(result.getRe(), -4.0);
    EXPECT_DOUBLE_EQ(result.getIm(), -6.0);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, SubtractionOfNegativeNumbers) {
    ComplexNumber z1(-3.0, -4.0);
    ComplexNumber z2(-1.0, -2.0);
    ComplexNumber result = z1 - z2;
    EXPECT_DOUBLE_EQ(result.getRe(), -2.0);
    EXPECT_DOUBLE_EQ(result.getIm(), -2.0);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, DefaultConstructor) {
    ComplexNumber z;
    EXPECT_DOUBLE_EQ(z.getRe(), 0.0);
    EXPECT_DOUBLE_EQ(z.getIm(), 0.0);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, ParameterizedConstructor) {
    ComplexNumber z(3.0, 4.0);
    EXPECT_DOUBLE_EQ(z.getRe(), 3.0);
    EXPECT_DOUBLE_EQ(z.getIm(), 4.0);
}

TEST(Kozlov_Mikhail_ComplexNumberTest, CopyConstructor) {
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(z1);
    EXPECT_DOUBLE_EQ(z1.getRe(), z2.getRe());
    EXPECT_DOUBLE_EQ(z1.getIm(), z2.getIm());
}

TEST(Kozlov_Mikhail_ComplexNumberTest, AssignmentOperator) {
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2;
    z2 = z1;
    EXPECT_DOUBLE_EQ(z1.getRe(), z2.getRe());
    EXPECT_DOUBLE_EQ(z1.getIm(), z2.getIm());
}
