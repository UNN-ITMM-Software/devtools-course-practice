// Copyright 2024 Kutarin Alexandr
#pragma once

#include "linked_list.h"

#include <string>
#include <vector>

class SingleLinkedList {
    SingleLinkedList<std::string> list;
    std::vector<std::string> parse(int argc, const char** argv);
    void help(std::vector<std::string>& output);
    void print(std::vector<std::string>& output);
    void push_back(std::vector<std::string>& output, std::string elem);
    void push_front(std::vector<std::string>& output, std::string elem);
 public:
    SingleLinkedList() {
        list.push_back("never");
        list.push_back("gonna");
        list.push_back("give");
        list.push_back("you");
        list.push_back("up");
    }
    std::vector<std::string> runApp(int argc, const char** argv);
};
