// Copyright 2024 Safronov Mikhail

#include <sstream>
#include <iostream>

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
        return false;
    }
    if ((argc - 2) % 3 != 0) {
        return false;
    }
    for (int i = 1; i < argc; ++i) {
        try {
            std::stoi(argv[i]);
        } catch (...) {
            return false;
        }
    }
    return true;
}

std::string KruskalApp::Parse(int argc, char *argv[]) {
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

    std::vector<Edge> mst = g.kruskalMST();

    std::ostringstream stream;
    stream << "Edges in the minimum spanning tree:\n";
    for (const auto& edge : mst) {
        stream << edge.src << " - " << edge.dest
        << " : " << edge.weight << "\n";
    }
    return stream.str();
}
