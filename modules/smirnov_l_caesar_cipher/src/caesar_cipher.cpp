// Copyright 2024 Smirnov Leonid

#include "include/caesar_cipher.h"

const int CaesarCipher::MIN_OFFSET = 1;
const int CaesarCipher::MAX_OFFSET = 25;
const int CaesarCipher::ALPHABET_SIZE = 26;

CaesarCipher::CaesarCipher(const int _offset) {
    if (_offset < MIN_OFFSET || _offset > MAX_OFFSET) {
        throw std::invalid_argument("Invalid offset value.");
    }
    this->offset = _offset;
}

char CaesarCipher::ShiftChar(char c, int offset) const {
    char base = isupper(c) ? 'A' : 'a';
    return static_cast<char>((c - base + offset) % ALPHABET_SIZE + base);
}

std::string CaesarCipher::CaesarCipherEncoder
(const std::string& plaintext) const {
    if (plaintext.empty()) {
        throw std::invalid_argument("an empty line");
    }
    std::string result;

    for (const char c : plaintext) {
        if (isalpha(c)) {
            result += ShiftChar(c, offset);
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
            result += ShiftChar(c, ALPHABET_SIZE - offset);
        } else {
            result += c;
        }
    }
    return result;
}
