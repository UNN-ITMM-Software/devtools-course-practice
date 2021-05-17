// Copyright 2021 Rustamov Azer

#include <iostream>
#include <string>

#include "include/polygon_area_calculator.hpp"

int main(int argc, const char* argv[]) {
    Polygon::PolygonAreaCalculator app;
    int retcode = 0;
    std::cout << app(argc, argv, &retcode);
    return retcode;
}
