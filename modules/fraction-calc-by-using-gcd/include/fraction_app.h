// Copyright 2021 Gruzdeva Diana

#ifndef MODULES_FRACTION_CALC_BY_USING_GCD_INCLUDE_FRACTION_APP_H_
#define MODULES_FRACTION_CALC_BY_USING_GCD_INCLUDE_FRACTION_APP_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char* argv[]);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

class Operation5Args {
 public:
    Operation5Args() {}
    std::string operator()(const char** argv);
 private:
    char parseOperation(std::string arg);
};

#endif  // MODULES_FRACTION_CALC_BY_USING_GCD_INCLUDE_FRACTION_APP_H_
