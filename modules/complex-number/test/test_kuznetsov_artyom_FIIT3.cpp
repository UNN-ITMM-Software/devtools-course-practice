// Copyright 2024 Kuznetsov Artyom

#include <gtest/gtest.h>

#include <cmath>
#include <random>

#include "include/complex_number.h"

static bool isEqual(double a, double b, double eps = 1.0e-6) {
  return std::fabs(a - b) <= eps;
}

TEST(Test_case_Kuznetsov_Artyom_FIIT3, testSet) {
  ComplexNumber value{};

  ASSERT_NO_THROW(value.setRe(1));
  ASSERT_NO_THROW(value.setIm(1));
}

TEST(Test_case_Kuznetsov_Artyom_FIIT3, testGet) {
  ComplexNumber value{};

  ASSERT_NO_THROW(value.getRe());
  ASSERT_NO_THROW(value.getIm());
}

TEST(Test_case_Kuznetsov_Artyom_FIIT3, testDivZero) {
  ASSERT_ANY_THROW(ComplexNumber() / ComplexNumber());
}

TEST(Test_case_Kuznetsov_Artyom_FIIT3, testEq) {
  ASSERT_TRUE(ComplexNumber(777.5, 0.1) == ComplexNumber(777.5, 0.1));
}

TEST(Test_case_Kuznetsov_Artyom_FIIT3, testNotEq) {
  ASSERT_FALSE(ComplexNumber(777.5, 0.1) != ComplexNumber(777.5, 0.1));
}

TEST(Test_case_Kuznetsov_Artyom_FIIT3, testSum) {
  ComplexNumber valueOne(123, 312);
  ComplexNumber valueTwo(-321, -123);
  ComplexNumber answer(-198, 189);

  auto result = valueOne + valueTwo;

  ASSERT_TRUE(isEqual(result.getRe(), answer.getRe()));
  ASSERT_TRUE(isEqual(result.getIm(), answer.getIm()));
}

TEST(Test_case_Kuznetsov_Artyom_FIIT3, testDiff) {
  ComplexNumber valueOne(10.55, -23.5);
  ComplexNumber valueTwo(65.1, 34.87);
  ComplexNumber answer(-54.55, -58.37);

  auto result = valueOne - valueTwo;

  ASSERT_TRUE(isEqual(result.getRe(), answer.getRe()));
  ASSERT_TRUE(isEqual(result.getIm(), answer.getIm()));
}

TEST(Test_case_Kuznetsov_Artyom_FIIT3, testMult) {
  ComplexNumber valueOne(-15.5, 17.5);
  ComplexNumber valueTwo(432, 345);
  ComplexNumber answer(-12733.5, 2212.5);

  auto result = valueOne * valueTwo;

  ASSERT_TRUE(isEqual(result.getRe(), answer.getRe()));
  ASSERT_TRUE(isEqual(result.getIm(), answer.getIm()));
}

TEST(Test_case_Kuznetsov_Artyom_FIIT3, testDiv) {
  ComplexNumber valueOne(-2315.5, 4317.5);
  ComplexNumber valueTwo(432.234, -345.777);
  ComplexNumber answer(-8.139125, 3.477694);

  auto result = valueOne / valueTwo;

  ASSERT_TRUE(isEqual(result.getRe(), answer.getRe()));
  ASSERT_TRUE(isEqual(result.getIm(), answer.getIm()));
}