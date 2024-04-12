// Copyright 2024 Tushentsova Karina

#include <gtest/gtest.h>
#include <iostream>
#include "include/permut_generator.h"

TEST(Tushentsova_Karina_Permut_Generator, CanCreateArrWhithoutParameters) {
    ASSERT_NO_THROW(PermutGenerator arr);
}

TEST(Tushentsova_Karina_Permut_Generator, CanGetArrCertainLength) {
    PermutGenerator arr(3);

    EXPECT_EQ(3, arr.GetLength());
}

TEST(Tushentsova_Karina_Permut_Generator, CanGetArrCertainLongLength) {
    PermutGenerator arr(100);

    EXPECT_EQ(100, arr.GetLength());
}

TEST(Tushentsova_Karina_Permut_Generator, CanCreateArrCertainLengthAllOnes) {
    PermutGenerator arr(3, '1');

    EXPECT_EQ("111", arr.CreateArray());
}

TEST(Tushentsova_Karina_Permut_Generator, CanCreateArrCertainLengthAllZeros) {
    PermutGenerator arr(3, '0');

    EXPECT_EQ("000", arr.CreateArray());
}
