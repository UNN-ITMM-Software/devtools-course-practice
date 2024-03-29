// Copyright 2024 Konovalov Igor

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Konovalov_Igor_ComplexNumberTest, can_create_zero) {
  // Arrange
  double re = 0.0;
  double im = 0.0;

  // Act
  ComplexNumber z(re, im);

  // Assert
  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Konovalov_Igor_ComplexNumberTest, can_add_correctly) {
  // Arrange
  double re1 = 1.0;
  double im1 = 1.0;
  double re2 = 2.0;
  double im2 = 2.0;
  double re_res = 3.0;
  double im_res = 3.0;

  // Act
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber res = z1 + z2;

  // Assert
  EXPECT_EQ(re_res, res.getRe());
  EXPECT_EQ(im_res, res.getIm());
}

TEST(Konovalov_Igor_ComplexNumberTest, can_substract_correctly) {
  // Arrange
  double re1 = 1.0;
  double im1 = 1.0;
  double re2 = 2.0;
  double im2 = 2.0;
  double re_res = -1.0;
  double im_res = -1.0;

  // Act
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber res = z1 - z2;

  // Assert
  EXPECT_EQ(re_res, res.getRe());
  EXPECT_EQ(im_res, res.getIm());
}

TEST(Konovalov_Igor_ComplexNumberTest, can_multiply_correctly) {
  // Arrange
  double re1 = 1.0;
  double im1 = 1.0;
  double re2 = 2.0;
  double im2 = 2.0;
  double re_res = (re1 * re2) - (im1 * im2);
  double im_res = (re1 * im2) + (re2 * im1);

  // Act
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber res = z1 * z2;

  // Assert
  EXPECT_EQ(re_res, res.getRe());
  EXPECT_EQ(im_res, res.getIm());
}

TEST(Konovalov_Igor_ComplexNumberTest, can_divide_correctly) {
  // Arrange
  double re1 = 1.0;
  double im1 = 1.0;
  double re2 = 2.0;
  double im2 = 2.0;
  double re_res = (re1 * re2 + im1 * im2) / (re2 * re2 + im2 * im2);
  double im_res = (im1 * re2 - re1 * im2) / (re2 * re2 + im2 * im2);

  // Act
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber res = z1 / z2;

  // Assert
  EXPECT_EQ(re_res, res.getRe());
  EXPECT_EQ(im_res, res.getIm());
}

TEST(Konovalov_Igor_ComplexNumberTest, division_by_zero_fails) {
  // Arrange
  double re = 1.0;
  double im = 1.0;

  // Act
  ComplexNumber z(re, im);
  ComplexNumber d(0.0, 0.0);

  // Assert
  ASSERT_ANY_THROW(z / d);
}
