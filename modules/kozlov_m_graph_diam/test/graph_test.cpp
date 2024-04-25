// Copyright 2024 Kozlov Mikhail

#include <gtest/gtest.h>
#include <limits>
#include "include/graph.h"

class GraphTest : public ::testing::Test {
 protected:
    Graph<50> graph;
};

// Test adding a single edge to the graph
TEST_F(GraphTest, AddSingleEdge) {
    EXPECT_NO_THROW(graph.add_edge(0, 1, 5));
}

// Test adding an edge with out of range vertices
TEST_F(GraphTest, AddEdgeOutOfRangeVertices) {
    ASSERT_THROW(graph.add_edge(5, 106, 8), std::invalid_argument);
}

// Test finding the diameter of a linear graph
TEST_F(GraphTest, FindDiameterLinearGraph) {
    Graph<4> linearGraph;
    linearGraph.add_edge(0, 1, 5);
    linearGraph.add_edge(1, 2, 3);
    linearGraph.add_edge(2, 3, 7);

    uint64_t diam = linearGraph.find_diam();

    ASSERT_EQ(diam, uint64_t(15));  // Diameter should be 15
}

TEST_F(GraphTest, FindDiametermultiple) {
    Graph<4> linearGraph;
    linearGraph.add_edge(0, 1, 5);
    linearGraph.add_edge(1, 2, 3);
    linearGraph.add_edge(2, 3, 7);
    linearGraph.add_edge(2, 3, 7);

    uint64_t diam = linearGraph.find_diam();

    ASSERT_EQ(diam, uint64_t(15));  // Diameter should be 15
}

TEST_F(GraphTest, FindDiameterfull) {
    Graph<3> linearGraph;
    linearGraph.add_edge(0, 1, 5);
    linearGraph.add_edge(1, 2, 3);
    linearGraph.add_edge(2, 0, 7);

    uint64_t diam = linearGraph.find_diam();

    ASSERT_EQ(diam, uint64_t(7));  // Diameter should be 7
}

// Test finding the diameter of a cyclic graph
TEST_F(GraphTest, FindDiameterCyclicGraph) {
    Graph<4> cyclicGraph;
    cyclicGraph.add_edge(0, 1, 4);
    cyclicGraph.add_edge(1, 2, 6);
    cyclicGraph.add_edge(2, 3, 5);
    cyclicGraph.add_edge(3, 0, 3);

    uint64_t diam = cyclicGraph.find_diam();

    ASSERT_EQ(diam, uint64_t(8));  // Diameter should be 11
}

// Test finding the diameter of a disconnected graph
TEST_F(GraphTest, FindDiameterDisconnectedGraph) {
    Graph<5> disconnectedGraph;
    disconnectedGraph.add_edge(0, 1, 5);
    disconnectedGraph.add_edge(2, 3, 8);

    ASSERT_EQ(disconnectedGraph.find_diam(), INF);
}

// Test finding the diameter of an empty graph
TEST_F(GraphTest, FindDiameterEmptyGraph) {
    Graph<3> emptyGraph;
    ASSERT_EQ(emptyGraph.find_diam(), uint64_t(0));
}
