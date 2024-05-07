// Copyright 2024 Martynov Aleksandr

#include <iostream>
#include "include/NumSysApplication.hpp"

int main(int argc, char *argv[]) {
  NumSysApplication application;
  std::cout << application.Parse(argc, argv) << std::endl;
  return 0;
}
