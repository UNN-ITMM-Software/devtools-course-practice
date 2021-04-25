// Copyright 2021 Kuznetsov Nikita

#include <gtest/gtest.h>

#include <tuple>

#include "include/complex_number.h"

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
Kuznetsov_Nikita_ComplexNumberTest_Param;
TEST_P(Kuznetsov_Nikita_ComplexNumberTest_Param, Can_Sum_Elements) {
  double re = std::get<0>(GetParam());
  double im = std::get<1>(GetParam());
  double re2 = std::get<2>(GetParam());
  double im2 = std::get<3>(GetParam());
  ComplexNumber z1(re, im);
  ComplexNumber z2(re, im);
  ComplexNumber z3(re2, im2);
  ComplexNumber z4(re2, im2);

  ComplexNumber sum = z1 + z2;
  ComplexNumber sum2 = z3 + z4;

  ASSERT_EQ(sum, ComplexNumber(2 * re, 2 * im));
  ASSERT_EQ(sum2, ComplexNumber(2 * re2, 2 * im2));
}

TEST_P(Kuznetsov_Nikita_ComplexNumberTest_Param, Can_Subtract_Elements) {
  double re = std::get<0>(GetParam());
  double im = std::get<1>(GetParam());
  double re2 = std::get<2>(GetParam());
  double im2 = std::get<3>(GetParam());
  ComplexNumber z1(re, im);
  ComplexNumber z2(re, im);
  ComplexNumber z3(re2, im2);
  ComplexNumber z4(re2, im2);

  ComplexNumber sub = z1 - z2;
  ComplexNumber sub2 = z3 - z4;

  ASSERT_EQ(sub, ComplexNumber(re - re, im - im));
  ASSERT_EQ(sub2, ComplexNumber(re - re, im - im));
}

TEST_P(Kuznetsov_Nikita_ComplexNumberTest_Param, Can_Multiply_Elements) {
  double re = std::get<0>(GetParam());
  double im = std::get<1>(GetParam());
  double re2 = std::get<2>(GetParam());
  double im2 = std::get<3>(GetParam());
  ComplexNumber z1(re, im);
  ComplexNumber z2(re, im);
  ComplexNumber z3(re2, im2);
  ComplexNumber z4(re2, im2);

  ComplexNumber result = z1 * z2;
  ComplexNumber result2 = z3 * z4;

  ASSERT_EQ(result, ComplexNumber(re * re - im * im, re * im + im * re));
  ASSERT_EQ(result2, ComplexNumber(re2 * re2 - im2 * im2,
    re2 * im2 + im2 * re2));
}
INSTANTIATE_TEST_CASE_P(/**/, Kuznetsov_Nikita_ComplexNumberTest_Param,
  testing::Values(
    std::make_tuple(-10.0, 2.0, 3.0, -5.0),
    std::make_tuple(5.0, -4.0, -1.5, 10.0),
    std::make_tuple(0.0, 1.0, 0.0, 0.0),
    std::make_tuple(0.0, 0.0, 0.0, 0.0))
);
