// Copyright 2021 Tyurmina Alexandra

#include <gtest/gtest.h>

#include <cmath>

#include "include/complex_number.h"

TEST(Tyurmina_Alexandra_ComplexNumberTest, hypotenuse_and_legs) {
  double re1 = 3.0;
  double im1 = 4.0;
  double re2 = 5.0;
  double im2 = 12.0;

  double res_legs1 = re1 + im1;
  double res1 = hypot(re1, im1);
  double res_legs2 = re2 + im2;
  double res2 = hypot(re2, im2);

  ASSERT_LT(res1, res_legs1);
  ASSERT_LT(res2, res_legs2);
  ASSERT_LT(res2+res1, res_legs2+res_legs1);
}

TEST(Tyurmina_Alexandra_ComplexNumberTest, equal) {
  ComplexNumber a(23.1, 15.6);

  double c = 15.6;
  double d = 23.1;

  double res1 = a.getRe() * c;
  double res2 = a.getIm() * d;

  ASSERT_EQ(res1, res2);
}

TEST(Tyurmina_Alexandra_ComplexNumberTest, not_equal) {
  ComplexNumber a(3.0, 5.0);
  ComplexNumber b(1.0, 4.0);
  ComplexNumber c(1.0, 1.0);
  ComplexNumber d(8.0, 7.0);

  double x = 2.0;

  double res1 = a.getRe() * x;
  double res2 = a.getIm() * x;
  double res3 = b.getRe() * x;
  double res4 = b.getIm() * x;
  double res5 = c.getRe() * x;
  double res6 = c.getIm() * x;
  double res7 = d.getRe() * x;
  double res8 = d.getIm() * x;

  ASSERT_LT(res1, res2);
  ASSERT_GT(res4, res3);
  ASSERT_LE(res5, res6);
  ASSERT_GE(res7, res8);
}
