// Copyright 2024 Nedelin Dmitry

#ifndef MODULES_NEDELIN_DMITRY_NUMBER_TO_WORDS_INCLUDE_NUMBER_TO_WORDS_H_
#define MODULES_NEDELIN_DMITRY_NUMBER_TO_WORDS_INCLUDE_NUMBER_TO_WORDS_H_

#include <string>

class NumberToWords {
 public:
  std::string convert(int number);

 private:
  std::string convertLessThanOneThousand(int number);
};

#endif  // MODULES_NEDELIN_DMITRY_NUMBER_TO_WORDS_INCLUDE_NUMBER_TO_WORDS_H_
