// Copyright 2021 Novozhilova Ekaterina

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Novozhilova_Ekaterina_ComplexNumberTest,
Created_With_The_Same_Complex_Number_Are_Equal) {
    // Arrange
    ComplexNumber z(2.0, -4.5);

    // Act
    ComplexNumber z1(z);
    ComplexNumber z2(z);

    // Assert
    ASSERT_DOUBLE_EQ(z1.getRe(), z2.getRe());
    ASSERT_DOUBLE_EQ(z1.getIm(), z2.getIm());
}

TEST(Novozhilova_Ekaterina_ComplexNumberTest, Equals_Origin) {
    // Arrange
    ComplexNumber a(-2.3, 4.5);

    // Act
    ComplexNumber b(a);
    ComplexNumber c(b);

    // Assert
    ASSERT_DOUBLE_EQ(a.getRe(), c.getRe());
    ASSERT_DOUBLE_EQ(a.getIm(), c.getIm());
}

typedef testing::TestWithParam<std::tuple<double, double, double>>
Novozhilova_Ekaterina_ComplexNumberTest_Param;
TEST_P(Novozhilova_Ekaterina_ComplexNumberTest_Param,
Res_Are_Not_Equal_Then_Numbers_Arent_Too) {
    // Arrange
    ComplexNumber a(std::get<0>(GetParam()), std::get<1>(GetParam()));
    ComplexNumber b(a);
    // 0 is not equal, 1 is equal
    int part_equality;
    int full_equality;

    // Act
    b.setRe(std::get<2>(GetParam()));
    if (a.getRe() != b.getRe()) {
        part_equality = 0;
    } else {
        part_equality = 1;
    }
    if (a != b) {
        full_equality = 0;
    } else {
        full_equality = 1;
    }

    // Assert
    ASSERT_EQ(part_equality, full_equality);
}

INSTANTIATE_TEST_CASE_P(/**/, Novozhilova_Ekaterina_ComplexNumberTest_Param,
    testing::Values(
    std::make_tuple(0.0, 3.3, 9.8),
    std::make_tuple(-4.0, -7.3, 10.4),
    std::make_tuple(4.0, -15.0, -6.6),
    std::make_tuple(-4.39, -1.22, -8.3)
));
