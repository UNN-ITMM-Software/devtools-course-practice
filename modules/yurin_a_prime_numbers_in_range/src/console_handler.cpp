// Copyright 2024 Kashin Stepan

#include <sstream>

#include "include/getting_prime_numbers.h"

std::string ConsoleHandler::vectorToString(const std::vector<uint32_t> &vec) {
    std::stringstream ss;

    ss << "{";

    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i != vec.size() - 1) {
            ss << ", ";
        }
    }

    ss << "}";

    return ss.str();
}

std::string ConsoleHandler::ConsoleInput(int argc, char **argv) {
  if (argc < 3) {
    return NO_ARGUMENTS;
  }

  uint32_t left = argv[1];
  uint32_t right = argv[2];

  return ConsoleHandler::vectorToString(
    primeNumbers.getPrimeNumbersInRange(left, right)
    );
}
