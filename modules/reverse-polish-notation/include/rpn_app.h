// Copyright 2021 Aleksandrychev Andrey

#ifndef MODULES_REVERSE_POLISH_NOTATION_INCLUDE_RPN_APP_H_
#define MODULES_REVERSE_POLISH_NOTATION_INCLUDE_RPN_APP_H_

#include <string>
#include <utility>
#include "include/rpn.h"

class RPN_App {
 public:
    RPN_App();

    std::string operator()(int argc, const char** argv);


 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_REVERSE_POLISH_NOTATION_INCLUDE_RPN_APP_H_
