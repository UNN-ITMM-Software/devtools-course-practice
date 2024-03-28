// Copyright 2024 Vasilev Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vasilev_Ivan_ComplexNumberTest, Can_Create_Zero) {
    double re = 0.0;
    double im = 0.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Vasilev_Ivan_ComplexNumberTest, Check_suma) {
    ComplexNumber x(3.5, 0.5);
    ComplexNumber y(5.5, 1.0);
    ComplexNumber z = x + y;
 
    EXPECT_DOUBLE_EQ(z.getRe(), 9.0);
    EXPECT_DOUBLE_EQ(z.getIm(), 1.5);
}

TEST(Vasilev_Ivan_ComplexNumberTest, Check_subtraction) {
    ComplexNumber x(7.0, 1.5);
    ComplexNumber y(3.7, 1.5);
    ComplexNumber z = x - y;
 
    EXPECT_DOUBLE_EQ(z.getRe(), 3.3);
    EXPECT_DOUBLE_EQ(z.getIm(), 0.0);
}

TEST(Vasilev_Ivan_ComplexNumberTest, Check_mult) {
    ComplexNumber x(1.0, 1.0);
    ComplexNumber y(4.0, -2.0);
    ComplexNumber z = x * y;
 
    EXPECT_DOUBLE_EQ(z.getRe(), 6.0);
    EXPECT_DOUBLE_EQ(z.getIm(), 2.0);
}

TEST(Vasilev_Ivan_ComplexNumberTest, Check_div) {
    ComplexNumber x(20.0, 2.5);
    ComplexNumber y(4.0, 0.5);
    ComplexNumber z = x / y;
 
    EXPECT_DOUBLE_EQ(z.getRe(), 5.0);
    EXPECT_DOUBLE_EQ(z.getIm(), 0.0);
}

TEST(Vasilev_Ivan_ComplexNumberTest, Check_div_zero) {
    ComplexNumber x(7.0, -7.0);
    ComplexNumber y(0.0, 0.0);

    ASSERT_ANY_THROW(x / y);
}

TEST(Vasilev_Ivan_ComplexNumberTest, check_equal_T) {
    ComplexNumber x(6.9, 1.4);
    ComplexNumber y(6.9, 1.4);

    EXPECT_TRUE(x == y);
}

TEST(Vasilev_Ivan_ComplexNumberTest, check_equal_F) {
    ComplexNumber x(5.6, 7.8);
    ComplexNumber y(6.5, 8.7);

    EXPECT_FALSE(x == y);
}

TEST(Vasilev_Ivan_ComplexNumberTest, check_unequal) {
    ComplexNumber x(4.8, 8.9);
    ComplexNumber y(7.7, 7.0);

    EXPECT_TRUE(x != y);
}

TEST(Vasilev_Ivan_ComplexNumberTest, Check_Set) {
    ComplexNumber x;

    ASSERT_NO_THROW(x.setRe(2.7));
    ASSERT_NO_THROW(x.setIm(-6.9));
}

TEST(Vasilev_Ivan_ComplexNumberTest, Check_Get) {
    ComplexNumber x(3.0, 4.0);

    ASSERT_NO_THROW(x.getRe());
    ASSERT_NO_THROW(x.getIm());
}
