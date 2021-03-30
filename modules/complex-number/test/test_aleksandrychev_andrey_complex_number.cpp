// Copyright 2021 Aleksandrychev Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

double Re1 = 10.5, Im1 = 14.2;
double Re2 = 5.0, Im2 = 2.1;
double Re3 = 8.3, Im3 = 7.6;

// Test arithmatical operators and Copy Constructor
TEST(Aleksandrychev_Andrey_ComplexNumberTest, Arithmetic_Copy_Constr) {
    ComplexNumber num1(Re1, Im1);
    ComplexNumber num2(Re2, Im2);
    ComplexNumber num3(Re3, Im3);

    ComplexNumber res(Re1 + Re2 / Re3, Im1 + Im2 / Im3);

    ASSERT_EQ(res, num1 + num2 / num3);
}

// Test getters and setters functions
TEST(Aleksandrychev_Andrey_ComplexNumberTest, Getters_and_Setters) {
    ComplexNumber num1(Re1, Im1);
    ComplexNumber num2(0.0, 0.0);

    num2.setRe(num1.getRe());
    num2.setIm(num1.getIm());

    ASSERT_EQ(num2.getRe(), Re1);
    ASSERT_EQ(num2.getIm(), Im1);
}

// Test function for check of equal or not equal value
TEST(Aleksandrychev_Andrey_ComplexNumberTest, Equally_and_Not_equally) {
    double Re1 = 5.5, Im1 = 2.2;
    double Re2 = 5.5, Im2 = 2.2;
    double Re3 = 5.0, Im3 = 1.1;

    ComplexNumber num1(Re1, Im1);
    ComplexNumber num2(Re2, Im2);
    ComplexNumber num3(Re3, Im3);

    bool res1, res2;
    if (num1 == num2) res1 = true;
    if (num1.getRe() == num2.getRe() && num1.getIm() == num2.getIm()) res2 = true;

    bool res3, res4;
    if (num1 != num3) res3 = true;
    if (num1.getRe() != num3.getRe() || num1.getIm() == num3.getIm()) res4 = true;

    ASSERT_EQ(res1, res2);
    ASSERT_EQ(res3, res4);
}