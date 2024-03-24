// Copyright 2024 Kashin Stepa

#ifndef MODULES_KASHIN_S_LAB2_INCLUDE_GRONSFELDCIPHER_H_
#define MODULES_KASHIN_S_LAB2_INCLUDE_GRONSFELDCIPHER_H_

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <algorithm>

using std::string;
using std::unordered_map;
using std::exception;

class TheStringDoesNotContainCharacters : public std::exception {
 public:
    virtual const char* what() const noexcept {
        return "it was expected"
        "that the line would not be empty";
    }
};

class TheStringContainsNonLatinCharacters : public std::exception {
 public:
    virtual const char* what() const noexcept {
        return "the string was"
        " expected to contain only Latin characters";
    }
};

class IncorrectKeyLength : public std::exception {
 public:
    virtual const char* what() const noexcept {
        return "the key must"
        " be longer than 0 and less than the length of the text";
    }
};

class  GronsfeldCipher{
 private:
    string key;
    int first = 'a';
    int alfabet = 26;
    unordered_map<char, double> letterFrequency = {
            {'a', 8.17},
            {'b', 1.49},
            {'c', 2.78},
            {'d', 4.25},
            {'e', 12.70},
            {'f', 2.23},
            {'g', 2.02},
            {'h', 6.09},
            {'i', 6.97},
            {'j', 0.15},
            {'k', 0.77},
            {'l', 4.03},
            {'m', 2.41},
            {'n', 6.75},
            {'o', 7.51},
            {'p', 1.93},
            {'q', 0.10},
            {'r', 5.99},
            {'s', 6.33},
            {'t', 9.06},
            {'u', 2.76},
            {'v', 0.98},
            {'w', 2.36},
            {'x', 0.15},
            {'y', 1.97},
            {'z', 0.07}
    };
    char encode_char(char word, char code) const;
    char decoder_char(char word, char code) const;
    char crackLetter(string line);

public:
    explicit GronsfeldCipher(string keyWord = "code");

    string getKey();

    void setKey(string keyWord);

    string encoder(string text);

    string decoder(string text);

    string getCrackKey(string text, int keySize);
};

#endif  // MODULES_KASHIN_S_LAB2_INCLUDE_GRONSFELDCIPHER_H_
