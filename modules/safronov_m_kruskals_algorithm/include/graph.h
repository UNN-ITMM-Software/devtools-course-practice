// Copyright 2024 Safronov Mikhail

#ifndef MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_
#define MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_

#include <vector>

struct Edge {
    int src, dest, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSets {
 public:
    explicit DisjointSets(int n);
    int find(int u);
    void unionSets(int u, int v);

 private:
    std::vector<int> parent, rank;
};

class Graph {
 public:
    explicit Graph(int V);
    void addEdge(int u, int v, int w);
    std::vector<Edge> kruskalMST();

 private:
    int V;
    std::vector<Edge> edges;
};

#endif  // MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_
