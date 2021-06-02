// Copyright 2021 Pestreev Daniil

#include <gtest/gtest.h>

#include <vector>

#include "include/connectivity_components.h"

TEST(Pestreev_connectivity_components, constructor) {
    const unsigned int SIZE = 10;
    ASSERT_NO_THROW(Graph graph(SIZE));
}

TEST(Pestreev_connectivity_components, no_vertexes) {
    Graph graph(0);
    const unsigned int true_res = 0;
    const unsigned int res = graph.getCountConnComps();

    ASSERT_EQ(true_res, res);
}

TEST(Pestreev_connectivity_components, graph_with_one_vertex) {
    const unsigned int SIZE = 1;

    Graph graph(SIZE);

    for (std::size_t i = 0 ; i < graph.getSize(); i++) {
        for (std::size_t j = i; j < graph.getSize(); j++) {
            graph.setElement(0, i, j);
            graph.setElement(graph.getElement(i, j), j, i);
            if (i == j) {
                graph.setElement(0, i, j);
            }
        }
    }
    const unsigned int true_res = 1;
    unsigned int res = graph.getCountConnComps();

    ASSERT_EQ(true_res, res);
}

TEST(Pestreev_connectivity_components, out_of_scope_index) {
    const unsigned int SIZE = 5;

    Graph graph(SIZE);

    for (std::size_t i = 0 ; i < graph.getSize(); i++) {
        for (std::size_t j = i; j < graph.getSize(); j++) {
            graph.setElement(i, i, j);
            graph.setElement(graph.getElement(i, j), j, i);
            if (i == j) {
                graph.setElement(0, i, j);
            }
        }
    }

    ASSERT_ANY_THROW(graph.getElement(6, 6));
    ASSERT_ANY_THROW(graph.setElement(1, 6, 6));
}

TEST(Pestreev_connectivity_components, out_of_scope_index_2) {
    const unsigned int SIZE = 5;

    Graph graph(SIZE);

    for (std::size_t i = 0 ; i < graph.getSize(); i++) {
        for (std::size_t j = i; j < graph.getSize(); j++) {
            graph.setElement(i, i, j);
            graph.setElement(graph.getElement(i, j), j, i);
            if (i == j) {
                graph.setElement(0, i, j);
            }
        }
    }

    ASSERT_ANY_THROW(graph.getElement(-1, 3));
}


TEST(Pestreev_connectivity_components, complete_simple_graph) {
    const unsigned int SIZE = 10;

    Graph graph(SIZE);

    for (std::size_t i = 0 ; i < graph.getSize(); i++) {
        for (std::size_t j = i; j < graph.getSize(); j++) {
            graph.setElement(1, i, j);
            graph.setElement(graph.getElement(i, j), j, i);
            if (i == j) {
                graph.setElement(0, i, j);
            }
        }
    }

    const unsigned int true_res = 1;
    const unsigned int res = graph.getCountConnComps();

    ASSERT_EQ(true_res, res);
}

TEST(Pestreev_connectivity_components, empty_graph) {
    const unsigned int SIZE = 10;

    Graph graph(SIZE);

    for (std::size_t i = 0 ; i < graph.getSize(); i++) {
        for (std::size_t j = i; j < graph.getSize(); j++) {
            graph.setElement(0, i, j);
            graph.setElement(graph.getElement(i, j), j, i);
            if (i == j) {
                graph.setElement(0, i, j);
            }
        }
    }
    const unsigned int true_res = 10;
    const unsigned int res = graph.getCountConnComps();

    ASSERT_EQ(true_res, res);
}

TEST(Pestreev_connectivity_components, multi_graph) {
    const unsigned int SIZE = 10;

    Graph graph(SIZE);

    for (std::size_t i = 0 ; i < graph.getSize(); i++) {
        for (std::size_t j = i; j < graph.getSize(); j++) {
            graph.setElement(i, i, j);
            graph.setElement(graph.getElement(i, j), j, i);
            if (i == j) {
                graph.setElement(0, i, j);
            }
        }
    }

    const unsigned int true_res = 2;
    const unsigned int res = graph.getCountConnComps();

    ASSERT_EQ(true_res, res);
}

TEST(Pestreev_connectivity_components, some_simple_graph) {
    const unsigned int SIZE = 7;

    Graph graph(SIZE);

    const std::vector<std::vector<unsigned int>> matrix = {
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    for (std::size_t i = 0 ; i < graph.getSize(); i++) {
        for (std::size_t j = 0; j < graph.getSize(); j++) {
            graph.setElement(matrix[i][j], i, j);
        }
    }

    const unsigned int true_res = 3;
    const unsigned int res = graph.getCountConnComps();

    ASSERT_EQ(true_res, res);
}

TEST(Pestreev_connectivity_components, some_multi_graph) {
    unsigned int SIZE = 8;

    Graph graph(SIZE);

    const std::vector<std::vector<unsigned int>> matrix = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 1, 0}
    };

    for (std::size_t i = 0 ; i < graph.getSize(); i++) {
        for (std::size_t j = 0; j < graph.getSize(); j++) {
            graph.setElement(matrix[i][j], i, j);
        }
    }

    const unsigned int true_res = 2;
    const unsigned int res = graph.getCountConnComps();

    ASSERT_EQ(true_res, res);
}

TEST(Tkachev_connectivity_components, append) {
    const unsigned int SIZE = 10;

    Graph graph_1(SIZE);
    const Graph graph_2(SIZE + 1);

    graph_1.append();

    const std::size_t size_graph_1 = graph_1.getSize();
    const std::size_t size_graph_2 = graph_2.getSize();

    ASSERT_EQ(size_graph_1, size_graph_2);
}

