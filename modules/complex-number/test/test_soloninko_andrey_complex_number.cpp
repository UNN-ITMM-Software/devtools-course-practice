// Copyright 2024 Soloninko Andrey

#include <gtest/gtest.h>

#include <cmath>

#include "include/complex_number.h"

bool checkEQ(double a, double b) 
{
    if (std::fabs(a - b) <= 0.000001)
    {
        return true;
    }
}

TEST(Soloninko_Andrey_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Soloninko_Andrey_ComplexNumberTest, Set) {
    ComplexNumber c_val;

    ASSERT_NO_THROW(c_val.setRe(1.0));
    ASSERT_NO_THROW(c_val.setIm(1.0));
}

TEST(Soloninko_Andrey_ComplexNumberTest, Get) {
    ComplexNumber c_val(1, 2);

    ASSERT_NO_THROW(c_val.getRe());
    ASSERT_NO_THROW(c_val.getIm());
}

TEST(Soloninko_Andrey_ComplexNumberTest, Equal) {
    ComplexNumber c_val(1.25, 2.21);
    ComplexNumber c_val_eq(1.25, 2.21);

    ASSERT_TRUE(checkEQ(c_val.getRe(), c_val_eq.getRe()));
    ASSERT_TRUE(checkEQ(c_val.getIm(), c_val_eq.getIm()));
}

TEST(Soloninko_Andrey_ComplexNumberTest, Sum_True) {
    ComplexNumber c_val(1.25, 2.21);
    ComplexNumber c_val_s(1.25, 2.21);

    ComplexNumber c_val_res = c_val + c_val_s;

    ASSERT_TRUE(checkEQ(c_val_res.getRe(), 2.5));
    ASSERT_TRUE(checkEQ(c_val_res.getIm(), 4.42));
}

TEST(Soloninko_Andrey_ComplexNumberTest, Multiplication) {
    ComplexNumber c_val(21, 2.21);
    ComplexNumber c_val_m(1.25, 78);

    ComplexNumber c_val_res = c_val * c_val_m;

    ASSERT_TRUE(checkEQ(c_val_res.getRe(), -146.13));
    ASSERT_TRUE(checkEQ(c_val_res.getIm(), 1640.7));
}

TEST(Soloninko_Andrey_ComplexNumberTest, Divide) {
    ComplexNumber c_val(21, 2.21);
    ComplexNumber c_val_d(1.25, 78);

    ComplexNumber c_val_res = c_val * c_val_d;

    ASSERT_TRUE(checkEQ(c_val_res.getRe(), 0.032));
    ASSERT_TRUE(checkEQ(c_val_res.getIm(), 0.268));
}