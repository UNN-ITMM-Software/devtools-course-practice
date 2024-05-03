// Copyright 2024 Dostavalov Semyon

#include "include/djarvis_app.h"
#include "include/djarvis.h"

std::string Application::run(std::vector<std::string>& args) {
    std::stringstream ss;
    std::vector<Point> points;

    if (args.empty()) {
        ss << "Usage: <executable> <point1_x> <point1_y> "
            "<point2_x> <point2_y> ...";
        return ss.str();
    }

    if (args.size() % 2 != 0) {
        ss << "Error: Invalid number of arguments!";
        return ss.str();
    }
    for (size_t i = 0; i < args.size(); i += 2) {
        try {
            double x = std::stod(args[i]);
            double y = std::stod(args[i + 1]);
            points.push_back({ x, y });
        }
        catch (const std::invalid_argument& e) {
            ss << "Error: Wrong point format!";
            return ss.str();
        }
    }
    if (points.size() < 3) {
        ss << "Error: Not enough points to form a convex hull!";
        return ss.str();
    }

}

