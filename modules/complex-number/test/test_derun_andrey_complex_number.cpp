// Copyright 2024 Derun Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Derun_Andrey_ComplexNumberTest, DefaultConstructor) {
  ComplexNumber number;
  ASSERT_EQ(number.getRe(), 0);
  ASSERT_EQ(number.getIm(), 0);
}

TEST(Derun_Andrey_ComplexNumberTest, TwoParamConstructor) {
  ComplexNumber number(2.5, 5.0);
  ASSERT_EQ(number.getRe(), 2.5);
  ASSERT_EQ(number.getIm(), 5.0);
}

TEST(Derun_Andrey_ComplexNumberTest, CopyConstructor) {
  ComplexNumber number(2.5, 5.0);
  ComplexNumber copy_number(number);
  ASSERT_EQ(copy_number.getRe(), 2.5);
  ASSERT_EQ(copy_number.getIm(), 5.0);
}

TEST(Derun_Andrey_ComplexNumberTest, AssignmentOperator) {
  ComplexNumber number(2.5, 5.0);
  ComplexNumber copy_number;
  copy_number = number;
  ASSERT_EQ(copy_number.getRe(), 2.5);
  ASSERT_EQ(copy_number.getIm(), 5.0);
}

TEST(Derun_Andrey_ComplexNumberTest, GetReMethod) {
  ComplexNumber number(2.5, 5.0);
  ASSERT_EQ(number.getRe(), 2.5);
}

TEST(Derun_Andrey_ComplexNumberTest, GetImMethod) {
  ComplexNumber number(2.5, 5.0);
  ASSERT_EQ(number.getIm(), 5.0);
}

TEST(Derun_Andrey_ComplexNumberTest, SetReMethod) {
  ComplexNumber number(2.5, 5.0);
  number.setRe(-3.0);
  ASSERT_EQ(number.getRe(), -3.0);
}

TEST(Derun_Andrey_ComplexNumberTest, SetImMethod) {
  ComplexNumber number(2.5, 5.0);
  number.setIm(10.5);
  ASSERT_EQ(number.getIm(), 10.5);
}

TEST(Derun_Andrey_ComplexNumberTest, PlusOperator) {
  ComplexNumber number_a(2.5, 5.0);
  ComplexNumber number_b(-3.0, 10.5);
  ComplexNumber number_c = number_a + number_b;
  ASSERT_EQ(number_c.getRe(), -0.5);
  ASSERT_EQ(number_c.getIm(), 15.5);
}

TEST(Derun_Andrey_ComplexNumberTest, MinusOperator) {
  ComplexNumber number_a(2.5, 5.0);
  ComplexNumber number_b(-3.0, 10.5);
  ComplexNumber number_c = number_a - number_b;
  ASSERT_EQ(number_c.getRe(), 5.5);
  ASSERT_EQ(number_c.getIm(), -5.5);
}

TEST(Derun_Andrey_ComplexNumberTest, MultiplyOperator) {
  ComplexNumber number_a(2.5, 5.0);
  ComplexNumber number_b(-3.0, 10.5);
  ComplexNumber number_c = number_a * number_b;
  ASSERT_EQ(number_c.getRe(), -60.0);
  ASSERT_EQ(number_c.getIm(), 11.25);
}

TEST(Derun_Andrey_ComplexNumberTest, DivisionOperatorThrow) {
  ComplexNumber number_a(2.5, 5.0);
  ComplexNumber number_b;
  ASSERT_ANY_THROW(number_a / number_b);
}

TEST(Derun_Andrey_ComplexNumberTest, DivisionOperator) {
  ComplexNumber number_a(2.5, 5.0);
  ComplexNumber number_b(-3.0, 10.5);
  ComplexNumber number_c = number_a / number_b;
  // printf("%f %f", number_c.getRe(), number_c.getIm());
  ASSERT_NEAR(number_c.getRe(), 0.37735, 0.00001);
  ASSERT_NEAR(number_c.getIm(), -0.34591, 0.00001);
}

TEST(Derun_Andrey_ComplexNumberTest, EqualsOperator) {
  ComplexNumber number_a(2.5, 5.0);
  ComplexNumber number_b(2.5, 5.0);
  ASSERT_TRUE(number_a == number_b);
}

TEST(Derun_Andrey_ComplexNumberTest, NotEqualsOperator) {
  ComplexNumber number_a(2.5, 5.0);
  ComplexNumber number_b(-3.0, 10.5);
  ASSERT_FALSE(number_a == number_b);
}
