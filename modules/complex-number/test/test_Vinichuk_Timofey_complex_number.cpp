// Copyright 2024 Vinichuk Timofey

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Vinichuk_Timofey_ComplexNumberTest, test_square_equals_one) {
    double re = 0.0;
    double im = 1.0;
    ComplexNumber z(re, im);
    ComplexNumber p = z * z;
    ASSERT_EQ(-1.0, p.getRe());
    ASSERT_EQ(0, p.getIm());
}

TEST(Vinichuk_Timofey_ComplexNumberTest, test_sum_opposites_is_zero) {
    ComplexNumber z1(2, -2);
    ComplexNumber z2(-2, 2);
    ComplexNumber p = z1 + z2;
    ASSERT_EQ(0, p.getRe());
    ASSERT_EQ(0, p.getIm());
}

TEST(Vinichuk_Timofey_ComplexNumberTest, test_invertion) {
    ComplexNumber z(2, 2);
    ComplexNumber z1(-2, -2);
    ComplexNumber z2(0, 0);
    ComplexNumber p = z2 - z;
    ASSERT_EQ(z1.getRe(), p.getRe());
    ASSERT_EQ(z1.getIm(), p.getIm());
}
