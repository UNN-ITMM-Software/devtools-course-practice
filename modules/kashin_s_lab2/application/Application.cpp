// Copyright 2024 Yurin Andrey

#include <iostream>

#include "../include/GronsfeldCipherApp.h"

int main(int argc, char* argv[]) {
  GronsfeldCipherApp app;
  std::cout << app.GronsfeldCipherCryptography(argc, argv) << '\n';
  return 0;
}
