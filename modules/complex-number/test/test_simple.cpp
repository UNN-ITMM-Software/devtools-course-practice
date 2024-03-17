// Copyright 2021 Dmitry Kurtaev

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Default, Constructor) {
    ComplexNumber number;
    ASSERT_EQ(number.getRe(), 0);
    ASSERT_EQ(number.getIm(), 0);
}

typedef testing::TestWithParam<std::tuple<double, double> > Parametrized;
TEST_P(Parametrized, Constructor) {
    double real = std::get<0>(GetParam());
    double imag = std::get<1>(GetParam());
    ComplexNumber number(real, imag);
    ASSERT_EQ(number.getRe(), real);
    ASSERT_EQ(number.getIm(), imag);
}

INSTANTIATE_TEST_CASE_P(/**/, Parametrized, testing::Combine(
  testing::Values(1.0, 2.0),
  testing::Values(3.0, 4.0)
));
