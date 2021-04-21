// Copyright 2021 Volkova Anastasia

#ifndef MODULES_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_ALGORITHM_H_
#define MODULES_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_ALGORITHM_H_

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

typedef std::pair<int, int> edge;

class Graph{
 private:
    int n;
    std::vector<std::pair<int, edge>> G;
    std::vector<std::pair<int, edge>> MST;
    std::vector<int> parent;
    int find_set(int vertex);
    void union_set(int a, int b);
    std::mt19937 gen;
 public:
    explicit Graph(const int n = 0);
    Graph(const Graph& tmp);
    Graph& operator=(const Graph& tmp);
    ~Graph() = default;
    void addEdge(const int x, const int y, const int w);
    void Kruskal();
    void printMST();
    void set_n(const int vertex_n);
    int get_n() const;
    const std::vector<std::pair<int, edge>>& get_G() const;
    const std::vector<std::pair<int, edge>>& get_MST() const;
    const std::vector<int>& get_parent() const;
};

#endif  // MODULES_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_ALGORITHM_H_
