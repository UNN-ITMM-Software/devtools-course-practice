// Copyright 2024 Safronov Mikhail

#ifndef MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_
#define MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_

#include <vector>

struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
 public:
    explicit Graph(int V);
    void addEdge(int src, int dest, int weight);
    std::vector<Edge> kruskalMST();

 private:
    int V;
    std::vector<Edge> edges;
    int find(const std::vector<int>& parent, int i) const;
    void unionSets(const std::vector<int>& parent, const std::vector<int>& rank,
                   int x, int y) const;
};

#endif  // MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_GRAPH_H_
