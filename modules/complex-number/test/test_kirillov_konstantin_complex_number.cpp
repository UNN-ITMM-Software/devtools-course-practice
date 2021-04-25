// Copyright 2021 Kirillov Konstantin

#include <gtest/gtest.h>
#include <tuple>
#include "include/complex_number.h"

TEST(Kirillov_Konstantin_ComplexNumberTest, Arifmetic_Operator_Test) {
    ComplexNumber num1(3.0, 4.0);
    ComplexNumber num2(5.0, 2.0);
    ComplexNumber num3(8.0, 8.0);
    ComplexNumber num4(1.0, 1.0);

    ComplexNumber dres(64.0, 48.0);

    ComplexNumber cres = (num1 + num2) * (num3 / num4);

    ASSERT_EQ(dres.getRe(), cres.getRe());
    ASSERT_EQ(dres.getIm(), cres.getIm());
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
    Kirillov_ComplexNumberTest_Param;


TEST_P(Kirillov_ComplexNumberTest_Param, Bool_Operator_Test) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber num1(re1, im1);
    ComplexNumber num2(re2, im2);

    ComplexNumber res = num1 * num2 / num1;
    bool is_equal = num1 == res;
    bool not_equal = num1 != res;
    ASSERT_NE(is_equal, not_equal);
}

TEST_P(Kirillov_ComplexNumberTest_Param, Div_Operator_Test) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber num1(re1, im1);
    ComplexNumber num2(re2, im2);

    ComplexNumber res = num2 - num1;
    res = res + num1;
    ASSERT_EQ(res, num2);
}

INSTANTIATE_TEST_CASE_P(/**/, Kirillov_ComplexNumberTest_Param,
    testing::Combine(
        testing::Values(7.0, 2.0),
        testing::Values(20.0, 15.0),
        testing::Values(13.0, 4.0),
        testing::Values(6.0, 5.0)
));
