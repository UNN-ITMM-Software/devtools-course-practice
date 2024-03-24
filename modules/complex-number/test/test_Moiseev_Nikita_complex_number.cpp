// Copyright 2024 Moiseev Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Moiseev_Nikita_ComplexNumberTest, Can_Add) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3 = z1 + z2;

    ASSERT_EQ(z3.getRe(), 4);
    ASSERT_EQ(z3.getIm(), 6);
}

TEST(Moiseev_Nikita_ComplexNumberTest, Can_Subtract) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3 = z1 - z2;

    ASSERT_EQ(z3.getRe(), -2);
    ASSERT_EQ(z3.getIm(), -2);
}

TEST(Moiseev_Nikita_ComplexNumberTest, Can_Multiply) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3 = z1 * z2;

    ASSERT_EQ(z3.getRe(), -5);
    ASSERT_EQ(z3.getIm(), 10);
}

TEST(Moiseev_Nikita_ComplexNumberTest, Can_Compare) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3(1, 2);

    ASSERT_TRUE(z1 == z3);
    ASSERT_TRUE(z1 != z2);
}

TEST(Moiseev_Nikita_ComplexNumberTest, Can_Change) {
    ComplexNumber z1(1, 2);
    z1.setRe(3);
    z1.setIm(4);

    ASSERT_EQ(z1.getRe(), 3);
    ASSERT_EQ(z1.getIm(), 4);
}

TEST(Moiseev_Nikita_ComplexNumberTest, Can_Create_Copy) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(z1);

    ASSERT_TRUE(z1 == z2);
}

TEST(Moiseev_Nikita_ComplexNumberTest, Can_Create_Default) {
    ComplexNumber z1;

    ASSERT_EQ(z1.getRe(), 0);
    ASSERT_EQ(z1.getIm(), 0);
}

TEST(Moiseev_Nikita_ComplexNumberTest, SumOperatorWithFractions) {
    ComplexNumber z1(3.25, 4.75);
    ComplexNumber z2(-3.25, 4.75);

    ComplexNumber z3 = z1 + z2;

    ASSERT_DOUBLE_EQ(z3.getRe(), 0.0);
    ASSERT_DOUBLE_EQ(z3.getIm(), 9.5);
}

TEST(Moiseev_Nikita_ComplexNumberTest, DifferenceOperatorWithFractions) {
    ComplexNumber z1(2.25, 53.25);
    ComplexNumber z2(-2.25, 53.25);

    ComplexNumber z3 = z1 - z2;

    ASSERT_DOUBLE_EQ(z3.getRe(), 4.5);
    ASSERT_DOUBLE_EQ(z3.getIm(), 0.0);
}

TEST(Moiseev_Nikita_ComplexNumberTest, DivisionOperatorWithFractions) {
    ComplexNumber z1(2.25, 5.25);
    ComplexNumber z2(-2.25, 5.25);

    ComplexNumber z3 = z1 / z2;

    ASSERT_NEAR(z3.getRe(), 0.6, 0.1);
    ASSERT_NEAR(z3.getIm(), -0.7, 0.1);
    ASSERT_ANY_THROW(ComplexNumber() / ComplexNumber());
}
