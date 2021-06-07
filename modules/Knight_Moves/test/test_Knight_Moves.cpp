// Copyright 2021 Galindo Buitrago Julio Cesar

#include <gtest/gtest.h>

#include "include/Knight_Moves.h"

TEST(Galindo_Knight_Moves, Minimum_without_obstacles_i) {
    KM sol;
    int x = 10;
    int y = 12;
    int result = sol.knightMinimumValue(x, y);
    int expectation = 8;
    ASSERT_EQ(expectation, result);
}

TEST(Galindo_Knight_Moves, Minimum_without_obstacles_ii) {
    KM sol;
    int x = 30;
    int y = 28;
    int result = sol.knightMinimumValue(x, y);
    int expectation = 20;
    ASSERT_EQ(expectation, result);
}

TEST(Galindo_Knight_Moves, Minimum_without_obstacles_iii) {
    KM sol;
    int x = 40;
    int y = 38;
    int result = sol.knightMinimumValue(x, y);
    int expectation = 26;
    ASSERT_EQ(expectation, result);
}

TEST(Galindo_Knight_Moves, Minimum_without_obstacles_iv) {
    KM sol;
    int x = 0;
    int y = 0;
    int result = sol.knightMinimumValue(x, y);
    int expectation = 0;
    ASSERT_EQ(expectation, result);
}

TEST(Galindo_Knight_Moves, Minimum_without_obstacles_v) {
    KM sol;
    int x = 1;
    int y = 1;
    int result = sol.knightMinimumValue(x, y);
    int expectation = 2;
    ASSERT_EQ(expectation, result);
}

TEST(Galindo_Knight_Moves, Minimum_without_obstacles_vi) {
    KM sol;
    int x = -34;
    int y = 50;
    int result = sol.knightMinimumValue(x, y);
    int expectation = 28;
    ASSERT_EQ(expectation, result);
}

TEST(Galindo_Knight_Moves, Minimum_without_obstacles_vii) {
    KM sol;
    int x = -63;
    int y = -78;
    int result = sol.knightMinimumValue(x, y);
    int expectation = 47;
    ASSERT_EQ(expectation, result);
}
