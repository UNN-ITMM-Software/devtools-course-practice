// Copyright 2024 Kashin Stepan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(KASHIN_STEPAN_ComplexNumberTest, Constructors) {
    ASSERT_NO_THROW(ComplexNumber());
    ASSERT_NO_THROW(ComplexNumber(1, 1));
    ASSERT_NO_THROW(ComplexNumber(ComplexNumber(1, 1)));
}

TEST(KASHIN_STEPAN_ComplexNumberTest, Sum) {
    ASSERT_EQ(ComplexNumber(3, -1) + ComplexNumber(-1, 2), ComplexNumber(2, 1));
}

TEST(KASHIN_STEPAN_ComplexNumberTest, Assignment) {
    ComplexNumber z1(1, 1);
    ComplexNumber z2(2, 2);
    ASSERT_NO_THROW(z2 = z1);

    ASSERT_NE(&z1, &z2);
    ASSERT_DOUBLE_EQ(z2.getRe(), 1);
    ASSERT_DOUBLE_EQ(z2.getIm(), 1);
}

TEST(KASHIN_STEPAN_ComplexNumberTest, MyNoPeEqUaLiTyOpErAtOr) {
    ASSERT_TRUE(
        ComplexNumber(1, 1) != ComplexNumber(1, 2) &&
        !(ComplexNumber(1, 1) != ComplexNumber(ComplexNumber(1, 1))));
}

TEST(KASHIN_STEPAN_ComplexNumberTest, MyEqUaLiTyOpErAtOr) {
    ASSERT_TRUE(
        ComplexNumber(1, 1) == ComplexNumber(1, 1) &&
        ComplexNumber(1, 1) == ComplexNumber(ComplexNumber(1, 1)));
}
