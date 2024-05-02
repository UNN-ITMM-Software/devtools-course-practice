// Copyright 2017 Korniakov Kirill

#include <iostream>
#include <string>

#include "include/metrics_app.h"

int main(int argc, const char** argv) {
  MetricsApp app;
  std::cout << app(argc, argv);
  return 0;
}
