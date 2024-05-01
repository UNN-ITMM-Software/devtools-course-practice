// Copyright 2024 Ivanchenko Aleksei

#include <iostream>

#include "include/DoubleLinkedListApp.h"

int main(int argc, const char** argv) {
    DoubleLinkedListApp app;
    auto output = app.runApp(argc, argv);
    for (auto str : output) {
        std::cout << str << std::endl;
    }
    return 0;
}
