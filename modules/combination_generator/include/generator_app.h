// Copyright 2021 Makarov Alexandr

#ifndef MODULES_COMBINATION_GENERATOR_INCLUDE_GENERATOR_APP_H_
#define MODULES_COMBINATION_GENERATOR_INCLUDE_GENERATOR_APP_H_

#include <string>

class Application {
 public:
    Application();

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

#endif  // MODULES_COMBINATION_GENERATOR_INCLUDE_GENERATOR_APP_H_
