// Copyright 2024 Kutarin Alexandr
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "include/linked_list.h"

class SinglLinkedList {
    LinkedList<std::string> list;
    std::vector<std::string> parse(int argc, const char** argv);
    void help(std::vector<std::string>& output);
    void print(std::vector<std::string>& output);
    void push_back(std::vector<std::string>& output, std::string elem);
    void push_front(std::vector<std::string>& output, std::string elem);
    void test_operator(std::vector<std::string>& output);
 public:
    SinglLinkedList() {}
    std::vector<std::string> runApp(int argc, const char** argv);
};
