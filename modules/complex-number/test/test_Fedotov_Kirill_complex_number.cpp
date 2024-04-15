// Copyright 2024 Fedotov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Fedotov_Kirill_ComplexNumberTest, defaultConstruct) {
    ComplexNumber z(re, im);

    ASSERT_EQ(0.0, z.getRe());
    ASSERT_EQ(0.0, z.getIm());
}