// Copyright 2021 Zhbanova Nadezhda

#include <iostream>

#include "include/calculate_price_application.h"

int main(int argc, const char ** argv) {
    CalculatePriceApplication app;
    std::cout << app(argc, argv);
    return 0;
}
