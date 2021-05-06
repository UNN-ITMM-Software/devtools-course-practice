// Copyright 2021 Bulychev Vladislav

#include <gtest/gtest.h>

#include <tuple>

#include "include/complex_number.h"

TEST(Bulychev_Vladislav_ComplexNumberTest, Get_And_Set) {
    double im = 0.0;
    ComplexNumber n(0.0, 1.0);

    n.setIm(im);

    ASSERT_EQ(im, n.getIm());
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
Bulychev_Vladislav_ComplexNumberTest_Param;

TEST_P(Bulychev_Vladislav_ComplexNumberTest_Param, Addition_Test) {
    ComplexNumber a(std::get<0>(GetParam()), std::get<1>(GetParam()));
    ComplexNumber b(std::get<2>(GetParam()), std::get<3>(GetParam()));
    double n1 = (std::get<0>(GetParam()));
    double n2 = (std::get<1>(GetParam()));
    double n3 = (std::get<2>(GetParam()));
    double n4 = (std::get<3>(GetParam()));
    double re = n1 + n3;
    double im = n2 + n4;

    ComplexNumber r1(re, im);
    ComplexNumber r2 = a + b;

    ASSERT_EQ(r1, r2);
}

TEST_P(Bulychev_Vladislav_ComplexNumberTest_Param, Multiplication_Test) {
    ComplexNumber a(std::get<0>(GetParam()), std::get<1>(GetParam()));
    ComplexNumber b(std::get<2>(GetParam()), std::get<3>(GetParam()));

    ComplexNumber r1 = (a - b) * (a + b);
    ComplexNumber r2 = a * a - b * b;

    ASSERT_EQ(r1, r2);
}

INSTANTIATE_TEST_CASE_P(/**/, Bulychev_Vladislav_ComplexNumberTest_Param,
    ::testing::Values(
        std::make_tuple(1.0, 3.0, 3.5, 1.5),
        std::make_tuple(0.0, 2.0, 1.0, 4.79),
        std::make_tuple(3.5, 5.0, 0.0, 1.0),
        std::make_tuple(4.0, 2.0, 1.0, 3.75)
    )
);
