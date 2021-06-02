// Copyright 2021 Lebedev Andrew

#include <gtest/gtest.h>
#include <utility>
#include <tuple>

#include "include/DepositCalc.h"

TEST(DepositCalc, setDepositSum) {
    depositCalc x;
    x.setDepositSum(300);
    ASSERT_EQ(300, x.getDepositSum());
}

TEST(DepositCalc, setBadDepositSum) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setDepositSum(-2));
}

TEST(DepositCalc, setNumberOfMonths) {
    depositCalc x;
    x.setNumberOfMonths(25);
    ASSERT_EQ(25, x.getNumberOfMonths());
}

TEST(DepositCalc, setBadNumberOfMonths) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setNumberOfMonths(-12));
}

TEST(DepositCalc, setNumberOfDays) {
    depositCalc x;
    x.setNumberOfDays(267);
    ASSERT_EQ(267, x.getNumberOfDays());
}

TEST(DepositCalc, setBadNumberOfDays) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setNumberOfDays(-20));
}

TEST(DepositCalc, setInterestRate) {
    depositCalc x;
    x.setInterestRate(8);
    ASSERT_EQ(8, x.getInterestRate());
}

TEST(DepositCalc, setBadInterestRate) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setInterestRate(-12));
}

TEST(DepositCalc, setDate) {
    depositCalc x;
    ASSERT_NO_THROW(x.setDate(8, 12, 2021));
}

TEST(DepositCalc, setBadDate) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setDate(-12, 13 , -1));
}

TEST(DepositCalc, setCapitalization) {
    depositCalc x;
    x.setCapitalization(2);
    ASSERT_EQ(2, x.getCapitalization());
}

TEST(DepositCalc, setBadCapitalization) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setCapitalization(-3));
}

TEST(DepositCalc, testParamConstructor) {
    ASSERT_NO_THROW(depositCalc x(300, 12, 2,
        4, 6, 2021, 1));
}

TEST(DepositCalc, calcTestNoDeposit) {
    depositCalc x;
    x.setDate(12, 07, 2021);
    x.setInterestRate(8);
    x.setNumberOfMonths(12);
    ASSERT_ANY_THROW(x.calculate());
}

TEST(DepositCalc, calcTestNoDAte) {
    depositCalc x;
    x.setDepositSum(700000);
    x.setInterestRate(8);
    x.setNumberOfMonths(12);
    ASSERT_ANY_THROW(x.calculate());
}

TEST(DepositCalc, calcTestNoInterestRate) {
    depositCalc x;
    x.setDepositSum(700000);
    x.setDate(12, 07, 2021);
    x.setNumberOfMonths(12);
    ASSERT_ANY_THROW(x.calculate());
}

TEST(DepositCalc, calcTestNoDuration) {
    depositCalc x;
    x.setDepositSum(700000);
    x.setDate(12, 07, 2021);
    x.setInterestRate(8);
    ASSERT_ANY_THROW(x.calculate());
}

TEST(DepositCalc, calcTestNumberOfDays) {
    depositCalc x;
    x.setDepositSum(700000);
    x.setDate(12, 07, 2021);
    x.setInterestRate(8);
    x.setNumberOfDays(93);
    ASSERT_NO_THROW(x.calculate());
    ASSERT_EQ(714268, x.getResult());
}

typedef testing::TestWithParam<std::tuple<int, int, int, int,
    double, int, int, int>> Parameterized;
TEST_P(Parameterized, calcTest) {
    int depositSum = std::get<0>(GetParam());
    int day = std::get<1>(GetParam());
    int month = std::get<2>(GetParam());
    int year = std::get<3>(GetParam());
    double interestRate = std::get<4>(GetParam());
    int numberOfMonths = std::get<5>(GetParam());
    int capitalization = std::get<6>(GetParam());
    int expected = std::get<7>(GetParam());
    depositCalc x;
    x.setDepositSum(depositSum);
    x.setDate(day, month, year);
    x.setInterestRate(interestRate);
    x.setNumberOfMonths(numberOfMonths);
    x.setCapitalization(capitalization);
    ASSERT_NO_THROW(x.calculate());
    ASSERT_EQ(expected, x.getResult());
}

INSTANTIATE_TEST_CASE_P(/**/, Parameterized, ::testing::Values(
     std::make_tuple(700000, 12, 07, 2021, 8, 12, 0, 756000),
     std::make_tuple(200000, 31, 07, 2021, 4.5, 11, 0, 208260),
     std::make_tuple(300000, 10, 07, 2021, 7, 2, 1, 303588),
     std::make_tuple(750000, 10, 07, 2021, 3, 13, 3, 774781),
     std::make_tuple(400000, 10, 07, 2021, 5, 4, 2, 406794),
     std::make_tuple(500000, 9, 06, 2021, 7, 5, 2, 514879),
     std::make_tuple(500000, 9, 06, 2021, 7, 25, 4, 575744)
));
