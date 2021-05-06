// Copyright 2021 Pestreev Daniil

#include <gtest/gtest.h>

#include <vector>

#include "include/connectivity_components.h"

TEST(Pestreev_connectivity_components, constructor) {
    ASSERT_NO_THROW(Graph graph(10));
}

TEST(Pestreev_connectivity_components, no_vertexes) {
    Graph graph(0);

    int res = graph.countConectComps();

    ASSERT_EQ(0, res);
}

TEST(Pestreev_connectivity_components, graph_with_one_vertex) {
    int N = 1;
    Graph graph(N);
    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            graph.element(i, j) = 0;
            graph.element(j, i) = graph.element(i, j);
            if (i == j) graph.element(i, j) = 0;
        }
    }

    int res = graph.countConectComps();

    ASSERT_EQ(1, res);
}

TEST(Pestreev_connectivity_components, out_of_scope_index) {
    int N = 5;
    Graph graph(N);

    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            graph.element(i, j) = i;
            graph.element(j, i) = graph.element(i, j);
            if (i == j) graph.element(i, j) = 0;
        }
    }

    ASSERT_ANY_THROW(graph.element(6, 6));
}

TEST(Pestreev_connectivity_components, out_of_scope_index_2) {
    int N = 5;
    Graph graph(N);

    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            graph.element(i, j) = i;
            graph.element(j, i) = graph.element(i, j);
            if (i == j) graph.element(i, j) = 0;
        }
    }

    ASSERT_ANY_THROW(graph.element(-1, 3));
}


TEST(Pestreev_connectivity_components, complete_simple_graph) {
    int N = 10;
    Graph graph(N);
    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            graph.element(i, j) = 1;
            graph.element(j, i) = graph.element(i, j);
            if (i == j) graph.element(i, j) = 0;
        }
    }

    int res = graph.countConectComps();

    ASSERT_EQ(1, res);
}

TEST(Pestreev_connectivity_components, empty_graph) {
    int N = 10;
    Graph graph(N);
    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            graph.element(i, j) = 0;
            graph.element(j, i) = graph.element(i, j);
            if (i == j) graph.element(i, j) = 0;
        }
    }

    int res = graph.countConectComps();

    ASSERT_EQ(10, res);
}

TEST(Pestreev_connectivity_components, multi_graph) {
    int N = 10;
    Graph graph(N);
    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            graph.element(i, j) = i;
            graph.element(j, i) = graph.element(i, j);
            if (i == j) graph.element(i, j) = 0;
        }
    }

    int res = graph.countConectComps();

    ASSERT_EQ(2, res);
}

TEST(Pestreev_connectivity_components, some_simple_graph) {
    int N = 7;
    Graph graph(N);
    std::vector<std::vector<int>> matrix = {
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph.element(i, j) = matrix[i][j];
        }
    }

    int res = graph.countConectComps();

    ASSERT_EQ(3, res);
}

TEST(Pestreev_connectivity_components, some_multi_graph) {
    int N = 8;
    Graph graph(N);
    std::vector<std::vector<int>> matrix = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 1, 0}
    };
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph.element(i, j) = matrix[i][j];
        }
    }

    int res = graph.countConectComps();

    ASSERT_EQ(2, res);
}
