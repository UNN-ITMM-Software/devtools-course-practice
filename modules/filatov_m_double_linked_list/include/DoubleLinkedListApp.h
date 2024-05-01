// Copyright 2024 Ivanchenko Aleksei

#pragma once

#include "DoubleLinkedList.h"
#include <string>
#include <vector>

#define UNRECOGNIZED_OPTIONS_ERROR "Error: unrecognized command-line option. Run --help for all supported options"

class DoubleLinkedListApp {
    DoubleLinkedList<std::string> list;
    std::vector<std::string> parse(int argc, const char** argv);    
    std::vector<std::string> parseString(const std::string& input);    
public:
    std::string runApp(int argc, const char** argv);
};
