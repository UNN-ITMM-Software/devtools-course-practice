// Copyright 2024 Morgachev Stepan

#include <iostream>

#include "include/levenshtein_distance_app.h"

int main(int argc, char *argv[]) {
    auto output = LevenshteinApp()(argc, argv);

    std::cout << output << '\n';

    return 0;
}
