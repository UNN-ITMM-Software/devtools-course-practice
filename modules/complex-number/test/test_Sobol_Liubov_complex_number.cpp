// Copyright 2024 Sobol Liubov

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sobol_Liubov_ComplexNumberTest, Can_Add_Complex_numbers) {
    ComplexNumber z1(1.2, 2.2);
    ComplexNumber z2(3.2, 4.2);

    ComplexNumber answer = z1+z2;

    ASSERT_DOUBLE_EQ(4.4, answer.getRe());
    ASSERT_DOUBLE_EQ(6.4, answer.getIm());
}
TEST(Sobol_Liubov_ComplexNumberTest, Can_Multiply_Complex_numbers) {
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(2.0, 2.0);

    ComplexNumber answer = z1 * z2;

    ASSERT_DOUBLE_EQ(0.0, answer.getRe());
    ASSERT_DOUBLE_EQ(4.0, answer.getIm());
}
TEST(Sobol_Liubov_ComplexNumberTest, Can_Subtract_Complex_numbers) {
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(2.0, 2.0);

    ComplexNumber answer = z1 - z2;

    ASSERT_DOUBLE_EQ(-1.0, answer.getRe());
    ASSERT_DOUBLE_EQ(-1.0, answer.getIm());
}
TEST(Sobol_Liubov_ComplexNumberTest, Can_Divide_Complex_numbers) {
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(2.0, 2.0);

    ComplexNumber answer = z2/z1;

    ASSERT_DOUBLE_EQ(2, answer.getRe());
    ASSERT_DOUBLE_EQ(0.0, answer.getIm());
}
TEST(Sobol_Liubov_ComplexNumberTest, Can_Not_Divide_on_zero) {
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(2.0, 2.0);

    ASSERT_ANY_THROW(z2 / z1);
}
