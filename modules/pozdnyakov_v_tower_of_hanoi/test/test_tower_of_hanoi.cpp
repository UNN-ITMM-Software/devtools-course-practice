// Copyright 2024 Pozdnyakov Vasya

#include <gtest/gtest.h>
#include <vector>
#include "include/tower_of_hanoi.h"

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_negative) {
    int rings = -10;
    TowerOfHanoi tower;
    ASSERT_ANY_THROW(tower.CalculateSteps(rings));
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_zero) {
    int rings = 0;
    TowerOfHanoi tower;
    ASSERT_ANY_THROW(tower.CalculateSteps(rings));
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_positive) {
    int rings = 10;
    TowerOfHanoi tower;
    ASSERT_NO_THROW(tower.CalculateSteps(rings));
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_1) {
    int rings = 1;
    TowerOfHanoi tower;
    std::vector<std::vector<int>> answer = {{1, 3}};
    std::vector<std::vector<int>> result;

    result = tower.CalculateSteps(rings);

    ASSERT_EQ(answer, result);
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_2) {
    int rings = 2;
    TowerOfHanoi tower;
    std::vector<std::vector<int>> answer = {{1, 2}, {1, 3}, {2, 3}};
    std::vector<std::vector<int>> result;

    result = tower.CalculateSteps(rings);

    ASSERT_EQ(answer, result);
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_3) {
    int rings = 3;
    TowerOfHanoi tower;
    std::vector<std::vector<int>> answer = {{1, 3}, {1, 2}, {3, 2},
                                            {1, 3}, {2, 1}, {2, 3},
                                            {1, 3}};
    std::vector<std::vector<int>> result;

    result = tower.CalculateSteps(rings);

    ASSERT_EQ(answer, result);
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_4) {
    int rings = 4;
    TowerOfHanoi tower;
    std::vector<std::vector<int>> answer = {{1, 2}, {1, 3}, {2, 3},
                                            {1, 2}, {3, 1}, {3, 2},
                                            {1, 2}, {1, 3}, {2, 3},
                                            {2, 1}, {3, 1}, {2, 3},
                                            {1, 2}, {1, 3}, {2, 3}};
    std::vector<std::vector<int>> result;

    result = tower.CalculateSteps(rings);

    ASSERT_EQ(answer, result);
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_5) {
    int rings = 5;
    TowerOfHanoi tower;
    std::vector<std::vector<int>> answer = { { 1, 3 }, { 1, 2 },
    { 3, 2 }, { 1, 3 }, { 2, 1 }, { 2, 3 }, { 1, 3 }, { 1, 2 },
    { 3, 2 }, { 3, 1 }, { 2, 1 }, { 3, 2 }, { 1, 3 }, { 1, 2 },
    { 3, 2 }, { 1, 3 }, { 2, 1 }, { 2, 3 }, { 1, 3 }, { 2, 1 },
    { 3, 2 }, { 3, 1 }, { 2, 1 }, { 2, 3 }, { 1, 3 }, { 1, 2 },
    { 3, 2 }, { 1, 3 }, { 2, 1 }, { 2, 3 }, { 1, 3 } };
    std::vector<std::vector<int>> result;

    result = tower.CalculateSteps(rings);

    ASSERT_EQ(answer, result);
}
