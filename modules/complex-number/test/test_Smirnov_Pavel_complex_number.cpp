// Copyright 2024 Smirnov Pavel
#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"

TEST(Smirnov_Pavel_ComlpexNumberTest, getTest) {
    double real = 1.0;
    double imaginary = 1.0;

    ComplexNumber complex = ComplexNumber(real, imaginary);

    ASSERT_EQ(complex.getRe(), real);
    ASSERT_EQ(complex.getIm(), imaginary);
}

TEST(Smirnov_Pavel_ComlpexNumberTest, additionTest) {
    ComplexNumber complex1 = ComplexNumber(1.0, 2.0);
    ComplexNumber complex2 = ComplexNumber(3.0, 4.0);

    ComplexNumber result = complex1 + complex2;

    ASSERT_EQ(result.getRe(), 4.0);
    ASSERT_EQ(result.getIm(), 6.0);
}

TEST(Smirnov_Pavel_ComlpexNumberTest, subtractionTest) {
    ComplexNumber complex1 = ComplexNumber(5.0, 6.0);
    ComplexNumber complex2 = ComplexNumber(2.0, 1.0);

    ComplexNumber result = complex1 - complex2;

    ASSERT_EQ(result.getRe(), 3.0);
    ASSERT_EQ(result.getIm(), 5.0);
}

TEST(Smirnov_Pavel_ComlpexNumberTest, multiplicationTest) {
    ComplexNumber complex1 = ComplexNumber(2.0, 3.0);
    ComplexNumber complex2 = ComplexNumber(4.0, 5.0);

    ComplexNumber result = complex1 * complex2;

    ASSERT_EQ(result.getRe(), -7.0);
    ASSERT_EQ(result.getIm(), 22.0);
}

TEST(Smirnov_Pavel_ComlpexNumberTest, divisionTest) {
    ComplexNumber complex1 = ComplexNumber(10.0, 15.0);
    ComplexNumber complex2 = ComplexNumber(2.0, 3.0);

    ComplexNumber result = complex1 / complex2;

    ASSERT_EQ(result.getRe(), 5.0);
    ASSERT_EQ(result.getIm(), 0);
}

TEST(Smirnov_Pavel_ComlpexNumberTest, zeroDivisionTest) {
    ComplexNumber z1(10.0, 4.0);
    ComplexNumber z2(0.0, 0.0);

    ASSERT_ANY_THROW(z1 / z2);
}