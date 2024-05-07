// Copyright 2024 Shubin Mikhail

#include <iostream>
#include "include/application.hpp"

int main(int argc, char* argv[]) {
  MatOpsApplication application;
  std::cout << application.Parse(argc, argv) << std::endl;
  return 0;
}
