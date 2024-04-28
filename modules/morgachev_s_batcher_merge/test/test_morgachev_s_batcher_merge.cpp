// Copyright 2024 Morgachev Stepan

#include <gtest/gtest.h>
#include <algorithm>

#include "include/batcher_merge.h"

TEST(Morgachev_Stepan_Batcher_Merge, Check_Empty_Data) {
    std::vector<int> data{};

    EXPECT_ANY_THROW(BatcherMerge<int>::batcherMerge(data));
}

TEST(Morgachev_Stepan_Batcher_Merge, Check_Simple_Data) {
    std::vector<int> data{ 15, 5, 8, 73 };
    std::vector<int> sorted = data;

    std::sort(sorted.begin(), sorted.end());
    BatcherMerge<int>::batcherMerge(data);

    EXPECT_EQ(data, sorted);
}

TEST(Morgachev_Stepan_Batcher_Merge, Check_Sorted_Data) {
    std::vector<int> data{ 5, 8, 15, 73 };
    std::vector<int> sorted = data;

    std::sort(sorted.begin(), sorted.end());
    BatcherMerge<int>::batcherMerge(data);

    EXPECT_EQ(data, sorted);
}

TEST(Morgachev_Stepan_Batcher_Merge, Check_Negative_Data) {
    std::vector<int> data{ -5, -13, -6, 0, 1, -4 };
    std::vector<int> sorted = data;

    std::sort(sorted.begin(), sorted.end());
    BatcherMerge<int>::batcherMerge(data);

    EXPECT_EQ(data, sorted);
}

TEST(Morgachev_Stepan_Batcher_Merge, Check_Random_Data) {
    std::vector<int> data = BatcherMerge<int>::getRandomVector(20);
    std::vector<int> sorted = data;

    std::sort(sorted.begin(), sorted.end());
    BatcherMerge<int>::batcherMerge(data);

    EXPECT_EQ(data, sorted);
}
