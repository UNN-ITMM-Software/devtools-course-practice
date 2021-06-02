// Copyright 2021 Yurin Stanislav

#include <gtest/gtest.h>

#include <tuple>

#include "include/fraction.h"

typedef testing::TestWithParam<int>
        Can_create_one_parametres_constructor;

TEST_P(Can_create_one_parametres_constructor, can_create_constructor) {
    int n = GetParam();

    Fraction f(n);

    ASSERT_EQ(n, f.getNumerator());
}

INSTANTIATE_TEST_CASE_P(, Can_create_one_parametres_constructor,
      testing::Values(3, 29)
);

typedef testing::TestWithParam<std::tuple<int, int>>
        Can_create_two_parametres_constructor;

TEST_P(Can_create_two_parametres_constructor, can_create_constructor) {
    int n = std::get<0>(GetParam());
    int d = std::get<1>(GetParam());

    Fraction f(n, d);

    ASSERT_EQ(d, f.getDenominator());
}

INSTANTIATE_TEST_CASE_P(, Can_create_two_parametres_constructor,
      testing::Values(std::make_tuple(2, 3), std::make_tuple(43, 99))
);

TEST(Fraction, throws_on_zero_denominator) {
    ASSERT_ANY_THROW(Fraction f(29, 0));
}

TEST(Fraction, default_fraction_creating) {
    Fraction f;

    ASSERT_EQ(0, f.getNumerator());
    ASSERT_EQ(1, f.getDenominator());
}

TEST(Fraction, fraction_with_negative_parametres_becomes_positive) {
    Fraction f(-1, -2);

    ASSERT_EQ(1, f.getNumerator());
    ASSERT_EQ(2, f.getDenominator());
}

TEST(Fraction, moves_minus_to_numerator) {
    Fraction f(1, -2);

    ASSERT_EQ(-1, f.getNumerator());
    ASSERT_EQ(2, f.getDenominator());
}

typedef testing::TestWithParam<std::tuple<int, int, int, int>>
        Reduction_par;

TEST_P(Reduction_par, reduction) {
    int n = std::get<0>(GetParam());
    int d = std::get<1>(GetParam());

    Fraction f(n, d);

    ASSERT_EQ(std::get<2>(GetParam()), f.getNumerator());
    ASSERT_EQ(std::get<3>(GetParam()), f.getDenominator());
}

INSTANTIATE_TEST_CASE_P(, Reduction_par,
      testing::Values(std::make_tuple(3, 6, 1, 2),
                      std::make_tuple(8, -32, -1, 4))
);

typedef testing::TestWithParam<std::tuple<int, int, int>>
        gcd_par;

TEST_P(gcd_par, ) {
    Fraction f;

    ASSERT_EQ(std::get<0>(GetParam()),
              f.gcd(std::get<1>(GetParam()),
                    std::get<2>(GetParam())));
}

INSTANTIATE_TEST_CASE_P(, gcd_par,
      testing::Values(std::make_tuple(3, 3, 6),
                      std::make_tuple(6, 18, 30))
);

TEST(Fraction, gcd_negative_parameter) {
    Fraction f;

    ASSERT_ANY_THROW(f.gcd(-18, 30));
}

typedef testing::TestWithParam<std::tuple<int, int, int>>
        lcm_par;

TEST_P(lcm_par, ) {
    Fraction f;

    ASSERT_EQ(std::get<0>(GetParam()),
              f.lcm(std::get<1>(GetParam()),
                    std::get<2>(GetParam())));
}

INSTANTIATE_TEST_CASE_P(, lcm_par,
      testing::Values(std::make_tuple(36, 12, 18),
                      std::make_tuple(15, 15, 3))
);

TEST(Fraction, lcm_negative_parameter) {
    Fraction f;

    ASSERT_ANY_THROW(f.lcm(-12, 18));
}

TEST(Fraction, can_self_appropriation) {
    Fraction f(2, 3);

    f = f;

    ASSERT_EQ(2, f.getNumerator());
    ASSERT_EQ(3, f.getDenominator());
}

TEST(Fraction, comparison_operator_overloading) {
    Fraction f1(2, 3);
    Fraction f2;

    f2 = f1;

    ASSERT_EQ(2, f2.getNumerator());
    ASSERT_EQ(3, f2.getDenominator());
}

typedef testing::TestWithParam<std::tuple<int, int, int, int, int, int>>
        plus_par;

TEST_P(plus_par, ) {
    Fraction f1(std::get<0>(GetParam()), std::get<1>(GetParam()));
    Fraction f2(std::get<2>(GetParam()), std::get<3>(GetParam()));
    Fraction f3;

    f3 = f1 + f2;

    ASSERT_EQ(std::get<4>(GetParam()), f3.getNumerator());
    ASSERT_EQ(std::get<5>(GetParam()), f3.getDenominator());
}

INSTANTIATE_TEST_CASE_P(, plus_par,
      testing::Values(std::make_tuple(2, 3, 3, 4, 17, 12),
                      std::make_tuple(-3, 5, 4, 7, -1, 35))
);

typedef testing::TestWithParam<std::tuple<int, int, int, int, int, int>>
        minus_par;

TEST_P(minus_par, ) {
    Fraction f1(std::get<0>(GetParam()), std::get<1>(GetParam()));
    Fraction f2(std::get<2>(GetParam()), std::get<3>(GetParam()));
    Fraction f3;

    f3 = f1 - f2;

    ASSERT_EQ(std::get<4>(GetParam()), f3.getNumerator());
    ASSERT_EQ(std::get<5>(GetParam()), f3.getDenominator());
}

INSTANTIATE_TEST_CASE_P(, minus_par,
      testing::Values(std::make_tuple(2, 5, 4, 3, -14, 15),
                      std::make_tuple(3, 8, 11, -5, 103, 40))
);

typedef testing::TestWithParam<std::tuple<int, int, int, int, int, int>>
        multi_par;

TEST_P(multi_par, ) {
    Fraction f1(std::get<0>(GetParam()), std::get<1>(GetParam()));
    Fraction f2(std::get<2>(GetParam()), std::get<3>(GetParam()));
    Fraction f3;

    f3 = f1 * f2;

    ASSERT_EQ(std::get<4>(GetParam()), f3.getNumerator());
    ASSERT_EQ(std::get<5>(GetParam()), f3.getDenominator());
}

INSTANTIATE_TEST_CASE_P(, multi_par,
      testing::Values(std::make_tuple(3, 2, 8, 11, 12, 11),
                      std::make_tuple(7, -4, -9, 3, 21, 4))
);

typedef testing::TestWithParam<std::tuple<int, int, int, int, int, int>>
        dev_par;

TEST_P(dev_par, ) {
    Fraction f1(std::get<0>(GetParam()), std::get<1>(GetParam()));
    Fraction f2(std::get<2>(GetParam()), std::get<3>(GetParam()));
    Fraction f3;

    f3 = f1 / f2;

    ASSERT_EQ(std::get<4>(GetParam()), f3.getNumerator());
    ASSERT_EQ(std::get<5>(GetParam()), f3.getDenominator());
}

INSTANTIATE_TEST_CASE_P(, dev_par,
      testing::Values(std::make_tuple(13, 11, 4, 5, 65, 44),
                      std::make_tuple(14, -6, -15, -2, -14, 45))
);
