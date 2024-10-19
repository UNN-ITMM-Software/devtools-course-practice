// Copyright 2024 Belan Vadim

#ifndef MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_CONSOLE_APPLICATION_H_
#define MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_CONSOLE_APPLICATION_H_

#include <string>
#include <vector>

#include "include/savchuk_point.h"
#include "include/savchuk_segment.h"

class Application {
 public:
  int main(int argc, const std::vector<std::string>& argv);
  std::string run(const Segment& segment1, const Segment& segment2);
};

#endif  // MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_CONSOLE_APPLICATION_H_
