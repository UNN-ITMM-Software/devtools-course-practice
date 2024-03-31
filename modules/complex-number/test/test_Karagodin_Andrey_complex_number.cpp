// Copyright 2024 Karagodin Andrey
#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Karagodin_Andrey_ComplexNumberTest, Subtraction_negative_Test) {
  double cmp1 = -4.5;
  double im1 = -3.0;
  ComplexNumber num1(cmp1, im1);

  double cmp2 = -2.5;
  double im2 = -5.0;
  ComplexNumber num2(cmp2, im2);

  double cmp3 = -2.0;
  double im3 = 2.0;
  ComplexNumber num3(cmp3, im3);

  EXPECT_EQ(num1 - num2, num3);
}

TEST(Karagodin_Andrey_ComplexNumberTest, Is_Zero_Possible_Test) {
  double cmp = 0.0;
  double im = 0.0;

  ComplexNumber num(cmp, im);
  EXPECT_EQ(cmp, num.getRe());
  EXPECT_EQ(im, num.getIm());
}

TEST(Karagodin_Andrey_ComplexNumberTest, Subtraction_Test) {
  double cmp1 = 3.5;
  double im1 = 5.0;
  ComplexNumber num1(cmp1, im1);

  double cmp2 = 5.5;
  double im2 = 7.0;
  ComplexNumber num2(cmp2, im2);

  double cmp3 = -2.0;
  double im3 = -2.0;
  ComplexNumber num3(cmp3, im3);

  EXPECT_EQ(num1 - num2, num3);
}
TEST(Karagodin_Andrey_ComplexNumberTest, Division_By_Zero_Not_Possible_Test) {
  double re1 = 20.24;
  double im1 = 5.0;
  ComplexNumber num1(re1, im1);

  double re2 = 0.0;
  double im2 = 0.0;
  ComplexNumber num2(re2, im2);

  ASSERT_ANY_THROW(num1 / num2);
}

TEST(Karagodin_Andrey_ComplexNumberTest, Summ_Test) {
  double cmp1 = 9.2;
  double im1 = 6.6;
  ComplexNumber num1(cmp1, im1);

  double cmp2 = 0.8;
  double im2 = 2.0;
  ComplexNumber num2(cmp2, im2);

  double cmp3 = 10.0;
  double im3 = 8.6;
  ComplexNumber num3(cmp3, im3);

  EXPECT_EQ(num1 + num2, num3);
}

TEST(Karagodin_Andrey_ComplexNumberTest, Operation_Equal_Test) {
  double cmp = 2.2;
  double im = 7.0;

  ComplexNumber num1(cmp, im);
  ComplexNumber num2(cmp, im);

  EXPECT_EQ(num1 == num2, true);
}

TEST(Karagodin_Andrey_ComplexNumberTest, Can_Summ_Negative_Test) {
  double cmp1 = -8.4;
  double im1 = -9.0;
  ComplexNumber num1(cmp1, im1);

  double cmp2 = -2.5;
  double im2 = -1.0;
  ComplexNumber num2(cmp2, im2);

  double cmp3 = -10.9;
  double im3 = -10.0;
  ComplexNumber num3(cmp3, im3);

  EXPECT_EQ(num1 + num2, num3);
}
