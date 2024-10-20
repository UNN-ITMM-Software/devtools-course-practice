// Copyright 2024 Podyachikh Mikhail

#include <stdio.h>
#include <stdlib.h>

#include <string>

#include "include/deposit_calculator_app.h"

int main(int argc, const char **argv) {
  Deposit::Application app{};
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
