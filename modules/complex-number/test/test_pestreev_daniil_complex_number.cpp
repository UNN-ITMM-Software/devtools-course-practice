// Copyright 2021 Pestreev Daniil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pestreev_Daniil_ComplexNumberTest, Sequence_of_actions) {
    ComplexNumber c1(2, 2);
    ComplexNumber c2(-2, 2);
    ComplexNumber c3(2, 63);
    ComplexNumber c4(0, 10);
    ComplexNumber c = c1 + c2 * c3 * (c4 - c3);
    ASSERT_EQ(c.getRe(), -6204);
    ASSERT_EQ(c.getIm(), 7136);
}

TEST(Pestreev_Daniil_ComplexNumberTest, Conjugate_property) {
    double c1 = 23.0;
    double c2 = 43.0;
    double r1 = c1;
    double r2 = -c2;

    ComplexNumber com1(c1, c2);
    ComplexNumber com2(r1, r2);
    ComplexNumber a = (com1 * com1 * com1 * com1 * com1);
    ComplexNumber b = (com2 * com2 * com2 * com2 * com2);
    double re = 174630628.0;
    ASSERT_DOUBLE_EQ(a.getRe(), re);
    ASSERT_DOUBLE_EQ(b.getRe(), re);
    double im = 213417772.0;
    ASSERT_DOUBLE_EQ((-1) * a.getIm(), im);
    ASSERT_DOUBLE_EQ(b.getIm(), im);
}

TEST(Pestreev_Daniil_ComplexNumberTest, Exponentiation_i) {
    ComplexNumber c1(0, 1);
    ComplexNumber c1_ext2 = c1 * c1;
    ASSERT_EQ(c1_ext2.getRe(), -1);
    ASSERT_EQ(c1_ext2.getIm(), 0);
    ComplexNumber c1_ext5 = c1_ext2 * c1_ext2 * c1;
    ASSERT_EQ(c1_ext5.getRe(), 0);
    ASSERT_EQ(c1_ext5.getIm(), 1);
}
