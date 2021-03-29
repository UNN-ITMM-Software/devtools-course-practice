// Copyright 2021 Kolesin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kolesin_Andrey_ComplexNumberTest, Rotation) {
    ComplexNumber i(0, 1);
    ComplexNumber a(3, 5);
    ComplexNumber b(-5, 3);
    ComplexNumber c(-3, -5);
    ComplexNumber d(5, -3);
    ASSERT_EQ(b, a * i);
    ASSERT_EQ(c, a * i * i);
    ASSERT_EQ(d, a * i * i * i);
    ASSERT_EQ(a, a * i * i * i * i);
}
TEST(Kolesin_Andrey_ComplexNumberTest, NegSqr) {
    ComplexNumber a(-5, 0);
    ComplexNumber b = a * a;
    ASSERT_EQ(b.getIm(), 0);
    ASSERT_GT(b.getRe(), 0);
}
TEST(Kolesin_Andrey_ComplexNumberTest, Conjugate) {
    ComplexNumber a(-5, 7);
    ComplexNumber ac(a.getRe(), -a.getIm());
    ComplexNumber b(8, -10);
    ComplexNumber bc(b.getRe(), -b.getIm());
    ComplexNumber apb = a + b;
    ComplexNumber apbc(apb.getRe(), -apb.getIm());
    ASSERT_EQ(apbc, ac + bc);
}
