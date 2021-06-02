// Copyright 2021 Nikolaev Denis

#ifndef MODULES_PERMUTATION_GENERATOR_INCLUDE_PERMUTATION_APP_H_
#define MODULES_PERMUTATION_GENERATOR_INCLUDE_PERMUTATION_APP_H_

#include <string>

class Permutation_App {
 public:
    Permutation_App();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int n;
        int m;
    } Arguments;
};

#endif  // MODULES_PERMUTATION_GENERATOR_INCLUDE_PERMUTATION_APP_H_
