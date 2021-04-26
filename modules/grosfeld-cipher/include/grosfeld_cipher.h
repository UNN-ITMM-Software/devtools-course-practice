// Copyright 2021 Aleksandrychev Andrey

#ifndef MODULES_GROSFELD_CIPHER_INCLUDE_GROSFELD_CIPHER_H_
#define MODULES_GROSFELD_CIPHER_INCLUDE_GROSFELD_CIPHER_H_

#include <vector>
#include <string>


class GronsfeldCipher {
 public:
    GronsfeldCipher(const std::string sourceString_, const int key_);
    ~GronsfeldCipher() = default;

    std::string getKeyString();
    int getKey();
    std::string getSource();

    std::string getCipher();
    std::string decode(const std::string sourceString_, int key);

    std::string hack(std::string cipherString);

 private:
    std::string sourceString = "";
    std::string keyString = "";
    int key = 0;

    std::string cipherString = "";

    int fixOverflow(int curVal, int min, int max);
    int KasiskeMethod(std::string sourceString);
    int NOD(int a1, int a2);
    int GCD(std::vector<int> list);
};

#endif  // MODULES_GROSFELD_CIPHER_INCLUDE_GROSFELD_CIPHER_H_
