// Copyright 2021 Belik Julia

#include <cmath>
#include <utility>
#include <stdexcept>

#include "include/TrianglePoint.h"

Triangle::Triangle(std::pair<double, double>  _a, std::pair<double, double> _b,
    std::pair<double, double> _c) : a(_a), b(_b), c(_c) {
    if (!isTriangle()) {
        throw std::runtime_error("ERROR: Not a triangle.\n");
    }
}

bool Triangle::isTriangle() {
    double AB, AC, BC;
    AB = sqrt((a.first - b.first) * (a.first - b.first) +
        (a.second - b.second) * (a.second - b.second));
    AC = sqrt((a.first - c.first) * (a.first - c.first) +
        (a.second - c.second) * (a.second - c.second));
    BC = sqrt((c.first - b.first) * (c.first - b.first) +
        (c.second - b.second) * (c.second - b.second));
    return (AC + AB > BC) && (AC + BC > AB) &&
        (AB + BC > AC);
}

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
