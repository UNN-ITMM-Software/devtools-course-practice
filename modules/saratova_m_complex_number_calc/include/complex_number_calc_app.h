// Copyright 2024 Smirnova Darya

#pragma once

#include <string>

#include "include/complex_number_calc.h"

class ComplexCalculatorApplication {
 private:
    std::string msg;
    ComplexCalculator num1;
    ComplexCalculator num2;
    ComplexCalculator result;
    bool Validate(int argc, char* argv[]);
    void Help(const char* application, const char* errMsg = nullptr);
 public:
    ComplexCalculatorApplication() = default;
    std::string ComplexCalculatorCalculation(int argc, char* argv[]);
};
