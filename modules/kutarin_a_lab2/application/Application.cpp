// Copyright 2024 Filatov Maxim

#include <iostream>

#include "include/dequeApp.h"

int main(int argc, const char** argv) {
    DequeApp app;
    auto output = app.runApp(argc, argv);
    for (auto str : output) {
        std::cout << str << std::endl;
    }
    return 0;
}