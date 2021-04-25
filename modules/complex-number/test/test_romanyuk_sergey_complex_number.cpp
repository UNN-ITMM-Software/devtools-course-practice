// Copyright 2021 Romanyuk Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Romanyuk_Sergey_ComplexNumberTesting, Complex_plus_and_multiplication) {
    // Creating buffer values
    ComplexNumber a(2.0, 3.0);
    ComplexNumber b(3.0, 2.0);
    ComplexNumber c(-5.0, 1.5);

    // Creating test and true values
    ComplexNumber test_value = (a + b) * c;
    ComplexNumber true_value(-32.5, -17.5);

    // Testing
    ASSERT_EQ(test_value.getRe(), true_value.getRe());
    ASSERT_EQ(test_value.getIm(), true_value.getIm());
}

TEST(Romanyuk_Sergey_ComplexNumberTesting, Complex_devision) {
    // Creating buffer values
    ComplexNumber a(-2.0, 1.0);
    ComplexNumber b(1.0, -1.0);

    // Creating test and true values
    ComplexNumber test_value = a / b;
    ComplexNumber true_value(-1.5, -0.5);

    // Testing
    ASSERT_EQ(test_value.getRe(), true_value.getRe());
    ASSERT_EQ(test_value.getIm(), true_value.getIm());
}

TEST(Romanyuk_Sergey_ComplexNumberTesting, Check_Set) {
    // Creating true value
    ComplexNumber true_value(4.0, 5.0);

    // Creating buffer and test variables
    ComplexNumber a(true_value.getRe(), true_value.getIm());
    ComplexNumber b;

    // Processing
    b.setRe(a.getRe());
    b.setIm(a.getIm());

    // Testing
    ASSERT_EQ(b, true_value);
}
