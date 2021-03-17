// Copyright 2021 Vodeneev Mikhail

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Vodeneev_Mikhail_ComplexNumberTest, Add_with_Subtraction) {
    double re1 = 1, re2 = 2, re3 = 3;
    double im1 = 6, im2 = 9, im3 = 12;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    ComplexNumber res = z1 + z2 - z3;

    ASSERT_EQ(0, res.getRe());
    ASSERT_EQ(3, res.getIm());
}

TEST(Vodeneev_Mikhail_ComplexNumberTest, Add_with_3_arguments) {
    double re1 = 1, re2 = 2, re3 = 3;
    double im1 = 6, im2 = 9, im3 = 12;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    ComplexNumber res = z1 + z2 + z3;

    ASSERT_EQ(6, res.getRe());
    ASSERT_EQ(27, res.getIm());
}

TEST(Vodeneev_Mikhail_ComplexNumberTest, Subtraction_with_3_arguments) {
    double re1 = 1, re2 = 2, re3 = 3;
    double im1 = 6, im2 = 9, im3 = 12;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    ComplexNumber res = z1 - z2 - z3;

    ASSERT_EQ(-4, res.getRe());
    ASSERT_EQ(-15, res.getIm());
}
