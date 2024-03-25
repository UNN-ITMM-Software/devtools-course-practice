// Copyright 2024 Pozdnyakov Vasya

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pozdnaykov_Vasya_ComplexNumberTest, test_sum_int) {

    ComplexNumber z1(1, 2);
    ComplexNumber z2(-5, 4);
    ComplexNumber res = z1 + z2;

    EXPECT_EQ(-4, res.getRe());
    EXPECT_EQ(6, res.getIm());
}

TEST(Pozdnaykov_Vasya_ComplexNumberTest, test_sub_int) {

    ComplexNumber z1(4, -2);
    ComplexNumber z2(2, -1);
    ComplexNumber res = z1 - z2;

    EXPECT_EQ(2, res.getRe());
    EXPECT_EQ(-1, res.getIm());
}

TEST(Pozdnaykov_Vasya_ComplexNumberTest, test_setRe_int) {

    ComplexNumber res(1, 2);

    res.setRe(10);

    EXPECT_EQ(10, res.getRe());
}

TEST(Pozdnaykov_Vasya_ComplexNumberTest, test_setIm_int) {

    ComplexNumber res(1, 2);
    
    res.setIm(10);

    EXPECT_EQ(10, res.getIm());
}

TEST(Pozdnaykov_Vasya_ComplexNumberTest, test_comprasion_themselves) {

    ComplexNumber z(3, -8);

    EXPECT_EQ(true, z == z);
}

TEST(Pozdnaykov_Vasya_ComplexNumberTest, test_comprasion_different) {

    ComplexNumber z1(3, -8);
    ComplexNumber z2(3, -8);

    EXPECT_EQ(true, z1 == z2);
}
