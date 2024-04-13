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
    std::vector<std::pair<double, double>> points = {{0, 0}};
    std::vector<std::pair<double, double>> result =
                                 GrahamScan::convexHull(points);
    EXPECT_TRUE(result.empty());
}

TEST(GrahamScanTest, TestTwoPoints) {
    std::vector<std::pair<double, double>> points = {{0, 0},
                                                    {1, 0}};
    std::vector<std::pair<double, double>> result =
                                 GrahamScan::convexHull(points);
    EXPECT_TRUE(result.empty());
}

TEST(GrahamScanTest, TestCollinearPoints) {
    std::vector<std::pair<double, double>> points = {{0, 0},
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
