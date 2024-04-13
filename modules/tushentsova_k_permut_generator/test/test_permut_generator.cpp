// Copyright 2024 Tushentsova Karina

#include <gtest/gtest.h>
#include "include/permut_generator.h"


TEST(Tushentsova_Karina_Permut_Generator, CanGetArrCertainLength) {
    int a[] = { 1, 2, 3 };
    ASSERT_THROW(PermutGenerator arr(a, 0), std::string);
    ASSERT_THROW(PermutGenerator arr(a, -3), std::string);
    ASSERT_NO_THROW(PermutGenerator arr(a, 3), std::string);
}

TEST(Tushentsova_Karina_Permut_Generator, CanPrintArray) {
    int const size = 3;
    int a[] = { 1, 2, 3 };

    PermutGenerator arr(a, size);

    EXPECT_EQ("123", arr.PrintArray());
}

TEST(Tushentsova_Karina_Permut_Generator, CanCreateSerialArray) {
    int const size1 = 3, size2 = 5;
    int a1[size1] = { 0 };
    int a2[size2] = { 0 };
    PermutGenerator arr1(a1, size1);
    PermutGenerator arr2(a2, size2);

    arr1.CreateArray();
    arr2.CreateArray();

    EXPECT_EQ("012", arr1.PrintArray());
    EXPECT_EQ("01234", arr2.PrintArray());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithoutRepetitions1) {
    int const size = 2;
    int a[size] = { 0 };
    PermutGenerator arr(a, size);

    arr.CreateArray();

    EXPECT_EQ("01 10", arr.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithoutRepetitions2) {
    int const size = 3;
    int a[size] = { 0 };
    PermutGenerator arr(a, size);

    arr.CreateArray();

    EXPECT_EQ("012 021 102 120 201 210", arr.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithRepetitions1) {
    int const size = 2;
    int a[size] = { 1, 1 };
    PermutGenerator arr(a, size);

    EXPECT_EQ("11", arr.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithRepetitions2) {
    int const size = 3;
    int a[size] = { 1, 1, 2 };
    PermutGenerator arr(a, size);

    EXPECT_EQ("112 121 211", arr.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithRepetitions3) {
    int const size = 4;
    int a[size] = { 1, 1, 2, 2};
    PermutGenerator arr(a, size);

    EXPECT_EQ("1122 1212 1221 2112 2121 2211", arr.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutUnsortedArray) {
    int const size = 3;
    int a[size] = { 2, 0, 1 };
    PermutGenerator arr(a, size);

    EXPECT_EQ("012 021 102 120 201 210", arr.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanNegativeValues) {
    int const size = 3;
    int a[size] = { -1, -1, -2 };
    PermutGenerator arr(a, size);

    EXPECT_EQ("-2-1-1 -1-2-1 -1-1-2", arr.GeneratorPermut());
}
