// Copyright 2024 Lesnikov Nikita

#include <gtest/gtest.h>
#include "include/LongNumber.h"

class BuildingFromStringParameterizedTestFixture :
    public ::testing::TestWithParam<std::pair<std::string, std::string>> {
};

TEST_P(BuildingFromStringParameterizedTestFixture, BuldingFromString) {
    LongNumber n(GetParam().first);
    EXPECT_EQ(n.getString(), GetParam().second);
}

INSTANTIATE_TEST_CASE_P(
    BuldingFromStringTests,
    BuildingFromStringParameterizedTestFixture,
    ::testing::Values(
        std::pair<std::string, std::string>{ "0", "0" },
        std::pair<std::string, std::string>{ "-0", "0" },
        std::pair<std::string, std::string>{ "1", "1" },
        std::pair<std::string, std::string>{ "1000", "1000" },
        std::pair<std::string, std::string>{ "1727", "1727" }
));

TEST(Lesnikov_Nikita_LongNumber, CopyConstructor) {
    LongNumber n("111");
    LongNumber n2 = n;
    EXPECT_EQ(n.getString(), n2.getString());
}

TEST(Lesnikov_Nikita_LongNumber, MoveConstructor) {
    LongNumber n("111");
    LongNumber n2 = std::move(n);
    EXPECT_EQ(n.getString(), "0");
    EXPECT_EQ(n2.getString(), "111");
}

TEST(Lesnikov_Nikita_LongNumber, CopyOperator) {
    LongNumber n("111");
    LongNumber n2("112");
    n2 = n;
    EXPECT_EQ(n.getString(), n2.getString());
}

TEST(Lesnikov_Nikita_LongNumber, MoveOperator) {
    LongNumber n("111");
    LongNumber n2("112");
    n2 = std::move(n);
    EXPECT_EQ(n.getString(), "0");
    EXPECT_EQ(n2.getString(), "111");
}

TEST(Lesnikov_Nikita_LongNumber, Comparing) {
    LongNumber n("10");
    LongNumber n2("10");
    LongNumber n3("11");
    EXPECT_EQ(n, n2);
    EXPECT_NE(n, n3);
}

TEST(Lesnikov_Nikita_LongNumber, ComparingLess) {
    LongNumber n("-2");
    LongNumber n2("0");
    LongNumber n3("10");
    LongNumber n4("10");
    EXPECT_TRUE(n < n2);
    EXPECT_TRUE(n2 < n3);
    EXPECT_FALSE(n2 < n);
    EXPECT_FALSE(n3 < n);
    EXPECT_FALSE(n3 < n4);
}

TEST(Lesnikov_Nikita_LongNumber, ComparingGreater) {
    LongNumber n("-2");
    LongNumber n2("0");
    LongNumber n3("10");
    LongNumber n4("10");
    EXPECT_FALSE(n > n2);
    EXPECT_FALSE(n2 > n3);
    EXPECT_TRUE(n2 > n);
    EXPECT_TRUE(n3 > n);
    EXPECT_FALSE(n3 > n4);
}

TEST(Lesnikov_Nikita_LongNumber, ComparingLessEqual) {
    LongNumber n("-2");
    LongNumber n2("0");
    LongNumber n3("10");
    LongNumber n4("10");
    EXPECT_TRUE(n <= n2);
    EXPECT_TRUE(n2 <= n3);
    EXPECT_FALSE(n2 <= n);
    EXPECT_FALSE(n3 <= n);
    EXPECT_TRUE(n3 <= n4);
}

TEST(Lesnikov_Nikita_LongNumber, ComparingGreaterEqual) {
    LongNumber n("-2");
    LongNumber n2("0");
    LongNumber n3("10");
    LongNumber n4("10");
    EXPECT_FALSE(n >= n2);
    EXPECT_FALSE(n2 >= n3);
    EXPECT_TRUE(n2 >= n);
    EXPECT_TRUE(n3 >= n);
    EXPECT_TRUE(n3 >= n4);
}

TEST(Lesnikov_Nikita_LongNumber, UnaryMinus) {
    LongNumber n("-2");
    LongNumber n2 = -n;
    EXPECT_EQ(n2.getString(), "2");
}

TEST(Lesnikov_Nikita_LongNumber, AdditionSmallNumbers) {
    LongNumber n("0");
    LongNumber n2("1");
    LongNumber n3("2");
    LongNumber n4("-1");
    LongNumber n5("16");
    EXPECT_EQ((n + n2).getString(), "1");
    EXPECT_EQ((n + n4).getString(), "-1");
    EXPECT_EQ((n2 + n4).getString(), "0");
    EXPECT_EQ((n2 + n3).getString(), "3");
    EXPECT_EQ((n4 + n5).getString(), "15");
}

TEST(Lesnikov_Nikita_LongNumber, AdditionBigNumbers) {
    LongNumber n("12334231");
    LongNumber n2("-3423322332");
    LongNumber n3("74665434424");
    EXPECT_EQ((n + n2).getString(), "-3410988101");
    EXPECT_EQ((n + n3).getString(), "74677768655");
}

TEST(Lesnikov_Nikita_LongNumber, SubSmallNumbers) {
    LongNumber n("0");
    LongNumber n2("1");
    LongNumber n3("2");
    LongNumber n4("-1");
    LongNumber n5("16");
    LongNumber ns = n4 - n5;
    std::string s = ns.getString();
    EXPECT_EQ((n - n2).getString(), "-1");
    EXPECT_EQ((n - n4).getString(), "1");
    EXPECT_EQ((n2 - n4).getString(), "2");
    EXPECT_EQ((n2 - n3).getString(), "-1");
    EXPECT_EQ((n4 - n5).getString(), "-17");
}

TEST(Lesnikov_Nikita_LongNumber, SubBigNumbers) {
    LongNumber n("12334231");
    LongNumber n2("-3423322332");
    LongNumber n3("74665434424");
    EXPECT_EQ((n - n2).getString(), "3435656563");
    EXPECT_EQ((n - n3).getString(), "-74653100193");
}

TEST(Lesnikov_Nikita_LongNumber, MultSmallNumbers) {
    LongNumber n("0");
    LongNumber n2("10");
    LongNumber n3("-8");
    LongNumber n4("7");
    LongNumber n5("1");
    EXPECT_EQ((n * n2).getString(), "0");
    EXPECT_EQ((n2 * n2).getString(), "100");
    EXPECT_EQ((n3 * n4).getString(), "-56");
    EXPECT_EQ((n4 * n5).getString(), "7");
    EXPECT_EQ((n3 * n3).getString(), "64");
}

TEST(Lesnikov_Nikita_LongNumber, MultBigNumbers) {
    LongNumber n("35263541423");
    LongNumber n2("-66355342332");
    LongNumber n3("939393993939");
    EXPECT_EQ((n * n2).getString(), "-2339924362961827418436");
    EXPECT_EQ((n * n3).getString(), "33126359017785337435197");
}

TEST(Lesnikov_Nikita_LongNumber, AddToSelf) {
    LongNumber n("1");
    LongNumber n2("-1");
    LongNumber n3("100");
    EXPECT_EQ((n += n2).getString(), "0");
    EXPECT_EQ((n += n3).getString(), "100");
}

TEST(Lesnikov_Nikita_LongNumber, SubSelf) {
    LongNumber n("1");
    LongNumber n2("-1");
    LongNumber n3("100");
    EXPECT_EQ((n -= n2).getString(), "2");
    EXPECT_EQ((n -= n3).getString(), "-98");
}

TEST(Lesnikov_Nikita_LongNumber, MultSelf) {
    LongNumber n("1");
    LongNumber n2("-1");
    LongNumber n3("100");
    EXPECT_EQ((n *= n2).getString(), "-1");
    EXPECT_EQ((n *= n3).getString(), "-100");
}

TEST(Lesnikov_Nikita_LongNumber, EmptyString) {
    LongNumber n("");
    EXPECT_EQ(n.getString(), "0");
}

TEST(Lesnikov_Nikita_LongNumber, SumNegative) {
    LongNumber n1("-1");
    LongNumber n2("-1");
    LongNumber n3 = n1 + n2;
    EXPECT_EQ(n3.getString(), "-2");
}

TEST(Lesnikov_Nikita_LongNumber, SumFirstBigger) {
    LongNumber n1("100");
    LongNumber n2("1");
    LongNumber n3 = n1 + n2;
    EXPECT_EQ(n3.getString(), "101");
}

TEST(Lesnikov_Nikita_LongNumber, MultNegative) {
    LongNumber n1("-2");
    LongNumber n2("-3");
    LongNumber n3 = n1 * n2;
    EXPECT_EQ(n3.getString(), "6");
}

TEST(Lesnikov_Nikita_LongNumber, MultNegativeFirstAbsBigger) {
    LongNumber n1("-3");
    LongNumber n2("-2");
    LongNumber n3 = n1 * n2;
    EXPECT_EQ(n3.getString(), "6");
}

TEST(Lesnikov_Nikita_LongNumber, ComparingNegatives) {
    LongNumber n1("-3");
    LongNumber n2("-2");
    EXPECT_LT(n1, n2);
}

TEST(Lesnikov_Nikita_LongNumber, ComparingZeros) {
    LongNumber n1("");
    LongNumber n2("");
    EXPECT_FALSE(n1 < n2);
}

TEST(Lesnikov_Nikita_LongNumber, AbsIsGreater) {
    LongNumber n1("-1000");
    LongNumber n2("10");
    EXPECT_TRUE(n1.absIsGreater(n2));
    EXPECT_FALSE(n2.absIsGreater(n1));
}

TEST(Lesnikov_Nikita_LongNumber, AbsIsGreaterNumberDigitsEqual) {
    LongNumber n1("101");
    LongNumber n2("100");
    EXPECT_TRUE(n1.absIsGreater(n2));
    EXPECT_FALSE(n2.absIsGreater(n1));
}

TEST(Lesnikov_Nikita_LongNumber, SubNegative) {
    LongNumber n1("-2");
    LongNumber n2("-3");
    LongNumber n3 = n1 - n2;
    EXPECT_EQ(n3.getString(), "1");
}

TEST(Lesnikov_Nikita_LongNumber, SubNegativeFirstAbsBigger) {
    LongNumber n1("-3");
    LongNumber n2("-2");
    LongNumber n3 = n1 - n2;
    EXPECT_EQ(n3.getString(), "-1");
}

TEST(Lesnikov_Nikita_LongNumber, AbsIsGreaterEqual) {
    LongNumber n1("333");
    LongNumber n2("333");
    EXPECT_FALSE(n1.absIsGreater(n2));
}

TEST(Lesnikov_Nikita_LongNumber, AbsIsLessEqual) {
    LongNumber n1("333");
    LongNumber n2("333");
    EXPECT_FALSE(n2.absIsGreater(n1));
}
