// Copyright 2024 Safarov Nurlan

#include <gtest/gtest.h>

#include "include/interpolation_search.h"

int binarySearch(const std::vector<int>& v, const int& target)
{
    int left = 0;
    int right = v.size() - 1;
    int middle;
    const int NOT_FOUND = -1;

    while (left <= right)
    {
        middle = (left + right) / 2;

        if (v[middle] == target) {
            return middle;
        }
        else if (v[middle] < target) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return NOT_FOUND;
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_1) {
    std::vector<int> v;
    int target = 3;
    const int NOT_FOUND = -1;

    int resultInterpolationSearch = interpolationSearch(v, target);

    ASSERT_EQ(resultInterpolationSearch, NOT_FOUND);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_2) {
    std::vector<int> v{ 1, 3, 5, 7, 9 };
    int target = 3;

    int resultInterpolationSearch = interpolationSearch(v, target);

    ASSERT_EQ(resultInterpolationSearch, 1);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_3) {
    std::vector<int> v{ -2, 0, 3, 5, 7, 9, 11, 15, 18 };
    int target = 5;

    int resultInterpolationSearch = interpolationSearch(v, target);

    ASSERT_EQ(resultInterpolationSearch, 3);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_4) {
    std::vector<int> v{ -25, -17, -1, 0, 3, 10, 12, 16, 19, 21, 31 };
    int target = 1;

    int resultInterpolationSearch = interpolationSearch(v, target);
    int resultBinarySearch = binarySearch(v, target);

    ASSERT_EQ(resultInterpolationSearch, resultBinarySearch);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_5) {
    std::vector<int> v{ 1, 4, 9, 11, 14, 17, 23, 27, 31, 37, 40, 44 };
    int target = 40;

    int resultInterpolationSearch = interpolationSearch(v, target);
    int resultBinarySearch = binarySearch(v, target);

    ASSERT_EQ(resultInterpolationSearch, resultBinarySearch);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_6) {
    std::vector<int> v{ -50, -47, -39, -35, -33, -24, -20, 17, 101, 255, 930 };
    int target = -35;

    int resultInterpolationSearch = interpolationSearch(v, target);
    int resultBinarySearch = binarySearch(v, target);

    ASSERT_EQ(resultInterpolationSearch, resultBinarySearch);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_7) {
    std::vector<int> v{ 1, 3, 5, 7, 10 };
    int target = 10;

    int resultInterpolationSearch = interpolationSearch(v, target);
    int resultBinarySearch = binarySearch(v, target);

    ASSERT_EQ(resultInterpolationSearch, resultBinarySearch);
}
