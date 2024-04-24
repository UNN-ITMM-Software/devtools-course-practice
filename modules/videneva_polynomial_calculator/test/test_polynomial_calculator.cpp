// Copyright 2024 Videneva Ekaterina

#include <gtest/gtest.h>

#include "include/polynomial_calculator.h"

TEST(polynomial_calculator, Can_Run) {
    ASSERT_NO_THROW(polynomial_calculator P);
}

TEST(polynomial_calculator,
    removes_the_polynomial_correctly) {
    polynomial_calculator P;
    ASSERT_NO_THROW(P.~polynomial_calculator());
}

TEST(polynomial_calculator, correctly_create_number) {
    ASSERT_NO_THROW(polynomial_calculator P(1.2));
}

TEST(polynomial_calculator, correctly_create_polynomial) {
    std::vector<double> a;
    a.push_back(1.1);
    a.push_back(1.2);
    a.push_back(1.3);
    ASSERT_NO_THROW(polynomial_calculator P(a, 3));
}

TEST(polynomial_calculator, size_not_equal_number_parameters) {
    std::vector<double> a;
    a.push_back(1.1);
    a.push_back(1.2);
    a.push_back(1.3);
    ASSERT_ANY_THROW(polynomial_calculator P(a, 5));
}

TEST(polynomial_calculator, can_Check_Number_Of_Arguments) {
    std::vector<double> a;
    a.push_back(1.1);
    a.push_back(1.2);
    polynomial_calculator P(a, 2);
    ASSERT_NO_THROW(P.GetSize());
}

TEST(polynomial_calculator,
    can_Check_Number_Of_Arguments_correctly) {
    std::vector<double> a;
    a.push_back(1.1);
    a.push_back(1.2);
    a.push_back(1.3);
    a.push_back(1.4);
    polynomial_calculator P(a, 4);
    EXPECT_EQ(4, P.GetSize());
}

TEST(polynomial_calculator, can_copy_a_polynomial) {
    std::vector<double> a;
    a.push_back(1.1);
    a.push_back(1.2);
    a.push_back(1.3);
    polynomial_calculator P(a, 3);
    ASSERT_NO_THROW(polynomial_calculator Q(P));
}

TEST(polynomial_calculator, can_calculate_the_value) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    a.push_back(1.3);
    polynomial_calculator P(a, 3);
    ASSERT_NO_THROW(P.value(2));
}

TEST(polynomial_calculator, can_calculate_the_value_correctly) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    a.push_back(1.3);
    polynomial_calculator P(a, 3);
    EXPECT_DOUBLE_EQ(45.7, P.value(2));
}

TEST(polynomial_calculator, can_add_polynomials) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    a.push_back(1.3);
    std::vector<double> b;
    b.push_back(1.1);
    b.push_back(2.2);
    polynomial_calculator P(a, 3);
    polynomial_calculator Q(b, 2);
    ASSERT_NO_THROW(P + Q);
}

TEST(polynomial_calculator,
    The_polynomials_are_defined_as_unequal) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    a.push_back(1.3);
    std::vector<double> b;
    b.push_back(1.1);
    b.push_back(2.2);
    polynomial_calculator P(a, 3);
    polynomial_calculator Q(b, 2);
    ASSERT_NO_THROW(P == Q);
}

TEST(polynomial_calculator,
    The_polynomials_are_defined_as_unequal_no_throw) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    a.push_back(1.3);
    std::vector<double> b;
    b.push_back(5.1);
    b.push_back(12.0);
    b.push_back(1.3);
    polynomial_calculator P(a, 3);
    polynomial_calculator Q(b, 3);
    ASSERT_NO_THROW(P == Q);
}

TEST(polynomial_calculator,
    The_polynomials_are_defined_as_unequal_no_throw_2) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    a.push_back(1.3);
    std::vector<double> b;
    b.push_back(5.1);
    b.push_back(2.0);
    b.push_back(1.3);
    polynomial_calculator P(a, 3);
    polynomial_calculator Q(b, 3);
    ASSERT_NO_THROW(P == Q);
}

TEST(polynomial_calculator,
    The_polynomials_are_defined_as_unequal_correct) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    a.push_back(1.3);
    std::vector<double> b;
    b.push_back(5.1);
    b.push_back(12.0);
    b.push_back(1.3);
    polynomial_calculator P(a, 3);
    polynomial_calculator Q(b, 3);
    EXPECT_EQ(P, Q);
}

TEST(polynomial_calculator,
    The_polynomials_are_defined_as_unequal_correct_2) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(1.0);
    a.push_back(1.3);
    std::vector<double> b;
    b.push_back(5.1);
    b.push_back(12.0);
    b.push_back(1.3);
    polynomial_calculator P(a, 3);
    polynomial_calculator Q(b, 3);
    EXPECT_NE(P, Q);
}

TEST(polynomial_calculator,
    The_polynomials_are_defined_as_no_unequal_no_throw) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    a.push_back(1.3);
    std::vector<double> b;
    b.push_back(5.1);
    b.push_back(1.0);
    b.push_back(1.3);
    polynomial_calculator P(a, 3);
    polynomial_calculator Q(b, 3);
    ASSERT_NO_THROW(P != Q);
}

TEST(polynomial_calculator,
    The_polynomials_are_defined_as_no_unequal_no_throw_2) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    std::vector<double> b;
    b.push_back(5.1);
    b.push_back(1.0);
    b.push_back(1.3);
    polynomial_calculator P(a, 2);
    polynomial_calculator Q(b, 3);
    ASSERT_NO_THROW(P != Q);
}

TEST(polynomial_calculator,
    The_polynomials_are_defined_as_no_unequal_no_throw_3) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    a.push_back(1.3);
    std::vector<double> b;
    b.push_back(5.1);
    b.push_back(12.0);
    b.push_back(1.3);
    polynomial_calculator P(a, 3);
    polynomial_calculator Q(b, 3);
    ASSERT_NO_THROW(P != Q);
}

TEST(polynomial_calculator,
    can_add_polynomials_different_sizes) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    std::vector<double> b;
    b.push_back(1.1);
    b.push_back(2.2);
    b.push_back(1.3);
    polynomial_calculator P(a, 2);
    polynomial_calculator Q(b, 3);
    ASSERT_NO_THROW(P + Q);
}

TEST(polynomial_calculator,
    can_add_polynomials_different_sizes_2) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    std::vector<double> b;
    b.push_back(1.1);
    b.push_back(2.2);
    b.push_back(1.3);
    polynomial_calculator P(b, 3);
    polynomial_calculator Q(a, 2);
    ASSERT_NO_THROW(P + Q);
}

TEST(polynomial_calculator,
    can_add_polynomials_different_sizes_correct) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    std::vector<double> b;
    b.push_back(1.1);
    b.push_back(2.2);
    b.push_back(1.3);
    polynomial_calculator P(a, 2);
    polynomial_calculator Q(b, 3);
    std::vector<double> c;
    c.push_back(1.1);
    c.push_back(7.3);
    c.push_back(13.3);
    polynomial_calculator C(c, 3);
    EXPECT_EQ(C, P + Q);
}

TEST(polynomial_calculator,
    can_sub_polynomials_different_sizes) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    std::vector<double> b;
    b.push_back(1.1);
    b.push_back(2.2);
    b.push_back(1.3);
    polynomial_calculator P(a, 2);
    polynomial_calculator Q(b, 3);
    ASSERT_NO_THROW(P - Q);
}

TEST(polynomial_calculator,
    can_sub_polynomials_different_sizes_2) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    std::vector<double> b;
    b.push_back(1.1);
    b.push_back(2.2);
    b.push_back(1.3);
    polynomial_calculator P(b, 3);
    polynomial_calculator Q(a, 2);
    ASSERT_NO_THROW(P - Q);
}

TEST(polynomial_calculator,
    can_sub_polynomials_different_sizes_correct) {
    std::vector<double> a;
    a.push_back(5.1);
    a.push_back(12.0);
    std::vector<double> b;
    b.push_back(1.1);
    b.push_back(2.0);
    b.push_back(1.3);
    polynomial_calculator P(a, 2);
    polynomial_calculator Q(b, 3);
    std::vector<double> c;
    c.push_back(-1.1);
    c.push_back(3.1);
    c.push_back(10.7);
    polynomial_calculator C(c, 3);
    EXPECT_EQ(C, P - Q);
}

TEST(polynomial_calculator,
    can_mult_polynomials_different_sizes) {
    std::vector<double> a;
    a.push_back(5);
    a.push_back(12);
    std::vector<double> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(1);
    polynomial_calculator P(a, 2);
    polynomial_calculator Q(b, 3);
    ASSERT_NO_THROW(P * Q);
}

TEST(polynomial_calculator,
    can_mult_polynomials_different_sizes_2) {
    std::vector<double> a;
    a.push_back(5);
    a.push_back(12);
    std::vector<double> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(1);
    polynomial_calculator P(a, 2);
    polynomial_calculator Q(b, 3);
    ASSERT_NO_THROW(Q * P);
}

TEST(polynomial_calculator,
    can_mult_polynomials_different_sizes_correct) {
    std::vector<double> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    std::vector<double> b;
    b.push_back(1);
    b.push_back(1);
    polynomial_calculator P(a, 4);
    polynomial_calculator Q(b, 2);
    std::vector<double> c;
    c.push_back(2);
    c.push_back(3);
    c.push_back(1);
    c.push_back(0);
    c.push_back(0);
    polynomial_calculator C(c, 5);
    ASSERT_NO_THROW(Q * P);
    ASSERT_EQ(C, Q * P);
}

TEST(polynomial_calculator,
    can_mult_polynomials_different_sizes_correct_2) {
    std::vector<double> a;
    a.push_back(4);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(2);
    std::vector<double> b;
    b.push_back(1);
    b.push_back(3);
    b.push_back(2);
    b.push_back(9);
    polynomial_calculator P(a, 6);
    polynomial_calculator Q(b, 4);
    std::vector<double> c;
    c.push_back(4);
    c.push_back(12);
    c.push_back(8);
    c.push_back(37);
    c.push_back(3);
    c.push_back(4);
    c.push_back(15);
    c.push_back(4);
    c.push_back(18);
    polynomial_calculator C(c, 9);
    ASSERT_NO_THROW(Q * P);
    ASSERT_EQ(C, Q * P);
}


TEST(polynomial_calculator,
    can_sum_empty_polynom_and_constant) {
    polynomial_calculator P;
    ASSERT_NO_THROW(P + 2);
    std::vector<double> b;
    b.push_back(2);
    polynomial_calculator Q(b, 1);
    ASSERT_EQ(P + 2, Q);
}

TEST(polynomial_calculator,
    can_sum_not_empty_polynom_and_constant) {
    std::vector<double> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(5);
    a.push_back(9);
    polynomial_calculator P(a, 4);
    ASSERT_NO_THROW(P + 5);
    std::vector<double> b;
    b.push_back(2);
    b.push_back(1);
    b.push_back(5);
    b.push_back(14);
    polynomial_calculator Q(b, 4);
    ASSERT_EQ(P + 5, Q);
}

TEST(polynomial_calculator,
    can_min_not_empty_polynom_and_constant) {
    std::vector<double> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(5);
    a.push_back(9);
    polynomial_calculator P(a, 4);
    ASSERT_NO_THROW(P - 10);
    std::vector<double> b;
    b.push_back(2);
    b.push_back(1);
    b.push_back(5);
    b.push_back(-1);
    polynomial_calculator Q(b, 4);
    ASSERT_EQ(P - 10, Q);
}

TEST(polynomial_calculator,
    can_mult_not_empty_polynom_and_constant) {
    std::vector<double> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(5);
    a.push_back(9);
    polynomial_calculator P(a, 4);
    ASSERT_NO_THROW(P * 5);
    std::vector<double> b;
    b.push_back(10);
    b.push_back(5);
    b.push_back(25);
    b.push_back(45);
    polynomial_calculator Q(b, 4);
    ASSERT_EQ(P * 5, Q);
}
