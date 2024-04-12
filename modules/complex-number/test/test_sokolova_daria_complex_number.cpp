// Copyright 2024 Sokolova Daria

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sokolova_Daria_ComplexNumberTest, Can_Add_Complex_Numbers) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber sum = z1 + z2;
    ASSERT_EQ(sum.getRe(), 4);
    ASSERT_EQ(sum.getIm(), 6);
}
TEST(Sokolova_Daria_ComplexNumberTest, Can_Subtract_Complex_Numbers) {
    ComplexNumber z1(3, 4);
    ComplexNumber z2(1, 2);
    ComplexNumber diff = z1 - z2;
    ASSERT_EQ(diff.getRe(), 2);
    ASSERT_EQ(diff.getIm(), 2);
}
TEST(Sokolova_Daria_ComplexNumberTest, Can_Multiply_Complex_Numbers) {
    ComplexNumber z1(3, 4);
    ComplexNumber z2(5, 6);
    ComplexNumber z3 = z1 * z2;

    ASSERT_EQ(z3.getRe(), -9);
    ASSERT_EQ(z3.getIm(), 38);
}
TEST(Sokolova_Daria_ComplexNumberTest, Can_Divide_By_Zero) {
    ComplexNumber z1(5, 7);
    ComplexNumber z2(0, 0);

    ASSERT_THROW(z1 / z2, std::string);
}
TEST(Sokolova_Daria_ComplexNumberTest, Can_Divide_Complex_Numbers) {
    ComplexNumber z1(3, 4);
    ComplexNumber z2(1, 2);

    ComplexNumber division = z1 / z2;

    ASSERT_DOUBLE_EQ(division.getRe(), 2.2);
    ASSERT_DOUBLE_EQ(division.getIm(), -0.4);
}

TEST(Sokolova_Daria_ComplexNumberTest, Can_Compare_Two_Different_Numbers) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);

    ASSERT_FALSE(z1 == z2);
    ASSERT_TRUE(z1 != z2);
}

TEST(Sokolova_Daria_ComplexNumberTest, Can_Multiply_By_Zero) {
    ComplexNumber z1(3, 4);
    ComplexNumber zero(0, 0);

    ComplexNumber result = z1 * zero;

    ASSERT_EQ(result.getRe(), 0);
    ASSERT_EQ(result.getIm(), 0);
}

TEST(Sokolova_Daria_ComplexNumberTest, Can_Create_Negative_Number) {
    ComplexNumber z1(-3, -4);

    ASSERT_EQ(z1.getRe(), -3);
    ASSERT_EQ(z1.getIm(), -4);
}

TEST(Sokolova_Daria_ComplexNumberTest, Can_Add_Negative_Numbers) {
    ComplexNumber z1(-2, -3);
    ComplexNumber z2(-4, -5);

    ComplexNumber sum = z1 + z2;

    ASSERT_EQ(sum.getRe(), -6);
    ASSERT_EQ(sum.getIm(), -8);
}

TEST(Sokolova_Daria_ComplexNumberTest, Can_Subtract_Negative_Numbers) {
    ComplexNumber z1(-3, -4);
    ComplexNumber z2(-1, -2);

    ComplexNumber diff = z1 - z2;

    ASSERT_EQ(diff.getRe(), -2);
    ASSERT_EQ(diff.getIm(), -2);
}
TEST(Sokolova_Daria_ComplexNumberTest,
    Can_Add_Complex_Numbers_With_Fractional_Values) {
    ComplexNumber z1(3.5, 4.5);
    ComplexNumber z2(1.5, 2.5);
    ComplexNumber division = z1 + z2;
    ASSERT_DOUBLE_EQ(division.getRe(), 5);
    ASSERT_DOUBLE_EQ(division.getIm(), 7);
}
TEST(Sokolova_Daria_ComplexNumberTest,
    Can_Subtract_Complex_Numbers_With_Fractional_Values) {
    ComplexNumber z1(3.5, 4.5);
    ComplexNumber z2(1.5, 2.5);
    ComplexNumber division = z1 - z2;
    ASSERT_DOUBLE_EQ(division.getRe(), 2);
    ASSERT_DOUBLE_EQ(division.getIm(), 2);
}

