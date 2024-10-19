// Copyright 2024 Skotin Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Skotin_ALexander_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Skotin_ALexander_ComplexNumberTest, Can_Add_ComplexNumbers) {
  ComplexNumber z1(1.0, 2.0);
  ComplexNumber z2(3.0, 4.0);

  ComplexNumber result = z1 + z2;

  EXPECT_EQ(4.0, result.getRe());
  EXPECT_EQ(6.0, result.getIm());
}

TEST(Skotin_ALexander_ComplexNumberTest, Can_Subtract_ComplexNumbers) {
  ComplexNumber z1(5.0, 6.0);
  ComplexNumber z2(2.0, 3.0);

  ComplexNumber result = z1 - z2;

  EXPECT_EQ(3.0, result.getRe());
  EXPECT_EQ(3.0, result.getIm());
}

TEST(Skotin_ALexander_ComplexNumberTest, Can_Multiply_ComplexNumbers) {
  ComplexNumber z1(2.0, 3.0);
  ComplexNumber z2(4.0, 5.0);

  ComplexNumber result = z1 * z2;

  EXPECT_EQ(-7.0, result.getRe());
  EXPECT_EQ(22.0, result.getIm());
}

TEST(Skotin_ALexander_ComplexNumberTest, Can_Create_Nonzero_Fractional) {
  double re = 2.5;
  double im = -3.7;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Skotin_ALexander_ComplexNumberTest, Can_Add_ComplexNumbers_Fractional) {
  ComplexNumber z1(1.5, 2.5);
  ComplexNumber z2(3.2, 4.7);

  ComplexNumber result = z1 + z2;

  EXPECT_DOUBLE_EQ(4.7, result.getRe());
  EXPECT_DOUBLE_EQ(7.2, result.getIm());
}

TEST(Skotin_ALexander_ComplexNumberTest,
     Can_Subtract_ComplexNumbers_Fractional) {
  ComplexNumber z1(5.5, 6.5);
  ComplexNumber z2(2.2, 3.3);

  ComplexNumber result = z1 - z2;

  EXPECT_DOUBLE_EQ(3.3, result.getRe());
  EXPECT_DOUBLE_EQ(3.2, result.getIm());
}

TEST(Skotin_Alexander_ComplexNumberTest,
     Can_Multiply_ComplexNumbers_Fractional) {
  ComplexNumber z1(2.2, 3.3);
  ComplexNumber z2(4.4, 5.5);

  ComplexNumber result = z1 * z2;

  EXPECT_DOUBLE_EQ(-8.47, result.getRe());
  EXPECT_DOUBLE_EQ(26.62, result.getIm());
}
