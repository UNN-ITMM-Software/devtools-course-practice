// Copyright 2021 Volkova Anastasia

#ifndef MODULES_STATISTIC_VALUES_INCLUDE_APPLICATION_H_
#define MODULES_STATISTIC_VALUES_INCLUDE_APPLICATION_H_

#include <string>
#include <vector>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char* argv[]);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::vector<double> x;
        std::vector<double> p;
        int n;
        int k;
        char operation;
    } Arguments;
};

#endif  // MODULES_STATISTIC_VALUES_INCLUDE_APPLICATION_H_
