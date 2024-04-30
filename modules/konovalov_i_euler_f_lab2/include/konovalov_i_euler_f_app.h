// Copyright 2024 Videneva Ekaterina

#pragma once

#include <cmath>
#include <stdexcept>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

#include "include/konovalov_i_euler_f.h"

class EulerFunctionApplication {
 public:
  enum class Option { Naive, NotNaive };
  EulerFunctionApplication() = default;
  std::string operator()(int argc, char* argv[]);

 private:
  Option mOption{};
  int n{};
  int result{};
  std::string message_{};
  bool validate(int argc, char* argv[]);
  void help(const char* appName, const char* msg = nullptr);
};
