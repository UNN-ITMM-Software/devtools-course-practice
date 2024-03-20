// Copyright 2024 Chuvashov Andrey

#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"

static bool equalizer(double first, double second) {
    return std::fabs(first - second) <= 1.0e-4;
}

TEST(ChuvashovAndreyTests, getTest) {
    ComplexNumber cm = ComplexNumber(1, 2);
    ASSERT_EQ(cm.getRe(), 1);
    ASSERT_EQ(cm.getIm(), 2);
}

TEST(ChuvashovAndreyTests, setTest) {
    ComplexNumber cm;
    ASSERT_NO_THROW(cm.setRe(1));
    ASSERT_NO_THROW(cm.setIm(2));
}

TEST(ChuvashovAndreyTests, setGetTest) {
    ComplexNumber cm;
    ASSERT_NO_THROW(cm.setRe(1));
    ASSERT_NO_THROW(cm.setIm(2));
    ASSERT_EQ(cm.getRe(), 1);
    ASSERT_EQ(cm.getIm(), 2);
}

TEST(ChuvashovAndreyTests, plusTest) {
    ComplexNumber cm1(10, 20), cm2(-20, -10), result(-10, 10);
    auto res = cm1 + cm2;
    ASSERT_EQ(result.getRe(), res.getRe());
    ASSERT_EQ(result.getIm(), res.getIm());
}

TEST(ChuvashovAndreyTests, minusTest) {
    ComplexNumber cm1(35, 95), cm2(-105, 25), result(140, 70);
    auto res = cm1 - cm2;
    ASSERT_EQ(result.getRe(), res.getRe());
    ASSERT_EQ(result.getIm(), res.getIm());
}

TEST(ChuvashovAndreyTests, multTest) {
    ComplexNumber cm1(189.19, 13), cm2(419.8, 11.34),
        result(79274.542, 7602.8146);
    auto res = cm1 * cm2;
    ASSERT_TRUE(equalizer(result.getRe(), res.getRe()));
    ASSERT_TRUE(equalizer(result.getIm(), res.getIm()));
}

TEST(ChuvashovAndreyTests, divTest) {
    ComplexNumber cm1(19.11, 45), cm2(76.15, 11.34),
        result(0.3315, 0.5415);
    auto res = cm1 / cm2;
    ASSERT_TRUE(equalizer(result.getRe(), res.getRe()));
    ASSERT_TRUE(equalizer(result.getIm(), res.getIm()));
}

TEST(ChuvashovAndreyTests, zeroDivErrorCheck) {
    ASSERT_ANY_THROW(ComplexNumber(1, 1) / ComplexNumber(0, 0));
}

TEST(ChuvashovAndreyTests, equalTest) {
    ASSERT_TRUE(ComplexNumber(0.1245, 1415.125) ==
        ComplexNumber(0.1245, 1415.125));
}

TEST(ChuvashovAndreyTests, notEqualTest) {
    ASSERT_TRUE(ComplexNumber(1241.6478, 2663.22) !=
        ComplexNumber(35743.15, 37326.2));
}

TEST(ChuvashovAndreyTests, comparisonTest) {
    ComplexNumber cm1(10, 20), cm2(-10, -20);
    cm1 = cm2;
    ASSERT_EQ(cm1.getRe(), -10);
    ASSERT_EQ(cm1.getIm(), -20);
}
