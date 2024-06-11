// Copyright 2024 Safronov Mikhail

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <limits>

#include "include/graph.h"
#include "include/kruskalapp.h"

std::string KruskalApp::Help(const std::string& app_name,
                             const std::string& message) {
    std::ostringstream stream;
    if (!message.empty()) {
        stream << message << "\n\n";
    }
    stream << "Usage: " << app_name << " <number_of_vertices> <edges>\n";
    stream << "Example: " << app_name << " 4 0 1 10 0 2 6 0 3 5 1 3 15 2 3 4\n";
    return stream.str();
}

bool KruskalApp::Validate(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Not enough arguments." << std::endl;
        return false;
    }

    if ((argc - 2) % 3 != 0) {
        std::cerr << "Must have 3 arguments (src, dest, weight)." << std::endl;
        return false;
    }

    try {
        int vertices = std::stoi(argv[1]);

        if (vertices <= 0) {
            std::cerr << "Num of vertices must be positive." << std::endl;
            return false;
        }

        for (int i = 2; i < argc; i += 3) {
            int64_t srcLong = std::stoll(argv[i]);
            int64_t destLong = std::stoll(argv[i + 1]);
            int64_t weightLong = std::stoll(argv[i + 2]);

            if (srcLong < std::numeric_limits<int>::min() ||
            srcLong > std::numeric_limits<int>::max() ||
                destLong < std::numeric_limits<int>::min() ||
                destLong > std::numeric_limits<int>::max() ||
                weightLong < std::numeric_limits<int>::min() ||
                weightLong > std::numeric_limits<int>::max()) {
                std::cerr << "Argument out of range." << std::endl;
                return false;
            }

            int src = static_cast<int>(srcLong);
            int dest = static_cast<int>(destLong);
            int weight = static_cast<int>(weightLong);

            if (src < 0 || dest < 0 || weight < 0) {
                std::cerr << "Values must be non-negative." << std::endl;
                return false;
            }
        }
    }
    catch (const std::invalid_argument&) {
        std::cerr << "Invalid argument. Expected integers." << std::endl;
        return false;
    }
    return true;
}

std::string KruskalApp::Parse(int argc, char* argv[]) {
    if (!Validate(argc, argv)) {
        return Help(argv[0], "Invalid arguments");
    }

    int V = std::stoi(argv[1]);
    Graph g(V);

    for (int i = 2; i < argc; i += 3) {
        int src = std::stoi(argv[i]);
        int dest = std::stoi(argv[i + 1]);
        int weight = std::stoi(argv[i + 2]);
        g.addEdge(src, dest, weight);
    }

    std::vector<Edge> mst;
    mst = g.kruskalMST();

    std::ostringstream stream;
    stream << "Edges in the minimum spanning tree:\n";
    for (const auto& edge : mst) {
        stream << edge.src << " - " << edge.dest << " : "
            << edge.weight << "\n";
    }
    return stream.str();
}
