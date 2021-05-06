// Copyright 2021 Lukianchencko Ivan

#include <gtest/gtest.h>
#include <tuple>
#include "include/complex_number.h"

TEST(Lukianchenko_CoplexNumberTest, Sum_Test) {
    ComplexNumber num_0(1.0, 0.0);
    ComplexNumber num_1(-2.0, 3.0);
    ComplexNumber num_2(4.0, -5.0);
    ComplexNumber num_3(5.0, 4.0);
    ComplexNumber num_4(3.0, 2.0);
    ComplexNumber sum = num_0 + num_1 + num_2 + num_3 + num_4;
    if (sum.getRe() > 0)
        sum = sum - num_0 - num_1 - num_2 - num_3 - num_4;
    ASSERT_EQ(sum.getRe(), sum.getIm());
}
typedef testing::TestWithParam<std::tuple<double, double, double, double>>
    Lukianchenko_CoplexNumberTest_WithParam;

TEST_P(Lukianchenko_CoplexNumberTest_WithParam, Bool_Test) {
    ComplexNumber num_0(std::get<0>(GetParam()), std::get<1>(GetParam()));
    ComplexNumber num_1(num_0);
    ComplexNumber num_2(std::get<2>(GetParam()), std::get<3>(GetParam()));
    ComplexNumber num_3(num_2);
    num_2 = num_2 - num_0 - num_0;
    num_3 = num_3 - (num_1 + num_1);
    ASSERT_EQ(num_2, num_3);
}

TEST_P(Lukianchenko_CoplexNumberTest_WithParam, Multiplication_Division_Test) {
    ComplexNumber num_0(std::get<0>(GetParam()), std::get<2>(GetParam()));
    ComplexNumber num_1(num_0.getIm(), num_0.getRe());
    ComplexNumber res_0 = num_0 *num_1;
    ComplexNumber num_2(res_0.getIm(), res_0.getRe());
    ComplexNumber res_1 = res_0/num_2;
    ComplexNumber res_test(0.0, 1.0);
    ASSERT_EQ(res_1, res_test);
}

INSTANTIATE_TEST_CASE_P(/**/, Lukianchenko_CoplexNumberTest_WithParam,
    testing::Combine(
        testing::Values(12.0, 2333.0),
        testing::Values(-15.0, 456.0),
        testing::Values(423.0, 0.0),
        testing::Values(-23.0, 44.0)
));

