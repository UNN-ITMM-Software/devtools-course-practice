// Copyright 2021 Kudriavtsev Alexandr

#ifndef MODULES_CEASAR_CIPHER_INCLUDE_CIPHER_H_
#define MODULES_CEASAR_CIPHER_INCLUDE_CIPHER_H_

#include <string>

class CeasarCipher {
 private:
    std::string code(const std::string& message, int key);
    inline bool isLowerLetter(char ch);
    inline bool isUpperLetter(char ch);

    static const int alph_size = 26;

 public:
    std::string encode(const std::string& message, int key = 1);
    std::string decode(const std::string& message, int key = 1);

    int getKey(const std::string& enc, const std::string& dec);
};

#endif  // MODULES_CEASAR_CIPHER_INCLUDE_CIPHER_H_
