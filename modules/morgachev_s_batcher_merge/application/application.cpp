// Copyright 2024 Chuvashov Andrey

#include <iostream>

#include "../include/batcher_merge_app.h"

int main(int argc, char* argv[]) {
    BatcherMergeApplication app;
    std::cout << app.Sort(argc, argv) << '\n';
    return 0;
}
