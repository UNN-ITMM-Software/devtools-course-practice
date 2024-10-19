// Copyright 2024 Shemiakina Alesia

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

#include "include/graph_components.h"

TEST(Shemiakina_Alesia_GraphNumbersTest, returns_1_when_given_2_super) {
  std::vector<std::vector<int>> v{{1}, {0}};
  int count = graph_components_numbers(2, v);
  EXPECT_EQ(1, count);
}

TEST(Shemiakina_Alesia_GraphNumbersTest, returns_2_when_given_5) {
  std::vector<std::vector<int>> v{{1}, {0, 2}, {1}, {4}, {3}};
  int count = graph_components_numbers(5, v);

  EXPECT_EQ(count, 2);
}

TEST(Shemiakina_Alesia_GraphNumbersTest, returns_1_when_given_1) {
  std::vector<std::vector<int>> v{{}};
  int count = graph_components_numbers(1, v);

  EXPECT_EQ(count, 1);
}

TEST(Shemiakina_Alesia_GraphNumbersTest, returns_3_when_given_8) {
  std::vector<std::vector<int>> v{{1, 7}, {0, 6}, {3},    {2, 4},
                                  {3},    {},     {1, 7}, {0, 6}};
  int count = graph_components_numbers(8, v);

  EXPECT_EQ(count, 3);
}

TEST(Shemiakina_Alesia_GraphNumbersTest, returns_1_when_given_10) {
  std::vector<std::vector<int>> v{{1},    {0, 2}, {3, 1}, {4, 2}, {5, 3},
                                  {6, 4}, {7, 5}, {8, 6}, {9, 7}, {8}};
  int count = graph_components_numbers(10, v);

  EXPECT_EQ(count, 1);
}

TEST(Shemiakina_Alesia_GraphNumbersTest, returns_0_when_given_0) {
  std::vector<std::vector<int>> v{};
  int count = graph_components_numbers(0, v);

  EXPECT_EQ(count, 0);
}

TEST(Shemiakina_Alesia_GraphNumbersTest, one_sided_list) {
  std::vector<std::vector<int>> v{{1}, {2}, {0}};
  int count = graph_components_numbers(3, v);

  EXPECT_EQ(count, 1);
}
