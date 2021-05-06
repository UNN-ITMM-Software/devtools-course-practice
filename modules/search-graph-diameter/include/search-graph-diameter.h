// Copyright 2021 Kurnikova Anastasia

#ifndef MODULES_SEARCH_GRAPH_DIAMETER_INCLUDE_SEARCH_GRAPH_DIAMETER_H_
#define MODULES_SEARCH_GRAPH_DIAMETER_INCLUDE_SEARCH_GRAPH_DIAMETER_H_

#include <vector>

using matrix = std::vector<std::vector<int>>;
using list = std::initializer_list<std::initializer_list<int>>;

class Graph {
 private:
    matrix vertex;
    int number;
 public:
    Graph();
    Graph(matrix && v, int n) noexcept;
    Graph(const Graph& graph);
    Graph& operator=(const Graph& graph);
    void path();
    int diameter();
};
#endif  // MODULES_SEARCH_GRAPH_DIAMETER_INCLUDE_SEARCH_GRAPH_DIAMETER_H_
