// Copyright 2021 Kudriavtsev Alexandr

#include <string>
#include <iostream>

#include "include/cipher.h"

std::string CeasarCipher::Code(const std::string& message,
    int key) {
    auto res = message;
    auto size = message.size();
    const int alph_size = 26;  // ENG
    key = key % alph_size;
    if (key < 0) {
        key += alph_size;
    }
    for (size_t i = 0; i < size; ++i) {
        if (isUpperLetter(res[i])) {
            res[i] = 'A' + (res[i] + key - 'A') % alph_size;
        } else if (isLowerLetter(res[i])) {
            res[i] = 'a' + (res[i] + key -'a') % alph_size;
        }
    }
    return res;
}

bool CeasarCipher::isLowerLetter(char ch) {
    return ch >= 'a' && ch <= 'z';
}

bool CeasarCipher::isUpperLetter(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

std::string CeasarCipher::Encode(const std::string& message,
    const int key) {
    return Code(message, key);
}

std::string CeasarCipher::Decode(const std::string& message,
    const int key) {
    return Code(message, -key);
}

int CeasarCipher::GetKey(const std::string& enc, const std::string& dec) {
    if (enc.size() != dec.size() || enc.size() == 0) {
        throw "Incorrect size";  // No message = any key
    }

    int key = enc[0] - dec[0];
    const int alph_size = 26;  // ENG
    if (key < 0) {
        key += alph_size;
    }
    auto size = enc.size();
    for (size_t i = 1; i < size; ++i) {
        if ((isLowerLetter(enc[i]) || isUpperLetter(enc[i]))) {
            int tmp_key = (enc[i] - dec[i]);
            if (tmp_key < 0 && key != (tmp_key + alph_size)
                || tmp_key >= 0 && key != (tmp_key)) {
                throw "This is not CC";  // CC
            }
        }
    }
    if (key < 0) {
        key += alph_size;
    }
    return key;
}
