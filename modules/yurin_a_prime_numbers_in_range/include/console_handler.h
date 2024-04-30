// Copyright 2024 Kashin Stepan

#ifndef MODULES_YURIN_A_PRIME_NUMBERS_IN_RANGE_INCLUDE_CONSOLE_HANDLER_H_
#define MODULES_YURIN_A_PRIME_NUMBERS_IN_RANGE_INCLUDE_CONSOLE_HANDLER_H_

#define NO_ARGUMENTS "There are no arguments. Example : <number1> <number2>"

#include <string>
#include <vector>

#include "../include/getting_prime_numbers.h"

class ConsoleHandler {
 private:
  GettingPrimeNumbers primeNumbers = GettingPrimeNumbers();
  std::string vectorToString(const std::vector<uint32_t> &vec);

 public:
  std::string ConsoleInput(int argc, char* argv[]);
};

#endif  // MODULES_YURIN_A_PRIME_NUMBERS_IN_RANGE_INCLUDE_CONSOLE_HANDLER_H_
