// Copyright 2024 Nogin Denis

#include <iostream>

#include "include/avltree_app.h"

int main(int argc, char *argv[]) {
  auto output = AvlTreeApplication()(argc, argv);

  std::cout << output << '\n';

  return 0;
}
