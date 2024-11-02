// Copyright 2024 Kachalov Mikhail
#include "include/polygon_area_calculator.h"

#include <cmath>
#include <stdexcept>

void PolygonAreaCalculator::addVertex(double x, double y) {
    vertices.emplace_back(x, y);
}

double PolygonAreaCalculator::calculateArea() const {
    if (vertices.size() < 3) {
        throw std::logic_error("A polygon must have at least 3 vertices ");
    }

    double area = 0.0;
    int n = vertices.size();

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += vertices[i].first * vertices[j].second;
        area -= vertices[i].second * vertices[j].first;
    }

    return std::abs(area) / 2.0;
}
