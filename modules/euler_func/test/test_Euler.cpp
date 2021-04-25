// Copyright 2021 Mishin Ilya

#include <gtest/gtest.h>
#include <tuple>

#include "include/Euler.h"

TEST(Mishin_Euler, AssertThrow) {
    ASSERT_ANY_THROW(phi(-1));
}

typedef testing::TestWithParam<std::tuple<int, int>> Parametrized;
TEST_P(Parametrized, Check_) {
    int a = std::get<0>(GetParam());
    int b = std::get<1>(GetParam());
    ASSERT_EQ(a, phi(b));
}

INSTANTIATE_TEST_CASE_P(/**/, Parametrized, ::testing::Values(
    std::make_tuple(0, 0),
    std::make_tuple(1, 1),
    std::make_tuple(1, 2),
    std::make_tuple(2, 3),
    std::make_tuple(2, 4),
    std::make_tuple(4, 5),
    std::make_tuple(120, 155)
));

TEST(Mishin_Euler, Check_multiplicativity) {
    ASSERT_EQ(phi(5)*phi(7), phi(5*7));
}

TEST(Mishin_Euler, Check_prime) {
    ASSERT_EQ(13 - 1, phi(13));
}

TEST(Mishin_Euler, Check_degree) {
    ASSERT_EQ(phi(17*17*17), 17*17*phi(17));
}
