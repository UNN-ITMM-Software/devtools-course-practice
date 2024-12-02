// Copyright 2024 Nedelin Dmitry

#ifndef MODULES_NEDELIN_D_NUMBER_TO_WORDS_LAB3_INCLUDE_NUMBER_TO_WORDS_H_
#define MODULES_NEDELIN_D_NUMBER_TO_WORDS_LAB3_INCLUDE_NUMBER_TO_WORDS_H_

#include <string>

class NumberToWords {
 public:
  std::string convert(int number);

 private:
  std::string convertLessThanOneThousand(int number);
};

#endif  // MODULES_NEDELIN_D_NUMBER_TO_WORDS_LAB3_INCLUDE_NUMBER_TO_WORDS_H_
