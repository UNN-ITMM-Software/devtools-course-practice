// Copyright 2021 Prokofeva Elizaveta

#ifndef MODULES_STACK_INCLUDE_STACK_APP_H_
#define MODULES_STACK_INCLUDE_STACK_APP_H_

#include "include/stack.h"

#include <string>

class StackApp {
 public:
    StackApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    Stack stack;
};

#endif  // MODULES_STACK_INCLUDE_STACK_APP_H_
