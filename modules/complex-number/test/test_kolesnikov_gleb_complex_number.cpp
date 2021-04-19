// Copyright 2021 Gleb Kolesnikov

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kolesnikov_Gleb_ComplexNumberTEST, Multiply_by_one) {
    ComplexNumber number(13, 13);
    ComplexNumber number_one(1, 0);
    ComplexNumber result = number * number_one;

    ASSERT_EQ(number, result);
}

TEST(Kolesnikov_Gleb_ComplexNumberTEST, Add_zero) {
    ComplexNumber number(13, 13);
    ComplexNumber number_zero(0, 0);
    ComplexNumber result = number + number_zero;

    ASSERT_EQ(number, result);
}

TEST(Kolesnikov_Gleb_ComplexNumberTEST, Divide_by_one) {
    ComplexNumber number(13, 13);
    ComplexNumber second_number(1, 1);
    ComplexNumber check(13, 0);
    ComplexNumber result = number / second_number;

    ASSERT_EQ(check, result);
}
