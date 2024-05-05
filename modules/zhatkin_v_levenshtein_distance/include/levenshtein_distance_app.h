// Copyright 2024 Morgachev Stepan

#pragma once

#include <string>

#include "include/levenshtein_distance.h"

class LevenshteinApp {
 public:
    LevenshteinApp() = default;

    std::string operator()(int argc, char *argv[]);

 private:
    std::string helpMessage{};
    std::string firstString{};
    std::string secondString{};

    bool validate(int argc, char *argv[]);

    void help(const char *appName, const char *errorMessage = nullptr);
};
