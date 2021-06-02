// Copyright 2021 Romanuyk Sergey
#include <string>
#include <utility>
#ifndef MODULES_NUMBER_TO_WORD_INCLUDE_APPLICATION_NUM_TO_WORD_H_
#define MODULES_NUMBER_TO_WORD_INCLUDE_APPLICATION_NUM_TO_WORD_H_
#include "include/number_to_word.h"

class NumToWord {
 public:
    NumToWord();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_NUMBER_TO_WORD_INCLUDE_APPLICATION_NUM_TO_WORD_H_
