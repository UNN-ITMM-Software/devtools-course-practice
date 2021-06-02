// Copyright 2021 Tyurmina Alexandra

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_

#include <string>

#include "include/leftist_heap.h"

class HeapSort {
 private:
  std::string message_;
  void Info(const char* appname, const char* message = "");
  bool CheckArguments(int argc, const char** argv);

 public:
  std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_
