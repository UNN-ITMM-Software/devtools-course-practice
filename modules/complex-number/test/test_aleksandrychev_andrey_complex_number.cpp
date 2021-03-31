// Copyright 2021 Aleksandrychev Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"


// Test arithmatical operators and Copy Constructor
TEST(Aleksandrychev_Andrey_ComplexNumberTest, Arithmetic_Copy_Constr) {
    double Re1 = -1.5, Im1 = 4.3;
    double Re2 = 5.0, Im2 = 2.1;
    double Re3 = 8.3, Im3 = 7.6;

    ComplexNumber num1(Re1, Im1);
    ComplexNumber num2(Re2, Im2);
    ComplexNumber num3(Re3, Im3);

    ComplexNumber res(Re1 + Re2 - Re3, Im1 + Im2 - Im3);

    ASSERT_EQ(res, num1 + num2 - num3);
}

// Test of multiplying
TEST(Aleksandrychev_Andrey_ComplexNumberTest, Multiplication) {
    double Re1 = 10.5, Im1 = 14.2;
    double Re2 = 5.0, Im2 = 2.1;
    ComplexNumber z1(Re1, Im1);
    ComplexNumber z2(Re2, -Im2);
    ASSERT_EQ(z2.getRe(), (z1*z2/z1).getRe());
}

// Test != operator
TEST(Aleksandrychev_Andrey_ComplexNumberTest, Not_equally_operator) {
    double Re1 = 4.0, Im1 = 2.2;
    ComplexNumber a(Re1, Im1);
    ComplexNumber b(0.0, 0.0);
    ASSERT_TRUE(a != b);
}
