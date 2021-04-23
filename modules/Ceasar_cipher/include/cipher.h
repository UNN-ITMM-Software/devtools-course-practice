// Copyright 2021 Kudriavtsev Alexandr

#include <string>

#ifndef MODULES_CEASAR_CIPHER_INCLUDE_CIPHER_H_
#define MODULES_CEASAR_CIPHER_INCLUDE_CIPHER_H_

class CeasarCipher {
 private:
    std::string Code(const std::string& message, const int key);
    inline bool isLowerLetter(char ch);
    inline bool isUpperLetter(char ch);

 public:
    std::string Encode(const std::string& message, const int key = 1);
    std::string Decode(const std::string& message, const int key = 1);

    int GetKey(const std::string& encoded_message,
        const std::string& decoded_message);
};

#endif  // MODULES_CEASAR_CIPHER_INCLUDE_CIPHER_H_
