// Copyright 2021 Volkova Nastya

#include <gtest/gtest.h>
#include <tuple>
#include "include/complex_number.h"

TEST(Volkova_Nastya_ComplexNumberTest, ComplexNumberCreation) {
    double numb_re = 1.5;
    double numb_im  = -2.8;
    ComplexNumber numb1(numb_re, numb_im);
    ComplexNumber numb2 = numb1;
    ComplexNumber numb3;
    numb3.setRe(numb_re);
    numb3.setIm(numb_im);

    ASSERT_EQ(numb1.getRe(), numb2.getRe());
    ASSERT_EQ(numb1.getIm(), numb2.getIm());
    ASSERT_EQ(numb1.getRe(), numb3.getRe());
    ASSERT_EQ(numb1.getIm(), numb3.getIm());
}

typedef testing::TestWithParam<std::tuple< double, double, double,
        double, double, double>> Volkova_Parametrized;

TEST_P(Volkova_Parametrized, Sum) {
    ComplexNumber numb1(std::get<0>(GetParam()), std::get<1>(GetParam()));
    ComplexNumber numb2(std::get<2>(GetParam()), std::get<3>(GetParam()));
    ComplexNumber numb3(std::get<4>(GetParam()), std::get<5>(GetParam()));

    ComplexNumber res1 = numb1 + numb2;
    ComplexNumber res2 = numb1 + numb3;
    ComplexNumber res3 = res2 - res1;
    ComplexNumber res4 = res3 + numb2;

    ASSERT_EQ(res4, numb3);
}

TEST_P(Volkova_Parametrized, MultiplicationAndSum) {
    ComplexNumber numb1(std::get<0>(GetParam()), std::get<1>(GetParam()));
    ComplexNumber numb2(std::get<2>(GetParam()), std::get<3>(GetParam()));
    ComplexNumber numb3(std::get<4>(GetParam()), std::get<5>(GetParam()));

    ComplexNumber res1 = numb1 * numb2;
    ComplexNumber res2 = numb1 * numb3;
    ComplexNumber res3 = res1 + res2;
    ComplexNumber res4 = numb2 + numb3;
    ComplexNumber res5 = numb1 * res4;

    ASSERT_EQ(res3, res5);
}

INSTANTIATE_TEST_CASE_P(/**/, Volkova_Parametrized, testing::Combine(
  testing::Values(4.0, 2.0),
  testing::Values(2.0, 4.0),
  testing::Values(1.0, 1.0),
  testing::Values(8.5, 6.5),
  testing::Values(8.5),
  testing::Values(1.5)
));
