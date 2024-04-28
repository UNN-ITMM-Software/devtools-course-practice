// Copyright 2024 Khodyrev Fedor

#include <iostream>

#include "include/caesar_cipher_app.h"

int main(int argc, char* argv[]) {
    CaesarCipherApplication application;
    std::cout << application.CaesarCipherCryptography(argc, argv) << std::endl;
    return 0;
}
