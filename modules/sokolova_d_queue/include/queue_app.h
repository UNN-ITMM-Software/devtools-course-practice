// Copyright 2024 Kochetov Nikolay

#pragma once

#include <string>
#include <vector>

#include "include/queue.h"


class QueueApp {
 private:
    Queue<std::string> queue;
    std::string get_next(size_t& next, int argc, const char** argv);
 public:
    size_t size(std::string& out);
    void display(std::string& out);
    std::string get_back(std::string& out);
    std::string get_front(std::string& out);
    bool isEmpty(std::string& out);
    bool isFull(std::string& out);
    std::string push_back(std::string elem, std::string& out);
    std::string pop_front(std::string& out);
    std::string Start(int argc, const char** argv);
};
