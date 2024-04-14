// Copyright 2024 Tushentsova Karina

#include <gtest/gtest.h>
#include "include/permut_generator.h"


TEST(Tushentsova_Karina_Permut_Generator, CanGetArrCertainLength) {
    int a[] = { 1, 2, 3 };
    ASSERT_NO_THROW(PermutGenerator arr(a, 3), std::string);
}

TEST(Tushentsova_Karina_Permut_Generator, CanGetArrInvalidValue) {
    int a[] = { 1, 2, 3 };
    ASSERT_THROW(PermutGenerator arr(a, 0), std::string);
    ASSERT_THROW(PermutGenerator arr(a, -3), std::string);
    int* p = NULL;
    ASSERT_THROW(PermutGenerator arr(p, 3), std::string);
}
