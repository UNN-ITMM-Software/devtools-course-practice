// Copyright 2024 Khodyrev Fedor

#pragma once

#include <string>

#include "include/caesar_cipher.h"

class CaesarCipherApplication {
 private:
    std::string msg;
    CaesarCipher cipher;
    bool Validate(int argc, char* argv[]);
    void Help(const char* application, const char* errMsg = nullptr);
 public:
    CaesarCipherApplication() = default;
    std::string CaesarCipherCryptography(int argc, char* argv[]);
};
