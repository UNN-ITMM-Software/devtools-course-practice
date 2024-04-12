// Copyright 2024 Shmelev Ivan

#include "include/graham_algorithm.h"

#include <cmath>
#include <stdexcept>
#include <algorithm>

int GrahamScan::orientation(std::pair<double, double>& p, std::pair<double, double>& q, std::pair<double, double>& r) {
    double val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

std::vector<std::pair<double, double>> GrahamScan::sortPoints(std::vector<std::pair<double, double>>& points) {
    int n = points.size();
    int minY = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].second < points[minY].second || (points[i].second ==
        points[minY].second && points[i].first < points[minY].first)) {
            minY = i;
        }
    }
    std::swap(points[0], points[minY]);
    std::sort(points.begin() + 1, points.end(), [&points](std::pair<double, double>& a, std::pair<double, double>& b) {
        int orient = orientation(points[0], a, b);
        if (orient == 0) {
            return (a.first - points[0].first) * (a.first - points[0].first) +
             (a.second - points[0].second) * (a.second - points[0].second) <
                   (b.first - points[0].first) * (b.first - points[0].first) +
                    (b.second - points[0].second) * (b.second - points[0].second);
        }
        return orient == 2;
    });

    return points;
}

std::vector<std::pair<double, double>> GrahamScan::convexHull(std::vector<std::pair<double, double>>& points) {
    int n = points.size();
    if (n < 3) return std::vector<std::pair<double, double>>();

    std::vector<std::pair<double, double>> sortedPoints = sortPoints(points);

    auto last = std::unique(sortedPoints.begin(), sortedPoints.end(), [](const std::pair<double, double>& a, const std::pair<double, double>& b) {
        return a.first == b.first && a.second == b.second;
    });
    sortedPoints.erase(last, sortedPoints.end());

    bool collinear = true;
    for (int i = 2; i < n && collinear; i++) {
        if (orientation(sortedPoints[0], sortedPoints[i-1], sortedPoints[i]) != 0) {
            collinear = false;
        }
    }
    if (collinear) {
        return std::vector<std::pair<double, double>>{sortedPoints[0], sortedPoints[n-1]};
    }

    std::vector<std::pair<double, double>> hull;

    hull.push_back(sortedPoints[0]);
    hull.push_back(sortedPoints[1]);

    for (int i = 2; i < n; i++) {
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], sortedPoints[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(sortedPoints[i]);
    }

    return hull;
}
