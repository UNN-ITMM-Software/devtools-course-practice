// Copyright 2021 Lebedev Andrew

#include <utility>
#include <vector>
#include <iostream>

#include "include/DepositCalc.h"

depositCalc::depositCalc() {
    depositSum = 0;
    numberOfMonths = 0;
    numberOfDays = 0;
    interestRate = 0;
    day = 0;
    month = 0;
    year = 0;
    capitalization = 0;
    daysInMonths.resize(12);
    initVector();
}

depositCalc::depositCalc(int _depositSum, int _numberOfMonths,
        double _interestRate, int _day, int _month, int _year,
        int _capitalization) {
    initVector();
    setDepositSum(_depositSum);
    setNumberOfMonths(_numberOfMonths);
    setInterestRate(_interestRate);
    setDate(_day, _month, _year);
    setCapitalization(_capitalization);
}

void depositCalc::initVector() {
    daysInMonths.resize(12);
    for (int i = 0; i < 12; i++) {
        if (i == 4 || i == 6 || i == 9 || i == 11)
            daysInMonths[i] = 30;
        else if (i == 2)
            daysInMonths[i] = 28;
        else
            daysInMonths[i] = 31;
    }
}

void depositCalc::setDepositSum(int _depositSum) {
    if (_depositSum <= 0) {
        throw "Sum must me positive";
    }
    depositSum = _depositSum;
}

void depositCalc::setNumberOfMonths(int _numberOfMonths) {
    if (_numberOfMonths <= 0) {
        throw "Number of months must be positive";
    }
    numberOfMonths = _numberOfMonths;
}

void depositCalc::setNumberOfDays(int _numberOfDays) {
    if (_numberOfDays <= 0) {
        throw "Number of days must be positive";
    }
    numberOfDays = _numberOfDays;
}

void depositCalc::setInterestRate(double _interestRate) {
    if (_interestRate <= 0) {
        throw "Interest rate must be positive";
    }
    interestRate = _interestRate;
}

void depositCalc::setDate(int _day, int _month, int _year) {
    if (_day <= 0 || _day > daysInMonths[_month % 12]
        || _month <= 0 || _month > 12 || _year < 0)
        throw "Incorrect date";
    day = _day;
    month = _month;
    year = _year;
}

void depositCalc::setCapitalization(int _capitalization) {
    /* 0 - No capitalization
       1 - Once a day
       2 - Once a week
       3 - Once a month
       4 - Once a year */
    if (_capitalization < 0 || _capitalization > 4) {
        throw "Wrong value";
    }
    capitalization = _capitalization;
}


int depositCalc::getDepositSum() const {
    return depositSum;
}

int depositCalc::getNumberOfDays() const {
    return numberOfDays;
}

int depositCalc::getNumberOfMonths() const {
    return numberOfMonths;
}

double depositCalc::getInterestRate() const {
    return interestRate;
}

int depositCalc::getCapitalization() const {
    return capitalization;
}

int depositCalc::getResult() const {
    return result;
}

void depositCalc::calculate() {
    if (!day || !month || !year
        || !depositSum || !interestRate
        || !(numberOfMonths || numberOfDays)) {
        throw "Parameters not set";
    }
    if (numberOfDays == 0) {
        int currMonth = month;
        for (int i = 0; i < numberOfMonths; i++) {
            numberOfDays += daysInMonths[currMonth % 12];
            currMonth++;
        }
    }
    double res = depositSum;
    if (!capitalization) {
        res += (numberOfDays / 365.0 *
            interestRate / 100 * depositSum);
        result = static_cast<int>(res + 0.5);
        return;
    }
    int daysCount = 1;  //  Days passed since beginning
    int daysSinceCap = 1;  // Days passed since last capitalization
    int capInc = 0;  //  delta between capitalizations
    int nextCap = 0;  // on which day will next capitalization be
    int currMonth = month;  // Current month for capitalization
    switch (capitalization) {
        case 1: capInc = 1; break;
        case 2: capInc = 7; break;
        case 4: capInc = 365; break;
    }
    if (capitalization == 3) {
        capInc = daysInMonths[currMonth % 12];
        currMonth++;
    }
    nextCap += capInc;
    while (daysCount <= numberOfDays) {
        if (daysCount == numberOfDays) {  // last day
            res += res * daysSinceCap / 365.0 *
                interestRate / 100;
            result = static_cast<int>(res + 0.5);
            return;
        }
        if (nextCap == daysCount) {
            res += res * daysSinceCap / 365.0 *
                interestRate / 100;
            daysSinceCap = 1;
            if (capitalization == 3) {
                capInc = daysInMonths[currMonth % 12];
                currMonth++;
            }
            nextCap += capInc;
        } else {
            daysSinceCap++;
        }
        daysCount++;
    }
}
