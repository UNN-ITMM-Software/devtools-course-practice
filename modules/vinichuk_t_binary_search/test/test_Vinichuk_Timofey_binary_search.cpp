// Copyright 2024 Vinichuk Timofey

#include <gtest/gtest.h>
#include <numeric>
#include "include/BinarySearch.h"


TEST(BinarySearchTest, test_find_middle) {
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7};
    ASSERT_EQ(binary_search(v, 4), 3);
}

TEST(BinarySearchTest, test_not_found) {
    std::vector<int> v { 1, 2, 3, 4, 5, 6, 7 };
    ASSERT_EQ(binary_search(v, 8), -1);
}

TEST(BinarySearchTest, test_empty_array) {
    std::vector<int> v1;
    std::vector<double> v2;

    ASSERT_EQ(binary_search(v1, 8), -1);
    ASSERT_EQ(binary_search(v2, 5.89), -1);
}

TEST(BinarySearchTest, test_one_element_found) {
    std::vector<int> v1 { 1 };
    std::vector<double> v2 { 2.005 };

    ASSERT_EQ(binary_search(v1, 1), 0);
    ASSERT_EQ(binary_search(v2, 2.005), 0);
}

TEST(BinarySearchTest, test_one_element_not_found) {
    std::vector<int> v { 1 };

    ASSERT_EQ(binary_search(v, 2), -1);
    ASSERT_EQ(binary_search(v, 10), -1);
}

TEST(BinarySearchTest, test_large_array) {
    std::vector<int> v(1000);
    std::iota(v.begin(), v.end(), 0);

    ASSERT_EQ(binary_search(v, 355), 355);
    ASSERT_EQ(binary_search(v, 10), 10);
    ASSERT_EQ(binary_search(v, 784), 784);
}

TEST(BinarySearchTest, test_first_element) {
    std::vector<int> v1 { 1, 4, 6, 59, 345 };
    std::vector<char> v2 { 'a', 'd', 'u', 'z'};

    ASSERT_EQ(binary_search(v1, 1), 0);
    ASSERT_EQ(binary_search(v2, 'a'), 0);
}

TEST(BinarySearchTest, test_last_element) {
    std::vector<int> v1 { 1, 4, 6, 59, 345 };
    std::vector<char> v2 { 'a', 'd', 'u', 'y', 'z'};

    ASSERT_EQ(binary_search(v1, 345), 4);
    ASSERT_EQ(binary_search(v2, 'z'), 4);
}
