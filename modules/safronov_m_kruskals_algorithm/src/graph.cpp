// Copyright 2024 Safronov Mikhail
#include "include/graph.h"

#include <algorithm>
#include <set>
#include <stdexcept>

// DisjointSets implementation
DisjointSets::DisjointSets(int n) {
  parent.resize(n);
  rank.resize(n, 0);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
  }
}

int DisjointSets::find(int u) {
  if (u != parent[u]) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

void DisjointSets::unionSets(int u, int v) {
  int uRoot = find(u);
  int vRoot = find(v);

  if (uRoot != vRoot) {
    if (rank[uRoot] < rank[vRoot]) {
      parent[uRoot] = vRoot;
    } else if (rank[uRoot] > rank[vRoot]) {
      parent[vRoot] = uRoot;
    } else {
      parent[vRoot] = uRoot;
      rank[uRoot]++;
    }
  }
}

// Graph implementation
Graph::Graph(int V) : V(V) {}

void Graph::addEdge(int u, int v, int w) { edges.push_back({u, v, w}); }

std::vector<Edge> Graph::kruskalMST() {
  std::vector<Edge> result;

  std::sort(edges.begin(), edges.end());

  DisjointSets ds(V);

  for (const Edge &edge : edges) {
    int u = ds.find(edge.src);
    int v = ds.find(edge.dest);

    if (u != v) {
      result.push_back(edge);
      ds.unionSets(u, v);
    }
  }

  std::set<int> unique_sets;
  for (int i = 0; i < V; ++i) {
    unique_sets.insert(ds.find(i));
  }
  if (unique_sets.size() > 1) {
    throw std::runtime_error("MST computation fail: graph is disconnected");
  }

  return result;
}
