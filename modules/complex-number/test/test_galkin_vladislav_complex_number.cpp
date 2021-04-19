// Copyright 2021 Galkin Vladislav

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Galkin_Vladislav_ComplexNumberTest, Mult_Subtraction) {
    double Re1 = 10.5, Im1 = 14.2;
    double Re2 = 5.0, Im2 = 2.1;
    double Re3 = 8.3, Im3 = 7.6;
    ComplexNumber z1(Re1, Im1);
    ComplexNumber z2(Re2, Im2);
    ComplexNumber z3(Re3, Im3);

    ComplexNumber res(Re1 - Re2 - Re3, Im1 - Im2 - Im3);

    // Check operator-
    ASSERT_EQ(res, z1 - z2 - z3);
}

TEST(Galkin_Vladislav_ComplexNumberTest, Check_Get_and_Set) {
    double Re1 = 1.1, Im1 = 2.5;
    ComplexNumber z1(Re1, Im1);
    ComplexNumber z2(0.0, 0.0);

    // Check SetRe and SetIm
    z2.setRe(z1.getRe());
    z2.setIm(z1.getIm());

    // Check GetRe and GetIm
    ASSERT_EQ(z2.getRe(), Re1);
    ASSERT_EQ(z2.getIm(), Im1);
}

TEST(Galkin_Vladislav_ComplexNumberTest,
Check_operator_equally_and_operator_not_equally) {
    double Re1 = 5.5, Im1 = 2.2;
    double Re2 = 5.5, Im2 = 2.2;
    double Re3 = 5.0, Im3 = 1.1;
    ComplexNumber z1(Re1, Im1);
    ComplexNumber z2(Re2, Im2);
    ComplexNumber z3(Re3, Im3);

    // ==
    bool res1, res2;

    if (z1 == z2) res1 = true;
    if (z1.getRe() == z2.getRe() && z1.getIm() == z2.getIm()) res2 = true;

    // !=
    bool res3, res4;

    if (z1 != z3) res3 = true;
    if (z1.getRe() != z3.getRe() || z1.getIm() != z3.getIm()) res4 = true;
    ASSERT_EQ(res1, res2);
    ASSERT_EQ(res3, res4);
}
