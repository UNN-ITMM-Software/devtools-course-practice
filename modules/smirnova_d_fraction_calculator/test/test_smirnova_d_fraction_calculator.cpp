// Copyright 2024 Smirnova Darya

#include <gtest/gtest.h>

#include "include/fraction_calculator.h"

TEST(FractionCalculatorTest, Can_Create_Fraction) {
    ASSERT_NO_THROW(FractionCalculator());
}

TEST(FractionCalculatorTest, Zero_Den_Fraction ) {
    ASSERT_ANY_THROW(FractionCalculator(5, 0));
}

TEST(FractionCalculatorTest, Cant_Set_Zero_Den) {
    FractionCalculator a;
     ASSERT_ANY_THROW(a.SetDen(0));
}

TEST(FractionCalculatorTest, Find_NOD_Different_Numbers) {
    FractionCalculator a;
    int x = a.NOD(30, 45);

    EXPECT_EQ(x, 15);
}

TEST(FractionCalculatorTest, Add_Fractions_Diff_Denominators) {
    FractionCalculator a(1, 4);
    FractionCalculator b(1, 6);
    FractionCalculator res(5, 12);
    FractionCalculator x;

    x = a + b;

    EXPECT_EQ(x.GetNum(), res.GetNum());
    EXPECT_EQ(x.GetDen(), res.GetDen());
}

TEST(FractionCalculatorTest, Subtract_Fractions_Diff_Denominators) {
    FractionCalculator a(1, 4);
    FractionCalculator b(1, 6);
    FractionCalculator res(1, 12);
    FractionCalculator x;

    x = a - b;

    EXPECT_EQ(x.GetNum(), res.GetNum());
    EXPECT_EQ(x.GetDen(), res.GetDen());
}

TEST(FractionCalculatorTest, Multiply_Fractions_Diff_Denominators) {
    FractionCalculator a(1, 4);
    FractionCalculator b(1, 6);
    FractionCalculator res(1, 24);
    FractionCalculator x;

    x = a * b;

    EXPECT_EQ(x.GetNum(), res.GetNum());
    EXPECT_EQ(x.GetDen(), res.GetDen());
}

TEST(FractionCalculatorTest, Denominator_Zero_Throws_Exception) {
    EXPECT_THROW({
        FractionCalculator a(3, 8);
        FractionCalculator b(5, 0);
        }, std::invalid_argument);
}

TEST(FractionCalculatorTest, Divide_Fractions_Diff_Denominators) {
    FractionCalculator a(1, 4);
    FractionCalculator b(1, 6);
    FractionCalculator res(3, 2);
    FractionCalculator x;

    x = a / b;

    EXPECT_EQ(x.GetNum(), res.GetNum());
    EXPECT_EQ(x.GetDen(), res.GetDen());
}

TEST(FractionCalculatorTest, Multiplication_Result) {
    FractionCalculator a(2, 3);
    FractionCalculator b(3, 4);
    FractionCalculator res(1, 2);
    FractionCalculator x;

    x = a * b;

    EXPECT_EQ(x.GetNum(), res.GetNum());
    EXPECT_EQ(x.GetDen(), res.GetDen());
}

TEST(FractionCalculatorTest, Test_Operator_Equal) {
    FractionCalculator a(2, 3);
    FractionCalculator b(3, 4);
    a = b;

    EXPECT_EQ(a.GetNum(), b.GetNum());
    EXPECT_EQ(a.GetDen(), b.GetDen());
}

TEST(FractionCalculatorTest, Divide_Fractions) {
    FractionCalculator a(2, 2);
    FractionCalculator b(1, 1);
    FractionCalculator res(1, 1);
    FractionCalculator x;

    x = a / b;

    EXPECT_EQ(x.GetNum(), res.GetNum());
    EXPECT_EQ(x.GetDen(), res.GetDen());
}

TEST(FractionCalculatorTest, SetNum) {
    FractionCalculator fr;
    fr.SetNum(5);
    EXPECT_EQ(fr.GetNum(), 5);
}

TEST(FractionCalculatorTest, SetDen) {
    FractionCalculator fr;
    EXPECT_NO_THROW(fr.SetDen(5));
    EXPECT_EQ(fr.GetDen(), 5);
    EXPECT_THROW(fr.SetDen(0), std::invalid_argument);
}

TEST(FractionCalculatorTest, DivisionByZero) {
    FractionCalculator fr1(1, 2);
    FractionCalculator fr2(0, 1);
    EXPECT_THROW(fr1 / fr2, std::invalid_argument);
}
