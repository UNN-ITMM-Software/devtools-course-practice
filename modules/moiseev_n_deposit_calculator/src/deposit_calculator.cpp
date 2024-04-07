// Copyright 2024 Moiseev Nikita

#include <stdexcept>
#include <cmath>

#include "include/deposit_calculator.h"

DepositCalculator::DepositCalculator() {}

DepositCalculator::~DepositCalculator() {}

double DepositCalculator::calculateProfitCapitalization(double depositAmount,
    double interestRate, int months) {
    if (depositAmount <= 0 || interestRate < 0 || months <= 0) {
        throw std::invalid_argument("Invalid arguments");
    }

    double monthlyInterestRate = interestRate / 100 / 12;
    double profit = 0.0;
    double currentDepositAmount = depositAmount;

    for (int i = 0; i < months; ++i) {
        profit += currentDepositAmount * monthlyInterestRate;
        currentDepositAmount += currentDepositAmount * monthlyInterestRate;
    }

    return currentDepositAmount;
}
double DepositCalculator::calculateProfit(double depositAmount,
    double interestRate, int months) {
    if (depositAmount <= 0 || interestRate < 0 || months <= 0) {
        throw std::invalid_argument("Invalid arguments");
    }

    double monthlyInterestRate = interestRate / 100 / 12;

    return depositAmount * monthlyInterestRate * months;
}
