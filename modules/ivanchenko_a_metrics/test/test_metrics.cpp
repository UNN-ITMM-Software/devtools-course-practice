// Copyright 2024 Ivanchenko Aleksei

#include <gtest/gtest.h>
#include "include/metrics.h"

TEST(ivanchenko_a_metrics, l1_zero_if_equal) {
    std::vector<float> v1, v2;
    float expected;

    v1 = {0.1, 0.2, 0.3};
    v2 = {0.1, 0.2, 0.3};

    expected = 0;

    EXPECT_FLOAT_EQ(expected, metrics::l1(v1, v2));
}

TEST(ivanchenko_a_metrics, l2_zero_if_equal) {
    std::vector<float> v1, v2;
    float expected;

    v1 = {0.1, 0.2, 0.3};
    v2 = {0.1, 0.2, 0.3};

    expected = 0;

    EXPECT_FLOAT_EQ(expected, metrics::l2(v1, v2));
}

TEST(ivanchenko_a_metrics, l3_zero_if_equal) {
    std::vector<float> v1, v2;
    float expected;

    v1 = {0.1, 0.2, 0.3};
    v2 = {0.1, 0.2, 0.3};

    expected = 0;

    EXPECT_FLOAT_EQ(expected, metrics::l3(v1, v2));
}

TEST(ivanchenko_a_metrics, l4_zero_if_equal) {
    std::vector<float> v1, v2;
    float expected;

    v1 = {0.1, 0.2, 0.3};
    v2 = {0.1, 0.2, 0.3};

    expected = 0;

    EXPECT_FLOAT_EQ(expected, metrics::l4(v1, v2));
}

TEST(ivanchenko_a_metrics, linf_zero_if_equal) {
    std::vector<float> v1, v2;
    float expected;

    v1 = {0.1, 0.2, 0.3};
    v2 = {0.1, 0.2, 0.3};

    expected = 0;

    EXPECT_FLOAT_EQ(expected, metrics::linf(v1, v2));
}

TEST(ivanchenko_a_metrics, l1_throws_if_different_size) {
    std::vector<float> v1, v2;

    v1.resize(10);
    v2.resize(9);

    EXPECT_ANY_THROW(metrics::l1(v1, v2));
}

TEST(ivanchenko_a_metrics, l2_throws_if_different_size) {
    std::vector<float> v1, v2;

    v1.resize(10);
    v2.resize(9);

    EXPECT_ANY_THROW(metrics::l2(v1, v2));
}

TEST(ivanchenko_a_metrics, l3_throws_if_different_size) {
    std::vector<float> v1, v2;

    v1.resize(10);
    v2.resize(9);

    EXPECT_ANY_THROW(metrics::l3(v1, v2));
}

TEST(ivanchenko_a_metrics, l4_throws_if_different_size) {
    std::vector<float> v1, v2;

    v1.resize(10);
    v2.resize(9);

    EXPECT_ANY_THROW(metrics::l4(v1, v2));
}

TEST(ivanchenko_a_metrics, linf_throws_if_different_size) {
    std::vector<float> v1, v2;

    v1.resize(10);
    v2.resize(9);

    EXPECT_ANY_THROW(metrics::linf(v1, v2));
}

TEST(ivanchenko_a_metrics, l1_not_zero_if_not_equal) {
    std::vector<float> v1, v2;
    float zero;

    v1 = {0.1, 0.2, 0.3};
    v2 = {0.1, 0.22, 0.3};
    zero = 0;

    EXPECT_NE(zero, metrics::l1(v1, v2));
}

TEST(ivanchenko_a_metrics, l2_not_zero_if_not_equal) {
    std::vector<float> v1, v2;
    float zero;

    v1 = {0.1, 0.2, 0.3};
    v2 = {0.1, 0.22, 0.3};
    zero = 0;

    EXPECT_NE(zero, metrics::l2(v1, v2));
}

TEST(ivanchenko_a_metrics, l3_not_zero_if_not_equal) {
    std::vector<float> v1, v2;
    float zero;

    v1 = {0.1, 0.2, 0.3};
    v2 = {0.1, 0.22, 0.3};

    zero = 0;

    EXPECT_NE(zero, metrics::l3(v1, v2));
}

TEST(ivanchenko_a_metrics, l4_not_zero_if_not_equal) {
    std::vector<float> v1, v2;
    float zero;

    v1 = {0.1, 0.2, 0.3};
    v2 = {0.1, 0.22, 0.3};
    zero = 0;

    EXPECT_NE(zero, metrics::l4(v1, v2));
}

TEST(ivanchenko_a_metrics, linf_not_zero_if_not_equal) {
    std::vector<float> v1, v2;
    float zero;

    v1 = {0.1, 0.2, 0.3};
    v2 = {0.1, 0.22, 0.3};
    zero = 0;

    EXPECT_NE(zero, metrics::linf(v1, v2));
}

TEST(ivanchenko_a_metrics, l1_expamle) {
    std::vector<float> v1, v2;
    float expected;

    v1 = {0.11, 0.2, 0.33};
    v2 = {0.1, 0.22, 0.3};
    expected = 0.06;

    EXPECT_FLOAT_EQ(expected, metrics::l1(v1, v2));
}

TEST(ivanchenko_a_metrics, l2_expamle) {
    std::vector<float> v1, v2;
    float expected;

    v1 = {1, 2, 3};
    v2 = {1, 5, 7};
    expected = 5;

    EXPECT_FLOAT_EQ(expected, metrics::l2(v1, v2));
}

TEST(ivanchenko_a_metrics, l3_example) {
    std::vector<float> v1, v2;
    float expected;

    v1 = {0.1, 0.2, 0.34};
    v2 = {0.1, 0.22, 0.3};

    expected = 0.041601669;

    EXPECT_FLOAT_EQ(expected, metrics::l3(v1, v2));
}

TEST(ivanchenko_a_metrics, l4_example) {
    std::vector<float> v1, v2;
    float expected;

    v1 = {0.1, 0.2, 0.34};
    v2 = {0.1, 0.22, 0.3};
    expected = 0.040610857;

    EXPECT_FLOAT_EQ(expected, metrics::l4(v1, v2));
}

TEST(ivanchenko_a_metrics, linf_example) {
    std::vector<float> v1, v2;
    float expected;

    v1 = {1, 2, 3};
    v2 = {2, 2.5, 3.25};
    expected = 1;

    EXPECT_FLOAT_EQ(expected, metrics::linf(v1, v2));
}
