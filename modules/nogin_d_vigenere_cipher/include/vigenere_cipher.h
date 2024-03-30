// Copyright 2024 Nogin Denis

#ifndef MODULES_NOGIN_D_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
#define MODULES_NOGIN_D_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

bool validateKey(const std::string& key);

std::string vigenereCipher(const std::string& data, const std::string& key);

std::string vigenereDecipher(const std::string& cipher, const std::string& key);

#endif  // MODULES_NOGIN_D_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
