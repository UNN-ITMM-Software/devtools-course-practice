// Copyright 2024 Safronov Mikhail

#ifndef MODULES_GRAPH_H_
#define MODULES_GRAPH_H_

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
    int find(std::vector<int>& parent, int i);
    void unionSets(std::vector<int>& parent, std::vector<int>& rank, int x, int y);
};

#endif  // MODULES_GRAPH_H_
