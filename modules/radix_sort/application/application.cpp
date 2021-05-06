// Copyright 2021 Kolesin Andrey
#include "include/application.h"

#include <iostream>

int main(int argc, const char** argv) {
    Application app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}
