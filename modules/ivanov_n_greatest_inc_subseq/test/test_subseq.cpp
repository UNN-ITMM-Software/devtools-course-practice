// Copyright 2024 Ivanov Nikita

#include <gtest/gtest.h>

#include <random>
#include <string>

#include "include/subseq.h"

TEST(Test_case_ivanov_lis, conctructor) {
    ASSERT_NO_THROW(LIS());
}

TEST(Test_case_ivanov_lis, run_dec_nums) {
    std::vector<int> nums{5, 4, 3, 2, 1, 0};
    LIS lis(nums);
    auto res = lis.run();
    ASSERT_EQ(res.size(), 1ull);
    ASSERT_EQ(res[0], 5);
}

TEST(Test_case_ivanov_lis, run_empty_nums) {
    LIS lis;
    auto res = lis.run();

    ASSERT_EQ(res.size(), 0ull);
}

TEST(Test_case_ivanov_lis, add_num) {
    std::vector<int> nums{5, 4, 3, 2, 1, 0};
    LIS lis(nums);

    ASSERT_NO_THROW(lis.addNumber(-1));

    ASSERT_EQ(lis.getSize(), 7ull);
}

TEST(Test_case_ivanov_lis, run1) {
    std::vector<int> nums{ 10, 22, 9, 33, 21, 50, 41, 60 };
    LIS lis(nums);
    auto res = lis.run();

    std::vector<int> ans{10, 22, 33, 50, 60};
    ASSERT_EQ(res, ans);
}

TEST(Test_case_ivanov_lis, run2) {
    std::vector<int> nums{ 3, 4, 9, 2, 5, 1 };
    LIS lis(nums);
    auto res = lis.run();

    std::vector<int> ans{3, 4, 9};
    ASSERT_EQ(res, ans);
}
