// Copyright 2024 Safronov Mikhail

#ifndef MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_
#define MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_

#include <vector>

struct Edge {
    int src;
    int dest;
    int weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {
 public:
    explicit Graph(int V);
    void addEdge(int src, int dest, int weight);
    virtual std::vector<Edge> kruskalMST();

 private:
    int V;
    std::vector<Edge> edges;

    int find(std::vector<int>& parent, int i) const;
    void unionSets(std::vector<int>& parent,
    std::vector<int>& rank, int x, int y) const;
};

#endif  // MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_
