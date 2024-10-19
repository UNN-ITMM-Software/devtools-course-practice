// Copyright 2024 Makhinya Danil

#ifndef MODULES_MAKHINYA_D_DIJKSTRA_ALGORITHM_INCLUDE_DIJKSTRA_ALGORITM_H_
#define MODULES_MAKHINYA_D_DIJKSTRA_ALGORITHM_INCLUDE_DIJKSTRA_ALGORITM_H_

#include <array>
#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <stdexcept>
#include <vector>

template <uint32_t N>
class Solver {
 protected:
  struct edge {
    uint32_t next_vertex;
    uint64_t weight;

    explicit edge(uint32_t _next_vertex = 0UL, uint64_t _weight = 0ULL);

    inline bool operator<(const edge& other) const {
      if (this->weight != other.weight) return this->weight < other.weight;

      return this->next_vertex < other.next_vertex;
    }
  };

  std::array<uint64_t, N> distances;
  std::array<std::vector<edge>, N> adjacency_list;

 public:
  const uint64_t NO_WAY_HOME = std::numeric_limits<uint64_t>::max();

  Solver() = default;
  ~Solver() = default;
  /**
   * @brief Added new directed edge in graph
   * @param[in] from_v First vertex
   * @param[in] to_v Second vertex
   * @param[in] weight Weight edge
   */
  void add_directed_edge(uint32_t from_v, uint32_t to_v,
                         uint64_t weight = 0ULL);

  /**
   * @brief Finding the shortest path using Dijkstra's algorithm
   * @param[in] start Start vertex
   * @param[in] end End vertex
   * @return Distance between Start and End. If no have path bettwen Start and
   * End, then return NO_WAY_HOME
   */
  uint64_t find_shortest_path(uint32_t start, uint32_t end);
};

template <uint32_t N>
Solver<N>::edge::edge(uint32_t _next_vertex, uint64_t _weight) {
  next_vertex = _next_vertex;
  weight = _weight;
}

template <uint32_t N>
void Solver<N>::add_directed_edge(uint32_t from_v, uint32_t to_v,
                                  uint64_t weight) {
  if (from_v >= N || to_v >= N)
    throw std::invalid_argument("vertex must be less N!");

  adjacency_list[from_v].push_back(edge(to_v, weight));
}

template <uint32_t N>
uint64_t Solver<N>::find_shortest_path(uint32_t start, uint32_t end) {
  if (start >= N || end >= N)
    throw std::invalid_argument("vertex must be less N!");

  distances.fill(NO_WAY_HOME);

  std::priority_queue<edge> q;

  q.push(edge(start, 0ULL));
  distances[start] = 0ULL;

  while (!q.empty()) {
    edge edge_start_to_x = q.top();
    q.pop();
    auto x = edge_start_to_x.next_vertex;
    auto dist_between_start_and_x = edge_start_to_x.weight;

    for (auto e : adjacency_list[x]) {
      auto y = e.next_vertex;
      auto w = e.weight;
      auto new_dist_between_start_and_y = dist_between_start_and_x + w;
      if (new_dist_between_start_and_y < distances[y]) {
        q.push(edge(y, new_dist_between_start_and_y));
        distances[y] = new_dist_between_start_and_y;
      }
    }
  }

  return distances[end];
}

#endif  // MODULES_MAKHINYA_D_DIJKSTRA_ALGORITHM_INCLUDE_DIJKSTRA_ALGORITM_H_
