// Copyright 2024 Mironov Ilya

#include <gtest/gtest.h>

#include <numeric>

#include "include/stats.h"

TEST(TestStats, OneElementMean) {
    std::vector<float> data = {1.0f};
    EXPECT_FLOAT_EQ(1.0f, stats::moment(data, 1, 0.0f));
}

TEST(TestStats, OneElementVar) {
    std::vector<float> data = {1.0f};
    const float mean = stats::moment(data, 1, 0.0f);
    EXPECT_FLOAT_EQ(0.0f, stats::moment(data, 2, mean));
}

TEST(TestStats, CompareVarImplsSimple) {
    std::vector<float> data = {1.0f, 2.0f, 3.0f};
    EXPECT_NEAR(0.6666f, stats::var(data), 1e-4);
    EXPECT_NEAR(0.6666f, stats::var_base(data), 1e-4);
}

TEST(TestStats, SimpleData) {
    std::vector<float> data = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    EXPECT_FLOAT_EQ(3.0f, stats::mean(data));
    EXPECT_FLOAT_EQ(2.0f, stats::var(data));
    EXPECT_FLOAT_EQ(2.0f, stats::var_base(data));
}

TEST(TestStats, CompareVarImplsIota) {
    std::vector<float> data(100);
    std::iota(data.begin(), data.end(), 0.0f);
    ASSERT_FLOAT_EQ(stats::var_base(data), stats::var(data));
}

TEST(TestStats, NegativeSimpleData) {
    std::vector<float> data = {-1.0f, -2.0f, -3.0f, -4.0f, -5.0f};
    EXPECT_FLOAT_EQ(-3.0f, stats::mean(data));
    EXPECT_FLOAT_EQ(2.0f, stats::var(data));
}
