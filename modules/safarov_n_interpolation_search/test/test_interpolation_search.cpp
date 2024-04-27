// Copyright 2024 Safarov Nurlan

#include <gtest/gtest.h>

#include "include/interpolation_search.h"

int binarySearch(const std::vector<int>& v, const int& target) {
    int left = 0;
    int right = v.size() - 1;
    int middle;
    const int NOT_FOUND = -1;

    while (left <= right) {
        middle = (left + right) / 2;

        if (v[middle] == target) {
            return middle;
        } else if (v[middle] < target) {
            left = middle + 1;
        } else {
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

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_8) {
    std::vector<int> v{1, 3, 6, 11, 20, 33, 50, 70, 91, 115, 140, 166, 193,
                       221, 250, 280, 311, 343, 376, 410, 445, 481, 518, 556,
                       595, 635, 676, 718, 761, 805, 850, 896, 943, 991, 1040,
                       1090, 1141, 1193, 1246};
    int target = 595;

    int resultInterpolationSearch = interpolationSearch(v, target);
    int resultBinarySearch = binarySearch(v, target);

    ASSERT_EQ(resultInterpolationSearch, resultBinarySearch);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_9) {
    std::vector<int> v{-50, -46, -45, -44, -41, -37, -34, -31, -30, -27, -24,
                       -22, -21, -17, -16, -14, -10, -9, -7, -4, 1, 3, 6, 7,
                       10, 11, 15, 18, 22, 23, 27, 31, 32, 33, 34, 35, 36, 39,
                       42, 45, 47, 50, 52, 56, 60, 61, 65, 69, 73, 76, 78, 82,
                       85, 86, 88, 91, 92, 93, 94, 95, 96, 99, 102, 104, 108,
                       111, 114, 118, 121, 122, 125, 129, 132, 134};
    int target = 36;

    int resultInterpolationSearch = interpolationSearch(v, target);
    int resultBinarySearch = binarySearch(v, target);

    ASSERT_EQ(resultInterpolationSearch, resultBinarySearch);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_10) {
    std::vector<int> v{-70, -66, -65, -62, -59, -56, -53, -51, -48, -45, -41,
                       -40, -39, -36, -32, -31, -28, -27, -24, -21, -18, -14,
                       -11, -9, -6, -2, 2, 4, 7, 10, 11, 15, 19, 22, 26, 30, 34,
                       38, 41, 44, 47, 51, 54, 55, 58, 59, 63, 66, 69, 73, 76,
                       79, 81, 85, 86, 88, 91, 93, 95, 97, 100, 104, 107, 108,
                       110, 114, 117, 120, 124, 127, 130, 134, 135, 136, 140,
                       141, 142, 146, 147, 149, 150, 154, 158, 160, 162, 164,
                       168, 171, 174, 176, 180, 183, 185, 188, 190, 193, 196};
    int target = 36;

    int resultInterpolationSearch = interpolationSearch(v, target);
    int resultBinarySearch = binarySearch(v, target);

    ASSERT_EQ(resultInterpolationSearch, resultBinarySearch);
}
