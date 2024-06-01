// Copyright 2024 Safronov Mikhail

#ifndef MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_
#define MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_

#include <vector>

struct Edge {
    int src;
    int dest;
    int weight;
};

class Graph {
 public:
    explicit Graph(int V);
    void addEdge(int src, int dest, int weight);
    std::vector<Edge> kruskalMST();

 private:
    int V;
    std::vector<Edge> edges;
};

#endif  // MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_
