// Copyright 2024 Shmelev Ivan

#include "include/graham_algorithm.h"

int GrahamScan::orientation(const Point& p, const Point& q, const Point& r) {
    double val = (q.second - p.second) * (r.first - q.first) -
        (q.first - p.first) * (r.second - q.second);
    if (val == 0) return COLLINEAR;
    return (val > 0) ? LEFT_TURN : RIGHT_TURN;
}

Points GrahamScan::sortPoints(Points& points) {
    size_t n = points.size();
    int minY = 0;
    for (size_t i = 1; i < n; i++) {
        if (points[i].second < points[minY].second || (points[i].second ==
            points[minY].second && points[i].first < points[minY].first)) {
            minY = i;
        }
    }
    std::swap(points[0], points[minY]);
    std::sort(points.begin() + 1, points.end(), [&points](Point& a, Point& b) {
        int orient = orientation(points[0], a, b);
    if (orient == COLLINEAR) {
        return (a.first - points[0].first) * (a.first - points[0].first) +
            (a.second - points[0].second) * (a.second - points[0].second) <
            (b.first - points[0].first) * (b.first - points[0].first) +
            (b.second - points[0].second) * (b.second - points[0].second);
    }
    return orient == LEFT_TURN;
        });

    return points;
}

bool GrahamScan::comparePoints(const Point& a, const Point& b) {
    return a.first == b.first && a.second == b.second;
}

Points GrahamScan::convexHull(Points& points) {
    size_t n = points.size();
    if (n < 3) return Points();

    Points sortedPoints = sortPoints(points);

    auto last = std::unique(sortedPoints.begin(), sortedPoints.end(),
        [](const Point& a, const Point& b) {
            return a.first == b.first && a.second == b.second;
        });
    sortedPoints.erase(last, sortedPoints.end());

    bool collinear = true;
    for (size_t i = 2; i < n && collinear; i++) {
        if (orientation(sortedPoints[0], sortedPoints[i - 1],
            sortedPoints[i]) != COLLINEAR) {
            collinear = false;
        }
    }
    if (collinear) {
        return Points{ sortedPoints[0], sortedPoints[n - 1] };
    }

    Points hull;

    hull.push_back(sortedPoints[0]);
    hull.push_back(sortedPoints[1]);

    for (size_t i = 2; i < n; i++) {
        while (hull.size() > 1 && orientation(hull[hull.size() - 2],
            hull[hull.size() - 1], sortedPoints[i]) != LEFT_TURN) {
            hull.pop_back();
        }
        hull.push_back(sortedPoints[i]);
    }

    return hull;
}
