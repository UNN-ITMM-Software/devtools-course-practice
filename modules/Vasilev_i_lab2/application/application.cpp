// Copyright 2024 Tushentsova Karina

#include <iostream>

#include "include/Combinations_app.h"

int main(int argc, char* argv[]) {
  auto output = CombinationsApp()(argc, argv);

  std::cout << output << '\n';

  return 0;
}
