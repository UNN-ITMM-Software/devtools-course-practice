// Copyright 2021 Gruzdeva Diana

#include <gtest/gtest.h>

#include <string>
#include <limits>
#include <iostream>

#include "include/complex_number.h"

TEST(Gruzdeva_Diana_ComplexNumberTest, Long_equation) {
  double resultRe = 4.2030000000000029;
  double resultIm = 16.7734000000000093;
  double re1 = 5.24;
  double im1 = 4.53;
  double re2 = 25.82;
  double im2 = -3.26;
  double re3 = 12.72;
  double im3 = -7.04;
  double re4 = -6.01;
  double im4 = -9.86;
  double error = std::numeric_limits<double>::epsilon();

  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber z3(re3, im3);
  ComplexNumber z4(re4, im4);
  ComplexNumber zReal = z1 * z2 + z3 * z4;
  std::cout << std::fixed << std::setprecision(25) << zReal.getIm();
  ASSERT_NEAR(resultRe, zReal.getRe(), error);
  ASSERT_NEAR(resultIm, zReal.getIm(), error);
}

TEST(Gruzdeva_Diana_ComplexNumberTest, Strings) {
  std::string result = "-5.584201 -2.654666i";
  double re = -5.584201;
  double im = -2.654666;

  ComplexNumber z(re, im);
  std::string parsed = std::to_string(z.getRe()) + " " +
                       std::to_string(z.getIm())+"i";

  ASSERT_EQ(result, parsed);
}

TEST(Gruzdeva_Diana_ComplexNumberTest, Reciprocal) {
  double re1 = 1.0;
  double im1 = -1.0;
  double re2 = re1 / (re1 * re1 + im1 * im1);
  double im2 = (-1) * im1 / (re1 * re1 + im1 * im1);

  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber z(0.0, 0.0);
  z = z1 * z2;

  ASSERT_EQ(1, z.getRe());
  ASSERT_EQ(0, z.getIm());
}
