// Copyright 2021 Kirichenko Nikita

#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"

TEST(Kirichenko_Nikita_ComplexNumberTest, Calculation) {
    ComplexNumber z(3.0, 4.0);
    ComplexNumber k(7.0, 10.0);
    ComplexNumber num1 = (z + k) * z;
    ComplexNumber res(-26.0, 82.0);
    ASSERT_EQ(res, num1);
}

TEST(Kirichenko_Nikita_ComplexNumberTest, Calculation2) {
    ComplexNumber m(1.0, 3.0);
    ComplexNumber n(8.0, 9.0);
    ComplexNumber num1 = (n + m) * (n - m);
    ComplexNumber res(-9.0, 138.0);
    ASSERT_EQ(res, num1);
}

TEST(Kirichenko_Nikita_ComplexNumberTest, Comparison) {
    ComplexNumber z(5.0, 9.0);
    ComplexNumber k(13.0, 16.0);
    ComplexNumber res1 = z + k;
    ComplexNumber num1(z.getRe(), z.getIm());
    ComplexNumber num2(k.getRe(), k.getIm());
    ComplexNumber res2 = num1 + num2;
    ASSERT_EQ(res1, res2);
}
