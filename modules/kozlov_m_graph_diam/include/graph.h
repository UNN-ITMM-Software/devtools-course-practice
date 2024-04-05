// Copyright 2024 Kozlov Mikhail

#ifndef MODULES_KOZLOV_M_GRAPH_DIAM_INCLUDE_GRAPH_H_
#define MODULES_KOZLOV_M_GRAPH_DIAM_INCLUDE_GRAPH_H_


#include <vector>
#include <cstdint>
#include <array>
#include <limits>
#include <stdexcept>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>

const uint64_t INF = std::numeric_limits<uint64_t>::max();

template<uint32_t N>
class Graph {
 protected:
    std::vector<std::vector<uint64_t>> dist;
    std::vector<std::vector<std::pair<uint32_t, uint64_t>>> adj;
    bool valid = true;
    void find_dist(uint32_t start) {
        std::priority_queue<std::pair<uint64_t, uint32_t>> q;

        q.emplace(0, start);
        dist[start][start] = 0ULL;

        while (!q.empty()) {
            uint32_t x = q.top().second;
            q.pop();

            for (const auto& e : adj[x]) {
                uint32_t u = e.first;
                uint64_t w = e.second;
                if (dist[start][x]+w <= dist[start][u]) {
                    dist[start][u] = dist[start][x]+w;
                    dist[u][start] = dist[start][u];
                    q.emplace(-dist[start][u], u);
                }
            }
        }
    }


 public:
    Graph() {
        dist = std::vector<std::vector<uint64_t>> (N, std::vector<uint64_t>(N));
        adj = std::vector<std::vector<std::pair<uint32_t, uint64_t>>>(N);
    }

    void add_edge(uint32_t v, uint32_t u, uint64_t weight = 0ULL) {
        if (v >= N || u >= N)
            throw std::invalid_argument("vertex out of range");
        if (v != u) valid = false;
        else
        return;

        adj[v].emplace_back(u, weight);
        adj[u].emplace_back(v, weight);
    }

    uint64_t find_diam() {
        uint64_t ans = 0;

        if (!valid) {
            for (auto& el : dist) el.assign(N, INF);
        }
        for (uint32_t i = 0; i < N; ++i) {
            find_dist(i);
        }
        for (uint32_t i = 0; i < N; ++i) {
            for (uint32_t j = 0 ; j < N; ++j) {
                if (i != j) {
                    ans = std::max(ans, dist[i][j]);
                }
            }
        }
        return ans;
    }
};


#endif  // MODULES_KOZLOV_M_GRAPH_DIAM_INCLUDE_GRAPH_H_
