// Copyright 2021 Belik Julia

#include <cmath>
#include <utility>

#include "include/TrianglePoint.h"

Triangle::Triangle(std::pair<double, double>  _a, std::pair<double, double> _b,
    std::pair<double, double> _c) : a(_a), b(_b), c(_c) {}

bool Triangle::isInside(std::pair<double, double>  x) {
    double t1, t2, t3;
    t1 = (a.first - x.first) * (b.second - a.second)
        - (b.first - a.first) * (a.second - x.second);
    t2 = (b.first - x.first) * (c.second - b.second)
        - (c.first - b.first) * (b.second - x.second);
    t3 = (c.first - x.first) * (a.second - c.second)
        - (a.first - c.first) * (c.second - x.second);
    return (((t1 > 0) && (t2 > 0) && (t3 > 0))
        || ((t1 < 0) && (t2 < 0) && (t3 < 0)));
}
