// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>

#include <limits>

#include "include/complex_number.h"

TEST(Chirkov_Roman_ComplexNumberTest, division_by_approximately_zero) {
  ComplexNumber z1(123.45011, 321);
  double eps = std::numeric_limits<double>::epsilon();
  double lessThanEpsilon = eps / 2;
  ComplexNumber z2(0.0, lessThanEpsilon);

  ASSERT_ANY_THROW(z1 / z2);
}

TEST(Chirkov_Roman_ComplexNumberTest, subtraction_then_addition) {
  ComplexNumber z1(1, 15.0034);
  ComplexNumber z2(16, -4);

  ComplexNumber subtExp(-15, 19.0034);
  ComplexNumber subtRes = z1 - z2;

  ASSERT_EQ(subtExp, subtRes);

  ComplexNumber addRes = subtRes + z2;

  ASSERT_EQ(z1, addRes);
}

TEST(Chirkov_Roman_ComplexNumberTest, multiplication_then_division) {
  ComplexNumber z1(100, -100.1);
  ComplexNumber z2(-10, -123.456);

  ComplexNumber multExp(-13357.9456, -11344.6);
  ComplexNumber multRes = z1 * z2;

  ASSERT_EQ(multExp, multRes);

  ComplexNumber divRes = multRes / z2;
  ASSERT_EQ(z1, divRes);
}
