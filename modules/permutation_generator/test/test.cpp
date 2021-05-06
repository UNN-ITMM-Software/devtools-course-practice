// Copyright 2021 Romanyuk Sergey
#include <gtest/gtest.h>
#include <tuple>
#include "include/permutation.h"

TEST(Permutation_Generate, Test1_while) {
    Permutation p;
    int n = 3;
    int *a = new int[n];
    a = p.get_arr(n);

    for (int i = 0; i < 20; i++) {
        p.NextSet(a, n);
    }

    int res[] = { 3, 2, 1};
    for (int i = 0; i < n; i++) {
        ASSERT_EQ(res[i], a[i]);
    }
}

TEST(Permutation_Generate, Test2_Fact) {
    Permutation p;
    int n = 3;
    int f = 6;
    int fa = p.fact(n);
    ASSERT_EQ(f, fa);
}

typedef testing::TestWithParam<std::tuple<int, int>>
Permutation_Generate_Param;
TEST_P(Permutation_Generate_Param, Test3_PARAM) {
    Permutation p;
    int n = std::get<0>(GetParam());
    int iterations = std::get<1>(GetParam());
    if (iterations > p.fact(n)) {
        iterations = p.fact(n);
    }
    int* a = new int[n];
    int* checker = new int[n];
    a = p.get_arr(n);
    checker = p.get_arr(n);
    for (int i = 0; i < iterations; ++i) {
        for (int j = 0; j < n; ++j) {
            ASSERT_EQ(a[j], checker[j]);
        }
        p.NextSet(a, n);
        std::next_permutation(checker, checker + n);
    }
}

INSTANTIATE_TEST_CASE_P(/**/, Permutation_Generate_Param, testing::Combine(
    testing::Values(2, 3, 5),
    testing::Values(2, 4, 6, 7)
));
