// Copyright 2021 Volkova Anastasia

#include <algorithm>
#include <ctime>
#include <numeric>
#include <random>
#include <utility>
#include <vector>

#include "include/Kruskal_algorithm.h"

Graph::Graph(const int size) : n(size) {
    parent.resize(n, 0);
    std::iota(parent.begin(), parent.end(), 0);
}

Graph::Graph(const Graph& tmp) : n(tmp.n),
                                 G(tmp.G),
                                 MST(tmp.MST),
                                 parent(tmp.parent) {}

Graph& Graph::operator=(const Graph& tmp) {
    if (this == &tmp) return *this;
    n = tmp.get_n();
    G = tmp.get_G();
    MST = tmp.get_MST();
    parent = tmp.get_parent();
    return *this;
}

void Graph::addEdge(const int x, const int y, const int w) {
    G.emplace_back(make_pair(w, edge(x, y)));
}

int Graph::find_set(int vertex) {
    if (vertex == parent[vertex]) return vertex;
    parent[vertex] = find_set(parent[vertex]);
    return parent[vertex];
}

void Graph::union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    gen.seed(time(0));
    if (gen() & 1) std::swap(a, b);
    if (a != b) parent[a] = parent[b];
}

void Graph::set_n(const int vertex_n) {
    if (vertex_n >= 0) n = vertex_n;
}

int Graph::get_n() const {
    return n;
}

const std::vector<int>& Graph::get_parent() const {
    return parent;
}

const std::vector<std::pair<int, edge>>& Graph::get_MST() const {
    return MST;
}

const std::vector<std::pair<int, edge>>& Graph::get_G() const {
    return G;
}

void Graph::Kruskal() {
    sort(G.begin(), G.end());
    for (auto i : G) {
        int a = find_set(i.second.first);
        int b = find_set(i.second.second);
        if (a != b) {
            MST.emplace_back(i);
            union_set(a, b);
        }
    }
}

void Graph::printMST() {
    int size = MST.size();
    for (int i = 0; i < size; i++) {
        std::cout << "( " << MST[i].second.first <<
        " - " << MST[i].second.second <<
        " ) : " << MST[i].first << '\n';
    }
}
