// Copyright 2024 Safarov Nurlan

#include <gtest/gtest.h>

#include "include/interpolation_search.h"

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_1) {
    std::vector<int> v;
    int target = 3;

    int result = interpolationSearch(v, target);

    ASSERT_EQ(result, -1);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_2) {
    std::vector<int> v = {-2, 0, 3, 5, 7, 9, 11, 15, 18};
    int target = 5;

    int result = interpolationSearch(v, target);

    ASSERT_EQ(result, 3);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_3) {
    std::vector<int> v = {-25, -17, -1, 0, 3, 10, 12, 16, 19, 21, 31};
    int target = 1;

    int result = interpolationSearch(v, target);

    ASSERT_EQ(result, -1);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_4) {
    std::vector<int> v = {1, 4, 9, 11, 14, 17, 23, 27, 31, 37, 40, 44};
    int target = 40;

    int result = interpolationSearch(v, target);

    ASSERT_EQ(result, 10);
}

TEST(Safarov_Nurlan_InterpolationSearchTest, Test_5) {
    std::vector<int> v = {-50, -47, -39, -35, -33, -24, -20, 17, 101, 255, 930};
    int target = -35;

    int result = interpolationSearch(v, target);

    ASSERT_EQ(result, 3);
}
