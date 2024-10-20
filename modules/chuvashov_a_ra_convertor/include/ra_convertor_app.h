// Copyright 2024 Moiseev Nikita
#pragma once

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/ra_convertor.h"

class ConverterApplication {
 public:
  ConverterApplication() = default;
  std::string operator()(int argc, char* argv[]);

 private:
  std::string hullMessage{};
  bool validate(int argc, char* argv[]);
  void help(const char* appName, const char* msg = nullptr);
};
