// Copyright 2024 Dostavalov Semyon

#include "../../../3rdparty/gtest/gtest.h"
#include "include/KMP.h"

TEST(dostavalov_s_knuth_morris_prath, BigFind) {
    std::string text = "ABABABACABAABABACCABABCABAACABAABBBACABA";
    std::string pattern = "ABACABA";

    std::vector<int> expected = { 4 };
    std::vector<int> result = KnuthMorrisPratt::findPattern(text, pattern);

    ASSERT_EQ(expected, result);
}

TEST(dostavalov_s_knuth_morris_prath, SingleFind) {
    std::string text = "AAAAAA";
    std::string pattern = "A";

    std::vector<int> expected = { 0, 1, 2, 3, 4, 5 };
    std::vector<int> result = KnuthMorrisPratt::findPattern(text, pattern);

    ASSERT_EQ(expected, result);
}

TEST(dostavalov_s_knuth_morris_prath, NotFound) {
    std::string text = "ABCDEFG";
    std::string pattern = "XYZ";

    std::vector<int> expected = {};
    std::vector<int> result = KnuthMorrisPratt::findPattern(text, pattern);

    ASSERT_EQ(expected, result);
}

TEST(dostavalov_s_knuth_morris_prath, MultipleFind) {
    std::string text = "ABABABAB";
    std::string pattern = "ABA";

    std::vector<int> expected = { 0, 2, 4 };
    std::vector<int> result = KnuthMorrisPratt::findPattern(text, pattern);

    ASSERT_EQ(expected, result);
}

TEST(dostavalov_s_knuth_morris_prath, FindEnd) {
    std::string text = "GFADEFABC";
    std::string pattern = "ABC";

    std::vector<int> expected = { 6 };
    std::vector<int> result = KnuthMorrisPratt::findPattern(text, pattern);

    ASSERT_EQ(expected, result);
}

TEST(dostavalov_s_knuth_morris_prath, FindStart) {
    std::string text = "DEFABCABC";
    std::string pattern = "DEF";

    std::vector<int> expected = { 0 };
    std::vector<int> result = KnuthMorrisPratt::findPattern(text, pattern);

    ASSERT_EQ(expected, result);
}

TEST(KnuthMorrisPrattTest, Long) {
    std::string text = "ABC";
    std::string pattern = "ABCDEF";

    std::vector<int> expected = {};
    std::vector<int> result = KnuthMorrisPratt::findPattern(text, pattern);

    ASSERT_EQ(expected, result);
}

TEST(dostavalov_s_knuth_morris_prath, Empty) {
    std::string text = "";
    std::string pattern = "";
    std::vector<int> expected = {};
    std::vector<int> result = KnuthMorrisPratt::findPattern(text, pattern);
    ASSERT_EQ(expected, result);
}
