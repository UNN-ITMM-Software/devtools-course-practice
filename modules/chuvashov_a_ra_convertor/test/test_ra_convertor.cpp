// Copyright 2024 Chuvashov Andrey

#include "../../../3rdparty/gtest/gtest.h"
#include "../include/ra_convertor.h"

static Convertor cnvrtr = Convertor::Convertor();

TEST(ChuvashovAndreyTests, ArabicToRomanCheckZero) {
    EXPECT_THROW(cnvrtr.ArabicToRoman(0), std::invalid_argument);
}

TEST(ChuvashovAndreyTests, ArabicToRomanCheckNegative) {
    EXPECT_THROW(cnvrtr.ArabicToRoman(-1'000'000), std::invalid_argument);
}

TEST(ChuvashovAndreyTests, ArabicToRomanCheckSmall) {
    EXPECT_EQ(cnvrtr.ArabicToRoman(1994), "MCMXCIV");
}

TEST(ChuvashovAndreyTests, ArabicToRomanCheckHuge) {
    EXPECT_EQ(cnvrtr.ArabicToRoman(10045), "MMMMMMMMMMXLV");
}

TEST(ChuvashovAndreyTests, ArabicToRomanCheckTooHugeForThat) {
    EXPECT_THROW(cnvrtr.ArabicToRoman(10'000'000'000), std::invalid_argument);
}

TEST(ChuvashovAndreyTests, RomanToArabicCheckZeroLength) {
    EXPECT_THROW(cnvrtr.RomanToArabic(""), std::invalid_argument);
}

TEST(ChuvashovAndreyTests, RomanToArabicCheckInvalid) {
    EXPECT_THROW(cnvrtr.RomanToArabic("IIVCM"), std::invalid_argument);
}

TEST(ChuvashovAndreyTests, RomanToArabicCheckSmall) {
    EXPECT_EQ(cnvrtr.RomanToArabic("XI"), 11);
}

TEST(ChuvashovAndreyTests, RomanToArabicCheckHuge) {
    EXPECT_EQ(cnvrtr.RomanToArabic("MXXVI"), 1026);
}

TEST(ChuvashovAndreyTests, RomanToArabicCheckTooHugeForThat) {
    EXPECT_THROW(cnvrtr.RomanToArabic("MMMXMXXXMMXMXXMM"),
        std::invalid_argument);
}
