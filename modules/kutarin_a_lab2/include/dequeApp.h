// Copyright 2024 Filatov Maxim

#pragma once

#include <string>
#include <vector>
#include "include/deque.h"

class DequeApp {
    Deque<std::string> deque;
    std::vector<std::string> parse(int argc, const char** argv);
    void help(std::vector<std::string>& output);
    void reverse(std::vector<std::string>& output);
    void print(std::vector<std::string>& output);
    void push_back(std::vector<std::string>& output, std::string elem);
    void push_front(std::vector<std::string>& output, std::string elem);
 public:
    DequeApp() {
        deque.push_back("never");
        deque.push_back("gonna");
        deque.push_back("give");
        deque.push_back("you");
        deque.push_back("up");
    }
    std::vector<std::string> runApp(int argc, const char** argv);
};
