// Copyright 2024 Soloninko Andrey

#include <gtest/gtest.h>

#include <cmath>

#include "include/complex_number.h"

bool checkEQ(double a, double b) 
{
    if (std::fabs(a - b) > 0.001)
    {
        return false;
    }
    else return true;
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

    ASSERT_TRUE(c_val == c_val_eq);
}

TEST(Soloninko_Andrey_ComplexNumberTest, Sum) {
    ComplexNumber c_val(1.25, 2.21);
    ComplexNumber c_val_s(1.25, 2.21);

    ComplexNumber c_val_res = c_val + c_val_s;

    ASSERT_TRUE(checkEQ(c_val_res.getRe(), 2.5));
    ASSERT_TRUE(checkEQ(c_val_res.getIm(), 4.42));
}

TEST(Soloninko_Andrey_ComplexNumberTest, Multiplication) {
    ComplexNumber valueOne(2, 5);
    ComplexNumber valueTwo(89, 45);
    ComplexNumber answer(-47, 535);

    auto result = valueOne * valueTwo;

    ASSERT_TRUE(checkEQ(result.getRe(), answer.getRe()));
    ASSERT_TRUE(checkEQ(result.getIm(), answer.getIm()));
}

TEST(Soloninko_Andrey_ComplexNumberTest, Divide) {
    ComplexNumber c_val(21, 2.21);
    ComplexNumber c_val_d(1.25, 78);
    ComplexNumber c_val_res_ex(0.032639, -0.268707);

    ComplexNumber c_val_res = c_val / c_val_d;

    ASSERT_TRUE(checkEQ(c_val_res.getRe(), c_val_res_ex.getRe()));
    ASSERT_TRUE(checkEQ(c_val_res.getIm(), c_val_res_ex.getIm()));
}