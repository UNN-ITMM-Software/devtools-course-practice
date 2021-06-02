// Copyright 2021 Belik Julia

#ifndef MODULES_DEPOSIT_CALC_INCLUDE_DEPOSITCALC_APP_H_
#define MODULES_DEPOSIT_CALC_INCLUDE_DEPOSITCALC_APP_H_

#include <string>
#include <vector>

class DepositCalc_app {
 public:
    DepositCalc_app();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    bool validateArguments(const char** argv, std::vector<int> daysInMonths);
    std::string message_;
    using Arguments = struct {
        int depositSum;
        int numberOfMonths;
        double interestRate;
        int day;
        int month;
        int year;
        int capitalization;
    };
};

#endif  // MODULES_DEPOSIT_CALC_INCLUDE_DEPOSITCALC_APP_H_
