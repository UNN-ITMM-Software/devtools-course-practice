// Copyright 2024 Platonova Maria

#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"

TEST(Platonova_Maria_ComlpexNumberTests, getTest) {
    double real = 1.0;
    double imaginary = 1.0;

    ComplexNumber complex = ComplexNumber(real, imaginary);

    ASSERT_EQ(complex.getRe(), real);
    ASSERT_EQ(complex.getIm(), imaginary);
}

TEST(Platonova_Maria_ComlpexNumberTests, setTest) {
    double real = 1.0;
    double imaginary = 1.0;

    ComplexNumber complex;
    complex.setRe(real);
    complex.setIm(imaginary);

    ASSERT_EQ(complex.getRe(), real);
    ASSERT_EQ(complex.getIm(), imaginary);
}

TEST(Platonova_Maria_ComlpexNumberTests, sumTest) {
    ComplexNumber a(5.2, 7.1);
    ComplexNumber b(3.3, 9.9);

    ComplexNumber c = a + b;

    EXPECT_DOUBLE_EQ(c.getRe(), 8.5);
    EXPECT_DOUBLE_EQ(c.getIm(), 17.0);
}

TEST(Platonova_Maria_ComlpexNumberTests, subTest) {
    ComplexNumber first = ComplexNumber(1.0, 1.0);
    ComplexNumber second = ComplexNumber(2.0, 2.0);

    ComplexNumber sub = first - second;

    ASSERT_EQ(sub.getRe(), -1.0);
    ASSERT_EQ(sub.getIm(), -1.0);
}

TEST(Platonova_Maria_ComlpexNumberTests, mulTest) {
    ComplexNumber first = ComplexNumber(1.0, 1.0);
    ComplexNumber second = ComplexNumber(2.0, 2.0);

    ComplexNumber mul = first * second;

    ASSERT_EQ(mul.getRe(), 0.0);
    ASSERT_EQ(mul.getIm(), 4.0);
}

TEST(Platonova_Maria_ComlpexNumberTests, divTest) {
    ComplexNumber first = ComplexNumber(1.0, 1.0);
    ComplexNumber second = ComplexNumber(2.0, 2.0);

    ComplexNumber sub = first / second;

    ASSERT_EQ(sub.getRe(), 0.5);
    ASSERT_EQ(sub.getIm(), 0.0);
}

TEST(Platonova_Maria_ComlpexNumberTests, equalTest) {
    ComplexNumber first = ComplexNumber(1.0, 1.0);
    ComplexNumber second = ComplexNumber(1.0, 1.0);

    EXPECT_TRUE(first == second);
}

TEST(Platonova_Maria_ComlpexNumberTests, nonEqualTest) {
    ComplexNumber first = ComplexNumber(1.0, 1.0);
    ComplexNumber second = ComplexNumber(-1.0, -1.0);

    EXPECT_FALSE(first == second);
}

TEST(Platonova_Maria_ComlpexNumberTests, divideByZero) {
    ComplexNumber first = ComplexNumber(1.0, 1.0);
    ComplexNumber zero = ComplexNumber(0.0, 0.0);

    ASSERT_ANY_THROW(first / zero);
}
