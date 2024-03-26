// Copyright 2024 Skotin Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Skotin_ALexander_ComplexNumberTest, Can_Create_Zero) {
    double re = 0.0;
    double im = 0.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Skotin_ALexander_ComplexNumberTest, Can_Add_ComplexNumbers) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);

    ComplexNumber result = z1 + z2;

    EXPECT_EQ(4.0, result.getRe());
    EXPECT_EQ(6.0, result.getIm());
}

TEST(Skotin_ALexander_ComplexNumberTest, Can_Subtract_ComplexNumbers) {
    ComplexNumber z1(5.0, 6.0);
    ComplexNumber z2(2.0, 3.0);

    ComplexNumber result = z1 - z2;

    EXPECT_EQ(3.0, result.getRe());
    EXPECT_EQ(3.0, result.getIm());
}

TEST(Skotin_ALexander_ComplexNumberTest, Can_Multiply_ComplexNumbers) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(4.0, 5.0);

    ComplexNumber result = z1 * z2;

    EXPECT_EQ(-7.0, result.getRe());
    EXPECT_EQ(22.0, result.getIm());
}
