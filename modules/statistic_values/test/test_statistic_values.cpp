// Copyright 2021 Prokofeva Elizaveta

#include <gtest/gtest.h>
#include <vector>

#include "include/statistic_values.h"

TEST(CalculateStatisticValues, Test_Mean_Value) {
    int size = 5;
    vector<double> x = { 1, 2, 3, 4, 5 };
    vector<double> p = { 0.1, 0.2, 0.3, 0.4, 0.5 };

    double result = statValues::meanValue(x, p, size);
    double correct = 5.5;

    ASSERT_EQ(correct, result);
}

TEST(CalculateStatisticValues, Test_Variance) {
    int size = 5;
    vector<double> x = { 1, 2, 3, 4, 5 };
    vector<double> p = { 0.1, 0.2, 0.3, 0.4, 0.5 };

    double result = statValues::variance(x, p, size);
    double correct = 7.375;

    ASSERT_EQ(correct, result);
}

TEST(CalculateStatisticValues, Test_First_Starting_Moment) {
    int size = 5;
    int pow = 1;
    vector<double> x = { 1, 2, 3, 4, 5 };
    vector<double> p = { 0.1, 0.2, 0.3, 0.4, 0.5 };

    double result = statValues::start(x, p, size, pow);
    double correct = statValues::meanValue(x, p, size);

    ASSERT_EQ(correct, result);
}

TEST(CalculateStatisticValues, Test_Second_Starting_Moment) {
    int size = 5;
    int pow = 2;
    vector<double> x = { 1, 2, 3, 4, 5 };
    vector<double> p = { 0.1, 0.2, 0.3, 0.4, 0.5 };

    double result = statValues::start(x, p, size, pow);
    double correct = 22.5;

    ASSERT_EQ(correct, result);
}

TEST(CalculateStatisticValues, Test_Second_Central_Moment) {
    int size = 5;
    int pow = 2;
    vector<double> x = { 1, 2, 3, 4, 5 };
    vector<double> p = { 0.1, 0.2, 0.3, 0.4, 0.5 };

    double result = statValues::centr(x, p, size, pow);
    double correct = statValues::variance(x, p, size);

    ASSERT_EQ(correct, result);
}

TEST(CalculateStatisticValues, Test_Third_Central_Moment) {
    int size = 5;
    int pow = 3;
    vector<double> x = { 1, 2, 3, 4, 5 };
    vector<double> p = { 0.1, 0.2, 0.3, 0.4, 0.5 };

    double result = statValues::centr(x, p, size, pow);
    double correct = -23.7875;

    ASSERT_EQ(correct, result);
}
