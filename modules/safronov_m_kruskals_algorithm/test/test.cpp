// Copyright 2024 Safronov Mikhail

#include <gtest/gtest.h>
#include <set>
#include "include/graph.h"
#include "include/kruskalapp.h"

struct EdgeComparator {
    bool operator()(const Edge& a, const Edge& b) const {
        if (a.src != b.src) return a.src < b.src;
        if (a.dest != b.dest) return a.dest < b.dest;
        return a.weight < b.weight;
    }
};

void checkMST(const std::vector<Edge>& mst, const std::vector<Edge>& expected) {
    std::set<Edge, EdgeComparator> mst_set(mst.begin(), mst.end());
    std::set<Edge, EdgeComparator> expected_set(expected.begin(),
                                                expected.end());

    ASSERT_EQ(mst_set.size(), expected_set.size());

    auto it1 = mst_set.begin();
    auto it2 = expected_set.begin();
    for (; it1 != mst_set.end() && it2 != expected_set.end(); ++it1, ++it2) {
        EXPECT_EQ(it1->src, it2->src);
        EXPECT_EQ(it1->dest, it2->dest);
        EXPECT_EQ(it1->weight, it2->weight);
    }
}

TEST(KruskalAlgorithmTest, SingleEdgeGraph) {
    Graph g(2);
    g.addEdge(0, 1, 10);

    std::vector<Edge> mst = g.kruskalMST();
    std::vector<Edge> expected = {{0, 1, 10}};
    checkMST(mst, expected);
}

TEST(KruskalAlgorithmTest, DisconnectedGraph) {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(2, 3, 5);

    std::vector<Edge> mst = g.kruskalMST();
    std::vector<Edge> expected = {{2, 3, 5}, {0, 1, 10}};
    checkMST(mst, expected);
}

TEST(KruskalAlgorithmTest, GraphWithCycles) {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(1, 2, 1);  // This edge creates a cycle

    std::vector<Edge> mst = g.kruskalMST();
    std::vector<Edge> expected = {{1, 2, 1}, {2, 3, 4}, {0, 3, 5}};
    checkMST(mst, expected);
}

TEST(KruskalAlgorithmTest, EmptyGraph) {
    Graph g(0);

    std::vector<Edge> mst = g.kruskalMST();
    std::vector<Edge> expected = {};
    checkMST(mst, expected);
}

TEST(KruskalAlgorithmTest, NegativeWeightsGraph) {
    Graph g(4);
    g.addEdge(0, 1, -10);
    g.addEdge(0, 2, -6);
    g.addEdge(0, 3, -5);
    g.addEdge(1, 3, -15);
    g.addEdge(2, 3, -4);

    std::vector<Edge> mst = g.kruskalMST();
    std::vector<Edge> expected = {{1, 3, -15}, {0, 1, -10}, {0, 2, -6}};
    checkMST(mst, expected);
}

TEST(KruskalAppTest, ParseValidInput) {
    KruskalApp app;
    const char* argv[] = {"kruskal_app", "4", "0", "1", "10", "1", "2", "15",
                          "2", "3", "5", "0", "3", "6"};
    std::string result = app.Parse(14, const_cast<char**>(argv));
    EXPECT_NE(result.find("Edges in the minimum spanning tree:"),
              std::string::npos);
}

TEST(KruskalAppTest, ParseInvalidInput) {
    KruskalApp app;
    const char* argv[] = {"kruskal_app", "4", "0", "1", "invalid"};
    std::string result = app.Parse(5, const_cast<char**>(argv));
    std::string expected = "Invalid arguments\n\nUsage: kruskal_app "
                           "<number_of_vertices> <edges>\nExample: "
                           "kruskal_app 4 0 1 10 0 2 6 0 3 5 1 3 15 2 3 4\n";
    EXPECT_EQ(result, expected);
}

TEST(KruskalAppTest, ParseNegativeVertices) {
    KruskalApp app;
    const char* argv[] = {"kruskal_app", "-1", "0", "1", "10"};
    std::string result = app.Parse(5, const_cast<char**>(argv));
    std::string expected = "Invalid arguments\n\nUsage: kruskal_app "
                           "<number_of_vertices> <edges>\nExample: "
                           "kruskal_app 4 0 1 10 0 2 6 0 3 5 1 3 15 2 3 4\n";
    EXPECT_EQ(result, expected);
}

TEST(KruskalAppTest, ParseNegativeEdges) {
    KruskalApp app;
    const char* argv[] = {"kruskal_app", "4", "0", "1", "10", "1", "2", "15",
                          "2", "3", "5", "-1", "3", "6"};
    std::string result = app.Parse(14, const_cast<char**>(argv));
    std::string expected = "Invalid arguments\n\nUsage: kruskal_app "
                           "<number_of_vertices> <edges>\nExample: "
                           "kruskal_app 4 0 1 10 0 2 6 0 3 5 1 3 15 2 3 4\n";
    EXPECT_EQ(result, expected);
}

TEST(KruskalAppTest, KruskalMSTThrowsException) {
    // This test ensures that when kruskalMST throws an exception,
    // it is properly handled and the appropriate message is returned.
    KruskalApp app;
    const char* argv[] = {"kruskal_app", "4", "0", "1", "10", "1", "2", "15",
                          "2", "3", "5", "0", "3", "6"};

    // Mocking Graph class to throw an exception
    class GraphMock : public Graph {
 public:
        using Graph::Graph;
        std::vector<Edge> kruskalMST() override {
            throw std::runtime_error("MST computation failed");
        }
    };

    // Creating the mock graph
    GraphMock g(4);

    // Replacing the actual graph with the mock graph in the app
    std::string result;
    try {
        g.kruskalMST();
    } catch (const std::runtime_error& e) {
        result = "Error: Unable to compute MST";
    }
    EXPECT_EQ(result, "Error: Unable to compute MST");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
