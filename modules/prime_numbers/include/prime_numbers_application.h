// Copyright 2021 Kolesnikov Gleb

#ifndef MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_APPLICATION_H_
#define MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_APPLICATION_H_

#include "include/prime_numbers.h"

#include <string>

class PrimeNumbersApplication {
 public:
    std::string operator()(int argc, const char** argv);

 private:
     std::string getHelp(const std::string& appname);
     bool checkArgument(const std::string& str);
     int parseArgument(const char* arg);
};
#endif  // MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_APPLICATION_H_
