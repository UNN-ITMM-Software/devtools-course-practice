// Copyright 2024 Smirnov Leonid

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Smirnov_Leonid_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Smirnov_Leonid_ComplexNumberTest, Addition_check) {
  ComplexNumber z1(3.0, 6.0);
  ComplexNumber z2(-6.0, -3.0);

  ComplexNumber result = z1 + z2;

  EXPECT_DOUBLE_EQ(result.getRe(), -3.0);
  EXPECT_DOUBLE_EQ(result.getIm(), 3.0);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Difference_check) {
  ComplexNumber z1(3.0, 6.0);
  ComplexNumber z2(-6.0, -3.0);

  ComplexNumber result = z1 - z2;

  EXPECT_DOUBLE_EQ(result.getRe(), 9.0);
  EXPECT_DOUBLE_EQ(result.getIm(), 9.0);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Equality_check) {
  ComplexNumber z1(3.0, 6.0);
  ComplexNumber z2(3.0, 6.0);
  ComplexNumber z3(2.0, 6.0);

  EXPECT_TRUE(z1 == z2);
  EXPECT_FALSE(z1 == z3);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Multiplication_check) {
  ComplexNumber z1(3.0, 2.0);
  ComplexNumber z2(6.0, 3.0);

  ComplexNumber result = z1 * z2;

  EXPECT_DOUBLE_EQ(result.getRe(), 12.0);
  EXPECT_DOUBLE_EQ(result.getIm(), 21.0);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Addition_Commutativity_check) {
  ComplexNumber z1(3.0, 2.0);
  ComplexNumber z2(6.0, 3.0);

  ComplexNumber result1 = z1 + z2;
  ComplexNumber result2 = z2 + z1;

  EXPECT_TRUE(result1 == result2);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Multiplication_Commutativity_check) {
  ComplexNumber z1(3.0, 2.0);
  ComplexNumber z2(6.0, 3.0);

  ComplexNumber result1 = z1 * z2;
  ComplexNumber result2 = z2 * z1;

  EXPECT_TRUE(result1 == result2);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Addition_Associativity_check) {
  ComplexNumber z1(3.0, 2.0);
  ComplexNumber z2(6.0, 3.0);
  ComplexNumber z3(1.0, 5.0);

  ComplexNumber result1 = (z1 + z2) + z3;
  ComplexNumber result2 = z1 + (z2 + z3);

  EXPECT_TRUE(result1 == result2);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Multiplication_Associativity_check) {
  ComplexNumber z1(3.0, 2.0);
  ComplexNumber z2(6.0, 3.0);
  ComplexNumber z3(1.0, 5.0);

  ComplexNumber result1 = (z1 * z2) * z3;
  ComplexNumber result2 = z1 * (z2 * z3);

  EXPECT_TRUE(result1 == result2);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Distributivity_check) {
  ComplexNumber z1(3.0, 2.0);
  ComplexNumber z2(6.0, 3.0);
  ComplexNumber z3(1.0, 5.0);

  ComplexNumber result1 = z1 * (z2 + z3);
  ComplexNumber result2 = z1 * z2 + z1 * z3;

  EXPECT_TRUE(result1 == result2);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Multiplication_By_Zero_check) {
  ComplexNumber z1(3.0, 2.0);
  ComplexNumber z2(0.0, 0.0);

  ComplexNumber result1 = z1 * z2;

  EXPECT_DOUBLE_EQ(result1.getRe(), 0.0);
  EXPECT_DOUBLE_EQ(result1.getIm(), 0.0);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Division_By_Zero_check) {
  ComplexNumber z1(3.0, 2.0);
  ComplexNumber z2(0.0, 0.0);

  ASSERT_ANY_THROW(z1 / z2);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Addition_Fractional_Numbers_check) {
  ComplexNumber z1(3.5, 6.5);
  ComplexNumber z2(3.2, 6.8);

  ComplexNumber result = z1 + z2;

  EXPECT_DOUBLE_EQ(result.getRe(), 6.7);
  EXPECT_DOUBLE_EQ(result.getIm(), 13.3);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Difference_Fractional_Numbers_check) {
  ComplexNumber z1(3.5, 6.5);
  ComplexNumber z2(3.2, 6.8);

  ComplexNumber result = z1 - z2;

  EXPECT_DOUBLE_EQ(result.getRe(), 0.3);
  EXPECT_DOUBLE_EQ(result.getIm(), -0.3);
}

TEST(Smirnov_Leonid_ComplexNumberTest, Multiplication_By_Zero_Frac_check) {
  ComplexNumber z1(3.5, 6.5);
  ComplexNumber z2(0.0, 0.0);

  ComplexNumber result1 = z1 * z2;

  EXPECT_DOUBLE_EQ(result1.getRe(), 0.0);
  EXPECT_DOUBLE_EQ(result1.getIm(), 0.0);
}
