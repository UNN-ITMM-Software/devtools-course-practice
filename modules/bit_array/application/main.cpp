// Copyright 2021 Gushchin Artem

#include <iostream>
#include <string>

#include "include/bit_array_application.h"

int main(int argc, const char* argv[]) {
    BitArrayApplication app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}
