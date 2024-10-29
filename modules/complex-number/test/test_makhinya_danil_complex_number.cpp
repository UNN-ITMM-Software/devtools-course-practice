// Copyright 2024 Makhinya Danil

#include <gtest/gtest.h>

#include <tuple>

#include "include/complex_number.h"

TEST(Makhinya_Danil_ComplexNumberTest, CorrectAssignRe) {
  ComplexNumber number;
  const double Re = 8.0;
  number.setRe(8.0);
  ASSERT_DOUBLE_EQ(number.getRe(), Re);
}

TEST(Makhinya_Danil_ComplexNumberTest, CorrectAssignIm) {
  ComplexNumber number;
  const double Im = 8.0;
  number.setIm(8.0);
  ASSERT_DOUBLE_EQ(number.getIm(), Im);
}

TEST(Makhinya_Danil_ComplexNumberTest, Constructor) {
  const double Re = 7.0;
  const double Im = 8.0;
  ComplexNumber number(Re, Im);
  ASSERT_DOUBLE_EQ(number.getRe(), Re);
  ASSERT_DOUBLE_EQ(number.getIm(), Im);
}

TEST(Makhinya_Danil_ComplexNumberTest, Sum) {
  const double Re1 = 7.0;
  const double Im1 = 8.0;
  ComplexNumber number1(Re1, Im1);

  const double Re2 = 3.0;
  const double Im2 = 4.0;
  ComplexNumber number2(Re2, Im2);

  ComplexNumber res = number1 + number2;
  ASSERT_DOUBLE_EQ(res.getRe(), Re1 + Re2);
  ASSERT_DOUBLE_EQ(res.getIm(), Im1 + Im2);
}

TEST(Makhinya_Danil_ComplexNumberTest, Mul) {
  const double Re1 = 7.0;
  const double Im1 = 8.0;
  ComplexNumber number1(Re1, Im1);

  const double Re2 = 3.0;
  const double Im2 = 4.0;
  ComplexNumber number2(Re2, Im2);

  ComplexNumber res = number1 * number2;
  ASSERT_DOUBLE_EQ(res.getRe(), Re1 * Re2 - Im1 * Im2);
  ASSERT_DOUBLE_EQ(res.getIm(), Re1 * Im2 + Re2 * Im1);
}

TEST(Makhinya_Danil_ComplexNumberTest, Div) {
  const double Re1 = 7.5;
  const double Im1 = 8.3;
  ComplexNumber number1(Re1, Im1);

  const double Re2 = 3.8;
  const double Im2 = 4.9;
  ComplexNumber number2(Re2, Im2);

  ComplexNumber res = number1 / number2;

  const double K = Re2 * Re2 + Im2 * Im2;
  const double resRe = (Re1 * Re2 + Im1 * Im2) / K;
  const double resIm = (-Re1 * Im2 + Re2 * Im1) / K;
  ASSERT_DOUBLE_EQ(res.getRe(), resRe);
  ASSERT_DOUBLE_EQ(res.getIm(), resIm);
}

TEST(Makhinya_Danil_ComplexNumberTest, Sub) {
  const double Re1 = 7.5;
  const double Im1 = 8.3;
  ComplexNumber number1(Re1, Im1);

  const double Re2 = 3.8;
  const double Im2 = 4.9;
  ComplexNumber number2(Re2, Im2);

  ComplexNumber res = number1 - number2;

  ASSERT_DOUBLE_EQ(res.getRe(), Re1 - Re2);
  ASSERT_DOUBLE_EQ(res.getIm(), Im1 - Im2);
}
