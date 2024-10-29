// Copyright 2024 Kochetov Nikolay

#include <iostream>

#include "include/queue_app.h"

int main(int argc, const char *argv[]) {
  QueueApp application;
  auto out = application.Start(argc, argv);
  std::cout << out << '\n';
  return 0;
}
