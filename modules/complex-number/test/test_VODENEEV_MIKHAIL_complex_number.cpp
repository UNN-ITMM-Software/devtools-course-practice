// Copyright 2021 Vodeneev Mikhail

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Vodeneev_Mikhail_ComplexNumberTest, Comparison) {

    double re1 = 10, re2 = 10;
    double im1 = 15, im2 = 15;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    EXPECT_EQ(z1, z2);
}

TEST(Vodeneev_Mikhail_ComplexNumberTest, Add) {

    double re1 = 1, re2 = 2;
    double im1 = 6, im2 = 9;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber res = z1 + z2;

    EXPECT_EQ(res.getRe(), 3);
    EXPECT_EQ(res.getIm(), 15);
}

TEST(Vodeneev_Mikhail_ComplexNumberTest, Subtraction) {

    double re1 = 1, re2 = 2;
    double im1 = 6, im2 = 9;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber res = z1 - z2;

    EXPECT_EQ(res.getRe(), -1);
    EXPECT_EQ(res.getIm(), -3);
}

TEST(Vodeneev_Mikhail_ComplexNumberTest, Setter) {

    ComplexNumber z;
    
    z.setRe(4);
    z.setIm(3);

    EXPECT_EQ(z.getRe(), 4);
    EXPECT_EQ(z.getIm(), 3);
}