// Copyright 2021 Paranicheva Alyona

#include <cmath>

#include <iostream>
#include <utility>

#include "include/triangle.h"

Triangle::Triangle(std::pair<double, double>  _a, std::pair<double, double> _b,
    std::pair<double, double> _c) : a(_a), b(_b), c(_c) {}

double Triangle::SideAB() {
    double AB = sqrt((b.second - a.second) * (b.second - a.second) +
        (b.first - a.first) * (b.first - a.first));
    return AB;
}

double Triangle::SideBC() {
    double BC = sqrt((c.second - b.second) * (c.second - b.second) +
        (c.first - b.first) * (c.first - b.first));
    return BC;
}

double Triangle::SideAC() {
    double AC = sqrt((c.second - a.second) * (c.second - a.second) +
        (c.first - a.first) * (c.first - a.first));
    return AC;
}

double Triangle::Perimeter() {
    double AB = SideAB();
    double BC = SideBC();
    double AC = SideAC();
    double P = AB + BC + AC;
    return P;
}

double Triangle::Area() {
    double AB = SideAB();
    double BC = SideBC();
    double AC = SideAC();
    double p = (AB + BC + AC) / 2;
    double S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
    return S;
}
