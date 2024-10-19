// Copyright 2024 Mironov Ilya

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Mironov_Ilya_ComplexNumberTest, Can_Add_Negative_Complex_Numbers) {
  ComplexNumber z1(-1.2, -2.2);
  ComplexNumber z2(-3.2, -4.2);

  ComplexNumber ans = z1 + z2;

  ASSERT_DOUBLE_EQ(-4.4, ans.getRe());
  ASSERT_DOUBLE_EQ(-6.4, ans.getIm());
}

TEST(Mironov_Ilya_ComplexNumberTest, Can_Multiply_By_Zero) {
  ComplexNumber z1(1.0, 1.0);
  ComplexNumber z2(0.0, 0.0);

  ComplexNumber ans = z1 * z2;

  ASSERT_DOUBLE_EQ(0.0, ans.getRe());
  ASSERT_DOUBLE_EQ(0.0, ans.getIm());
}

TEST(Mironov_Ilya_ComplexNumberTest, Can_Subtract_From_Itself) {
  ComplexNumber z1(2.5, 3.5);

  ComplexNumber ans = z1 - z1;

  ASSERT_DOUBLE_EQ(0.0, ans.getRe());
  ASSERT_DOUBLE_EQ(0.0, ans.getIm());
}

TEST(Mironov_Ilya_ComplexNumberTest, Can_Divide_By_Itself) {
  ComplexNumber z1(3.0, 4.0);

  ComplexNumber ans = z1 / z1;

  ASSERT_DOUBLE_EQ(1.0, ans.getRe());
  ASSERT_DOUBLE_EQ(0.0, ans.getIm());
}

TEST(Mironov_Ilya_ComplexNumberTest, Cant_Divide_By_Zero) {
  ComplexNumber z1(0.0, 0.0);
  ComplexNumber z2(0.0, 0.0);

  ASSERT_ANY_THROW(z1 / z2);
}
