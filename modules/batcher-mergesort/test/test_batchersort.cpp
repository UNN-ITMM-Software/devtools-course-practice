// Copyright 2021 Solovev Alexandr
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "include/mergesort.h"

TEST(Batcher_Merge_Sort_Test, Test_Creating_Vector_Exception) {
    ASSERT_ANY_THROW(MergeSort::createRandomVector(-1));
}

TEST(Batcher_Merge_Sort_Test, Test_Creating_Odd_Vector_Exception) {
    ASSERT_ANY_THROW(MergeSort::createRandomVector(11));
}

TEST(Batcher_Merge_Sort_Test, Test_Correct_Creating_Vector) {
    size_t n = 10;
    std::vector<double> vec(n);
    ASSERT_NO_THROW(vec = MergeSort::createRandomVector(n));
}

TEST(Batcher_Merge_Sort_Test, Test_Correct_Sorting_Small_Vector) {
    size_t n = 16;
    std::vector<double> vec = MergeSort::createRandomVector(n);
    std::vector<double> vec_copy = vec;
    MergeSort::OddEvenMergeSort(&vec, 0, n - 1);
    std::sort(vec_copy.begin(), vec_copy.end());
    ASSERT_EQ(vec_copy, vec);
}

TEST(Batcher_Merge_Sort_Test, Test_Correct_Sorting_Medium_Vector) {
    size_t n = 256;
    std::vector<double> vec = MergeSort::createRandomVector(n);
    std::vector<double> vec_copy = vec;
    MergeSort::OddEvenMergeSort(&vec, 0, n - 1);
    std::sort(vec_copy.begin(), vec_copy.end());
    ASSERT_EQ(vec_copy, vec);
}

TEST(Batcher_Merge_Sort_Test, Test_Correct_Sorting_Sorted_Vec) {
    size_t n = 32;
    std::vector<double> vec(n);
    for (size_t i = 0; i < n; i++) {
        vec[i] = i;
    }
    std::vector<double> vec_copy = vec;
    MergeSort::OddEvenMergeSort(&vec, 0, n - 1);
    std::sort(vec_copy.begin(), vec_copy.end());
    ASSERT_EQ(vec_copy, vec);
}

TEST(Batcher_Merge_Sort_Test, Test_Sorting_Reverse_Sorted_Vec) {
    size_t n = 128;
    std::vector<double> vec(n);
    for (size_t i = 0; i < n; i++) {
        vec[i] = n - i;
    }
    std::vector<double> vec_copy = vec;
    MergeSort::OddEvenMergeSort(&vec, 0, n - 1);
    std::sort(vec_copy.begin(), vec_copy.end());
    ASSERT_EQ(vec_copy, vec);
}

TEST(Batcher_Merge_Sort_Test, Test_Correct_Sorting_Equal_Elements) {
    size_t n = 64;
    std::vector<double> vec(n);
    for (size_t i = 0; i < n; i++) {
        vec[i] = 1;
    }
    std::vector<double> vec_copy = vec;
    MergeSort::OddEvenMergeSort(&vec, 0, n - 1);
    std::sort(vec_copy.begin(), vec_copy.end());
    ASSERT_EQ(vec_copy, vec);
}
