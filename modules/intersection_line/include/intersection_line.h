// Copyright 2021 Skripal Andrey

#include <utility>
#include <algorithm>

#ifndef MODULES_INTERSECTION_LINE_INCLUDE_INTERSECTION_LINE_H_
#define MODULES_INTERSECTION_LINE_INCLUDE_INTERSECTION_LINE_H_

class Line {
 private:
    std::pair<int, int>  a;
    std::pair<int, int>  b;

 public:
    bool intersect(int a, int  b, int  c, int  d);
    int area(std::pair<int, int>  a, std::pair<int, int>  b,
        std::pair<int, int>  c);
    Line(std::pair<int, int>  _a, std::pair<int, int> _b);
    bool intersection(Line l);
};

#endif  // MODULES_INTERSECTION_LINE_INCLUDE_INTERSECTION_LINE_H_
