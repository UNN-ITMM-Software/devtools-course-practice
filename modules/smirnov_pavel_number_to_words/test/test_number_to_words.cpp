// Copyright 2024 Smirnov Pavel

#include <gtest/gtest.h>

#include "include/number_to_words.h"

TEST(NumberToWordsTest, ConvertZero) {
    NumberToWords converter;
    ASSERT_EQ(converter.convert(0), "zero");
}

TEST(NumberToWordsTest, ConvertPositiveNumbers) {
    NumberToWords converter;
    ASSERT_EQ(converter.convert(1), "one");
    ASSERT_EQ(converter.convert(12), "twelve");
    ASSERT_EQ(converter.convert(123), "one hundred twenty three");
    ASSERT_EQ(converter.convert(1234), "one thousand two hundred thirty four");
    ASSERT_EQ(converter.convert(1234567),
    "one million two hundred thirty four thousand five hundred sixty seven");
}

TEST(NumberToWordsTest, ConvertNegativeNumbers) {
    NumberToWords converter;
    ASSERT_EQ(converter.convert(-1), "negative one");
    ASSERT_EQ(converter.convert(-12), "negative twelve");
    ASSERT_EQ(converter.convert(-123), "negative one hundred twenty three");
}

