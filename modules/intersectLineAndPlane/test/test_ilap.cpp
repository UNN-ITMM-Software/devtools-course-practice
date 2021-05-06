// Copyright 2021 Loganov Andrei
#include <gtest/gtest.h>
#include <cmath>
#include <limits>
#include "include/ilap.h"

TEST(Loganov_Tests, TEST1) {
    Point p;
    p.x = 10;
    p.y = 10;
    ASSERT_EQ(p.x, p.y);
}
TEST(Loganov_Tests, TEST2) {
    Point p;
    p.y = 1.25;
    p.z = 1.25;
    ASSERT_EQ(p.y, p.z);
}
TEST(Loganov_Tests, TEST3) {
    Point p;
    p.z = -1.25;
    ASSERT_EQ(-1.25, p.z);
}
TEST(Loganov_Tests, TEST4) {
    Point D, E, F, G, H, I;
    D.x = 0;
    D.y = 0;
    D.z = 0;
    E.x = 1;
    E.y = 0;
    E.z = 0;
    F.x = 0;
    F.y = 1;
    F.z = 0;
    G.x = 1;
    G.y = 1;
    G.z = 1;
    H.x = 0;
    H.y = 0;
    H.z = 5;
    I.PlaneIntersectLine(D, E, F, G, H);
    ASSERT_EQ(1.25, I.x);
    ASSERT_EQ(1.25, I.y);
    ASSERT_EQ(0, I.z);
}
TEST(Loganov_Tests, TEST5) {
    Point D, E, F, G, H, I;
    D.x = 0;
    D.y = 0;
    D.z = 1;
    E.x = 1;
    E.y = 0;
    E.z = 1;
    F.x = 0;
    F.y = 0;
    F.z = 0;
    G.x = 1;
    G.y = 1;
    G.z = 1;
    H.x = 0;
    H.y = 0;
    H.z = 5;
    I.PlaneIntersectLine(D, E, F, G, H);
    ASSERT_EQ(0, I.x);
    ASSERT_EQ(0, I.y);
    ASSERT_EQ(5, I.z);
}
TEST(Loganov_Tests, TEST6) {
    Point D, E, F, G, H, I;
    D.x = 0;
    D.y = 0;
    D.z = 1;
    E.x = 1;
    E.y = 0;
    E.z = 1;
    F.x = 0;
    F.y = 0;
    F.z = 0;
    G.x = 0;
    G.y = 1.27;
    G.z = 0;
    H.x = 0;
    H.y = 1.27;
    H.z = 3;
    I.PlaneIntersectLine(D, E, F, G, H);
    ASSERT_EQ(I.x, std::numeric_limits<double>::max());
    ASSERT_EQ(I.y, std::numeric_limits<double>::max());
    ASSERT_EQ(I.z, std::numeric_limits<double>::max());
}

