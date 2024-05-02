// Copyright 2024 Kulikov Artem
#pragma once
#include <string>
#include <vector>

class LISApp {
 public:
    LISApp() = default;

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::vector<int> seq;
    } Arguments;
};
