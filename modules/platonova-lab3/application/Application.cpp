// Copyright 2024 Platonova Maria

#include <iostream>

#include "include/bisymmetricApp.h"

int main(int argc, const char** argv) {
    BysimmetricApp app;
    auto output = app.runApp(argc, argv);
    for (auto str : output) {
        std::cout << str << std::endl;
    }
    return 0;
}