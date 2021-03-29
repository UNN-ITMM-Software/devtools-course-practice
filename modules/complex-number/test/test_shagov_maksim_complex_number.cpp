// Copyright 2021 Maksim Shagov

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shagov_Maksim_ComplexNumberTEST, Assign_operator) {
    ComplexNumber number(13.7, -11.2);
    ComplexNumber number1 = number;

    ASSERT_EQ(number.getRe(), number1.getRe());
    ASSERT_EQ(number.getIm(), number1.getIm());
}

TEST(Shagov_Maksim_ComplexNumberTEST, Addition_test) {
    ComplexNumber number(13.2, -10.2);
    ComplexNumber number1(-22.2, 21.3);

    ComplexNumber add_number = number1 + number;

    ASSERT_EQ(add_number.getRe(), number1.getRe() + number.getRe());
    ASSERT_EQ(add_number.getIm(), number1.getIm() + number.getIm());
}

TEST(Shagov_Maksim_ComplexNumberTEST, No_equal_test) {
    ComplexNumber number(1.0, -1.0);
    ComplexNumber number1(-131.2, 13.8);

    ASSERT_NE(number, number1);
}

TEST(Shagov_Maksim_ComplexNumberTEST, Complex_number_multiplied_by_number) {
    ComplexNumber complex_number(20.12, 2000.0);
    ComplexNumber number(3.0, 0.0);

    ComplexNumber mult_number = complex_number * number;

    ASSERT_EQ(mult_number.getRe(), number.getRe() * complex_number.getRe());
    ASSERT_EQ(mult_number.getIm(), number.getRe() * complex_number.getIm());
}
