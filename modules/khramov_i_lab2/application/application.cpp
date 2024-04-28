// Copyright 2024 Pozdnyakov Vasya

#include <iostream>

#include "include/radix_sort_app.h"

int main(int argc, char* argv[]) {
    RadixSortApplication app;
    std::cout << app.Sort(argc, argv) << '\n';
    return 0;
}
