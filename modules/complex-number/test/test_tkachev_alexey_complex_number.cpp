// Copyright 2021 Tkachev Alexey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Tkachev_Alexey_ComplexNumberTest, distributive_law) {
    const double real_1 = 10.2;
    const double imaginary_1 = -30.5;

    const double real_2 = 40.5;
    const double imaginary_2 = 1.2;

    const double real_3 = -0.5;
    const double imaginary_3 = 21.5;

    const ComplexNumber complex_number_1(real_1, imaginary_1);
    const ComplexNumber complex_number_2(real_2, imaginary_2);
    const ComplexNumber complex_number_3(real_3, imaginary_3);

    const ComplexNumber first_expression =
        complex_number_1 * (complex_number_2 + complex_number_3);

    const ComplexNumber second_expression =
        complex_number_1 * complex_number_2 +
        complex_number_1 * complex_number_3;

    ASSERT_EQ(first_expression, second_expression);
}

TEST(Tkachev_Alexey_ComplexNumberTest, sum_with_im_zero) {
    const double real_1 = 5.0;
    const double imaginary_1 = 0.0;

    const double real_2 = 2.0;
    const double imaginary_2 = 0.0;

    const ComplexNumber complex_number_1(real_1, imaginary_1);
    const ComplexNumber complex_number_2(real_2, imaginary_2);

    const double true_real =
        complex_number_1.getRe() + complex_number_2.getRe();

    const double true_imaginary = 0.0;

    const ComplexNumber sum_complex_number =
        complex_number_1 + complex_number_2;

    const ComplexNumber true_sum_complex_number(
        true_real, true_imaginary);

    ASSERT_EQ(true_sum_complex_number, sum_complex_number);
}

TEST(Tkachev_Alexey_ComplexNumberTest, multiplication_with_im_zero) {
    const double real_1 = 25.0;
    const double imaginary_1 = 0.0;

    const double real_2 = 30.1;
    const double imaginary_2 = 0.0;

    const ComplexNumber complex_number_1(real_1, imaginary_1);
    const ComplexNumber complex_number_2(real_2, imaginary_2);

    const double true_real =
        complex_number_1.getRe() * complex_number_2.getRe();

    const double true_imaginary = 0.0;

    const ComplexNumber mult_complex_number =
        complex_number_1 * complex_number_2;

    const ComplexNumber true_mult_complex_number(
        true_real, true_imaginary);

    ASSERT_EQ(true_mult_complex_number, mult_complex_number);
}

TEST(Tkachev_Alexey_ComplexNumberTest, division_zero_by_not_a_zero) {
    const double real_1 = 0.0;
    const double imaginary_1 = 0.0;

    const double real_2 = 30.1;
    const double imaginary_2 = 50.1;

    const ComplexNumber complex_number_1(real_1, imaginary_1);
    const ComplexNumber complex_number_2(real_2, imaginary_2);

    const ComplexNumber div_complex_number =
        complex_number_1 / complex_number_2;

    const double true_real = 0.0;
    const double true_imaginary = 0.0;

    const ComplexNumber true_div_complex_number(
        true_real, true_imaginary);

    ASSERT_EQ(true_div_complex_number, div_complex_number);
}

TEST(Tkachev_Alexey_ComplexNumberTest, division_by_real_one) {
    const double real_1 = 1.1;
    const double imaginary_1 = -1.1;

    const double real_2 = 1.0;
    const double imaginary_2 = 0.0;

    const ComplexNumber complex_number_1(real_1, imaginary_1);
    const ComplexNumber complex_number_2(real_2, imaginary_2);

    const ComplexNumber div_complex_number =
        complex_number_1 / complex_number_2;

    const ComplexNumber true_div_complex_number =
        complex_number_1;

    ASSERT_EQ(true_div_complex_number, div_complex_number);
}
