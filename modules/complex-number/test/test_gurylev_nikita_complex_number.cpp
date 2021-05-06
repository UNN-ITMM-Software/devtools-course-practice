// Copyright 2021 Gurylev Nikita

#include <gtest/gtest.h>

#include <tuple>
#include <cmath>

#include "include/complex_number.h"

TEST(Gurylev_Nikita_ComplexNumberTest, EqualityCheck) {
    double re = 1.0;
    double im = 2.0;

    ComplexNumber z(re, im);
    ComplexNumber result = (z * z) / z;

    ASSERT_DOUBLE_EQ(re, result.getRe());
    ASSERT_DOUBLE_EQ(im, result.getIm());
}

TEST(Gurylev_Nikita_ComplexNumberTest, ArithmeticOperation) {
    ComplexNumber z(8.0, 9.0);
    ComplexNumber q(4.0, 3.0);

    ComplexNumber num1 = (z + q) * (z - q);
    ComplexNumber result(-24.0, 120.0);

    ASSERT_EQ(num1, result);
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
Gurylev_Nikita_ComplexNumberTest_Param;
TEST_P(Gurylev_Nikita_ComplexNumberTest_Param, ComparisonOperation) {
    ComplexNumber z(std::get<0>(GetParam()), std::get<1>(GetParam()));
    ComplexNumber q(std::get<2>(GetParam()), std::get<3>(GetParam()));

    ComplexNumber result1 = (z * z * z) + (q * q * q);
    ComplexNumber result2 = (z + q) * (z * z - z * q + q * q);

    ASSERT_EQ(result1, result2);
}

INSTANTIATE_TEST_CASE_P(/**/, Gurylev_Nikita_ComplexNumberTest_Param,
    ::testing::Values(
        std::make_tuple(2.0, 3.0, 5.7, 1.5),
        std::make_tuple(6.0, 2.0, 4.0, 5.0),
        std::make_tuple(4.5, 7.0, 9.0, 3.0),
        std::make_tuple(3.0, 3.0, 5.0, 4.0)));
