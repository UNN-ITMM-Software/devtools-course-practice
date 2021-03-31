// Copyright 2021 Ostapovich Denis

#include <gtest/gtest.h>

#include <limits>

#include <tuple>
#include "include/complex_number.h"

const double epsilon = std::numeric_limits<double>::epsilon();

typedef testing::TestWithParam<std::tuple<double, double>>
    Ostapovich_Denis_ComplexNumberTest_Param_2;

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
    Ostapovich_Denis_ComplexNumberTest_Param_4;

TEST_P(Ostapovich_Denis_ComplexNumberTest_Param_2,
    Equality_Operator_Not_Zero) {
    double re = std::get<0>(GetParam());
    double im = std::get<1>(GetParam());

    ComplexNumber a(re, im);
    ComplexNumber b(re, im);
    ASSERT_EQ(a, b);
}

TEST(Ostapovich_Denis_ComplexNumberTest,
    Equality_Operator_Approximately_Zero) {
    ComplexNumber a(0.0, 0.0);
    ComplexNumber b(-epsilon, epsilon);
    ASSERT_NE(a, b);
}

TEST_P(Ostapovich_Denis_ComplexNumberTest_Param_4,
    No_Throw_On_Addition) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber a(re1, im1);
    ComplexNumber b(re1, im2);

    ASSERT_NO_THROW(a + b);
}

TEST_P(Ostapovich_Denis_ComplexNumberTest_Param_4,
    No_Throw_On_Subtraction) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber a(re1, im1);
    ComplexNumber b(re1, im2);

    ASSERT_NO_THROW(a - b);
}

TEST_P(Ostapovich_Denis_ComplexNumberTest_Param_4,
    No_Throw_On_Multiplication) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber a(re1, im1);
    ComplexNumber b(re1, im2);

    ASSERT_NO_THROW(a * b);
}

TEST_P(Ostapovich_Denis_ComplexNumberTest_Param_4,
    No_Throw_On_Division_By_Not_Zero) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber a(re1, im1);
    ComplexNumber b(re1, im2);

    ASSERT_NO_THROW(a / b);
}

INSTANTIATE_TEST_CASE_P(/**/, Ostapovich_Denis_ComplexNumberTest_Param_2,
    testing::Values(
  std::make_tuple(15.0, 1.0),
  std::make_tuple(6.0, -3.0),
  std::make_tuple(0, 0),
  std::make_tuple(-12, 10),
  std::make_tuple(-12, -21)
));

INSTANTIATE_TEST_CASE_P(/**/, Ostapovich_Denis_ComplexNumberTest_Param_4,
    testing::Values(
  std::make_tuple(11.0, 12.0, 13.0, 14.0),
  std::make_tuple(-11.0, 12.0, -13.0, 14.0),
  std::make_tuple(11.0, -12.0, 13.0, -14.0),
  std::make_tuple(-11.0, -12.0, -13.0, -14.0)
));
