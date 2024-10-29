// Copyright 2024 Kirillov Maxim

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "include/increasing_cont_app.h"

int main(int argc, char* argv[]) {
  auto output = IncreasingContrastApp()(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
