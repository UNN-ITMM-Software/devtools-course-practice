// Copyright 2021 Chernyh Daria

#include <gtest/gtest.h>

#include <tuple>

#include "include/complex_number.h"

typedef testing::TestWithParam<std::tuple<double, double>>
Chernyh_Daria_ComplexNumberTest_Parametrized;
TEST_P(Chernyh_Daria_ComplexNumberTest_Parametrized,
  Addition_of_conjugate) {
  double numberRe = std::get<0>(GetParam());
  double numberIm = std::get<1>(GetParam());
  double numberIm_conj = -numberIm;
  ComplexNumber number(numberRe, numberIm);
  ComplexNumber number_conj(numberRe, numberIm_conj);
  ComplexNumber result = number + number_conj;

  double check_Re = numberRe + numberRe;
  double check_Im = numberIm + numberIm_conj;

  ASSERT_DOUBLE_EQ(check_Re, result.getRe());
  ASSERT_DOUBLE_EQ(check_Im, result.getIm());
}

typedef testing::TestWithParam<std::tuple<double, double>>
Chernyh_Daria_ComplexNumberTest_Parametrized;
TEST_P(Chernyh_Daria_ComplexNumberTest_Parametrized,
  Division_of_conjugate) {
  double numberRe = std::get<0>(GetParam());
  double numberIm = std::get<1>(GetParam());
  double numberIm_conj = -numberIm;
  ComplexNumber number(numberRe, numberIm);
  ComplexNumber number_conj(numberRe, numberIm_conj);
  ComplexNumber result = number / number_conj;

  double check_Re = (numberRe * numberRe + numberIm * numberIm_conj)
      / (numberRe * numberRe + numberIm_conj * numberIm_conj);
  double check_Im = (numberRe * numberIm - numberRe * numberIm_conj)
      / (numberRe * numberRe + numberIm_conj * numberIm_conj);

  ASSERT_DOUBLE_EQ(check_Re, result.getRe());
  ASSERT_DOUBLE_EQ(check_Im, result.getIm());
}

TEST(Chernyh_Daria_ComplexNumberTEST, Not_equality_of_conjugate) {
  ComplexNumber number(21, 6);
  ComplexNumber number_conj(21, -6);

  ASSERT_NE(number, number_conj);
}
INSTANTIATE_TEST_CASE_P(/**/, Chernyh_Daria_ComplexNumberTest_Parametrized,
    testing::Combine(
    testing::Values(-1.0, 3.0),
    testing::Values(6.0, -2.0)
));
