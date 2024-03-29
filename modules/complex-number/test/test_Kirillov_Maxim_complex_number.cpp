// Copyright 2024 Kirillov Maxim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kirillov_Maxim_ComplexNumberTest, Can_Divide_By_Zero) {
    double re1 = 1.8, im1 = 2.3;
    double re2 = 0.0, im2 = 0.0;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_THROW(z1 / z2, std::string);
}

TEST(Kirillov_Maxim_ComplexNumberTest, Can_Multiply_ComplexNumbers) {
    double re1 = 2.1, im1 = 1.2;
    double re2 = 4.1, im2 = 3.1;

    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber res = z1 * z2;

    ASSERT_EQ(re1 * re2 - im1 * im2, res.getRe());
    ASSERT_EQ(re1 * im2 + re2 * im1, res.getIm());
}

TEST(Kirillov_Maxim_ComplexNumberTest, Can_Divide_ComplexNumbers) {
    double re1 = 4.2, im1 = 3.6;
    double re2 = 3.9, im2 = 2.1;

    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber res = z1 / z2;

    ASSERT_EQ((re1*re2 + im1*im2) / (re2*re2 + im2*im2), res.getRe());
    ASSERT_EQ((im1*re2 - re1*im2) / (re2*re2 + im2*im2), res.getIm());
}

TEST(Kirillov_Maxim_ComplexNumberTest, Can_Check_Equality) {
    double re1 = 2.2, im1 = 1.5;
    double re2 = 2.2, im2 = 1.5;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_TRUE(z1 == z2);
}
