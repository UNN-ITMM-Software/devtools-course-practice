// Copyright 2021 Rustamov Azer

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/polygon.h"
#include "include/polygon_area_calculator.hpp"


namespace Polygon {

std::string PolygonAreaCalculator::help(const std::string& filename) const {
    return "Usage: " + filename +
            " Coordinates of points...\n" \
            "Example: " + filename +
            " 1.2 2.0 1.2 2.3 5.7 0.5";
}

std::string PolygonAreaCalculator::operator()
    (int argc, const char* argv[], int* retcode) const {
    if (retcode != nullptr)
        *retcode = 1;
    if (argc <= 1)
        return help(argv[0]);
    if ((argc - 1) % 2 == 1)
        return "[ERROR]: Number of arguments must be even";
    double result;

    std::vector<double> numbers;
    numbers.reserve(argc - 1);
    for (auto i = 1; i < argc; i++) {
        std::string arg = argv[i];
        try {
            double num = std::stod(arg);
            numbers.push_back(num);
        } catch (std::invalid_argument& e) {
            return "[ERROR] " + arg + ": invalid argument. " +
                   std::string(e.what());
        } catch (std::out_of_range& e) {
            return "[ERROR] " + arg + ": out of range. " +
                   std::string(e.what());
        }
    }

    Points2D points((argc - 1) / 2);
    for (auto i = 0; i < argc - 2; i += 2) {
        points[i / 2].first = numbers[i];
        points[i / 2].second = numbers[i + 1];
    }
    result = PolygonArea(points);
    std::ostringstream stream;
    stream << "Area of polygon = " << result;

    if (retcode != nullptr)
        *retcode = 0;
    return stream.str();
}

}  // namespace Polygon
