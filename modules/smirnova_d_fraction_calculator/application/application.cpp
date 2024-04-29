// Copyright 2024 Saratova Marina

#include <iostream>

#include "include/fraction_calculator_app.h"

int main(int argc, char* argv[]) {
    FractionCalculatorApplication application;
    std::cout << application.FractionCalculation(argc, argv) << std::endl;
    return 0;
}
