// Copyright 2024 Kashin Stepan

#include <sstream>
#include <cstdlib>

#include "../include/console_handler.h"

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
  uint32_t left = std::strtoul(argv[1], nullptr, 10);
  uint32_t right = std::strtoul(argv[2], nullptr, 10);
  return ConsoleHandler::vectorToString(
    primeNumbers.getPrimeNumbersInRange(left, right));
}
