// Copyright 2024 Makhinya Danil

#include <gtest/gtest.h>
#include <limits>
#include "include/dijkstra_algoritm.h"

TEST(Makhinya_Danil_DijkstraTest, CanCreateEdge1) {
    Solver<2> sol;
    sol.add_directed_edge(0, 1, 5ULL);
    EXPECT_EQ(sol.find_shortest_path(0, 1), 5ULL);
}

TEST(Makhinya_Danil_DijkstraTest, CanCreateEdge2) {
    Solver<2> sol;
    sol.add_directed_edge(0, 1, 5ULL);
    EXPECT_EQ(sol.find_shortest_path(1, 0), sol.NO_WAY_HOME);
}

TEST(Makhinya_Danil_DijkstraTest, AddEdgeInvalidFirstArgument) {
    const uint32_t N = 5;
    Solver<N> sol;
    EXPECT_ANY_THROW(sol.add_directed_edge(N, 0, 5ULL));
}

TEST(Makhinya_Danil_DijkstraTest, AddEdgeInvalidSecondArgument) {
    const uint32_t N = 5;
    Solver<N> sol;
    EXPECT_ANY_THROW(sol.add_directed_edge(0, N, 5ULL));
}

TEST(Makhinya_Danil_DijkstraTest, FindPathgeInvalidFirstArgument) {
    const uint32_t N = 5;
    Solver<N> sol;
    sol.add_directed_edge(0, 1, 5ULL);
    EXPECT_ANY_THROW(sol.find_shortest_path(N, 0));
}

TEST(Makhinya_Danil_DijkstraTest, FindPathgeInvalidSecondArgument) {
    const uint32_t N = 5;
    Solver<N> sol;
    sol.add_directed_edge(0, 1, 5ULL);
    EXPECT_ANY_THROW(sol.find_shortest_path(0, N));
}

TEST(Makhinya_Danil_DijkstraTest, CorrectDist) {
    const uint32_t N = 5;
    Solver<N> sol;
    sol.add_directed_edge(0, 2, 2ULL);
    sol.add_directed_edge(2, 1, 4ULL);
    sol.add_directed_edge(1, 0, 3ULL);
    EXPECT_EQ(sol.find_shortest_path(0, 1), 6Ull);
}
