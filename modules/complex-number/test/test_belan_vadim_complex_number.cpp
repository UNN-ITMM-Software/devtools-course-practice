// Copyright 2024 Belan Vadim

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Belan_Vadim_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;
  ComplexNumber z(re, im);
  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Belan_Vadim_ComplexNumberTest, Can_Add_Two_Complex_Numbers) {
  double re1 = 2.5;
  double im1 = 3.1;
  double re2 = -1.0;
  double im2 = 4.5;
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber sum = z1 + z2;
  EXPECT_EQ(re1 + re2, sum.getRe());
  EXPECT_EQ(im1 + im2, sum.getIm());
}

TEST(Belan_Vadim_ComplexNumberTest, Can_Subtract_Two_Complex_Numbers) {
  double re1 = 5.0;
  double im1 = 2.0;
  double re2 = 1.5;
  double im2 = 3.5;
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber difference = z1 - z2;
  EXPECT_EQ(re1 - re2, difference.getRe());
  EXPECT_EQ(im1 - im2, difference.getIm());
}

TEST(Belan_Vadim_ComplexNumberTest, Can_Multiply_Two_Complex_Numbers) {
  double re1 = 1.5;
  double im1 = 2.0;
  double re2 = 3.0;
  double im2 = -1.0;
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber product = z1 * z2;
  EXPECT_EQ(re1 * re2 - im1 * im2, product.getRe());
  EXPECT_EQ(re1 * im2 + im1 * re2, product.getIm());
}
