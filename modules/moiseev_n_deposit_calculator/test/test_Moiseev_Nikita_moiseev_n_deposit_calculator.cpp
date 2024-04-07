// Copyright 2024 Moiseev Nikita

#include <gtest/gtest.h>
#include <stdexcept>

#include "include/deposit_calculator.h"

class DepositCalculatorTest : public ::testing::Test {
 protected:
    DepositCalculator calculator;
};

TEST(DepositCalculatorTests, CalculateProfit_ZeroDepositAmount_ReturnsZero) {
    DepositCalculator calculator;
    EXPECT_THROW(calculator.calculateProfit(0, 10, 12),
        std::invalid_argument);
    EXPECT_THROW(calculator.calculateProfitCapitalization(0, 10, 12),
        std::invalid_argument);
}

TEST(DepositCalculatorTests,
    CalculateProfit_NegativeInterestRate_ThrowsException) {
    DepositCalculator calculator;

    EXPECT_THROW(calculator.calculateProfit(1000, -1, 12),
        std::invalid_argument);
    EXPECT_THROW(calculator.calculateProfitCapitalization(1000, -1, 12),
        std::invalid_argument);
}

TEST(DepositCalculatorTests,
    CalculateProfit_SimpleCase_ReturnsCorrectProfit2) {
    DepositCalculator calculator;

    double profit = calculator.calculateProfit(1000, 10, 12);

    EXPECT_NEAR(profit, 1000 * (10.0 / 100 / 12) * 12, 0.01);
}
TEST(DepositCalculatorTests,
    CalculateProfit_NegativeDepositAmount_ThrowsException) {
    DepositCalculator calculator;

    EXPECT_THROW(calculator.calculateProfit(-1000, 10, 12),
        std::invalid_argument);
    EXPECT_THROW(calculator.calculateProfitCapitalization(-1000, 10, 12),
        std::invalid_argument);
}

TEST(DepositCalculatorTests,
    CalculateProfit_ZeroMonths_ThrowsException) {
    DepositCalculator calculator;

    EXPECT_THROW(calculator.calculateProfit(1000, 10, 0),
        std::invalid_argument);
    EXPECT_THROW(calculator.calculateProfitCapitalization(1000, 10, 0),
        std::invalid_argument);
}

TEST(DepositCalculatorTests,
    CalculateProfit_ZeroInterestRate_ReturnsZero) {

    DepositCalculator calculator;

    double profit = calculator.calculateProfit(1000, 0, 12);

    EXPECT_EQ(profit, 0);
}

TEST(DepositCalculatorTests,
    CalculateProfit_MaximumMonths_ReturnsCorrectProfit) {
    DepositCalculator calculator;

    double profit = calculator.calculateProfit(1000, 10,
        std::numeric_limits<int>::max());

    EXPECT_GT(profit, 0);
}


TEST(DepositCalculatorTests,
    CalculateProfitCapitalization_ZeroInterestRate_ReturnsInitialDeposit) {
    DepositCalculator calculator;

    double profit = calculator.calculateProfitCapitalization(1000, 0, 12);

    EXPECT_EQ(profit, 1000);
}

TEST(DepositCalculatorTests,
    CalculateProfitCapitalization_OneMonth_ReturnsCorrectProfit) {
    DepositCalculator calculator;

    double profit = calculator.calculateProfitCapitalization(1000, 10, 1);

    EXPECT_NEAR(profit, 1000 + 1000 * (10.0 / 100 / 12), 0.01);
}

TEST(DepositCalculatorTests,
    CalculateProfitCapitalization_LargeDeposit_ReturnsCorrectProfit) {
    DepositCalculator calculator;

    double profit = calculator.calculateProfitCapitalization(
        std::numeric_limits<double>::max(), 10, 12);

    EXPECT_GT(profit, 0);
}

TEST(DepositCalculatorTests,
    CalculateProfitCapitalization_LargeInterestRate_ReturnsCorrectProfit) {
    DepositCalculator calculator;

    double profit = calculator.calculateProfitCapitalization(
        1000, std::numeric_limits<double>::max(), 12);

    EXPECT_GT(profit, 0);
}
