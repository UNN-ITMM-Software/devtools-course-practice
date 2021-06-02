// Copyright 2021 Pronkin Dmitry

#ifndef MODULES_GROSFELD_CIPHER_INCLUDE_GROSFELD_CIPHER_APP_H_
#define MODULES_GROSFELD_CIPHER_INCLUDE_GROSFELD_CIPHER_APP_H_

#include <string>
#include "./grosfeld_cipher.h"

class GronsfeldCipherApp {
 public:
    GronsfeldCipherApp();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    struct Arguments {
        std::string sourceString;
        int key;
        char operation;
    };
};

#endif  // MODULES_GROSFELD_CIPHER_INCLUDE_GROSFELD_CIPHER_APP_H_
