// Copyright 2024 Derun Andrey

#include <gtest/gtest.h>

#include "include/bisymmetric.h"


TEST(Derun_A_Bisymmetric, Default_Constructor) {
    int size = 10;
    ASSERT_NO_THROW(new BisymmetricMatrix<int>(10));
}
