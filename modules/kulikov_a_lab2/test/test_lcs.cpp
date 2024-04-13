// Copyright 2024 Kulikov Artem

#include <gtest/gtest.h>

#include "include/lcs.h"

TEST(LCSTest, EmptyStrings) {
    std::string str1 = "";
    std::string str2 = "";
    ASSERT_EQ("", LCS::findLCS(str1, str2));
}

TEST(LCSTest, SameStrings) {
    std::string str1 = "abc";
    std::string str2 = "abc";
    ASSERT_EQ("abc", LCS::findLCS(str1, str2));
}

TEST(LCSTest, DifferentLengthStrings) {
    std::string str1 = "abcd";
    std::string str2 = "abc";
    ASSERT_EQ("abc", LCS::findLCS(str1, str2));
}

TEST(LCSTest, CommonSubstring) {
    std::string str1 = "abcd";
    std::string str2 = "xbcde";
    ASSERT_EQ("bcd", LCS::findLCS(str1, str2));
}

TEST(LCSTest, NoCommonSubstring) {
    std::string str1 = "abc";
    std::string str2 = "def";
    ASSERT_EQ("", LCS::findLCS(str1, str2));
}

TEST(LCSTest, ComplexStrings) {
    std::string str1 = "AGGTAB";
    std::string str2 = "GXTXAYB";
    ASSERT_EQ("GTAB", LCS::findLCS(str1, str2));
}
