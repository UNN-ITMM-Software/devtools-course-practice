// Copyright 2024 Fedorets Ilya

#include <gtest/gtest.h>

#include <limits>

#include "include/complex_number.h"

class Fedorets_Ilya_ComplexNumberTest : public ::testing::Test {
 protected:
  const double eps = std::numeric_limits<double>::epsilon();
};

// Test default constructor
TEST_F(Fedorets_Ilya_ComplexNumberTest, DefaultConstructor) {
  ComplexNumber z;
  EXPECT_DOUBLE_EQ(z.getRe(), 0.0);
  EXPECT_DOUBLE_EQ(z.getIm(), 0.0);
}

// Test parameterized constructor
TEST_F(Fedorets_Ilya_ComplexNumberTest, ParameterizedConstructor) {
  ComplexNumber z(3.14, 2.71);
  EXPECT_DOUBLE_EQ(z.getRe(), 3.14);
  EXPECT_DOUBLE_EQ(z.getIm(), 2.71);
}

// Test copy constructor
TEST_F(Fedorets_Ilya_ComplexNumberTest, CopyConstructor) {
  ComplexNumber original(1.23, 4.56);
  ComplexNumber copy(original);
  EXPECT_DOUBLE_EQ(copy.getRe(), 1.23);
  EXPECT_DOUBLE_EQ(copy.getIm(), 4.56);
}

// Test assignment operator
TEST_F(Fedorets_Ilya_ComplexNumberTest, AssignmentOperator) {
  ComplexNumber z1(1.0, 2.0);
  ComplexNumber z2;
  z2 = z1;
  EXPECT_DOUBLE_EQ(z2.getRe(), 1.0);
  EXPECT_DOUBLE_EQ(z2.getIm(), 2.0);
}

// Test getter and setter methods
TEST_F(Fedorets_Ilya_ComplexNumberTest, GetterSetterMethods) {
  ComplexNumber z;
  z.setRe(5.0);
  z.setIm(-3.0);
  EXPECT_DOUBLE_EQ(z.getRe(), 5.0);
  EXPECT_DOUBLE_EQ(z.getIm(), -3.0);
}

// Test addition operator
TEST_F(Fedorets_Ilya_ComplexNumberTest, AdditionOperator) {
  ComplexNumber z1(1.0, 2.0);
  ComplexNumber z2(3.0, 4.0);
  ComplexNumber sum = z1 + z2;
  EXPECT_DOUBLE_EQ(sum.getRe(), 4.0);
  EXPECT_DOUBLE_EQ(sum.getIm(), 6.0);
}

// Test subtraction operator
TEST_F(Fedorets_Ilya_ComplexNumberTest, SubtractionOperator) {
  ComplexNumber z1(5.0, 7.0);
  ComplexNumber z2(2.0, 3.0);
  ComplexNumber diff = z1 - z2;
  EXPECT_DOUBLE_EQ(diff.getRe(), 3.0);
  EXPECT_DOUBLE_EQ(diff.getIm(), 4.0);
}

// Test multiplication operator
TEST_F(Fedorets_Ilya_ComplexNumberTest, MultiplicationOperator) {
  ComplexNumber z1(2.0, 3.0);
  ComplexNumber z2(4.0, 5.0);
  ComplexNumber mult = z1 * z2;
  EXPECT_DOUBLE_EQ(mult.getRe(), -7.0);  // (2*4 - 3*5)
  EXPECT_DOUBLE_EQ(mult.getIm(), 22.0);  // (2*5 + 3*4)
}

// Test division operator
TEST_F(Fedorets_Ilya_ComplexNumberTest, DivisionOperator) {
  ComplexNumber z1(1.0, 2.0);
  ComplexNumber z2(3.0, 4.0);
  ComplexNumber div = z1 / z2;

  // Expected values calculated manually
  EXPECT_NEAR(div.getRe(), 0.44, eps);
  EXPECT_NEAR(div.getIm(), 0.08, eps);
}

// Test division by zero
TEST_F(Fedorets_Ilya_ComplexNumberTest, DivisionByZero) {
  ComplexNumber z1(1.0, 2.0);
  ComplexNumber z2(0.0, 0.0);

  EXPECT_THROW({ z1 / z2; }, std::string);
}

// Test equalsZero method
// TEST_F(Fedorets_Ilya_ComplexNumberTest, EqualsZero) {
//   ComplexNumber z1(0.0, 0.0);
//   ComplexNumber z2(eps / 2.0, eps / 2.0);
//   ComplexNumber z3(eps * 2.0, eps * 2.0);

//   EXPECT_TRUE(ComplexNumber::equalsZero(z1));
//   EXPECT_TRUE(ComplexNumber::equalsZero(z2));
//   EXPECT_FALSE(ComplexNumber::equalsZero(z3));
// }

// Test equality operator
TEST_F(Fedorets_Ilya_ComplexNumberTest, EqualityOperator) {
  ComplexNumber z1(1.0, 2.0);
  ComplexNumber z2(1.0, 2.0);
  ComplexNumber z3(1.1, 2.0);

  EXPECT_TRUE(z1 == z2);
  EXPECT_FALSE(z1 == z3);
}

// Test inequality operator
TEST_F(Fedorets_Ilya_ComplexNumberTest, InequalityOperator) {
  ComplexNumber z1(1.0, 2.0);
  ComplexNumber z2(1.1, 2.0);

  EXPECT_TRUE(z1 != z2);
}

// Test edge cases
TEST_F(Fedorets_Ilya_ComplexNumberTest, EdgeCases) {
  // Very small numbers
  ComplexNumber z1(1e-300, 1e-300);
  ComplexNumber z2(1e-300, 1e-300);
  EXPECT_TRUE(z1 == z2);

  // Very large numbers
  ComplexNumber z3(1e300, 1e300);
  ComplexNumber z4(1e300, 1e300);
  EXPECT_TRUE(z3 == z4);
}

// Test complex arithmetic properties
TEST_F(Fedorets_Ilya_ComplexNumberTest, ArithmeticProperties) {
  ComplexNumber z1(3.0, 4.0);
  ComplexNumber z2(1.0, 2.0);
  ComplexNumber z3(2.0, 3.0);

  // Associative property of addition
  ComplexNumber sum1 = (z1 + z2) + z3;
  ComplexNumber sum2 = z1 + (z2 + z3);
  EXPECT_TRUE(sum1 == sum2);

  // Distributive property
  ComplexNumber dist1 = z1 * (z2 + z3);
  ComplexNumber dist2 = z1 * z2 + z1 * z3;
  EXPECT_TRUE(dist1 == dist2);
}

// Test complex number with zero
TEST_F(Fedorets_Ilya_ComplexNumberTest, ZeroOperations) {
  ComplexNumber z1(1.0, 2.0);
  ComplexNumber zero(0.0, 0.0);

  // Addition with zero
  EXPECT_TRUE(z1 + zero == z1);

  // Subtraction with zero
  EXPECT_TRUE(z1 - zero == z1);

  // Multiplication with zero
  EXPECT_TRUE(z1 * zero == zero);
}
