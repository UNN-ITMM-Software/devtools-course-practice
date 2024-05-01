// Copyright 2024 Троицкий Александр

#include "include/graph_app.h"

#include "graph.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, const char **argv) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <operation> <number_of_vertices> <edge1> <edge2> ..." << std::endl;
        return 1;
    }

    std::string operation = argv[1];

    if (operation != "build") {
        std::cerr << "Unknown operation: " << operation << std::endl;
        return 1;
    }

    uint32_t num_vertices = std::stoi(argv[2]);
    if (argc != (num_vertices * (num_vertices + 3) / 2 + 3)) {
        std::cerr << "Wrong number of arguments." << std::endl;
        return 1;
    }

    Graph<100> graph;

    int idx = 3;
    for (uint32_t i = 0; i < num_vertices; ++i) {
        for (uint32_t j = i + 1; j < num_vertices; ++j) {
            uint64_t weight = std::stoull(argv[idx++]);
            graph.add_edge(i, j, weight);
        }
    }

    uint64_t diameter = graph.find_diam();
    std::cout << "Diameter of the graph: " << diameter << std::endl;

    return 0;
}
