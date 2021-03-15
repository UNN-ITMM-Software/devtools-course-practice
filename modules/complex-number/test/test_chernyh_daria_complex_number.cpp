// Copyright 2021 Chernyh Daria

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Chernyh_Daria_ComplexNumberTEST, Addition_of_conjugate) {
  ComplexNumber number(21, 6);
  ComplexNumber number_conj(21, -6);
  ComplexNumber result = number + number_conj;
  ComplexNumber check_res(number.getRe() + number.getRe(), 0);

  ASSERT_EQ(check_res, result);
}

TEST(Chernyh_Daria_ComplexNumberTEST, Multiply_of_conjugate) {
  ComplexNumber number(21, 6);
  ComplexNumber number_conj(21, -6);
  ComplexNumber result = number * number_conj;
  ComplexNumber check_res(number.getRe() * number.getRe()
    + number.getIm() * number.getIm(), 0);

  ASSERT_EQ(check_res, result);
}

TEST(Chernyh_Daria_ComplexNumberTEST, Division_by_zero) {
  ComplexNumber number(21, 6);
  ComplexNumber number_zero(0, 0);
   
  ASSERT_ANY_THROW(number / number_zero);
}

TEST(Chernyh_Daria_ComplexNumberTEST, Not_equality_of_conjugate) {
  ComplexNumber number(21, 6);
  ComplexNumber number_conj(21, -6);

  ASSERT_NE(number, number_conj);
}
