// Copyright 2021 Aleksandrychev Andrey

#include <gtest/gtest.h>
#include <vector>

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
TEST(Aleksandrychev_Andrey_ComplexNumberTest, Multiplication_Division) {
    double Re1 = 10.5, Im1 = 14.2;
    double Re2 = 5.0, Im2 = 2.1;
    ComplexNumber z1(Re1, Im1);
    ComplexNumber z2(Re2, -Im2);
    ASSERT_EQ(z2.getRe(), (z1*z2/z1).getRe());
}

// Test == operator and copy constructor
TEST(Aleksandrychev_Andrey_ComplexNumberTest, constructor_copy_equal_operator) {
    std::vector<ComplexNumber> origin_list;
    std::vector<ComplexNumber> copy_list;
    for (int i = 0; i < 10; i++) {
        origin_list.push_back(ComplexNumber(i, i + 10));
    }

    for (int i = 0; i < 10; i++) {
        copy_list.push_back(ComplexNumber(origin_list[i]));
    }

    int count_true = 0;
    for (int i = 0; i < 10; i++) {
        if (origin_list[i] == copy_list[i]) count_true++;
    }

    bool res = count_true == 10;

    ASSERT_TRUE(res);
}
