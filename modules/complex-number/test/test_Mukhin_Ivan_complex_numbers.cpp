// Copyright 2024 Mukhin Ivan

#include <gtest/gtest.h>
#include <tuple>
#include <utility>
#include "include/complex_number.h"

using std::pair;
using std::make_pair;
using std::tuple;
using std::make_tuple;

class Mukhin_Ivan_parametric_test_1 \
      : public ::testing::TestWithParam<pair<double, double>> {};

class Mukhin_Ivan_parametric_test_2 \
      : public ::testing::TestWithParam \
               <tuple<pair<double, double>, pair<double, double>>> {};

TEST_P(Mukhin_Ivan_parametric_test_1, can_create_complex_number) {
    auto values = GetParam();
    ASSERT_NO_THROW(ComplexNumber(values.first, values.second));
}

TEST_P(Mukhin_Ivan_parametric_test_1, copy_constructor_works) {
    auto values = GetParam();
    ComplexNumber a(values.first, values.second);
    ComplexNumber b(a);
    EXPECT_EQ(a.getRe(), b.getRe());
    EXPECT_EQ(a.getIm(), b.getIm());
}

TEST_P(Mukhin_Ivan_parametric_test_2, operator_eq_and_not_eq_works) {
    auto values = GetParam();
    auto first_pair = std::get<0>(values);
    auto second_pair = std::get<1>(values);
    ComplexNumber a(first_pair.first, first_pair.second);
    ComplexNumber b(second_pair.first, second_pair.second);
    if (first_pair.first == second_pair.first &&
        first_pair.second == second_pair.second) {
        EXPECT_TRUE(a == b);
    } else {
        EXPECT_TRUE(a != b);
    }
}

TEST(Mukhin_Ivan_tests_cases, can_set_re_and_im) {
    ComplexNumber a;
    ASSERT_NO_THROW(a.setIm(1.0));
    ASSERT_NO_THROW(a.setRe(2.0));
}

TEST(Mukhin_Ivan_tests_cases, cant_divide_by_zero) {
    ASSERT_ANY_THROW(ComplexNumber(2, 8) / ComplexNumber(0, 0));
}

TEST_P(Mukhin_Ivan_parametric_test_1, can_take_re_and_im_parts_of_number) {
    auto values = GetParam();
    ComplexNumber a(values.first, values.second);
    EXPECT_EQ(values.first, a.getRe());
    EXPECT_EQ(values.second, a.getIm());
}

TEST_P(Mukhin_Ivan_parametric_test_2, can_sum_complex_numbers) {
    auto values = GetParam();
    auto first_pair = std::get<0>(values);
    auto second_pair = std::get<1>(values);
    ComplexNumber a = ComplexNumber(first_pair.first, first_pair.second);
    ComplexNumber b = ComplexNumber(second_pair.first, second_pair.second);
    ComplexNumber c = a + b;
    EXPECT_EQ(first_pair.first + second_pair.first, c.getRe());
    EXPECT_EQ(first_pair.second + second_pair.second, c.getIm());
}

TEST_P(Mukhin_Ivan_parametric_test_2, can_sub_complex_numbers) {
    auto values = GetParam();
    auto first_pair = std::get<0>(values);
    auto second_pair = std::get<1>(values);
    ComplexNumber a(first_pair.first, first_pair.second);
    ComplexNumber b(second_pair.first, second_pair.second);
    ComplexNumber c = a - b;
    EXPECT_EQ(first_pair.first - second_pair.first, c.getRe());
    EXPECT_EQ(first_pair.second - second_pair.second, c.getIm());
}

TEST_P(Mukhin_Ivan_parametric_test_2, can_mult_complex_numbers) {
    auto values = GetParam();
    auto first_pair = std::get<0>(values);
    auto second_pair = std::get<1>(values);
    ComplexNumber a(first_pair.first, first_pair.second);
    ComplexNumber b(second_pair.first, second_pair.second);
    ComplexNumber c = a * b;
    double Re = (
        first_pair.first * second_pair.first - \
        first_pair.second * second_pair.second);
    double Im = (
        first_pair.first * second_pair.second + \
        first_pair.second * second_pair.first);
    EXPECT_EQ(Re, c.getRe());
    EXPECT_EQ(Im, c.getIm());
}


INSTANTIATE_TEST_CASE_P(Mukhin_Ivan_tests_cases, Mukhin_Ivan_parametric_test_1,
testing::Values(
    make_pair(2.0, 3.0),
    make_pair(0.0, 0.0),
    make_pair(-2.0, 3.0),
    make_pair(2.12132, 10.213),
    make_pair(-12.0, 83.0),
    make_pair(-120.12, 718.05)
));

INSTANTIATE_TEST_CASE_P(Mukhin_Ivan_tests_cases, Mukhin_Ivan_parametric_test_2,
testing::Values(
    make_tuple(make_pair(1.0, 2.0), make_pair(-1.0, -2.0)),
    make_tuple(make_pair(0.0, 0.0), make_pair(0.0, 0.0)),
    make_tuple(make_pair(1.25, -2.873), make_pair(8.0, -2.0)),
    make_tuple(make_pair(0.426, 0.3284), make_pair(-0.123, -2.0)),
    make_tuple(make_pair(100.023, 200.0213), make_pair(-100.0213, -2000.0)),
    make_tuple(make_pair(12, 2), make_pair(-1, -22)),
    make_tuple(make_pair(0.5, -24), make_pair(-100, -2193)),
    make_tuple(make_pair(0.005, 2.05), make_pair(-1.023, -2.89)),
    make_tuple(make_pair(12, 2), make_pair(-1, -22)),
    make_tuple(make_pair(1000, 200), make_pair(-123, -98))
));
