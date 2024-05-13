// Copyright 2024 Sobol Lyubov

#include <iostream>

#include "include/stack_app.h"

int main(int argc, char *argv[]) {
    auto output = StackApp()(argc, argv);

    std::cout << output << '\n';

    return 0;
}
