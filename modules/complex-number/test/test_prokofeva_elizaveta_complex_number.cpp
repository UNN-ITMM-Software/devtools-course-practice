// Copyright 2021 Prokofeva Elizaveta

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Prokofeva_Liza_Complex_Number, Test_Sum_And_Diff) {
    ComplexNumber first(1.5, 0.5);
    ComplexNumber second(2.5, 3.5);
    ComplexNumber third(0.5, -0.5);
    ComplexNumber fourth(-9.5, -7.5);

    ComplexNumber result = (first + second) - (third - fourth);

    ASSERT_DOUBLE_EQ(-6, result.getRe());
    ASSERT_DOUBLE_EQ(-3, result.getIm());
}

TEST(Prokofeva_Liza_Complex_Number, Test_Mult_And_Diff) {
    ComplexNumber first(10.0, 2.9);
    ComplexNumber second(18.75, 23.46);

    ComplexNumber result = (second * first) / (first * second);

    ASSERT_EQ(1, result.getRe());
    ASSERT_EQ(0, result.getIm());
}

TEST(Prokofeva_Liza_Complex_Number, Test_Set_And_Assigment) {
    ComplexNumber first(69.4266, -6.7813);

    first.setRe(20);
    first.setIm(45);

    ComplexNumber second(0.0, 0.0);

    second = first;

    ASSERT_EQ(20, second.getRe());
    ASSERT_EQ(45, second.getIm());
}
