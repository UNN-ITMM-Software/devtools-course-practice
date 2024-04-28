// Copyright 2024 Saratova Marina

#pragma once

#include <string>

#include "include/fraction_calculator.h"

class FractionCalculatorApplication {
 private:
    std::string msg;
    FractionCalculator first;
    FractionCalculator second;
    FractionCalculator result;
    bool Validate(int argc, char* argv[]);
    void Help(const char* application, const char* errMsg = nullptr);
 public:
    FractionCalculatorApplication() = default;
    std::string FractionCalculation(int argc, char* argv[]);
};
