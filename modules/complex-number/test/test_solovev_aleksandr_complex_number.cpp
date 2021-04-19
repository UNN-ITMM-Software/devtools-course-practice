// Copyright 2021 Solovev Aleksandr

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Solovev_Aleksandr_ComplexNumberTest, Test_Equal) {
    ComplexNumber c1(7.0, 10.0);

    ASSERT_EQ(c1, c1);
}

TEST(Solovev_Aleksandr_ComplexNumberTest, Test_NoEqual) {
    ComplexNumber c1(7.0, 10.0);
    ComplexNumber c2(11.2, 17.1);
    ComplexNumber c3(c2);

    ASSERT_NE(c1, c3);
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
        Solovev_Aleksandr_ComplexNumberTest_Parametrized;
TEST_P(Solovev_Aleksandr_ComplexNumberTest_Parametrized, Test_Multiply) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());
    double resultRe = (re1 * re2) - (im1 * im2);
    double resultIm = (re1 * im2) + (im1 * re2);

    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber result = c1 * c2;

    ASSERT_EQ(resultRe, result.getRe());
    ASSERT_EQ(resultIm, result.getIm());
};

INSTANTIATE_TEST_CASE_P(/**/, Solovev_Aleksandr_ComplexNumberTest_Parametrized,
                        testing::Values(
  std::make_tuple(10.0, 3.0, 13.0, 3.0),
  std::make_tuple(0.0, 4.0, 0.0, 1.0),
  std::make_tuple(2.0, 0.0, 13.5, 0.0),
  std::make_tuple(0.0, 0.0, 0.0, 0.0)
));

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
        Solovev_Aleksandr_ComplexNumberTest_Add_Parametrized;
TEST_P(Solovev_Aleksandr_ComplexNumberTest_Add_Parametrized, Test_Add) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());
    double resultRe = re1 + re2;
    double resultIm = im1 + im2;

    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber result = c1 + c2;

    EXPECT_EQ(resultRe, result.getRe());
    EXPECT_EQ(resultIm, result.getIm());
}

INSTANTIATE_TEST_CASE_P(/**/,
                        Solovev_Aleksandr_ComplexNumberTest_Add_Parametrized,
                        testing::Values(
  std::make_tuple(10.0, 3.0, 13.0, 3.0),
  std::make_tuple(0.0, 4.0, 0.0, 1.0),
  std::make_tuple(2.0, 0.0, 13.5, 0.0),
  std::make_tuple(0.0, 0.0, 0.0, 0.0)
));
