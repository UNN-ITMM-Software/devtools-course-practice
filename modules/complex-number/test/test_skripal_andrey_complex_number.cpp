// Copyright 2021 Skripal Andrey

#include <gtest/gtest.h>
#include <tuple>
#include "include/complex_number.h"

TEST(Skripal_Andrey_ComplexNumberTest, OperationsPlusMinMult_Test) {
    ComplexNumber n1(15.0, 10.0);
    ComplexNumber n2(5.0, 7.0);
    ComplexNumber n3(8.0, 2.0);
    ComplexNumber n4(20.0, 13.0);

    ComplexNumber res1(9.0, -43.0);
    ComplexNumber res2 = n1 - n2 * n3 + n4;

    ASSERT_EQ(res1.getRe(), res2.getRe());
    ASSERT_EQ(res1.getIm(), res2.getIm());
}

TEST(Skripal_Andrey_ComplexNumberTest, DivisionThrow_Test) {
    ComplexNumber n1(12.1, 30.55);

    double re = 0.0;
    double im = 0.0;

    ComplexNumber n2(re, im);

    ASSERT_ANY_THROW(n1 / n2);
}

TEST(Skripal_Andrey_ComplexNumberTest, NotEqual_Test) {
    double re1 = 22.15;
    double im1 = 10.35;
    double re2 = 3.89;
    double im2 = 7.11;

    ComplexNumber n1(re1, im1);
    ComplexNumber n2(re2, im2);

    bool res = n1 != n2;
    ASSERT_TRUE(res);
}

    typedef testing::TestWithParam<std::tuple<double, double, double, double>>
    Skripal_Andrey_ComplexNumberTest_Param;

TEST_P(Skripal_Andrey_ComplexNumberTest_Param, DivisionAndMultParam_Test) {
     double re1 = std::get<0>(GetParam());
     double im1 = std::get<1>(GetParam());
     double re2 = std::get<2>(GetParam());
     double im2 = std::get<3>(GetParam());

     ComplexNumber n1(re1, im1);
     ComplexNumber n2;
     n2.setRe(re2);
     n2.setIm(im2);

     ComplexNumber res = n1 / n2;
     res = res * n2;

     ASSERT_DOUBLE_EQ(re1, res.getRe());
     ASSERT_DOUBLE_EQ(im1, res.getIm());
}

INSTANTIATE_TEST_CASE_P(/**/, Skripal_Andrey_ComplexNumberTest_Param,
     testing::Combine(
         testing::Values(71.342, 33.22),
         testing::Values(-201.69, 15.11),
         testing::Values(666.458, -68.33),
         testing::Values(137.12, 44.9)));

