// Copyright 2024 Sobol Lyubov

#pragma once

#include <string>

#include "include/stack.h"
typedef int T;
class StackApp {
 public:
  StackApp() = default;
  Stack<T> Mystack;
  std::string operator()(int argc, char *argv[]);

 private:
  std::string message_{};

  bool validate(int argc, char *argv[]);

  void help(const char *appName, const char *errorMessage = nullptr);
};
