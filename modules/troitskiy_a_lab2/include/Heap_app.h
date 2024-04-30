// Copyright 2024 Kozlov Mikhail

#ifndef MODULES_TROITSKIY_A_LAB2_INCLUDE_HEAP_APP_H_
#define MODULES_TROITSKIY_A_LAB2_INCLUDE_HEAP_APP_H_

#include <string>
#include <vector>
#include <stdexcept>

#include "include/lab2.h"

class Heap_app {
 public:
  Heap_app() = default;

  std::string operator()(int argc, const char **argv);

 private:
  void help(const char *appname, const char *message = "");
  bool validateNumberOfArguments(int argc, const char **argv);
  std::string message_;
  typedef struct {
    std::vector<double> nums;
    char operation;
  } Arguments;
};

#endif   // MODULES_TROITSKIY_A_LAB2_INCLUDE_HEAP_APP_H_
