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

    /*int x;
    FractionCalculator a;
    // Act
    x = a.NOD(24, 36);
    // Assert
    EXPECT_EQ(x, 12); */
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
        }, std::string);
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
