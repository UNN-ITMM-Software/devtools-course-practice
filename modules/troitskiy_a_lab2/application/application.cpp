// Copyright 2024 Kozlov Mikhail

#include <iostream>

#include "include/Heap_app.h"

int main(int argc, const char *argv[]) {
  Heap_app app;
  auto output = app(argc, argv);

  std::cout << output << '\n';

  return 0;
}
