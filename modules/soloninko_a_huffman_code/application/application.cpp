// Copyright 2024 Lesnikov Nikita

#include <iostream>

#include "include/huffman_app.h"

int main(int argc, char** argv) {
  HuffmanApp app;
  std::cout << app(argc, argv);
  return 0;
}
