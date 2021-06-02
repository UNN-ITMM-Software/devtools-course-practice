// Copyright 2021 Tsvetkov Maxim

#include <string>

#ifndef MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_APP_H_
#define MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_APP_H_
class StringCalculatorApp {
 public:
    std::string operator()(int argc, const char** argv);

 private:
    std::string help(const std::string& filename);
};
#endif  // MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_APP_H_
