// Copyright 2024 Saratova Marina

#include <gtest/gtest.h>
#include <vector>
#include "include/complex_number_calc.h"

TEST(ComplexCalculatorTest, Addition1) {
    ComplexCalculator num1(1, 2);
    ComplexCalculator num2(2, 5);
    ComplexCalculator result = num1 + num2;
    EXPECT_DOUBLE_EQ(result.getReal(), 3);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 7);
}

TEST(ComplexCalculatorTest, Addition2) {
    ComplexCalculator num1(3, 4);
    ComplexCalculator num2(5, -2);
    ComplexCalculator result = num1 + num2;
    EXPECT_DOUBLE_EQ(result.getReal(), 8);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 2);
}

TEST(ComplexCalculatorTest, Subtraction1) {
    ComplexCalculator num1(2, 3);
    ComplexCalculator num2(1, 2);
    ComplexCalculator result = num1 - num2;
    EXPECT_DOUBLE_EQ(result.getReal(), 1);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 1);
}

TEST(ComplexCalculatorTest, Subtraction2) {
    ComplexCalculator num1(3, 4);
    ComplexCalculator num2(5, -2);
    ComplexCalculator result = num1 - num2;
    EXPECT_DOUBLE_EQ(result.getReal(), -2);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 6);
}

TEST(ComplexCalculatorTest, Multiplication1) {
    ComplexCalculator num1(1, 2);
    ComplexCalculator num2(3, 4);
    ComplexCalculator result = num1 * num2;
    EXPECT_DOUBLE_EQ(result.getReal(), -5);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 10);
}

TEST(ComplexCalculatorTest, Multiplication2) {
    ComplexCalculator num1(3, 4);
    ComplexCalculator num2(5, -2);
    ComplexCalculator result = num1 * num2;
    EXPECT_DOUBLE_EQ(result.getReal(), 23);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 14);
}

TEST(ComplexCalculatorTest, Division) {
    ComplexCalculator num1(4, 0);
    ComplexCalculator num2(1, 0);
    ComplexCalculator result = num1 / num2;
    EXPECT_DOUBLE_EQ(result.getReal(), 4);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 0);
}

TEST(ComplexCalculatorTest, Division2) {
    ComplexCalculator num1(6, 2);
    ComplexCalculator num2(2, 1);

    ComplexCalculator result = num1 / num2;

    EXPECT_DOUBLE_EQ(result.getReal(), 2.8);
    EXPECT_DOUBLE_EQ(result.getImaginary(), -0.4);
}

TEST(ComplexCalculatorTest, DivisionByZero) {
    ComplexCalculator num1(3, 4);
    ComplexCalculator num2(0, 0);

    EXPECT_THROW(num1 / num2, std::invalid_argument);
}

TEST(ComplexCalculatorTest, DivisionWithFractions) {
    ComplexCalculator num1(3.5, 2.25);
    ComplexCalculator num2(1.75, 1.25);

    ComplexCalculator result = num1 / num2;

    EXPECT_NEAR(result.getReal(), 1.93243, 0.01);
    EXPECT_NEAR(result.getImaginary(), -0.09459, 0.01);
}
