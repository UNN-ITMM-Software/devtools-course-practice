// Copyright 2024 Moiseev Nikita

#ifndef MODULES_MOISEEV_N_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_
#define MODULES_MOISEEV_N_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_

namespace constants {
    constexpr int kMonthsInYear = 12;
    constexpr int kPercentageConversionFactor = 100;
}

#include <string>

class DepositCalculator {
 public:
    DepositCalculator();
    ~DepositCalculator();

    double calculateProfit(double depositAmount, double interestRate,
        int months);
    double calculateProfitCapitalization(double depositAmount,
        double interestRate, int months);
 private:
    void validateArguments(double depositAmount,
        double interestRate, int months);
};

#endif  // MODULES_MOISEEV_N_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_
