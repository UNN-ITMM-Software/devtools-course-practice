// Copyright 2021 Kolesin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kolesin_Andrey_ComplexNumberTest, Rotation90Degrees) {
    ComplexNumber i(0, 1);
    double re = 3.6;
    double im = 5.7;
    ComplexNumber a(re, im);
    ComplexNumber ai(-im, re);
    ComplexNumber aii(-re, -im);
    ComplexNumber aiii(im, -re);
    ASSERT_EQ(ai, a * i);
    ASSERT_EQ(aii, a * i * i);
    ASSERT_EQ(aiii, a * i * i * i);
    ASSERT_EQ(a, a * i * i * i * i);
}

TEST(Kolesin_Andrey_ComplexNumberTest, NegativeSquaredIsPositive) {
    ComplexNumber a(-5.2, 0);
    ComplexNumber aSquered = a * a;
    ASSERT_EQ(aSquered.getIm(), 0);
    ASSERT_GT(aSquered.getRe(), 0);
}

TEST(Kolesin_Andrey_ComplexNumberTest, SumOfConjugatesIsConjugationOfSum) {
    ComplexNumber a(-5.3, 7.2);
    ComplexNumber aConjugated(a.getRe(), -a.getIm());
    ComplexNumber b(8.9, -10.5);
    ComplexNumber bConjugated(b.getRe(), -b.getIm());
    ComplexNumber aPlusB = a + b;
    ComplexNumber aPlusBConjugated(aPlusB.getRe(), -aPlusB.getIm());
    ASSERT_EQ(aPlusBConjugated, aConjugated + bConjugated);
}
