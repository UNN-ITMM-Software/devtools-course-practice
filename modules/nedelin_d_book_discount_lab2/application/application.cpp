// Copyright 2024 Смирнов Павел

#include <iostream>

#include "include/HarryPotterBooksApp.h"

int main(int argc, char *argv[]) {
  HarryPotterBooksApp app;
  auto output = app.run(argc, argv);

  std::cout << output << '\n';

  return 0;
}
