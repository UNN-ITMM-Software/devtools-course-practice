// Copyright 2021 Molotkova Svetlana

#include <cmath>
#include <utility>

#include "include/QuadraticEquation.h"

QuadraticEquation::QuadraticEquation(double a, double b, double c) {
    if (a == 0) {
         throw "Not quadratic equation";
     } else {
       this->a = a;
       this->b = b;
       this->c = c;
     }
  }

double QuadraticEquation::discr(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    return d;
}

std::pair<double, double> QuadraticEquation::solver() {
    double d = discr(a, b, c);
    if (d < 0) {
         throw "The discriminate value is less than zero";
     } else {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        return std::make_pair(x1, x2);
        }
}
