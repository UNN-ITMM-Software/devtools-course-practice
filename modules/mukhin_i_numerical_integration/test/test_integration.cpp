// Copyright 2024 Mukhin Ivan

#define _USE_MATH_DEFINES

#include <gtest/gtest.h>
#include <cmath>
#include <functional>
#include "include/integration_methods.h"


struct TestCasesHelper {
    std::function<double(double)> f;
    double x0;
    double xn;
    double n;
    double expected_answer;
    TestCasesHelper(
        const std::function<double(double)>& f_,
        double x0,
        double xn,
        double n,
        double expected_answer) : f(f_),
                                  x0(x0),
                                  xn(xn),
                                  n(n),
                                  expected_answer(expected_answer) { }
};


double equals_zero(double x) {
    if (x <= 1e-8) {
        return 0.0;
    }
    return x;
}


class mukhin_i_parametric_tests_1 :
    public ::testing::TestWithParam<TestCasesHelper> { };


TEST_P(

    mukhin_i_parametric_tests_1,
    can_correctly_integrate_trapezoid_with_small_precision

    ) {
    TestCasesHelper helper = GetParam();
    double numeric_answer = IntegrationMethods::integrate_trapezoid(helper.f,
                                                                    helper.x0,
                                                                    helper.xn,
                                                                    helper.n);
    double expected_answer = helper.expected_answer;
    EXPECT_FLOAT_EQ(expected_answer, equals_zero(numeric_answer));
}


TEST(mukhin_i_test_cases, throw_if_splits_negative) {
    ASSERT_ANY_THROW(
        IntegrationMethods::integrate_trapezoid([](double x) { return x; },
                                                0,
                                                1,
                                                -50));
}


TEST_P(

    mukhin_i_parametric_tests_1,
    can_correctly_integrate_quads_with_small_precision

    ) {
    TestCasesHelper helper = GetParam();
    double numeric_answer = IntegrationMethods::integrate_quads(helper.f,
                                                                helper.x0,
                                                                helper.xn,
                                                                helper.n);
    double expected_answer = helper.expected_answer;
    EXPECT_FLOAT_EQ(expected_answer, equals_zero(numeric_answer));
}


INSTANTIATE_TEST_CASE_P(mukhin_i_test_cases, mukhin_i_parametric_tests_1,
testing::Values(
    TestCasesHelper([](double x) { return x * x; },
                    0,
                    1,
                    10000,
                    1.0 / 3.0),
    TestCasesHelper([](double x) { return x * x; },
                    0,
                    10,
                    10000,
                    1000.0 / 3.0),
    TestCasesHelper([](double x) { return std::sinh(x); },
                    -10,
                    10,
                    10000,
                    0),
    TestCasesHelper([](double x) { return std::log(x); },
                    2,
                    3,
                    10000,
                    std::log(27.0 / 4.0) - 1),
    TestCasesHelper([](double x) { return 1.0 / std::sqrt(1 - x*x); },
                    0,
                    0.5,
                    10000,
                    M_PI / 6.0)));
