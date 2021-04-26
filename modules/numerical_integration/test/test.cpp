// Copyright 2021 Tashirev Ivan
#include <gtest/gtest.h>
#include<cmath>
#include "integral.h"

TEST(integral, Test_func1_1) {
    double numerical_integration = get_Integral(func1, 2, 5, 10);
    double answer = 0.5363761633138187;
        ASSERT_LE(numerical_integration, answer);
}
TEST(integral, Test_func1_2) {
    double numerical_integration = get_Integral(func1, 1, 10, 100);
    double answer = 1.474004572610699;
        ASSERT_LE(numerical_integration, answer);
    }
}
TEST(integral, Test_func2_1) {
    double numerical_integration = get_Integral(func2, 2, 5, 10);
    double answer = 2.495135691915521;
        ASSERT_LE(numerical_integration, answer);
}
TEST(integral, Test_func3_1) {
    double numerical_integration = get_Integral(func3, 2, 5, 10);
    double answer = 0.02676495780795789;
        ASSERT_LE(numerical_integration, answer);
}
TEST(integral, Test_func3_2) {
    double numerical_integration = get_Integral(func3, 1, 12, 100);
    double answer = 0.1897329721344028;
        ASSERT_LE(numerical_integration, answer);
}
