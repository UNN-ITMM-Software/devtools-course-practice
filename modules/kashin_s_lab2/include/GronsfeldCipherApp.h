// Copyright 2024 Yurin Andrey


#ifndef DEVTOOLS_GRONSFELDCIPHERAPP_H
#define DEVTOOLS_GRONSFELDCIPHERAPP_H


#include <string>
#include <set>
#include "GronsfeldCipher.h"

class GronsfeldCipherApp {
private:
    const int requiredArgc{4};
    const std::vector<std::string> commands{"d", "e", "c"};
    GronsfeldCipher cipher = GronsfeldCipher();

    std::string _msg;

    bool Validate(int argc, char* argv[]);
    void Help(const char* application);
public:
    std::string GronsfeldCipherCryptography(int argc, char* argv[]);
};


#endif //DEVTOOLS_GRONSFELDCIPHERAPP_H
