// Copyright 2021 Belik Julia

#ifndef MODULES_TRIANGLE_POINT_INCLUDE_TRIANGLEPOINT_H_
#define MODULES_TRIANGLE_POINT_INCLUDE_TRIANGLEPOINT_H_

#include <utility>

class Triangle {
 public:
    Triangle(std::pair<double, double>  _a, std::pair<double, double> _b,
        std::pair<double, double> _c);

    bool isInside(std::pair<double, double>  x);

 private:
    std::pair<double, double>  a;
    std::pair<double, double>  b;
    std::pair<double, double>  c;
};

#endif  // MODULES_TRIANGLE_POINT_INCLUDE_TRIANGLEPOINT_H_
