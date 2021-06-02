// Copyright 2021 Makarov Alexander

#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/binary_search.h"

TEST(Binary_Search_Test, IntSearch) {
    std::vector<int> array = {
        -3, -2, -1, 0, 1, 2, 3
    };
    int result = BinarySearch::Search<int>(0, array, 0, array.size() - 1);
    ASSERT_EQ(3, result);
}

TEST(Binary_Search_Test, DoubleSearch) {
    std::vector<double> array = {
        -3.7, -2.8, -1.9, 0.35, 1.5, 2.89, 3.14
    };
    int result = BinarySearch::Search<double>(3.14, array, 0,
                                              array.size() - 1);
    ASSERT_EQ(6, result);
}

TEST(Binary_Search_Test, StringSearch) {
    std::vector<std::string> array = {
        "a", "b", "c", "d", "e", "f", "g"
    };
    int result = BinarySearch::Search<std::string>("a", array, 0,
                                                   array.size() - 1);
    ASSERT_EQ(0, result);
}

TEST(Binary_Search_Test, MissingValueSearch) {
    std::vector<int> array = {
        -3, -2, -1, 0, 1, 2, 3
    };
    int result = BinarySearch::Search<int>(10, array, 0, array.size() - 1);
    ASSERT_EQ(-1, result);
}

TEST(Binary_Search_Test, UnsortedSearch) {
    std::vector<int> array = {
        8, 2, 3, 17, -1, 27, -31
    };
    int result = BinarySearch::Search<int>(-1, array, 0, array.size() - 1);
    ASSERT_EQ(-1, result);
}

TEST(Binary_Search_Test, SearchInPartOfArray) {
    std::vector<int> array = {
        -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5
    };
    int result = BinarySearch::Search<int>(3, array, 2, 8);
    ASSERT_EQ(8, result);
}

TEST(Binary_Search_Test, IncorrectRightNegative) {
    std::vector<int> array = {
        -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5
    };
    ASSERT_THROW(BinarySearch::Search<int>(3, array, 2, -3),
                 std::runtime_error);
}

TEST(Binary_Search_Test, IncorrectRightOutOfRange) {
    std::vector<int> array = {
            -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5
    };
    ASSERT_THROW(BinarySearch::Search<int>(3, array, 2, 27),
                 std::runtime_error);
}

TEST(Binary_Search_Test, IncorrectLeftNegative) {
    std::vector<int> array = {
        -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5
    };
    ASSERT_THROW(BinarySearch::Search<int>(3, array, -7, 8),
                 std::runtime_error);
}

TEST(Binary_Search_Test, IncorrectLeftOutOfRange) {
    std::vector<int> array = {
            -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5
    };
    ASSERT_THROW(BinarySearch::Search<int>(3, array, 27, 8),
                 std::runtime_error);
}

TEST(Binary_Search_Test, LeftGreaterThanRight) {
    std::vector<int> array = {
        -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5
    };
    ASSERT_THROW(BinarySearch::Search<int>(3, array, 8, 3),
                 std::runtime_error);
}
