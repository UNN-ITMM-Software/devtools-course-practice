// Copyright 2024 Zhatkin Vyacheslav

#include <gtest/gtest.h>
#include <string>
#include "include/levenshtein_distance.h"
TEST(zhatkin_v_levenshtein_distance, constructors) {
    LevenshteinDistance ld1;
    LevenshteinDistance ld2("ab", "cd");
    EXPECT_EQ("", ld1.getStr1());
    EXPECT_EQ("", ld1.getStr2());
    EXPECT_EQ("ab", ld2.getStr1());
    EXPECT_EQ("cd", ld2.getStr2());
}

TEST(zhatkin_v_levenshtein_distance, EmptyStrings) {
    LevenshteinDistance ld;
    EXPECT_EQ(0, ld.getResult());
}

TEST(zhatkin_v_levenshtein_distance, OneCharString) {
    LevenshteinDistance ld1("a", "a");
    LevenshteinDistance ld2("a", "b");
    EXPECT_EQ(0, ld1.getResult());
    EXPECT_EQ(1, ld2.getResult());
}

TEST(zhatkin_v_levenshtein_distance, DifferentLengthStrings) {
    LevenshteinDistance ld1("kitten", "sitting");
    LevenshteinDistance ld2("hello", "world");
    EXPECT_EQ(3, ld1.getResult());
    EXPECT_EQ(4, ld2.getResult());
}

TEST(zhatkin_v_levenshtein_distance, IdenticalStrings) {
    LevenshteinDistance ld1("kitten", "kitten");
    LevenshteinDistance ld2("hello", "hello");
    EXPECT_EQ(0, ld1.getResult());
    EXPECT_EQ(0, ld2.getResult());
}

TEST(zhatkin_v_levenshtein_distance, LongStrings) {
    std::string str1 = "supercalifragilisticexpialidocious";
    std::string str2 = "supercalifragilistic";
    LevenshteinDistance ld(str1, str2);
    EXPECT_EQ(14, ld.getResult());
}
