// Copyright 2024 Kokin Ivan

#include <gtest/gtest.h>
#include "../include/sort_station.h"

TEST(SortingStationTest, ParseValidExpression) {
    SortStationDerived station;
    double result = station.evaluateFunction("1-(2/(4^2))");
    EXPECT_EQ(result, 0.875);
}

TEST(SortingStationTest, ParseInvalidExpression) {
    SortStationDerived station;
    double result = station.evaluateFunction("1-2");
    EXPECT_EQ(result, -1);
}
