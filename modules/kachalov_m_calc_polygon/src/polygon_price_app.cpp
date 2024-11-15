// Copyright 2024 Mironov Ilya

#include "include/polygon_price_app.h"

#include <stdexcept>

std::string PolygonPriceApp::operator()(int argc, char** argv) {
    if (!(argc >= 6 + 2 && argc % 2 == 0)) {
        help(argv[0], "invalid arguments number");
        return sMessage;
    }

    try {
        parseArgs(argc, argv);
    } catch (const std::invalid_argument& e) {
        help(argv[0], "invalid_argument");
        return sMessage;
    } catch (const std::out_of_range& e) {
        help(argv[0], "numbers are to large");
        return sMessage;
    }

    double area = areaCalculator.calculateArea();
    double cost = area * pricePerSquareMeter;

    sMessage = "Area: " + std::to_string(area) + " square meters\n";
    sMessage += "Cost: " + std::to_string(cost) + " currency units\n";

    return sMessage;
}

void PolygonPriceApp::help(const char* appname, const char* message) {
    sMessage = "Usage: " + std::string(appname) +
               " <x1> <y1> <x2> <y2> <x3> <y3> ... <price_per_square_meter>\n";
    if (message) {
        sMessage += std::string(message) + "\n";
    }
}

void PolygonPriceApp::parseArgs(int argc, char** argv) {
    areaCalculator.clearVertices();

    for (int i = 1; i < argc - 1; i += 2) {
        double x = std::stod(argv[i]);
        double y = std::stod(argv[i + 1]);
        areaCalculator.addVertex(x, y);
    }

    pricePerSquareMeter = std::stod(argv[argc - 1]);
}
