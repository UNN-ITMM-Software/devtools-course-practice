// Copyright 2021 Kudriavtsev Alexandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Addition) {
    const double Re1 = 100.75;
    const double Re2 = -800.0;
    const double Im1 = -178.0;
    const double Im2 = -500.5;

    const double re_res = Re1 + Re2;
    const double im_res = Im1 + Im2;

    ComplexNumber cn1(Re1, Im1);
    ComplexNumber cn2(Re2, Im2);
    ComplexNumber res = cn1 + cn2;

    ASSERT_DOUBLE_EQ(re_res, res.getRe());
    ASSERT_DOUBLE_EQ(im_res, res.getIm());
}

TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Zero_is_Zero) {
    const double zero = 0.0;

    ComplexNumber c1(zero, zero);

    EXPECT_EQ(zero, c1.getRe());
    EXPECT_EQ(zero, c1.getIm());
}

TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Substract_Himself_is_Zero) {
    const double re = 22.8;
    const double im = 9.5;

    ComplexNumber cn(re, im);
    ComplexNumber result = cn - cn;

    ASSERT_DOUBLE_EQ(0.0, result.getRe());
    ASSERT_DOUBLE_EQ(0.0, result.getIm());
}

TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Substract_Copy_is_Zero) {
    const double re = 2402.8;
    const double im = -57.5;

    ComplexNumber cn1(re, im);
    ComplexNumber cn2(cn1);
    ComplexNumber result = cn1 - cn2;

    ASSERT_DOUBLE_EQ(0.0, result.getRe());
    ASSERT_DOUBLE_EQ(0.0, result.getIm());
}