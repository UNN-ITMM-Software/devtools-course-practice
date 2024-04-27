// Copyright 2024 Khramov Ivan

#include <iostream>

#include "include/point_hits_a_triangle_app.h"

int main(int argc, char* argv[]) {
    PointTriangleApplication application;
    std::cout << application.CheckInside(argc, argv) << std::endl;
    return 0;
}
