// Copyright 2024 Fedorets Ilya

#include <iostream>
#include <string>

#include "include/set_app.h"

int main(int argc, const char** argv) {
  SetApp app;
  try {
    std::cout << app(argc, argv) << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
