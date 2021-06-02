// Copyright 2021 Schekotilova Julia

#include <iostream>
#include <string>

#include "include/algorithm_huffmana_app.h"

int main(int argc, const char** argv) {
  AlgorithmHuffmanaApp app;
  std::string output = app(argc, argv);
  std::cout << output;
return 0;
}
