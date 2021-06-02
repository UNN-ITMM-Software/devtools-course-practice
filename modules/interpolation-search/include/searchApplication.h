// Copyright 2021 Pestreev Daniil

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_SEARCHAPPLICATION_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_SEARCHAPPLICATION_H_

#include <string>
#include <vector>

class searchApplication {
 public:
    searchApplication();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname);
    std::string message_;
    bool validateNumberOfArguments(int argc, const char** argv);
};

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_SEARCHAPPLICATION_H_
