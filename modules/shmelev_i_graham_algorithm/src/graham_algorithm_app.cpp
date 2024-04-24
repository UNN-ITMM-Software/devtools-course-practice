// Copyright 2024 Kulaev Zhenya

#include "include/graham_algorithm_app.h"

#include <cstring>
#include <sstream>

bool GrahamScanApplication::validate(int argc, char* argv[]) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc > 8) {
    help(argv[0], "the maximum number of points is 7");
    return false;
  } else if (std::strcmp(argv[1], "--help") == 0) {
    help(argv[0]);
    return false;
  }

  if (argc != 1 && argc <= 8) {
    points.resize(argc);
    for (int i = 1; i < argc; i++) {
      std::stringstream ss(argv[i]);
      double x, y;
      char comma, open_bracket, close_bracket;
      if (!(ss >> open_bracket >> x >> comma >> y >> close_bracket)) {
        help(argv[0],
                "Wrong number format, write --help to see how it is needed");
        points.clear();
        return false;
      }
      points[i - 1] = {x, y};
    }
  }
  return true;
}

void GrahamScanApplication::help(const char* appName, const char* msg) {
  std::stringstream message;

  if (msg) message << "Error: " << msg << '\n';

  message <<  "This is an application for calculating the convex hull";
  message << "by Graham's algorithm.\n\n";
  message <<  "Please provide arguments in the following format:\n\n";

  message <<  " $ " + std::string(appName) +
        " (point1.x, point1.y), ... ,  (point10.x, point10.y)," +

  "The coordinates of the points are " +
  "floating point numbers(double)"
   "at the end, it will output a convex hull";

  hullMessage = message.str();
}

std::string GrahamScanApplication::operator()(int argc, char* argv[]) {
  if (validate(argc, argv)) {
    Points hull = GrahamScan::convexHull(points);
    std::stringstream ss;
    for (auto& point : hull) {
      ss << "(" << point.first << ", " << point.second << ") ";
    }
    points.clear();
    hull.clear();
    hullMessage = ss.str();
  }
  return hullMessage;
}
