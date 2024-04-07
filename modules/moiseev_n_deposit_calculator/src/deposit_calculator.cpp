// Copyright 2024 Moiseev Nikita

#include <stdexcept>
#include <cmath>

#include "include/deposit_calculator.h"

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
    double monthlyInterestRate = interestRate / percent / percentMonth;
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
    double monthlyInterestRate = interestRate / percent / percentMonth;

    return depositAmount * monthlyInterestRate * months;
}
