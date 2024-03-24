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

class TheStringDoesNotContainCharacters : public std::exception {
 public:
    virtual const char* what() const noexcept {
        return "изза тупых проверок codev тут этот текст";
    }
};

class TheStringContainsNonLatinCharacters : public std::exception {
 public:
    virtual const char* what() const noexcept {
        return "изза тупых проверок codev тут этот текст";
    }
};

class IncorrectKeyLength : public std::exception {
 public:
    virtual const char* what() const noexcept {
        return "изза тупых проверок codev тут этот текст";
    }
};

class  GronsfeldCipher{
 private:
    std::string key;
    int first = 'a';
    int alfabet = 26;
    std::unordered_map<char, double> letterFrequency = {
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
    char crackLetter(std::string line);

 public:
    explicit GronsfeldCipher(std::string keyWord = "code");

    std::string getKey();

    void setKey(std::string keyWord);

    std::string encoder(std::string text);

    std::string decoder(std::string text);

    std::string getCrackKey(std::string text, size_t keySize);
};

#endif  // MODULES_KASHIN_S_LAB2_INCLUDE_GRONSFELDCIPHER_H_
