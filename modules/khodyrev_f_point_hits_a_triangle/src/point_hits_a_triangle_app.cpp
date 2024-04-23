// Copyright 2024 Khramov Ivan

#include "include/point_hits_a_triangle_app.h"

#include <cstring>
#include <exception>
#include <sstream>

bool PointTriangleApplication::Validate(int argc, char *argv[]) {
    int required_argc = 9;
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (std::strcmp(argv[1], "--help") == 0) {
        Help(argv[0]);
        return false;
    } else if (argc != required_argc) {
        Help(argv[0], "Incorrect number of arguments.");
        return false;
    } else {
        try {
            double x1 = std::stod(argv[1]);
            double y1 = std::stod(argv[2]);
            double x2 = std::stod(argv[3]);
            double y2 = std::stod(argv[4]);
            double x3 = std::stod(argv[5]);
            double y3 = std::stod(argv[6]);
            double point_x = std::stod(argv[7]);
            double point_y = std::stod(argv[8]);

            point = Point(point_x, point_y);
            triangle = Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
        } catch(const std::exception& e) {
            Help(argv[0], "Invalid arguments.");
            return false;
        }
    }
    return true;
}

void PointTriangleApplication::Help(const char *application,
 const char *errMsg) {
    std::stringstream message;

    if (errMsg) {
        message << "Error: " << errMsg << '\n';
    }

    message << "Usage:\n";
    message << '\t' << application <<
    " <x1> <y1> <x2> <y2> <x3> <y3> <point_x> <point_y>\n";
    message << "Where:\n";
    message << '\t' <<
    "<x1>, <y1>, <x2>, <y2>, <x3>, <y3> are coord-s of triangle vertices.\n";
    message << '\t' << "<point_x>, <point_y> are coord-s of point.\n";
    msg = message.str();
}

std::string PointTriangleApplication::CheckInside(int argc, char *argv[]) {
    if (Validate(argc, argv)) {
        try {
            if (triangle.isValid()) {
                if (triangle.isInside(point)) {
                    return "Point is inside the triangle.";
                } else {
                    return "Point is outside the triangle.";
                }
            }
        }
        catch(const std::exception& e) {
            return "Error: Invalid input of triangle points.";
        }
    }
    return msg;
}
