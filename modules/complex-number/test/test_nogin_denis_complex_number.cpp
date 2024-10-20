// Copyright 2024 Nogin Denis

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Nogin_Denis_ComplexNumberTest, test_get) {
  double re = 4.4;
  double im = 3.2;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Nogin_Denis_ComplexNumberTest, test_set) {
  double re = 4.4;
  double im = 3.2;

  ComplexNumber z;

  z.setIm(im);
  z.setRe(re);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Nogin_Denis_ComplexNumberTest, test_assign) {
  double re1 = 4.4;
  double im1 = 3.2;

  ComplexNumber z1(re1, im1);
  ComplexNumber z2;

  z2 = z1;

  EXPECT_EQ(z1.getRe(), z2.getRe());
  EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Nogin_Denis_ComplexNumberTest, test_div_by_zero) {
  ComplexNumber z1(4.4, 3.2);
  ComplexNumber z2(0, 0);

  EXPECT_ANY_THROW(z1 / z2);
}

TEST(Nogin_Denis_ComplexNumberTest, test_create_number) {
  ComplexNumber z1(4.4, 3.2);
  ComplexNumber z2(z1);

  EXPECT_EQ(z1, z2);
}
