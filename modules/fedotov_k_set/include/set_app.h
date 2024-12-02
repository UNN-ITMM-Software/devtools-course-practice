// Copyright 2024 Fedorets Ilya

#ifndef MODULES_FEDOTOV_K_SET_INCLUDE_SET_APP_H_
#define MODULES_FEDOTOV_K_SET_INCLUDE_SET_APP_H_

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "set.h"

class SetApp {
 private:
  std::string message_;

 public:
  void help(const char* appname, const char* message = "");
  bool validate(int argc, const char** argv);
  std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_FEDOTOV_K_SET_INCLUDE_SET_APP_H_
