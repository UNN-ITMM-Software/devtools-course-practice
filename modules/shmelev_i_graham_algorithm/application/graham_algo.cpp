// Copyright 2024 Kulaev Zhenya

#include <iostream>

#include "include/graham_algorithm_app.h"

int main(int argc, char* argv[]) {
    auto output = GrahamScanApplication()(argc, argv);

    std::cout << output << '\n';
    return 0;
}
