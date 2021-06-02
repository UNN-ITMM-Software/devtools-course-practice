// Copyright 2021 Zaitsev Andrey

#include <iostream>
#include <string>

#include "include/mergesort_application.h"

int main(int argc, const char* argv[]) {
    MergeSortApplication app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}
