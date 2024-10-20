// Copyright 2024 Kulaev Zhenya
#pragma once

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/graham_algorithm.h"

class GrahamScanApplication {
 public:
  GrahamScanApplication() = default;
  std::string operator()(int argc, char* argv[]);

 private:
  Points points{};
  std::string hullMessage{};
  bool validate(int argc, char* argv[]);
  void help(const char* appName, const char* msg = nullptr);
};
