// Copyright 2021 Tyurmina Alexandra

#include <string>
#include <cstring>

#include "include/leftist_heap_app.h"

void HeapSort::Info(const char* appname, const char* message) {
  message_ = std::string(message) +
    "This is a heapsort application. \n\n" +
    "Please, provide arguments in the following format: \n\n"
    " $ " + appname + " <x1> <x2> ... <xn>, \n\n" +
    "Where all arguments are integer numbers you want to sort. ";
}

bool HeapSort::CheckArguments(int argc, const char** argv) {
  if (argc == 1) {
    Info(argv[0]);
    return false;
  }

  for (int i = 1; i < argc; i++) {
    if ((atoi(argv[i]) == 0) && strcmp(argv[i], "0") != 0) {
      Info(argv[0], "ERROR : All arguments must be integers. \n\n");
      return false;
    }
  }

  return true;
}

std::string HeapSort::operator()(int argc, const char** argv) {
  LeftistHeap lh;
  std::string sorted = "";

  if (!CheckArguments(argc, argv)) {
    return message_;
  }
  for (int i = 1; i < argc; i++) {
    lh.insert(std::atoi(argv[i]));
  }
  while (!lh.isEmpty()) {
    sorted += (std::to_string(lh.findMin()) + " ");
    lh.deleteMin();
  }

  message_ = "Sorted array = " + sorted;
  return message_;
}
