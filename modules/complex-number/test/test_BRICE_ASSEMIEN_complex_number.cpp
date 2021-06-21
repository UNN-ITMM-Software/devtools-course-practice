// Copyright 2021 Brice Assemien

#include <gtest/gtest.h>
#include <vector>

#include "include/complex_number.h"



TEST(Brice_Assemien_ComplexNumberTest, Arithmetic_Copy_Constr) {
    double Re1 = -3.2, Im1 = 7.1;
    double Re2 = 8.1, Im2 = 1.2;
    double Re3 = 9.0, Im3 = -5.6;

    ComplexNumber num1(Re1, Im1);
    ComplexNumber num2(Re2, Im2);
    ComplexNumber num3(Re3, Im3);

    ComplexNumber res(Re1 + Re2 - Re3, Im1 + Im2 - Im3);

    ASSERT_EQ(res, num1 + num2 - num3);
}

TEST(Brice_Assemien_ComplexNumberTest, Multiplication_Division) {
    double Re1 = 13.5, Im1 = 18.2;
    double Re2 = 4.1, Im2 = 2.0;
    ComplexNumber z1(Re1, Im1);
    ComplexNumber z2(Re2, -Im2);
    ASSERT_EQ(z2.getRe(), (z1*z2/z1).getRe());
}

TEST(Brice_Assemien_ComplexNumberTest, constructor_copy_equal_operator) {
    std::vector<ComplexNumber> origin;
    std::vector<ComplexNumber> copy;
    for (int i = 0; i < 10; i++) {
        origin.push_back(ComplexNumber(i, i + 10));
    }

    for (int i = 0; i < 10; i++) {
        copy.push_back(ComplexNumber(origin[i]));
    }

    int count_true = 0;
    for (int i = 0; i < 10; i++) {
        if (origin[i] == copy[i]) count_true++;
    }

    bool res = count_true == 10;

    ASSERT_TRUE(res);
}
