// Copyright 2021 Kirichenko Nikita

#include <gtest/gtest.h>

#include <tuple>
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
    ComplexNumber num1(std::get<0>(GetParam()), std::get<1>(GetParam()));
    ComplexNumber num2(std::get<2>(GetParam()), std::get<3>(GetParam()));

    ComplexNumber r1 = (num1 / num2) * num1;
    ComplexNumber r2 = (r1 * num2) / num1;

    ASSERT_EQ(r2, num1);
}

INSTANTIATE_TEST_CASE_P(/**/, Kirichenko_Nikita_ComplexNumberTestTest_Param,
    testing::Values(
        std::make_tuple(4.0, 2.0, 6.0, 12.0),
        std::make_tuple(1.0, 4.0, 0.0, 2.0),
        std::make_tuple(2.0, 0.0, 13.5, 0.0),
        std::make_tuple(8.0, 5.0, 3.0, 5.0)));
