// Copyright 2021 Lebedev Andrew

#ifndef MODULES_DEPOSIT_CALC_INCLUDE_DEPOSITCALC_H_
#define MODULES_DEPOSIT_CALC_INCLUDE_DEPOSITCALC_H_

#include <vector>
#include <utility>

class  depositCalc {
    int depositSum;
    int numberOfMonths;
    int numberOfDays;
    double interestRate;
    int day;
    int month;
    int year;
    std::vector<int> daysInMonths;
    int capitalization;
    int result;
    void initVector();

 public:
    depositCalc();
    depositCalc(int _depositSum, int _numberOfMonths,
        double _interestRate, int _day, int _month, int _year,
        int _capitalization = 0);
    void setDepositSum(int _depositSum);
    void setNumberOfMonths(int _numberOfMonths);
    void setNumberOfDays(int _numberOfDays);
    void setInterestRate(double _interestRate);
    void setDate(int _day, int _month, int _year);
    void setCapitalization(int _capitalization);
    int getDepositSum() const;
    int getNumberOfDays() const;
    int getNumberOfMonths() const;
    double getInterestRate() const;
    int getCapitalization() const;
    int getResult() const;
    void calculate();
};
#endif  // MODULES_DEPOSIT_CALC_INCLUDE_DEPOSITCALC_H_
