// Copyright 2024 Lesnikov Nikita

#pragma once

#include "include/huffman.h"

#include <queue>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cstring>


class HuffmanApp {
 public:
    std::string operator()(int argc, char** argv);
    std::string encode(int argc, char** argv);
    std::string decode(int argc, char** argv);

 private:
    std::unordered_map<std::string, char> _getCodes(int argc,
         char** argv);
    std::string _validate(int argc, char** argv);
    bool _validateNumArgs(int num);
    bool _validateEncoded(const char* str);
    bool _validateCodes(int argc, char** argv);
    std::string _help(const char* appName);
};
