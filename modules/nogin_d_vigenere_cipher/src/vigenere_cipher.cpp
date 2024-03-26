// Copyright 2024 Nogin Denis

#include "include/vigenere_cipher.h"

namespace var {
extern const int lowerCaseBegin = 97;
extern const int lowerCaseEnd = 122;
extern const int upperCaseBegin = 65;
extern const int upperCaseEnd = 90;
extern const int alphabetSize = 26;
} // namespace var

std::string vigenereCipher(const std::string &data, const std::string &key) {
  std::string transformKey = key;
  std::transform(transformKey.begin(), transformKey.end(), transformKey.begin(),
                 [](unsigned char symbol) { return std::tolower(symbol); });
  std::string result;

  int lenKey = transformKey.size();
  int lenData = data.size();
  int space = 0;

  for (int i = 0; i < lenData; ++i) {
    unsigned char new_symbol;
    if ((data[i] >= var::upperCaseBegin) && (data[i] <= var::lowerCaseEnd) &&
        ((data[i] <= var::upperCaseEnd) || (data[i] >= var::lowerCaseBegin))) {
      new_symbol =
          data[i] + transformKey[(i - space) % lenKey] - var::lowerCaseBegin;
      if ((data[i] <= var::upperCaseEnd) && (data[i] >= var::upperCaseBegin)) {
        while (new_symbol > var::upperCaseEnd)
          new_symbol -= var::alphabetSize;
      } else if ((data[i] <= var::lowerCaseEnd) &&
                 (data[i] >= var::lowerCaseBegin)) {
        while (new_symbol > var::lowerCaseEnd)
          new_symbol -= var::alphabetSize;
      }
    } else {
      ++space;
      new_symbol = data[i];
    }
    result += new_symbol;
  }

  return result;
}

std::string vigenereDecipher(const std::string &cipher,
                             const std::string &key) {
  std::string transformKey = key;
  std::transform(transformKey.begin(), transformKey.end(), transformKey.begin(),
                 [](unsigned char symbol) { return std::tolower(symbol); });
  std::string result;

  int lenKey = transformKey.size();
  int lenCipher = cipher.size();
  int space = 0;

  for (int i = 0; i < lenCipher; ++i) {
    unsigned char new_symbol;
    if ((cipher[i] >= var::upperCaseBegin) &&
        (cipher[i] <= var::lowerCaseEnd) &&
        ((cipher[i] <= var::upperCaseEnd) ||
         (cipher[i] >= var::lowerCaseBegin))) {
      new_symbol =
          cipher[i] - transformKey[(i - space) % lenKey] + var::lowerCaseBegin;
      if ((cipher[i] <= var::upperCaseEnd) &&
          (cipher[i] >= var::upperCaseBegin)) {
        while (new_symbol < var::upperCaseBegin)
          new_symbol += var::alphabetSize;
      } else if ((cipher[i] <= var::lowerCaseEnd) &&
                 (cipher[i] >= var::lowerCaseBegin)) {
        while (new_symbol < var::lowerCaseBegin)
          new_symbol += var::alphabetSize;
      }
    } else {
      ++space;
      new_symbol = cipher[i];
    }
    result += new_symbol;
  }

  return result;
}
