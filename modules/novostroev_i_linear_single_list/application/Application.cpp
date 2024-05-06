// Copyright 2024 Kutarin Alexandr
#include <iostream>

#include "include/SinglLinkedList.h"

int main(int argc, const char** argv) {
    SinglLinkedList app;
    auto output = app.runApp(argc, argv);
    for (auto str : output) {
        std::cout << str << std::endl;
    }
    return 0;
}
