// Copyright 2024 Shemiakina Alesia

#include <iostream>

#include "include/graph_components_app.h"

int main(int argc, char* argv[]) {
    auto output = GraphComponentsApplication()(argc, argv);

    std::cout << output << '\n';
    return 0;
}
