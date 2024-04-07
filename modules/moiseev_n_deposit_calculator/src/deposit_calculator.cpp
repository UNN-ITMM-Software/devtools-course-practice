// Copyright 2024 Moiseev Nikita

#include <stdexcept>
#include <cmath>

#include "include/deposit_calculator.h"

namespace constants {
    constexpr int kMonthsInYear = 12;
    constexpr int kPercentageConversionFactor = 100;
}

DepositCalculator::DepositCalculator() {}

DepositCalculator::~DepositCalculator() {}

void DepositCalculator::validateArguments(double depositAmount,
    double interestRate, int months) {
    if (depositAmount <= 0 || interestRate < 0 || months <= 0) {
        throw std::invalid_argument("Invalid arguments");
    }
}

double DepositCalculator::calculateProfitCapitalization(double depositAmount,
    double interestRate, int months) {
    validateArguments(depositAmount, interestRate, months);
    int percent = 100;
    int percentMonth = 12;
    double monthlyInterestRate = interestRate /
        constants::kPercentageConversionFactor / constants::kMonthsInYear;
    double currentDepositAmount = depositAmount;

    for (int i = 0; i < months; ++i) {
        currentDepositAmount += currentDepositAmount * monthlyInterestRate;
    }

    return currentDepositAmount;
}
double DepositCalculator::calculateProfit(double depositAmount,
    double interestRate, int months) {
    int percent = 100;
    int percentMonth = 12;
    validateArguments(depositAmount, interestRate, months);
    double monthlyInterestRate = interestRate /
        constants::kPercentageConversionFactor / constants::kMonthsInYear;

    return depositAmount * monthlyInterestRate * months;
}
