// Copyright 2024 Mironov Ilya
#pragma once

#include <string>
#include <vector>

#include "include/polygon_area_calculator.h"

class PolygonPriceApp {
 private:
    PolygonAreaCalculator areaCalculator{};
    std::string sMessage{};
    double pricePerSquareMeter{};

 public:
    PolygonPriceApp() = default;
    std::string operator()(int argc, char** argv);

 private:
    void help(const char* appname, const char* message = "");
    void parseArgs(int argc, char** argv);
};
