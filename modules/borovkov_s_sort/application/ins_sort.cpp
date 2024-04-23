// Copyright 2024 Soloninko Andrey

#include <iostream>

#include "include/ins_sort_app.h"

int main(int argc, char* argv[]) {
    auto output = SortApp()(argc, argv);

    std::cout << output << '\n';
    return 0;
}