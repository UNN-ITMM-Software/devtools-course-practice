// Copyright 2021 Kurnikova Anastasia

#include <gtest/gtest.h>

#include <vector>

#include "include/search-graph-diameter.h"

class DiameterTest : public ::testing::Test {
 public:
    int n = 8;
    matrix v;
    list l;
    void init() {
        v.resize(n);
        int i = 0;
        for (auto it : l) {
            v[i].insert(v[i].end(), it.begin(), it.end());
            i++;
        }
    }
};

TEST_F(DiameterTest, Diameter_Equal) {
    l = { { 0, 1, 0, 0, 0, 1, 0, 0 },
          { 1, 0, 1, 1, 0, 0, 0, 0 },
          { 0, 1, 0, 0, 0, 0, 1, 0 },
          { 0, 1, 0, 0, 1, 0, 0, 0 },
          { 0, 0, 0, 1, 0, 1, 0, 1 },
          { 1, 0, 0, 0, 1, 0, 0, 0 },
          { 0, 0, 1, 0, 0, 0, 0, 1 },
          { 0, 0, 0, 0, 1, 0, 1, 0 } };
    init();
    Graph g(move(v), n);
    int res = g.diameter();
    ASSERT_EQ(3, res);
}

TEST_F(DiameterTest, Diameter_Different) {
    l = { { 0, 3, 0, 0, 0, 6, 0, 0 },
          { 3, 0, 9, 1, 0, 0, 0, 0 },
          { 0, 9, 0, 0, 0, 0, 5, 0 },
          { 0, 1, 0, 0, 4, 0, 0, 0 },
          { 0, 0, 0, 4, 0, 1, 0, 2 },
          { 6, 0, 0, 0, 1, 0, 0, 0 },
          { 0, 0, 5, 0, 0, 0, 0, 7 },
          { 0, 0, 0, 0, 2, 0, 7, 0 } };
    init();
    Graph g(move(v), n);
    int res = g.diameter();
    ASSERT_EQ(16, res);
}

TEST_F(DiameterTest, Copy) {
    l = { { 0, 0, 2, 0, 0, 0, 0, 0 },
          { 0, 0, 4, 0, 0, 0, 0, 0 },
          { 2, 4, 0, 3, 2, 0, 0, 0 },
          { 0, 0, 3, 0, 2, 0, 0, 0 },
          { 0, 0, 0, 2, 0, 0, 0, 0 },
          { 0, 0, 2, 0, 0, 0, 2, 1 },
          { 0, 0, 0, 0, 0, 2, 0, 0 },
          { 0, 0, 0, 0, 0, 1, 0, 0 } };
    init();
    Graph a(move(v), n);
    Graph b(a);
    int res1 = a.diameter();
    int res2 = b.diameter();
    ASSERT_EQ(res1, res2);
}

TEST_F(DiameterTest, Equality) {
    l = { { 0, 0, 2, 0, 0, 0, 0, 0 },
          { 0, 0, 4, 0, 0, 0, 0, 0 },
          { 2, 4, 0, 3, 2, 0, 0, 0 },
          { 0, 0, 3, 0, 2, 0, 0, 0 },
          { 0, 0, 0, 2, 0, 0, 0, 0 },
          { 0, 0, 2, 0, 0, 0, 2, 1 },
          { 0, 0, 0, 0, 0, 2, 0, 0 },
          { 0, 0, 0, 0, 0, 1, 0, 0 } };
    init();
    Graph a(move(v), n);
    Graph b;
    int res1 = a.diameter();
    b = a;
    int res2 = b.diameter();
    ASSERT_EQ(res1, res2);
}
