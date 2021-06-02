// Copyright 2021 Ludina Daria

#include <iostream>
#include <string>

#include "include/mortgage_app.h"

int main(int argc, const char** argv) {
  mortgage_app app;
  std::string output = app(argc, argv);
  std::cout << output.c_str() << std::endl;
  return 0;
}
