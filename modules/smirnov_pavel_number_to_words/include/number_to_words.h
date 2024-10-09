#ifndef NUMBER_TO_WORDS_H
#define NUMBER_TO_WORDS_H

#include <string>

class NumberToWords {
 public:
  std::string convert(int number);

 private:
  std::string convertLessThanOneThousand(int number);
};

#endif
