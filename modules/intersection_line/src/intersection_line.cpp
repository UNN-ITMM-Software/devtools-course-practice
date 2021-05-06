// Copyright 2021 Skripal Andrey

#include "include/intersection_line.h"
#include <utility>
#include <algorithm>

bool Line::intersect(int a, int b, int c, int d) {
    if (a > b)  std::swap(a, b);
    if (c > d)  std::swap(c, d);
    return std::max(a, c) <= std::min(b, d);
}

int Line::area(std::pair<int, int> a, std::pair<int, int> b,
    std::pair<int, int> c) {
    return (b.first - a.first) * (c.second - a.second) -
        (b.second - a.second) * (c.first - a.first);
}

Line::Line(std::pair<int, int> _a, std::pair<int, int> _b): a(_a), b(_b) {}

bool Line::intersection(Line l) {
    return intersect(a.first, b.first, l.a.first, l.b.first)
        && intersect(a.second, b.second, l.a.second, l.b.second)
        && area(a, b, l.a) * area(a, b, l.b) <= 0
        && area(l.a, l.b, a) * area(l.a, l.b, b) <= 0;
}
