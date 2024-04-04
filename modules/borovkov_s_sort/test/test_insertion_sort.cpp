// Copyright 2024 Borovkov Sergey
#include <gtest/gtest.h>

#include "include/insertion_sort.h"

TEST(Borovkov_Sergey_InsertionSortTest, SortTest_1) {
  std::vector<int> test1 = {5, 2, 4, 6, 1, 3};
  InsertionSort::sort(test1);
  std::vector<int> expected1 = {1, 2, 3, 4, 5, 6};
  ASSERT_EQ(test1, expected1);
}

TEST(Borovkov_Sergey_InsertionSortTest, SortTest_2) {
  std::vector<int> test2 = {3, 1, 4, 1, 5, 9, 2, 6};
  InsertionSort::sort(test2);
  std::vector<int> expected2 = {1, 1, 2, 3, 4, 5, 6, 9};
  ASSERT_EQ(test2, expected2);
}

TEST(Borovkov_Sergey_InsertionSortTest, SortTest_3) {
  std::vector<int> test3 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  InsertionSort::sort(test3);
  std::vector<int> expected3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_EQ(test3, expected3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
