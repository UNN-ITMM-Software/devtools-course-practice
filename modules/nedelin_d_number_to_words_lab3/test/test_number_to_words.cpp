// Copyright 2024 Nedelin Dmitry

#include <gtest/gtest.h>
#include <climits>

#include "include/number_to_words.h"
#include "include/number_to_wordsApp.h"

TEST(NumberToWordsTest, ConvertZero) {
    NumberToWords converter;
    ASSERT_EQ(converter.convert(0), "zero");
}

TEST(NumberToWordsTest, ConvertPositiveNumbers) {
    NumberToWords converter;
    ASSERT_EQ(converter.convert(1), "one");
    ASSERT_EQ(converter.convert(12), "twelve");
    ASSERT_EQ(converter.convert(123), "one hundred twenty three");
    ASSERT_EQ(converter.convert(1234),
        "one thousand two hundred thirty four");
    ASSERT_EQ(converter.convert(1234567),
        "one million two hundred thirty four thousand "
        "five hundred sixty seven");
}

TEST(NumberToWordsTest, ConvertNegativeNumbers) {
    NumberToWords converter;
    ASSERT_EQ(converter.convert(-1), "negative one");
    ASSERT_EQ(converter.convert(-12), "negative twelve");
    ASSERT_EQ(converter.convert(-123), "negative one hundred twenty three");
}

TEST(NumberToWordsTest, ConvertLargeNumbers) {
    NumberToWords converter;
    ASSERT_EQ(converter.convert(1000000000), "one billion");
    ASSERT_EQ(converter.convert(1172839450),
        "one billion one hundred seventy two million eight hundred "
        "thirty nine thousand four hundred fifty");
}

TEST(NumberToWordsTest, ConvertNegativeLargeNumbers) {
    NumberToWords converter;
    ASSERT_EQ(converter.convert(-1000000000), "negative one billion");
    ASSERT_EQ(converter.convert(-1172839450),
        "negative one billion one hundred seventy two million "
        "eight hundred thirty nine thousand four hundred fifty");
}

TEST(NumberToWordsTest, ConvertEdgeCases) {
    NumberToWords converter;
    ASSERT_EQ(converter.convert(0), "zero");
    ASSERT_EQ(converter.convert(INT_MAX),
        "two billion one hundred forty seven million four hundred "
        "eighty three thousand six hundred forty seven");
    ASSERT_EQ(converter.convert(INT_MIN),
        "negative two billion one hundred forty seven million four "
        "hundred eighty three thousand six hundred forty eight");
}

TEST(NumberToWordsTest, ConvertTensAndUnits) {
    NumberToWords converter;
    ASSERT_EQ(converter.convert(20), "twenty");
    ASSERT_EQ(converter.convert(99), "ninety nine");
    ASSERT_EQ(converter.convert(101), "one hundred one");
    ASSERT_EQ(converter.convert(111), "one hundred eleven");
}

TEST(ApplicationTest, ValidInput_PositiveNumber) {
    Application app;
    const char* argv[] = { "app", "123" };
    auto output = app.runApp(2, argv);
    ASSERT_EQ(output.size(), 1);
    EXPECT_EQ(output[0], "one hundred twenty three");
}

TEST(ApplicationTest, ValidInput_NegativeNumber) {
    Application app;
    const char* argv[] = { "app", "-456" };
    auto output = app.runApp(2, argv);
    ASSERT_EQ(output.size(), 1);
    EXPECT_EQ(output[0], "negative four hundred fifty six");
}

TEST(ApplicationTest, InvalidInput_NonNumeric) {
    Application app;
    const char* argv[] = { "app", "abc" };
    auto output = app.runApp(2, argv);
    ASSERT_EQ(output.size(), 1);
    EXPECT_EQ(output[0], "Invalid number format!");
}

TEST(ApplicationTest, MissingArgument) {
    Application app;
    const char* argv[] = { "app" };
    auto output = app.runApp(1, argv);
    ASSERT_EQ(output.size(), 1);
    EXPECT_EQ(output[0], "Usage: number_to_words <number>");
}

TEST(ApplicationTest, Boundary_MinInt) {
    Application app;
    const char* argv[] = { "app", "-2147483648" };
    auto output = app.runApp(2, argv);
    ASSERT_EQ(output.size(), 1);
    EXPECT_EQ(output[0],
        "negative two billion one hundred forty seven million four "
        "hundred eighty three thousand six hundred forty eight");
}

TEST(ApplicationTest, Boundary_MaxInt) {
    Application app;
    const char* argv[] = { "app", "2147483647" };
    auto output = app.runApp(2, argv);
    ASSERT_EQ(output.size(), 1);
    EXPECT_EQ(output[0],
        "two billion one hundred forty seven million four hundred "
        "eighty three thousand six hundred forty seven");
}
