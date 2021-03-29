// Copyright 2021 Bezrodnov Dmitry

#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"

TEST(Bezrodnov_Dmitry_ComplexNumberTest, Multiplication_Conjugate_Numbers) {
    double re = 1.0;
    double im = 3.0;
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, -im);
    ASSERT_EQ(10, (z1*z2).getRe());
}

TEST(Bezrodnov_Dmitry_ComplexNumberTest, Sum_Conjugate_Numbers) {
    double re = 1.0;
    double im = 3.0;
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, -im);
    ASSERT_EQ(2, (z1+z2).getRe());
}

TEST(Bezrodnov_Dmitry_ComplexNumberTest, Module_Conjugate_Numbers) {
    ComplexNumber z1(3, 4);
    ComplexNumber z2(3, -4);
    ASSERT_EQ(5, static_cast<int>(sqrt(pow(z1.getRe(), 2)
        + pow(z1.getIm(), 2))));
    ASSERT_EQ(5, static_cast<int>(sqrt(pow(z2.getRe(), 2)
        + pow(z2.getIm(), 2))));
}
