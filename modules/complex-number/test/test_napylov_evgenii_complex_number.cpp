// Copyright 2021 Evgenii Napylov

#include <gtest/gtest.h>

#include <cmath>

#include <limits>

#include "include/complex_number.h"

TEST(Napylov_Evgenii_ComplexNumberTest, Complex_number_module) {
    ComplexNumber num(3, 4);
    ComplexNumber num_conj(num.getRe(), num.getIm() * -1);
    ComplexNumber mult = num * num_conj;
    ASSERT_EQ(0, mult.getIm());
    double num_abs = std::sqrt(mult.getRe());
    double correct_abs = 5;
    ASSERT_EQ(correct_abs, num_abs);
}

TEST(Napylov_Evgenii_ComplexNumberTest, Imaginary_unit_square) {
    ComplexNumber num(0, 1);
    ComplexNumber res = num * num;
    ASSERT_EQ(-1, res.getRe());
    ASSERT_EQ(0, res.getIm());
}

TEST(Napylov_Evgenii_ComplexNumberTest, Overflow_no_throw) {
    constexpr double max_d = std::numeric_limits<double>::max();
    ComplexNumber num(max_d, max_d);
    ASSERT_NO_THROW(ComplexNumber(num + num));
}

TEST(Napylov_Evgenii_ComplexNumberTest, Create_infinity) {
    constexpr double inf = std::numeric_limits<double>::infinity();
    ASSERT_NO_THROW(ComplexNumber num_inf(inf, inf));
}
