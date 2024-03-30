// Copyright 2024 Kokin Ivan

#include <gtest/gtest.h>

#include "../include/complex_number.h"

TEST(Kokin_Ivan_ComplexNumberTest, Getto) {
    ComplexNumber z(222.875, 23.454);
    ASSERT_DOUBLE_EQ(z.getRe(), 222.875);
    ASSERT_DOUBLE_EQ(z.getIm(), 23.454);
}

TEST(Kokin_Ivan_ComplexNumberTest, CanSum) {
    ComplexNumber z1(11, 12);
    ComplexNumber z2(13, 14);
    ComplexNumber z3 = z1 + z2;
    ASSERT_EQ(z3.getRe(), 24);
    ASSERT_EQ(z3.getIm(), 26);
}

TEST(Kokin_Ivan_ComplexNumberTest, Setto) {
    ComplexNumber z1{};
    z1.setRe(121.45);
    z1.setIm(434.21);
    ASSERT_DOUBLE_EQ(z1.getRe(), 121.45);
    ASSERT_DOUBLE_EQ(z1.getIm(), 434.21);
}

TEST(Kokin_Ivan_ComplexNumberTest, falseTrue) {
    ComplexNumber z1(12.43, 34.54);
    ComplexNumber z2(12.43, 34.54);
    EXPECT_EQ(z1 == z2, true);
}

TEST(Kokin_Ivan_ComplexNumberTest, TestZeroDel) {
    ComplexNumber z1(123.7, 342.2);
    ComplexNumber z2(0.0, 0.0);
    ASSERT_ANY_THROW(z1 / z2);
}
