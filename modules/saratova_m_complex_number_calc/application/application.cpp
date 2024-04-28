// Copyright 2024 Smirnova Darya

#include <iostream>

#include "include/complex_number_calc_app.h"

int main(int argc, char* argv[]) {
    ComplexCalculatorApplication application;
    std::cout << application.ComplexCalculatorCalculation(argc, argv)
                                                        << std::endl;
    return 0;
}
