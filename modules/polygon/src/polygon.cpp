// Copyright 2021 Alibekov Murad

#include "include/polygon.h"

double Polygon::PolygonArea(const Points2D& polygon) {
    double area = 0.;
    int N = polygon.size();

    if (N == 0)
        throw std::runtime_error("[ERROR]: Polygon without points");

    if ((N == 1) || (N == 2))
        return area;

    for (int i = 0; i < N - 1; i++)
        area += polygon[i].first * polygon[i + 1].second
              - polygon[i + 1].first * polygon[i].second;

    area += polygon[N - 1].first * polygon[0].second
          - polygon[0].first * polygon[N - 1].second;

    return fabs(area) / 2;
}
