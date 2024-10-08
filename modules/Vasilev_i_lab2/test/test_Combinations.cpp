// Copyright 2024 Vasilev Ivan
// Copyright 2024 Tushentsova Karina

#include "gtest/gtest.h"
#include <vector>
#include "include/Combinations.h"

TEST(CombinationGeneratorTest, BasicTest) {
    std::vector<int> arr = {1, 2, 3, 4};
    int k = 2;
    std::vector<std::vector<int>> expected = {{1, 2}, {1, 3},
                                              {1, 4}, {2, 3},
                                              {2, 4}, {3, 4}};
    auto result = generateCombinations(arr, k);
    ASSERT_EQ(result, expected);
}

TEST(CombinationGeneratorTest, EmptyArray) {
    std::vector<int> arr;
    int k = 2;
    std::vector<std::vector<int>> expected = {};
    auto result = generateCombinations(arr, k);
    ASSERT_EQ(result, expected);
}

TEST(CombinationGeneratorTest, KGreaterThanN) {
    std::vector<int> arr = {1, 2, 3, 4};
    int k = 5;
    std::vector<std::vector<int>> expected = {};
    auto result = generateCombinations(arr, k);
    ASSERT_EQ(result, expected);
}

TEST(CombinationGeneratorTest, KEqualsN) {
    std::vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    std::vector<std::vector<int>> expected = {{1, 2, 3, 4}};
    auto result = generateCombinations(arr, k);
    ASSERT_EQ(result, expected);
}

TEST(CombinationGeneratorTest, SingleElementArray) {
    std::vector<int> arr = {5};
    int k = 1;
    std::vector<std::vector<int>> expected = {{5}};
    auto result = generateCombinations(arr, k);
    ASSERT_EQ(result, expected);
}

TEST(CombinationGeneratorTest, LargerArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 3;
    std::vector<std::vector<int>> expected = {{1, 2, 3}, {1, 2, 4},
                                              {1, 2, 5}, {1, 2, 6},
                                              {1, 3, 4}, {1, 3, 5},
                                              {1, 3, 6}, {1, 4, 5},
                                              {1, 4, 6}, {1, 5, 6},
                                              {2, 3, 4}, {2, 3, 5},
                                              {2, 3, 6}, {2, 4, 5},
                                              {2, 4, 6}, {2, 5, 6},
                                              {3, 4, 5}, {3, 4, 6},
                                              {3, 5, 6}, {4, 5, 6}};
    auto result = generateCombinations(arr, k);
    ASSERT_EQ(result, expected);
}
