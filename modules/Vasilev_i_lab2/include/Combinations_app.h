// Copyright 2024 Tushentsova Karina

#pragma once

#include <string>

#include "include/Combinations.h"

class CombinationsApp {
 public:
  CombinationsApp() = default;

  std::string operator()(int argc, char* argv[]);

 private:
  std::string helpMssg{};
  std::string input{};

  bool validate(int argc, char* argv[]);

  void help(const char* appName, const char* errorMessage = nullptr);
};
