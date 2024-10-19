// Copyright 2024 Safarov Nurlan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Safarov_Nurlan_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Safarov_Nurlan_ComplexNumberTest, Multiplication_Of_Complex_Numbers) {
  ComplexNumber a(1.0, 1.0);
  ComplexNumber b(4.0, -2.0);

  ComplexNumber c = a * b;

  EXPECT_DOUBLE_EQ(c.getRe(), 6.0);
  EXPECT_DOUBLE_EQ(c.getIm(), 2.0);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Division_Of_Complex_Numbers) {
  ComplexNumber a(1.0, 2.0);
  ComplexNumber b(4.0, 3.0);

  ComplexNumber c = a / b;

  EXPECT_DOUBLE_EQ(c.getRe(), 0.4);
  EXPECT_DOUBLE_EQ(c.getIm(), 0.2);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Addition_Of_Complex_Numbers) {
  ComplexNumber a(5.2, 7.1);
  ComplexNumber b(3.3, 9.9);

  ComplexNumber c = a + b;

  EXPECT_DOUBLE_EQ(c.getRe(), 8.5);
  EXPECT_DOUBLE_EQ(c.getIm(), 17.0);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Subtraction_Of_Complex_Numbers) {
  ComplexNumber a(-1.0, 4.0);
  ComplexNumber b(3.0, 1.0);

  ComplexNumber c = a - b;

  EXPECT_DOUBLE_EQ(c.getRe(), -4.0);
  EXPECT_DOUBLE_EQ(c.getIm(), 3.0);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Dividing_A_Complex_Number_By_Zero) {
  ComplexNumber a(3.0, 5.0);
  ComplexNumber b(0.0, 0.0);

  ASSERT_ANY_THROW(a / b);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Multiplication_By_Zero) {
  ComplexNumber a(3.0, 5.0);
  ComplexNumber b(0.0, 0.0);

  ComplexNumber c = a * b;

  EXPECT_DOUBLE_EQ(c.getRe(), 0.0);
  EXPECT_DOUBLE_EQ(c.getIm(), 0.0);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Equality_Of_Complex_Numbers_True) {
  ComplexNumber a(8.0, 8.0);
  ComplexNumber b(8.0, 8.0);

  EXPECT_TRUE(a == b);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Equality_Of_Complex_Numbers_False) {
  ComplexNumber a(11.0, 11.0);
  ComplexNumber b(11.0, 11.0);

  EXPECT_FALSE(a != b);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Complex_Number_Inequality) {
  ComplexNumber a(-4.0, 10.0);
  ComplexNumber b(7.0, 12.0);

  EXPECT_TRUE(a != b);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Commutativity_Of_Addition) {
  ComplexNumber a(4.0, 10.0);
  ComplexNumber b(7.0, 12.0);

  ComplexNumber leftSide = a + b;
  ComplexNumber rightSide = b + a;

  EXPECT_TRUE(leftSide == rightSide);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Addition_Associativity) {
  ComplexNumber a(4.0, 10.0);
  ComplexNumber b(7.0, 12.0);
  ComplexNumber c(3.0, 15.0);

  ComplexNumber leftSide = a + (b + c);
  ComplexNumber rightSide = (a + b) + c;

  EXPECT_TRUE(leftSide == rightSide);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Commutativity_For_Multiplication) {
  ComplexNumber a(1.0, 2.0);
  ComplexNumber b(-3.0, 4.0);

  ComplexNumber leftSide = a * b;
  ComplexNumber rightSide = b * a;

  EXPECT_TRUE(leftSide == rightSide);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Associativity_For_Multiplication) {
  ComplexNumber a(1.0, 2.0);
  ComplexNumber b(3.0, 4.0);
  ComplexNumber c(5.0, 6.0);

  ComplexNumber leftSide = a * (b * c);
  ComplexNumber rightSide = (a * b) * c;

  EXPECT_TRUE(leftSide == rightSide);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Unit_Property_For_Multiplication) {
  ComplexNumber a(20.5, -3.94);
  ComplexNumber b(1.0, 0.0);

  ComplexNumber leftSide = a * b;
  ComplexNumber rightSide = a;

  EXPECT_TRUE(leftSide == rightSide);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Distributivity_For_Multiplication) {
  ComplexNumber a(-1.0, 2.0);
  ComplexNumber b(5.0, -6.0);
  ComplexNumber c(-3.0, 4.0);

  ComplexNumber leftSide = a * (b + c);
  ComplexNumber rightSide = a * b + a * c;

  EXPECT_TRUE(leftSide == rightSide);
}

TEST(Safarov_Nurlan_ComplexNumberTest, Setter_Check) {
  ComplexNumber a;

  ASSERT_NO_THROW(a.setRe(5.25));
  ASSERT_NO_THROW(a.setIm(-10.80));
}

TEST(Safarov_Nurlan_ComplexNumberTest, Getter_Check) {
  ComplexNumber a(1.0, 7.0);

  ASSERT_NO_THROW(a.getRe());
  ASSERT_NO_THROW(a.getIm());
}
