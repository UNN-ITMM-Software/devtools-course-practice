// Copyright 2024 Ivanov Nikita
#pragma once
#include <string>

class LCSApp {
 public:
    LCSApp();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::string str1;
        std::string str2;
        double z2_real;
        double z2_imaginary;
        char operation;
    } Arguments;
};
