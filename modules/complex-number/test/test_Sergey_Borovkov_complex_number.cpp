// Copyright 2024 Borovkov Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Borovkov_Sergey_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Borovkov_Sergey_ComplexNumberTest, test_sum) {
  double re1 = 3.25, re2 = 6.12;
  double im1 = 2.0, im2 = 4.0;

  ComplexNumber z1(re1, im1), z2(re2, im2);
  ComplexNumber z = z1 + z2;

  EXPECT_EQ(re1 + re2, z.getRe());
  EXPECT_EQ(im1 + im2, z.getIm());
}

TEST(Borovkov_Sergey_ComplexNumberTest, test_subtraction) {
  double re1 = 3.25, re2 = 6.12;
  double im1 = 2.0, im2 = 4.0;

  ComplexNumber z1(re1, im1), z2(re2, im2);
  ComplexNumber z = z1 - z2;

  EXPECT_EQ(re1 - re2, z.getRe());
  EXPECT_EQ(im1 - im2, z.getIm());
}

TEST(Borovkov_Sergey_ComplexNumberTest, test_multiply) {
  double re1 = 3.25, re2 = 6.12;
  double im1 = 2.0, im2 = 4.0;

  ComplexNumber z1(re1, im1), z2(re2, im2);
  ComplexNumber z = z1 * z2;

  EXPECT_EQ(re1 * re2 - im1 * im2, z.getRe());
  EXPECT_EQ(re1 * im2 + im1 * re2, z.getIm());
}

TEST(Borovkov_Sergey_ComplexNumberTest, test_assignment) {
  double re1 = 3.25;
  double im1 = 2.0;

  ComplexNumber z1(re1, im1);
  ComplexNumber z2(z1);

  EXPECT_EQ(z1, z2);
}
