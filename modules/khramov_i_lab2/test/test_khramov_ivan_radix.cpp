// Copyright 2024 Khramov Ivan

#include <gtest/gtest.h>
#include <algorithm>

#include "include/radix_sort.h"

TEST(Khramov_Ivan_RadixTest, Check_Simple_Sort) {
    // Arrange
    std::vector<int> data {170, 45, 75, 90, 802, 24, 2, 66};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Descending_Sort) {
    // Arrange
    std::vector<int> data {170, 45, 75, 90, 802, 24, 2, 66};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end(),
     [](int a, int b) { return a > b; });
    RadixSort::radixSort(data, false);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Empty_Array_Sort) {
    // Arrange
    std::vector<int> data {};
    // Assert
    EXPECT_ANY_THROW(RadixSort::radixSort(data));
}

TEST(Khramov_Ivan_RadixTest, Check_Zeros_Array_Sort) {
    // Arrange
    std::vector<int> data {0, 0, 0, 0, 0};
    std::vector<int> expected = data;
    // Act
    RadixSort::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Negative_Array_Sort) {
    // Arrange
    std::vector<int> data {-5, -3, -2, -7, -12};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Descending_Negative_Array_Sort) {
    // Arrange
    std::vector<int> data {-5, -3, -2, -7, -12};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end(),
     [](int a, int b) { return a > b; });
    RadixSort::radixSort(data, false);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_One_Element_Array_Sort) {
    // Arrange
    std::vector<int> data {3};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Already_Sorted_Array_Sort) {
    // Arrange
    std::vector<int> data {1, 2, 3};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Descending_Already_Sorted_Array_Sort) {
    // Arrange
    std::vector<int> data {3, 2, 1};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end(),
     [](int a, int b) { return a > b; });
    RadixSort::radixSort(data, false);
    // Assert
    EXPECT_EQ(data, expected);
}
