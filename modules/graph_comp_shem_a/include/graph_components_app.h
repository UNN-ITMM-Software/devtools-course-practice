// Copyright 2024 Shemiakina Alesia

#pragma once

#include <cmath>
#include <stdexcept>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

#include "include/graph_components.h"

class GraphComponentsApplication {
 public:
  GraphComponentsApplication() = default;
  std::string operator()(int argc, char* argv[]);

 private:
  int n{};
  int result{};
  std::string message_{};
  bool validate(int argc, char* argv[]);
  void help(const char* appName, const char* msg = nullptr);
};
