// Copyright 2021 Paranicheva Alyona

#ifndef MODULES_PARAMS_TRIANGLE_INCLUDE_TRIANGLE_H_
#define MODULES_PARAMS_TRIANGLE_INCLUDE_TRIANGLE_H_

#include <utility>

class Triangle {
 private:
    std::pair<double, double>  a;
    std::pair<double, double>  b;
    std::pair<double, double>  c;
 public:
    Triangle(std::pair<double, double>  _a, std::pair<double, double> _b,
        std::pair<double, double> _c);

    double SideAB();
    double SideBC();
    double SideAC();

    double Perimeter();
    double Area();
};

#endif  // MODULES_PARAMS_TRIANGLE_INCLUDE_TRIANGLE_H_
