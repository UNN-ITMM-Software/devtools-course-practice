// Copyright 2024 Moiseev Nikita

#include <iostream>

#include "include/ra_convertor_app.h"

int main(int argc, char* argv[]) {
  auto output = ConverterApplication()(argc, argv);

  std::cout << output << '\n';

  return 0;
}
