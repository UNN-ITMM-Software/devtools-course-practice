// Copyright 2021 Aleksandrychev Andrey

#include <vector>
#include <string>
#include <iostream>
#include "include/grosfeld_cipher.h"

int GronsfeldCipher::fixOverflow(int curVal, int min, int max) {
    int res = curVal;
    while (res < min) res = max - (min - res);
    while (res> max) res = min + (res - max);
    return res;
}

void GronsfeldCipher::intKeyToString(int key_) {
    this->keyString = std::to_string(key_);
    int lengthOfKey = this->keyString.length();
    for (int i = static_cast<int>(this->keyString.length());
        i < static_cast<int>(this->sourceString.length()); i++) {
        this->keyString += this->keyString[i % lengthOfKey];
    }
}

GronsfeldCipher::GronsfeldCipher(const std::string sourceString_,
            const int key_) {
    this->sourceString = sourceString_;
    this->key = key_;
    this->intKeyToString(this->key);
}

void GronsfeldCipher::setKey(int key_) {
    this->key = key_;
    this->keyString = std::to_string(key_);
    this->intKeyToString(this->key);
}

void GronsfeldCipher::setSourceString(std::string sourceString_) {
    this->sourceString = sourceString_;
    this->intKeyToString(this->key);
}

std::string GronsfeldCipher::getSource() {
    return this->sourceString;
}

std::string GronsfeldCipher::getKeyString() {
    return this->keyString;
}

int GronsfeldCipher::getKey() {
    return this->key;
}

std::string GronsfeldCipher::getCipher() {
    if (this->cipherString == "") {
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < static_cast<int>(this->keyString.length()); i++) {
            int curOffset =
                std::stoi(std::to_string(this->keyString[i])) - 48;
            int letterPlace = alphabet.find(this->sourceString[i], 0);
            int newLetterIndex = this->fixOverflow(letterPlace + curOffset,
                0, alphabet.length() - 1);

            this->cipherString += alphabet[newLetterIndex];
        }
    }

    return this->cipherString;
}

std::string GronsfeldCipher::decode(const std::string sourceString_,
                                    int sourceKey) {
    this->cipherString = sourceString_;
    this->key = sourceKey;
    this->keyString = std::to_string(sourceKey);
    int lengthOfKey = static_cast<int>(this->keyString.length());
    for (int i = static_cast<int>(this->keyString.length());
            i < static_cast<int>(this->sourceString.length()); i++) {
        this->keyString += this->keyString[i % lengthOfKey];
    }

    std::string trueString = "";

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < static_cast<int>(this->cipherString.length()); i++) {
        int curOffset = std::stoi(std::to_string(this->keyString[i])) - 48;
        int letterPlace = alphabet.find(this->cipherString[i], 0);
        int trueLetterIndex = this->fixOverflow(letterPlace - curOffset,
                            0, static_cast<int>(alphabet.length() - 1));

        trueString += alphabet[trueLetterIndex];
    }

    this->sourceString = trueString;

    return trueString;
}
