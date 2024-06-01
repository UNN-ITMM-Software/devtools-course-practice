// Copyright 2024 Safronov Mikhail

#include "include/graph.h"

#include <algorithm>

Graph::Graph(int V) : V(V) {}

void Graph::addEdge(int src, int dest, int weight) {
    edges.push_back(Edge(src, dest, weight));
}

int Graph::find(const std::vector<int>& parent, int i) const {
    if (parent[i] != i) return find(parent, parent[i]);
    return parent[i];
}

void Graph::unionSets(const std::vector<int>& parent,
                      const std::vector<int>& rank, int x, int y) const {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) {
        const_cast<std::vector<int>&>(parent)[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        const_cast<std::vector<int>&>(parent)[yroot] = xroot;
    } else {
        const_cast<std::vector<int>&>(parent)[yroot] = xroot;
        const_cast<std::vector<int>&>(rank)[xroot]++;
    }
}

std::vector<Edge> Graph::kruskalMST() {
    std::vector<Edge> result;
    int e = 0;
    std::vector<int> parent(V);
    std::vector<int> rank(V, 0);

    for (int v = 0; v < V; ++v) parent[v] = v;

    std::sort(edges.begin(), edges.end());

    std::vector<Edge>::size_type i = 0;

    while (e < V - 1 && i < edges.size()) {
        Edge next_edge = edges[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            unionSets(parent, rank, x, y);
            e++;
        }
    }

    return result;
}
