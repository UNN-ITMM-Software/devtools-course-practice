// Copyright 2024 Kirillov Maxim
#pragma once
#include <string>

#include "include/increasing_cont.h"

class IncreasingContrastApp {
 private:
  bool validate(int argc, char* argv[]);
  void help(const char* appName, const char* msg = nullptr);
  std::string message_;

 public:
  IncreasingContrastApp() = default;
  std::string operator()(int argc, char* argv[]);
};
