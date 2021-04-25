// Copyright 2021 Gusarova Daria

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

typedef testing::TestWithParam<std::tuple<double, double, double, double,
double, double>> Gusarova_Daria_ComplexNumberTest_Param;

TEST_P(Gusarova_Daria_ComplexNumberTest_Param, Subtract_Zero) {
    // Arrange
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    const double re2 = 0.0;
    const double im2 = 0.0;

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    ComplexNumber res = a - b;

    // Assert
    ASSERT_DOUBLE_EQ(re1, res.getRe());
    ASSERT_DOUBLE_EQ(im1, res.getIm());
}

TEST_P(Gusarova_Daria_ComplexNumberTest_Param, Communicative_Law_For_Mult) {
    // Arrange
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    ComplexNumber res1 = a * b;
    ComplexNumber res2 = b * a;

    // Assert
    ASSERT_DOUBLE_EQ(res1.getRe(), res2.getRe());
    ASSERT_DOUBLE_EQ(res1.getIm(), res2.getIm());
}

TEST_P(Gusarova_Daria_ComplexNumberTest_Param, Associative_Law_For_Mult) {
    // Arrange
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());
    double re3 = std::get<4>(GetParam());
    double im3 = std::get<5>(GetParam());

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    ComplexNumber c(re3, im3);
    ComplexNumber res1 = (a * b) * c;
    ComplexNumber res2 = a * (b * c);

    // Assert
    ASSERT_DOUBLE_EQ(res1.getRe(), res2.getRe());
    ASSERT_DOUBLE_EQ(res1.getIm(), res2.getIm());
}

INSTANTIATE_TEST_CASE_P(/**/, Gusarova_Daria_ComplexNumberTest_Param,
    testing::Values(
    std::make_tuple(1.5, 6.8, 7.3, 0.35, 18.0, 14.5),
    std::make_tuple(-8.0, 4.2, -0.3, 11.0, 2.8, -9.5),
    std::make_tuple(24.0, -3.4, 2.1, 18.0, -9.7, 0.81),
    std::make_tuple(-20.6, 0.18, 5.4, 3.56, -0.7, 19.0),
    std::make_tuple(4.2, 8.0, -1.2, 45.9, -4.0, 14.6)
));

