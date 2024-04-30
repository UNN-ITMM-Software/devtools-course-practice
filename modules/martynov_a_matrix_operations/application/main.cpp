#include "include/application.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  MatOpsApplication application;
  std::cout << application.Parse(argc, argv) << std::endl;
  return 0;
}