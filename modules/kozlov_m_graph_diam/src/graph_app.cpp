// Copyright 2024 Троицкий Александр

#include "include/graph_app.h"
#include "include/graph.h"
#include <iostream>
#include <sstream>
#include <string>

void Graph_app::help(const char *appname, const char *message) {
    message_ = std::string(message) +
               "This is a graph application. The format is as follows:\n"
               "First argument: B - build graph\n"
               "Second argument: number of vertices\n"
               "Remaining arguments: edge weights for each pair of vertices";
}

bool Graph_app::validateNumberOfArguments(int argc, const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

uint64_t parseUint64(const char *arg) {
    char *end;
    uint64_t value = strtoull(arg, &end, 10);

    if (end[0]) {
        throw std::logic_error("Wrong number format!");
    }

    return value;
}

std::string Graph_app::operator()(int argc, const char **argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    if (argc < 4) {
        return "Insufficient arguments.";
    }

    const char *op = argv[1];
    if (op[0] != 'B') {
        return "Wrong operation.";
    }

    uint32_t num_vertices = 0;
    try {
        num_vertices = parseUint64(argv[2]);
    } catch (std::logic_error &str) {
        return str.what();
    }
    int V = num_vertices * (num_vertices + 3) / 2 + 2;
    if (argc != V) {
        return "Wrong number of arguments.";
    }

    Graph<100> graph;

    int idx = 3;
    for (uint32_t i = 0; i < num_vertices; ++i) {
        for (uint32_t j = i + 1; j < num_vertices; ++j) {
            uint64_t weight = 0;
            try {
                weight = parseUint64(argv[idx++]);
            } catch (std::logic_error &str) {
                return str.what();
            }
            graph.add_edge(i, j, weight);
        }
    }

    uint64_t diameter = graph.find_diam();
    std::ostringstream stream;
    stream << "Diameter of the graph: " << diameter;

    message_ = stream.str();
    return message_;
}

