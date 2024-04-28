// Copyright 2024 Kashin Stepan

#include <iostream>

#include "../include/console_handler.h"

int main(int argc, char* argv[]) {
  ConsoleHandler app;
  std::cout << app.ConsoleInput(argc, argv) << '\n';
  return 0;
}
