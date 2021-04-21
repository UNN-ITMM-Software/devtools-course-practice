// Copyright 2021 Kudriavtsev Alexandr

#include <string>

#ifndef MODULES_CEASAR_CIPHER_INCLUDE_CIPHER_H_
#define MODULES_CEASAR_CIPHER_INCLUDE_CIPHER_H_


class CeasarCipher {
 private:
    std::string Code(const std::string& message, const int key);

 public:
    std::string Encode(const std::string& message, const int key = 1);
    std::string Decode(const std::string& message, const int key = 1);
};


#endif  // MODULES_CEASAR_CIPHER_INCLUDE_CIPHER_H_
