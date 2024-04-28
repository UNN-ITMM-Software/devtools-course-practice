// Copyright 2024 Videneva Ekaterina

#include <iostream>

#include "include/konovalov_i_euler_f_app.h"

int main(int argc, char* argv[]) {
    auto output = EulerFunctionApplication()(argc, argv);

    std::cout << output << '\n';
    return 0;
}
