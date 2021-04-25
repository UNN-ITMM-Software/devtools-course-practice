// Copyright 2021 Zoreev Mikhail

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "include/radix_sort.h"

TEST(RadixSort_Test, Test_Sort_Signed) {
    size_t size = 16;
    auto vector_radix =  RadixSort::getRandomVector<int32_t>(size);
    auto vector_std = vector_radix;

    RadixSort::radixSort<int32_t>(vector_radix.begin(), vector_radix.end());
    std::sort(vector_std.begin(), vector_std.end());

    ASSERT_EQ(vector_std, vector_radix);
}

TEST(RadixSort_Test, Test_Sort_Signed_Long) {
    size_t size = 16;
    auto vector_radix =  RadixSort::getRandomVector<int64_t>(size);
    auto vector_std = vector_radix;

    RadixSort::radixSort<int64_t>(vector_radix.begin(), vector_radix.end());
    std::sort(vector_std.begin(), vector_std.end());

    ASSERT_EQ(vector_std, vector_radix);
}

TEST(RadixSort_Test, Test_Sort_Unsigned) {
    size_t size = 12;
    auto vector_radix =  RadixSort::getRandomVector<uint32_t>(size);
    auto vector_std = vector_radix;

    RadixSort::radixSort<uint32_t>(vector_radix.begin(), vector_radix.end());
    std::sort(vector_std.begin(), vector_std.end());

    ASSERT_EQ(vector_std, vector_radix);
}

TEST(RadixSort_Test, Test_Sort_Sorted) {
    size_t size = 13;
    auto vector_radix = RadixSort::getRandomVector<int32_t>(size);
    std::sort(vector_radix.begin(), vector_radix.end());
    auto vector_std = vector_radix;

    RadixSort::radixSort<int32_t>(vector_radix.begin(), vector_radix.end());
    std::sort(vector_std.begin(), vector_std.end());

    ASSERT_EQ(vector_std, vector_radix);
}

TEST(RadixSort_Test, Test_Sort_Reverse_Sorted) {
    size_t size = 11;
    auto vector_radix = RadixSort::getRandomVector<int32_t>(size);
    std::sort(vector_radix.begin(), vector_radix.end(),
              [](const int32_t &a, const int32_t &b){ return a > b; });
    auto vector_std = vector_radix;

    RadixSort::radixSort<int32_t>(vector_radix.begin(), vector_radix.end());
    std::sort(vector_std.begin(), vector_std.end());

    ASSERT_EQ(vector_std, vector_radix);
}

TEST(RadixSort_Test, Test_Can_Get_Random_Empty_Vector) {
    ASSERT_NO_THROW(RadixSort::getRandomVector<int32_t>(0));
}

TEST(RadixSort_Test, Test_Can_Get_Random_Vector) {
    size_t size = 15;

    ASSERT_NO_THROW(RadixSort::getRandomVector<int32_t>(size));
}
