// Copyright 2024 Kokin Ivan

#include <gtest/gtest.h>

#include "../include/complex_number.h"

TEST(Kokin_Ivan_ComplexNumberTest, Getto) {
    ComplexNumber z(222.875, 23.454);

    ASSERT_DOUBLE_EQ(z.getRe(), 222.875);
    ASSERT_DOUBLE_EQ(z.getIm(), 23.454);
}

TEST(Kokin_Ivan_ComplexNumberTest, CanUmn) {
    ComplexNumber z1(11, 12);
    ComplexNumber z2(13, 14);
    ComplexNumber z3 = z1 * z2;

    ASSERT_EQ(z3.getRe(), 143);
    ASSERT_EQ(z3.getIm(), 168);
}

TEST(Kokin_Ivan_ComplexNumberTest, Setto) {
    ComplexNumber s1{};
    s1.setRe(121.45);
    s1.setIm(434.21);

    ASSERT_DOUBLE_EQ(s1.getRe(), 121.45);
    ASSERT_DOUBLE_EQ(s1.getIm(), 434.21);
}

TEST(Kokin_Ivan_ComplexNumberTest, falseTrue) {
    ComplexNumber z1(12.43, 34.54);
    ComplexNumber z2(12.43, 34.54);
    EXPECT_EQ(z1 == z2, true);
}
