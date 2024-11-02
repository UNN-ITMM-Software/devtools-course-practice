// Copyright 2024 Kachalov Mikhail

#ifndef MODULES_KACHALOV_M_CALC_POLYGON_INCLUDE_POLYGON_AREA_CALCULATOR_H
#define MODULES_KACHALOV_M_CALC_POLYGON_INCLUDE_POLYGON_AREA_CALCULATOR_H

#include <vector>
#include <utility>

class PolygonAreaCalculator {
public:
    void addVertex(double x, double y);

    double calculateArea() const;

private:
    std::vector<std::pair<double, double>> vertices;
};

#endif // MODULES_KACHALOV_M_CALC_POLYGON_INCLUDE_POLYGON_AREA_CALCULATOR_H
