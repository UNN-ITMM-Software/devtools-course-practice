// Copyright 2021 Molotkova Svetlana

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATICEQUATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATICEQUATION_H_

#include <utility>

class QuadraticEquation {
 private:
    double a;
    double b;
    double c;
 public:
    QuadraticEquation(double a, double b, double c);
    double discr(double a, double b, double c);
    std::pair <double, double> solver();
};

#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATICEQUATION_H_
