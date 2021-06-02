// Copyright 2021 Mishin Ilya

#ifndef MODULES_CEASAR_CIPHER_INCLUDE_CEASAR_APPLICATION_H_
#define MODULES_CEASAR_CIPHER_INCLUDE_CEASAR_APPLICATION_H_

#include <string>

class CeasarApplication {
 public:
    std::string operator()(int argc, const char** argv) const;

 private:
    std::string getHelp(const std::string& filename) const;
};

#endif  // MODULES_CEASAR_CIPHER_INCLUDE_CEASAR_APPLICATION_H_
