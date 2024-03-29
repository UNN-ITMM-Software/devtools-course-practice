// Copyright 2024 Kuznetsov Artem

#include <iostream>

#include "include/vigenere_cipher_app.h"

int main(int argc, char* argv[]) {
  auto output = VigenereApplication()(argc, argv);

  std::cout << output << '\n';

  return 0;
}
