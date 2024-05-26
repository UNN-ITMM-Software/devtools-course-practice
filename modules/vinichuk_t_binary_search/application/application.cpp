// Copyright 2024 Borisov Saveliy

#include <iostream>

#include "include/BinarySearchApp.h"

int main(int argc, char* argv[]) {
  auto output = BinarySearchApplication()(argc, argv);

  std::cout << output << '\n';

  return 0;
}
