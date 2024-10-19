// Copyright 2024 Safronov Mikhail

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Safronov_Mikhail_ComplexNumberTest, test_get) {
  double re = 5.5;
  double im = 2.3;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Safronov_Mikhail_ComplexNumberTest, test_set) {
  double re = 5.5;
  double im = 2.3;

  ComplexNumber z;

  z.setIm(im);
  z.setRe(re);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Safronov_Mikhail_ComplexNumberTest, test_assign) {
  double re1 = 5.5;
  double im1 = 2.3;

  ComplexNumber z1(re1, im1);
  ComplexNumber z2;

  z2 = z1;

  EXPECT_EQ(z1.getRe(), z2.getRe());
  EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Safronov_Mikhail_ComplexNumberTest, test_div_by_zero) {
  ComplexNumber z1(5.5, 2.3);
  ComplexNumber z2(0, 0);

  EXPECT_ANY_THROW(z1 / z2);
}

TEST(Safronov_Mikhail_ComplexNumberTest, test_create_number) {
  ComplexNumber z1(5.5, 2.3);
  ComplexNumber z2(z1);

  EXPECT_EQ(z1, z2);
}
