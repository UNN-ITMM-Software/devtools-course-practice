// Copyright 2021 Aleksandrychev Andrey

#include <vector>
#include <string>
#include <iostream>
#include "include/grosfeld_cipher.h"

#define INTMAX 2147483647
#define INTMIN -2147483648

int GronsfeldCipher::NOD(int a, int b) {
    while (a && b)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a | b;
}

int GronsfeldCipher::GCD(std::vector<int> list) {
    int GCD = list[0];

    for (int i = 1; i < list.size(); i++) {
        GCD = NOD(GCD, list[i]);
    }

    return GCD;
}

int GronsfeldCipher::fixOverflow(int curVal, int min, int max) {
    int res = curVal;
    while (res < min) res = max - (min - res);
    while (res> max) res = min + (res - max);
    return res;
}

int GronsfeldCipher::KasiskeMethod(std::string sourceString) {
    if (sourceString.length() < 90) return INTMIN;

    int probValueStartIndex = 0;
    int probValueSize = 3;
    std::string probValue = sourceString.substr(probValueStartIndex,
            probValueStartIndex + probValueSize);

    int countProbValue = 1;

    int probValueNextIndex = 3;

    while (countProbValue < 3 &&
            probValueStartIndex + probValueSize <
                static_cast<int>(sourceString.length() - 1)) {
        int placeProbValue = sourceString.find(probValue, probValueNextIndex);
        if (placeProbValue == -1) {
            probValueStartIndex += 1;
            probValue = sourceString.substr(probValueStartIndex,
                    probValueStartIndex + probValueSize);
            countProbValue = 1;
        } else {
            probValueNextIndex = placeProbValue;
            countProbValue += 1;
        }
    }

    if (probValueStartIndex + probValueSize >=
            static_cast<int>(sourceString.length() - 1)) {
        return INTMAX;
    }

    std::vector<int> deltas;
    probValueStartIndex = sourceString.find(probValue, 0);
    probValueNextIndex = sourceString.find(probValue, probValueStartIndex);
    while (probValueNextIndex >= 0) {
        deltas.push_back(probValueNextIndex - probValueStartIndex);
        probValueStartIndex = probValueNextIndex;
        probValueNextIndex = sourceString.find(probValue, probValueStartIndex);
    }

    return this->GCD(deltas);
}

GronsfeldCipher::GronsfeldCipher(const std::string sourceString_,
            const int key_) {
    this->sourceString = sourceString_;
    this->key = key_;
    this->keyString = std::to_string(key_);
    int lengthOfKey = this->keyString.length();
    for (int i = static_cast<int>(this->keyString.length());
            i < this->sourceString.length(); i++) {
        this->keyString += this->keyString[i % lengthOfKey];
    }
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
            int curOffset = std::stoi(std::to_string(this->keyString[i]));
            int letterPlace = alphabet.find(this->keyString[i], 0);
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
            i < this->sourceString.length(); i++) {
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

std::string GronsfeldCipher::hack(std::string cipherString) {
    std::string trueString = "";

    int probkeyStringSize = this->KasiskeMethod(cipherString);
    if (probkeyStringSize == INTMIN) return "ERROR: So small string !!!";
    if (probkeyStringSize == INTMAX) return "WARNING: Failed to decode.";

    return trueString;
}
