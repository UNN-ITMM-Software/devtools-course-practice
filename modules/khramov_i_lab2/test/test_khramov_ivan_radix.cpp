// Copyright 2024 Khramov Ivan

#include <gtest/gtest.h>
#include <algorithm>
#include <functional>

#include "include/radix_sort.h"

TEST(Khramov_Ivan_RadixTest, Check_Simple_Sort) {
    // Arrange
    std::vector<int> data {170, 45, 75, 90, 802, 24, 2, 66};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort<int>::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Descending_Sort) {
    // Arrange
    std::vector<int> data {170, 45, 75, 90, 802, 24, 2, 66};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end(), std::greater<int>());
    RadixSort<int>::radixSort(data, false);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Empty_Array_Sort) {
    // Arrange
    std::vector<int> data {};
    // Assert
    EXPECT_ANY_THROW(RadixSort<int>::radixSort(data));
}

TEST(Khramov_Ivan_RadixTest, Check_Zeros_Array_Sort) {
    // Arrange
    std::vector<int> data {0, 0, 0, 0, 0};
    std::vector<int> expected = data;
    // Act
    RadixSort<int>::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Negative_Array_Sort) {
    // Arrange
    std::vector<int> data {-5, -3, -2, -7, -12};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort<int>::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Descending_Negative_Array_Sort) {
    // Arrange
    std::vector<int> data {-5, -3, -2, -7, -12};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end(), std::greater<int>());
    RadixSort<int>::radixSort(data, false);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_One_Element_Array_Sort) {
    // Arrange
    std::vector<int> data {3};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort<int>::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Already_Sorted_Array_Sort) {
    // Arrange
    std::vector<int> data {1, 2, 3};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort<int>::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Descending_Already_Sorted_Array_Sort) {
    // Arrange
    std::vector<int> data {3, 2, 1};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end(), std::greater<int>());
    RadixSort<int>::radixSort(data, false);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Big_Range_Array_Sort) {
    // Arrange
    std::vector<int> data = RadixSort<int>::getRandomVector(1000000);
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort<int>::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Short_Type_Array_Sort) {
    // Arrange
    std::vector<short> data = RadixSort<short>::getRandomVector(10000); //NOLINT
    std::vector<short> expected = data; //NOLINT
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort<short>::radixSort(data); //NOLINT
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Int64_Type_Array_Sort) {
    // Arrange
    std::vector<int64_t> data = RadixSort<int64_t>::getRandomVector(10000);
    std::vector<int64_t> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort<int64_t>::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}

TEST(Khramov_Ivan_RadixTest, Check_Single_Negative_Sort) {
    // Arrange
    std::vector<int> data {100, -40, 5, 2567, 490, 67};
    std::vector<int> expected = data;
    // Act
    std::sort(expected.begin(), expected.end());
    RadixSort<int>::radixSort(data);
    // Assert
    EXPECT_EQ(data, expected);
}
