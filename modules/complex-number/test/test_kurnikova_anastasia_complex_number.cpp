// Copyright 2021 Kurnikova Anastasia

#include <gtest/gtest.h>
#include <limits>
#include "include/complex_number.h"

TEST(Kurnikova_Anastasia_ComplexNumberTest, can_create_with_min_max) {
    double re = std::numeric_limits<double>::min();
    double im = std::numeric_limits<double>::max();
    EXPECT_NO_THROW(ComplexNumber a(re, im));
}

TEST(Kurnikova_Anastasia_ComplexNumberTest, can_create_with_infinity) {
    EXPECT_NO_THROW(ComplexNumber a(std::numeric_limits<double>::infinity(),
                             std::numeric_limits<double>::infinity()));
}

TEST(Kurnikova_Anastasia_ComplexNumberTest, can_compare_zeroes) {
    double re = 0.0;
    double im = 0.0;
    ComplexNumber a(re, im);
    ComplexNumber b(0.0, 0.0);
    EXPECT_EQ(0, a != b);
}
