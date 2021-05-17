// Copyright 2021 Vodeneev Mikhail

#ifndef MODULES_MODIFIED_STACK_MINIMUMS_INCLUDE_MODIFY_STACK_APP_H_
#define MODULES_MODIFIED_STACK_MINIMUMS_INCLUDE_MODIFY_STACK_APP_H_

#include <string>
#include "include/modified_stack_minimums.h"

class StackApp {
 public:
StackApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    ModifiedStack stack;
};

#endif  // MODULES_MODIFIED_STACK_MINIMUMS_INCLUDE_MODIFY_STACK_APP_H_
