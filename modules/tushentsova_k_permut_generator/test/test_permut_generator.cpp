// Copyright 2024 Tushentsova Karina

#include <gtest/gtest.h>
#include <iostream>
#include "include/permut_generator.h"

TEST(Tushentsova_Karina_Permut_Generator, CanCreateArrWhithoutParameters) {
    ASSERT_NO_THROW(PermutGenerator arr);
}

TEST(Tushentsova_Karina_Permut_Generator, CanGetArrCertainLength) {
    ASSERT_NO_THROW(PermutGenerator arr(3));
}

TEST(Tushentsova_Karina_Permut_Generator, CanPrintArray) {
    int const size = 3;
    int a[] = { 1, 2, 3 };
    PermutGenerator arr(size);
    EXPECT_EQ("123", arr.PrintArray(a));
}

TEST(Tushentsova_Karina_Permut_Generator, CanCreateSerialArray) {
    int const size = 3;
    int a[size] = { 0 };
    PermutGenerator arr(size);

    arr.CreateArray(a);

    EXPECT_EQ("012", arr.PrintArray(a));
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithoutRepetitions1) {
    int const size = 2;
    int a[size] = { 0 };
    PermutGenerator arr(size);

    arr.CreateArray(a);

    EXPECT_EQ("01 10", arr.GeneratorPermut(a));
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithoutRepetitions2) {
    int const size = 3;
    int a[size] = { 0 };
    PermutGenerator arr(size);

    arr.CreateArray(a);

    EXPECT_EQ("012 021 102 120 201 210", arr.GeneratorPermut(a));
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithRepetitions1) {
    int const size = 2;
    int a[size] = { 1, 1 };
    PermutGenerator arr(size);

    EXPECT_EQ("11", arr.GeneratorPermut(a));
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithRepetitions2) {
    int const size = 3;
    int a[size] = { 1, 1, 2 };
    PermutGenerator arr(size);

    EXPECT_EQ("112 121 211", arr.GeneratorPermut(a));
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithRepetitions3) {
    int const size = 4;
    int a[size] = { 1, 1, 2, 2};
    PermutGenerator arr(size);

    EXPECT_EQ("1122 1212 1221 2112 2121 2211", arr.GeneratorPermut(a));
}

