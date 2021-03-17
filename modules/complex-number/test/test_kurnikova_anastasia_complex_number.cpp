// Copyright 2021 Kurnikova Anastasia

#include <gtest/gtest.h>

#include <limits>

#include "include/complex_number.h"

TEST(Kurnikova_Anastasia_ComplexNumberTest, can_create_with_min_max) {
    double re = std::numeric_limits<double>::min();
    double im = std::numeric_limits<double>::max();
    ASSERT_NO_THROW(ComplexNumber a(re, im));
}

TEST(Kurnikova_Anastasia_ComplexNumberTest, can_create_with_infinity) {
    double re = std::numeric_limits<double>::infinity();
    double im = std::numeric_limits<double>::infinity();
    ASSERT_NO_THROW(ComplexNumber a(re, im));
}

TEST(Kurnikova_Anastasia_ComplexNumberTest, can_compare_zeroes) {
    double re = 0.0;
    double im = 0.0;
    ComplexNumber a(re, im);
    ComplexNumber b(0.0, 0.0);
    ASSERT_FALSE(a != b);
}
