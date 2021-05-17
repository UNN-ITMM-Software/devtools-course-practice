// Copyright 2021 Volkova Anastasia

#include <iostream>
#include <string>

#include "include/application.h"

int main(int argc, const char** argv) {
    Application app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}
