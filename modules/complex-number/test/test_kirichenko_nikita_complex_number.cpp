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

TEST(Kirichenko_Nikita_ComplexNumberTest, Comparison_of_addition) {
    ComplexNumber z(5.0, 9.0);
    ComplexNumber k(13.0, 16.0);
    ComplexNumber res1 = z + k;
    ComplexNumber num1(z.getRe(), z.getIm());
    ComplexNumber num2(k.getRe(), k.getIm());
    ComplexNumber res2 = num1 + num2;
    ASSERT_EQ(res1, res2);
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
Kirichenko_Nikita_ComplexNumberTestTest_Param;
TEST_P(Kirichenko_Nikita_ComplexNumberTestTest_Param, Operations_Test) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber num1(re1, im1);
    ComplexNumber num2(re2, im2);

    ComplexNumber r1 = num1 + num2;
    ComplexNumber r2 = num1 + num1;
    ComplexNumber r3 = r1 - r2;
    ComplexNumber total = num2 -num1;

    ASSERT_EQ(r3, total);
}

INSTANTIATE_TEST_CASE_P(/**/, Kirichenko_Nikita_ComplexNumberTestTest_Param,
    testing::Combine(
        testing::Values(4.0, 2.0),
        testing::Values(2.0, 4.0),
        testing::Values(1.0, 1.0),
        testing::Values(8.5, 6.5)));
