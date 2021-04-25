// Copyright 2021 Kurnikova Anastasia

#include <limits>
#include <vector>
#include <algorithm>

#include "include/search-graph-diameter.h"

Graph::Graph() : number(10) {
    vertex.resize(number);
    for (int i = 0; i < number; ++i) {
        vertex[i].resize(number);
        for (int j = 0; j < number; ++j)
            vertex[i][j] = 0;
    }
}

Graph::Graph(matrix && v, int n) noexcept : vertex(move(v)), number(n) {}

Graph::Graph(const Graph& graph) : number(graph.number) {
    vertex.resize(number);
    for (int i = 0; i < number; ++i)
        for (unsigned int j = 0; j < graph.vertex[i].size(); ++j)
            vertex[i].push_back(graph.vertex[i][j]);
}

Graph& Graph::operator=(const Graph& graph) {
    number = graph.number;
    vertex = graph.vertex;
    return *this;
}

void Graph::path() {
    for (int i = 0; i < number; ++i)
        for (int j = 0; j < number; ++j)
            if (i != j && ((vertex[i][j] == 0) || (vertex[i][j] == -1)))
                vertex[i][j] = std::numeric_limits<signed int>::max()/2;
    for (int k = 0; k < number; ++k)
        for (int i = 0; i < number; ++i)
            for (int j = 0; j < number; ++j)
                vertex[i][j] = std::min(vertex[i][j],
                          vertex[i][k] + vertex[k][j]);
}

int Graph::diameter() {
    path();
    int res = -2;
    for (int i = 0; i < number; ++i)
        for (int j = 0; j < number; ++j)
            res = std::max(res, vertex[i][j]);
    return res;
}
