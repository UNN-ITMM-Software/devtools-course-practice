// Copyright 2021 Zaitsev Andrey

#include <gtest/gtest.h>

#include <tuple>

#include "include/complex_number.h"

TEST(Zaitsev_Andrey_ComplexNumberTest, Get_And_Set_Check) {
  double re = 23.42;
  double im = 6.23;
  ComplexNumber num1(re, im);
  ComplexNumber num2(num1.getRe(), num1.getIm());
  ComplexNumber num3 = ComplexNumber();
  num3.setRe(re);
  num3.setIm(im);

  ASSERT_EQ(num1.getRe(), num2.getRe());
  ASSERT_EQ(num1.getIm(), num2.getIm());
  ASSERT_EQ(num1.getRe(), num3.getRe());
  ASSERT_EQ(num1.getIm(), num3.getIm());
}

TEST(Zaitsev_Andrey_ComplexNumberTest, Arifm_Operations_Test) {
  ComplexNumber num1(12.0, 12.0);
  ComplexNumber num2(2.0, 2.0);
  ComplexNumber num3(8.0, 10.0);
  ComplexNumber num4(3.0, 4.0);

  ComplexNumber answer(66.0, 84.0);

  ComplexNumber result = (num1 / num2) * (num3 + num4);
  ASSERT_EQ(answer.getRe(), result.getRe());
  ASSERT_EQ(answer.getIm(), result.getIm());
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
Zaitsev_Andrey_ComplexNumberTest_Param;

TEST_P(Zaitsev_Andrey_ComplexNumberTest_Param, Add_And_Sub_Operations_Test) {
  ComplexNumber num1(std::get<0>(GetParam()), std::get<1>(GetParam()));
  ComplexNumber num2(std::get<2>(GetParam()), std::get<3>(GetParam()));

  ComplexNumber res1 = num1 + num2;
  ComplexNumber res2 = num1 - num2;
  ComplexNumber res3 = res1 - res2;
  ComplexNumber answer = num2 + num2;

  ASSERT_EQ(res3, answer);
}

INSTANTIATE_TEST_CASE_P(/**/, Zaitsev_Andrey_ComplexNumberTest_Param,
  testing::Values(
    std::make_tuple(10.21, 5.3, 6.5, 7.0),
    std::make_tuple(4.6, 8.44, 4.0, 2.5),
    std::make_tuple(7.5, 9.7, 5.5, 9.0),
    std::make_tuple(8.8, 12.2, 1.5, 6.0)));
