// Copyright 2024 Chuvashov Andrey

#include "../../../3rdparty/gtest/gtest.h"
#include "../include/ra_convertor.h"

static Convertor cnvrtr;

TEST(ChuvashovAndreyTests, ArabicToRomanCheckZero) {
    EXPECT_ANY_THROW(cnvrtr.ArabicToRoman(0));
}

TEST(ChuvashovAndreyTests, ArabicToRomanCheckNegative) {
    EXPECT_ANY_THROW(cnvrtr.ArabicToRoman(-1000000));
}

TEST(ChuvashovAndreyTests, ArabicToRomanCheckSmall) {
    EXPECT_EQ(cnvrtr.ArabicToRoman(1994), "MCMXCIV");
}

TEST(ChuvashovAndreyTests, ArabicToRomanCheckHuge) {
    EXPECT_EQ(cnvrtr.ArabicToRoman(10045), "MMMMMMMMMMXLV");
}

TEST(ChuvashovAndreyTests, ArabicToRomanCheckTooHugeForThat) {
    EXPECT_ANY_THROW(cnvrtr.ArabicToRoman(2000000000));
}

TEST(ChuvashovAndreyTests, RomanToArabicCheckZeroLength) {
    EXPECT_ANY_THROW(cnvrtr.RomanToArabic(""));
}

TEST(ChuvashovAndreyTests, RomanToArabicCheckInvalid) {
    EXPECT_ANY_THROW(cnvrtr.RomanToArabic("IIVCM"));
}

TEST(ChuvashovAndreyTests, RomanToArabicCheckSmall) {
    EXPECT_EQ(cnvrtr.RomanToArabic("XI"), 11);
}

TEST(ChuvashovAndreyTests, RomanToArabicCheckHuge) {
    EXPECT_EQ(cnvrtr.RomanToArabic("MXXVI"), 1026);
}

TEST(ChuvashovAndreyTests, RomanToArabicCheckTooHugeForThat) {
    EXPECT_ANY_THROW(cnvrtr.RomanToArabic("MMMXMXXXMMXMXXMM"));
}
