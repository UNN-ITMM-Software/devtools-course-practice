// Copyright 2024 Shmelev Ivan

#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_set>
#include <utility>

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
  std::vector<std::pair<double, double>> points{{0, 0}, {1, 0}};
  std::vector<std::pair<double, double>> result =
      GrahamScan::convexHull(points);
  EXPECT_TRUE(result.empty());
}

TEST(GrahamScanTest, TestCollinearPoints) {
  std::vector<std::pair<double, double>> points{{0, 0}, {1, 0}, {2, 0}, {3, 0}};
  std::vector<std::pair<double, double>> result =
      GrahamScan::convexHull(points);
  std::vector<std::pair<double, double>> expected = {{0, 0}, {3, 0}};
  EXPECT_EQ(result, expected);
}

TEST(GrahamScan, CollinearPoints) {
  std::vector<std::pair<double, double>> points{{0, 0}, {1, 1}, {2, 2}};
  std::vector<std::pair<double, double>> expected{{0, 0}, {2, 2}};
  EXPECT_EQ(GrahamScan::convexHull(points), expected);
}

TEST(GrahamScanTest, TenPointsTest) {
  std::vector<std::pair<double, double>> points{
      {0.0, 0.0}, {1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}, {4.0, 4.0},
      {5.0, 1.0}, {6.0, 3.0}, {7.0, 2.0}, {8.0, 5.0}, {9.0, 4.0}};

  std::vector<std::pair<double, double>> expected_hull{
      {0.0, 0.0}, {4.0, 4.0}, {8.0, 5.0}, {9.0, 4.0}, {7.0, 2.0}, {5.0, 1.0}};

  std::vector<std::pair<double, double>> result =
      GrahamScan::convexHull(points);

  ASSERT_EQ(expected_hull.size(), result.size());

  for (size_t i = 0; i < expected_hull.size(); ++i) {
    EXPECT_DOUBLE_EQ(expected_hull[i].first, result[i].first);
    EXPECT_DOUBLE_EQ(expected_hull[i].second, result[i].second);
  }
}

TEST(GrahamScanTest, TestPointsOnLine) {
  std::vector<std::pair<double, double>> points{
      {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};
  std::vector<std::pair<double, double>> result =
      GrahamScan::convexHull(points);
  std::vector<std::pair<double, double>> expected = {{0, 0}, {4, 4}};
  EXPECT_EQ(result, expected);
}

TEST(GrahamScanTest, TestConvexPolygon) {
  std::vector<std::pair<double, double>> points{
      {0, 0}, {1, 1}, {2, 0}, {1, -1}};
  std::vector<std::pair<double, double>> result =
      GrahamScan::convexHull(points);
  EXPECT_EQ(result.size(), points.size());
  EXPECT_TRUE(
      std::is_permutation(result.begin(), result.end(), points.begin()));
}

TEST(GrahamScanTest, TestDistinctPoints) {
  std::vector<std::pair<double, double>> points{{0, 0}, {1, 1}, {2, 2}, {3, 3}};
  std::vector<std::pair<double, double>> result =
      GrahamScan::convexHull(points);
  std::vector<std::pair<double, double>> expected = {{0, 0}, {3, 3}};
  EXPECT_EQ(result, expected);
}

TEST(GrahamScanTest, TestComparePoints) {
  Point a = {1, 2};
  Point b = {1, 2};
  Point c = {2, 2};
  EXPECT_TRUE(GrahamScan::comparePoints(a, b));
  EXPECT_FALSE(GrahamScan::comparePoints(a, c));
}

TEST(GrahamScanTest, TestSortPoints) {
  Points points = {{3, 4}, {2, 3}, {1, 2}, {2, 2}, {1, 1}};
  Points expected = {{1, 1}, {1, 2}, {2, 3}, {3, 4}, {2, 2}};
  EXPECT_EQ(GrahamScan::sortPoints(points), expected);
}

TEST(GrahamScanTest, TestConvexPolygon1) {
  Points points = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
  Points expected = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
  EXPECT_EQ(GrahamScan::convexHull(points), expected);
}

TEST(GrahamScanTest, TestNonConvexPolygon2) {
  Points points = {{0, 0}, {1, 0}, {1, 1}, {0, 1}, {0.5, 0.5}};
  Points expected = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
  EXPECT_EQ(GrahamScan::convexHull(points), expected);
}
