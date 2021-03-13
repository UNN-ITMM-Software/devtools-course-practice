// Copyright 2021 Kudriavtsev Alexandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Addition) {
    const double re1 = 100.75;
    const double re2 = -800.0;
    const double im1 = -178.0;
    const double im2 = -500.5;

    const double re_res = re1 + re2;
    const double im_res = im1 + im2;

    ComplexNumber cn1(re1, im1);
    ComplexNumber cn2(re2, im2);
    ComplexNumber res = cn1 + cn2;

    ASSERT_DOUBLE_EQ(re_res, res.getRe());
    ASSERT_DOUBLE_EQ(im_res, res.getIm());
}

TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Zero_is_Zero) {
    const double zero = 0.0;

    ComplexNumber cn1(zero, zero);

    ASSERT_DOUBLE_EQ(zero, cn1.getRe());
    ASSERT_DOUBLE_EQ(zero, cn1.getIm());
}

TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Substract_Himself_is_Zero) {
    const double re = 22.8;
    const double im = 9.5;

    ComplexNumber cn(re, im);
    ComplexNumber res = cn - cn;

    ASSERT_DOUBLE_EQ(0.0, res.getRe());
    ASSERT_DOUBLE_EQ(0.0, res.getIm());
}

TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Substract_Copy_is_Zero) {
    const double re = 2402.8;
    const double im = -57.5;

    ComplexNumber cn1(re, im);
    ComplexNumber cn2(cn1);
    ComplexNumber res = cn1 - cn2;

    ASSERT_DOUBLE_EQ(0.0, res.getRe());
    ASSERT_DOUBLE_EQ(0.0, res.getIm());
}
