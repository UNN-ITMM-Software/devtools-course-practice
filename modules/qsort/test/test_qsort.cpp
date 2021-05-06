// Copyright 2021 Taktaev Artem
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "include/qsort.h"

TEST(QSort_Test, Test_Creating_Vector_Exception) {
    ASSERT_ANY_THROW(QSort::createRandomVector(-1));
}

TEST(QSort_Test, Test_Out_Of_Bounds_Exception) {
    int n = 11;
    std::vector<double> vec = QSort::createRandomVector(n);
    ASSERT_ANY_THROW(QSort::Sort(&vec, -1, n));
}

TEST(QSort_Test, Test_Index_Overlap_Exception) {
    int n = 10;
    std::vector<double> vec = QSort::createRandomVector(n);
    ASSERT_ANY_THROW(QSort::Sort(&vec, n - 1, 0));
}

TEST(QSort_Test, Test_Correct_Creating_Vector) {
    int n = 10;
    std::vector<double> vec(n);
    ASSERT_NO_THROW(vec = QSort::createRandomVector(n));
}

TEST(QSort_Test, Test_Correct_Sorting_Rand_Even_Size_Vec) {
    int n = 10;
    std::vector<double> vec = QSort::createRandomVector(n);
    std::vector<double> vec_copy = vec;
    QSort::Sort(&vec, 0, n - 1);
    std::sort(vec_copy.begin(), vec_copy.end());
    ASSERT_EQ(vec_copy, vec);
}

TEST(QSort_Test, Test_Correct_Sorting_Rand_Odd_Vec) {
    int n = 11;
    std::vector<double> vec = QSort::createRandomVector(n);
    std::vector<double> vec_copy = vec;
    QSort::Sort(&vec, 0, n - 1);
    std::sort(vec_copy.begin(), vec_copy.end());
    ASSERT_EQ(vec_copy, vec);
}

TEST(QSort_Test, Test_Correct_Sorting_Sorted_Vec) {
    int n = 15;
    std::vector<double> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = i;
    }
    std::vector<double> vec_copy = vec;
    QSort::Sort(&vec, 0, n - 1);
    std::sort(vec_copy.begin(), vec_copy.end());
    ASSERT_EQ(vec_copy, vec);
}

TEST(QSort_Test, Test_Correct_Sorting_Reverse_Sorted_Vec) {
    int n = 12;
    std::vector<double> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = n - i;
    }
    std::vector<double> vec_copy = vec;
    QSort::Sort(&vec, 0, n - 1);
    std::sort(vec_copy.begin(), vec_copy.end());
    ASSERT_EQ(vec_copy, vec);
}

TEST(QSort_Test, Test_Correct_Sorting_Eq_Elements_Vec) {
    int n = 18;
    std::vector<double> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = 1;
    }
    std::vector<double> vec_copy = vec;
    QSort::Sort(&vec, 0, n - 1);
    std::sort(vec_copy.begin(), vec_copy.end());
    ASSERT_EQ(vec_copy, vec);
}
