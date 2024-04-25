// Copyright 2024 Khramov Ivan

#pragma once

#include <string>

#include "include/point_hits_a_triangle.h"

class PointTriangleApplication {
 private:
    std::string msg;
    Triangle triangle;
    Point point;
    bool Validate(int argc, char* argv[]);
    void Help(const char* application, const char* errMsg = nullptr);
 public:
    PointTriangleApplication() = default;
    std::string CheckInside(int argc, char* argv[]);
};
