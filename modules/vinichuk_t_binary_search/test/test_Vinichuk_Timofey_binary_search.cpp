// Copyright 2024 Vinichuk Timofey

#include <gtest/gtest.h>
#include <numeric>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "include/BinarySearch.h"


TEST(BinarySearchTest, test_find_middle) {
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7};
    ASSERT_EQ(binsearch::binary_search(v, 4), 3);
}

TEST(BinarySearchTest, test_not_found) {
    std::vector<int> v { 1, 2, 3, 4, 5, 6, 7 };
    ASSERT_EQ(binsearch::binary_search(v, 8), binsearch::NOT_LISTED);
}

TEST(BinarySearchTest, test_empty_array) {
    std::vector<int> v1;
    std::vector<double> v2;

    ASSERT_EQ(binsearch::binary_search(v1, 8), binsearch::NOT_LISTED);
    ASSERT_EQ(binsearch::binary_search(v2, 5.89), binsearch::NOT_LISTED);
}

TEST(BinarySearchTest, test_one_element_found) {
    std::vector<int> v1 { 1 };
    std::vector<double> v2 { 2.005 };

    ASSERT_EQ(binsearch::binary_search(v1, 1), 0);
    ASSERT_EQ(binsearch::binary_search(v2, 2.005), 0);
}

TEST(BinarySearchTest, test_one_element_not_found) {
    std::vector<int> v { 1 };

    ASSERT_EQ(binsearch::binary_search(v, 2), binsearch::NOT_LISTED);
    ASSERT_EQ(binsearch::binary_search(v, 10), binsearch::NOT_LISTED);
}

TEST(BinarySearchTest, test_large_array) {
    std::vector<int> v(1000);
    std::iota(v.begin(), v.end(), 0);

    ASSERT_EQ(binsearch::binary_search(v, 355), 355);
    ASSERT_EQ(binsearch::binary_search(v, 10), 10);
    ASSERT_EQ(binsearch::binary_search(v, 784), 784);
}

TEST(BinarySearchTest, test_element_left_and_right) {
    std::vector<int> v1{ 1, 4, 6, 59, 100, 344, 345 };
    ASSERT_EQ(binsearch::binary_search(v1, 4), 1);
    ASSERT_EQ(binsearch::binary_search(v1, 344), 5);
}

TEST(BinarySearchTest, test_first_element) {
    std::vector<int> v1 { 1, 4, 6, 59, 345 };
    std::vector<char> v2 { 'a', 'd', 'u', 'z'};

    ASSERT_EQ(binsearch::binary_search(v1, 1), 0);
    ASSERT_EQ(binsearch::binary_search(v2, 'a'), 0);
}

TEST(BinarySearchTest, test_last_element) {
    std::vector<int> v1 { 1, 4, 6, 59, 345 };
    std::vector<char> v2 { 'a', 'd', 'u', 'y', 'z'};

    ASSERT_EQ(binsearch::binary_search(v1, 345), 4);
    ASSERT_EQ(binsearch::binary_search(v2, 'z'), 4);
}

int compare(const void* x1, const void* x2) {
    return (*(reinterpret_cast<int*>(const_cast<void*>(x1)))
        - *(reinterpret_cast<int*>(const_cast<void*>(x2))));
}

TEST(BinarySearchTest, test_random_vector) {
    int size = 10;
    int minVal = 1;
    int maxVal = 100;
    int targetIndex = 5;

    std::vector<int> vec(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(minVal, maxVal);

    for (int i = 0; i < size; ++i) {
        vec[i] = distribution(gen);
    }
    int targ = vec[targetIndex];

    std::sort(vec.begin(), vec.end());

    int* arr = vec.data();

    int* result = reinterpret_cast<int*>(std::bsearch(&targ, arr, vec.size(),
                                         sizeof(int), compare));

    EXPECT_EQ(result - arr, binsearch::binary_search(vec, targ));
}
