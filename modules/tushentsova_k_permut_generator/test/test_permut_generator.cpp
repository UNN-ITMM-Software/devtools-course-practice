// Copyright 2024 Tushentsova Karina

#include <gtest/gtest.h>
#include "include/permut_generator.h"

TEST(Tushentsova_Karina_Permut_Generator, CanGetArrCertainLength) {
    int a[] { 1, 2, 3 };
    ASSERT_NO_THROW(PermutGenerator arr(a, 3));
}

TEST(Tushentsova_Karina_Permut_Generator, CanGetArrInvalidValue) {
    int a[] { 1, 2, 3 };
    ASSERT_ANY_THROW(PermutGenerator arr(a, 0));
    ASSERT_ANY_THROW(PermutGenerator arr(a, -3));
    int* p = NULL;
    ASSERT_ANY_THROW(PermutGenerator arr(p, 3));
}


TEST(Tushentsova_Karina_Permut_Generator, CanPrintArray) {
    int const size = 3;
    int a1[] { 1, 1, 1 }, a2[] { 1, 2, 3 };

    PermutGenerator arr1(a1, size);
    PermutGenerator arr2(a2, size);

    EXPECT_EQ("111", arr1.PrintArray());
    EXPECT_EQ("123", arr2.PrintArray());
}

TEST(Tushentsova_Karina_Permut_Generator, CanCreateSerialArray) {
    int const size = 5;
    int a[size] { 0 };
    PermutGenerator arr(a, size);
    arr.CreateArray();

    for (int i = 0; i < size; i++)
        EXPECT_EQ(a[i], i);
}

TEST(Tushentsova_Karina_Permut_Generator, CanSwap) {
    int const size = 2;
    int a[size] { 0, 1 };
    PermutGenerator arr(a, size);

    EXPECT_NO_THROW(arr.Swap(0, 1));
    ASSERT_ANY_THROW(arr.Swap(-1, 1));
    ASSERT_ANY_THROW(arr.Swap(0, 3));

    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 0);
}

TEST(Tushentsova_Karina_Permut_Generator, CanGetNextSet) {
    int const size = 3;
    int a[size] { 0, 1, 2};
    PermutGenerator arr(a, size);

    EXPECT_TRUE(arr.NextSet());
    EXPECT_EQ(a[0], 0);
    EXPECT_EQ(a[1], 2);
    EXPECT_EQ(a[2], 1);
}

TEST(Tushentsova_Karina_Permut_Generator, CanBubbleSort) {
    int const size = 3;
    int a[size] { 2, 0, 1 };
    PermutGenerator arr(a, size);

    EXPECT_TRUE(arr.BubbleSort());
    EXPECT_EQ("012", arr.PrintArray());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithoutRepetitions) {
    int const size1 = 2, size2 = 3;
    int a1[size1] { 0 }, a2[size2] { 0 };
    PermutGenerator arr1(a1, size1);
    PermutGenerator arr2(a2, size2);

    arr1.CreateArray();
    arr2.CreateArray();

    EXPECT_EQ("01 10", arr1.GeneratorPermut());
    EXPECT_EQ("012 021 102 120 201 210", arr2.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutWithRepetitions) {
    int const size1 = 2, size2 = 3, size3 = 4;
    int a1[size1] { 1, 1 },
        a2[size2] { 1, 1, 2 },
        a3[size3] { 1, 1, 2, 2 };
    PermutGenerator arr1(a1, size1);
    PermutGenerator arr2(a2, size2);
    PermutGenerator arr3(a3, size3);

    EXPECT_EQ("11", arr1.GeneratorPermut());
    EXPECT_EQ("112 121 211", arr2.GeneratorPermut());
    EXPECT_EQ("1122 1212 1221 2112 2121 2211", arr3.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutUnsortedArray) {
    int const size1 = 2, size2 = 3;
    int a1[size1] { 2, 0 },
        a2[size2] { 2, 0, 1 };
    PermutGenerator arr1(a1, size1);
    PermutGenerator arr2(a2, size2);

    EXPECT_EQ("02 20", arr1.GeneratorPermut());
    EXPECT_EQ("012 021 102 120 201 210", arr2.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutNegativeValues) {
    int const size1 = 2, size2 = 3;
    int a1[size1] { -1, -2 },
        a2[size2] { -1, -1, -2 };
    PermutGenerator arr1(a1, size1);
    PermutGenerator arr2(a2, size2);

    EXPECT_EQ("-2-1 -1-2", arr1.GeneratorPermut());
    EXPECT_EQ("-2-1-1 -1-2-1 -1-1-2", arr2.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutOneValue) {
    int const size1 = 1, size2 = 1;
    int a1[size1] { -1 },
        a2[size2] { 1 };
    PermutGenerator arr1(a1, size1);
    PermutGenerator arr2(a2, size2);

    EXPECT_EQ("-1", arr1.GeneratorPermut());
    EXPECT_EQ("1", arr2.GeneratorPermut());
}

TEST(Tushentsova_Karina_Permut_Generator, CanPermutDifferentValues) {
    int const size1 = 2, size2 = 3;
    int a1[size1] { 1, -2 },
        a2[size2] { -1, -1, 2 };
    PermutGenerator arr1(a1, size1);
    PermutGenerator arr2(a2, size2);

    EXPECT_EQ("-21 1-2", arr1.GeneratorPermut());
    EXPECT_EQ("-1-12 -12-1 2-1-1", arr2.GeneratorPermut());
}
