// Copyright 2021 Chistov Vladimir

#ifndef MODULES_PSEUDOGRAPHICS_INCLUDE_APPLICATION_H_
#define MODULES_PSEUDOGRAPHICS_INCLUDE_APPLICATION_H_

#include <vector>
#include <string>

#include "include/Pseudographics.h"

class Application {
 public:
    Application();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_PSEUDOGRAPHICS_INCLUDE_APPLICATION_H_
