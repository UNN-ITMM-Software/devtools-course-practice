// Copyright 2021 Chistov Vladimir

#include <gtest/gtest.h>
#include <tuple>
#include "include/complex_number.h"

TEST(Chistov_Vladimir_ComplexNumberTest, Arifmetic_Test) {
    ComplexNumber a(12.0, 9.1);
    ComplexNumber b(3.0, 1.1);
    ComplexNumber c(1.3, 1.1);
    ComplexNumber d(1.7, 0.9);
    ComplexNumber res1(11.0, 42.0);
    ComplexNumber res2 = (a - b) * (c + d);
    ASSERT_EQ(res1.getRe(), res2.getRe());
    ASSERT_EQ(res1.getIm(), res2.getIm());
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
Chistov_Vladimir_ComplexNumberTest_Param;


TEST_P(Chistov_Vladimir_ComplexNumberTest_Param, Bool_Test) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());
    double res_re = re1 - re2;
    double res_im = im1 - im2;
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    ComplexNumber res = a - b;
    bool bres1 = res_re == res.getRe();
    bool bres2 = res_re != res.getIm();
    ASSERT_EQ(bres1, bres2);
}

TEST_P(Chistov_Vladimir_ComplexNumberTest_Param, Par_Test) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());
    double res_re = (re1 * re2) - (im1 * im2);
    double res_im = (re1 * im2) + (im1 * re2);
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    ComplexNumber res = a * b;
    ASSERT_EQ(res_re, res.getRe());
    ASSERT_EQ(res_im, res.getIm());
}

INSTANTIATE_TEST_CASE_P(/**/, Chistov_Vladimir_ComplexNumberTest_Param,
    testing::Combine(
        testing::Values(1511.1, 42.3),
        testing::Values(7.8, 15.3),
        testing::Values(33.7, 5329.2),
        testing::Values(6.6, 28.4)
    )
);
