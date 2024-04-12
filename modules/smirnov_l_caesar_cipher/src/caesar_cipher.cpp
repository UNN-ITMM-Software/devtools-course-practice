// Copyright 2024 Smirnov Leonid

#include "include/caesar_cipher.h"

CaesarCipher::CaesarCipher(const int _offset) {
    if (_offset < 1 || _offset > 25) {
        throw std::invalid_argument("invalid value");
    }
    this->offset = _offset;
}

std::string CaesarCipher::CaesarCipherEncoder
(const std::string& plaintext) const {
    if (plaintext.empty()) {
        throw std::invalid_argument("an empty line");
    }
    std::string result;

    for (const char c : plaintext) {
        if (isalpha(c)) {
            if (isupper(c)) {
                result += static_cast<char>((c - 'A' + offset) % 26 + 'A');
            }
            if (islower(c)) {
                result += static_cast<char>((c - 'a' + offset) % 26 + 'a');
            }
        } else {
            result += c;
        }
    }
    return result;
}

std::string CaesarCipher::CaesarCipherDecoder
(const std::string& ciphertext) const {
    if (ciphertext.empty()) {
        throw std::invalid_argument("an empty line");
    }
    std::string result;

    for (const char c : ciphertext) {
        if (isalpha(c)) {
            if (isupper(c)) {
                result += static_cast<char>((c - 'A' - offset + 26) % 26 + 'A');
            }
            if (islower(c)) {
                result += static_cast<char>((c - 'a' - offset + 26) % 26 + 'a');
            }
        } else {
            result += c;
        }
    }
    return result;
}
