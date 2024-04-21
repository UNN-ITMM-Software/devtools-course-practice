// Copyright 2024 Borisov Saveliy
#pragma once

#include <string>

#include "include/BinarySearch.h"

class BinarySearchApplication {
 public:
    BinarySearchApplication() = default;
    std::string operator()(int argc, char* argv[]);

 private:
    bool validate(int argc, char* argv[]);
    void help(const char* appName, const char* msg = nullptr);
    template<typename T>
    std::vector<T> parseInput(std::string input);
    std::string mMessage{};
};
