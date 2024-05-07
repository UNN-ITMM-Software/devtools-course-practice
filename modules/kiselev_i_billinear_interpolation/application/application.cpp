// Copyright 2024 Bodrov Daniil

#include <iostream>

#include "include/Billinear_interpolation_app.h"

int main(int argc, char* argv[]) {
  auto output = BillinearInterpolationApp()(argc, argv);

  std::cout << output << '\n';

  return 0;
}
