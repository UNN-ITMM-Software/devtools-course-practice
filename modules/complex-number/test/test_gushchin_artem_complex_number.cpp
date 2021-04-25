// Copyright 2021 Gushchin Artem

#include <gtest/gtest.h>

#include <tuple>

#include "include/complex_number.h"

TEST(Gushchin_Artem_ComplexNumberTest, Getters_And_Setters) {
    double re = -7.93;
    double im = 7.5;
    ComplexNumber z(-8.58, 32.7);

    z.setRe(re);
    z.setIm(im);

    ASSERT_EQ(re, z.getRe());
    ASSERT_EQ(im, z.getIm());
}

class Gushchin_Artem_Operations_ComplexNumberTest :
    public ::testing::TestWithParam<std::tuple<double, double,
                                               double, double>> {
 public:
    Gushchin_Artem_Operations_ComplexNumberTest() :
        operator1(std::get<0>(GetParam()), std::get<1>(GetParam())),
        operator2(std::get<2>(GetParam()), std::get<3>(GetParam())) {}
 protected:
    ComplexNumber operator1, operator2;
};

TEST_P(Gushchin_Artem_Operations_ComplexNumberTest, Sum_Operation_Is_Correct) {
    double reManual = std::get<0>(GetParam()) + std::get<2>(GetParam());
    double imManual = std::get<1>(GetParam()) + std::get<3>(GetParam());

    ComplexNumber res = operator1 + operator2;

    ASSERT_EQ(ComplexNumber(reManual, imManual), res);
}

TEST_P(Gushchin_Artem_Operations_ComplexNumberTest, Diff_Operation_Is_Correct) {
    double reManual = std::get<0>(GetParam()) - std::get<2>(GetParam());
    double imManual = std::get<1>(GetParam()) - std::get<3>(GetParam());

    ComplexNumber res = operator1 - operator2;

    ASSERT_EQ(ComplexNumber(reManual, imManual), res);
}

TEST_P(Gushchin_Artem_Operations_ComplexNumberTest, Mult_Operation_Is_Correct) {
    double a1 = std::get<0>(GetParam());
    double b1 = std::get<1>(GetParam());
    double a2 = std::get<2>(GetParam());
    double b2 = std::get<3>(GetParam());
    double reManual = a1 * a2 - b1 * b2;
    double imManual = a1 * b2 + b1 * a2;

    ComplexNumber res = operator1 * operator2;

    ASSERT_EQ(ComplexNumber(reManual, imManual), res);
}

INSTANTIATE_TEST_CASE_P(,
    Gushchin_Artem_Operations_ComplexNumberTest,
    ::testing::Values(
        std::make_tuple(153.37, -96.22, 68.03, -75.92),
        std::make_tuple(0.0, 113.16, -118.64, 22.79),
        std::make_tuple(141.53, 25.04, 15.88, 116.24),
        std::make_tuple(-98.61, 174.35, -51.32, -52.71)
    )
);
