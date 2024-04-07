// Copyright 2024 Moiseev Nikita

#ifndef MODULES_DEPOSIT_CALCULATOR_H_
#define MODULES_DEPOSIT_CALCULATOR_H_

#include <string>

class DepositCalculator
{
public:
    DepositCalculator();
    ~DepositCalculator();

    double calculateProfit(double depositAmount, double interestRate, int months);
    double calculateProfitCapitalization(double depositAmount, double interestRate, int months);
};

#endif  // MODULES_DEPOSIT_CALCULATOR_H_
