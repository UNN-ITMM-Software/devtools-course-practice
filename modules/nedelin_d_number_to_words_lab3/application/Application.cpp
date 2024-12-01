// Copyright 2024 Nedelin Dmitry

#include <iostream>

#include "include/number_to_wordsApp.h"

int main(int argc, const char** argv) {
  Application app;
  auto output = app.runApp(argc, argv);
  for (auto str : output) {
    std::cout << str << std::endl;
  }
  return 0;
}
