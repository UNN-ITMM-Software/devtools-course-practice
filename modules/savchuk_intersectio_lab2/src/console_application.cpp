// Copyright 2024 Belan Vadim

#include "include/console_application.h"

#include <iostream>
#include <sstream>

#include "include/savchuk_intersectio.h"

const int EXPECTED_ARGUMENT_COUNT = 9;

int Application::main(int argc, const std::vector<std::string>& argv) {
  if (argc != EXPECTED_ARGUMENT_COUNT) {
    std::cerr << "Usage: " << argv[0] << " x1 y1 x2 y2 x3 y3 x4 y4"
              << std::endl;
    return 1;
  }

  double x1 = std::stod(argv[1]);
  double y1 = std::stod(argv[2]);
  double x2 = std::stod(argv[3]);
  double y2 = std::stod(argv[4]);
  double x3 = std::stod(argv[5]);
  double y3 = std::stod(argv[6]);
  double x4 = std::stod(argv[7]);
  double y4 = std::stod(argv[8]);

  Segment segment1(Point(x1, y1), Point(x2, y2));
  Segment segment2(Point(x3, y3), Point(x4, y4));

  std::string output = run(segment1, segment2);
  std::cout << output << std::endl;

  return 0;
}

std::string Application::run(const Segment& segment1, const Segment& segment2) {
  std::stringstream ss;
  if (TwoSegments::checkIntersection(segment1, segment2)) {
    ss << "Segments intersect";
  } else if (TwoSegments::checkParallel(segment1, segment2)) {
    ss << "Segments are parallel";
  } else {
    ss << "Segments do not intersect";
  }
  return ss.str();
}
