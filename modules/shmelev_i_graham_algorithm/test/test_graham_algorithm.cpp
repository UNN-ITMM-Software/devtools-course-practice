// Copyright 2024 Shmelev Ivan

#include <gtest/gtest.h>
#include <unordered_set>
#include <utility>
#include <algorithm>

#include "include/graham_algorithm.h"

TEST(GrahamScanTest, TestEmptyVector) {
    std::vector<std::pair<double, double>> points;
    std::vector<std::pair<double, double>> result =
                                 GrahamScan::convexHull(points);
    EXPECT_TRUE(result.empty());
}

TEST(GrahamScanTest, TestOnePoint) {
    std::vector<std::pair<double, double>> points{{0, 0}};
    std::vector<std::pair<double, double>> result =
                                 GrahamScan::convexHull(points);
    EXPECT_TRUE(result.empty());
}

TEST(GrahamScanTest, TestTwoPoints) {
    std::vector<std::pair<double, double>> points{{0, 0},
                                                    {1, 0}};
    std::vector<std::pair<double, double>> result =
                                 GrahamScan::convexHull(points);
    EXPECT_TRUE(result.empty());
}

TEST(GrahamScanTest, TestCollinearPoints) {
    std::vector<std::pair<double, double>> points{{0, 0},
                                             {1, 0}, {2, 0}, {3, 0}};
    std::vector<std::pair<double, double>> result =
                                 GrahamScan::convexHull(points);
    std::vector<std::pair<double, double>> expected = {{0, 0},
                                                             {3, 0}};
    EXPECT_EQ(result, expected);
}

TEST(GrahamScan, CollinearPoints) {
    std::vector<std::pair<double, double>> points{{0, 0}, {1, 1}, {2, 2}};
    std::vector<std::pair<double, double>> expected{{0, 0}, {2, 2}};
    EXPECT_EQ(GrahamScan::convexHull(points), expected);
}

TEST(GrahamScanTest, TenPointsTest) {
    std::vector<std::pair<double, double>> points = {
        {0, 0},
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 0},
        {6, 1},
        {7, 2},
        {8, 3},
        {9, 4}
    };

    std::vector<std::pair<double, double>> expected_hull = {
        {0, 0},
        {5, 0},
        {9, 4},
        {4, 4}
    };

    std::vector<std::pair<double, double>> hull = GrahamScan::convexHull(points);

    ASSERT_EQ(hull.size(), expected_hull.size());
    for (size_t i = 0; i < hull.size(); i++) {
        ASSERT_DOUBLE_EQ(hull[i].first, expected_hull[i].first);
        ASSERT_DOUBLE_EQ(hull[i].second, expected_hull[i].second);
    }
}
