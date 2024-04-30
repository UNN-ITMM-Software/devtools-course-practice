// Copyright 2024 Shmelev Ivan

#ifndef MODULES_SHMELEV_I_GRAHAM_ALGORITHM_INCLUDE_GRAHAM_ALGORITHM_H_
#define MODULES_SHMELEV_I_GRAHAM_ALGORITHM_INCLUDE_GRAHAM_ALGORITHM_H_

#include <cmath>
#include <stdexcept>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

enum Direction: int {LEFT_TURN = 0, RIGHT_TURN = 2, COLLINEAR = 1};

using Point = std::pair<double, double>;
using Points = std::vector<Point>;

class GrahamScan {
 public:
    static Points convexHull(Points& points);
 private:
    static int orientation(const Point& p, const Point& q, const Point& r);
    static Points sortPoints(Points& points);
    static bool comparePoints(const Point& a, const Point& b);
};

#endif  // MODULES_SHMELEV_I_GRAHAM_ALGORITHM_INCLUDE_GRAHAM_ALGORITHM_H_
