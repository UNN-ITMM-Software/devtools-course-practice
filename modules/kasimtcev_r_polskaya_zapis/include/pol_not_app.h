// Copyright 2024 Sokolova Daria

#pragma once
#include "pol_not.h"
#include <string>

class PolNotApp {
 public:
    PolNotApp() = default;

    std::string operator()(int argc, char* argv[]);

 private:
    std::string helpMessage{};
    std::string input{};

    bool validate(int argc, char* argv[]);

    void help(const char* appName, const char* errorMessage = nullptr);
};
