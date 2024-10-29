// Copyright 2024 Sokolova Daria

#include <iostream>

#include "include/pol_not_app.h"

int main(int argc, char* argv[]) {
  auto output = PolNotApp()(argc, argv);

  std::cout << output << '\n';

  return 0;
}
