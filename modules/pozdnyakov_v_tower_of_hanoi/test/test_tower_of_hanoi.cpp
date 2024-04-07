// Copyright 2024 Pozdnyakov Vasya

#include <gtest/gtest.h>
#include <vector>
#include "include/tower_of_hanoi.h"

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_negative) {
    ASSERT_ANY_THROW(TowerOfHanoi::CalculateSteps(-10));
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_zero) {
    ASSERT_ANY_THROW(TowerOfHanoi::CalculateSteps(0));
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_positive) {
    ASSERT_NO_THROW(TowerOfHanoi::CalculateSteps(10));
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_1) {
    std::vector<std::vector<int>> answer = {{1, 3}};
    std::vector<std::vector<int>> result = TowerOfHanoi::CalculateSteps(1);

    ASSERT_EQ(answer, result);
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_2) {
    std::vector<std::vector<int>> answer = {{1, 2}, {1, 3}, {2, 3}};
    std::vector<std::vector<int>> result = TowerOfHanoi::CalculateSteps(2);
    
    ASSERT_EQ(answer, result);
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_3) {
    std::vector<std::vector<int>> answer = {{1, 3}, {1, 2}, {3, 2}, {1, 3}, {2, 1}, {2, 3}, {1, 3}};
    std::vector<std::vector<int>> result = TowerOfHanoi::CalculateSteps(3);

    ASSERT_EQ(answer, result);
}

TEST(Pozdnyakov_Vasya_HanoiTests, number_of_rings_is_4) {
    std::vector<std::vector<int>> answer = {{1, 2}, {1, 3}, {2, 3},
                                            {1, 2}, {3, 1}, {3, 2}, 
                                            {1, 2}, {1, 3}, {2, 3}, 
                                            {2, 1}, {3, 1}, {2, 3}, 
                                            {1, 2}, {1, 3}, {2, 3}};
    std::vector<std::vector<int>> result = TowerOfHanoi::CalculateSteps(4);

    ASSERT_EQ(answer, result);
}
