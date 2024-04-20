// Copyright 2024 Kulaev Zhenya
#pragma once

#include <cmath>
#include <stdexcept>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

#include "include/graham_algorithm.h"

class GrahamScanApplication{
 public:
  GrahamScanApplication() = default;
  std::string operator()(int argc, char* argv[]);

 private:
  Points points{};
  std::string hullMessage{};
  bool validate(int argc, char* argv[]);
  void help(const char* appName, const char* msg = nullptr);
};
