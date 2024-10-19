// Copyright 202 Ivanov Nikita

#include <gtest/gtest.h>

#include <tuple>

#include "include/complex_number.h"

TEST(Test_case_Ivanov_Nikita, Constructor) {
  ComplexNumber number;
  ASSERT_EQ(number.getRe(), 0);
  ASSERT_EQ(number.getIm(), 0);
}

TEST(Test_case_Ivanov_Nikita, Copy_constructor) {
  ComplexNumber number;
  ComplexNumber number2(number);

  number2.setRe(1);
  number2.setIm(1);
  ASSERT_EQ(number.getRe(), number2.getRe() - 1);
  ASSERT_EQ(number.getIm(), number2.getIm() - 1);
}

TEST(Test_case_Ivanov_Nikita, Assign_operator) {
  ComplexNumber number;
  ComplexNumber number2 = number;

  number2.setRe(1);
  number2.setIm(1);
  ASSERT_EQ(number.getRe(), number2.getRe() - 1);
  ASSERT_EQ(number.getIm(), number2.getIm() - 1);
}

TEST(Test_case_Ivanov_Nikita, get_real_im_part) {
  ComplexNumber number;

  ASSERT_NO_THROW(number.getRe());
  ASSERT_NO_THROW(number.getIm());
}

TEST(Test_case_Ivanov_Nikita, set_real_im_part) {
  ComplexNumber number;
  ASSERT_NO_THROW(number.setRe(1));
  ASSERT_NO_THROW(number.setIm(1));
}

TEST(Test_case_Ivanov_Nikita, set_real_im_part_2) {
  ComplexNumber number;
  number.setRe(1);
  number.setIm(1.5);

  ASSERT_EQ(number.getRe(), 1);
  ASSERT_EQ(number.getIm(), 1.5);
}

TEST(Test_case_Ivanov_Nikita, operator_plus) {
  ComplexNumber number(-2, 2.5);
  ComplexNumber number2(1, 2);
  ComplexNumber number3 = number + number2;

  ASSERT_EQ(number3.getRe(), -1);
  ASSERT_EQ(number3.getIm(), 4.5);
}

TEST(Test_case_Ivanov_Nikita, operator_minus) {
  ComplexNumber number(-2, 2.5);
  ComplexNumber number2(1, 2);
  ComplexNumber number3 = number - number2;

  ASSERT_EQ(number3.getRe(), -3);
  ASSERT_EQ(number3.getIm(), 0.5);
}

TEST(Test_case_Ivanov_Nikita, operator_mul) {
  ComplexNumber number(-2, 2.5);
  ComplexNumber number2(1, 2);
  ComplexNumber number3 = number * number2;

  ASSERT_EQ(number3.getRe(), -2 * 1 - 2.5 * 2);
  ASSERT_EQ(number3.getIm(), -2 * 2 + 2.5 * 1);
}

TEST(Test_case_Ivanov_Nikita, operator_div) {
  ComplexNumber number(-2, 4);
  ComplexNumber number2(1, 3);
  ComplexNumber number3 = number / number2;

  ASSERT_LE(number3.getRe() - 1, 0.00001);
  ASSERT_LE(number3.getIm() - 1, 0.00001);
}

TEST(Test_case_Ivanov_Nikita, operator_comp) {
  ComplexNumber number(1, 2);
  ComplexNumber number2(1, 2);

  ASSERT_TRUE(number == number2);
}

TEST(Test_case_Ivanov_Nikita, operator_not_comp) {
  ComplexNumber number(1, 2);
  ComplexNumber number2(1, 2);

  ASSERT_FALSE(number != number2);
}
