// Copyright 2021 Kudriavtsev Alexandr

#include <string>

#include "include/cipher.h"

std::string CeasarCipher::code(const std::string& message, int key) {
    auto res = message;
    auto size = message.size();
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

bool CeasarCipher::isLowerLetter(char ch) {  // Lowercase
    return (ch >= 'a' && ch <= 'z');
}

bool CeasarCipher::isUpperLetter(char ch) {  // Uppercase
    return (ch >= 'A' && ch <= 'Z');
}

std::string CeasarCipher::encode(const std::string& message, int key) {
    return code(message, key);
}

std::string CeasarCipher::decode(const std::string& message, int key) {
    return code(message, -key);
}

int CeasarCipher::getKey(const std::string& enc, const std::string& dec) {
    if (enc.size() != dec.size() || enc.size() == 0) {
        throw "Incorrect size";  // No message = any key
    }
    auto size = enc.size();
    for (size_t i = 0; i < size; ++i) {
        if ((isLowerLetter(enc[i]) && !isLowerLetter(dec[i]))
            || (isUpperLetter(enc[i]) && !isUpperLetter(dec[i])))
            throw "This is not CC";  // C.C.
    }

    int key;

    size_t i;
    for (i = 0; i < size; ++i) {
        if (isLowerLetter(enc[i]) || isUpperLetter(enc[i])) {
            key = (enc[i] - dec[i]);

            if (key < 0) {
                key += alph_size;
            }
            break;
        }
    }

    for (size_t i = 1; i < size; ++i) {
        if ((isLowerLetter(enc[i]) || isUpperLetter(enc[i]))) {
            int tmp_key = (enc[i] - dec[i]);
            if ((tmp_key < 0 && key != (tmp_key + alph_size))
                || (tmp_key >= 0 && key != tmp_key)) {
                throw "This is not CC";  // C.C.
            }
        }
    }
    return key;
}
