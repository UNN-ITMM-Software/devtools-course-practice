// Copyright 2021 Kudriavtsev Alexandr

#include "include/cipher.h"

std::string Crypthography::CeasarCipher::Code(const std::string& message,
    int key) {
    auto res = message;
    auto size = message.size();
    const int alph_size = 26;  // ENG
    key = key % alph_size;
    if (key < 0) {
        key += alph_size;
    }
    for (size_t i = 0; i < size; ++i) {
        // English
        if (res[i] >= 'A' && res[i] <= 'Z') {
            res[i] = 'A' + (res[i] + key - 'A') % alph_size;  // 26
        } else if (res[i] >= 'a' && res[i] <= 'z') {
            res[i] = 'a' + (res[i] + key -'a') % alph_size;  // 26
        }
    }
    return res;
}

std::string Crypthography::CeasarCipher::Encode(const std::string& message,
    const int key) {
    return Code(message, key);
}

std::string Crypthography::CeasarCipher::Decode(const std::string& message,
    const int key) {
    return Code(message, -key);
}

