// Copyright 2024 Mukhin Ivan
#include <gtest/gtest.h>
#include <initializer_list>
#include "include/vectors.h"

class TestCaseHelper {
 public:
    mukhin_i::Vector3D<double> v1;
    mukhin_i::Vector3D<double> v2;

    TestCaseHelper(const std::initializer_list<double>& v11,
                   const std::initializer_list<double>& v22)
                   : v1(v11), v2(v22) {}
};

class mukhin_i_test_cases_vector \
      : public ::testing::TestWithParam<TestCaseHelper> {};


TEST(mukhin_i_vectors_test_cases, can_create_vector) {
    mukhin_i::Vector3D<double> v({1.0, 2.0, 3.0});
    EXPECT_EQ(v[0], 1.0);
}

TEST(mukhin_i_vectors_test_cases, copy_constructor_works) {
    mukhin_i::Vector3D<double> y({1.0, 2.0, 3.0});
    mukhin_i::Vector3D<double> v(y);
    EXPECT_EQ(v[0], 1.0);
}

TEST(mukhin_i_vectors_test_cases, copy_operator_works) {
    mukhin_i::Vector3D<double> y({1.0, 2.0, 3.0});
    mukhin_i::Vector3D<double> v = y;
    EXPECT_EQ(v[0], 1.0);
}

TEST_P(mukhin_i_test_cases_vector, can_sum_vectors) {
    auto helper = GetParam();
    mukhin_i::Vector3D<double> res({helper.v1[0] + helper.v2[0],
                                    helper.v1[1] + helper.v2[1],
                                    helper.v1[2] + helper.v2[2]});
    EXPECT_EQ(helper.v1 + helper.v2, res);
}

TEST_P(mukhin_i_test_cases_vector, can_sub_vectors) {
    auto helper = GetParam();
    mukhin_i::Vector3D<double> res({helper.v1[0] - helper.v2[0],
                                    helper.v1[1] - helper.v2[1],
                                    helper.v1[2] - helper.v2[2]});
    EXPECT_EQ(helper.v1 - helper.v2, res);
}

TEST_P(mukhin_i_test_cases_vector, can_mul_vectors) {
    auto helper = GetParam();
    mukhin_i::Vector3D<double> res({helper.v1[0] * helper.v2[0],
                                    helper.v1[1] * helper.v2[1],
                                    helper.v1[2] * helper.v2[2]});
    EXPECT_EQ(helper.v1 * helper.v2, res);
}

TEST_P(mukhin_i_test_cases_vector, can_dot_vectors) {
    auto helper = GetParam();
    double res = (helper.v1[0] *  helper.v2[0] +
                  helper.v1[1] *  helper.v2[1] +
                  helper.v1[2] *  helper.v2[2]);
    EXPECT_EQ(dot(helper.v1, helper.v2), res);
}

TEST_P(mukhin_i_test_cases_vector, can_norm_vectors) {
    auto helper = GetParam();
    double res1 = std::sqrt(helper.v1[0] *  helper.v1[0] +
                            helper.v1[1] *  helper.v1[1] +
                            helper.v1[2] *  helper.v1[2]);
    double res2 = std::sqrt(helper.v2[0] *  helper.v2[0] +
                            helper.v2[1] *  helper.v2[1] +
                            helper.v2[2] *  helper.v2[2]);
    EXPECT_EQ(helper.v1.norm(), res1);
    EXPECT_EQ(helper.v2.norm(), res2);
}

INSTANTIATE_TEST_CASE_P(mukhin_i_parametric, mukhin_i_test_cases_vector,
testing::Values(TestCaseHelper({1.0, 2.0, 3.0},
                                   {1.0, 2.0, 3.0}),
                TestCaseHelper({-1.0, -2.0, -3.0},
                                   {1.0, 2.0, 3.0}),
                TestCaseHelper({0.25, -0.75, 3.123},
                                   {1.23, 2.89, 3.23})));
