// Copyright 2024 Yurin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Yurin_Andrey_ComplexNumberTest, Constructors) {
  ASSERT_NO_THROW(ComplexNumber());
  ASSERT_NO_THROW(ComplexNumber(-3.0, 5.7));
  ASSERT_NO_THROW(ComplexNumber(ComplexNumber(-212.0342, 432.7342)));
}

TEST(Yurin_Andrey_ComplexNumberTest, AssignmentOperator) {
  ComplexNumber z1(342.324, 345.543);
  ComplexNumber z2(453.412, 2134.435);
  ASSERT_NO_THROW(z2 = z1);

  z2 = z1;

  ASSERT_NE(&z1, &z2);
  ASSERT_DOUBLE_EQ(z2.getRe(), 342.324);
  ASSERT_DOUBLE_EQ(z2.getIm(), 345.543);
}

TEST(Yurin_Andrey_ComplexNumberTest, Getter) {
  ComplexNumber z(321.32, 32.432);

  ASSERT_DOUBLE_EQ(z.getRe(), 321.32);
  ASSERT_DOUBLE_EQ(z.getIm(), 32.432);
}

TEST(Yurin_Andrey_ComplexNumberTest, Setter) {
  ComplexNumber z{};
  z.setRe(213.123);
  z.setIm(-21.312);

  ASSERT_DOUBLE_EQ(z.getRe(), 213.123);
  ASSERT_DOUBLE_EQ(z.getIm(), -21.312);
}

TEST(Yurin_Andrey_ComplexNumberTest, SumOperator) {
  ComplexNumber z1(3.2, 4.4);
  ComplexNumber z2(-3.2, 4.4);

  ComplexNumber z3 = z1 + z2;

  ASSERT_DOUBLE_EQ(z3.getRe(), 0.0);
  ASSERT_DOUBLE_EQ(z3.getIm(), 8.8);
}

TEST(Yurin_Andrey_ComplexNumberTest, DifferenceOperator) {
  ComplexNumber z1(2.5, 53.3);
  ComplexNumber z2(-2.5, 53.3);

  ComplexNumber z3 = z1 - z2;

  ASSERT_DOUBLE_EQ(z3.getRe(), 5.0);
  ASSERT_DOUBLE_EQ(z3.getIm(), 0.0);
}

TEST(Yurin_Andrey_ComplexNumberTest, DivisionOperator) {
  ComplexNumber z1(2.5, 5);
  ComplexNumber z2(-2.5, 5);

  ComplexNumber z3 = z1 / z2;

  ASSERT_DOUBLE_EQ(z3.getRe(), 0.6);
  ASSERT_DOUBLE_EQ(z3.getIm(), -0.8);
  ASSERT_ANY_THROW(ComplexNumber() / ComplexNumber());
}

TEST(Yurin_Andrey_ComplexNumberTest, EqualityOperator) {
  ComplexNumber z1(2.5, 5);
  ComplexNumber z2(-2.5, 5);

  ASSERT_FALSE(z1 == z2);
  ASSERT_TRUE(z1 == ComplexNumber(z1));
}

TEST(Yurin_Andrey_ComplexNumberTest, NotEqualityOperator) {
  ComplexNumber z1(2.5, 5);
  ComplexNumber z2(-2.5, 5);

  ASSERT_TRUE(z1 != z2);
  ASSERT_FALSE(z1 != ComplexNumber(z1));
}
