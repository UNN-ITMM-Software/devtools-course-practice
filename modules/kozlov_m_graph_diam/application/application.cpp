// Copyright 2024 Тroitskiy Alexander

#include <iostream>

#include "include/graph_app.h"

int main(int argc, const char **argv) {
    Graph_app graphApp;
    std::string result = graphApp(argc, argv);
    std::cout << result << std::endl;
    return 0;
}
