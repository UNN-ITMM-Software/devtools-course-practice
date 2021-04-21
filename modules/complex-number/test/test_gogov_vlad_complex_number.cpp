// Copyright 2021 Gogov Vlad

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Gogov_Vlad_ComplexNumberTest, Can_Add) {
    double re1 = 15.0;
    double im1 = -6.0;

    double re2 = 7.0;
    double im2 = 3.5;

    double reResult = 22.0;
    double imResult = -2.5;

    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber result = c1 + c2;

    ASSERT_EQ(reResult, result.getRe());
    ASSERT_EQ(imResult, result.getIm());
}

TEST(Gogov_Vlad_ComplexNumberTest, Can_Substract) {
    double re1 = 10.0;
    double im1 = 2.0;

    double re2 = 9.0;
    double im2 = 1.5;

    double reResult = 1.0;
    double imResult = 0.5;

    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber result = c1 - c2;

    ASSERT_EQ(reResult, result.getRe());
    ASSERT_EQ(imResult, result.getIm());
}

TEST(Gogov_Vlad_ComplexNumberTest, Can_Multiply) {
    double re1 = 2.0;
    double im1 = 4.5;

    double re2 = 3.5;
    double im2 = 7.0;

    double reResult = -24.5;
    double imResult = 29.75;

    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber result = c1 * c2;

    ASSERT_EQ(reResult, result.getRe());
    ASSERT_EQ(imResult, result.getIm());
}

TEST(Gogov_Vlad_ComplexNumberTest, Can_Divide) {
    double re1 = -2.0;
    double im1 = 1.0;

    double re2 = 1.0;
    double im2 = -1.0;

    double reResult = -1.5;
    double imResult = -0.5;

    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber result = c1 / c2;

    ASSERT_EQ(reResult, result.getRe());
    ASSERT_EQ(imResult, result.getIm());
}
