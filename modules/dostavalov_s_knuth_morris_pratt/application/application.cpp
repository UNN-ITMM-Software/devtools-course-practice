// Copyright 2024 Kudinov Nikita

#include <iostream>

#include "include/KMP_app.h"

int main(int argc, char* argv[]) {
  auto output = KMPApplication()(argc, argv);

  std::cout << output;

  return 0;
}
