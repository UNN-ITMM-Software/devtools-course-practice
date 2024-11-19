// Copyright 2024 Kachalov Mikhail

#include <iostream>
#include "include/stats_app.h"

int main(int argc, char* argv[]) {
  StatisticsApp app;
  std::cout << app(argc, argv) << std::endl;
  return 0;
}
