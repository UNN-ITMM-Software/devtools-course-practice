// Copyright 2021 Kiseleva Anastasia

#include <gtest/gtest.h>

#include <cmath>

#include "include/complex_number.h"


TEST(Kiseleva_Anastasia_ComplexNumberTest, Subtraction_Property) {
    double re = 5.1+5.2;
    double im = 0.09-1.9;

    ComplexNumber z(re, im);
    ComplexNumber conj_z(re, im * -1);

    ComplexNumber res = z - conj_z;
    ComplexNumber Res(0.0, 2*im);

    ASSERT_EQ(res, Res);
}

TEST(Kiseleva_Anastasia_ComplexNumberTest, Abs_Of_Conjugate_Numbers_Minus) {
    double re = 5.7;
    double im = 11.2;

    ComplexNumber z(re, im);
    ComplexNumber z2(re, im * -1);

    double abs1 = std::sqrt(z.getRe()* z.getRe()+z.getIm()* z.getIm());
    double abs2 = std::sqrt(z2.getRe() * z2.getRe() + z2.getIm() * z2.getIm());

    double res = abs1 - abs2;

    ASSERT_EQ(0.0, res);
}

TEST(Kiseleva_Anastasia_ComplexNumberTest, Division_Of_Conjugate_Numbers) {
    double re = -4.3;
    double im = 0.75;
    double re2 = 7.0;
    double im2 = 5.2;

    ComplexNumber z1(re, im);
    ComplexNumber z2(re2, im2);

    ComplexNumber conj_z1(re, im * -1);
    ComplexNumber conj_z2(re2, im2 * -1);

    ComplexNumber div_conj = conj_z1 / conj_z2;
    ComplexNumber div = z1 / z2;

    double imd = div.getIm() * -1;
    div.setIm(imd);

    ASSERT_EQ(div_conj, div);
}

