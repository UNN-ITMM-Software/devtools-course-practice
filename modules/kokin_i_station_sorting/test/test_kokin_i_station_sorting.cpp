// Copyright 2024 Kokin Ivan

#include <gtest/gtest.h>
#include "../include/sort_station.h"

TEST(SortingStationTest, ParseValidExpression) {
    SortStationDerived station;
    double result = station.evaluateFunction("1-(2/(4^2))");
    EXPECT_EQ(result, 0.875);
}

TEST(SortStationDerivedTest, EvaluateFunction) {
    SortStationDerived calculator;
    EXPECT_EQ(calculator.evaluateFunction("3+4*2"), 11.0);
}

TEST(SortStationDerivedTest, valid) {
    SortStationDerived calculator;
    EXPECT_EQ(calculator.evaluateFunction("5+3*6-8"), 15.0);
}

TEST(SortStationDerivedTest, valid2) {
    SortStationDerived calculator;
    EXPECT_EQ(calculator.evaluateFunction("4^2+36/12-1"), 5.5);
}
