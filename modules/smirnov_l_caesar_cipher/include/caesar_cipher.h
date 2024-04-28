// Copyright 2024 Smirnov Leonid

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class CaesarCipher {
 private:
    int offset;
    static const int MIN_OFFSET;
    static const int MAX_OFFSET;
    static const int ALPHABET_SIZE;

 public:
    CaesarCipher() : offset(0) {}
    explicit CaesarCipher(int _offset);

    char ShiftChar(char c, int offset) const;
    std::string CaesarCipherEncoder(const std::string& plaintext) const;
    std::string CaesarCipherDecoder(const std::string& ciphertext) const;
};
