// Copyright 2024 Pozdnyakov Vasya

#include <gtest/gtest.h>
#include <vector>
#include "include/tower_of_hanoi.h"

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_negative) {
    int rings = -10;

    ASSERT_ANY_THROW(TowerOfHanoi::CalculateSteps(rings));
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_zero) {
    int rings = 0;

    ASSERT_ANY_THROW(TowerOfHanoi::CalculateSteps(rings));
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_positive) {
    int rings = 10;

    ASSERT_NO_THROW(TowerOfHanoi::CalculateSteps(rings));
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_1) {
    int rings = 1;
    std::vector<std::vector<int>> answer = {{1, 3}};
    std::vector<std::vector<int>> result;

    result = TowerOfHanoi::CalculateSteps(rings);

    ASSERT_EQ(answer, result);
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_2) {
    int rings = 2;
    std::vector<std::vector<int>> answer = {{1, 2}, {1, 3}, {2, 3}};
    std::vector<std::vector<int>> result;

    result = TowerOfHanoi::CalculateSteps(rings);

    ASSERT_EQ(answer, result);
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_3) {
    int rings = 3;
    std::vector<std::vector<int>> answer = {{1, 3}, {1, 2}, {3, 2},
                                            {1, 3}, {2, 1}, {2, 3},
                                            {1, 3}};
    std::vector<std::vector<int>> result;

    result = TowerOfHanoi::CalculateSteps(rings);

    ASSERT_EQ(answer, result);
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_4) {
    int rings = 4;
    std::vector<std::vector<int>> answer = {{1, 2}, {1, 3}, {2, 3},
                                            {1, 2}, {3, 1}, {3, 2},
                                            {1, 2}, {1, 3}, {2, 3},
                                            {2, 1}, {3, 1}, {2, 3},
                                            {1, 2}, {1, 3}, {2, 3}};
    std::vector<std::vector<int>> result;

    result = TowerOfHanoi::CalculateSteps(rings);

    ASSERT_EQ(answer, result);
}
