// Copyright 2024 Smirnov Pavel

#ifndef MODULES_SMIRNOV_PAVEL_NUMBER_TO_WORDS_INCLUDE_NUMBER_TO_WORDS_H_
#define MODULES_SMIRNOV_PAVEL_NUMBER_TO_WORDS_INCLUDE_NUMBER_TO_WORDS_H_

#include <string>

class NumberToWords {
 public:
  std::string convert(int number);

 private:
  std::string convertLessThanOneThousand(int number);
};

#endif  // MODULES_SMIRNOV_PAVEL_NUMBER_TO_WORDS_INCLUDE_NUMBER_TO_WORDS_H_
