// Copyright 2021 Kudriavtsev Alexandr

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Zero_is_Zero) {
    const double kZero = 0.0;

    ComplexNumber cn1(kZero, kZero);

    ASSERT_DOUBLE_EQ(kZero, cn1.getRe());
    ASSERT_DOUBLE_EQ(kZero, cn1.getIm());
}

TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Substract_Himself_is_Zero) {
    const double kRe = 22.8;
    const double kIm = 9.5;

    ComplexNumber cn(kRe, kIm);
    ComplexNumber res = cn - cn;

    ASSERT_DOUBLE_EQ(0.0, res.getRe());
    ASSERT_DOUBLE_EQ(0.0, res.getIm());
}

TEST(Kudriavtsev_Alexandr_ComplexNumberTest, Substract_Copy_is_Zero) {
    const double kRe = 2402.8;
    const double kIm = -57.5;

    ComplexNumber cn1(kRe, kIm);
    ComplexNumber cn2(cn1);
    ComplexNumber res = cn1 - cn2;

    ASSERT_DOUBLE_EQ(0.0, res.getRe());
    ASSERT_DOUBLE_EQ(0.0, res.getIm());
}
