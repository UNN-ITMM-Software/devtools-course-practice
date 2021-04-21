// Copyright 2021 Pronkin Dmitry

#include <gtest/gtest.h>
#include <tuple>
#include <memory>

#include "include/complex_number.h"

TEST(Pronkin_Dmitry_ComplexNumberTest, Can_Create_Pointer) {
    double re = 13.0;
    double im = 13.0;
    std::unique_ptr<ComplexNumber> z(new ComplexNumber(re, im));

    ASSERT_EQ(re, z->getRe());
    ASSERT_EQ(im, z->getIm());
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
        Pronkin_Dmitry_ComplexNumberTest_Parametrized_4;
TEST_P(Pronkin_Dmitry_ComplexNumberTest_Parametrized_4,
       Multiplication_Complex_Conjugate) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re1, -im1);
    ComplexNumber z4(re2, -im2);

    ComplexNumber control = z1 / z2;
    ComplexNumber result = z3 / z4;

    ASSERT_DOUBLE_EQ(control.getRe(), result.getRe());
    ASSERT_DOUBLE_EQ(-control.getIm(), result.getIm());
}

TEST_P(Pronkin_Dmitry_ComplexNumberTest_Parametrized_4,
       Multiplication_After_Division_Give_Original) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ComplexNumber z = z1 / z2;
    ComplexNumber result = z * z2;

    ASSERT_DOUBLE_EQ(re1, result.getRe());
    ASSERT_DOUBLE_EQ(im1, result.getIm());
}

INSTANTIATE_TEST_CASE_P(/**/, Pronkin_Dmitry_ComplexNumberTest_Parametrized_4,
    testing::Values(
  std::make_tuple(-3.0, 1.4, 5.7, -13.0),
  std::make_tuple(11.13, 11.22, 22.63, -1.0),
  std::make_tuple(2.3, 3.4, 5.6, 7.8),
  std::make_tuple(3.31, 5.07, -5.0, 3.0)
));
