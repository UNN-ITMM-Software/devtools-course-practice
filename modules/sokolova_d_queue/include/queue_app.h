// Copyright 2024 Kochetov Nikolay

#pragma once

#include <string>
#include <vector>

#include "include/queue.h"

std::string output = "";

class QueueApp {
private:
    Queue<std::string> queue;
    size_t size(std::string& out = output);
    void display(std::string& out = output);
    std::string get_back(std::string& out = output);
    std::string get_front(std::string& out = output);
    bool isEmpty(std::string& out = output);
    bool isFull(std::string& out = output);
    std::string push_back(std::string elem, std::string& out = output);
    std::string pop_front(std::string& out = output);
public:
    std::string get_next(int& next, int argc, const char** argv);
    std::string Start(int argc, const char** argv);
};

