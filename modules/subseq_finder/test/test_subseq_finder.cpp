// Copyright 2021 Tsvetkov Maxim

#include <gtest/gtest.h>
#include <vector>

#include "include/subseq_finder.h"

TEST(Tsvetkov_Subseq_Finder, TestNoThrow) {
    ASSERT_NO_THROW(SubseqFinder({1, 2, 3}, {2, 3}));
}

TEST(Tsvetkov_Subseq_Finder, TestObject) {
    SubseqFinder finder({1, 2, 3}, {2, 3});
    std::vector<int> result;
    finder.getMaxSubseq(&result);
    ASSERT_EQ(result, std::vector<int>({2, 3}));
}

TEST(Tsvetkov_Subseq_Finder, TestNoSubseq) {
    SubseqFinder finder({1, 2, 3}, {4, 5});
    std::vector<int> result;
    finder.getMaxSubseq(&result);
    ASSERT_EQ(result, std::vector<int>());
}

TEST(Tsvetkov_Subseq_Finder, TestMaximalSubseq) {
    SubseqFinder finder({1, 2, 3}, {1, 2, 3});
    std::vector<int> result;
    finder.getMaxSubseq(&result);
    ASSERT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST(Tsvetkov_Subseq_Finder, TestForCovSubseq1) {
    SubseqFinder finder({1, 2, 3}, {0, 1, 2, 3, 4, 5});
    std::vector<int> result;
    finder.getMaxSubseq(&result);
    ASSERT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST(Tsvetkov_Subseq_Finder, TestForCovSubseq2) {
    SubseqFinder finder({0, 1, 2, 0, 1, 2}, {0, 1, 2, 3, 4, 5});
    std::vector<int> result;
    finder.getMaxSubseq(&result);
    ASSERT_EQ(result, std::vector<int>({0, 1, 2}));
}


TEST(Tsvetkov_Subseq_Finder, TestFuncNoThrow) {
    std::vector<int> result;
    ASSERT_NO_THROW(SubseqFinder::findMaxSubseq({1, 2, 3}, {2, 3}, &result));
}

TEST(Tsvetkov_Subseq_Finder, TestFunction) {
    std::vector<int> result;
    SubseqFinder::findMaxSubseq({1, 2, 3}, {2, 3}, &result);
    ASSERT_EQ(result, std::vector<int>({2, 3}));
}

TEST(Tsvetkov_Subseq_Finder, TestFuncNoSubseq) {
    std::vector<int> result;
    SubseqFinder::findMaxSubseq({1, 2, 3}, {4, 5}, &result);
    ASSERT_EQ(result, std::vector<int>());
}

TEST(Tsvetkov_Subseq_Finder, TestFuncMaximalSubseq) {
    std::vector<int> result;
    SubseqFinder::findMaxSubseq({1, 2, 3}, {1, 2, 3}, &result);
    ASSERT_EQ(result, std::vector<int>({1, 2, 3}));
}
