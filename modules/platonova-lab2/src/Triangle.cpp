// triangle.cpp
#include "include/Triangle.h"

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

double Triangle::sideLength(double x1, double y1, double x2, double y2) const {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

double Triangle::perimeter() const {
    double a = sideLength(x1, y1, x2, y2);
    double b = sideLength(x2, y2, x3, y3);
    double c = sideLength(x3, y3, x1, y1);
    return a + b + c;
}

double Triangle::area() const {
    double a = sideLength(x1, y1, x2, y2);
    double b = sideLength(x2, y2, x3, y3);
    double c = sideLength(x3, y3, x1, y1);
    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

