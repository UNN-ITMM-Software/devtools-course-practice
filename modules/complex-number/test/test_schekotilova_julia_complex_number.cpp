
// Copyright 2021 Schekotilova Julia

#include <gtest/gtest.h>

#include <cmath>

#include "include/complex_number.h"



TEST(Schekotilova_Julia_ComplexNumberTest, Can_be_double) {
  // Arrange
  double re = 120.23;
  double im = 1.11;

  // Act
  ComplexNumber z(re, im);
  // Assert
  ASSERT_EQ(im, z.getIm());
  ASSERT_EQ(re, z.getRe());
}

TEST(Schekotilova_Julia_ComplexNumberTest, Division) {
  // Arrange
  double re = 10.0;
  double im = 10.0;
  double re1 = 5.0;
  double im1 = 5.0;
  double res = 2.0;
  // Act
  ComplexNumber z(re, im);
  ComplexNumber z1(re1, im1);
  // Assert
  ASSERT_EQ(res, z.getRe() / z1.getIm());
  ASSERT_EQ(res, z.getIm() / z1.getIm());
}

TEST(Schekotilova_Julia_ComplexNumberTest, Comparison) {
  // Arrange
  double re = 12.4;
  double im = 12.4;
  // Act
  ComplexNumber z1(re, im);
  // Assert
  ASSERT_LT(0.0, sqrt(z1.getRe() * z1.getRe() + z1.getIm() * z1.getIm()));
}
