// Copyright 2021 Volkova Nastya

#include <gtest/gtest.h>
#include <tuple>
#include <utility>
#include <vector>

#include "include/Kruskal_algorithm.h"

TEST(Volkova_Kruskal_Algorithm, Constructor) {
    Graph g;

    ASSERT_EQ(0, g.get_n());
    ASSERT_EQ(0, static_cast<int>(g.get_parent().size()));
    ASSERT_EQ(0, static_cast<int>(g.get_G().size()));
    ASSERT_EQ(0, static_cast<int>(g.get_MST().size()));
}

TEST(Volkova_Kruskal_Algorithm, TheNumberOfVertices) {
    Graph g(10);

    ASSERT_EQ(10, g.get_n());
}

TEST(Volkova_Kruskal_Algorithm, SetNumberOfVertices) {
    Graph g(10);
    g.set_n(4);

    ASSERT_EQ(4, g.get_n());
}

TEST(Volkova_Kruskal_Algorithm, CopyConstructor) {
    Graph g(5);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 4);
    g.Kruskal();

    Graph g_copy(g);

    ASSERT_EQ(g.get_n(), g_copy.get_n());
    ASSERT_EQ(g.get_G(), g_copy.get_G());
    ASSERT_EQ(g.get_MST(), g_copy.get_MST());
    ASSERT_EQ(g.get_parent(), g_copy.get_parent());
}

TEST(Volkova_Kruskal_Algorithm, AssignmentOperator) {
    Graph g(5);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 4);
    g.Kruskal();

    Graph g_copy = g;

    ASSERT_EQ(g.get_n(), g_copy.get_n());
    ASSERT_EQ(g.get_G(), g_copy.get_G());
    ASSERT_EQ(g.get_MST(), g_copy.get_MST());
    ASSERT_EQ(g.get_parent(), g_copy.get_parent());
}

TEST(Volkova_Kruskal_Algorithm, AssignmentOperator2) {
    Graph g(5);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 4);
    g.Kruskal();

    Graph g_copy(5);
    g_copy.addEdge(0, 1, 3);
    g_copy = g;

    ASSERT_EQ(g.get_n(), g_copy.get_n());
    ASSERT_EQ(g.get_G(), g_copy.get_G());
    ASSERT_EQ(g.get_MST(), g_copy.get_MST());
    ASSERT_EQ(g.get_parent(), g_copy.get_parent());
}

TEST(Volkova_Kruskal_Algorithm, SelfAppropriation) {
    Graph g(5);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 4);

    g = g;

    ASSERT_EQ(5, g.get_n());
}

TEST(Volkova_Kruskal_Algorithm, MultipleAssignment) {
    Graph g1(4);
    g1.addEdge(0, 1, 2);
    g1.addEdge(0, 3, 1);
    g1.addEdge(1, 3, 2);
    g1.addEdge(2, 3, 3);

    Graph g2 = g1;
    Graph g3 = g2;
    Graph g4 = g3;

    ASSERT_EQ(g1.get_n(), g4.get_n());
    ASSERT_EQ(g1.get_G(), g4.get_G());
    ASSERT_EQ(g1.get_MST(), g4.get_MST());
    ASSERT_EQ(g1.get_parent(), g4.get_parent());
}

TEST(Volkova_Kruskal_Algorithm, AddEdgeToGraph) {
    Graph g(2);
    g.addEdge(0, 1, 10);
    std::vector<std::pair<int, edge>> gr = g.get_G();
    int x = gr[0].second.first;
    int y = gr[0].second.second;
    int w = gr[0].first;

    ASSERT_EQ(0, x);
    ASSERT_EQ(1, y);
    ASSERT_EQ(10, w);
}

TEST(Volkova_Kruskal_Algorithm, Parent) {
    Graph g(10);
    std::vector<int> p = g.get_parent();

    for (int i = 0; i < 10; ++i) {
        ASSERT_EQ(i, p[i]);
    }
}

TEST(Volkova_Kruskal_Algorithm, ParentSize) {
    Graph g(6);
    std::vector<int> p = g.get_parent();

    ASSERT_EQ(6, static_cast<int>(p.size()));
}

TEST(Volkova_Kruskal_Algorithm, TheNumberOfEdges) {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 3);
    std::vector<std::pair<int, edge>> gr = g.get_G();

    ASSERT_EQ(4, static_cast<int>(gr.size()));
}

TEST(Volkova_Kruskal_Algorithm, KruskalAlgorithmN5) {
    Graph g(5);
    g.addEdge(0, 3, 5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(2, 1, 6);
    g.addEdge(2, 3, 1);
    g.addEdge(4, 1, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 3, 2);
    g.Kruskal();
    std::vector<std::pair<int, edge>> mst = g.get_MST();

    ASSERT_EQ(0, mst[0].second.first);
    ASSERT_EQ(1, mst[0].second.second);
    ASSERT_EQ(1, mst[0].first);

    ASSERT_EQ(2, mst[1].second.first);
    ASSERT_EQ(3, mst[1].second.second);
    ASSERT_EQ(1, mst[1].first);

    ASSERT_EQ(4, mst[2].second.first);
    ASSERT_EQ(2, mst[2].second.second);
    ASSERT_EQ(2, mst[2].first);

    ASSERT_EQ(0, mst[3].second.first);
    ASSERT_EQ(2, mst[3].second.second);
    ASSERT_EQ(3, mst[3].first);
}

TEST(Volkova_Kruskal_Algorithm, KruskalAlgorithmN4) {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 3);
    g.Kruskal();
    std::vector<std::pair<int, edge>> mst = g.get_MST();

    ASSERT_EQ(0, mst[0].second.first);
    ASSERT_EQ(3, mst[0].second.second);
    ASSERT_EQ(1, mst[0].first);

    ASSERT_EQ(0, mst[1].second.first);
    ASSERT_EQ(1, mst[1].second.second);
    ASSERT_EQ(2, mst[1].first);

    ASSERT_EQ(2, mst[2].second.first);
    ASSERT_EQ(3, mst[2].second.second);
    ASSERT_EQ(3, mst[2].first);
}

TEST(Volkova_Kruskal_Algorithm, TheMinimumSpanningTreeVerification) {
    Graph g(4);
    g.addEdge(0, 3, 1);
    g.addEdge(0, 1, 2);
    g.addEdge(2, 3, 3);
    g.Kruskal();
    std::vector<std::pair<int, edge>> gr = g.get_G();
    std::vector<std::pair<int, edge>> mst = g.get_MST();

    ASSERT_EQ(gr, mst);
}

TEST(Volkova_Kruskal_Algorithm, MSTForTwoIdenticalTrees) {
    Graph g1(4);
    g1.addEdge(0, 1, 14);
    g1.addEdge(0, 3, 12);
    g1.addEdge(1, 3, 14);
    g1.addEdge(2, 3, 16);
    g1.Kruskal();
    std::vector<std::pair<int, edge>> mst1 = g1.get_MST();

    Graph g2(4);
    g2.addEdge(2, 3, 16);
    g2.addEdge(0, 3, 12);
    g2.addEdge(0, 1, 14);
    g2.addEdge(1, 3, 14);
    g2.Kruskal();
    std::vector<std::pair<int, edge>> mst2 = g2.get_MST();

    ASSERT_EQ(mst1, mst2);
}
