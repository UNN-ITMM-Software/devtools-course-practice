// Copyright 2024 Borovkov Sergey
#include <gtest/gtest.h>

#include <algorithm>
#include <random>

#include "include/insertion_sort.h"
TEST(Borovkov_Sergey_InsertionSortTest, SortTest_1) {
  std::vector<int> test1{5, 2, 4, 6, 1, 3};
  InsertionSort::sort(test1);
  std::vector<int> expected1{1, 2, 3, 4, 5, 6};
  ASSERT_EQ(test1, expected1);
}

TEST(Borovkov_Sergey_InsertionSortTest, SortTest_2) {
  std::vector<int> test2{3, 1, 4, 1, 5, 9, 2, 6};
  InsertionSort::sort(test2);
  std::vector<int> expected2{1, 1, 2, 3, 4, 5, 6, 9};
  ASSERT_EQ(test2, expected2);
}

TEST(Borovkov_Sergey_InsertionSortTest, SortTest_3) {
  std::vector<int> test3{9, 8, 7, 6, 5, 4, 3, 2, 1};
  InsertionSort::sort(test3);
  std::vector<int> expected3{1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_EQ(test3, expected3);
}

TEST(Borovkov_Sergey_InsertionSortTest, SortIntVector) {
  std::vector<int> vec{4, 2, 7, 1, 5};
  std::vector<int> insertionSortedVec = vec;
  InsertionSort::sort(insertionSortedVec);
  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(insertionSortedVec, vec);
}

TEST(Borovkov_Sergey_InsertionSortTest, SortDoubleVector) {
  std::vector<double> vec{3.14, 2.71, 1.618, 0.1};
  std::vector<double> insertionSortedVec = vec;
  InsertionSort::sort(insertionSortedVec);
  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(insertionSortedVec, vec);
}

TEST(Borovkov_Sergey_InsertionSortTest, SortSizeTVector) {
  std::vector<size_t> vec{10, 5, 20, 1, 15};
  std::vector<size_t> insertionSortedVec = vec;
  InsertionSort::sort(insertionSortedVec);
  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(insertionSortedVec, vec);
}

TEST(Borovkov_Sergey_InsertionSortTest, SortRandomIntVector) {
  std::vector<int> vec(1000);
  std::generate(vec.begin(), vec.end(), []() { return rand() % 1000; });
  std::vector<int> insertionSortedVec = vec;
  InsertionSort::sort(insertionSortedVec);
  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(insertionSortedVec, vec);
}

TEST(Borovkov_Sergey_InsertionSortTest, SortUniformDoubleVector) {
  std::vector<double> vec(1000);
  std::uniform_real_distribution<double> distribution(0.0, 1000.0);
  std::mt19937 engine;
  std::generate(vec.begin(), vec.end(), [&]() { return distribution(engine); });
  std::vector<double> insertionSortedVec = vec;
  InsertionSort::sort(insertionSortedVec);
  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(insertionSortedVec, vec);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
