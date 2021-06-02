// Copyright 2021 Tsvetkov Maxim

#ifndef MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_
#define MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_

#include <vector>
#include <algorithm>
#include <string>
#include <functional>

class StringCalculator {
 private:
    static bool isNumber(char a);

 public:
    template <typename Op>
    static int operation(const std::string& str, Op operation) {
         std::string numbers(str);
         if (numbers == "") {
            return 0;
         }

         int result;

         if (std::is_same<Op, std::multiplies<int>>::value) {
            result = 1;
         } else {
            result = 0;
         }

         char separator = ',';

         if (!isNumber(numbers[0])) {
            separator = numbers[0];
            numbers.erase(0, 2);
         }

         for (size_t i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == separator || numbers[i] == '\n') {
                  numbers[i] = ' ';
            }
         }
         std::istringstream is(numbers);
         std::string num;
         std::vector<int> negatives;
         while (is >> num) {
            try {
                  int a = std::stoi(num);
                  if (a < 0) {
                     negatives.push_back(a);
                  } else {
                     result = operation(result, a);
                  }
            } catch(...) {
                  throw std::runtime_error("ERROR: Wrong number format!\n");
            }
         }
         if (negatives.size() > 0) {
            std::string error = "ERROR: negatives not allowed : ";
            for (size_t i = 0; i < negatives.size(); ++i) {
                  error += std::to_string(negatives[i]);
                  error += " ";
            }
            error += "\n";
            throw std::runtime_error(error);
         }
         return result;
      }

    static int add(const std::string& str);
    static int subtract(const std::string& str);
    static int multiplicate(const std::string& str);
};

#endif  // MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_
