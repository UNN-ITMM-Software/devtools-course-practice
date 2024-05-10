// Copyright 2024 Bakhtiarov Alexander

#include <iostream>

#include "include/stackApp.h"

int main(int argc, char *argv[]) {
    auto output = StackApp()(argc, argv);

    std::cout << output << '\n';

    return 0;
}
