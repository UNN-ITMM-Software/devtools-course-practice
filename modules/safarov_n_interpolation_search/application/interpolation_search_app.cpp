// Copyright 2024 Borovkov Sergey
#include "include/interpolation_search_app.h"

#include <iostream>

int main(int argc, char* argv[]) {
  SearchApp app;
  std::string output = app.search_application(argc, argv);
  std::cout << output << '\n';
  return 0;
}
