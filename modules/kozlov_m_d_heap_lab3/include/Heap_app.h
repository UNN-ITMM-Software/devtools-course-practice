// Copyright 2024 Kozlov Mikhail

#ifndef MODULES_KOZLOV_M_D_HEAP_LAB3_INCLUDE_HEAP_APP_H_
#define MODULES_KOZLOV_M_D_HEAP_LAB3_INCLUDE_HEAP_APP_H_

#include <string>
#include <vector>

#include "include/Heap.h"

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

#endif // MODULES_KOZLOV_M_D_HEAP_LAB3_INCLUDE_HEAP_APP_H_
